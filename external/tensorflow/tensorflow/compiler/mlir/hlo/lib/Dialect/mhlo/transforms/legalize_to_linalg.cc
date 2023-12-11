/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// This file implements logic for lowering HLO/LHLO dialect to Linalg dialect.

#include <numeric>

#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/SetVector.h"
#include "mlir-hlo/Dialect/mhlo/IR/hlo_ops.h"
#include "mlir-hlo/Dialect/mhlo/IR/lhlo_ops.h"
#include "mlir-hlo/Dialect/mhlo/transforms/map_lmhlo_to_scalar_op.h"
#include "mlir-hlo/Dialect/mhlo/transforms/rewriters.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Linalg/IR/LinalgOps.h"
#include "mlir/Dialect/Linalg/IR/LinalgTypes.h"
#include "mlir/Dialect/Math/IR/Math.h"
#include "mlir/Dialect/SCF/SCF.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Dialect/Tensor/IR/Tensor.h"
#include "mlir/IR/AffineExpr.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Location.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Matchers.h"
#include "mlir/IR/Operation.h"
#include "mlir/IR/OperationSupport.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/IR/TypeUtilities.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Transforms/DialectConversion.h"

namespace mlir {
namespace {

/// Returns an ArrayAttr that contains `nLoops` attributes. All the attributes
/// are "parallel" except the last `nReduction` elements, where are "reduction"
/// attributes.
SmallVector<StringRef, 3> GetParallelAndReductionIterators(
    unsigned nLoops, unsigned nReduction) {
  SmallVector<StringRef, 3> res(nLoops - nReduction,
                                getParallelIteratorTypeName());
  res.append(nReduction, getReductionIteratorTypeName());
  return res;
}

SmallVector<StringRef, 3> GetNParallelLoopsAttrs(unsigned nParallelLoops) {
  return GetParallelAndReductionIterators(nParallelLoops, 0);
}

template <bool isLHLO = true>
Value GetResultValue(Operation* op) {
  return isLHLO ? op->getOperand(op->getNumOperands() - 1) : op->getResult(0);
}

template <bool isLHLO = true>
ShapedType GetHloOpResultType(Operation* op) {
  return GetResultValue<isLHLO>(op).getType().template cast<ShapedType>();
}

template <bool isLHLO = true>
bool VerifyHloOpBufferOrTensorSemantics(Operation* op) {
  auto verify_type = [&](Value val) -> bool {
    return (isLHLO && val.getType().isa<MemRefType>()) ||
           (!isLHLO && val.getType().isa<RankedTensorType>());
  };
  if (!llvm::all_of(op->getOperands(), verify_type)) return false;
  return isLHLO ? op->getResults().empty()
                : llvm::all_of(op->getResults(), verify_type);
}

Value GetInitTensor(OpBuilder& b, Location loc, ShapedType type,
                    ArrayRef<Value> dyn_sizes) {
  return b.create<linalg::InitTensorOp>(loc, dyn_sizes, type.getShape(),
                                        type.getElementType());
}

SmallVector<Value, 2> ExtractDynamicSizes(OpBuilder& b, Location loc,
                                          Value tensor) {
  auto tensor_type = tensor.getType().dyn_cast<RankedTensorType>();
  if (!tensor_type) return {};
  SmallVector<Value, 2> dyn_sizes;
  for (auto& en : llvm::enumerate(tensor_type.getShape())) {
    if (en.value() != ShapedType::kDynamicSize) continue;
    dyn_sizes.push_back(b.create<DimOp>(loc, tensor, en.index()));
  }
  return dyn_sizes;
}

SmallVector<int64_t, 4> Extract1DVector(DenseIntElementsAttr elements) {
  SmallVector<int64_t, 4> ret;
  for (const APInt& element : elements) {
    ret.push_back(element.getLimitedValue());
  }
  return ret;
}

/// Returns the constant value associated with the init value if the defining
/// operation is a constant.
Attribute GetInitValueAsConst(Value init) {
  DenseElementsAttr attr;
  if (!matchPattern(init, m_Constant(&attr))) return {};
  auto type = attr.getType().dyn_cast<ShapedType>();
  if (!type || type.getRank() != 0) return {};
  return attr.getValue({});
}

/// Returns a permutation AffineMap that puts all reduction dimensions to the
/// last. The order of parallel loops and reduction loops are all sorted. E.g.,
/// if `rank` is 4 and `reductionDims` is {1, 3}, then
/// "(d0, d1, d2, d3) -> (d0, d2, d1, d3)" is used. The inverse permutation of
/// the AffineMap is returned.
AffineMap GetTransposeMapForReduction(MLIRContext* context, int rank,
                                      ArrayRef<int64_t> reduction_dims) {
  llvm::SmallSetVector<int, 4> s;
  for (auto dim : reduction_dims) s.insert(dim);

  SmallVector<unsigned, 4> permutation;
  for (int i = 0; i < rank; ++i)
    if (!s.count(i)) permutation.push_back(i);
  for (auto dim : reduction_dims) permutation.push_back(dim);

  auto map = AffineMap::getPermutationMap(permutation, context);
  return inversePermutation(map);
}

template <typename OpTy, bool isLHLO = true>
class PointwiseToLinalgConverter : public OpConversionPattern<OpTy> {
 public:
  using OpConversionPattern<OpTy>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      OpTy op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    auto loc = op.getLoc();
    ShapedType t0 = args[0].getType().template dyn_cast<ShapedType>();
    if (!t0) return failure();

    unsigned nloops = t0.getRank();
    auto fail = [&](ShapedType t) {
      return !t || !t.hasRank() || t.getRank() != nloops ||
             !(t.getElementType().isSignlessIntOrFloat() ||
               t.getElementType().isa<ComplexType>());
    };
    if (llvm::any_of(args,
                     [&](Value v) {
                       return fail(v.getType().dyn_cast<ShapedType>());
                     }) ||
        llvm::any_of(op.getOperation()->getResultTypes(),
                     [&](Type t) { return fail(t.dyn_cast<ShapedType>()); }))
      return emitError(loc,
                       "lhlo to linalg conversion expects ranked args of "
                       "signless int, float or complex element type with ")
             << nloops << " parallel iterators: " << *(op.getOperation());

    // Construct the indexing maps needed for linalg.generic ops.
    SmallVector<Type, 4> body_arg_types, body_result_types, op_result_types;

    // This doesnt account for implicit broadcast, but the working assumption
    // in HLO/LHLO is that are broadcasts are made explicit.

    if (isLHLO && !nloops) return failure();

    int num_inputs = (isLHLO ? args.size() - 1 : args.size());

    ValueRange inputs(args.take_front(num_inputs));
    for (Value in : inputs)
      body_arg_types.emplace_back(getElementTypeOrSelf(in.getType()));

    SmallVector<Value, 4> output_buffers;
    if (isLHLO) {
      output_buffers.append(args.begin() + num_inputs, args.end());
    } else {
      Value result = op.getOperation()->getResult(0);
      ShapedType result_type = result.getType().template cast<ShapedType>();
      auto dyn_sizes = ExtractDynamicSizes(rewriter, loc, args[0]);
      output_buffers.push_back(
          GetInitTensor(rewriter, loc, result_type, dyn_sizes));
      op_result_types.push_back(result.getType());
    }
    body_result_types = llvm::to_vector<4>(llvm::map_range(
        output_buffers, [](Value v) { return getElementTypeOrSelf(v); }));

    AffineMap common_indexing_map =
        nloops ? rewriter.getMultiDimIdentityMap(nloops)
               : AffineMap::get(nloops, 0, rewriter.getContext());
    SmallVector<AffineMap, 2> indexing_maps(args.size() + (isLHLO ? 0 : 1),
                                            common_indexing_map);

    bool failed = false;
    auto linalg_op = rewriter.create<linalg::GenericOp>(
        loc, op_result_types, inputs, output_buffers, indexing_maps,
        GetNParallelLoopsAttrs(nloops),
        [&](OpBuilder& nested_builder, Location nested_loc, ValueRange args) {
          // TODO(ravishankarm) : For now use the method in lmhlo namespace.
          // That method needs to be moved out of there.
          Value op_result = lmhlo::HloOpToStdScalarOp::map<OpTy>(
              op, body_result_types,
              llvm::to_vector<2>(args.take_front(inputs.size())), &rewriter);
          if (op_result == nullptr) {
            failed = true;
          } else {
            nested_builder.create<linalg::YieldOp>(loc, op_result);
          }
        });
    if (failed) return failure();
    rewriter.replaceOp(op, linalg_op.getOperation()->getResults());
    return success();
  }
};

template <typename LhloOp>
class ScalarPointwiseToStandardConverter : public OpConversionPattern<LhloOp> {
 public:
  using OpConversionPattern<LhloOp>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      LhloOp lhlo_op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    auto loc = lhlo_op.getLoc();
    auto arg_type =
        lhlo_op.getOperand(0).getType().template dyn_cast<ShapedType>();
    if (!arg_type || !arg_type.getElementType().isSignlessIntOrFloat() ||
        (arg_type.getRank() != 0)) {
      return failure();
    }

    // Create two loads from the input.
    auto lhs = rewriter.create<LoadOp>(loc, lhlo_op.lhs());
    auto rhs = rewriter.create<LoadOp>(loc, lhlo_op.rhs());
    // TODO(ravishankarm) : Move this method out of lmhlo namespace.
    Value op_result = lmhlo::HloOpToStdScalarOp::map<LhloOp>(
        lhlo_op, arg_type.getElementType(), llvm::ArrayRef<Value>{lhs, rhs},
        &rewriter);
    rewriter.create<StoreOp>(loc, op_result, lhlo_op.out());
    rewriter.eraseOp(lhlo_op);
    return success();
  }
};

//===----------------------------------------------------------------------===//
// lmhlo.convolution conversion pattern.
//===----------------------------------------------------------------------===//

/// Converts lmhlo.convolution operation to a linalg.conv op.
struct ConvToLinalgConverter : public OpConversionPattern<lmhlo::ConvOp> {
 public:
  using OpConversionPattern<lmhlo::ConvOp>::OpConversionPattern;

  //  This code has been adapted from IREE's
  //  (https://github.com/google/iree/) mhlo -> linalg conversion.
  LogicalResult matchAndRewrite(
      lmhlo::ConvOp op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    // Check validity of dimension information.
    if (const mhlo::ConvDimensionNumbers& dimension_numbers =
            op.dimension_numbers()) {
      const int input_spatial_rank =
          llvm::size(dimension_numbers.input_spatial_dimensions());
      // The dimensions for input should follow the order of
      // batch_count, spatial_dims..., input_feature_count.
      if (dimension_numbers.input_batch_dimension().getInt() != 0 ||
          dimension_numbers.input_feature_dimension().getInt() !=
              (input_spatial_rank + 1))
        return failure();

      const int kernel_spatial_rank =
          llvm::size(dimension_numbers.kernel_spatial_dimensions());
      // The dimensions for filter should follow the order of
      // spatial_dims..., input_feature_count, num_output_feature_count.
      if (dimension_numbers.kernel_input_feature_dimension().getInt() !=
              kernel_spatial_rank ||
          dimension_numbers.kernel_output_feature_dimension().getInt() !=
              (kernel_spatial_rank + 1))
        return failure();

      const int output_spatial_rank =
          llvm::size(dimension_numbers.output_spatial_dimensions());
      // The dimensions for output should follow the order of
      // batch_count, spatial_dims.., output_feature_count.
      if (dimension_numbers.output_batch_dimension().getInt() != 0 ||
          dimension_numbers.output_feature_dimension().getInt() !=
              (output_spatial_rank + 1))
        return failure();

      if (input_spatial_rank != output_spatial_rank ||
          input_spatial_rank != kernel_spatial_rank)
        return failure();

      auto input_spatial_dim =
          dimension_numbers.input_spatial_dimensions().begin();
      auto kernel_spatial_dim =
          dimension_numbers.kernel_spatial_dimensions().begin();
      auto output_spatial_dim =
          dimension_numbers.output_spatial_dimensions().begin();
      // Check if spatial dims are ordered correctly.
      for (int i = 0; i < input_spatial_rank; ++i) {
        const int dim = i + 1;
        if ((*input_spatial_dim++).getZExtValue() != dim ||
            (*output_spatial_dim++).getZExtValue() != dim ||
            (*kernel_spatial_dim++).getZExtValue() != i)
          return failure();
      }
    }

    // TODO: LHS dilation for deconvolution not supported yet.
    // TODO(jurahul): Window reversal is not supported yet.
    if (op.lhs_dilation() || op.hasWindowReversal()) {
      return failure();
    }

    llvm::SmallVector<Attribute, 4> strides;
    if (auto window_strides = op.window_strides()) {
      auto range = window_strides->getAttributeValues();
      strides.assign(range.begin(), range.end());
    }
    auto strides_arg = ArrayAttr::get(op.getContext(), strides);

    llvm::SmallVector<Attribute, 2> dilation;
    if (auto rhs_dilation = op.rhs_dilation()) {
      auto range = rhs_dilation->getAttributeValues();
      dilation.assign(range.begin(), range.end());
    } else {
      // Default dilation of 1.
      dilation.resize(2, IntegerAttr::get(rewriter.getIntegerType(64), 1));
    }
    auto dilation_arg = ArrayAttr::get(op.getContext(), dilation);

    // Set padding only if it is non-zero.
    DenseIntElementsAttr padding = op.paddingAttr();
    if (!padding ||
        !llvm::any_of(padding.getValues<APInt>(),
                      [](APInt int_val) { return !int_val.isNullValue(); })) {
      padding = nullptr;
    }

    // The order of input and filter are switched with linalg.conv.
    rewriter.replaceOpWithNewOp<linalg::ConvOp>(
        op, args[1], args[0], args[2], strides_arg, dilation_arg, padding);
    return success();
  }
};

/// Base class for lowering HLO operations that have one operand and one result,
/// and are semantically equivalent to a copy of the input to the output (like
/// transpose, some reshape, etc.). The derived classes need to provide a method
/// `getIndexingMaps` that returns AffineMaps for the index maps of the input
/// and the output.
template <typename Derived, typename OpTy, bool isLHLO = true>
class DataMovementOpConverter : public OpConversionPattern<OpTy> {
 public:
  using OpConversionPattern<OpTy>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      OpTy op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    if (!VerifyHloOpBufferOrTensorSemantics<isLHLO>(op)) return failure();
    auto result_type = GetHloOpResultType<isLHLO>(op);

    SmallVector<AffineMap, 2> indexing_maps =
        Derived::getIndexingMaps(op, &rewriter);
    if (indexing_maps.empty()) return failure();

    auto nloops = result_type.getRank();
    auto loc = op.getLoc();
    // TODO(pifon): technically, the op itself could have size operands (e.g.
    // broadcast into a dynamic dimension).Handle this case.
    auto dyn_sizes = isLHLO ? SmallVector<Value, 2>()
                            : ExtractDynamicSizes(rewriter, loc, args[0]);
    auto linalg_op = rewriter.create<linalg::GenericOp>(
        loc,
        /*resultTensorTypes=*/isLHLO ? ArrayRef<Type>{} : result_type,
        /*inputs=*/args.front(),
        /*outputBuffers=*/
        isLHLO
            ? ValueRange{args.back()}
            : ValueRange{GetInitTensor(rewriter, loc, result_type, dyn_sizes)},
        indexing_maps, GetNParallelLoopsAttrs(nloops),
        [&](OpBuilder& nested_builder, Location nested_loc, ValueRange args) {
          nested_builder.create<linalg::YieldOp>(loc, *args.begin());
        });
    rewriter.replaceOp(op, linalg_op.getOperation()->getResults());
    return success();
  }
};

/// Pattern to convert BroadcastOp to Linalg ops.
template <typename OpTy, bool isLHLO = true>
class BroadcastConverter
    : public DataMovementOpConverter<BroadcastConverter<OpTy, isLHLO>, OpTy,
                                     isLHLO> {
 public:
  using DataMovementOpConverter<BroadcastConverter, OpTy,
                                isLHLO>::DataMovementOpConverter;

  static SmallVector<AffineMap, 2> getIndexingMaps(OpTy broadcast_op,
                                                   Builder* b) {
    ShapedType input_type =
        broadcast_op.operand().getType().template cast<ShapedType>();
    unsigned input_rank = input_type.getRank();
    unsigned nloops = GetHloOpResultType<isLHLO>(broadcast_op).getRank();

    // BroadcastOp prepends the dimensions in the `broadcast_sizes` attribute to
    // the input's dimensions.
    unsigned num_prepended_dims = llvm::size(broadcast_op.broadcast_sizes());
    SmallVector<AffineExpr, 4> input_dim_exprs;
    input_dim_exprs.reserve(input_rank);
    for (int i = 0; i < input_rank; ++i) {
      input_dim_exprs.push_back(b->getAffineDimExpr(num_prepended_dims + i));
    }

    AffineMap input_map;
    MLIRContext* context = b->getContext();
    if (input_dim_exprs.empty()) {
      // The input is a scalar, i.e. this is a scalar broadcast op.
      input_map = AffineMap::get(nloops, /*symbolCount=*/0, context);
    } else {
      input_map =
          AffineMap::get(nloops, /*symbolCount=*/0, input_dim_exprs, context);
    }
    return {input_map, b->getMultiDimIdentityMap(nloops)};
  }
};

class HloBroadcastInDimConverter
    : public DataMovementOpConverter<HloBroadcastInDimConverter,
                                     mhlo::BroadcastInDimOp, false> {
 public:
  using DataMovementOpConverter<HloBroadcastInDimConverter,
                                mhlo::BroadcastInDimOp,
                                false>::DataMovementOpConverter;

  static SmallVector<AffineMap, 2> getIndexingMaps(
      mhlo::BroadcastInDimOp broadcast_op, Builder* b) {
    auto result_type = GetHloOpResultType<false>(broadcast_op);
    auto operand_type =
        broadcast_op.operand().getType().template cast<ShapedType>();
    unsigned nloops = result_type.getRank();

    // The input is a scalar, i.e. this is a scalar broadcast op.
    if (operand_type.getRank() == 0) {
      return {AffineMap::get(nloops, /*symbolCount=*/0, b->getContext()),
              b->getMultiDimIdentityMap(nloops)};
    }

    auto operand_shape = operand_type.getShape();
    SmallVector<AffineExpr, 4> dim_exprs;
    dim_exprs.reserve(nloops);

    if (broadcast_op.broadcast_dimensions()) {
      for (const auto& broadcastDim :
           enumerate(broadcast_op.broadcast_dimensions().getIntValues())) {
        int size = broadcastDim.value().getSExtValue();
        bool expansion_needed = operand_shape[broadcastDim.index()] == 1 &&
                                result_type.getShape()[size] != 1;
        dim_exprs.push_back(expansion_needed ? b->getAffineConstantExpr(0)
                                             : b->getAffineDimExpr(size));
      }
    }
    return {
        AffineMap::get(nloops, /*symbolCount=*/0, dim_exprs, b->getContext()),
        b->getMultiDimIdentityMap(nloops)};
  }
};

class HloDynamicBroadcastInDimConverter
    : public OpConversionPattern<mhlo::DynamicBroadcastInDimOp> {
 public:
  using OpConversionPattern<mhlo::DynamicBroadcastInDimOp>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      mhlo::DynamicBroadcastInDimOp op, ArrayRef<Value> operands,
      ConversionPatternRewriter& rewriter) const final {
    // Convert only if the producer is an HLO constant. Ideally the pattern
    // (`mhlo.constant` -> `mhlo.dynamic_broadcast_in_dim`) should be converted
    // to an Tensor-dialect op similar to TF ConstantLikeOp.
    if (!op.operand().getDefiningOp<mhlo::ConstOp>()) return failure();

    mhlo::DynamicBroadcastInDimOp::Adaptor adaptor(op);
    Value operand = adaptor.operand();
    auto operand_type = operand.getType().dyn_cast<RankedTensorType>();
    if (!operand_type || operand_type.getRank() != 0) return failure();

    Value shape = adaptor.output_dimensions();
    auto shape_type = shape.getType().cast<RankedTensorType>();
    int64_t result_rank = shape_type.getDimSize(0);

    SmallVector<Value, 2> dyn_dims;
    Location loc = op.getLoc();
    for (int i = 0; i < result_rank; ++i) {
      Value index = rewriter.create<ConstantIndexOp>(loc, i);
      dyn_dims.push_back(rewriter.create<tensor::ExtractOp>(loc, shape, index));
    }
    auto result_type = op.getType().dyn_cast<RankedTensorType>();
    if (!result_type) return failure();

    int64_t nloops = result_type.getRank();
    Value init = rewriter.create<linalg::InitTensorOp>(
        loc, dyn_dims, result_type.getShape(), result_type.getElementType());
    Operation* generic = rewriter.create<linalg::GenericOp>(
        loc, TypeRange{init.getType()}, ValueRange{operand},
        /*outputBuffers=*/ValueRange{init},
        llvm::makeArrayRef(
            {AffineMap::get(/*dimCount=*/nloops, /*symbolCount=*/0, {},
                            rewriter.getContext()),
             rewriter.getMultiDimIdentityMap(nloops)}),
        GetNParallelLoopsAttrs(nloops),
        [&](OpBuilder& nested_builder, Location nested_loc, ValueRange args) {
          nested_builder.create<linalg::YieldOp>(loc, *args.begin());
        });
    rewriter.replaceOp(op, generic->getResults());
    return success();
  }
};

class LhloBroadcastInDimConverter
    : public OpConversionPattern<lmhlo::BroadcastInDimOp> {
 public:
  using OpConversionPattern<lmhlo::BroadcastInDimOp>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      lmhlo::BroadcastInDimOp op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    lmhlo::BroadcastInDimOp::Adaptor operand_adaptor(args);
    auto result_type = operand_adaptor.output().getType().cast<MemRefType>();
    auto result_shape = result_type.getShape();

    auto operand_and_dims = InsertReshapeIfNecessary(op, args, rewriter);

    Value operand = std::get<0>(operand_and_dims);
    auto broadcast_dims = std::get<1>(operand_and_dims);

    auto loc = op.getLoc();
    auto nloops = result_type.getRank();
    auto operand_type = operand.getType().cast<MemRefType>();

    // For a degenerate case, i.e. broadcasting with expansion of
    // memref<1xELEMENT_TYPE>, the operand is not passed to `linalg.generic`.
    // Instead the value is loaded and used directly in `linalg.yield`.
    if (operand_type.getRank() == 1 &&
        operand_type.getDimSize(0) <
            result_type.getDimSize(broadcast_dims.front())) {
      Value zero = rewriter.create<ConstantIndexOp>(loc, 0);
      Value val =
          rewriter.create<LoadOp>(loc, operand, llvm::makeArrayRef({zero}));
      rewriter.create<linalg::GenericOp>(
          loc, /*inputs=*/ValueRange{},
          /*outputBuffers=*/ValueRange{operand_adaptor.output()},
          llvm::makeArrayRef(rewriter.getMultiDimIdentityMap(nloops)),
          GetNParallelLoopsAttrs(nloops),
          [&](OpBuilder& nested_builder, Location nested_loc, ValueRange args) {
            nested_builder.create<linalg::YieldOp>(loc, val);
          });

    } else {
      auto indexing_maps = getIndexingMaps(op, broadcast_dims, result_shape,
                                           operand_type, &rewriter);
      rewriter.create<linalg::GenericOp>(
          loc, /*inputs=*/ValueRange{operand},
          /*outputBuffers=*/ValueRange{operand_adaptor.output()}, indexing_maps,
          GetNParallelLoopsAttrs(nloops),
          [&](OpBuilder& nested_builder, Location nested_loc, ValueRange args) {
            nested_builder.create<linalg::YieldOp>(loc, *args.begin());
          });
    }
    rewriter.replaceOp(op, llvm::None);
    return success();
  }

  // Inserts 'linalg.reshape' if there is a size-1 dim expansion.
  std::pair<Value, SmallVector<int64_t, 2>> InsertReshapeIfNecessary(
      lmhlo::BroadcastInDimOp op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const {
    lmhlo::BroadcastInDimOp::Adaptor operand_adaptor(args);
    Value operand = operand_adaptor.operand();
    auto operand_type = operand_adaptor.operand().getType().cast<MemRefType>();
    auto operand_shape = operand_type.getShape();

    Value result = operand_adaptor.output();
    auto result_type = result.getType().cast<MemRefType>();
    auto result_shape = result_type.getShape();

    SmallVector<int64_t, 2> operand_strides;
    int64_t operand_offset;
    if (failed(getStridesAndOffset(operand_type, operand_strides,
                                   operand_offset))) {
      op.emitOpError() << "Failed to get offset and strides.";
    }

    SmallVector<int64_t, 2> new_shape, new_strides, broadcast_dims;
    SmallVector<linalg::ReassociationIndices, 4> collapsed_dims_list;
    linalg::ReassociationIndices collapsed_dims;
    for (const auto& item :
         enumerate(op.broadcast_dimensions().getIntValues())) {
      size_t index = item.index();
      int dim = item.value().getSExtValue();

      collapsed_dims.push_back(index);

      bool expansion_needed =
          operand_shape[index] == 1 && result_shape[dim] != 1;
      if (expansion_needed) {
        continue;
      }
      new_shape.push_back(operand_shape[index]);
      new_strides.push_back(operand_strides[index]);
      broadcast_dims.push_back(dim);

      collapsed_dims_list.push_back(collapsed_dims);
      collapsed_dims.clear();
    }
    // If `collapsed_dims_list` is empty, then the memref has shape [1, ..., 1]
    // and all dimensions need expansion. Such memref will be reshaped to a 1D
    // memref with a single element. New shape and strides needs to be updated
    // accordingly.
    if (collapsed_dims_list.empty()) {
      collapsed_dims_list.push_back({});
      new_shape.push_back(1);
      new_strides.push_back(1);
      broadcast_dims.push_back(0);
    }
    for (const auto& dims : collapsed_dims) {
      collapsed_dims_list.back().push_back(dims);
    }

    // `linalg.reshape` is inserted only if necessary, i.e. when the rank can be
    // reduced.
    if (new_shape.size() < operand_shape.size()) {
      auto new_memref_type = MemRefType::get(
          new_shape, operand_type.getElementType(),
          makeStridedLinearLayoutMap(new_strides, operand_offset,
                                     rewriter.getContext()));
      operand = rewriter.create<linalg::ReshapeOp>(op.getLoc(), new_memref_type,
                                                   operand_adaptor.operand(),
                                                   collapsed_dims_list);
    }
    return std::make_pair(operand, broadcast_dims);
  }

  SmallVector<AffineMap, 2> getIndexingMaps(lmhlo::BroadcastInDimOp op,
                                            ArrayRef<int64_t> broadcast_dims,
                                            ArrayRef<int64_t> result_shape,
                                            MemRefType operand_type,
                                            Builder* b) const {
    unsigned nloops = result_shape.size();

    // The input is a scalar, i.e. this is a scalar broadcast op.
    if (operand_type.getRank() == 0) {
      return {AffineMap::get(nloops, /*symbolCount=*/0, b->getContext()),
              b->getMultiDimIdentityMap(nloops)};
    }

    auto operand_shape = operand_type.getShape();
    SmallVector<AffineExpr, 4> dim_exprs;
    dim_exprs.reserve(nloops);

    for (const auto& broadcast_dim : llvm::enumerate(broadcast_dims)) {
      int size = broadcast_dim.value();
      bool expansion_needed =
          operand_shape[broadcast_dim.index()] == 1 && result_shape[size] != 1;
      if (expansion_needed) {
        op.emitOpError(
            "BroadcastInDimOp lowering to Linalg does not support size-1 "
            "dimensions expansion.");
      }
      dim_exprs.push_back(b->getAffineDimExpr(size));
    }
    return {
        AffineMap::get(nloops, /*symbolCount=*/0, dim_exprs, b->getContext()),
        b->getMultiDimIdentityMap(nloops)};
  }
};

template <typename OpTy, bool isLHLO = true>
class TransposeConverter
    : public DataMovementOpConverter<TransposeConverter<OpTy, isLHLO>, OpTy,
                                     isLHLO> {
 public:
  using DataMovementOpConverter<TransposeConverter<OpTy, isLHLO>, OpTy,
                                isLHLO>::DataMovementOpConverter;
  static SmallVector<AffineMap, 2> getIndexingMaps(OpTy op, Builder* b) {
    auto result_type =
        GetHloOpResultType<isLHLO>(op).template cast<ShapedType>();
    auto nloops = result_type.getRank();
    SmallVector<AffineExpr, 2> input_exprs;
    input_exprs.resize(result_type.getRank());
    for (auto permutation : llvm::enumerate(op.permutation())) {
      input_exprs[permutation.value().getZExtValue()] =
          b->getAffineDimExpr(permutation.index());
    }
    return {
        AffineMap::get(nloops, /*symbolCount=*/0, input_exprs, b->getContext()),
        b->getMultiDimIdentityMap(nloops)};
  }
};

// Converts reshape ops that can be proven to be either a collapse of dimensions
// or expansion of dimensions of the operand.
template <typename OpTy, bool isLHLO = true>
class ReshapeOpConverter : public OpConversionPattern<OpTy> {
 public:
  using OpConversionPattern<OpTy>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      OpTy reshape_op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    if (!VerifyHloOpBufferOrTensorSemantics<isLHLO>(reshape_op))
      return failure();
    typename OpTy::Adaptor operands(args);
    ShapedType operand_type =
        operands.operand().getType().template cast<ShapedType>();
    ShapedType result_type = GetHloOpResultType<isLHLO>(reshape_op);

    if (!operand_type.hasStaticShape() || !result_type.hasStaticShape())
      return failure();

    // Compute the reassociation maps for the linalg operation.
    ArrayRef<int64_t> src_shape =
        (operand_type.getRank() > result_type.getRank()
             ? operand_type.getShape()
             : result_type.getShape());
    ArrayRef<int64_t> dst_shape =
        (operand_type.getRank() > result_type.getRank()
             ? result_type.getShape()
             : operand_type.getShape());
    unsigned curr_src_dim = 0, curr_dst_dim = 0;
    SmallVector<linalg::ReassociationExprs, 4> reassociation_map(
        dst_shape.size());

    // First scan all dimensions in the source shapes to see whether we have a
    // perfect case where consecutive dimensions in source are collapsed. For
    // such case we can just generate one single linalg.reshape.
    bool is_collapsing_source = true;
    while (curr_src_dim < src_shape.size() && curr_dst_dim < dst_shape.size()) {
      int64_t dst_size = dst_shape[curr_dst_dim];
      int64_t src_size = src_shape[curr_src_dim];
      while (src_size < dst_size && curr_src_dim < src_shape.size()) {
        reassociation_map[curr_dst_dim].push_back(
            rewriter.getAffineDimExpr(curr_src_dim++));
        src_size *= src_shape[curr_src_dim];
      }
      if (src_size == dst_size) {
        reassociation_map[curr_dst_dim].push_back(
            rewriter.getAffineDimExpr(curr_src_dim++));
        // If the next dim in dst_shape is not 1, treat subsequent dims in
        // src_shape which are 1 to be collapsed.
        if (curr_dst_dim == dst_shape.size() - 1 ||
            dst_shape[curr_dst_dim + 1] != 1) {
          while (curr_src_dim < src_shape.size() &&
                 src_shape[curr_src_dim] == 1) {
            reassociation_map[curr_dst_dim].push_back(
                rewriter.getAffineDimExpr(curr_src_dim++));
          }
        }
      } else {
        is_collapsing_source = false;
        break;
      }
      curr_dst_dim++;
    }
    if (curr_src_dim != src_shape.size() || curr_dst_dim != dst_shape.size())
      is_collapsing_source = false;

    // Otherwise, we need to first reduce all source dimensions into one and
    // then expand to the destination dimensions.
    if (!is_collapsing_source) {
      auto get_identity_exprs = [&rewriter](int n) {
        SmallVector<AffineExpr, 4> exprs;
        for (int i = 0; i < n; ++i)
          exprs.push_back(rewriter.getAffineDimExpr(i));
        return exprs;
      };
      Location loc = reshape_op.getLoc();
      int64_t total_elems = std::accumulate(src_shape.begin(), src_shape.end(),
                                            1, std::multiplies<int64_t>());
      auto elem_type = operand_type.getElementType();
      SmallVector<linalg::ReassociationExprs, 4> collapsing_map = {
          // Use operand_type here because we need to collapse all operands
          // dimensions.
          get_identity_exprs(operand_type.getShape().size())};
      SmallVector<linalg::ReassociationExprs, 4> expanding_map = {
          // Use result_type here because we need to expand to all result
          // dimensions.
          get_identity_exprs(result_type.getShape().size())};

      if (isLHLO) {
        auto collapsed_type = MemRefType::get({total_elems}, elem_type);
        Value collapsed_op = rewriter.create<linalg::ReshapeOp>(
            loc, collapsed_type, args[0], collapsing_map);
        Value reshape_buffer = rewriter.create<linalg::ReshapeOp>(
            loc, result_type, collapsed_op, expanding_map);
        rewriter.replaceOpWithNewOp<linalg::CopyOp>(reshape_op, reshape_buffer,
                                                    args[1]);
      } else {
        auto collapsed_type = RankedTensorType::get({total_elems}, elem_type);
        Value collapsed_op = rewriter.create<linalg::TensorReshapeOp>(
            loc, collapsed_type, args[0], collapsing_map);
        rewriter.replaceOpWithNewOp<linalg::TensorReshapeOp>(
            reshape_op, result_type, collapsed_op, expanding_map);
      }
      return success();
    }

    if (isLHLO) {
      Value reshape_buffer = rewriter.create<linalg::ReshapeOp>(
          reshape_op.getLoc(), result_type, args[0], reassociation_map);
      rewriter.replaceOpWithNewOp<linalg::CopyOp>(reshape_op, reshape_buffer,
                                                  args[1]);
    } else {
      rewriter.replaceOpWithNewOp<linalg::TensorReshapeOp>(
          reshape_op, result_type, args[0], reassociation_map);
    }
    return success();
  }
};

template <typename OpTy, bool isLHLO = true>
class IotaConverter : public OpConversionPattern<OpTy> {
 public:
  using OpConversionPattern<OpTy>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      OpTy iota_op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    ShapedType result_shaped_type = GetHloOpResultType<isLHLO>(iota_op);
    if (!result_shaped_type) return failure();

    auto result_element_type = result_shaped_type.getElementType();
    if (!result_element_type.isSignlessIntOrFloat()) return failure();

    // Construct the indexing maps needed for linalg.generic ops.
    unsigned nloops = result_shaped_type.getRank();

    Location loc = iota_op.getLoc();
    auto dyn_sizes = isLHLO
                         ? SmallVector<Value, 2>()
                         : ExtractDynamicSizes(rewriter, loc,
                                               GetResultValue<isLHLO>(iota_op));
    auto linalg_op = rewriter.create<linalg::IndexedGenericOp>(
        loc,
        /*resultTensorTypes=*/
        isLHLO ? ArrayRef<Type>{} : ArrayRef<Type>{result_shaped_type},
        /*inputs=*/ValueRange{},
        /*outputBuffers=*/
        isLHLO ? ValueRange{args}
               : ValueRange{GetInitTensor(rewriter, loc, result_shaped_type,
                                          dyn_sizes)},
        llvm::makeArrayRef(rewriter.getMultiDimIdentityMap(nloops)),
        GetNParallelLoopsAttrs(nloops),
        [&](OpBuilder& nested_builder, Location nested_loc, ValueRange ivs,
            ValueRange args) {
          Value cast_op = nested_builder.create<IndexCastOp>(
              nested_loc, ivs[iota_op.iota_dimension()],
              nested_builder.getIntegerType(
                  result_element_type.getIntOrFloatBitWidth()));
          if (result_element_type.template isa<FloatType>()) {
            cast_op = nested_builder.create<SIToFPOp>(nested_loc, cast_op,
                                                      result_element_type);
          }
          nested_builder.create<linalg::YieldOp>(nested_loc, cast_op);
        });
    if (isLHLO)
      rewriter.replaceOp(iota_op, llvm::None);
    else
      rewriter.replaceOp(iota_op, linalg_op.result_tensors());
    return success();
  }
};

template <typename OpTy>
class ConstConverter : public OpConversionPattern<OpTy> {
 public:
  using OpConversionPattern<OpTy>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      OpTy const_op, ArrayRef<Value> /*args*/,
      ConversionPatternRewriter& rewriter) const final {
    Location loc = const_op.getLoc();
    auto value_attr = const_op.value().template cast<DenseElementsAttr>();
    if (value_attr.getType().getRank() != 0) return failure();
    ReplaceConstOp(loc, const_op, value_attr, rewriter);
    return success();
  }

 private:
  void ReplaceConstOp(Location loc, mhlo::ConstOp op,
                      DenseElementsAttr value_attr,
                      ConversionPatternRewriter& rewriter) const {
    Value std_tensor_const = rewriter.create<mlir::ConstantOp>(loc, value_attr);
    rewriter.replaceOp(op, {std_tensor_const});
  }
  void ReplaceConstOp(Location loc, lmhlo::ConstOp op,
                      DenseElementsAttr value_attr,
                      ConversionPatternRewriter& rewriter) const {
    Value std_scalar_const =
        rewriter.create<mlir::ConstantOp>(loc, value_attr.getValue({}));
    rewriter.create<mlir::AffineStoreOp>(loc, std_scalar_const, op.getOperand(),
                                         llvm::None);
    rewriter.eraseOp(op);
  }
};

class ReduceConverter : public OpConversionPattern<lmhlo::ReduceOp> {
 public:
  using OpConversionPattern<lmhlo::ReduceOp>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      lmhlo::ReduceOp reduce_op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    auto loc = reduce_op.getLoc();
    lmhlo::ReduceOp::Adaptor adaptor(args);
    auto operand_shape =
        adaptor.operands()[0].getType().template dyn_cast<ShapedType>();
    if (!operand_shape || !operand_shape.hasRank()) {
      emitError(loc, "lhlo to linalg conversion expects known-rank args");
      return failure();
    }

    // First fill the output buffer with the init value.
    Value init_value = rewriter.create<LoadOp>(loc, adaptor.init_values()[0]);
    rewriter.create<linalg::FillOp>(loc, adaptor.out()[0], init_value);

    DenseIntElementsAttr dimensions_attr = reduce_op.dimensions();
    SmallVector<int, 4> reduction_dims;
    for (const auto& dim : dimensions_attr.getIntValues()) {
      reduction_dims.push_back(dim.getSExtValue());
    }

    SmallVector<AffineExpr, 2> src_exprs;
    SmallVector<AffineExpr, 2> dst_exprs;
    SmallVector<StringRef, 4> types;
    for (int i = 0, rank = operand_shape.getRank(); i != rank; ++i) {
      bool is_reduced = llvm::is_contained(reduction_dims, i);
      types.push_back(is_reduced ? getReductionIteratorTypeName()
                                 : getParallelIteratorTypeName());

      src_exprs.push_back(mlir::getAffineDimExpr(i, rewriter.getContext()));
      if (!is_reduced) {
        dst_exprs.push_back(mlir::getAffineDimExpr(i, rewriter.getContext()));
      }
    }

    auto maps = AffineMap::inferFromExprList({src_exprs, dst_exprs});

    auto linalg_op = rewriter.create<linalg::GenericOp>(
        loc, /*resultTensorTypes=*/ArrayRef<Type>{},
        /*inputs=*/adaptor.operands(), /*outputBuffers=*/adaptor.out(), maps,
        types);
    rewriter.inlineRegionBefore(reduce_op.body(), linalg_op.region(),
                                linalg_op.region().end());
    {
      OpBuilder::InsertionGuard region_guard(rewriter);
      Block* block = linalg_op.getBody();
      rewriter.setInsertionPoint(&block->front());

      // The incoming region is operating on buffers, while linalg.generic
      // expects scalar SSA values. Add some allocs around the original op to
      // make it compatible.
      auto arg_type = block->getArgument(0).getType().cast<MemRefType>();
      Value alloc_a = rewriter.create<AllocaOp>(loc, arg_type);
      Value alloc_b = rewriter.create<AllocaOp>(loc, arg_type);
      Value alloc_res = rewriter.create<AllocaOp>(loc, arg_type);

      // Now turn the existing signature
      //   (memref<X>, memref<X>, memref<X>) -> ()
      // into
      //   (X, X) -> X
      TypeConverter::SignatureConversion signature_converter(3);
      signature_converter.remapInput(0, alloc_a);
      signature_converter.remapInput(1, alloc_b);
      signature_converter.remapInput(2, alloc_res);
      signature_converter.addInputs(
          {arg_type.getElementType(), arg_type.getElementType()});
      Block* entry_block = rewriter.applySignatureConversion(
          &linalg_op.region(), signature_converter);

      // Store the arguments into the newly allocated buffers.
      rewriter.setInsertionPointAfter(alloc_res.getDefiningOp());
      rewriter.create<StoreOp>(loc, entry_block->getArgument(0), alloc_a);
      rewriter.create<StoreOp>(loc, entry_block->getArgument(1), alloc_b);
      rewriter.replaceOp(entry_block->getTerminator(), {});

      // Load & yield the result.
      rewriter.setInsertionPointToEnd(entry_block);
      auto load_res = rewriter.create<LoadOp>(loc, alloc_res);
      rewriter.create<linalg::YieldOp>(loc, ValueRange{load_res});
    }

    rewriter.replaceOp(reduce_op, linalg_op.getOperation()->getResults());
    return success();
  }
};

// TODO(b/156787842): Support the lowering for dynamic shapes.
template <typename OpTy, bool isLHLO = true>
class ReverseConverter
    : public DataMovementOpConverter<ReverseConverter<OpTy, isLHLO>, OpTy,
                                     isLHLO> {
 public:
  using DataMovementOpConverter<ReverseConverter<OpTy, isLHLO>, OpTy,
                                isLHLO>::DataMovementOpConverter;
  static SmallVector<AffineMap, 2> getIndexingMaps(OpTy op, Builder* b) {
    auto result_type =
        GetHloOpResultType<isLHLO>(op).template cast<ShapedType>();
    auto nloops = result_type.getRank();
    SmallVector<AffineExpr, 2> input_exprs;
    input_exprs.reserve(nloops);
    for (int i = 0; i < nloops; ++i)
      input_exprs.push_back(b->getAffineDimExpr(i));
    for (auto dim : op.dimensions()) {
      int i = dim.getZExtValue();
      if (result_type.isDynamicDim(i)) return {};
      int n = result_type.getShape()[i];
      input_exprs[i] = b->getAffineConstantExpr(n - 1) - input_exprs[i];
    }
    return {
        AffineMap::get(nloops, /*symbolCount=*/0, input_exprs, b->getContext()),
        b->getMultiDimIdentityMap(nloops)};
  }
};

class SliceConverter : public OpConversionPattern<lmhlo::SliceOp> {
 public:
  using OpConversionPattern<lmhlo::SliceOp>::OpConversionPattern;

  LogicalResult matchAndRewrite(
      lmhlo::SliceOp slice_op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    auto loc = slice_op.getLoc();
    auto arg_type =
        slice_op.getOperand(0).getType().template dyn_cast<ShapedType>();
    if (!arg_type || !arg_type.hasRank()) {
      emitError(loc, "lhlo to linalg conversion expects known-rank args");
      return failure();
    }

    SmallVector<OpFoldResult, 3> offsets, sizes, strides;
    for (int i = 0, e = arg_type.getRank(); i < e; ++i) {
      offsets.push_back(rewriter.getI64IntegerAttr(
          slice_op.start_indices().getValue<int64_t>(i)));
      sizes.push_back(rewriter.getI64IntegerAttr(
          slice_op.limit_indices().getValue<int64_t>(i) -
          slice_op.start_indices().getValue<int64_t>(i)));
      strides.push_back(
          rewriter.getI64IntegerAttr(slice_op.strides().getValue<int64_t>(i)));
    }
    auto linalg_slice = rewriter.create<SubViewOp>(loc, slice_op.getOperand(0),
                                                   offsets, sizes, strides);
    rewriter.create<linalg::CopyOp>(loc, linalg_slice, slice_op.getOperand(1));
    rewriter.eraseOp(slice_op);
    return success();
  }
};

enum class DotOperationType {
  kVectorDot = 0,
  kMatrixVector = 1,
  kMatrixMatrix = 2,
  kUnsupported = 3
};

DotOperationType GetDotOperationType(mhlo::DotOp dot_op) {
  ArrayRef<int64_t> lhs_shape =
      dot_op.lhs().getType().cast<ShapedType>().getShape();
  ArrayRef<int64_t> rhs_shape =
      dot_op.rhs().getType().cast<ShapedType>().getShape();
  auto shape_matches = [](int64_t a, int64_t b) {
    return a == ShapedType::kDynamicSize || b == ShapedType::kDynamicSize ||
           a == b;
  };
  if (lhs_shape.size() == 1 && rhs_shape.size() == 1 &&
      shape_matches(lhs_shape[0], rhs_shape[0])) {
    return DotOperationType::kVectorDot;
  }
  if (lhs_shape.size() == 2 && rhs_shape.size() == 1 &&
      shape_matches(lhs_shape[1], rhs_shape[0])) {
    return DotOperationType::kMatrixVector;
  }
  if (rhs_shape.size() == 2 && rhs_shape.size() == 2 &&
      shape_matches(lhs_shape[1], rhs_shape[0])) {
    return DotOperationType::kMatrixMatrix;
  }
  return DotOperationType::kUnsupported;
}

SmallVector<Value, 2> GetDotOpInitTensorDynSizes(OpBuilder& b, Location loc,
                                                 Value lhs, Value rhs,
                                                 DotOperationType type) {
  SmallVector<Value, 2> dyn_shape;
  switch (type) {
    case DotOperationType::kMatrixMatrix: {
      if (lhs.getType().cast<ShapedType>().isDynamicDim(0))
        dyn_shape.push_back(b.create<DimOp>(loc, lhs, 0));
      if (rhs.getType().cast<ShapedType>().isDynamicDim(1))
        dyn_shape.push_back(b.create<DimOp>(loc, rhs, 1));
      break;
    }
    case DotOperationType::kMatrixVector: {
      if (lhs.getType().cast<ShapedType>().isDynamicDim(0))
        dyn_shape.push_back(b.create<DimOp>(loc, lhs, 0));
      break;
    }
    case DotOperationType::kVectorDot:
    case DotOperationType::kUnsupported:
    default: {
      break;
    }
  }
  return dyn_shape;
}

class DotOpOnTensorsConversion : public OpConversionPattern<mhlo::DotOp> {
 public:
  using OpConversionPattern<mhlo::DotOp>::OpConversionPattern;
  LogicalResult matchAndRewrite(
      mhlo::DotOp op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    if (!VerifyHloOpBufferOrTensorSemantics</*isLHLO=*/false>(op)) {
      return failure();
    }
    Location loc = op.getLoc();
    mhlo::DotOp::Adaptor adaptor(args);
    Type result_type = op.getResult().getType();
    auto shaped_type = result_type.cast<ShapedType>();
    DotOperationType op_type = GetDotOperationType(op);
    auto zero_attr = rewriter.getZeroAttr(shaped_type.getElementType());
    Value zero = rewriter.create<ConstantOp>(loc, zero_attr);
    SmallVector<Value, 2> dyn_shape = GetDotOpInitTensorDynSizes(
        rewriter, loc, adaptor.lhs(), adaptor.rhs(), op_type);
    auto init_tensor = GetInitTensor(rewriter, loc, shaped_type, dyn_shape);
    Value zero_tensor =
        rewriter.create<linalg::FillOp>(loc, init_tensor, zero).getResult(0);
    linalg::LinalgOp linalg_op;
    switch (op_type) {
      case DotOperationType::kMatrixMatrix: {
        linalg_op = rewriter.create<linalg::MatmulOp>(
            loc, TypeRange{result_type},
            ValueRange{adaptor.lhs(), adaptor.rhs()}, ValueRange{zero_tensor});
        break;
      }
      case DotOperationType::kMatrixVector: {
        linalg_op = rewriter.create<linalg::MatvecOp>(
            loc, TypeRange{result_type},
            ValueRange{adaptor.lhs(), adaptor.rhs()}, ValueRange{zero_tensor});
        break;
      }
      case DotOperationType::kVectorDot: {
        linalg_op = rewriter.create<linalg::DotOp>(
            loc, TypeRange{result_type},
            ValueRange{adaptor.lhs(), adaptor.rhs()}, ValueRange{zero_tensor});
        break;
      }
      case DotOperationType::kUnsupported:
      default: {
        return op.emitError("unsupported dot operation type");
      }
    }
    rewriter.replaceOp(op, linalg_op->getResults());
    return success();
  }
};

SmallVector<Value, 8> GetDotGeneralOpInitTensorDynSizes(
    OpBuilder& b, Location loc, Value lhs, Value rhs, ShapedType result_type) {
  SmallVector<Value, 8> dyn_shape;
  if (result_type.isDynamicDim(0))
    dyn_shape.push_back(b.create<DimOp>(loc, lhs, 0));
  if (result_type.isDynamicDim(1))
    dyn_shape.push_back(b.create<DimOp>(loc, lhs, 1));
  if (result_type.isDynamicDim(2))
    dyn_shape.push_back(b.create<DimOp>(loc, rhs, 2));
  return dyn_shape;
}

class DotGeneralOpOnTensorsConversion
    : public OpConversionPattern<mhlo::DotGeneralOp> {
 public:
  using OpConversionPattern<mhlo::DotGeneralOp>::OpConversionPattern;
  LogicalResult matchAndRewrite(
      mhlo::DotGeneralOp op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    if (!VerifyHloOpBufferOrTensorSemantics</*isLHLO=*/false>(op)) {
      return failure();
    }
    mhlo::DotDimensionNumbers dim_numbers = op.dot_dimension_numbers();
    auto lhs_bathcing_dims =
        Extract1DVector(dim_numbers.lhs_batching_dimensions());
    auto rhs_bathcing_dims =
        Extract1DVector(dim_numbers.rhs_batching_dimensions());
    auto lhs_contracting_dims =
        Extract1DVector(dim_numbers.lhs_contracting_dimensions());
    auto rhs_contracting_dims =
        Extract1DVector(dim_numbers.rhs_contracting_dimensions());
    if (lhs_bathcing_dims.size() != 1 || lhs_bathcing_dims[0] != 0) {
      return rewriter.notifyMatchFailure(
          op, "expected lhs batching dimensions exactly {0}");
    }
    if (rhs_bathcing_dims.size() != 1 || rhs_bathcing_dims[0] != 0) {
      return rewriter.notifyMatchFailure(
          op, "expected rhs batching dimensions exactly {0}");
    }
    if (lhs_contracting_dims.size() != 1 || lhs_contracting_dims[0] != 2) {
      return rewriter.notifyMatchFailure(
          op, "expected lhs contracting dimensions exactly {2}");
    }
    if (rhs_contracting_dims.size() != 1 || rhs_contracting_dims[0] != 1) {
      return rewriter.notifyMatchFailure(
          op, "expected rhs contracting dimensions exactly {1}");
    }
    Location loc = op.getLoc();
    mhlo::DotGeneralOp::Adaptor adaptor(args);
    Type result_type = op.getResult().getType();
    auto shaped_type = result_type.cast<ShapedType>();
    SmallVector<Value, 8> dyn_shape = GetDotGeneralOpInitTensorDynSizes(
        rewriter, loc, adaptor.lhs(), adaptor.rhs(), shaped_type);
    auto zero_attr = rewriter.getZeroAttr(shaped_type.getElementType());
    Value zero = rewriter.create<ConstantOp>(loc, zero_attr);
    auto init_tensor = GetInitTensor(rewriter, loc, shaped_type, dyn_shape);
    Value zero_tensor =
        rewriter.create<linalg::FillOp>(loc, init_tensor, zero).getResult(0);
    auto linalg_op = rewriter.create<linalg::BatchMatmulOp>(
        loc, /*resultTensorTypes=*/TypeRange{result_type},
        /*inputs=*/ValueRange{adaptor.lhs(), adaptor.rhs()},
        /*outputBuffers=*/ValueRange{zero_tensor});
    rewriter.replaceOp(op, linalg_op.getResults());
    return success();
  }
};

template <typename OpTy>
struct ReduceRegionXLAOpConversion : public OpConversionPattern<OpTy> {
  using OpConversionPattern<OpTy>::OpConversionPattern;
  LogicalResult matchAndRewrite(
      OpTy op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    // Only convert the body of reduction ops to std ops.
    auto parent_op = op.getOperation()->getParentRegion()->getParentOp();
    if (!isa<mhlo::ReduceOp, linalg::GenericOp, linalg::IndexedGenericOp>(
            parent_op)) {
      return failure();
    }
    if (!op.getResult().getType().template isa<TensorType>()) return failure();
    if (llvm::all_of(args, [](Value arg) {
          return arg.getType().template isa<TensorType>();
        })) {
      return failure();
    }
    Value result = lmhlo::HloOpToStdScalarOp::map<OpTy>(op, args[0].getType(),
                                                        args, &rewriter);
    rewriter.replaceOp(op, result);
    return success();
  }
};

SmallVector<Value, 8> GetReduceOpInitTensorDynSizes(
    OpBuilder& b, Location loc, Value arg, ShapedType result_type,
    ArrayRef<int64_t> reduction_dims) {
  llvm::SmallSetVector<int, 4> s;
  for (auto dim : reduction_dims) s.insert(dim);

  SmallVector<unsigned, 4> parallel_dims;
  SmallVector<Value, 8> dyn_shape;
  int rank = arg.getType().cast<RankedTensorType>().getRank();
  for (int i = 0, j = 0; i < rank; ++i) {
    if (s.count(i)) continue;
    if (!result_type.isDynamicDim(j++)) continue;
    dyn_shape.push_back(b.create<DimOp>(loc, arg, i));
  }

  return dyn_shape;
}

class ReduceRegionReturnOpConversion
    : public OpConversionPattern<mhlo::ReturnOp> {
 public:
  using OpConversionPattern<mhlo::ReturnOp>::OpConversionPattern;
  LogicalResult matchAndRewrite(
      mhlo::ReturnOp op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    rewriter.replaceOpWithNewOp<linalg::YieldOp>(op, args);
    return success();
  }
};

class ReduceOnTensorsConversion : public OpConversionPattern<mhlo::ReduceOp> {
 public:
  using OpConversionPattern<mhlo::ReduceOp>::OpConversionPattern;
  LogicalResult matchAndRewrite(
      mhlo::ReduceOp op, ArrayRef<Value> args,
      ConversionPatternRewriter& rewriter) const final {
    Location loc = op.getLoc();
    mhlo::ReduceOp::Adaptor adaptor(args);
    if (op.getNumOperands() != 2) {
      return op.emitError("expects exactly two operands");
    }
    Value src = adaptor.operands()[0];
    auto src_type = src.getType().cast<ShapedType>();
    int src_rank = src_type.getRank();
    if (!src_rank) {
      return rewriter.notifyMatchFailure(op, "expects known-rank args");
    }

    // Check if init_value is constant. If so, inline the value into the region.
    Value init_value = adaptor.init_values()[0];
    Attribute init_const_val = GetInitValueAsConst(init_value);
    if (init_const_val) {
      init_value = rewriter.create<ConstantOp>(
          init_value.getDefiningOp()->getLoc(), init_const_val);
    } else {
      init_value = rewriter.create<tensor::ExtractOp>(loc, init_value);
    }

    // Prepare indexing maps for linalg generic op. The elements are for src and
    // dst. Transpose `src` to make the reduction loops be the innermost,
    // because it's easier to fully utilize processors.
    SmallVector<AffineMap, 3> indexing_maps;
    SmallVector<int64_t, 4> reduction_dims = Extract1DVector(op.dimensions());
    indexing_maps.emplace_back(GetTransposeMapForReduction(
        rewriter.getContext(), src_rank, reduction_dims));

    // The indexing map of `dst` should drop the reduction loops. Since the
    // reduction loops now are all in the innermost, drops
    // `reduction_dims.size()` dimensions. We don't need an inverse permutation
    // here because they are the same.
    SmallVector<AffineExpr, 4> exprs;
    for (int i = 0, e = src_rank - reduction_dims.size(); i < e; ++i)
      exprs.push_back(rewriter.getAffineDimExpr(i));
    indexing_maps.emplace_back(AffineMap::get(src_rank, /*symbolCount=*/0,
                                              exprs, rewriter.getContext()));

    SmallVector<Value, 2> inputs = {adaptor.operands()[0]};
    Type result_type = op.getResult(0).getType();
    auto shaped_type = result_type.cast<ShapedType>();
    SmallVector<Value, 8> dyn_shape = GetReduceOpInitTensorDynSizes(
        rewriter, loc, adaptor.operands()[0], result_type.cast<ShapedType>(),
        reduction_dims);
    auto init_tensor = GetInitTensor(rewriter, loc, shaped_type, dyn_shape);
    Value filled_tensor =
        rewriter.create<linalg::FillOp>(loc, init_tensor, init_value)
            .getResult(0);

    auto linalg_op = rewriter.create<linalg::GenericOp>(
        loc, /*resultTensorTypes=*/op.getResultTypes(), inputs,
        /*outputBuffers=*/ValueRange{filled_tensor}, indexing_maps,
        GetParallelAndReductionIterators(src_rank, reduction_dims.size()));

    // Convert the signature of the body. The reduce op region apply function
    // has a signature (lhs, rhs) -> output, all of the same tensor type t.
    // This is converted to a function with the same signature but with
    // element types. E.g., "(tensor<f32>, tensor<f32>) -> tensor<f32>" will
    // be converted to "(f32, f32, f32)".
    Region& region = linalg_op.region();
    rewriter.inlineRegionBefore(op.body(), region, region.end());
    TypeConverter::SignatureConversion signatureConverter(2);
    signatureConverter.addInputs(0, src_type.getElementType());
    signatureConverter.addInputs(1, src_type.getElementType());
    rewriter.applySignatureConversion(&region, signatureConverter);
    rewriter.replaceOp(op, linalg_op.getResults());
    return success();
  }
};

void populateLHLOToLinalgConversionPattern(MLIRContext* context,
                                           OwningRewritePatternList* patterns) {
  // clang-format off
  patterns->insert<BroadcastConverter<lmhlo::BroadcastOp>,
                   ConstConverter<lmhlo::ConstOp>,
                   ConvToLinalgConverter,
                   IotaConverter<lmhlo::IotaOp>,
                   LhloBroadcastInDimConverter,
                   PointwiseToLinalgConverter<lmhlo::AbsOp>,
                   PointwiseToLinalgConverter<lmhlo::AddOp>,
                   PointwiseToLinalgConverter<lmhlo::AndOp>,
                   PointwiseToLinalgConverter<lmhlo::Atan2Op>,
                   PointwiseToLinalgConverter<lmhlo::CeilOp>,
                   PointwiseToLinalgConverter<lmhlo::ClampOp>,
                   PointwiseToLinalgConverter<lmhlo::CompareOp>,
                   PointwiseToLinalgConverter<lmhlo::ComplexOp>,
                   PointwiseToLinalgConverter<lmhlo::ConvertOp>,
                   // TODO(ataei): Remove this pattern, CopyOp is folded away.
                   PointwiseToLinalgConverter<lmhlo::CopyOp>,
                   PointwiseToLinalgConverter<lmhlo::CosOp>,
                   PointwiseToLinalgConverter<lmhlo::DivOp>,
                   PointwiseToLinalgConverter<lmhlo::ExpOp>,
                   PointwiseToLinalgConverter<lmhlo::Expm1Op>,
                   PointwiseToLinalgConverter<lmhlo::FloorOp>,
                   PointwiseToLinalgConverter<lmhlo::ImagOp>,
                   PointwiseToLinalgConverter<lmhlo::IsFiniteOp>,
                   PointwiseToLinalgConverter<lmhlo::LogOp>,
                   PointwiseToLinalgConverter<lmhlo::LogisticOp>,
                   PointwiseToLinalgConverter<lmhlo::Log1pOp>,
                   PointwiseToLinalgConverter<lmhlo::MaxOp>,
                   PointwiseToLinalgConverter<lmhlo::MinOp>,
                   PointwiseToLinalgConverter<lmhlo::MulOp>,
                   PointwiseToLinalgConverter<lmhlo::NegOp>,
                   PointwiseToLinalgConverter<lmhlo::NotOp>,
                   PointwiseToLinalgConverter<lmhlo::OrOp>,
                   PointwiseToLinalgConverter<lmhlo::PowOp>,
                   PointwiseToLinalgConverter<lmhlo::RealOp>,
                   PointwiseToLinalgConverter<lmhlo::RemOp>,
                   PointwiseToLinalgConverter<lmhlo::RsqrtOp>,
                   PointwiseToLinalgConverter<lmhlo::SelectOp>,
                   PointwiseToLinalgConverter<lmhlo::ShiftLeftOp>,
                   PointwiseToLinalgConverter<lmhlo::ShiftRightArithmeticOp>,
                   PointwiseToLinalgConverter<lmhlo::ShiftRightLogicalOp>,
                   PointwiseToLinalgConverter<lmhlo::SignOp>,
                   PointwiseToLinalgConverter<lmhlo::SinOp>,
                   PointwiseToLinalgConverter<lmhlo::SqrtOp>,
                   PointwiseToLinalgConverter<lmhlo::SubOp>,
                   PointwiseToLinalgConverter<lmhlo::TanhOp>,
                   PointwiseToLinalgConverter<lmhlo::XorOp>,
                   ReduceConverter,
                   ReshapeOpConverter<lmhlo::ReshapeOp>,
                   ReverseConverter<lmhlo::ReverseOp>,
                   ScalarPointwiseToStandardConverter<lmhlo::AddOp>,
                   ScalarPointwiseToStandardConverter<lmhlo::MaxOp>,
                   SliceConverter,
                   TransposeConverter<lmhlo::TransposeOp>
                  >(context);
  // clang-format on
}

// Converts LHLO ops to Linalg generic.
// Sample result for lmhlo::AddOp.
//
// "lmhlo.add"(%arg1, %arg2, %out) :
//      (memref<2x2xf32>, memref<2x2xf32>, memref<2x2xf32>) -> ()
//
// will be converted to
//
// #map0 = (d0, d1) -> (d0, d1)
// "linalg.generic"(%arg1, %arg2, %out) ( {
//   ^bb0(%arg4: f32, %arg5: f32):
//     %0 = addf %arg4, %arg5 : f32
//     "linalg.yield"(%0) : (f32) -> ()
// }) {
//     indexing_maps = [#map0, #map0, #map0],
//     iterator_types = ["parallel", "parallel"],
// } : (memref<2x2xf32>, memref<2x2xf32>, memref<2x2xf32>) -> ()
struct LhloLegalizeToLinalgPass
    : public PassWrapper<LhloLegalizeToLinalgPass, FunctionPass> {
  void getDependentDialects(DialectRegistry& registry) const override {
    registry.insert<AffineDialect, linalg::LinalgDialect, math::MathDialect>();
  }

  void runOnFunction() override {
    OwningRewritePatternList patterns;
    ConversionTarget target(getContext());
    target.addLegalDialect<complex::ComplexDialect, linalg::LinalgDialect,
                           math::MathDialect, StandardOpsDialect,
                           AffineDialect>();

    auto func = getFunction();
    populateLHLOToLinalgConversionPattern(func.getContext(), &patterns);
    if (failed(applyPartialConversion(func, target, std::move(patterns)))) {
      signalPassFailure();
    }
  }
};

struct HloLegalizeToLinalgPass
    : public PassWrapper<HloLegalizeToLinalgPass, FunctionPass> {
  void getDependentDialects(DialectRegistry& registry) const override {
    registry.insert<linalg::LinalgDialect, scf::SCFDialect,
                    complex::ComplexDialect, math::MathDialect>();
  }

  void runOnFunction() override {
    OwningRewritePatternList patterns;
    ConversionTarget target(getContext());
    target.addLegalDialect<complex::ComplexDialect, linalg::LinalgDialect,
                           math::MathDialect, StandardOpsDialect,
                           tensor::TensorDialect, scf::SCFDialect>();

    auto func = getFunction();
    mhlo::populateHLOToLinalgConversionPattern(func.getContext(), &patterns);
    if (failed(applyPartialConversion(func, target, std::move(patterns)))) {
      signalPassFailure();
    }
  }
};

}  // namespace

namespace lmhlo {
std::unique_ptr<OperationPass<FuncOp>> createLegalizeLhloToLinalgPass() {
  return std::make_unique<LhloLegalizeToLinalgPass>();
}
}  // namespace lmhlo

namespace mhlo {

void populateHLOToLinalgConversionPattern(MLIRContext* context,
                                          OwningRewritePatternList* patterns) {
  patterns->insert<
      BroadcastConverter<mhlo::BroadcastOp, false>,
      ConstConverter<mhlo::ConstOp>, HloDynamicBroadcastInDimConverter,
      HloBroadcastInDimConverter, IotaConverter<mhlo::IotaOp, false>,
      PointwiseToLinalgConverter<mhlo::AbsOp, false>,
      PointwiseToLinalgConverter<mhlo::AddOp, false>,
      PointwiseToLinalgConverter<mhlo::AndOp, false>,
      PointwiseToLinalgConverter<mhlo::Atan2Op, false>,
      PointwiseToLinalgConverter<mhlo::CeilOp, false>,
      PointwiseToLinalgConverter<mhlo::ClampOp, false>,
      PointwiseToLinalgConverter<mhlo::CompareOp, false>,
      PointwiseToLinalgConverter<mhlo::ComplexOp, false>,
      PointwiseToLinalgConverter<mhlo::ConvertOp, false>,
      PointwiseToLinalgConverter<mhlo::CopyOp, false>,
      PointwiseToLinalgConverter<mhlo::CosOp, false>,
      PointwiseToLinalgConverter<mhlo::DivOp, false>,
      PointwiseToLinalgConverter<mhlo::ExpOp, false>,
      PointwiseToLinalgConverter<mhlo::Expm1Op, false>,
      PointwiseToLinalgConverter<mhlo::FloorOp, false>,
      PointwiseToLinalgConverter<mhlo::ImagOp, false>,
      PointwiseToLinalgConverter<mhlo::IsFiniteOp, false>,
      PointwiseToLinalgConverter<mhlo::LogOp, false>,
      PointwiseToLinalgConverter<mhlo::LogisticOp, false>,
      PointwiseToLinalgConverter<mhlo::Log1pOp, false>,
      PointwiseToLinalgConverter<mhlo::MaxOp, false>,
      PointwiseToLinalgConverter<mhlo::MinOp, false>,
      PointwiseToLinalgConverter<mhlo::MulOp, false>,
      PointwiseToLinalgConverter<mhlo::NegOp, false>,
      PointwiseToLinalgConverter<mhlo::NotOp, false>,
      PointwiseToLinalgConverter<mhlo::OrOp, false>,
      PointwiseToLinalgConverter<mhlo::PowOp, false>,
      PointwiseToLinalgConverter<mhlo::RealOp, false>,
      PointwiseToLinalgConverter<mhlo::RemOp, false>,
      PointwiseToLinalgConverter<mhlo::RsqrtOp, false>,
      PointwiseToLinalgConverter<mhlo::SelectOp, false>,
      PointwiseToLinalgConverter<mhlo::ShiftLeftOp, false>,
      PointwiseToLinalgConverter<mhlo::ShiftRightArithmeticOp, false>,
      PointwiseToLinalgConverter<mhlo::ShiftRightLogicalOp, false>,
      PointwiseToLinalgConverter<mhlo::SignOp, false>,
      PointwiseToLinalgConverter<mhlo::SinOp, false>,
      PointwiseToLinalgConverter<mhlo::SqrtOp, false>,
      PointwiseToLinalgConverter<mhlo::SubOp, false>,
      PointwiseToLinalgConverter<mhlo::TanhOp, false>,
      PointwiseToLinalgConverter<mhlo::XorOp, false>,
      ReshapeOpConverter<mhlo::ReshapeOp, false>,
      ReverseConverter<mhlo::ReverseOp, false>,
      TransposeConverter<mhlo::TransposeOp, false>, DotOpOnTensorsConversion,
      DotGeneralOpOnTensorsConversion, ReduceOnTensorsConversion>(context);
  patterns->insert<ReduceRegionXLAOpConversion<mhlo::AddOp>,
                   ReduceRegionXLAOpConversion<mhlo::MinOp>,
                   ReduceRegionXLAOpConversion<mhlo::MaxOp>,
                   ReduceRegionReturnOpConversion>(context);
}

std::unique_ptr<OperationPass<FuncOp>> createLegalizeHloToLinalgPass() {
  return std::make_unique<HloLegalizeToLinalgPass>();
}
}  // namespace mhlo
}  // namespace mlir
