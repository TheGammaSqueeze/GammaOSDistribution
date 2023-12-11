/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "intrinsics_arm64.h"

#include "arch/arm64/callee_save_frame_arm64.h"
#include "arch/arm64/instruction_set_features_arm64.h"
#include "art_method.h"
#include "base/bit_utils.h"
#include "code_generator_arm64.h"
#include "common_arm64.h"
#include "data_type-inl.h"
#include "entrypoints/quick/quick_entrypoints.h"
#include "heap_poisoning.h"
#include "intrinsics.h"
#include "intrinsics_utils.h"
#include "lock_word.h"
#include "mirror/array-inl.h"
#include "mirror/object_array-inl.h"
#include "mirror/reference.h"
#include "mirror/string-inl.h"
#include "mirror/var_handle.h"
#include "scoped_thread_state_change-inl.h"
#include "thread-current-inl.h"
#include "utils/arm64/assembler_arm64.h"

using namespace vixl::aarch64;  // NOLINT(build/namespaces)

// TODO(VIXL): Make VIXL compile with -Wshadow.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#include "aarch64/disasm-aarch64.h"
#include "aarch64/macro-assembler-aarch64.h"
#pragma GCC diagnostic pop

namespace art {

namespace arm64 {

using helpers::CPURegisterFrom;
using helpers::DRegisterFrom;
using helpers::HeapOperand;
using helpers::LocationFrom;
using helpers::InputCPURegisterOrZeroRegAt;
using helpers::IsConstantZeroBitPattern;
using helpers::OperandFrom;
using helpers::RegisterFrom;
using helpers::SRegisterFrom;
using helpers::WRegisterFrom;
using helpers::XRegisterFrom;
using helpers::HRegisterFrom;
using helpers::InputRegisterAt;
using helpers::OutputRegister;

namespace {

ALWAYS_INLINE inline MemOperand AbsoluteHeapOperandFrom(Location location, size_t offset = 0) {
  return MemOperand(XRegisterFrom(location), offset);
}

}  // namespace

MacroAssembler* IntrinsicCodeGeneratorARM64::GetVIXLAssembler() {
  return codegen_->GetVIXLAssembler();
}

ArenaAllocator* IntrinsicCodeGeneratorARM64::GetAllocator() {
  return codegen_->GetGraph()->GetAllocator();
}

using IntrinsicSlowPathARM64 = IntrinsicSlowPath<InvokeDexCallingConventionVisitorARM64,
                                                 SlowPathCodeARM64,
                                                 Arm64Assembler>;

#define __ codegen->GetVIXLAssembler()->

// Slow path implementing the SystemArrayCopy intrinsic copy loop with read barriers.
class ReadBarrierSystemArrayCopySlowPathARM64 : public SlowPathCodeARM64 {
 public:
  ReadBarrierSystemArrayCopySlowPathARM64(HInstruction* instruction, Location tmp)
      : SlowPathCodeARM64(instruction), tmp_(tmp) {
    DCHECK(kEmitCompilerReadBarrier);
    DCHECK(kUseBakerReadBarrier);
  }

  void EmitNativeCode(CodeGenerator* codegen_in) override {
    CodeGeneratorARM64* codegen = down_cast<CodeGeneratorARM64*>(codegen_in);
    LocationSummary* locations = instruction_->GetLocations();
    DCHECK(locations->CanCall());
    DCHECK(instruction_->IsInvokeStaticOrDirect())
        << "Unexpected instruction in read barrier arraycopy slow path: "
        << instruction_->DebugName();
    DCHECK(instruction_->GetLocations()->Intrinsified());
    DCHECK_EQ(instruction_->AsInvoke()->GetIntrinsic(), Intrinsics::kSystemArrayCopy);

    const int32_t element_size = DataType::Size(DataType::Type::kReference);

    Register src_curr_addr = XRegisterFrom(locations->GetTemp(0));
    Register dst_curr_addr = XRegisterFrom(locations->GetTemp(1));
    Register src_stop_addr = XRegisterFrom(locations->GetTemp(2));
    Register tmp_reg = WRegisterFrom(tmp_);

    __ Bind(GetEntryLabel());
    vixl::aarch64::Label slow_copy_loop;
    __ Bind(&slow_copy_loop);
    __ Ldr(tmp_reg, MemOperand(src_curr_addr, element_size, PostIndex));
    codegen->GetAssembler()->MaybeUnpoisonHeapReference(tmp_reg);
    // TODO: Inline the mark bit check before calling the runtime?
    // tmp_reg = ReadBarrier::Mark(tmp_reg);
    // No need to save live registers; it's taken care of by the
    // entrypoint. Also, there is no need to update the stack mask,
    // as this runtime call will not trigger a garbage collection.
    // (See ReadBarrierMarkSlowPathARM64::EmitNativeCode for more
    // explanations.)
    DCHECK_NE(tmp_.reg(), LR);
    DCHECK_NE(tmp_.reg(), WSP);
    DCHECK_NE(tmp_.reg(), WZR);
    // IP0 is used internally by the ReadBarrierMarkRegX entry point
    // as a temporary (and not preserved).  It thus cannot be used by
    // any live register in this slow path.
    DCHECK_NE(LocationFrom(src_curr_addr).reg(), IP0);
    DCHECK_NE(LocationFrom(dst_curr_addr).reg(), IP0);
    DCHECK_NE(LocationFrom(src_stop_addr).reg(), IP0);
    DCHECK_NE(tmp_.reg(), IP0);
    DCHECK(0 <= tmp_.reg() && tmp_.reg() < kNumberOfWRegisters) << tmp_.reg();
    // TODO: Load the entrypoint once before the loop, instead of
    // loading it at every iteration.
    int32_t entry_point_offset =
        Thread::ReadBarrierMarkEntryPointsOffset<kArm64PointerSize>(tmp_.reg());
    // This runtime call does not require a stack map.
    codegen->InvokeRuntimeWithoutRecordingPcInfo(entry_point_offset, instruction_, this);
    codegen->GetAssembler()->MaybePoisonHeapReference(tmp_reg);
    __ Str(tmp_reg, MemOperand(dst_curr_addr, element_size, PostIndex));
    __ Cmp(src_curr_addr, src_stop_addr);
    __ B(&slow_copy_loop, ne);
    __ B(GetExitLabel());
  }

  const char* GetDescription() const override { return "ReadBarrierSystemArrayCopySlowPathARM64"; }

 private:
  Location tmp_;

  DISALLOW_COPY_AND_ASSIGN(ReadBarrierSystemArrayCopySlowPathARM64);
};
#undef __

bool IntrinsicLocationsBuilderARM64::TryDispatch(HInvoke* invoke) {
  Dispatch(invoke);
  LocationSummary* res = invoke->GetLocations();
  if (res == nullptr) {
    return false;
  }
  return res->Intrinsified();
}

#define __ masm->

static void CreateFPToIntLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresFpuRegister());
  locations->SetOut(Location::RequiresRegister());
}

static void CreateIntToFPLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetOut(Location::RequiresFpuRegister());
}

static void MoveFPToInt(LocationSummary* locations, bool is64bit, MacroAssembler* masm) {
  Location input = locations->InAt(0);
  Location output = locations->Out();
  __ Fmov(is64bit ? XRegisterFrom(output) : WRegisterFrom(output),
          is64bit ? DRegisterFrom(input) : SRegisterFrom(input));
}

static void MoveIntToFP(LocationSummary* locations, bool is64bit, MacroAssembler* masm) {
  Location input = locations->InAt(0);
  Location output = locations->Out();
  __ Fmov(is64bit ? DRegisterFrom(output) : SRegisterFrom(output),
          is64bit ? XRegisterFrom(input) : WRegisterFrom(input));
}

void IntrinsicLocationsBuilderARM64::VisitDoubleDoubleToRawLongBits(HInvoke* invoke) {
  CreateFPToIntLocations(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitDoubleLongBitsToDouble(HInvoke* invoke) {
  CreateIntToFPLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitDoubleDoubleToRawLongBits(HInvoke* invoke) {
  MoveFPToInt(invoke->GetLocations(), /* is64bit= */ true, GetVIXLAssembler());
}
void IntrinsicCodeGeneratorARM64::VisitDoubleLongBitsToDouble(HInvoke* invoke) {
  MoveIntToFP(invoke->GetLocations(), /* is64bit= */ true, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitFloatFloatToRawIntBits(HInvoke* invoke) {
  CreateFPToIntLocations(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitFloatIntBitsToFloat(HInvoke* invoke) {
  CreateIntToFPLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitFloatFloatToRawIntBits(HInvoke* invoke) {
  MoveFPToInt(invoke->GetLocations(), /* is64bit= */ false, GetVIXLAssembler());
}
void IntrinsicCodeGeneratorARM64::VisitFloatIntBitsToFloat(HInvoke* invoke) {
  MoveIntToFP(invoke->GetLocations(), /* is64bit= */ false, GetVIXLAssembler());
}

static void CreateIntToIntLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetOut(Location::RequiresRegister(), Location::kNoOutputOverlap);
}

static void CreateIntIntToIntLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetOut(Location::RequiresRegister(), Location::kNoOutputOverlap);
}

static void CreateIntIntToIntSlowPathCallLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());
  // Force kOutputOverlap; see comments in IntrinsicSlowPath::EmitNativeCode.
  locations->SetOut(Location::RequiresRegister(), Location::kOutputOverlap);
}

static void GenerateReverseBytes(MacroAssembler* masm,
                                 DataType::Type type,
                                 CPURegister in,
                                 CPURegister out) {
  switch (type) {
    case DataType::Type::kUint16:
      __ Rev16(out.W(), in.W());
      break;
    case DataType::Type::kInt16:
      __ Rev16(out.W(), in.W());
      __ Sxth(out.W(), out.W());
      break;
    case DataType::Type::kInt32:
      __ Rev(out.W(), in.W());
      break;
    case DataType::Type::kInt64:
      __ Rev(out.X(), in.X());
      break;
    case DataType::Type::kFloat32:
      __ Rev(in.W(), in.W());  // Note: Clobbers `in`.
      __ Fmov(out.S(), in.W());
      break;
    case DataType::Type::kFloat64:
      __ Rev(in.X(), in.X());  // Note: Clobbers `in`.
      __ Fmov(out.D(), in.X());
      break;
    default:
      LOG(FATAL) << "Unexpected type for reverse-bytes: " << type;
      UNREACHABLE();
  }
}

static void GenReverseBytes(LocationSummary* locations,
                            DataType::Type type,
                            MacroAssembler* masm) {
  Location in = locations->InAt(0);
  Location out = locations->Out();
  GenerateReverseBytes(masm, type, CPURegisterFrom(in, type), CPURegisterFrom(out, type));
}

void IntrinsicLocationsBuilderARM64::VisitIntegerReverseBytes(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitIntegerReverseBytes(HInvoke* invoke) {
  GenReverseBytes(invoke->GetLocations(), DataType::Type::kInt32, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitLongReverseBytes(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitLongReverseBytes(HInvoke* invoke) {
  GenReverseBytes(invoke->GetLocations(), DataType::Type::kInt64, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitShortReverseBytes(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitShortReverseBytes(HInvoke* invoke) {
  GenReverseBytes(invoke->GetLocations(), DataType::Type::kInt16, GetVIXLAssembler());
}

static void GenNumberOfLeadingZeros(LocationSummary* locations,
                                    DataType::Type type,
                                    MacroAssembler* masm) {
  DCHECK(type == DataType::Type::kInt32 || type == DataType::Type::kInt64);

  Location in = locations->InAt(0);
  Location out = locations->Out();

  __ Clz(RegisterFrom(out, type), RegisterFrom(in, type));
}

void IntrinsicLocationsBuilderARM64::VisitIntegerNumberOfLeadingZeros(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitIntegerNumberOfLeadingZeros(HInvoke* invoke) {
  GenNumberOfLeadingZeros(invoke->GetLocations(), DataType::Type::kInt32, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitLongNumberOfLeadingZeros(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitLongNumberOfLeadingZeros(HInvoke* invoke) {
  GenNumberOfLeadingZeros(invoke->GetLocations(), DataType::Type::kInt64, GetVIXLAssembler());
}

static void GenNumberOfTrailingZeros(LocationSummary* locations,
                                     DataType::Type type,
                                     MacroAssembler* masm) {
  DCHECK(type == DataType::Type::kInt32 || type == DataType::Type::kInt64);

  Location in = locations->InAt(0);
  Location out = locations->Out();

  __ Rbit(RegisterFrom(out, type), RegisterFrom(in, type));
  __ Clz(RegisterFrom(out, type), RegisterFrom(out, type));
}

void IntrinsicLocationsBuilderARM64::VisitIntegerNumberOfTrailingZeros(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitIntegerNumberOfTrailingZeros(HInvoke* invoke) {
  GenNumberOfTrailingZeros(invoke->GetLocations(), DataType::Type::kInt32, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitLongNumberOfTrailingZeros(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitLongNumberOfTrailingZeros(HInvoke* invoke) {
  GenNumberOfTrailingZeros(invoke->GetLocations(), DataType::Type::kInt64, GetVIXLAssembler());
}

static void GenReverse(LocationSummary* locations,
                       DataType::Type type,
                       MacroAssembler* masm) {
  DCHECK(type == DataType::Type::kInt32 || type == DataType::Type::kInt64);

  Location in = locations->InAt(0);
  Location out = locations->Out();

  __ Rbit(RegisterFrom(out, type), RegisterFrom(in, type));
}

void IntrinsicLocationsBuilderARM64::VisitIntegerReverse(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitIntegerReverse(HInvoke* invoke) {
  GenReverse(invoke->GetLocations(), DataType::Type::kInt32, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitLongReverse(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitLongReverse(HInvoke* invoke) {
  GenReverse(invoke->GetLocations(), DataType::Type::kInt64, GetVIXLAssembler());
}

static void GenBitCount(HInvoke* instr, DataType::Type type, MacroAssembler* masm) {
  DCHECK(DataType::IsIntOrLongType(type)) << type;
  DCHECK_EQ(instr->GetType(), DataType::Type::kInt32);
  DCHECK_EQ(DataType::Kind(instr->InputAt(0)->GetType()), type);

  UseScratchRegisterScope temps(masm);

  Register src = InputRegisterAt(instr, 0);
  Register dst = RegisterFrom(instr->GetLocations()->Out(), type);
  VRegister fpr = (type == DataType::Type::kInt64) ? temps.AcquireD() : temps.AcquireS();

  __ Fmov(fpr, src);
  __ Cnt(fpr.V8B(), fpr.V8B());
  __ Addv(fpr.B(), fpr.V8B());
  __ Fmov(dst, fpr);
}

void IntrinsicLocationsBuilderARM64::VisitLongBitCount(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitLongBitCount(HInvoke* invoke) {
  GenBitCount(invoke, DataType::Type::kInt64, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitIntegerBitCount(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitIntegerBitCount(HInvoke* invoke) {
  GenBitCount(invoke, DataType::Type::kInt32, GetVIXLAssembler());
}

static void GenHighestOneBit(HInvoke* invoke, DataType::Type type, MacroAssembler* masm) {
  DCHECK(type == DataType::Type::kInt32 || type == DataType::Type::kInt64);

  UseScratchRegisterScope temps(masm);

  Register src = InputRegisterAt(invoke, 0);
  Register dst = RegisterFrom(invoke->GetLocations()->Out(), type);
  Register temp = (type == DataType::Type::kInt64) ? temps.AcquireX() : temps.AcquireW();
  size_t high_bit = (type == DataType::Type::kInt64) ? 63u : 31u;
  size_t clz_high_bit = (type == DataType::Type::kInt64) ? 6u : 5u;

  __ Clz(temp, src);
  __ Mov(dst, UINT64_C(1) << high_bit);  // MOV (bitmask immediate)
  __ Bic(dst, dst, Operand(temp, LSL, high_bit - clz_high_bit));  // Clear dst if src was 0.
  __ Lsr(dst, dst, temp);
}

void IntrinsicLocationsBuilderARM64::VisitIntegerHighestOneBit(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitIntegerHighestOneBit(HInvoke* invoke) {
  GenHighestOneBit(invoke, DataType::Type::kInt32, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitLongHighestOneBit(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitLongHighestOneBit(HInvoke* invoke) {
  GenHighestOneBit(invoke, DataType::Type::kInt64, GetVIXLAssembler());
}

static void GenLowestOneBit(HInvoke* invoke, DataType::Type type, MacroAssembler* masm) {
  DCHECK(type == DataType::Type::kInt32 || type == DataType::Type::kInt64);

  UseScratchRegisterScope temps(masm);

  Register src = InputRegisterAt(invoke, 0);
  Register dst = RegisterFrom(invoke->GetLocations()->Out(), type);
  Register temp = (type == DataType::Type::kInt64) ? temps.AcquireX() : temps.AcquireW();

  __ Neg(temp, src);
  __ And(dst, temp, src);
}

void IntrinsicLocationsBuilderARM64::VisitIntegerLowestOneBit(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitIntegerLowestOneBit(HInvoke* invoke) {
  GenLowestOneBit(invoke, DataType::Type::kInt32, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitLongLowestOneBit(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitLongLowestOneBit(HInvoke* invoke) {
  GenLowestOneBit(invoke, DataType::Type::kInt64, GetVIXLAssembler());
}

static void CreateFPToFPLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresFpuRegister());
  locations->SetOut(Location::RequiresFpuRegister(), Location::kNoOutputOverlap);
}

void IntrinsicLocationsBuilderARM64::VisitMathSqrt(HInvoke* invoke) {
  CreateFPToFPLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathSqrt(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = GetVIXLAssembler();
  __ Fsqrt(DRegisterFrom(locations->Out()), DRegisterFrom(locations->InAt(0)));
}

void IntrinsicLocationsBuilderARM64::VisitMathCeil(HInvoke* invoke) {
  CreateFPToFPLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathCeil(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = GetVIXLAssembler();
  __ Frintp(DRegisterFrom(locations->Out()), DRegisterFrom(locations->InAt(0)));
}

void IntrinsicLocationsBuilderARM64::VisitMathFloor(HInvoke* invoke) {
  CreateFPToFPLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathFloor(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = GetVIXLAssembler();
  __ Frintm(DRegisterFrom(locations->Out()), DRegisterFrom(locations->InAt(0)));
}

void IntrinsicLocationsBuilderARM64::VisitMathRint(HInvoke* invoke) {
  CreateFPToFPLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathRint(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = GetVIXLAssembler();
  __ Frintn(DRegisterFrom(locations->Out()), DRegisterFrom(locations->InAt(0)));
}

static void CreateFPToIntPlusFPTempLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresFpuRegister());
  locations->SetOut(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresFpuRegister());
}

static void GenMathRound(HInvoke* invoke, bool is_double, vixl::aarch64::MacroAssembler* masm) {
  // Java 8 API definition for Math.round():
  // Return the closest long or int to the argument, with ties rounding to positive infinity.
  //
  // There is no single instruction in ARMv8 that can support the above definition.
  // We choose to use FCVTAS here, because it has closest semantic.
  // FCVTAS performs rounding to nearest integer, ties away from zero.
  // For most inputs (positive values, zero or NaN), this instruction is enough.
  // We only need a few handling code after FCVTAS if the input is negative half value.
  //
  // The reason why we didn't choose FCVTPS instruction here is that
  // although it performs rounding toward positive infinity, it doesn't perform rounding to nearest.
  // For example, FCVTPS(-1.9) = -1 and FCVTPS(1.1) = 2.
  // If we were using this instruction, for most inputs, more handling code would be needed.
  LocationSummary* l = invoke->GetLocations();
  VRegister in_reg = is_double ? DRegisterFrom(l->InAt(0)) : SRegisterFrom(l->InAt(0));
  VRegister tmp_fp = is_double ? DRegisterFrom(l->GetTemp(0)) : SRegisterFrom(l->GetTemp(0));
  Register out_reg = is_double ? XRegisterFrom(l->Out()) : WRegisterFrom(l->Out());
  vixl::aarch64::Label done;

  // Round to nearest integer, ties away from zero.
  __ Fcvtas(out_reg, in_reg);

  // For positive values, zero or NaN inputs, rounding is done.
  __ Tbz(out_reg, out_reg.GetSizeInBits() - 1, &done);

  // Handle input < 0 cases.
  // If input is negative but not a tie, previous result (round to nearest) is valid.
  // If input is a negative tie, out_reg += 1.
  __ Frinta(tmp_fp, in_reg);
  __ Fsub(tmp_fp, in_reg, tmp_fp);
  __ Fcmp(tmp_fp, 0.5);
  __ Cinc(out_reg, out_reg, eq);

  __ Bind(&done);
}

void IntrinsicLocationsBuilderARM64::VisitMathRoundDouble(HInvoke* invoke) {
  CreateFPToIntPlusFPTempLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathRoundDouble(HInvoke* invoke) {
  GenMathRound(invoke, /* is_double= */ true, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitMathRoundFloat(HInvoke* invoke) {
  CreateFPToIntPlusFPTempLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathRoundFloat(HInvoke* invoke) {
  GenMathRound(invoke, /* is_double= */ false, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitMemoryPeekByte(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMemoryPeekByte(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  __ Ldrsb(WRegisterFrom(invoke->GetLocations()->Out()),
          AbsoluteHeapOperandFrom(invoke->GetLocations()->InAt(0), 0));
}

void IntrinsicLocationsBuilderARM64::VisitMemoryPeekIntNative(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMemoryPeekIntNative(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  __ Ldr(WRegisterFrom(invoke->GetLocations()->Out()),
         AbsoluteHeapOperandFrom(invoke->GetLocations()->InAt(0), 0));
}

void IntrinsicLocationsBuilderARM64::VisitMemoryPeekLongNative(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMemoryPeekLongNative(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  __ Ldr(XRegisterFrom(invoke->GetLocations()->Out()),
         AbsoluteHeapOperandFrom(invoke->GetLocations()->InAt(0), 0));
}

void IntrinsicLocationsBuilderARM64::VisitMemoryPeekShortNative(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMemoryPeekShortNative(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  __ Ldrsh(WRegisterFrom(invoke->GetLocations()->Out()),
           AbsoluteHeapOperandFrom(invoke->GetLocations()->InAt(0), 0));
}

static void CreateIntIntToVoidLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());
}

void IntrinsicLocationsBuilderARM64::VisitMemoryPokeByte(HInvoke* invoke) {
  CreateIntIntToVoidLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMemoryPokeByte(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  __ Strb(WRegisterFrom(invoke->GetLocations()->InAt(1)),
          AbsoluteHeapOperandFrom(invoke->GetLocations()->InAt(0), 0));
}

void IntrinsicLocationsBuilderARM64::VisitMemoryPokeIntNative(HInvoke* invoke) {
  CreateIntIntToVoidLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMemoryPokeIntNative(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  __ Str(WRegisterFrom(invoke->GetLocations()->InAt(1)),
         AbsoluteHeapOperandFrom(invoke->GetLocations()->InAt(0), 0));
}

void IntrinsicLocationsBuilderARM64::VisitMemoryPokeLongNative(HInvoke* invoke) {
  CreateIntIntToVoidLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMemoryPokeLongNative(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  __ Str(XRegisterFrom(invoke->GetLocations()->InAt(1)),
         AbsoluteHeapOperandFrom(invoke->GetLocations()->InAt(0), 0));
}

void IntrinsicLocationsBuilderARM64::VisitMemoryPokeShortNative(HInvoke* invoke) {
  CreateIntIntToVoidLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMemoryPokeShortNative(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  __ Strh(WRegisterFrom(invoke->GetLocations()->InAt(1)),
          AbsoluteHeapOperandFrom(invoke->GetLocations()->InAt(0), 0));
}

void IntrinsicLocationsBuilderARM64::VisitThreadCurrentThread(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetOut(Location::RequiresRegister());
}

void IntrinsicCodeGeneratorARM64::VisitThreadCurrentThread(HInvoke* invoke) {
  codegen_->Load(DataType::Type::kReference, WRegisterFrom(invoke->GetLocations()->Out()),
                 MemOperand(tr, Thread::PeerOffset<kArm64PointerSize>().Int32Value()));
}

static void GenUnsafeGet(HInvoke* invoke,
                         DataType::Type type,
                         bool is_volatile,
                         CodeGeneratorARM64* codegen) {
  LocationSummary* locations = invoke->GetLocations();
  DCHECK((type == DataType::Type::kInt32) ||
         (type == DataType::Type::kInt64) ||
         (type == DataType::Type::kReference));
  Location base_loc = locations->InAt(1);
  Register base = WRegisterFrom(base_loc);      // Object pointer.
  Location offset_loc = locations->InAt(2);
  Register offset = XRegisterFrom(offset_loc);  // Long offset.
  Location trg_loc = locations->Out();
  Register trg = RegisterFrom(trg_loc, type);

  if (type == DataType::Type::kReference && kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
    // UnsafeGetObject/UnsafeGetObjectVolatile with Baker's read barrier case.
    Register temp = WRegisterFrom(locations->GetTemp(0));
    MacroAssembler* masm = codegen->GetVIXLAssembler();
    // Piggy-back on the field load path using introspection for the Baker read barrier.
    __ Add(temp, base, offset.W());  // Offset should not exceed 32 bits.
    codegen->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                   trg_loc,
                                                   base,
                                                   MemOperand(temp.X()),
                                                   /* needs_null_check= */ false,
                                                   is_volatile);
  } else {
    // Other cases.
    MemOperand mem_op(base.X(), offset);
    if (is_volatile) {
      codegen->LoadAcquire(invoke, type, trg, mem_op, /* needs_null_check= */ true);
    } else {
      codegen->Load(type, trg, mem_op);
    }

    if (type == DataType::Type::kReference) {
      DCHECK(trg.IsW());
      codegen->MaybeGenerateReadBarrierSlow(invoke, trg_loc, trg_loc, base_loc, 0u, offset_loc);
    }
  }
}

static void CreateIntIntIntToIntLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  bool can_call = kEmitCompilerReadBarrier &&
      (invoke->GetIntrinsic() == Intrinsics::kUnsafeGetObject ||
       invoke->GetIntrinsic() == Intrinsics::kUnsafeGetObjectVolatile);
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke,
                                      can_call
                                          ? LocationSummary::kCallOnSlowPath
                                          : LocationSummary::kNoCall,
                                      kIntrinsified);
  if (can_call && kUseBakerReadBarrier) {
    locations->SetCustomSlowPathCallerSaves(RegisterSet::Empty());  // No caller-save registers.
    // We need a temporary register for the read barrier load in order to use
    // CodeGeneratorARM64::GenerateFieldLoadWithBakerReadBarrier().
    locations->AddTemp(FixedTempLocation());
  }
  locations->SetInAt(0, Location::NoLocation());        // Unused receiver.
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetInAt(2, Location::RequiresRegister());
  locations->SetOut(Location::RequiresRegister(),
                    (can_call ? Location::kOutputOverlap : Location::kNoOutputOverlap));
}

void IntrinsicLocationsBuilderARM64::VisitUnsafeGet(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafeGetVolatile(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafeGetLong(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafeGetLongVolatile(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafeGetObject(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafeGetObjectVolatile(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitUnsafeGet(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kInt32, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafeGetVolatile(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kInt32, /* is_volatile= */ true, codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafeGetLong(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kInt64, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafeGetLongVolatile(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kInt64, /* is_volatile= */ true, codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafeGetObject(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kReference, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafeGetObjectVolatile(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kReference, /* is_volatile= */ true, codegen_);
}

static void CreateIntIntIntIntToVoid(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::NoLocation());        // Unused receiver.
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetInAt(2, Location::RequiresRegister());
  locations->SetInAt(3, Location::RequiresRegister());
}

void IntrinsicLocationsBuilderARM64::VisitUnsafePut(HInvoke* invoke) {
  CreateIntIntIntIntToVoid(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafePutOrdered(HInvoke* invoke) {
  CreateIntIntIntIntToVoid(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafePutVolatile(HInvoke* invoke) {
  CreateIntIntIntIntToVoid(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafePutObject(HInvoke* invoke) {
  CreateIntIntIntIntToVoid(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafePutObjectOrdered(HInvoke* invoke) {
  CreateIntIntIntIntToVoid(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafePutObjectVolatile(HInvoke* invoke) {
  CreateIntIntIntIntToVoid(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafePutLong(HInvoke* invoke) {
  CreateIntIntIntIntToVoid(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafePutLongOrdered(HInvoke* invoke) {
  CreateIntIntIntIntToVoid(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafePutLongVolatile(HInvoke* invoke) {
  CreateIntIntIntIntToVoid(allocator_, invoke);
}

static void GenUnsafePut(HInvoke* invoke,
                         DataType::Type type,
                         bool is_volatile,
                         bool is_ordered,
                         CodeGeneratorARM64* codegen) {
  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = codegen->GetVIXLAssembler();

  Register base = WRegisterFrom(locations->InAt(1));    // Object pointer.
  Register offset = XRegisterFrom(locations->InAt(2));  // Long offset.
  Register value = RegisterFrom(locations->InAt(3), type);
  Register source = value;
  MemOperand mem_op(base.X(), offset);

  {
    // We use a block to end the scratch scope before the write barrier, thus
    // freeing the temporary registers so they can be used in `MarkGCCard`.
    UseScratchRegisterScope temps(masm);

    if (kPoisonHeapReferences && type == DataType::Type::kReference) {
      DCHECK(value.IsW());
      Register temp = temps.AcquireW();
      __ Mov(temp.W(), value.W());
      codegen->GetAssembler()->PoisonHeapReference(temp.W());
      source = temp;
    }

    if (is_volatile || is_ordered) {
      codegen->StoreRelease(invoke, type, source, mem_op, /* needs_null_check= */ false);
    } else {
      codegen->Store(type, source, mem_op);
    }
  }

  if (type == DataType::Type::kReference) {
    bool value_can_be_null = true;  // TODO: Worth finding out this information?
    codegen->MarkGCCard(base, value, value_can_be_null);
  }
}

void IntrinsicCodeGeneratorARM64::VisitUnsafePut(HInvoke* invoke) {
  GenUnsafePut(invoke,
               DataType::Type::kInt32,
               /* is_volatile= */ false,
               /* is_ordered= */ false,
               codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafePutOrdered(HInvoke* invoke) {
  GenUnsafePut(invoke,
               DataType::Type::kInt32,
               /* is_volatile= */ false,
               /* is_ordered= */ true,
               codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafePutVolatile(HInvoke* invoke) {
  GenUnsafePut(invoke,
               DataType::Type::kInt32,
               /* is_volatile= */ true,
               /* is_ordered= */ false,
               codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafePutObject(HInvoke* invoke) {
  GenUnsafePut(invoke,
               DataType::Type::kReference,
               /* is_volatile= */ false,
               /* is_ordered= */ false,
               codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafePutObjectOrdered(HInvoke* invoke) {
  GenUnsafePut(invoke,
               DataType::Type::kReference,
               /* is_volatile= */ false,
               /* is_ordered= */ true,
               codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafePutObjectVolatile(HInvoke* invoke) {
  GenUnsafePut(invoke,
               DataType::Type::kReference,
               /* is_volatile= */ true,
               /* is_ordered= */ false,
               codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafePutLong(HInvoke* invoke) {
  GenUnsafePut(invoke,
               DataType::Type::kInt64,
               /* is_volatile= */ false,
               /* is_ordered= */ false,
               codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafePutLongOrdered(HInvoke* invoke) {
  GenUnsafePut(invoke,
               DataType::Type::kInt64,
               /* is_volatile= */ false,
               /* is_ordered= */ true,
               codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafePutLongVolatile(HInvoke* invoke) {
  GenUnsafePut(invoke,
               DataType::Type::kInt64,
               /* is_volatile= */ true,
               /* is_ordered= */ false,
               codegen_);
}

static void CreateUnsafeCASLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  bool can_call = kEmitCompilerReadBarrier &&
      (invoke->GetIntrinsic() == Intrinsics::kUnsafeCASObject);
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke,
                                      can_call
                                          ? LocationSummary::kCallOnSlowPath
                                          : LocationSummary::kNoCall,
                                      kIntrinsified);
  if (can_call && kUseBakerReadBarrier) {
    locations->SetCustomSlowPathCallerSaves(RegisterSet::Empty());  // No caller-save registers.
  }
  locations->SetInAt(0, Location::NoLocation());        // Unused receiver.
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetInAt(2, Location::RequiresRegister());
  locations->SetInAt(3, Location::RequiresRegister());
  locations->SetInAt(4, Location::RequiresRegister());

  locations->SetOut(Location::RequiresRegister(), Location::kNoOutputOverlap);
}

static void EmitLoadExclusive(CodeGeneratorARM64* codegen,
                              DataType::Type type,
                              Register ptr,
                              Register old_value,
                              bool use_load_acquire) {
  Arm64Assembler* assembler = codegen->GetAssembler();
  MacroAssembler* masm = assembler->GetVIXLAssembler();
  switch (type) {
    case DataType::Type::kBool:
    case DataType::Type::kUint8:
    case DataType::Type::kInt8:
      if (use_load_acquire) {
        __ Ldaxrb(old_value, MemOperand(ptr));
      } else {
        __ Ldxrb(old_value, MemOperand(ptr));
      }
      break;
    case DataType::Type::kUint16:
    case DataType::Type::kInt16:
      if (use_load_acquire) {
        __ Ldaxrh(old_value, MemOperand(ptr));
      } else {
        __ Ldxrh(old_value, MemOperand(ptr));
      }
      break;
    case DataType::Type::kInt32:
    case DataType::Type::kInt64:
    case DataType::Type::kReference:
      if (use_load_acquire) {
        __ Ldaxr(old_value, MemOperand(ptr));
      } else {
        __ Ldxr(old_value, MemOperand(ptr));
      }
      break;
    default:
      LOG(FATAL) << "Unexpected type: " << type;
      UNREACHABLE();
  }
  switch (type) {
    case DataType::Type::kInt8:
      __ Sxtb(old_value, old_value);
      break;
    case DataType::Type::kInt16:
      __ Sxth(old_value, old_value);
      break;
    case DataType::Type::kReference:
      assembler->MaybeUnpoisonHeapReference(old_value);
      break;
    default:
      break;
  }
}

static void EmitStoreExclusive(CodeGeneratorARM64* codegen,
                               DataType::Type type,
                               Register ptr,
                               Register store_result,
                               Register new_value,
                               bool use_store_release) {
  Arm64Assembler* assembler = codegen->GetAssembler();
  MacroAssembler* masm = assembler->GetVIXLAssembler();
  if (type == DataType::Type::kReference) {
    assembler->MaybePoisonHeapReference(new_value);
  }
  switch (type) {
    case DataType::Type::kBool:
    case DataType::Type::kUint8:
    case DataType::Type::kInt8:
      if (use_store_release) {
        __ Stlxrb(store_result, new_value, MemOperand(ptr));
      } else {
        __ Stxrb(store_result, new_value, MemOperand(ptr));
      }
      break;
    case DataType::Type::kUint16:
    case DataType::Type::kInt16:
      if (use_store_release) {
        __ Stlxrh(store_result, new_value, MemOperand(ptr));
      } else {
        __ Stxrh(store_result, new_value, MemOperand(ptr));
      }
      break;
    case DataType::Type::kInt32:
    case DataType::Type::kInt64:
    case DataType::Type::kReference:
      if (use_store_release) {
        __ Stlxr(store_result, new_value, MemOperand(ptr));
      } else {
        __ Stxr(store_result, new_value, MemOperand(ptr));
      }
      break;
    default:
      LOG(FATAL) << "Unexpected type: " << type;
      UNREACHABLE();
  }
  if (type == DataType::Type::kReference) {
    assembler->MaybeUnpoisonHeapReference(new_value);
  }
}

static void GenerateCompareAndSet(CodeGeneratorARM64* codegen,
                                  DataType::Type type,
                                  std::memory_order order,
                                  bool strong,
                                  vixl::aarch64::Label* cmp_failure,
                                  Register ptr,
                                  Register new_value,
                                  Register old_value,
                                  Register store_result,
                                  Register expected,
                                  Register expected2 = Register()) {
  // The `expected2` is valid only for reference slow path and represents the unmarked old value
  // from the main path attempt to emit CAS when the marked old value matched `expected`.
  DCHECK(type == DataType::Type::kReference || !expected2.IsValid());

  DCHECK(ptr.IsX());
  DCHECK_EQ(new_value.IsX(), type == DataType::Type::kInt64);
  DCHECK_EQ(old_value.IsX(), type == DataType::Type::kInt64);
  DCHECK(store_result.IsW());
  DCHECK_EQ(expected.IsX(), type == DataType::Type::kInt64);
  DCHECK(!expected2.IsValid() || expected2.IsW());

  Arm64Assembler* assembler = codegen->GetAssembler();
  MacroAssembler* masm = assembler->GetVIXLAssembler();

  bool use_load_acquire =
      (order == std::memory_order_acquire) || (order == std::memory_order_seq_cst);
  bool use_store_release =
      (order == std::memory_order_release) || (order == std::memory_order_seq_cst);
  DCHECK(use_load_acquire || use_store_release || order == std::memory_order_relaxed);

  // repeat: {
  //   old_value = [ptr];  // Load exclusive.
  //   if (old_value != expected && old_value != expected2) goto cmp_failure;
  //   store_result = failed([ptr] <- new_value);  // Store exclusive.
  // }
  // if (strong) {
  //   if (store_result) goto repeat;  // Repeat until compare fails or store exclusive succeeds.
  // } else {
  //   store_result = store_result ^ 1;  // Report success as 1, failure as 0.
  // }
  //
  // Flag Z indicates whether `old_value == expected || old_value == expected2`.
  // (Is `expected2` is not valid, the `old_value == expected2` part is not emitted.)

  vixl::aarch64::Label loop_head;
  if (strong) {
    __ Bind(&loop_head);
  }
  EmitLoadExclusive(codegen, type, ptr, old_value, use_load_acquire);
  __ Cmp(old_value, expected);
  if (expected2.IsValid()) {
    __ Ccmp(old_value, expected2, ZFlag, ne);
  }
  // If the comparison failed, the Z flag is cleared as we branch to the `cmp_failure` label.
  // If the comparison succeeded, the Z flag is set and remains set after the end of the
  // code emitted here, unless we retry the whole operation.
  __ B(cmp_failure, ne);
  EmitStoreExclusive(codegen, type, ptr, store_result, new_value, use_store_release);
  if (strong) {
    __ Cbnz(store_result, &loop_head);
  } else {
    // Flip the `store_result` register to indicate success by 1 and failure by 0.
    __ Eor(store_result, store_result, 1);
  }
}

class ReadBarrierCasSlowPathARM64 : public SlowPathCodeARM64 {
 public:
  ReadBarrierCasSlowPathARM64(HInvoke* invoke,
                              std::memory_order order,
                              bool strong,
                              Register base,
                              Register offset,
                              Register expected,
                              Register new_value,
                              Register old_value,
                              Register old_value_temp,
                              Register store_result,
                              bool update_old_value,
                              CodeGeneratorARM64* arm64_codegen)
      : SlowPathCodeARM64(invoke),
        order_(order),
        strong_(strong),
        base_(base),
        offset_(offset),
        expected_(expected),
        new_value_(new_value),
        old_value_(old_value),
        old_value_temp_(old_value_temp),
        store_result_(store_result),
        update_old_value_(update_old_value),
        mark_old_value_slow_path_(nullptr),
        update_old_value_slow_path_(nullptr) {
    if (!kUseBakerReadBarrier) {
      // We need to add the slow path now, it is too late when emitting slow path code.
      mark_old_value_slow_path_ = arm64_codegen->AddReadBarrierSlowPath(
          invoke,
          Location::RegisterLocation(old_value_temp.GetCode()),
          Location::RegisterLocation(old_value.GetCode()),
          Location::RegisterLocation(base.GetCode()),
          /*offset=*/ 0u,
          /*index=*/ Location::RegisterLocation(offset.GetCode()));
      if (update_old_value_) {
        update_old_value_slow_path_ = arm64_codegen->AddReadBarrierSlowPath(
            invoke,
            Location::RegisterLocation(old_value.GetCode()),
            Location::RegisterLocation(old_value_temp.GetCode()),
            Location::RegisterLocation(base.GetCode()),
            /*offset=*/ 0u,
            /*index=*/ Location::RegisterLocation(offset.GetCode()));
      }
    }
  }

  const char* GetDescription() const override { return "ReadBarrierCasSlowPathARM64"; }

  void EmitNativeCode(CodeGenerator* codegen) override {
    CodeGeneratorARM64* arm64_codegen = down_cast<CodeGeneratorARM64*>(codegen);
    Arm64Assembler* assembler = arm64_codegen->GetAssembler();
    MacroAssembler* masm = assembler->GetVIXLAssembler();
    __ Bind(GetEntryLabel());

    // Mark the `old_value_` from the main path and compare with `expected_`.
    if (kUseBakerReadBarrier) {
      DCHECK(mark_old_value_slow_path_ == nullptr);
      arm64_codegen->GenerateIntrinsicCasMoveWithBakerReadBarrier(old_value_temp_, old_value_);
    } else {
      DCHECK(mark_old_value_slow_path_ != nullptr);
      __ B(mark_old_value_slow_path_->GetEntryLabel());
      __ Bind(mark_old_value_slow_path_->GetExitLabel());
    }
    __ Cmp(old_value_temp_, expected_);
    if (update_old_value_) {
      // Update the old value if we're going to return from the slow path.
      __ Csel(old_value_, old_value_temp_, old_value_, ne);
    }
    __ B(GetExitLabel(), ne);  // If taken, Z=false indicates failure.

    // The `old_value` we have read did not match `expected` (which is always a to-space
    // reference) but after the read barrier the marked to-space value matched, so the
    // `old_value` must be a from-space reference to the same object. Do the same CAS loop
    // as the main path but check for both `expected` and the unmarked old value
    // representing the to-space and from-space references for the same object.

    UseScratchRegisterScope temps(masm);
    DCHECK(!store_result_.IsValid() || !temps.IsAvailable(store_result_));
    Register tmp_ptr = temps.AcquireX();
    Register store_result = store_result_.IsValid() ? store_result_ : temps.AcquireW();

    // Recalculate the `tmp_ptr` from main path clobbered by the read barrier above.
    __ Add(tmp_ptr, base_.X(), Operand(offset_));

    vixl::aarch64::Label mark_old_value;
    GenerateCompareAndSet(arm64_codegen,
                          DataType::Type::kReference,
                          order_,
                          strong_,
                          /*cmp_failure=*/ update_old_value_ ? &mark_old_value : GetExitLabel(),
                          tmp_ptr,
                          new_value_,
                          /*old_value=*/ old_value_temp_,
                          store_result,
                          expected_,
                          /*expected2=*/ old_value_);
    if (update_old_value_) {
      // To reach this point, the `old_value_temp_` must be either a from-space or a to-space
      // reference of the `expected_` object. Update the `old_value_` to the to-space reference.
      __ Mov(old_value_, expected_);
    }

    // Z=true from the CMP+CCMP in GenerateCompareAndSet() above indicates comparison success.
    // For strong CAS, that's the overall success. For weak CAS, the code also needs
    // to check the `store_result` after returning from the slow path.
    __ B(GetExitLabel());

    if (update_old_value_) {
      __ Bind(&mark_old_value);
      if (kUseBakerReadBarrier) {
        DCHECK(update_old_value_slow_path_ == nullptr);
        arm64_codegen->GenerateIntrinsicCasMoveWithBakerReadBarrier(old_value_, old_value_temp_);
      } else {
        // Note: We could redirect the `failure` above directly to the entry label and bind
        // the exit label in the main path, but the main path would need to access the
        // `update_old_value_slow_path_`. To keep the code simple, keep the extra jumps.
        DCHECK(update_old_value_slow_path_ != nullptr);
        __ B(update_old_value_slow_path_->GetEntryLabel());
        __ Bind(update_old_value_slow_path_->GetExitLabel());
      }
      __ B(GetExitLabel());
    }
  }

 private:
  std::memory_order order_;
  bool strong_;
  Register base_;
  Register offset_;
  Register expected_;
  Register new_value_;
  Register old_value_;
  Register old_value_temp_;
  Register store_result_;
  bool update_old_value_;
  SlowPathCodeARM64* mark_old_value_slow_path_;
  SlowPathCodeARM64* update_old_value_slow_path_;
};

static void GenUnsafeCas(HInvoke* invoke, DataType::Type type, CodeGeneratorARM64* codegen) {
  MacroAssembler* masm = codegen->GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register out = WRegisterFrom(locations->Out());                 // Boolean result.
  Register base = WRegisterFrom(locations->InAt(1));              // Object pointer.
  Register offset = XRegisterFrom(locations->InAt(2));            // Long offset.
  Register expected = RegisterFrom(locations->InAt(3), type);     // Expected.
  Register new_value = RegisterFrom(locations->InAt(4), type);    // New value.

  // This needs to be before the temp registers, as MarkGCCard also uses VIXL temps.
  if (type == DataType::Type::kReference) {
    // Mark card for object assuming new value is stored.
    bool new_value_can_be_null = true;  // TODO: Worth finding out this information?
    codegen->MarkGCCard(base, new_value, new_value_can_be_null);
  }

  UseScratchRegisterScope temps(masm);
  Register tmp_ptr = temps.AcquireX();                             // Pointer to actual memory.
  Register old_value;                                              // Value in memory.

  vixl::aarch64::Label exit_loop_label;
  vixl::aarch64::Label* exit_loop = &exit_loop_label;
  vixl::aarch64::Label* cmp_failure = &exit_loop_label;

  if (kEmitCompilerReadBarrier && type == DataType::Type::kReference) {
    // We need to store the `old_value` in a non-scratch register to make sure
    // the read barrier in the slow path does not clobber it.
    old_value = WRegisterFrom(locations->GetTemp(0));  // The old value from main path.
    // The `old_value_temp` is used first for the marked `old_value` and then for the unmarked
    // reloaded old value for subsequent CAS in the slow path. It cannot be a scratch register.
    Register old_value_temp = WRegisterFrom(locations->GetTemp(1));
    ReadBarrierCasSlowPathARM64* slow_path =
        new (codegen->GetScopedAllocator()) ReadBarrierCasSlowPathARM64(
            invoke,
            std::memory_order_seq_cst,
            /*strong=*/ true,
            base,
            offset,
            expected,
            new_value,
            old_value,
            old_value_temp,
            /*store_result=*/ Register(),  // Use a scratch register.
            /*update_old_value=*/ false,
            codegen);
    codegen->AddSlowPath(slow_path);
    exit_loop = slow_path->GetExitLabel();
    cmp_failure = slow_path->GetEntryLabel();
  } else {
    old_value = temps.AcquireSameSizeAs(new_value);
  }

  __ Add(tmp_ptr, base.X(), Operand(offset));

  GenerateCompareAndSet(codegen,
                        type,
                        std::memory_order_seq_cst,
                        /*strong=*/ true,
                        cmp_failure,
                        tmp_ptr,
                        new_value,
                        old_value,
                        /*store_result=*/ old_value.W(),  // Reuse `old_value` for ST*XR* result.
                        expected);
  __ Bind(exit_loop);
  __ Cset(out, eq);
}

void IntrinsicLocationsBuilderARM64::VisitUnsafeCASInt(HInvoke* invoke) {
  CreateUnsafeCASLocations(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafeCASLong(HInvoke* invoke) {
  CreateUnsafeCASLocations(allocator_, invoke);
}
void IntrinsicLocationsBuilderARM64::VisitUnsafeCASObject(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // UnsafeCASObject intrinsic is the Baker-style read barriers. b/173104084
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  CreateUnsafeCASLocations(allocator_, invoke);
  if (kEmitCompilerReadBarrier) {
    // We need two non-scratch temporary registers for read barrier.
    LocationSummary* locations = invoke->GetLocations();
    if (kUseBakerReadBarrier) {
      locations->AddTemp(Location::RequiresRegister());
      locations->AddTemp(Location::RequiresRegister());
    } else {
      // To preserve the old value across the non-Baker read barrier
      // slow path, use a fixed callee-save register.
      constexpr int first_callee_save = CTZ(kArm64CalleeSaveRefSpills);
      locations->AddTemp(Location::RegisterLocation(first_callee_save));
      // To reduce the number of moves, request x0 as the second temporary.
      DCHECK(InvokeRuntimeCallingConvention().GetReturnLocation(DataType::Type::kReference).Equals(
                 Location::RegisterLocation(x0.GetCode())));
      locations->AddTemp(Location::RegisterLocation(x0.GetCode()));
    }
  }
}

void IntrinsicCodeGeneratorARM64::VisitUnsafeCASInt(HInvoke* invoke) {
  GenUnsafeCas(invoke, DataType::Type::kInt32, codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafeCASLong(HInvoke* invoke) {
  GenUnsafeCas(invoke, DataType::Type::kInt64, codegen_);
}
void IntrinsicCodeGeneratorARM64::VisitUnsafeCASObject(HInvoke* invoke) {
  GenUnsafeCas(invoke, DataType::Type::kReference, codegen_);
}

enum class GetAndUpdateOp {
  kSet,
  kAdd,
  kAddWithByteSwap,
  kAnd,
  kOr,
  kXor
};

static void GenerateGetAndUpdate(CodeGeneratorARM64* codegen,
                                 GetAndUpdateOp get_and_update_op,
                                 DataType::Type load_store_type,
                                 std::memory_order order,
                                 Register ptr,
                                 CPURegister arg,
                                 CPURegister old_value) {
  MacroAssembler* masm = codegen->GetVIXLAssembler();
  UseScratchRegisterScope temps(masm);
  Register store_result = temps.AcquireW();

  DCHECK_EQ(old_value.GetSizeInBits(), arg.GetSizeInBits());
  Register old_value_reg;
  Register new_value;
  switch (get_and_update_op) {
    case GetAndUpdateOp::kSet:
      old_value_reg = old_value.IsX() ? old_value.X() : old_value.W();
      new_value = arg.IsX() ? arg.X() : arg.W();
      break;
    case GetAndUpdateOp::kAddWithByteSwap:
    case GetAndUpdateOp::kAdd:
      if (arg.IsVRegister()) {
        old_value_reg = arg.IsD() ? temps.AcquireX() : temps.AcquireW();
        new_value = old_value_reg;  // Use the same temporary.
        break;
      }
      FALLTHROUGH_INTENDED;
    case GetAndUpdateOp::kAnd:
    case GetAndUpdateOp::kOr:
    case GetAndUpdateOp::kXor:
      old_value_reg = old_value.IsX() ? old_value.X() : old_value.W();
      new_value = old_value.IsX() ? temps.AcquireX() : temps.AcquireW();
      break;
  }

  bool use_load_acquire =
      (order == std::memory_order_acquire) || (order == std::memory_order_seq_cst);
  bool use_store_release =
      (order == std::memory_order_release) || (order == std::memory_order_seq_cst);
  DCHECK(use_load_acquire || use_store_release);

  vixl::aarch64::Label loop_label;
  __ Bind(&loop_label);
  EmitLoadExclusive(codegen, load_store_type, ptr, old_value_reg, use_load_acquire);
  switch (get_and_update_op) {
    case GetAndUpdateOp::kSet:
      break;
    case GetAndUpdateOp::kAddWithByteSwap:
      // To avoid unnecessary sign extension before REV16, the caller must specify `kUint16`
      // instead of `kInt16` and do the sign-extension explicitly afterwards.
      DCHECK_NE(load_store_type, DataType::Type::kInt16);
      GenerateReverseBytes(masm, load_store_type, old_value_reg, old_value_reg);
      FALLTHROUGH_INTENDED;
    case GetAndUpdateOp::kAdd:
      if (arg.IsVRegister()) {
        VRegister old_value_vreg = old_value.IsD() ? old_value.D() : old_value.S();
        VRegister sum = temps.AcquireSameSizeAs(old_value_vreg);
        __ Fmov(old_value_vreg, old_value_reg);
        __ Fadd(sum, old_value_vreg, arg.IsD() ? arg.D() : arg.S());
        __ Fmov(new_value, sum);
      } else {
        __ Add(new_value, old_value_reg, arg.IsX() ? arg.X() : arg.W());
      }
      if (get_and_update_op == GetAndUpdateOp::kAddWithByteSwap) {
        GenerateReverseBytes(masm, load_store_type, new_value, new_value);
      }
      break;
    case GetAndUpdateOp::kAnd:
      __ And(new_value, old_value_reg, arg.IsX() ? arg.X() : arg.W());
      break;
    case GetAndUpdateOp::kOr:
      __ Orr(new_value, old_value_reg, arg.IsX() ? arg.X() : arg.W());
      break;
    case GetAndUpdateOp::kXor:
      __ Eor(new_value, old_value_reg, arg.IsX() ? arg.X() : arg.W());
      break;
  }
  EmitStoreExclusive(codegen, load_store_type, ptr, store_result, new_value, use_store_release);
  __ Cbnz(store_result, &loop_label);
}

void IntrinsicLocationsBuilderARM64::VisitStringCompareTo(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke,
                                       invoke->InputAt(1)->CanBeNull()
                                           ? LocationSummary::kCallOnSlowPath
                                           : LocationSummary::kNoCall,
                                       kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  // Need temporary registers for String compression's feature.
  if (mirror::kUseStringCompression) {
    locations->AddTemp(Location::RequiresRegister());
  }
  locations->SetOut(Location::RequiresRegister(), Location::kOutputOverlap);
}

void IntrinsicCodeGeneratorARM64::VisitStringCompareTo(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register str = InputRegisterAt(invoke, 0);
  Register arg = InputRegisterAt(invoke, 1);
  DCHECK(str.IsW());
  DCHECK(arg.IsW());
  Register out = OutputRegister(invoke);

  Register temp0 = WRegisterFrom(locations->GetTemp(0));
  Register temp1 = WRegisterFrom(locations->GetTemp(1));
  Register temp2 = WRegisterFrom(locations->GetTemp(2));
  Register temp3;
  if (mirror::kUseStringCompression) {
    temp3 = WRegisterFrom(locations->GetTemp(3));
  }

  vixl::aarch64::Label loop;
  vixl::aarch64::Label find_char_diff;
  vixl::aarch64::Label end;
  vixl::aarch64::Label different_compression;

  // Get offsets of count and value fields within a string object.
  const int32_t count_offset = mirror::String::CountOffset().Int32Value();
  const int32_t value_offset = mirror::String::ValueOffset().Int32Value();

  // Note that the null check must have been done earlier.
  DCHECK(!invoke->CanDoImplicitNullCheckOn(invoke->InputAt(0)));

  // Take slow path and throw if input can be and is null.
  SlowPathCodeARM64* slow_path = nullptr;
  const bool can_slow_path = invoke->InputAt(1)->CanBeNull();
  if (can_slow_path) {
    slow_path = new (codegen_->GetScopedAllocator()) IntrinsicSlowPathARM64(invoke);
    codegen_->AddSlowPath(slow_path);
    __ Cbz(arg, slow_path->GetEntryLabel());
  }

  // Reference equality check, return 0 if same reference.
  __ Subs(out, str, arg);
  __ B(&end, eq);

  if (mirror::kUseStringCompression) {
    // Load `count` fields of this and argument strings.
    __ Ldr(temp3, HeapOperand(str, count_offset));
    __ Ldr(temp2, HeapOperand(arg, count_offset));
    // Clean out compression flag from lengths.
    __ Lsr(temp0, temp3, 1u);
    __ Lsr(temp1, temp2, 1u);
  } else {
    // Load lengths of this and argument strings.
    __ Ldr(temp0, HeapOperand(str, count_offset));
    __ Ldr(temp1, HeapOperand(arg, count_offset));
  }
  // out = length diff.
  __ Subs(out, temp0, temp1);
  // temp0 = min(len(str), len(arg)).
  __ Csel(temp0, temp1, temp0, ge);
  // Shorter string is empty?
  __ Cbz(temp0, &end);

  if (mirror::kUseStringCompression) {
    // Check if both strings using same compression style to use this comparison loop.
    __ Eor(temp2, temp2, Operand(temp3));
    // Interleave with compression flag extraction which is needed for both paths
    // and also set flags which is needed only for the different compressions path.
    __ Ands(temp3.W(), temp3.W(), Operand(1));
    __ Tbnz(temp2, 0, &different_compression);  // Does not use flags.
  }
  // Store offset of string value in preparation for comparison loop.
  __ Mov(temp1, value_offset);
  if (mirror::kUseStringCompression) {
    // For string compression, calculate the number of bytes to compare (not chars).
    // This could in theory exceed INT32_MAX, so treat temp0 as unsigned.
    __ Lsl(temp0, temp0, temp3);
  }

  UseScratchRegisterScope scratch_scope(masm);
  Register temp4 = scratch_scope.AcquireX();

  // Assertions that must hold in order to compare strings 8 bytes at a time.
  DCHECK_ALIGNED(value_offset, 8);
  static_assert(IsAligned<8>(kObjectAlignment), "String of odd length is not zero padded");

  const size_t char_size = DataType::Size(DataType::Type::kUint16);
  DCHECK_EQ(char_size, 2u);

  // Promote temp2 to an X reg, ready for LDR.
  temp2 = temp2.X();

  // Loop to compare 4x16-bit characters at a time (ok because of string data alignment).
  __ Bind(&loop);
  __ Ldr(temp4, MemOperand(str.X(), temp1.X()));
  __ Ldr(temp2, MemOperand(arg.X(), temp1.X()));
  __ Cmp(temp4, temp2);
  __ B(ne, &find_char_diff);
  __ Add(temp1, temp1, char_size * 4);
  // With string compression, we have compared 8 bytes, otherwise 4 chars.
  __ Subs(temp0, temp0, (mirror::kUseStringCompression) ? 8 : 4);
  __ B(&loop, hi);
  __ B(&end);

  // Promote temp1 to an X reg, ready for EOR.
  temp1 = temp1.X();

  // Find the single character difference.
  __ Bind(&find_char_diff);
  // Get the bit position of the first character that differs.
  __ Eor(temp1, temp2, temp4);
  __ Rbit(temp1, temp1);
  __ Clz(temp1, temp1);

  // If the number of chars remaining <= the index where the difference occurs (0-3), then
  // the difference occurs outside the remaining string data, so just return length diff (out).
  // Unlike ARM, we're doing the comparison in one go here, without the subtraction at the
  // find_char_diff_2nd_cmp path, so it doesn't matter whether the comparison is signed or
  // unsigned when string compression is disabled.
  // When it's enabled, the comparison must be unsigned.
  __ Cmp(temp0, Operand(temp1.W(), LSR, (mirror::kUseStringCompression) ? 3 : 4));
  __ B(ls, &end);

  // Extract the characters and calculate the difference.
  if (mirror:: kUseStringCompression) {
    __ Bic(temp1, temp1, 0x7);
    __ Bic(temp1, temp1, Operand(temp3.X(), LSL, 3u));
  } else {
    __ Bic(temp1, temp1, 0xf);
  }
  __ Lsr(temp2, temp2, temp1);
  __ Lsr(temp4, temp4, temp1);
  if (mirror::kUseStringCompression) {
    // Prioritize the case of compressed strings and calculate such result first.
    __ Uxtb(temp1, temp4);
    __ Sub(out, temp1.W(), Operand(temp2.W(), UXTB));
    __ Tbz(temp3, 0u, &end);  // If actually compressed, we're done.
  }
  __ Uxth(temp4, temp4);
  __ Sub(out, temp4.W(), Operand(temp2.W(), UXTH));

  if (mirror::kUseStringCompression) {
    __ B(&end);
    __ Bind(&different_compression);

    // Comparison for different compression style.
    const size_t c_char_size = DataType::Size(DataType::Type::kInt8);
    DCHECK_EQ(c_char_size, 1u);
    temp1 = temp1.W();
    temp2 = temp2.W();
    temp4 = temp4.W();

    // `temp1` will hold the compressed data pointer, `temp2` the uncompressed data pointer.
    // Note that flags have been set by the `str` compression flag extraction to `temp3`
    // before branching to the `different_compression` label.
    __ Csel(temp1, str, arg, eq);   // Pointer to the compressed string.
    __ Csel(temp2, str, arg, ne);   // Pointer to the uncompressed string.

    // We want to free up the temp3, currently holding `str` compression flag, for comparison.
    // So, we move it to the bottom bit of the iteration count `temp0` which we then need to treat
    // as unsigned. Start by freeing the bit with a LSL and continue further down by a SUB which
    // will allow `subs temp0, #2; bhi different_compression_loop` to serve as the loop condition.
    __ Lsl(temp0, temp0, 1u);

    // Adjust temp1 and temp2 from string pointers to data pointers.
    __ Add(temp1, temp1, Operand(value_offset));
    __ Add(temp2, temp2, Operand(value_offset));

    // Complete the move of the compression flag.
    __ Sub(temp0, temp0, Operand(temp3));

    vixl::aarch64::Label different_compression_loop;
    vixl::aarch64::Label different_compression_diff;

    __ Bind(&different_compression_loop);
    __ Ldrb(temp4, MemOperand(temp1.X(), c_char_size, PostIndex));
    __ Ldrh(temp3, MemOperand(temp2.X(), char_size, PostIndex));
    __ Subs(temp4, temp4, Operand(temp3));
    __ B(&different_compression_diff, ne);
    __ Subs(temp0, temp0, 2);
    __ B(&different_compression_loop, hi);
    __ B(&end);

    // Calculate the difference.
    __ Bind(&different_compression_diff);
    __ Tst(temp0, Operand(1));
    static_assert(static_cast<uint32_t>(mirror::StringCompressionFlag::kCompressed) == 0u,
                  "Expecting 0=compressed, 1=uncompressed");
    __ Cneg(out, temp4, ne);
  }

  __ Bind(&end);

  if (can_slow_path) {
    __ Bind(slow_path->GetExitLabel());
  }
}

// The cut off for unrolling the loop in String.equals() intrinsic for const strings.
// The normal loop plus the pre-header is 9 instructions without string compression and 12
// instructions with string compression. We can compare up to 8 bytes in 4 instructions
// (LDR+LDR+CMP+BNE) and up to 16 bytes in 5 instructions (LDP+LDP+CMP+CCMP+BNE). Allow up
// to 10 instructions for the unrolled loop.
constexpr size_t kShortConstStringEqualsCutoffInBytes = 32;

static const char* GetConstString(HInstruction* candidate, uint32_t* utf16_length) {
  if (candidate->IsLoadString()) {
    HLoadString* load_string = candidate->AsLoadString();
    const DexFile& dex_file = load_string->GetDexFile();
    return dex_file.StringDataAndUtf16LengthByIdx(load_string->GetStringIndex(), utf16_length);
  }
  return nullptr;
}

void IntrinsicLocationsBuilderARM64::VisitStringEquals(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());

  // For the generic implementation and for long const strings we need a temporary.
  // We do not need it for short const strings, up to 8 bytes, see code generation below.
  uint32_t const_string_length = 0u;
  const char* const_string = GetConstString(invoke->InputAt(0), &const_string_length);
  if (const_string == nullptr) {
    const_string = GetConstString(invoke->InputAt(1), &const_string_length);
  }
  bool is_compressed =
      mirror::kUseStringCompression &&
      const_string != nullptr &&
      mirror::String::DexFileStringAllASCII(const_string, const_string_length);
  if (const_string == nullptr || const_string_length > (is_compressed ? 8u : 4u)) {
    locations->AddTemp(Location::RequiresRegister());
  }

  // TODO: If the String.equals() is used only for an immediately following HIf, we can
  // mark it as emitted-at-use-site and emit branches directly to the appropriate blocks.
  // Then we shall need an extra temporary register instead of the output register.
  locations->SetOut(Location::RequiresRegister(), Location::kOutputOverlap);
}

void IntrinsicCodeGeneratorARM64::VisitStringEquals(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register str = WRegisterFrom(locations->InAt(0));
  Register arg = WRegisterFrom(locations->InAt(1));
  Register out = XRegisterFrom(locations->Out());

  UseScratchRegisterScope scratch_scope(masm);
  Register temp = scratch_scope.AcquireW();
  Register temp1 = scratch_scope.AcquireW();

  vixl::aarch64::Label loop;
  vixl::aarch64::Label end;
  vixl::aarch64::Label return_true;
  vixl::aarch64::Label return_false;

  // Get offsets of count, value, and class fields within a string object.
  const int32_t count_offset = mirror::String::CountOffset().Int32Value();
  const int32_t value_offset = mirror::String::ValueOffset().Int32Value();
  const int32_t class_offset = mirror::Object::ClassOffset().Int32Value();

  // Note that the null check must have been done earlier.
  DCHECK(!invoke->CanDoImplicitNullCheckOn(invoke->InputAt(0)));

  StringEqualsOptimizations optimizations(invoke);
  if (!optimizations.GetArgumentNotNull()) {
    // Check if input is null, return false if it is.
    __ Cbz(arg, &return_false);
  }

  // Reference equality check, return true if same reference.
  __ Cmp(str, arg);
  __ B(&return_true, eq);

  if (!optimizations.GetArgumentIsString()) {
    // Instanceof check for the argument by comparing class fields.
    // All string objects must have the same type since String cannot be subclassed.
    // Receiver must be a string object, so its class field is equal to all strings' class fields.
    // If the argument is a string object, its class field must be equal to receiver's class field.
    //
    // As the String class is expected to be non-movable, we can read the class
    // field from String.equals' arguments without read barriers.
    AssertNonMovableStringClass();
    // /* HeapReference<Class> */ temp = str->klass_
    __ Ldr(temp, MemOperand(str.X(), class_offset));
    // /* HeapReference<Class> */ temp1 = arg->klass_
    __ Ldr(temp1, MemOperand(arg.X(), class_offset));
    // Also, because we use the previously loaded class references only in the
    // following comparison, we don't need to unpoison them.
    __ Cmp(temp, temp1);
    __ B(&return_false, ne);
  }

  // Check if one of the inputs is a const string. Do not special-case both strings
  // being const, such cases should be handled by constant folding if needed.
  uint32_t const_string_length = 0u;
  const char* const_string = GetConstString(invoke->InputAt(0), &const_string_length);
  if (const_string == nullptr) {
    const_string = GetConstString(invoke->InputAt(1), &const_string_length);
    if (const_string != nullptr) {
      std::swap(str, arg);  // Make sure the const string is in `str`.
    }
  }
  bool is_compressed =
      mirror::kUseStringCompression &&
      const_string != nullptr &&
      mirror::String::DexFileStringAllASCII(const_string, const_string_length);

  if (const_string != nullptr) {
    // Load `count` field of the argument string and check if it matches the const string.
    // Also compares the compression style, if differs return false.
    __ Ldr(temp, MemOperand(arg.X(), count_offset));
    // Temporarily release temp1 as we may not be able to embed the flagged count in CMP immediate.
    scratch_scope.Release(temp1);
    __ Cmp(temp, Operand(mirror::String::GetFlaggedCount(const_string_length, is_compressed)));
    temp1 = scratch_scope.AcquireW();
    __ B(&return_false, ne);
  } else {
    // Load `count` fields of this and argument strings.
    __ Ldr(temp, MemOperand(str.X(), count_offset));
    __ Ldr(temp1, MemOperand(arg.X(), count_offset));
    // Check if `count` fields are equal, return false if they're not.
    // Also compares the compression style, if differs return false.
    __ Cmp(temp, temp1);
    __ B(&return_false, ne);
  }

  // Assertions that must hold in order to compare strings 8 bytes at a time.
  // Ok to do this because strings are zero-padded to kObjectAlignment.
  DCHECK_ALIGNED(value_offset, 8);
  static_assert(IsAligned<8>(kObjectAlignment), "String of odd length is not zero padded");

  if (const_string != nullptr &&
      const_string_length <= (is_compressed ? kShortConstStringEqualsCutoffInBytes
                                            : kShortConstStringEqualsCutoffInBytes / 2u)) {
    // Load and compare the contents. Though we know the contents of the short const string
    // at compile time, materializing constants may be more code than loading from memory.
    int32_t offset = value_offset;
    size_t remaining_bytes =
        RoundUp(is_compressed ? const_string_length : const_string_length * 2u, 8u);
    temp = temp.X();
    temp1 = temp1.X();
    while (remaining_bytes > sizeof(uint64_t)) {
      Register temp2 = XRegisterFrom(locations->GetTemp(0));
      __ Ldp(temp, temp1, MemOperand(str.X(), offset));
      __ Ldp(temp2, out, MemOperand(arg.X(), offset));
      __ Cmp(temp, temp2);
      __ Ccmp(temp1, out, NoFlag, eq);
      __ B(&return_false, ne);
      offset += 2u * sizeof(uint64_t);
      remaining_bytes -= 2u * sizeof(uint64_t);
    }
    if (remaining_bytes != 0u) {
      __ Ldr(temp, MemOperand(str.X(), offset));
      __ Ldr(temp1, MemOperand(arg.X(), offset));
      __ Cmp(temp, temp1);
      __ B(&return_false, ne);
    }
  } else {
    // Return true if both strings are empty. Even with string compression `count == 0` means empty.
    static_assert(static_cast<uint32_t>(mirror::StringCompressionFlag::kCompressed) == 0u,
                  "Expecting 0=compressed, 1=uncompressed");
    __ Cbz(temp, &return_true);

    if (mirror::kUseStringCompression) {
      // For string compression, calculate the number of bytes to compare (not chars).
      // This could in theory exceed INT32_MAX, so treat temp as unsigned.
      __ And(temp1, temp, Operand(1));    // Extract compression flag.
      __ Lsr(temp, temp, 1u);             // Extract length.
      __ Lsl(temp, temp, temp1);          // Calculate number of bytes to compare.
    }

    // Store offset of string value in preparation for comparison loop
    __ Mov(temp1, value_offset);

    temp1 = temp1.X();
    Register temp2 = XRegisterFrom(locations->GetTemp(0));
    // Loop to compare strings 8 bytes at a time starting at the front of the string.
    __ Bind(&loop);
    __ Ldr(out, MemOperand(str.X(), temp1));
    __ Ldr(temp2, MemOperand(arg.X(), temp1));
    __ Add(temp1, temp1, Operand(sizeof(uint64_t)));
    __ Cmp(out, temp2);
    __ B(&return_false, ne);
    // With string compression, we have compared 8 bytes, otherwise 4 chars.
    __ Sub(temp, temp, Operand(mirror::kUseStringCompression ? 8 : 4), SetFlags);
    __ B(&loop, hi);
  }

  // Return true and exit the function.
  // If loop does not result in returning false, we return true.
  __ Bind(&return_true);
  __ Mov(out, 1);
  __ B(&end);

  // Return false and exit the function.
  __ Bind(&return_false);
  __ Mov(out, 0);
  __ Bind(&end);
}

static void GenerateVisitStringIndexOf(HInvoke* invoke,
                                       MacroAssembler* masm,
                                       CodeGeneratorARM64* codegen,
                                       bool start_at_zero) {
  LocationSummary* locations = invoke->GetLocations();

  // Note that the null check must have been done earlier.
  DCHECK(!invoke->CanDoImplicitNullCheckOn(invoke->InputAt(0)));

  // Check for code points > 0xFFFF. Either a slow-path check when we don't know statically,
  // or directly dispatch for a large constant, or omit slow-path for a small constant or a char.
  SlowPathCodeARM64* slow_path = nullptr;
  HInstruction* code_point = invoke->InputAt(1);
  if (code_point->IsIntConstant()) {
    if (static_cast<uint32_t>(code_point->AsIntConstant()->GetValue()) > 0xFFFFU) {
      // Always needs the slow-path. We could directly dispatch to it, but this case should be
      // rare, so for simplicity just put the full slow-path down and branch unconditionally.
      slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathARM64(invoke);
      codegen->AddSlowPath(slow_path);
      __ B(slow_path->GetEntryLabel());
      __ Bind(slow_path->GetExitLabel());
      return;
    }
  } else if (code_point->GetType() != DataType::Type::kUint16) {
    Register char_reg = WRegisterFrom(locations->InAt(1));
    __ Tst(char_reg, 0xFFFF0000);
    slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathARM64(invoke);
    codegen->AddSlowPath(slow_path);
    __ B(ne, slow_path->GetEntryLabel());
  }

  if (start_at_zero) {
    // Start-index = 0.
    Register tmp_reg = WRegisterFrom(locations->GetTemp(0));
    __ Mov(tmp_reg, 0);
  }

  codegen->InvokeRuntime(kQuickIndexOf, invoke, invoke->GetDexPc(), slow_path);
  CheckEntrypointTypes<kQuickIndexOf, int32_t, void*, uint32_t, uint32_t>();

  if (slow_path != nullptr) {
    __ Bind(slow_path->GetExitLabel());
  }
}

void IntrinsicLocationsBuilderARM64::VisitStringIndexOf(HInvoke* invoke) {
  LocationSummary* locations = new (allocator_) LocationSummary(
      invoke, LocationSummary::kCallOnMainAndSlowPath, kIntrinsified);
  // We have a hand-crafted assembly stub that follows the runtime calling convention. So it's
  // best to align the inputs accordingly.
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, LocationFrom(calling_convention.GetRegisterAt(0)));
  locations->SetInAt(1, LocationFrom(calling_convention.GetRegisterAt(1)));
  locations->SetOut(calling_convention.GetReturnLocation(DataType::Type::kInt32));

  // Need to send start_index=0.
  locations->AddTemp(LocationFrom(calling_convention.GetRegisterAt(2)));
}

void IntrinsicCodeGeneratorARM64::VisitStringIndexOf(HInvoke* invoke) {
  GenerateVisitStringIndexOf(invoke, GetVIXLAssembler(), codegen_, /* start_at_zero= */ true);
}

void IntrinsicLocationsBuilderARM64::VisitStringIndexOfAfter(HInvoke* invoke) {
  LocationSummary* locations = new (allocator_) LocationSummary(
      invoke, LocationSummary::kCallOnMainAndSlowPath, kIntrinsified);
  // We have a hand-crafted assembly stub that follows the runtime calling convention. So it's
  // best to align the inputs accordingly.
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, LocationFrom(calling_convention.GetRegisterAt(0)));
  locations->SetInAt(1, LocationFrom(calling_convention.GetRegisterAt(1)));
  locations->SetInAt(2, LocationFrom(calling_convention.GetRegisterAt(2)));
  locations->SetOut(calling_convention.GetReturnLocation(DataType::Type::kInt32));
}

void IntrinsicCodeGeneratorARM64::VisitStringIndexOfAfter(HInvoke* invoke) {
  GenerateVisitStringIndexOf(invoke, GetVIXLAssembler(), codegen_, /* start_at_zero= */ false);
}

void IntrinsicLocationsBuilderARM64::VisitStringNewStringFromBytes(HInvoke* invoke) {
  LocationSummary* locations = new (allocator_) LocationSummary(
      invoke, LocationSummary::kCallOnMainAndSlowPath, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, LocationFrom(calling_convention.GetRegisterAt(0)));
  locations->SetInAt(1, LocationFrom(calling_convention.GetRegisterAt(1)));
  locations->SetInAt(2, LocationFrom(calling_convention.GetRegisterAt(2)));
  locations->SetInAt(3, LocationFrom(calling_convention.GetRegisterAt(3)));
  locations->SetOut(calling_convention.GetReturnLocation(DataType::Type::kReference));
}

void IntrinsicCodeGeneratorARM64::VisitStringNewStringFromBytes(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register byte_array = WRegisterFrom(locations->InAt(0));
  __ Cmp(byte_array, 0);
  SlowPathCodeARM64* slow_path =
      new (codegen_->GetScopedAllocator()) IntrinsicSlowPathARM64(invoke);
  codegen_->AddSlowPath(slow_path);
  __ B(eq, slow_path->GetEntryLabel());

  codegen_->InvokeRuntime(kQuickAllocStringFromBytes, invoke, invoke->GetDexPc(), slow_path);
  CheckEntrypointTypes<kQuickAllocStringFromBytes, void*, void*, int32_t, int32_t, int32_t>();
  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderARM64::VisitStringNewStringFromChars(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kCallOnMainOnly, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, LocationFrom(calling_convention.GetRegisterAt(0)));
  locations->SetInAt(1, LocationFrom(calling_convention.GetRegisterAt(1)));
  locations->SetInAt(2, LocationFrom(calling_convention.GetRegisterAt(2)));
  locations->SetOut(calling_convention.GetReturnLocation(DataType::Type::kReference));
}

void IntrinsicCodeGeneratorARM64::VisitStringNewStringFromChars(HInvoke* invoke) {
  // No need to emit code checking whether `locations->InAt(2)` is a null
  // pointer, as callers of the native method
  //
  //   java.lang.StringFactory.newStringFromChars(int offset, int charCount, char[] data)
  //
  // all include a null check on `data` before calling that method.
  codegen_->InvokeRuntime(kQuickAllocStringFromChars, invoke, invoke->GetDexPc());
  CheckEntrypointTypes<kQuickAllocStringFromChars, void*, int32_t, int32_t, void*>();
}

void IntrinsicLocationsBuilderARM64::VisitStringNewStringFromString(HInvoke* invoke) {
  LocationSummary* locations = new (allocator_) LocationSummary(
      invoke, LocationSummary::kCallOnMainAndSlowPath, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, LocationFrom(calling_convention.GetRegisterAt(0)));
  locations->SetOut(calling_convention.GetReturnLocation(DataType::Type::kReference));
}

void IntrinsicCodeGeneratorARM64::VisitStringNewStringFromString(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register string_to_copy = WRegisterFrom(locations->InAt(0));
  __ Cmp(string_to_copy, 0);
  SlowPathCodeARM64* slow_path =
      new (codegen_->GetScopedAllocator()) IntrinsicSlowPathARM64(invoke);
  codegen_->AddSlowPath(slow_path);
  __ B(eq, slow_path->GetEntryLabel());

  codegen_->InvokeRuntime(kQuickAllocStringFromString, invoke, invoke->GetDexPc(), slow_path);
  CheckEntrypointTypes<kQuickAllocStringFromString, void*, void*>();
  __ Bind(slow_path->GetExitLabel());
}

static void CreateFPToFPCallLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  DCHECK_EQ(invoke->GetNumberOfArguments(), 1U);
  DCHECK(DataType::IsFloatingPointType(invoke->InputAt(0)->GetType()));
  DCHECK(DataType::IsFloatingPointType(invoke->GetType()));

  LocationSummary* const locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kCallOnMainOnly, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;

  locations->SetInAt(0, LocationFrom(calling_convention.GetFpuRegisterAt(0)));
  locations->SetOut(calling_convention.GetReturnLocation(invoke->GetType()));
}

static void CreateFPFPToFPCallLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  DCHECK_EQ(invoke->GetNumberOfArguments(), 2U);
  DCHECK(DataType::IsFloatingPointType(invoke->InputAt(0)->GetType()));
  DCHECK(DataType::IsFloatingPointType(invoke->InputAt(1)->GetType()));
  DCHECK(DataType::IsFloatingPointType(invoke->GetType()));

  LocationSummary* const locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kCallOnMainOnly, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;

  locations->SetInAt(0, LocationFrom(calling_convention.GetFpuRegisterAt(0)));
  locations->SetInAt(1, LocationFrom(calling_convention.GetFpuRegisterAt(1)));
  locations->SetOut(calling_convention.GetReturnLocation(invoke->GetType()));
}

static void GenFPToFPCall(HInvoke* invoke,
                          CodeGeneratorARM64* codegen,
                          QuickEntrypointEnum entry) {
  codegen->InvokeRuntime(entry, invoke, invoke->GetDexPc());
}

void IntrinsicLocationsBuilderARM64::VisitMathCos(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathCos(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickCos);
}

void IntrinsicLocationsBuilderARM64::VisitMathSin(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathSin(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickSin);
}

void IntrinsicLocationsBuilderARM64::VisitMathAcos(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathAcos(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickAcos);
}

void IntrinsicLocationsBuilderARM64::VisitMathAsin(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathAsin(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickAsin);
}

void IntrinsicLocationsBuilderARM64::VisitMathAtan(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathAtan(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickAtan);
}

void IntrinsicLocationsBuilderARM64::VisitMathCbrt(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathCbrt(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickCbrt);
}

void IntrinsicLocationsBuilderARM64::VisitMathCosh(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathCosh(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickCosh);
}

void IntrinsicLocationsBuilderARM64::VisitMathExp(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathExp(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickExp);
}

void IntrinsicLocationsBuilderARM64::VisitMathExpm1(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathExpm1(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickExpm1);
}

void IntrinsicLocationsBuilderARM64::VisitMathLog(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathLog(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickLog);
}

void IntrinsicLocationsBuilderARM64::VisitMathLog10(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathLog10(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickLog10);
}

void IntrinsicLocationsBuilderARM64::VisitMathSinh(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathSinh(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickSinh);
}

void IntrinsicLocationsBuilderARM64::VisitMathTan(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathTan(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickTan);
}

void IntrinsicLocationsBuilderARM64::VisitMathTanh(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathTanh(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickTanh);
}

void IntrinsicLocationsBuilderARM64::VisitMathAtan2(HInvoke* invoke) {
  CreateFPFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathAtan2(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickAtan2);
}

void IntrinsicLocationsBuilderARM64::VisitMathPow(HInvoke* invoke) {
  CreateFPFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathPow(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickPow);
}

void IntrinsicLocationsBuilderARM64::VisitMathHypot(HInvoke* invoke) {
  CreateFPFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathHypot(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickHypot);
}

void IntrinsicLocationsBuilderARM64::VisitMathNextAfter(HInvoke* invoke) {
  CreateFPFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathNextAfter(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickNextAfter);
}

void IntrinsicLocationsBuilderARM64::VisitStringGetCharsNoCheck(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetInAt(2, Location::RequiresRegister());
  locations->SetInAt(3, Location::RequiresRegister());
  locations->SetInAt(4, Location::RequiresRegister());

  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
}

void IntrinsicCodeGeneratorARM64::VisitStringGetCharsNoCheck(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  // Check assumption that sizeof(Char) is 2 (used in scaling below).
  const size_t char_size = DataType::Size(DataType::Type::kUint16);
  DCHECK_EQ(char_size, 2u);

  // Location of data in char array buffer.
  const uint32_t data_offset = mirror::Array::DataOffset(char_size).Uint32Value();

  // Location of char array data in string.
  const uint32_t value_offset = mirror::String::ValueOffset().Uint32Value();

  // void getCharsNoCheck(int srcBegin, int srcEnd, char[] dst, int dstBegin);
  // Since getChars() calls getCharsNoCheck() - we use registers rather than constants.
  Register srcObj = XRegisterFrom(locations->InAt(0));
  Register srcBegin = XRegisterFrom(locations->InAt(1));
  Register srcEnd = XRegisterFrom(locations->InAt(2));
  Register dstObj = XRegisterFrom(locations->InAt(3));
  Register dstBegin = XRegisterFrom(locations->InAt(4));

  Register src_ptr = XRegisterFrom(locations->GetTemp(0));
  Register num_chr = XRegisterFrom(locations->GetTemp(1));
  Register tmp1 = XRegisterFrom(locations->GetTemp(2));

  UseScratchRegisterScope temps(masm);
  Register dst_ptr = temps.AcquireX();
  Register tmp2 = temps.AcquireX();

  vixl::aarch64::Label done;
  vixl::aarch64::Label compressed_string_vector_loop;
  vixl::aarch64::Label compressed_string_remainder;
  __ Sub(num_chr, srcEnd, srcBegin);
  // Early out for valid zero-length retrievals.
  __ Cbz(num_chr, &done);

  // dst address start to copy to.
  __ Add(dst_ptr, dstObj, Operand(data_offset));
  __ Add(dst_ptr, dst_ptr, Operand(dstBegin, LSL, 1));

  // src address to copy from.
  __ Add(src_ptr, srcObj, Operand(value_offset));
  vixl::aarch64::Label compressed_string_preloop;
  if (mirror::kUseStringCompression) {
    // Location of count in string.
    const uint32_t count_offset = mirror::String::CountOffset().Uint32Value();
    // String's length.
    __ Ldr(tmp2, MemOperand(srcObj, count_offset));
    __ Tbz(tmp2, 0, &compressed_string_preloop);
  }
  __ Add(src_ptr, src_ptr, Operand(srcBegin, LSL, 1));

  // Do the copy.
  vixl::aarch64::Label loop;
  vixl::aarch64::Label remainder;

  // Save repairing the value of num_chr on the < 8 character path.
  __ Subs(tmp1, num_chr, 8);
  __ B(lt, &remainder);

  // Keep the result of the earlier subs, we are going to fetch at least 8 characters.
  __ Mov(num_chr, tmp1);

  // Main loop used for longer fetches loads and stores 8x16-bit characters at a time.
  // (Unaligned addresses are acceptable here and not worth inlining extra code to rectify.)
  __ Bind(&loop);
  __ Ldp(tmp1, tmp2, MemOperand(src_ptr, char_size * 8, PostIndex));
  __ Subs(num_chr, num_chr, 8);
  __ Stp(tmp1, tmp2, MemOperand(dst_ptr, char_size * 8, PostIndex));
  __ B(ge, &loop);

  __ Adds(num_chr, num_chr, 8);
  __ B(eq, &done);

  // Main loop for < 8 character case and remainder handling. Loads and stores one
  // 16-bit Java character at a time.
  __ Bind(&remainder);
  __ Ldrh(tmp1, MemOperand(src_ptr, char_size, PostIndex));
  __ Subs(num_chr, num_chr, 1);
  __ Strh(tmp1, MemOperand(dst_ptr, char_size, PostIndex));
  __ B(gt, &remainder);
  __ B(&done);

  if (mirror::kUseStringCompression) {
    // For compressed strings, acquire a SIMD temporary register.
    VRegister vtmp1 = temps.AcquireVRegisterOfSize(kQRegSize);
    const size_t c_char_size = DataType::Size(DataType::Type::kInt8);
    DCHECK_EQ(c_char_size, 1u);
    __ Bind(&compressed_string_preloop);
    __ Add(src_ptr, src_ptr, Operand(srcBegin));

    // Save repairing the value of num_chr on the < 8 character path.
    __ Subs(tmp1, num_chr, 8);
    __ B(lt, &compressed_string_remainder);

    // Keep the result of the earlier subs, we are going to fetch at least 8 characters.
    __ Mov(num_chr, tmp1);

    // Main loop for compressed src, copying 8 characters (8-bit) to (16-bit) at a time.
    // Uses SIMD instructions.
    __ Bind(&compressed_string_vector_loop);
    __ Ld1(vtmp1.V8B(), MemOperand(src_ptr, c_char_size * 8, PostIndex));
    __ Subs(num_chr, num_chr, 8);
    __ Uxtl(vtmp1.V8H(), vtmp1.V8B());
    __ St1(vtmp1.V8H(), MemOperand(dst_ptr, char_size * 8, PostIndex));
    __ B(ge, &compressed_string_vector_loop);

    __ Adds(num_chr, num_chr, 8);
    __ B(eq, &done);

    // Loop for < 8 character case and remainder handling with a compressed src.
    // Copies 1 character (8-bit) to (16-bit) at a time.
    __ Bind(&compressed_string_remainder);
    __ Ldrb(tmp1, MemOperand(src_ptr, c_char_size, PostIndex));
    __ Strh(tmp1, MemOperand(dst_ptr, char_size, PostIndex));
    __ Subs(num_chr, num_chr, Operand(1));
    __ B(gt, &compressed_string_remainder);
  }

  __ Bind(&done);
}

// Mirrors ARRAYCOPY_SHORT_CHAR_ARRAY_THRESHOLD in libcore, so we can choose to use the native
// implementation there for longer copy lengths.
static constexpr int32_t kSystemArrayCopyCharThreshold = 32;

static void SetSystemArrayCopyLocationRequires(LocationSummary* locations,
                                               uint32_t at,
                                               HInstruction* input) {
  HIntConstant* const_input = input->AsIntConstant();
  if (const_input != nullptr && !vixl::aarch64::Assembler::IsImmAddSub(const_input->GetValue())) {
    locations->SetInAt(at, Location::RequiresRegister());
  } else {
    locations->SetInAt(at, Location::RegisterOrConstant(input));
  }
}

void IntrinsicLocationsBuilderARM64::VisitSystemArrayCopyChar(HInvoke* invoke) {
  // Check to see if we have known failures that will cause us to have to bail out
  // to the runtime, and just generate the runtime call directly.
  HIntConstant* src_pos = invoke->InputAt(1)->AsIntConstant();
  HIntConstant* dst_pos = invoke->InputAt(3)->AsIntConstant();

  // The positions must be non-negative.
  if ((src_pos != nullptr && src_pos->GetValue() < 0) ||
      (dst_pos != nullptr && dst_pos->GetValue() < 0)) {
    // We will have to fail anyways.
    return;
  }

  // The length must be >= 0 and not so long that we would (currently) prefer libcore's
  // native implementation.
  HIntConstant* length = invoke->InputAt(4)->AsIntConstant();
  if (length != nullptr) {
    int32_t len = length->GetValue();
    if (len < 0 || len > kSystemArrayCopyCharThreshold) {
      // Just call as normal.
      return;
    }
  }

  ArenaAllocator* allocator = invoke->GetBlock()->GetGraph()->GetAllocator();
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  // arraycopy(char[] src, int src_pos, char[] dst, int dst_pos, int length).
  locations->SetInAt(0, Location::RequiresRegister());
  SetSystemArrayCopyLocationRequires(locations, 1, invoke->InputAt(1));
  locations->SetInAt(2, Location::RequiresRegister());
  SetSystemArrayCopyLocationRequires(locations, 3, invoke->InputAt(3));
  SetSystemArrayCopyLocationRequires(locations, 4, invoke->InputAt(4));

  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
}

static void CheckSystemArrayCopyPosition(MacroAssembler* masm,
                                         const Location& pos,
                                         const Register& input,
                                         const Location& length,
                                         SlowPathCodeARM64* slow_path,
                                         const Register& temp,
                                         bool length_is_input_length = false) {
  const int32_t length_offset = mirror::Array::LengthOffset().Int32Value();
  if (pos.IsConstant()) {
    int32_t pos_const = pos.GetConstant()->AsIntConstant()->GetValue();
    if (pos_const == 0) {
      if (!length_is_input_length) {
        // Check that length(input) >= length.
        __ Ldr(temp, MemOperand(input, length_offset));
        __ Cmp(temp, OperandFrom(length, DataType::Type::kInt32));
        __ B(slow_path->GetEntryLabel(), lt);
      }
    } else {
      // Check that length(input) >= pos.
      __ Ldr(temp, MemOperand(input, length_offset));
      __ Subs(temp, temp, pos_const);
      __ B(slow_path->GetEntryLabel(), lt);

      // Check that (length(input) - pos) >= length.
      __ Cmp(temp, OperandFrom(length, DataType::Type::kInt32));
      __ B(slow_path->GetEntryLabel(), lt);
    }
  } else if (length_is_input_length) {
    // The only way the copy can succeed is if pos is zero.
    __ Cbnz(WRegisterFrom(pos), slow_path->GetEntryLabel());
  } else {
    // Check that pos >= 0.
    Register pos_reg = WRegisterFrom(pos);
    __ Tbnz(pos_reg, pos_reg.GetSizeInBits() - 1, slow_path->GetEntryLabel());

    // Check that pos <= length(input) && (length(input) - pos) >= length.
    __ Ldr(temp, MemOperand(input, length_offset));
    __ Subs(temp, temp, pos_reg);
    // Ccmp if length(input) >= pos, else definitely bail to slow path (N!=V == lt).
    __ Ccmp(temp, OperandFrom(length, DataType::Type::kInt32), NFlag, ge);
    __ B(slow_path->GetEntryLabel(), lt);
  }
}

// Compute base source address, base destination address, and end
// source address for System.arraycopy* intrinsics in `src_base`,
// `dst_base` and `src_end` respectively.
static void GenSystemArrayCopyAddresses(MacroAssembler* masm,
                                        DataType::Type type,
                                        const Register& src,
                                        const Location& src_pos,
                                        const Register& dst,
                                        const Location& dst_pos,
                                        const Location& copy_length,
                                        const Register& src_base,
                                        const Register& dst_base,
                                        const Register& src_end) {
  // This routine is used by the SystemArrayCopy and the SystemArrayCopyChar intrinsics.
  DCHECK(type == DataType::Type::kReference || type == DataType::Type::kUint16)
      << "Unexpected element type: " << type;
  const int32_t element_size = DataType::Size(type);
  const int32_t element_size_shift = DataType::SizeShift(type);
  const uint32_t data_offset = mirror::Array::DataOffset(element_size).Uint32Value();

  if (src_pos.IsConstant()) {
    int32_t constant = src_pos.GetConstant()->AsIntConstant()->GetValue();
    __ Add(src_base, src, element_size * constant + data_offset);
  } else {
    __ Add(src_base, src, data_offset);
    __ Add(src_base, src_base, Operand(XRegisterFrom(src_pos), LSL, element_size_shift));
  }

  if (dst_pos.IsConstant()) {
    int32_t constant = dst_pos.GetConstant()->AsIntConstant()->GetValue();
    __ Add(dst_base, dst, element_size * constant + data_offset);
  } else {
    __ Add(dst_base, dst, data_offset);
    __ Add(dst_base, dst_base, Operand(XRegisterFrom(dst_pos), LSL, element_size_shift));
  }

  if (copy_length.IsConstant()) {
    int32_t constant = copy_length.GetConstant()->AsIntConstant()->GetValue();
    __ Add(src_end, src_base, element_size * constant);
  } else {
    __ Add(src_end, src_base, Operand(XRegisterFrom(copy_length), LSL, element_size_shift));
  }
}

void IntrinsicCodeGeneratorARM64::VisitSystemArrayCopyChar(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();
  Register src = XRegisterFrom(locations->InAt(0));
  Location src_pos = locations->InAt(1);
  Register dst = XRegisterFrom(locations->InAt(2));
  Location dst_pos = locations->InAt(3);
  Location length = locations->InAt(4);

  SlowPathCodeARM64* slow_path =
      new (codegen_->GetScopedAllocator()) IntrinsicSlowPathARM64(invoke);
  codegen_->AddSlowPath(slow_path);

  // If source and destination are the same, take the slow path. Overlapping copy regions must be
  // copied in reverse and we can't know in all cases if it's needed.
  __ Cmp(src, dst);
  __ B(slow_path->GetEntryLabel(), eq);

  // Bail out if the source is null.
  __ Cbz(src, slow_path->GetEntryLabel());

  // Bail out if the destination is null.
  __ Cbz(dst, slow_path->GetEntryLabel());

  if (!length.IsConstant()) {
    // Merge the following two comparisons into one:
    //   If the length is negative, bail out (delegate to libcore's native implementation).
    //   If the length > 32 then (currently) prefer libcore's native implementation.
    __ Cmp(WRegisterFrom(length), kSystemArrayCopyCharThreshold);
    __ B(slow_path->GetEntryLabel(), hi);
  } else {
    // We have already checked in the LocationsBuilder for the constant case.
    DCHECK_GE(length.GetConstant()->AsIntConstant()->GetValue(), 0);
    DCHECK_LE(length.GetConstant()->AsIntConstant()->GetValue(), 32);
  }

  Register src_curr_addr = WRegisterFrom(locations->GetTemp(0));
  Register dst_curr_addr = WRegisterFrom(locations->GetTemp(1));
  Register src_stop_addr = WRegisterFrom(locations->GetTemp(2));

  CheckSystemArrayCopyPosition(masm,
                               src_pos,
                               src,
                               length,
                               slow_path,
                               src_curr_addr,
                               false);

  CheckSystemArrayCopyPosition(masm,
                               dst_pos,
                               dst,
                               length,
                               slow_path,
                               src_curr_addr,
                               false);

  src_curr_addr = src_curr_addr.X();
  dst_curr_addr = dst_curr_addr.X();
  src_stop_addr = src_stop_addr.X();

  GenSystemArrayCopyAddresses(masm,
                              DataType::Type::kUint16,
                              src,
                              src_pos,
                              dst,
                              dst_pos,
                              length,
                              src_curr_addr,
                              dst_curr_addr,
                              src_stop_addr);

  // Iterate over the arrays and do a raw copy of the chars.
  const int32_t char_size = DataType::Size(DataType::Type::kUint16);
  UseScratchRegisterScope temps(masm);
  Register tmp = temps.AcquireW();
  vixl::aarch64::Label loop, done;
  __ Bind(&loop);
  __ Cmp(src_curr_addr, src_stop_addr);
  __ B(&done, eq);
  __ Ldrh(tmp, MemOperand(src_curr_addr, char_size, PostIndex));
  __ Strh(tmp, MemOperand(dst_curr_addr, char_size, PostIndex));
  __ B(&loop);
  __ Bind(&done);

  __ Bind(slow_path->GetExitLabel());
}

// We can choose to use the native implementation there for longer copy lengths.
static constexpr int32_t kSystemArrayCopyThreshold = 128;

// CodeGenerator::CreateSystemArrayCopyLocationSummary use three temporary registers.
// We want to use two temporary registers in order to reduce the register pressure in arm64.
// So we don't use the CodeGenerator::CreateSystemArrayCopyLocationSummary.
void IntrinsicLocationsBuilderARM64::VisitSystemArrayCopy(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // SystemArrayCopy intrinsic is the Baker-style read barriers.
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  // Check to see if we have known failures that will cause us to have to bail out
  // to the runtime, and just generate the runtime call directly.
  HIntConstant* src_pos = invoke->InputAt(1)->AsIntConstant();
  HIntConstant* dest_pos = invoke->InputAt(3)->AsIntConstant();

  // The positions must be non-negative.
  if ((src_pos != nullptr && src_pos->GetValue() < 0) ||
      (dest_pos != nullptr && dest_pos->GetValue() < 0)) {
    // We will have to fail anyways.
    return;
  }

  // The length must be >= 0.
  HIntConstant* length = invoke->InputAt(4)->AsIntConstant();
  if (length != nullptr) {
    int32_t len = length->GetValue();
    if (len < 0 || len >= kSystemArrayCopyThreshold) {
      // Just call as normal.
      return;
    }
  }

  SystemArrayCopyOptimizations optimizations(invoke);

  if (optimizations.GetDestinationIsSource()) {
    if (src_pos != nullptr && dest_pos != nullptr && src_pos->GetValue() < dest_pos->GetValue()) {
      // We only support backward copying if source and destination are the same.
      return;
    }
  }

  if (optimizations.GetDestinationIsPrimitiveArray() || optimizations.GetSourceIsPrimitiveArray()) {
    // We currently don't intrinsify primitive copying.
    return;
  }

  ArenaAllocator* allocator = invoke->GetBlock()->GetGraph()->GetAllocator();
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  // arraycopy(Object src, int src_pos, Object dest, int dest_pos, int length).
  locations->SetInAt(0, Location::RequiresRegister());
  SetSystemArrayCopyLocationRequires(locations, 1, invoke->InputAt(1));
  locations->SetInAt(2, Location::RequiresRegister());
  SetSystemArrayCopyLocationRequires(locations, 3, invoke->InputAt(3));
  SetSystemArrayCopyLocationRequires(locations, 4, invoke->InputAt(4));

  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
    // Temporary register IP0, obtained from the VIXL scratch register
    // pool, cannot be used in ReadBarrierSystemArrayCopySlowPathARM64
    // (because that register is clobbered by ReadBarrierMarkRegX
    // entry points). It cannot be used in calls to
    // CodeGeneratorARM64::GenerateFieldLoadWithBakerReadBarrier
    // either. For these reasons, get a third extra temporary register
    // from the register allocator.
    locations->AddTemp(Location::RequiresRegister());
  } else {
    // Cases other than Baker read barriers: the third temporary will
    // be acquired from the VIXL scratch register pool.
  }
}

void IntrinsicCodeGeneratorARM64::VisitSystemArrayCopy(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // SystemArrayCopy intrinsic is the Baker-style read barriers.
  DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  uint32_t class_offset = mirror::Object::ClassOffset().Int32Value();
  uint32_t super_offset = mirror::Class::SuperClassOffset().Int32Value();
  uint32_t component_offset = mirror::Class::ComponentTypeOffset().Int32Value();
  uint32_t primitive_offset = mirror::Class::PrimitiveTypeOffset().Int32Value();
  uint32_t monitor_offset = mirror::Object::MonitorOffset().Int32Value();

  Register src = XRegisterFrom(locations->InAt(0));
  Location src_pos = locations->InAt(1);
  Register dest = XRegisterFrom(locations->InAt(2));
  Location dest_pos = locations->InAt(3);
  Location length = locations->InAt(4);
  Register temp1 = WRegisterFrom(locations->GetTemp(0));
  Location temp1_loc = LocationFrom(temp1);
  Register temp2 = WRegisterFrom(locations->GetTemp(1));
  Location temp2_loc = LocationFrom(temp2);

  SlowPathCodeARM64* intrinsic_slow_path =
      new (codegen_->GetScopedAllocator()) IntrinsicSlowPathARM64(invoke);
  codegen_->AddSlowPath(intrinsic_slow_path);

  vixl::aarch64::Label conditions_on_positions_validated;
  SystemArrayCopyOptimizations optimizations(invoke);

  // If source and destination are the same, we go to slow path if we need to do
  // forward copying.
  if (src_pos.IsConstant()) {
    int32_t src_pos_constant = src_pos.GetConstant()->AsIntConstant()->GetValue();
    if (dest_pos.IsConstant()) {
      int32_t dest_pos_constant = dest_pos.GetConstant()->AsIntConstant()->GetValue();
      if (optimizations.GetDestinationIsSource()) {
        // Checked when building locations.
        DCHECK_GE(src_pos_constant, dest_pos_constant);
      } else if (src_pos_constant < dest_pos_constant) {
        __ Cmp(src, dest);
        __ B(intrinsic_slow_path->GetEntryLabel(), eq);
      }
      // Checked when building locations.
      DCHECK(!optimizations.GetDestinationIsSource()
             || (src_pos_constant >= dest_pos.GetConstant()->AsIntConstant()->GetValue()));
    } else {
      if (!optimizations.GetDestinationIsSource()) {
        __ Cmp(src, dest);
        __ B(&conditions_on_positions_validated, ne);
      }
      __ Cmp(WRegisterFrom(dest_pos), src_pos_constant);
      __ B(intrinsic_slow_path->GetEntryLabel(), gt);
    }
  } else {
    if (!optimizations.GetDestinationIsSource()) {
      __ Cmp(src, dest);
      __ B(&conditions_on_positions_validated, ne);
    }
    __ Cmp(RegisterFrom(src_pos, invoke->InputAt(1)->GetType()),
           OperandFrom(dest_pos, invoke->InputAt(3)->GetType()));
    __ B(intrinsic_slow_path->GetEntryLabel(), lt);
  }

  __ Bind(&conditions_on_positions_validated);

  if (!optimizations.GetSourceIsNotNull()) {
    // Bail out if the source is null.
    __ Cbz(src, intrinsic_slow_path->GetEntryLabel());
  }

  if (!optimizations.GetDestinationIsNotNull() && !optimizations.GetDestinationIsSource()) {
    // Bail out if the destination is null.
    __ Cbz(dest, intrinsic_slow_path->GetEntryLabel());
  }

  // We have already checked in the LocationsBuilder for the constant case.
  if (!length.IsConstant() &&
      !optimizations.GetCountIsSourceLength() &&
      !optimizations.GetCountIsDestinationLength()) {
    // Merge the following two comparisons into one:
    //   If the length is negative, bail out (delegate to libcore's native implementation).
    //   If the length >= 128 then (currently) prefer native implementation.
    __ Cmp(WRegisterFrom(length), kSystemArrayCopyThreshold);
    __ B(intrinsic_slow_path->GetEntryLabel(), hs);
  }
  // Validity checks: source.
  CheckSystemArrayCopyPosition(masm,
                               src_pos,
                               src,
                               length,
                               intrinsic_slow_path,
                               temp1,
                               optimizations.GetCountIsSourceLength());

  // Validity checks: dest.
  CheckSystemArrayCopyPosition(masm,
                               dest_pos,
                               dest,
                               length,
                               intrinsic_slow_path,
                               temp1,
                               optimizations.GetCountIsDestinationLength());
  {
    // We use a block to end the scratch scope before the write barrier, thus
    // freeing the temporary registers so they can be used in `MarkGCCard`.
    UseScratchRegisterScope temps(masm);
    Location temp3_loc;  // Used only for Baker read barrier.
    Register temp3;
    if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
      temp3_loc = locations->GetTemp(2);
      temp3 = WRegisterFrom(temp3_loc);
    } else {
      temp3 = temps.AcquireW();
    }

    if (!optimizations.GetDoesNotNeedTypeCheck()) {
      // Check whether all elements of the source array are assignable to the component
      // type of the destination array. We do two checks: the classes are the same,
      // or the destination is Object[]. If none of these checks succeed, we go to the
      // slow path.

      if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
        if (!optimizations.GetSourceIsNonPrimitiveArray()) {
          // /* HeapReference<Class> */ temp1 = src->klass_
          codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                          temp1_loc,
                                                          src.W(),
                                                          class_offset,
                                                          temp3_loc,
                                                          /* needs_null_check= */ false,
                                                          /* use_load_acquire= */ false);
          // Bail out if the source is not a non primitive array.
          // /* HeapReference<Class> */ temp1 = temp1->component_type_
          codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                          temp1_loc,
                                                          temp1,
                                                          component_offset,
                                                          temp3_loc,
                                                          /* needs_null_check= */ false,
                                                          /* use_load_acquire= */ false);
          __ Cbz(temp1, intrinsic_slow_path->GetEntryLabel());
          // If heap poisoning is enabled, `temp1` has been unpoisoned
          // by the the previous call to GenerateFieldLoadWithBakerReadBarrier.
          // /* uint16_t */ temp1 = static_cast<uint16>(temp1->primitive_type_);
          __ Ldrh(temp1, HeapOperand(temp1, primitive_offset));
          static_assert(Primitive::kPrimNot == 0, "Expected 0 for kPrimNot");
          __ Cbnz(temp1, intrinsic_slow_path->GetEntryLabel());
        }

        // /* HeapReference<Class> */ temp1 = dest->klass_
        codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                        temp1_loc,
                                                        dest.W(),
                                                        class_offset,
                                                        temp3_loc,
                                                        /* needs_null_check= */ false,
                                                        /* use_load_acquire= */ false);

        if (!optimizations.GetDestinationIsNonPrimitiveArray()) {
          // Bail out if the destination is not a non primitive array.
          //
          // Register `temp1` is not trashed by the read barrier emitted
          // by GenerateFieldLoadWithBakerReadBarrier below, as that
          // method produces a call to a ReadBarrierMarkRegX entry point,
          // which saves all potentially live registers, including
          // temporaries such a `temp1`.
          // /* HeapReference<Class> */ temp2 = temp1->component_type_
          codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                          temp2_loc,
                                                          temp1,
                                                          component_offset,
                                                          temp3_loc,
                                                          /* needs_null_check= */ false,
                                                          /* use_load_acquire= */ false);
          __ Cbz(temp2, intrinsic_slow_path->GetEntryLabel());
          // If heap poisoning is enabled, `temp2` has been unpoisoned
          // by the the previous call to GenerateFieldLoadWithBakerReadBarrier.
          // /* uint16_t */ temp2 = static_cast<uint16>(temp2->primitive_type_);
          __ Ldrh(temp2, HeapOperand(temp2, primitive_offset));
          static_assert(Primitive::kPrimNot == 0, "Expected 0 for kPrimNot");
          __ Cbnz(temp2, intrinsic_slow_path->GetEntryLabel());
        }

        // For the same reason given earlier, `temp1` is not trashed by the
        // read barrier emitted by GenerateFieldLoadWithBakerReadBarrier below.
        // /* HeapReference<Class> */ temp2 = src->klass_
        codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                        temp2_loc,
                                                        src.W(),
                                                        class_offset,
                                                        temp3_loc,
                                                        /* needs_null_check= */ false,
                                                        /* use_load_acquire= */ false);
        // Note: if heap poisoning is on, we are comparing two unpoisoned references here.
        __ Cmp(temp1, temp2);

        if (optimizations.GetDestinationIsTypedObjectArray()) {
          vixl::aarch64::Label do_copy;
          __ B(&do_copy, eq);
          // /* HeapReference<Class> */ temp1 = temp1->component_type_
          codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                          temp1_loc,
                                                          temp1,
                                                          component_offset,
                                                          temp3_loc,
                                                          /* needs_null_check= */ false,
                                                          /* use_load_acquire= */ false);
          // /* HeapReference<Class> */ temp1 = temp1->super_class_
          // We do not need to emit a read barrier for the following
          // heap reference load, as `temp1` is only used in a
          // comparison with null below, and this reference is not
          // kept afterwards.
          __ Ldr(temp1, HeapOperand(temp1, super_offset));
          __ Cbnz(temp1, intrinsic_slow_path->GetEntryLabel());
          __ Bind(&do_copy);
        } else {
          __ B(intrinsic_slow_path->GetEntryLabel(), ne);
        }
      } else {
        // Non read barrier code.

        // /* HeapReference<Class> */ temp1 = dest->klass_
        __ Ldr(temp1, MemOperand(dest, class_offset));
        // /* HeapReference<Class> */ temp2 = src->klass_
        __ Ldr(temp2, MemOperand(src, class_offset));
        bool did_unpoison = false;
        if (!optimizations.GetDestinationIsNonPrimitiveArray() ||
            !optimizations.GetSourceIsNonPrimitiveArray()) {
          // One or two of the references need to be unpoisoned. Unpoison them
          // both to make the identity check valid.
          codegen_->GetAssembler()->MaybeUnpoisonHeapReference(temp1);
          codegen_->GetAssembler()->MaybeUnpoisonHeapReference(temp2);
          did_unpoison = true;
        }

        if (!optimizations.GetDestinationIsNonPrimitiveArray()) {
          // Bail out if the destination is not a non primitive array.
          // /* HeapReference<Class> */ temp3 = temp1->component_type_
          __ Ldr(temp3, HeapOperand(temp1, component_offset));
          __ Cbz(temp3, intrinsic_slow_path->GetEntryLabel());
          codegen_->GetAssembler()->MaybeUnpoisonHeapReference(temp3);
          // /* uint16_t */ temp3 = static_cast<uint16>(temp3->primitive_type_);
          __ Ldrh(temp3, HeapOperand(temp3, primitive_offset));
          static_assert(Primitive::kPrimNot == 0, "Expected 0 for kPrimNot");
          __ Cbnz(temp3, intrinsic_slow_path->GetEntryLabel());
        }

        if (!optimizations.GetSourceIsNonPrimitiveArray()) {
          // Bail out if the source is not a non primitive array.
          // /* HeapReference<Class> */ temp3 = temp2->component_type_
          __ Ldr(temp3, HeapOperand(temp2, component_offset));
          __ Cbz(temp3, intrinsic_slow_path->GetEntryLabel());
          codegen_->GetAssembler()->MaybeUnpoisonHeapReference(temp3);
          // /* uint16_t */ temp3 = static_cast<uint16>(temp3->primitive_type_);
          __ Ldrh(temp3, HeapOperand(temp3, primitive_offset));
          static_assert(Primitive::kPrimNot == 0, "Expected 0 for kPrimNot");
          __ Cbnz(temp3, intrinsic_slow_path->GetEntryLabel());
        }

        __ Cmp(temp1, temp2);

        if (optimizations.GetDestinationIsTypedObjectArray()) {
          vixl::aarch64::Label do_copy;
          __ B(&do_copy, eq);
          if (!did_unpoison) {
            codegen_->GetAssembler()->MaybeUnpoisonHeapReference(temp1);
          }
          // /* HeapReference<Class> */ temp1 = temp1->component_type_
          __ Ldr(temp1, HeapOperand(temp1, component_offset));
          codegen_->GetAssembler()->MaybeUnpoisonHeapReference(temp1);
          // /* HeapReference<Class> */ temp1 = temp1->super_class_
          __ Ldr(temp1, HeapOperand(temp1, super_offset));
          // No need to unpoison the result, we're comparing against null.
          __ Cbnz(temp1, intrinsic_slow_path->GetEntryLabel());
          __ Bind(&do_copy);
        } else {
          __ B(intrinsic_slow_path->GetEntryLabel(), ne);
        }
      }
    } else if (!optimizations.GetSourceIsNonPrimitiveArray()) {
      DCHECK(optimizations.GetDestinationIsNonPrimitiveArray());
      // Bail out if the source is not a non primitive array.
      if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
        // /* HeapReference<Class> */ temp1 = src->klass_
        codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                        temp1_loc,
                                                        src.W(),
                                                        class_offset,
                                                        temp3_loc,
                                                        /* needs_null_check= */ false,
                                                        /* use_load_acquire= */ false);
        // /* HeapReference<Class> */ temp2 = temp1->component_type_
        codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                        temp2_loc,
                                                        temp1,
                                                        component_offset,
                                                        temp3_loc,
                                                        /* needs_null_check= */ false,
                                                        /* use_load_acquire= */ false);
        __ Cbz(temp2, intrinsic_slow_path->GetEntryLabel());
        // If heap poisoning is enabled, `temp2` has been unpoisoned
        // by the the previous call to GenerateFieldLoadWithBakerReadBarrier.
      } else {
        // /* HeapReference<Class> */ temp1 = src->klass_
        __ Ldr(temp1, HeapOperand(src.W(), class_offset));
        codegen_->GetAssembler()->MaybeUnpoisonHeapReference(temp1);
        // /* HeapReference<Class> */ temp2 = temp1->component_type_
        __ Ldr(temp2, HeapOperand(temp1, component_offset));
        __ Cbz(temp2, intrinsic_slow_path->GetEntryLabel());
        codegen_->GetAssembler()->MaybeUnpoisonHeapReference(temp2);
      }
      // /* uint16_t */ temp2 = static_cast<uint16>(temp2->primitive_type_);
      __ Ldrh(temp2, HeapOperand(temp2, primitive_offset));
      static_assert(Primitive::kPrimNot == 0, "Expected 0 for kPrimNot");
      __ Cbnz(temp2, intrinsic_slow_path->GetEntryLabel());
    }

    if (length.IsConstant() && length.GetConstant()->AsIntConstant()->GetValue() == 0) {
      // Null constant length: not need to emit the loop code at all.
    } else {
      Register src_curr_addr = temp1.X();
      Register dst_curr_addr = temp2.X();
      Register src_stop_addr = temp3.X();
      vixl::aarch64::Label done;
      const DataType::Type type = DataType::Type::kReference;
      const int32_t element_size = DataType::Size(type);

      if (length.IsRegister()) {
        // Don't enter the copy loop if the length is null.
        __ Cbz(WRegisterFrom(length), &done);
      }

      if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
        // TODO: Also convert this intrinsic to the IsGcMarking strategy?

        // SystemArrayCopy implementation for Baker read barriers (see
        // also CodeGeneratorARM64::GenerateReferenceLoadWithBakerReadBarrier):
        //
        //   uint32_t rb_state = Lockword(src->monitor_).ReadBarrierState();
        //   lfence;  // Load fence or artificial data dependency to prevent load-load reordering
        //   bool is_gray = (rb_state == ReadBarrier::GrayState());
        //   if (is_gray) {
        //     // Slow-path copy.
        //     do {
        //       *dest_ptr++ = MaybePoison(ReadBarrier::Mark(MaybeUnpoison(*src_ptr++)));
        //     } while (src_ptr != end_ptr)
        //   } else {
        //     // Fast-path copy.
        //     do {
        //       *dest_ptr++ = *src_ptr++;
        //     } while (src_ptr != end_ptr)
        //   }

        // Make sure `tmp` is not IP0, as it is clobbered by
        // ReadBarrierMarkRegX entry points in
        // ReadBarrierSystemArrayCopySlowPathARM64.
        DCHECK(temps.IsAvailable(ip0));
        temps.Exclude(ip0);
        Register tmp = temps.AcquireW();
        DCHECK_NE(LocationFrom(tmp).reg(), IP0);
        // Put IP0 back in the pool so that VIXL has at least one
        // scratch register available to emit macro-instructions (note
        // that IP1 is already used for `tmp`). Indeed some
        // macro-instructions used in GenSystemArrayCopyAddresses
        // (invoked hereunder) may require a scratch register (for
        // instance to emit a load with a large constant offset).
        temps.Include(ip0);

        // /* int32_t */ monitor = src->monitor_
        __ Ldr(tmp, HeapOperand(src.W(), monitor_offset));
        // /* LockWord */ lock_word = LockWord(monitor)
        static_assert(sizeof(LockWord) == sizeof(int32_t),
                      "art::LockWord and int32_t have different sizes.");

        // Introduce a dependency on the lock_word including rb_state,
        // to prevent load-load reordering, and without using
        // a memory barrier (which would be more expensive).
        // `src` is unchanged by this operation, but its value now depends
        // on `tmp`.
        __ Add(src.X(), src.X(), Operand(tmp.X(), LSR, 32));

        // Compute base source address, base destination address, and end
        // source address for System.arraycopy* intrinsics in `src_base`,
        // `dst_base` and `src_end` respectively.
        // Note that `src_curr_addr` is computed from from `src` (and
        // `src_pos`) here, and thus honors the artificial dependency
        // of `src` on `tmp`.
        GenSystemArrayCopyAddresses(masm,
                                    type,
                                    src,
                                    src_pos,
                                    dest,
                                    dest_pos,
                                    length,
                                    src_curr_addr,
                                    dst_curr_addr,
                                    src_stop_addr);

        // Slow path used to copy array when `src` is gray.
        SlowPathCodeARM64* read_barrier_slow_path =
            new (codegen_->GetScopedAllocator()) ReadBarrierSystemArrayCopySlowPathARM64(
                invoke, LocationFrom(tmp));
        codegen_->AddSlowPath(read_barrier_slow_path);

        // Given the numeric representation, it's enough to check the low bit of the rb_state.
        static_assert(ReadBarrier::NonGrayState() == 0, "Expecting non-gray to have value 0");
        static_assert(ReadBarrier::GrayState() == 1, "Expecting gray to have value 1");
        __ Tbnz(tmp, LockWord::kReadBarrierStateShift, read_barrier_slow_path->GetEntryLabel());

        // Fast-path copy.
        // Iterate over the arrays and do a raw copy of the objects. We don't need to
        // poison/unpoison.
        vixl::aarch64::Label loop;
        __ Bind(&loop);
        __ Ldr(tmp, MemOperand(src_curr_addr, element_size, PostIndex));
        __ Str(tmp, MemOperand(dst_curr_addr, element_size, PostIndex));
        __ Cmp(src_curr_addr, src_stop_addr);
        __ B(&loop, ne);

        __ Bind(read_barrier_slow_path->GetExitLabel());
      } else {
        // Non read barrier code.
        // Compute base source address, base destination address, and end
        // source address for System.arraycopy* intrinsics in `src_base`,
        // `dst_base` and `src_end` respectively.
        GenSystemArrayCopyAddresses(masm,
                                    type,
                                    src,
                                    src_pos,
                                    dest,
                                    dest_pos,
                                    length,
                                    src_curr_addr,
                                    dst_curr_addr,
                                    src_stop_addr);
        // Iterate over the arrays and do a raw copy of the objects. We don't need to
        // poison/unpoison.
        vixl::aarch64::Label loop;
        __ Bind(&loop);
        {
          Register tmp = temps.AcquireW();
          __ Ldr(tmp, MemOperand(src_curr_addr, element_size, PostIndex));
          __ Str(tmp, MemOperand(dst_curr_addr, element_size, PostIndex));
        }
        __ Cmp(src_curr_addr, src_stop_addr);
        __ B(&loop, ne);
      }
      __ Bind(&done);
    }
  }

  // We only need one card marking on the destination array.
  codegen_->MarkGCCard(dest.W(), Register(), /* value_can_be_null= */ false);

  __ Bind(intrinsic_slow_path->GetExitLabel());
}

static void GenIsInfinite(LocationSummary* locations,
                          bool is64bit,
                          MacroAssembler* masm) {
  Operand infinity(0);
  Operand tst_mask(0);
  Register out;

  if (is64bit) {
    infinity = Operand(kPositiveInfinityDouble);
    tst_mask = MaskLeastSignificant<uint64_t>(63);
    out = XRegisterFrom(locations->Out());
  } else {
    infinity = Operand(kPositiveInfinityFloat);
    tst_mask = MaskLeastSignificant<uint32_t>(31);
    out = WRegisterFrom(locations->Out());
  }

  MoveFPToInt(locations, is64bit, masm);
  // Checks whether exponent bits are all 1 and fraction bits are all 0.
  __ Eor(out, out, infinity);
  // TST bitmask is used to mask out the sign bit: either 0x7fffffff or 0x7fffffffffffffff
  // depending on is64bit.
  __ Tst(out, tst_mask);
  __ Cset(out, eq);
}

void IntrinsicLocationsBuilderARM64::VisitFloatIsInfinite(HInvoke* invoke) {
  CreateFPToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitFloatIsInfinite(HInvoke* invoke) {
  GenIsInfinite(invoke->GetLocations(), /* is64bit= */ false, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitDoubleIsInfinite(HInvoke* invoke) {
  CreateFPToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitDoubleIsInfinite(HInvoke* invoke) {
  GenIsInfinite(invoke->GetLocations(), /* is64bit= */ true, GetVIXLAssembler());
}

void IntrinsicLocationsBuilderARM64::VisitIntegerValueOf(HInvoke* invoke) {
  InvokeRuntimeCallingConvention calling_convention;
  IntrinsicVisitor::ComputeIntegerValueOfLocations(
      invoke,
      codegen_,
      calling_convention.GetReturnLocation(DataType::Type::kReference),
      Location::RegisterLocation(calling_convention.GetRegisterAt(0).GetCode()));
}

void IntrinsicCodeGeneratorARM64::VisitIntegerValueOf(HInvoke* invoke) {
  IntrinsicVisitor::IntegerValueOfInfo info =
      IntrinsicVisitor::ComputeIntegerValueOfInfo(invoke, codegen_->GetCompilerOptions());
  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = GetVIXLAssembler();

  Register out = RegisterFrom(locations->Out(), DataType::Type::kReference);
  UseScratchRegisterScope temps(masm);
  Register temp = temps.AcquireW();
  auto allocate_instance = [&]() {
    DCHECK(out.X().Is(InvokeRuntimeCallingConvention().GetRegisterAt(0)));
    codegen_->LoadIntrinsicDeclaringClass(out, invoke);
    codegen_->InvokeRuntime(kQuickAllocObjectInitialized, invoke, invoke->GetDexPc());
    CheckEntrypointTypes<kQuickAllocObjectWithChecks, void*, mirror::Class*>();
  };
  if (invoke->InputAt(0)->IsConstant()) {
    int32_t value = invoke->InputAt(0)->AsIntConstant()->GetValue();
    if (static_cast<uint32_t>(value - info.low) < info.length) {
      // Just embed the j.l.Integer in the code.
      DCHECK_NE(info.value_boot_image_reference, IntegerValueOfInfo::kInvalidReference);
      codegen_->LoadBootImageAddress(out, info.value_boot_image_reference);
    } else {
      DCHECK(locations->CanCall());
      // Allocate and initialize a new j.l.Integer.
      // TODO: If we JIT, we could allocate the j.l.Integer now, and store it in the
      // JIT object table.
      allocate_instance();
      __ Mov(temp.W(), value);
      __ Str(temp.W(), HeapOperand(out.W(), info.value_offset));
      // Class pointer and `value` final field stores require a barrier before publication.
      codegen_->GenerateMemoryBarrier(MemBarrierKind::kStoreStore);
    }
  } else {
    DCHECK(locations->CanCall());
    Register in = RegisterFrom(locations->InAt(0), DataType::Type::kInt32);
    // Check bounds of our cache.
    __ Add(out.W(), in.W(), -info.low);
    __ Cmp(out.W(), info.length);
    vixl::aarch64::Label allocate, done;
    __ B(&allocate, hs);
    // If the value is within the bounds, load the j.l.Integer directly from the array.
    codegen_->LoadBootImageAddress(temp, info.array_data_boot_image_reference);
    MemOperand source = HeapOperand(
        temp, out.X(), LSL, DataType::SizeShift(DataType::Type::kReference));
    codegen_->Load(DataType::Type::kReference, out, source);
    codegen_->GetAssembler()->MaybeUnpoisonHeapReference(out);
    __ B(&done);
    __ Bind(&allocate);
    // Otherwise allocate and initialize a new j.l.Integer.
    allocate_instance();
    __ Str(in.W(), HeapOperand(out.W(), info.value_offset));
    // Class pointer and `value` final field stores require a barrier before publication.
    codegen_->GenerateMemoryBarrier(MemBarrierKind::kStoreStore);
    __ Bind(&done);
  }
}

void IntrinsicLocationsBuilderARM64::VisitReferenceGetReferent(HInvoke* invoke) {
  IntrinsicVisitor::CreateReferenceGetReferentLocations(invoke, codegen_);

  if (kEmitCompilerReadBarrier && kUseBakerReadBarrier && invoke->GetLocations() != nullptr) {
    invoke->GetLocations()->AddTemp(Location::RequiresRegister());
  }
}

void IntrinsicCodeGeneratorARM64::VisitReferenceGetReferent(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Location obj = locations->InAt(0);
  Location out = locations->Out();

  SlowPathCodeARM64* slow_path = new (GetAllocator()) IntrinsicSlowPathARM64(invoke);
  codegen_->AddSlowPath(slow_path);

  if (kEmitCompilerReadBarrier) {
    // Check self->GetWeakRefAccessEnabled().
    UseScratchRegisterScope temps(masm);
    Register temp = temps.AcquireW();
    __ Ldr(temp,
           MemOperand(tr, Thread::WeakRefAccessEnabledOffset<kArm64PointerSize>().Uint32Value()));
    __ Cbz(temp, slow_path->GetEntryLabel());
  }

  {
    // Load the java.lang.ref.Reference class.
    UseScratchRegisterScope temps(masm);
    Register temp = temps.AcquireW();
    codegen_->LoadIntrinsicDeclaringClass(temp, invoke);

    // Check static fields java.lang.ref.Reference.{disableIntrinsic,slowPathEnabled} together.
    MemberOffset disable_intrinsic_offset = IntrinsicVisitor::GetReferenceDisableIntrinsicOffset();
    DCHECK_ALIGNED(disable_intrinsic_offset.Uint32Value(), 2u);
    DCHECK_EQ(disable_intrinsic_offset.Uint32Value() + 1u,
              IntrinsicVisitor::GetReferenceSlowPathEnabledOffset().Uint32Value());
    __ Ldrh(temp, HeapOperand(temp, disable_intrinsic_offset.Uint32Value()));
    __ Cbnz(temp, slow_path->GetEntryLabel());
  }

  // Load the value from the field.
  uint32_t referent_offset = mirror::Reference::ReferentOffset().Uint32Value();
  if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
    codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                    out,
                                                    WRegisterFrom(obj),
                                                    referent_offset,
                                                    /*maybe_temp=*/ locations->GetTemp(0),
                                                    /*needs_null_check=*/ true,
                                                    /*use_load_acquire=*/ true);
  } else {
    MemOperand field = HeapOperand(WRegisterFrom(obj), referent_offset);
    codegen_->LoadAcquire(
        invoke, DataType::Type::kReference, WRegisterFrom(out), field, /*needs_null_check=*/ true);
    codegen_->MaybeGenerateReadBarrierSlow(invoke, out, out, obj, referent_offset);
  }
  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderARM64::VisitReferenceRefersTo(HInvoke* invoke) {
  IntrinsicVisitor::CreateReferenceRefersToLocations(invoke);
}

void IntrinsicCodeGeneratorARM64::VisitReferenceRefersTo(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = codegen_->GetVIXLAssembler();
  UseScratchRegisterScope temps(masm);

  Register obj = WRegisterFrom(locations->InAt(0));
  Register other = WRegisterFrom(locations->InAt(1));
  Register out = WRegisterFrom(locations->Out());
  Register tmp = temps.AcquireW();

  uint32_t referent_offset = mirror::Reference::ReferentOffset().Uint32Value();
  uint32_t monitor_offset = mirror::Object::MonitorOffset().Int32Value();

  MemOperand field = HeapOperand(obj, referent_offset);
  codegen_->LoadAcquire(invoke, DataType::Type::kReference, tmp, field, /*needs_null_check=*/ true);
  codegen_->GetAssembler()->MaybeUnpoisonHeapReference(tmp);

  __ Cmp(tmp, other);

  if (kEmitCompilerReadBarrier) {
    DCHECK(kUseBakerReadBarrier);

    vixl::aarch64::Label calculate_result;

    // If the GC is not marking, the comparison result is final.
    __ Cbz(mr, &calculate_result);

    __ B(&calculate_result, eq);  // ZF set if taken.

    // Check if the loaded reference is null.
    __ Cbz(tmp, &calculate_result);  // ZF clear if taken.

    // For correct memory visibility, we need a barrier before loading the lock word.
    codegen_->GenerateMemoryBarrier(MemBarrierKind::kLoadAny);

    // Load the lockword and check if it is a forwarding address.
    static_assert(LockWord::kStateShift == 30u);
    static_assert(LockWord::kStateForwardingAddress == 3u);
    __ Ldr(tmp, HeapOperand(tmp, monitor_offset));
    __ Cmp(tmp, Operand(0xc0000000));
    __ B(&calculate_result, lo);   // ZF clear if taken.

    // Extract the forwarding address and compare with `other`.
    __ Cmp(other, Operand(tmp, LSL, LockWord::kForwardingAddressShift));

    __ Bind(&calculate_result);
  }

  // Convert ZF into the Boolean result.
  __ Cset(out, eq);
}

void IntrinsicLocationsBuilderARM64::VisitThreadInterrupted(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetOut(Location::RequiresRegister());
}

void IntrinsicCodeGeneratorARM64::VisitThreadInterrupted(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  Register out = RegisterFrom(invoke->GetLocations()->Out(), DataType::Type::kInt32);
  UseScratchRegisterScope temps(masm);
  Register temp = temps.AcquireX();

  __ Add(temp, tr, Thread::InterruptedOffset<kArm64PointerSize>().Int32Value());
  __ Ldar(out.W(), MemOperand(temp));

  vixl::aarch64::Label done;
  __ Cbz(out.W(), &done);
  __ Stlr(wzr, MemOperand(temp));
  __ Bind(&done);
}

void IntrinsicLocationsBuilderARM64::VisitReachabilityFence(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::Any());
}

void IntrinsicCodeGeneratorARM64::VisitReachabilityFence(HInvoke* invoke ATTRIBUTE_UNUSED) { }

void IntrinsicLocationsBuilderARM64::VisitCRC32Update(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasCRC()) {
    return;
  }

  LocationSummary* locations = new (allocator_) LocationSummary(invoke,
                                                                LocationSummary::kNoCall,
                                                                kIntrinsified);

  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetOut(Location::RequiresRegister(), Location::kNoOutputOverlap);
}

// Lower the invoke of CRC32.update(int crc, int b).
void IntrinsicCodeGeneratorARM64::VisitCRC32Update(HInvoke* invoke) {
  DCHECK(codegen_->GetInstructionSetFeatures().HasCRC());

  MacroAssembler* masm = GetVIXLAssembler();

  Register crc = InputRegisterAt(invoke, 0);
  Register val = InputRegisterAt(invoke, 1);
  Register out = OutputRegister(invoke);

  // The general algorithm of the CRC32 calculation is:
  //   crc = ~crc
  //   result = crc32_for_byte(crc, b)
  //   crc = ~result
  // It is directly lowered to three instructions.

  UseScratchRegisterScope temps(masm);
  Register tmp = temps.AcquireSameSizeAs(out);

  __ Mvn(tmp, crc);
  __ Crc32b(tmp, tmp, val);
  __ Mvn(out, tmp);
}

// Generate code using CRC32 instructions which calculates
// a CRC32 value of a byte.
//
// Parameters:
//   masm   - VIXL macro assembler
//   crc    - a register holding an initial CRC value
//   ptr    - a register holding a memory address of bytes
//   length - a register holding a number of bytes to process
//   out    - a register to put a result of calculation
static void GenerateCodeForCalculationCRC32ValueOfBytes(MacroAssembler* masm,
                                                        const Register& crc,
                                                        const Register& ptr,
                                                        const Register& length,
                                                        const Register& out) {
  // The algorithm of CRC32 of bytes is:
  //   crc = ~crc
  //   process a few first bytes to make the array 8-byte aligned
  //   while array has 8 bytes do:
  //     crc = crc32_of_8bytes(crc, 8_bytes(array))
  //   if array has 4 bytes:
  //     crc = crc32_of_4bytes(crc, 4_bytes(array))
  //   if array has 2 bytes:
  //     crc = crc32_of_2bytes(crc, 2_bytes(array))
  //   if array has a byte:
  //     crc = crc32_of_byte(crc, 1_byte(array))
  //   crc = ~crc

  vixl::aarch64::Label loop, done;
  vixl::aarch64::Label process_4bytes, process_2bytes, process_1byte;
  vixl::aarch64::Label aligned2, aligned4, aligned8;

  // Use VIXL scratch registers as the VIXL macro assembler won't use them in
  // instructions below.
  UseScratchRegisterScope temps(masm);
  Register len = temps.AcquireW();
  Register array_elem = temps.AcquireW();

  __ Mvn(out, crc);
  __ Mov(len, length);

  __ Tbz(ptr, 0, &aligned2);
  __ Subs(len, len, 1);
  __ B(&done, lo);
  __ Ldrb(array_elem, MemOperand(ptr, 1, PostIndex));
  __ Crc32b(out, out, array_elem);

  __ Bind(&aligned2);
  __ Tbz(ptr, 1, &aligned4);
  __ Subs(len, len, 2);
  __ B(&process_1byte, lo);
  __ Ldrh(array_elem, MemOperand(ptr, 2, PostIndex));
  __ Crc32h(out, out, array_elem);

  __ Bind(&aligned4);
  __ Tbz(ptr, 2, &aligned8);
  __ Subs(len, len, 4);
  __ B(&process_2bytes, lo);
  __ Ldr(array_elem, MemOperand(ptr, 4, PostIndex));
  __ Crc32w(out, out, array_elem);

  __ Bind(&aligned8);
  __ Subs(len, len, 8);
  // If len < 8 go to process data by 4 bytes, 2 bytes and a byte.
  __ B(&process_4bytes, lo);

  // The main loop processing data by 8 bytes.
  __ Bind(&loop);
  __ Ldr(array_elem.X(), MemOperand(ptr, 8, PostIndex));
  __ Subs(len, len, 8);
  __ Crc32x(out, out, array_elem.X());
  // if len >= 8, process the next 8 bytes.
  __ B(&loop, hs);

  // Process the data which is less than 8 bytes.
  // The code generated below works with values of len
  // which come in the range [-8, 0].
  // The first three bits are used to detect whether 4 bytes or 2 bytes or
  // a byte can be processed.
  // The checking order is from bit 2 to bit 0:
  //  bit 2 is set: at least 4 bytes available
  //  bit 1 is set: at least 2 bytes available
  //  bit 0 is set: at least a byte available
  __ Bind(&process_4bytes);
  // Goto process_2bytes if less than four bytes available
  __ Tbz(len, 2, &process_2bytes);
  __ Ldr(array_elem, MemOperand(ptr, 4, PostIndex));
  __ Crc32w(out, out, array_elem);

  __ Bind(&process_2bytes);
  // Goto process_1bytes if less than two bytes available
  __ Tbz(len, 1, &process_1byte);
  __ Ldrh(array_elem, MemOperand(ptr, 2, PostIndex));
  __ Crc32h(out, out, array_elem);

  __ Bind(&process_1byte);
  // Goto done if no bytes available
  __ Tbz(len, 0, &done);
  __ Ldrb(array_elem, MemOperand(ptr));
  __ Crc32b(out, out, array_elem);

  __ Bind(&done);
  __ Mvn(out, out);
}

// The threshold for sizes of arrays to use the library provided implementation
// of CRC32.updateBytes instead of the intrinsic.
static constexpr int32_t kCRC32UpdateBytesThreshold = 64 * 1024;

void IntrinsicLocationsBuilderARM64::VisitCRC32UpdateBytes(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasCRC()) {
    return;
  }

  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke,
                                       LocationSummary::kCallOnSlowPath,
                                       kIntrinsified);

  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetInAt(2, Location::RegisterOrConstant(invoke->InputAt(2)));
  locations->SetInAt(3, Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  locations->SetOut(Location::RequiresRegister());
}

// Lower the invoke of CRC32.updateBytes(int crc, byte[] b, int off, int len)
//
// Note: The intrinsic is not used if len exceeds a threshold.
void IntrinsicCodeGeneratorARM64::VisitCRC32UpdateBytes(HInvoke* invoke) {
  DCHECK(codegen_->GetInstructionSetFeatures().HasCRC());

  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  SlowPathCodeARM64* slow_path =
      new (codegen_->GetScopedAllocator()) IntrinsicSlowPathARM64(invoke);
  codegen_->AddSlowPath(slow_path);

  Register length = WRegisterFrom(locations->InAt(3));
  __ Cmp(length, kCRC32UpdateBytesThreshold);
  __ B(slow_path->GetEntryLabel(), hi);

  const uint32_t array_data_offset =
      mirror::Array::DataOffset(Primitive::kPrimByte).Uint32Value();
  Register ptr = XRegisterFrom(locations->GetTemp(0));
  Register array = XRegisterFrom(locations->InAt(1));
  Location offset = locations->InAt(2);
  if (offset.IsConstant()) {
    int32_t offset_value = offset.GetConstant()->AsIntConstant()->GetValue();
    __ Add(ptr, array, array_data_offset + offset_value);
  } else {
    __ Add(ptr, array, array_data_offset);
    __ Add(ptr, ptr, XRegisterFrom(offset));
  }

  Register crc = WRegisterFrom(locations->InAt(0));
  Register out = WRegisterFrom(locations->Out());

  GenerateCodeForCalculationCRC32ValueOfBytes(masm, crc, ptr, length, out);

  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderARM64::VisitCRC32UpdateByteBuffer(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasCRC()) {
    return;
  }

  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke,
                                       LocationSummary::kNoCall,
                                       kIntrinsified);

  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetInAt(2, Location::RequiresRegister());
  locations->SetInAt(3, Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  locations->SetOut(Location::RequiresRegister());
}

// Lower the invoke of CRC32.updateByteBuffer(int crc, long addr, int off, int len)
//
// There is no need to generate code checking if addr is 0.
// The method updateByteBuffer is a private method of java.util.zip.CRC32.
// This guarantees no calls outside of the CRC32 class.
// An address of DirectBuffer is always passed to the call of updateByteBuffer.
// It might be an implementation of an empty DirectBuffer which can use a zero
// address but it must have the length to be zero. The current generated code
// correctly works with the zero length.
void IntrinsicCodeGeneratorARM64::VisitCRC32UpdateByteBuffer(HInvoke* invoke) {
  DCHECK(codegen_->GetInstructionSetFeatures().HasCRC());

  MacroAssembler* masm = GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register addr = XRegisterFrom(locations->InAt(1));
  Register ptr = XRegisterFrom(locations->GetTemp(0));
  __ Add(ptr, addr, XRegisterFrom(locations->InAt(2)));

  Register crc = WRegisterFrom(locations->InAt(0));
  Register length = WRegisterFrom(locations->InAt(3));
  Register out = WRegisterFrom(locations->Out());
  GenerateCodeForCalculationCRC32ValueOfBytes(masm, crc, ptr, length, out);
}

void IntrinsicLocationsBuilderARM64::VisitFP16ToFloat(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasFP16()) {
    return;
  }

  LocationSummary* locations = new (allocator_) LocationSummary(invoke,
                                                                LocationSummary::kNoCall,
                                                                kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetOut(Location::RequiresFpuRegister());
}

void IntrinsicCodeGeneratorARM64::VisitFP16ToFloat(HInvoke* invoke) {
  DCHECK(codegen_->GetInstructionSetFeatures().HasFP16());
  MacroAssembler* masm = GetVIXLAssembler();
  UseScratchRegisterScope scratch_scope(masm);
  Register bits = InputRegisterAt(invoke, 0);
  VRegister out = SRegisterFrom(invoke->GetLocations()->Out());
  VRegister half = scratch_scope.AcquireH();
  __ Fmov(half, bits);  // ARMv8.2
  __ Fcvt(out, half);
}

void IntrinsicLocationsBuilderARM64::VisitFP16ToHalf(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasFP16()) {
    return;
  }

  LocationSummary* locations = new (allocator_) LocationSummary(invoke,
                                                                LocationSummary::kNoCall,
                                                                kIntrinsified);
  locations->SetInAt(0, Location::RequiresFpuRegister());
  locations->SetOut(Location::RequiresRegister());
}

void IntrinsicCodeGeneratorARM64::VisitFP16ToHalf(HInvoke* invoke) {
  DCHECK(codegen_->GetInstructionSetFeatures().HasFP16());
  MacroAssembler* masm = GetVIXLAssembler();
  UseScratchRegisterScope scratch_scope(masm);
  VRegister in = SRegisterFrom(invoke->GetLocations()->InAt(0));
  VRegister half = scratch_scope.AcquireH();
  Register out = WRegisterFrom(invoke->GetLocations()->Out());
  __ Fcvt(half, in);
  __ Fmov(out, half);
  __ Sxth(out, out);  // sign extend due to returning a short type.
}

template<typename OP>
void GenerateFP16Round(HInvoke* invoke,
                       CodeGeneratorARM64* const codegen_,
                       MacroAssembler* masm,
                       const OP roundOp) {
  DCHECK(codegen_->GetInstructionSetFeatures().HasFP16());
  LocationSummary* locations = invoke->GetLocations();
  UseScratchRegisterScope scratch_scope(masm);
  Register out = WRegisterFrom(locations->Out());
  VRegister half = scratch_scope.AcquireH();
  __ Fmov(half, WRegisterFrom(locations->InAt(0)));
  roundOp(half, half);
  __ Fmov(out, half);
  __ Sxth(out, out);
}

void IntrinsicLocationsBuilderARM64::VisitFP16Floor(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasFP16()) {
    return;
  }

  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitFP16Floor(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  auto roundOp = [masm](const VRegister& out, const VRegister& in) {
    __ Frintm(out, in);  // Round towards Minus infinity
  };
  GenerateFP16Round(invoke, codegen_, masm, roundOp);
}

void IntrinsicLocationsBuilderARM64::VisitFP16Ceil(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasFP16()) {
    return;
  }

  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitFP16Ceil(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  auto roundOp = [masm](const VRegister& out, const VRegister& in) {
    __ Frintp(out, in);  // Round towards Plus infinity
  };
  GenerateFP16Round(invoke, codegen_, masm, roundOp);
}

void IntrinsicLocationsBuilderARM64::VisitFP16Rint(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasFP16()) {
    return;
  }

  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitFP16Rint(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  auto roundOp = [masm](const VRegister& out, const VRegister& in) {
    __ Frintn(out, in);  // Round to nearest, with ties to even
  };
  GenerateFP16Round(invoke, codegen_, masm, roundOp);
}

template<typename OP>
void GenerateFP16Compare(HInvoke* invoke,
                         CodeGeneratorARM64* codegen,
                         MacroAssembler* masm,
                         const OP compareOp) {
  DCHECK(codegen->GetInstructionSetFeatures().HasFP16());
  LocationSummary* locations = invoke->GetLocations();
  Register out = WRegisterFrom(locations->Out());
  VRegister half0 = HRegisterFrom(locations->GetTemp(0));
  VRegister half1 = HRegisterFrom(locations->GetTemp(1));
  __ Fmov(half0, WRegisterFrom(locations->InAt(0)));
  __ Fmov(half1, WRegisterFrom(locations->InAt(1)));
  compareOp(out, half0, half1);
}

static inline void GenerateFP16Compare(HInvoke* invoke,
                                       CodeGeneratorARM64* codegen,
                                       MacroAssembler* masm,
                                       vixl::aarch64::Condition cond) {
  auto compareOp = [masm, cond](const Register out, const VRegister& in0, const VRegister& in1) {
    __ Fcmp(in0, in1);
    __ Cset(out, cond);
  };
  GenerateFP16Compare(invoke, codegen, masm, compareOp);
}

void IntrinsicLocationsBuilderARM64::VisitFP16Greater(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasFP16()) {
    return;
  }

  CreateIntIntToIntLocations(allocator_, invoke);
  invoke->GetLocations()->AddTemp(Location::RequiresFpuRegister());
  invoke->GetLocations()->AddTemp(Location::RequiresFpuRegister());
}

void IntrinsicCodeGeneratorARM64::VisitFP16Greater(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  GenerateFP16Compare(invoke, codegen_, masm, gt);
}

void IntrinsicLocationsBuilderARM64::VisitFP16GreaterEquals(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasFP16()) {
    return;
  }

  CreateIntIntToIntLocations(allocator_, invoke);
  invoke->GetLocations()->AddTemp(Location::RequiresFpuRegister());
  invoke->GetLocations()->AddTemp(Location::RequiresFpuRegister());
}

void IntrinsicCodeGeneratorARM64::VisitFP16GreaterEquals(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  GenerateFP16Compare(invoke, codegen_, masm, ge);
}

void IntrinsicLocationsBuilderARM64::VisitFP16Less(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasFP16()) {
    return;
  }

  CreateIntIntToIntLocations(allocator_, invoke);
  invoke->GetLocations()->AddTemp(Location::RequiresFpuRegister());
  invoke->GetLocations()->AddTemp(Location::RequiresFpuRegister());
}

void IntrinsicCodeGeneratorARM64::VisitFP16Less(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  GenerateFP16Compare(invoke, codegen_, masm, mi);
}

void IntrinsicLocationsBuilderARM64::VisitFP16LessEquals(HInvoke* invoke) {
  if (!codegen_->GetInstructionSetFeatures().HasFP16()) {
    return;
  }

  CreateIntIntToIntLocations(allocator_, invoke);
  invoke->GetLocations()->AddTemp(Location::RequiresFpuRegister());
  invoke->GetLocations()->AddTemp(Location::RequiresFpuRegister());
}

void IntrinsicCodeGeneratorARM64::VisitFP16LessEquals(HInvoke* invoke) {
  MacroAssembler* masm = GetVIXLAssembler();
  GenerateFP16Compare(invoke, codegen_, masm, ls);
}

static void GenerateDivideUnsigned(HInvoke* invoke, CodeGeneratorARM64* codegen) {
  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = codegen->GetVIXLAssembler();
  DataType::Type type = invoke->GetType();
  DCHECK(type == DataType::Type::kInt32 || type == DataType::Type::kInt64);

  Register dividend = RegisterFrom(locations->InAt(0), type);
  Register divisor = RegisterFrom(locations->InAt(1), type);
  Register out = RegisterFrom(locations->Out(), type);

  // Check if divisor is zero, bail to managed implementation to handle.
  SlowPathCodeARM64* slow_path =
      new (codegen->GetScopedAllocator()) IntrinsicSlowPathARM64(invoke);
  codegen->AddSlowPath(slow_path);
  __ Cbz(divisor, slow_path->GetEntryLabel());

  __ Udiv(out, dividend, divisor);

  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderARM64::VisitIntegerDivideUnsigned(HInvoke* invoke) {
  CreateIntIntToIntSlowPathCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitIntegerDivideUnsigned(HInvoke* invoke) {
  GenerateDivideUnsigned(invoke, codegen_);
}

void IntrinsicLocationsBuilderARM64::VisitLongDivideUnsigned(HInvoke* invoke) {
  CreateIntIntToIntSlowPathCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitLongDivideUnsigned(HInvoke* invoke) {
  GenerateDivideUnsigned(invoke, codegen_);
}

void IntrinsicLocationsBuilderARM64::VisitMathMultiplyHigh(HInvoke* invoke) {
  CreateIntIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorARM64::VisitMathMultiplyHigh(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = codegen_->GetVIXLAssembler();
  DataType::Type type = invoke->GetType();
  DCHECK(type == DataType::Type::kInt64);

  Register x = RegisterFrom(locations->InAt(0), type);
  Register y = RegisterFrom(locations->InAt(1), type);
  Register out = RegisterFrom(locations->Out(), type);

  __ Smulh(out, x, y);
}

class VarHandleSlowPathARM64 : public IntrinsicSlowPathARM64 {
 public:
  VarHandleSlowPathARM64(HInvoke* invoke, std::memory_order order)
      : IntrinsicSlowPathARM64(invoke),
        order_(order),
        return_success_(false),
        strong_(false),
        get_and_update_op_(GetAndUpdateOp::kAdd) {
  }

  vixl::aarch64::Label* GetByteArrayViewCheckLabel() {
    return &byte_array_view_check_label_;
  }

  vixl::aarch64::Label* GetNativeByteOrderLabel() {
    return &native_byte_order_label_;
  }

  void SetCompareAndSetOrExchangeArgs(bool return_success, bool strong) {
    if (return_success) {
      DCHECK(GetAccessModeTemplate() == mirror::VarHandle::AccessModeTemplate::kCompareAndSet);
    } else {
      DCHECK(GetAccessModeTemplate() == mirror::VarHandle::AccessModeTemplate::kCompareAndExchange);
    }
    return_success_ = return_success;
    strong_ = strong;
  }

  void SetGetAndUpdateOp(GetAndUpdateOp get_and_update_op) {
    DCHECK(GetAccessModeTemplate() == mirror::VarHandle::AccessModeTemplate::kGetAndUpdate);
    get_and_update_op_ = get_and_update_op;
  }

  void EmitNativeCode(CodeGenerator* codegen_in) override {
    if (GetByteArrayViewCheckLabel()->IsLinked()) {
      EmitByteArrayViewCode(codegen_in);
    }
    IntrinsicSlowPathARM64::EmitNativeCode(codegen_in);
  }

 private:
  HInvoke* GetInvoke() const {
    return GetInstruction()->AsInvoke();
  }

  mirror::VarHandle::AccessModeTemplate GetAccessModeTemplate() const {
    return mirror::VarHandle::GetAccessModeTemplateByIntrinsic(GetInvoke()->GetIntrinsic());
  }

  void EmitByteArrayViewCode(CodeGenerator* codegen_in);

  vixl::aarch64::Label byte_array_view_check_label_;
  vixl::aarch64::Label native_byte_order_label_;
  // Shared parameter for all VarHandle intrinsics.
  std::memory_order order_;
  // Extra arguments for GenerateVarHandleCompareAndSetOrExchange().
  bool return_success_;
  bool strong_;
  // Extra argument for GenerateVarHandleGetAndUpdate().
  GetAndUpdateOp get_and_update_op_;
};

// Generate subtype check without read barriers.
static void GenerateSubTypeObjectCheckNoReadBarrier(CodeGeneratorARM64* codegen,
                                                    SlowPathCodeARM64* slow_path,
                                                    Register object,
                                                    Register type,
                                                    bool object_can_be_null = true) {
  MacroAssembler* masm = codegen->GetVIXLAssembler();

  const MemberOffset class_offset = mirror::Object::ClassOffset();
  const MemberOffset super_class_offset = mirror::Class::SuperClassOffset();

  vixl::aarch64::Label success;
  if (object_can_be_null) {
    __ Cbz(object, &success);
  }

  UseScratchRegisterScope temps(masm);
  Register temp = temps.AcquireW();

  __ Ldr(temp, HeapOperand(object, class_offset.Int32Value()));
  codegen->GetAssembler()->MaybeUnpoisonHeapReference(temp);
  vixl::aarch64::Label loop;
  __ Bind(&loop);
  __ Cmp(type, temp);
  __ B(&success, eq);
  __ Ldr(temp, HeapOperand(temp, super_class_offset.Int32Value()));
  codegen->GetAssembler()->MaybeUnpoisonHeapReference(temp);
  __ Cbz(temp, slow_path->GetEntryLabel());
  __ B(&loop);
  __ Bind(&success);
}

// Check access mode and the primitive type from VarHandle.varType.
// Check reference arguments against the VarHandle.varType; for references this is a subclass
// check without read barrier, so it can have false negatives which we handle in the slow path.
static void GenerateVarHandleAccessModeAndVarTypeChecks(HInvoke* invoke,
                                                        CodeGeneratorARM64* codegen,
                                                        SlowPathCodeARM64* slow_path,
                                                        DataType::Type type) {
  mirror::VarHandle::AccessMode access_mode =
      mirror::VarHandle::GetAccessModeByIntrinsic(invoke->GetIntrinsic());
  Primitive::Type primitive_type = DataTypeToPrimitive(type);

  MacroAssembler* masm = codegen->GetVIXLAssembler();
  Register varhandle = InputRegisterAt(invoke, 0);

  const MemberOffset var_type_offset = mirror::VarHandle::VarTypeOffset();
  const MemberOffset access_mode_bit_mask_offset = mirror::VarHandle::AccessModesBitMaskOffset();
  const MemberOffset primitive_type_offset = mirror::Class::PrimitiveTypeOffset();

  UseScratchRegisterScope temps(masm);
  Register var_type_no_rb = temps.AcquireW();
  Register temp2 = temps.AcquireW();

  // Check that the operation is permitted and the primitive type of varhandle.varType.
  // We do not need a read barrier when loading a reference only for loading constant
  // primitive field through the reference. Use LDP to load the fields together.
  DCHECK_EQ(var_type_offset.Int32Value() + 4, access_mode_bit_mask_offset.Int32Value());
  __ Ldp(var_type_no_rb, temp2, HeapOperand(varhandle, var_type_offset.Int32Value()));
  codegen->GetAssembler()->MaybeUnpoisonHeapReference(var_type_no_rb);
  __ Tbz(temp2, static_cast<uint32_t>(access_mode), slow_path->GetEntryLabel());
  __ Ldrh(temp2, HeapOperand(var_type_no_rb, primitive_type_offset.Int32Value()));
  if (primitive_type == Primitive::kPrimNot) {
    static_assert(Primitive::kPrimNot == 0);
    __ Cbnz(temp2, slow_path->GetEntryLabel());
  } else {
    __ Cmp(temp2, static_cast<uint16_t>(primitive_type));
    __ B(slow_path->GetEntryLabel(), ne);
  }

  temps.Release(temp2);

  if (type == DataType::Type::kReference) {
    // Check reference arguments against the varType.
    // False negatives due to varType being an interface or array type
    // or due to the missing read barrier are handled by the slow path.
    size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
    uint32_t arguments_start = /* VarHandle object */ 1u + expected_coordinates_count;
    uint32_t number_of_arguments = invoke->GetNumberOfArguments();
    for (size_t arg_index = arguments_start; arg_index != number_of_arguments; ++arg_index) {
      HInstruction* arg = invoke->InputAt(arg_index);
      DCHECK_EQ(arg->GetType(), DataType::Type::kReference);
      if (!arg->IsNullConstant()) {
        Register arg_reg = WRegisterFrom(invoke->GetLocations()->InAt(arg_index));
        GenerateSubTypeObjectCheckNoReadBarrier(codegen, slow_path, arg_reg, var_type_no_rb);
      }
    }
  }
}

static void GenerateVarHandleStaticFieldCheck(HInvoke* invoke,
                                              CodeGeneratorARM64* codegen,
                                              SlowPathCodeARM64* slow_path) {
  MacroAssembler* masm = codegen->GetVIXLAssembler();
  Register varhandle = InputRegisterAt(invoke, 0);

  const MemberOffset coordinate_type0_offset = mirror::VarHandle::CoordinateType0Offset();

  UseScratchRegisterScope temps(masm);
  Register temp = temps.AcquireW();

  // Check that the VarHandle references a static field by checking that coordinateType0 == null.
  // Do not emit read barrier (or unpoison the reference) for comparing to null.
  __ Ldr(temp, HeapOperand(varhandle, coordinate_type0_offset.Int32Value()));
  __ Cbnz(temp, slow_path->GetEntryLabel());
}

static void GenerateVarHandleInstanceFieldChecks(HInvoke* invoke,
                                                 CodeGeneratorARM64* codegen,
                                                 SlowPathCodeARM64* slow_path) {
  MacroAssembler* masm = codegen->GetVIXLAssembler();
  Register varhandle = InputRegisterAt(invoke, 0);
  Register object = InputRegisterAt(invoke, 1);

  const MemberOffset coordinate_type0_offset = mirror::VarHandle::CoordinateType0Offset();
  const MemberOffset coordinate_type1_offset = mirror::VarHandle::CoordinateType1Offset();

  // Null-check the object.
  __ Cbz(object, slow_path->GetEntryLabel());

  UseScratchRegisterScope temps(masm);
  Register temp = temps.AcquireW();
  Register temp2 = temps.AcquireW();

  // Check that the VarHandle references an instance field by checking that
  // coordinateType1 == null. coordinateType0 should not be null, but this is handled by the
  // type compatibility check with the source object's type, which will fail for null.
  DCHECK_EQ(coordinate_type0_offset.Int32Value() + 4, coordinate_type1_offset.Int32Value());
  __ Ldp(temp, temp2, HeapOperand(varhandle, coordinate_type0_offset.Int32Value()));
  codegen->GetAssembler()->MaybeUnpoisonHeapReference(temp);
  // No need for read barrier or unpoisoning of coordinateType1 for comparison with null.
  __ Cbnz(temp2, slow_path->GetEntryLabel());

  // Check that the object has the correct type.
  // We deliberately avoid the read barrier, letting the slow path handle the false negatives.
  temps.Release(temp2);  // Needed by GenerateSubTypeObjectCheckNoReadBarrier().
  GenerateSubTypeObjectCheckNoReadBarrier(
      codegen, slow_path, object, temp, /*object_can_be_null=*/ false);
}

static DataType::Type GetVarHandleExpectedValueType(HInvoke* invoke,
                                                    size_t expected_coordinates_count) {
  DCHECK_EQ(expected_coordinates_count, GetExpectedVarHandleCoordinatesCount(invoke));
  uint32_t number_of_arguments = invoke->GetNumberOfArguments();
  DCHECK_GE(number_of_arguments, /* VarHandle object */ 1u + expected_coordinates_count);
  if (number_of_arguments == /* VarHandle object */ 1u + expected_coordinates_count) {
    return invoke->GetType();
  } else {
    return GetDataTypeFromShorty(invoke, number_of_arguments - 1u);
  }
}

static void GenerateVarHandleArrayChecks(HInvoke* invoke,
                                         CodeGeneratorARM64* codegen,
                                         VarHandleSlowPathARM64* slow_path) {
  MacroAssembler* masm = codegen->GetVIXLAssembler();
  Register varhandle = InputRegisterAt(invoke, 0);
  Register object = InputRegisterAt(invoke, 1);
  Register index = InputRegisterAt(invoke, 2);
  DataType::Type value_type =
      GetVarHandleExpectedValueType(invoke, /*expected_coordinates_count=*/ 2u);
  Primitive::Type primitive_type = DataTypeToPrimitive(value_type);

  const MemberOffset coordinate_type0_offset = mirror::VarHandle::CoordinateType0Offset();
  const MemberOffset coordinate_type1_offset = mirror::VarHandle::CoordinateType1Offset();
  const MemberOffset component_type_offset = mirror::Class::ComponentTypeOffset();
  const MemberOffset primitive_type_offset = mirror::Class::PrimitiveTypeOffset();
  const MemberOffset class_offset = mirror::Object::ClassOffset();
  const MemberOffset array_length_offset = mirror::Array::LengthOffset();

  // Null-check the object.
  __ Cbz(object, slow_path->GetEntryLabel());

  UseScratchRegisterScope temps(masm);
  Register temp = temps.AcquireW();
  Register temp2 = temps.AcquireW();

  // Check that the VarHandle references an array, byte array view or ByteBuffer by checking
  // that coordinateType1 != null. If that's true, coordinateType1 shall be int.class and
  // coordinateType0 shall not be null but we do not explicitly verify that.
  DCHECK_EQ(coordinate_type0_offset.Int32Value() + 4, coordinate_type1_offset.Int32Value());
  __ Ldp(temp, temp2, HeapOperand(varhandle, coordinate_type0_offset.Int32Value()));
  codegen->GetAssembler()->MaybeUnpoisonHeapReference(temp);
  // No need for read barrier or unpoisoning of coordinateType1 for comparison with null.
  __ Cbz(temp2, slow_path->GetEntryLabel());

  // Check object class against componentType0.
  //
  // This is an exact check and we defer other cases to the runtime. This includes
  // conversion to array of superclass references, which is valid but subsequently
  // requires all update operations to check that the value can indeed be stored.
  // We do not want to perform such extra checks in the intrinsified code.
  //
  // We do this check without read barrier, so there can be false negatives which we
  // defer to the slow path. There shall be no false negatives for array classes in the
  // boot image (including Object[] and primitive arrays) because they are non-movable.
  __ Ldr(temp2, HeapOperand(object, class_offset.Int32Value()));
  codegen->GetAssembler()->MaybeUnpoisonHeapReference(temp2);
  __ Cmp(temp, temp2);
  __ B(slow_path->GetEntryLabel(), ne);

  // Check that the coordinateType0 is an array type. We do not need a read barrier
  // for loading constant reference fields (or chains of them) for comparison with null,
  // nor for finally loading a constant primitive field (primitive type) below.
  __ Ldr(temp2, HeapOperand(temp, component_type_offset.Int32Value()));
  codegen->GetAssembler()->MaybeUnpoisonHeapReference(temp2);
  __ Cbz(temp2, slow_path->GetEntryLabel());

  // Check that the array component type matches the primitive type.
  __ Ldrh(temp2, HeapOperand(temp2, primitive_type_offset.Int32Value()));
  if (primitive_type == Primitive::kPrimNot) {
    static_assert(Primitive::kPrimNot == 0);
    __ Cbnz(temp2, slow_path->GetEntryLabel());
  } else {
    // With the exception of `kPrimNot` (handled above), `kPrimByte` and `kPrimBoolean`,
    // we shall check for a byte array view in the slow path.
    // The check requires the ByteArrayViewVarHandle.class to be in the boot image,
    // so we cannot emit that if we're JITting without boot image.
    bool boot_image_available =
        codegen->GetCompilerOptions().IsBootImage() ||
        !Runtime::Current()->GetHeap()->GetBootImageSpaces().empty();
    DCHECK(boot_image_available || codegen->GetCompilerOptions().IsJitCompiler());
    size_t can_be_view = (DataType::Size(value_type) != 1u) && boot_image_available;
    vixl::aarch64::Label* slow_path_label =
        can_be_view ? slow_path->GetByteArrayViewCheckLabel() : slow_path->GetEntryLabel();
    __ Cmp(temp2, static_cast<uint16_t>(primitive_type));
    __ B(slow_path_label, ne);
  }

  // Check for array index out of bounds.
  __ Ldr(temp, HeapOperand(object, array_length_offset.Int32Value()));
  __ Cmp(index, temp);
  __ B(slow_path->GetEntryLabel(), hs);
}

static void GenerateVarHandleCoordinateChecks(HInvoke* invoke,
                                              CodeGeneratorARM64* codegen,
                                              VarHandleSlowPathARM64* slow_path) {
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  if (expected_coordinates_count == 0u) {
    GenerateVarHandleStaticFieldCheck(invoke, codegen, slow_path);
  } else if (expected_coordinates_count == 1u) {
    GenerateVarHandleInstanceFieldChecks(invoke, codegen, slow_path);
  } else {
    DCHECK_EQ(expected_coordinates_count, 2u);
    GenerateVarHandleArrayChecks(invoke, codegen, slow_path);
  }
}

static VarHandleSlowPathARM64* GenerateVarHandleChecks(HInvoke* invoke,
                                                       CodeGeneratorARM64* codegen,
                                                       std::memory_order order,
                                                       DataType::Type type) {
  VarHandleSlowPathARM64* slow_path =
      new (codegen->GetScopedAllocator()) VarHandleSlowPathARM64(invoke, order);
  codegen->AddSlowPath(slow_path);

  GenerateVarHandleAccessModeAndVarTypeChecks(invoke, codegen, slow_path, type);
  GenerateVarHandleCoordinateChecks(invoke, codegen, slow_path);

  return slow_path;
}

struct VarHandleTarget {
  Register object;  // The object holding the value to operate on.
  Register offset;  // The offset of the value to operate on.
};

static VarHandleTarget GetVarHandleTarget(HInvoke* invoke) {
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  LocationSummary* locations = invoke->GetLocations();

  VarHandleTarget target;
  // The temporary allocated for loading the offset.
  target.offset = WRegisterFrom(locations->GetTemp(0u));
  // The reference to the object that holds the value to operate on.
  target.object = (expected_coordinates_count == 0u)
      ? WRegisterFrom(locations->GetTemp(1u))
      : InputRegisterAt(invoke, 1);
  return target;
}

static void GenerateVarHandleTarget(HInvoke* invoke,
                                    const VarHandleTarget& target,
                                    CodeGeneratorARM64* codegen) {
  MacroAssembler* masm = codegen->GetVIXLAssembler();
  Register varhandle = InputRegisterAt(invoke, 0);
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);

  if (expected_coordinates_count <= 1u) {
    // For static fields, we need to fill the `target.object` with the declaring class,
    // so we can use `target.object` as temporary for the `ArtMethod*`. For instance fields,
    // we do not need the declaring class, so we can forget the `ArtMethod*` when
    // we load the `target.offset`, so use the `target.offset` to hold the `ArtMethod*`.
    Register method = (expected_coordinates_count == 0) ? target.object : target.offset;

    const MemberOffset art_field_offset = mirror::FieldVarHandle::ArtFieldOffset();
    const MemberOffset offset_offset = ArtField::OffsetOffset();

    // Load the ArtField, the offset and, if needed, declaring class.
    __ Ldr(method.X(), HeapOperand(varhandle, art_field_offset.Int32Value()));
    __ Ldr(target.offset, MemOperand(method.X(), offset_offset.Int32Value()));
    if (expected_coordinates_count == 0u) {
      codegen->GenerateGcRootFieldLoad(invoke,
                                       LocationFrom(target.object),
                                       method.X(),
                                       ArtField::DeclaringClassOffset().Int32Value(),
                                       /*fixup_label=*/ nullptr,
                                       kCompilerReadBarrierOption);
    }
  } else {
    DCHECK_EQ(expected_coordinates_count, 2u);
    DataType::Type value_type =
        GetVarHandleExpectedValueType(invoke, /*expected_coordinates_count=*/ 2u);
    size_t size_shift = DataType::SizeShift(value_type);
    MemberOffset data_offset = mirror::Array::DataOffset(DataType::Size(value_type));

    Register index = InputRegisterAt(invoke, 2);
    Register shifted_index = index;
    if (size_shift != 0u) {
      shifted_index = target.offset;
      __ Lsl(shifted_index, index, size_shift);
    }
    __ Add(target.offset, shifted_index, data_offset.Int32Value());
  }
}

static bool HasVarHandleIntrinsicImplementation(HInvoke* invoke) {
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  if (expected_coordinates_count > 2u) {
    // Invalid coordinate count. This invoke shall throw at runtime.
    return false;
  }
  if (expected_coordinates_count != 0u &&
      invoke->InputAt(1)->GetType() != DataType::Type::kReference) {
    // Except for static fields (no coordinates), the first coordinate must be a reference.
    return false;
  }
  if (expected_coordinates_count == 2u) {
    // For arrays and views, the second coordinate must be convertible to `int`.
    // In this context, `boolean` is not convertible but we have to look at the shorty
    // as compiler transformations can give the invoke a valid boolean input.
    DataType::Type index_type = GetDataTypeFromShorty(invoke, 2);
    if (index_type == DataType::Type::kBool ||
        DataType::Kind(index_type) != DataType::Type::kInt32) {
      return false;
    }
  }

  uint32_t number_of_arguments = invoke->GetNumberOfArguments();
  DataType::Type return_type = invoke->GetType();
  mirror::VarHandle::AccessModeTemplate access_mode_template =
      mirror::VarHandle::GetAccessModeTemplateByIntrinsic(invoke->GetIntrinsic());
  switch (access_mode_template) {
    case mirror::VarHandle::AccessModeTemplate::kGet:
      // The return type should be the same as varType, so it shouldn't be void.
      if (return_type == DataType::Type::kVoid) {
        return false;
      }
      break;
    case mirror::VarHandle::AccessModeTemplate::kSet:
      if (return_type != DataType::Type::kVoid) {
        return false;
      }
      break;
    case mirror::VarHandle::AccessModeTemplate::kCompareAndSet: {
      if (return_type != DataType::Type::kBool) {
        return false;
      }
      uint32_t expected_value_index = number_of_arguments - 2;
      uint32_t new_value_index = number_of_arguments - 1;
      DataType::Type expected_value_type = GetDataTypeFromShorty(invoke, expected_value_index);
      DataType::Type new_value_type = GetDataTypeFromShorty(invoke, new_value_index);
      if (expected_value_type != new_value_type) {
        return false;
      }
      break;
    }
    case mirror::VarHandle::AccessModeTemplate::kCompareAndExchange: {
      uint32_t expected_value_index = number_of_arguments - 2;
      uint32_t new_value_index = number_of_arguments - 1;
      DataType::Type expected_value_type = GetDataTypeFromShorty(invoke, expected_value_index);
      DataType::Type new_value_type = GetDataTypeFromShorty(invoke, new_value_index);
      if (expected_value_type != new_value_type || return_type != expected_value_type) {
        return false;
      }
      break;
    }
    case mirror::VarHandle::AccessModeTemplate::kGetAndUpdate: {
      DataType::Type value_type = GetDataTypeFromShorty(invoke, number_of_arguments - 1);
      if (IsVarHandleGetAndAdd(invoke) &&
          (value_type == DataType::Type::kReference || value_type == DataType::Type::kBool)) {
        // We should only add numerical types.
        return false;
      } else if (IsVarHandleGetAndBitwiseOp(invoke) && !DataType::IsIntegralType(value_type)) {
        // We can only apply operators to bitwise integral types.
        // Note that bitwise VarHandle operations accept a non-integral boolean type and
        // perform the appropriate logical operation. However, the result is the same as
        // using the bitwise operation on our boolean representation and this fits well
        // with DataType::IsIntegralType() treating the compiler type kBool as integral.
        return false;
      }
      if (value_type != return_type) {
        return false;
      }
      break;
    }
  }

  return true;
}

static LocationSummary* CreateVarHandleCommonLocations(HInvoke* invoke) {
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  DataType::Type return_type = invoke->GetType();

  ArenaAllocator* allocator = invoke->GetBlock()->GetGraph()->GetAllocator();
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  // Require coordinates in registers. These are the object holding the value
  // to operate on (except for static fields) and index (for arrays and views).
  for (size_t i = 0; i != expected_coordinates_count; ++i) {
    locations->SetInAt(/* VarHandle object */ 1u + i, Location::RequiresRegister());
  }
  if (return_type != DataType::Type::kVoid) {
    if (DataType::IsFloatingPointType(return_type)) {
      locations->SetOut(Location::RequiresFpuRegister());
    } else {
      locations->SetOut(Location::RequiresRegister());
    }
  }
  uint32_t arguments_start = /* VarHandle object */ 1u + expected_coordinates_count;
  uint32_t number_of_arguments = invoke->GetNumberOfArguments();
  for (size_t arg_index = arguments_start; arg_index != number_of_arguments; ++arg_index) {
    HInstruction* arg = invoke->InputAt(arg_index);
    if (IsConstantZeroBitPattern(arg)) {
      locations->SetInAt(arg_index, Location::ConstantLocation(arg->AsConstant()));
    } else if (DataType::IsFloatingPointType(arg->GetType())) {
      locations->SetInAt(arg_index, Location::RequiresFpuRegister());
    } else {
      locations->SetInAt(arg_index, Location::RequiresRegister());
    }
  }

  // Add a temporary for offset.
  if ((kEmitCompilerReadBarrier && !kUseBakerReadBarrier) &&
      GetExpectedVarHandleCoordinatesCount(invoke) == 0u) {  // For static fields.
    // To preserve the offset value across the non-Baker read barrier slow path
    // for loading the declaring class, use a fixed callee-save register.
    constexpr int first_callee_save = CTZ(kArm64CalleeSaveRefSpills);
    locations->AddTemp(Location::RegisterLocation(first_callee_save));
  } else {
    locations->AddTemp(Location::RequiresRegister());
  }
  if (expected_coordinates_count == 0u) {
    // Add a temporary to hold the declaring class.
    locations->AddTemp(Location::RequiresRegister());
  }

  return locations;
}

static void CreateVarHandleGetLocations(HInvoke* invoke) {
  if (!HasVarHandleIntrinsicImplementation(invoke)) {
    return;
  }

  if ((kEmitCompilerReadBarrier && !kUseBakerReadBarrier) &&
      invoke->GetType() == DataType::Type::kReference &&
      invoke->GetIntrinsic() != Intrinsics::kVarHandleGet &&
      invoke->GetIntrinsic() != Intrinsics::kVarHandleGetOpaque) {
    // Unsupported for non-Baker read barrier because the artReadBarrierSlow() ignores
    // the passed reference and reloads it from the field. This gets the memory visibility
    // wrong for Acquire/Volatile operations. b/173104084
    return;
  }

  CreateVarHandleCommonLocations(invoke);
}

static void GenerateVarHandleGet(HInvoke* invoke,
                                 CodeGeneratorARM64* codegen,
                                 std::memory_order order,
                                 bool byte_swap = false) {
  DataType::Type type = invoke->GetType();
  DCHECK_NE(type, DataType::Type::kVoid);

  LocationSummary* locations = invoke->GetLocations();
  MacroAssembler* masm = codegen->GetVIXLAssembler();
  CPURegister out = helpers::OutputCPURegister(invoke);

  VarHandleTarget target = GetVarHandleTarget(invoke);
  VarHandleSlowPathARM64* slow_path = nullptr;
  if (!byte_swap) {
    slow_path = GenerateVarHandleChecks(invoke, codegen, order, type);
    GenerateVarHandleTarget(invoke, target, codegen);
    __ Bind(slow_path->GetNativeByteOrderLabel());
  }

  // ARM64 load-acquire instructions are implicitly sequentially consistent.
  bool use_load_acquire =
      (order == std::memory_order_acquire) || (order == std::memory_order_seq_cst);
  DCHECK(use_load_acquire || order == std::memory_order_relaxed);

  // Load the value from the target location.
  if (type == DataType::Type::kReference && kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
    // Piggy-back on the field load path using introspection for the Baker read barrier.
    // The `target.offset` is a temporary, use it for field address.
    Register tmp_ptr = target.offset.X();
    __ Add(tmp_ptr, target.object.X(), target.offset.X());
    codegen->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                   locations->Out(),
                                                   target.object,
                                                   MemOperand(tmp_ptr),
                                                   /*needs_null_check=*/ false,
                                                   use_load_acquire);
    DCHECK(!byte_swap);
  } else {
    MemOperand address(target.object.X(), target.offset.X());
    CPURegister load_reg = out;
    DataType::Type load_type = type;
    UseScratchRegisterScope temps(masm);
    if (byte_swap) {
      if (type == DataType::Type::kInt16) {
        // Avoid unnecessary sign extension before REV16.
        load_type = DataType::Type::kUint16;
      } else if (type == DataType::Type::kFloat32) {
        load_type = DataType::Type::kInt32;
        load_reg = target.offset.W();
      } else if (type == DataType::Type::kFloat64) {
        load_type = DataType::Type::kInt64;
        load_reg = target.offset.X();
      }
    }
    if (use_load_acquire) {
      codegen->LoadAcquire(invoke, load_type, load_reg, address, /*needs_null_check=*/ false);
    } else {
      codegen->Load(load_type, load_reg, address);
    }
    if (type == DataType::Type::kReference) {
      DCHECK(!byte_swap);
      DCHECK(out.IsW());
      Location out_loc = locations->Out();
      Location object_loc = LocationFrom(target.object);
      Location offset_loc = LocationFrom(target.offset);
      codegen->MaybeGenerateReadBarrierSlow(invoke, out_loc, out_loc, object_loc, 0u, offset_loc);
    } else if (byte_swap) {
      GenerateReverseBytes(masm, type, load_reg, out);
    }
  }

  if (!byte_swap) {
    __ Bind(slow_path->GetExitLabel());
  }
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGet(HInvoke* invoke) {
  CreateVarHandleGetLocations(invoke);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGet(HInvoke* invoke) {
  GenerateVarHandleGet(invoke, codegen_, std::memory_order_relaxed);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetOpaque(HInvoke* invoke) {
  CreateVarHandleGetLocations(invoke);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetOpaque(HInvoke* invoke) {
  GenerateVarHandleGet(invoke, codegen_, std::memory_order_relaxed);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAcquire(HInvoke* invoke) {
  CreateVarHandleGetLocations(invoke);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAcquire(HInvoke* invoke) {
  GenerateVarHandleGet(invoke, codegen_, std::memory_order_acquire);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetVolatile(HInvoke* invoke) {
  CreateVarHandleGetLocations(invoke);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetVolatile(HInvoke* invoke) {
  GenerateVarHandleGet(invoke, codegen_, std::memory_order_seq_cst);
}

static void CreateVarHandleSetLocations(HInvoke* invoke) {
  if (!HasVarHandleIntrinsicImplementation(invoke)) {
    return;
  }

  CreateVarHandleCommonLocations(invoke);
}

static void GenerateVarHandleSet(HInvoke* invoke,
                                 CodeGeneratorARM64* codegen,
                                 std::memory_order order,
                                 bool byte_swap = false) {
  uint32_t value_index = invoke->GetNumberOfArguments() - 1;
  DataType::Type value_type = GetDataTypeFromShorty(invoke, value_index);

  MacroAssembler* masm = codegen->GetVIXLAssembler();
  CPURegister value = InputCPURegisterOrZeroRegAt(invoke, value_index);

  VarHandleTarget target = GetVarHandleTarget(invoke);
  VarHandleSlowPathARM64* slow_path = nullptr;
  if (!byte_swap) {
    slow_path = GenerateVarHandleChecks(invoke, codegen, order, value_type);
    GenerateVarHandleTarget(invoke, target, codegen);
    __ Bind(slow_path->GetNativeByteOrderLabel());
  }

  // ARM64 store-release instructions are implicitly sequentially consistent.
  bool use_store_release =
      (order == std::memory_order_release) || (order == std::memory_order_seq_cst);
  DCHECK(use_store_release || order == std::memory_order_relaxed);

  // Store the value to the target location.
  {
    CPURegister source = value;
    UseScratchRegisterScope temps(masm);
    if (kPoisonHeapReferences && value_type == DataType::Type::kReference) {
      DCHECK(value.IsW());
      Register temp = temps.AcquireW();
      __ Mov(temp, value.W());
      codegen->GetAssembler()->PoisonHeapReference(temp);
      source = temp;
    }
    if (byte_swap) {
      DCHECK(!source.IsZero());  // We use the main path for zero as it does not need a byte swap.
      Register temp = source.Is64Bits() ? temps.AcquireX() : temps.AcquireW();
      if (value_type == DataType::Type::kInt16) {
        // Avoid unnecessary sign extension before storing.
        value_type = DataType::Type::kUint16;
      } else if (DataType::IsFloatingPointType(value_type)) {
        __ Fmov(temp, source.Is64Bits() ? source.D() : source.S());
        value_type = source.Is64Bits() ? DataType::Type::kInt64 : DataType::Type::kInt32;
        source = temp;  // Source for the `GenerateReverseBytes()` below.
      }
      GenerateReverseBytes(masm, value_type, source, temp);
      source = temp;
    }
    MemOperand address(target.object.X(), target.offset.X());
    if (use_store_release) {
      codegen->StoreRelease(invoke, value_type, source, address, /*needs_null_check=*/ false);
    } else {
      codegen->Store(value_type, source, address);
    }
  }

  if (CodeGenerator::StoreNeedsWriteBarrier(value_type, invoke->InputAt(value_index))) {
    codegen->MarkGCCard(target.object, Register(value), /*value_can_be_null=*/ true);
  }

  if (!byte_swap) {
    __ Bind(slow_path->GetExitLabel());
  }
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleSet(HInvoke* invoke) {
  CreateVarHandleSetLocations(invoke);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleSet(HInvoke* invoke) {
  GenerateVarHandleSet(invoke, codegen_, std::memory_order_relaxed);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleSetOpaque(HInvoke* invoke) {
  CreateVarHandleSetLocations(invoke);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleSetOpaque(HInvoke* invoke) {
  GenerateVarHandleSet(invoke, codegen_, std::memory_order_relaxed);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleSetRelease(HInvoke* invoke) {
  CreateVarHandleSetLocations(invoke);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleSetRelease(HInvoke* invoke) {
  GenerateVarHandleSet(invoke, codegen_, std::memory_order_release);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleSetVolatile(HInvoke* invoke) {
  CreateVarHandleSetLocations(invoke);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleSetVolatile(HInvoke* invoke) {
  GenerateVarHandleSet(invoke, codegen_, std::memory_order_seq_cst);
}

static void CreateVarHandleCompareAndSetOrExchangeLocations(HInvoke* invoke, bool return_success) {
  if (!HasVarHandleIntrinsicImplementation(invoke)) {
    return;
  }

  uint32_t number_of_arguments = invoke->GetNumberOfArguments();
  DataType::Type value_type = GetDataTypeFromShorty(invoke, number_of_arguments - 1u);
  if ((kEmitCompilerReadBarrier && !kUseBakerReadBarrier) &&
      value_type == DataType::Type::kReference) {
    // Unsupported for non-Baker read barrier because the artReadBarrierSlow() ignores
    // the passed reference and reloads it from the field. This breaks the read barriers
    // in slow path in different ways. The marked old value may not actually be a to-space
    // reference to the same object as `old_value`, breaking slow path assumptions. And
    // for CompareAndExchange, marking the old value after comparison failure may actually
    // return the reference to `expected`, erroneously indicating success even though we
    // did not set the new value. (And it also gets the memory visibility wrong.) b/173104084
    return;
  }

  LocationSummary* locations = CreateVarHandleCommonLocations(invoke);

  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    // We need callee-save registers for both the class object and offset instead of
    // the temporaries reserved in CreateVarHandleCommonLocations().
    static_assert(POPCOUNT(kArm64CalleeSaveRefSpills) >= 2u);
    uint32_t first_callee_save = CTZ(kArm64CalleeSaveRefSpills);
    uint32_t second_callee_save = CTZ(kArm64CalleeSaveRefSpills ^ (1u << first_callee_save));
    if (GetExpectedVarHandleCoordinatesCount(invoke) == 0u) {  // For static fields.
      DCHECK_EQ(locations->GetTempCount(), 2u);
      DCHECK(locations->GetTemp(0u).Equals(Location::RequiresRegister()));
      DCHECK(locations->GetTemp(1u).Equals(Location::RegisterLocation(first_callee_save)));
      locations->SetTempAt(0u, Location::RegisterLocation(second_callee_save));
    } else {
      DCHECK_EQ(locations->GetTempCount(), 1u);
      DCHECK(locations->GetTemp(0u).Equals(Location::RequiresRegister()));
      locations->SetTempAt(0u, Location::RegisterLocation(first_callee_save));
    }
  }
  size_t old_temp_count = locations->GetTempCount();
  DCHECK_EQ(old_temp_count, (GetExpectedVarHandleCoordinatesCount(invoke) == 0) ? 2u : 1u);
  if (!return_success) {
    if (DataType::IsFloatingPointType(value_type)) {
      // Add a temporary for old value and exclusive store result if floating point
      // `expected` and/or `new_value` take scratch registers.
      size_t available_scratch_registers =
          (IsConstantZeroBitPattern(invoke->InputAt(number_of_arguments - 1u)) ? 1u : 0u) +
          (IsConstantZeroBitPattern(invoke->InputAt(number_of_arguments - 2u)) ? 1u : 0u);
      size_t temps_needed = /* pointer, old value, store result */ 3u - available_scratch_registers;
      // We can reuse the declaring class (if present) and offset temporary.
      if (temps_needed > old_temp_count) {
        locations->AddRegisterTemps(temps_needed - old_temp_count);
      }
    } else if ((value_type != DataType::Type::kReference && DataType::Size(value_type) != 1u) &&
               !IsConstantZeroBitPattern(invoke->InputAt(number_of_arguments - 2u)) &&
               !IsConstantZeroBitPattern(invoke->InputAt(number_of_arguments - 1u)) &&
               GetExpectedVarHandleCoordinatesCount(invoke) == 2u) {
      // Allocate a normal temporary for store result in the non-native byte order path
      // because scratch registers are used by the byte-swapped `expected` and `new_value`.
      DCHECK_EQ(old_temp_count, 1u);
      locations->AddTemp(Location::RequiresRegister());
    }
  }
  if (kEmitCompilerReadBarrier && value_type == DataType::Type::kReference) {
    // Add a temporary for the `old_value_temp` in slow path.
    locations->AddTemp(Location::RequiresRegister());
  }
}

static Register MoveToTempIfFpRegister(const CPURegister& cpu_reg,
                                       DataType::Type type,
                                       MacroAssembler* masm,
                                       UseScratchRegisterScope* temps) {
  if (cpu_reg.IsS()) {
    DCHECK_EQ(type, DataType::Type::kFloat32);
    Register reg = temps->AcquireW();
    __ Fmov(reg, cpu_reg.S());
    return reg;
  } else if (cpu_reg.IsD()) {
    DCHECK_EQ(type, DataType::Type::kFloat64);
    Register reg = temps->AcquireX();
    __ Fmov(reg, cpu_reg.D());
    return reg;
  } else {
    return DataType::Is64BitType(type) ? cpu_reg.X() : cpu_reg.W();
  }
}

static void GenerateVarHandleCompareAndSetOrExchange(HInvoke* invoke,
                                                     CodeGeneratorARM64* codegen,
                                                     std::memory_order order,
                                                     bool return_success,
                                                     bool strong,
                                                     bool byte_swap = false) {
  DCHECK(return_success || strong);

  uint32_t expected_index = invoke->GetNumberOfArguments() - 2;
  uint32_t new_value_index = invoke->GetNumberOfArguments() - 1;
  DataType::Type value_type = GetDataTypeFromShorty(invoke, new_value_index);
  DCHECK_EQ(value_type, GetDataTypeFromShorty(invoke, expected_index));

  MacroAssembler* masm = codegen->GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();
  CPURegister expected = InputCPURegisterOrZeroRegAt(invoke, expected_index);
  CPURegister new_value = InputCPURegisterOrZeroRegAt(invoke, new_value_index);
  CPURegister out = helpers::OutputCPURegister(invoke);

  VarHandleTarget target = GetVarHandleTarget(invoke);
  VarHandleSlowPathARM64* slow_path = nullptr;
  if (!byte_swap) {
    slow_path = GenerateVarHandleChecks(invoke, codegen, order, value_type);
    slow_path->SetCompareAndSetOrExchangeArgs(return_success, strong);
    GenerateVarHandleTarget(invoke, target, codegen);
    __ Bind(slow_path->GetNativeByteOrderLabel());
  }

  // This needs to be before the temp registers, as MarkGCCard also uses VIXL temps.
  if (CodeGenerator::StoreNeedsWriteBarrier(value_type, invoke->InputAt(new_value_index))) {
    // Mark card for object assuming new value is stored.
    bool new_value_can_be_null = true;  // TODO: Worth finding out this information?
    codegen->MarkGCCard(target.object, new_value.W(), new_value_can_be_null);
  }

  // Reuse the `offset` temporary for the pointer to the target location,
  // except for references that need the offset for the read barrier.
  UseScratchRegisterScope temps(masm);
  Register tmp_ptr = target.offset.X();
  if (kEmitCompilerReadBarrier && value_type == DataType::Type::kReference) {
    tmp_ptr = temps.AcquireX();
  }
  __ Add(tmp_ptr, target.object.X(), target.offset.X());

  // Move floating point values to scratch registers.
  // Note that float/double CAS uses bitwise comparison, rather than the operator==.
  Register expected_reg = MoveToTempIfFpRegister(expected, value_type, masm, &temps);
  Register new_value_reg = MoveToTempIfFpRegister(new_value, value_type, masm, &temps);
  bool is_fp = DataType::IsFloatingPointType(value_type);
  DataType::Type cas_type = is_fp
      ? ((value_type == DataType::Type::kFloat64) ? DataType::Type::kInt64 : DataType::Type::kInt32)
      : value_type;
  // Avoid sign extension in the CAS loop by zero-extending `expected` before the loop. This adds
  // one instruction for CompareAndExchange as we shall need to sign-extend the returned value.
  if (value_type == DataType::Type::kInt16 && !expected.IsZero()) {
    Register temp = temps.AcquireW();
    __ Uxth(temp, expected_reg);
    expected_reg = temp;
    cas_type = DataType::Type::kUint16;
  } else if (value_type == DataType::Type::kInt8 && !expected.IsZero()) {
    Register temp = temps.AcquireW();
    __ Uxtb(temp, expected_reg);
    expected_reg = temp;
    cas_type = DataType::Type::kUint8;
  }

  if (byte_swap) {
    // Do the byte swap and move values to scratch registers if needed.
    // Non-zero FP values and non-zero `expected` for `kInt16` are already in scratch registers.
    DCHECK_NE(value_type, DataType::Type::kInt8);
    if (!expected.IsZero()) {
      bool is_scratch = is_fp || (value_type == DataType::Type::kInt16);
      Register temp = is_scratch ? expected_reg : temps.AcquireSameSizeAs(expected_reg);
      GenerateReverseBytes(masm, cas_type, expected_reg, temp);
      expected_reg = temp;
    }
    if (!new_value.IsZero()) {
      Register temp = is_fp ? new_value_reg : temps.AcquireSameSizeAs(new_value_reg);
      GenerateReverseBytes(masm, cas_type, new_value_reg, temp);
      new_value_reg = temp;
    }
  }

  // Prepare registers for old value and the result of the exclusive store.
  Register old_value;
  Register store_result;
  if (return_success) {
    // Use the output register for both old value and exclusive store result.
    old_value = (cas_type == DataType::Type::kInt64) ? out.X() : out.W();
    store_result = out.W();
  } else if (DataType::IsFloatingPointType(value_type)) {
    // We need two temporary registers but we have already used scratch registers for
    // holding the expected and new value unless they are zero bit pattern (+0.0f or
    // +0.0). We have allocated sufficient normal temporaries to handle that.
    size_t next_temp = 1u;
    if (expected.IsZero()) {
      old_value = (cas_type == DataType::Type::kInt64) ? temps.AcquireX() : temps.AcquireW();
    } else {
      Location temp = locations->GetTemp(next_temp);
      ++next_temp;
      old_value = (cas_type == DataType::Type::kInt64) ? XRegisterFrom(temp) : WRegisterFrom(temp);
    }
    store_result =
        new_value.IsZero() ? temps.AcquireW() : WRegisterFrom(locations->GetTemp(next_temp));
    DCHECK(!old_value.Is(tmp_ptr));
    DCHECK(!store_result.Is(tmp_ptr));
  } else {
    // Use the output register for the old value.
    old_value = (cas_type == DataType::Type::kInt64) ? out.X() : out.W();
    // Use scratch register for the store result, except when we have used up
    // scratch registers for byte-swapped `expected` and `new_value`.
    // In that case, we have allocated a normal temporary.
    store_result = (byte_swap && !expected.IsZero() && !new_value.IsZero())
        ? WRegisterFrom(locations->GetTemp(1))
        : temps.AcquireW();
    DCHECK(!store_result.Is(tmp_ptr));
  }

  vixl::aarch64::Label exit_loop_label;
  vixl::aarch64::Label* exit_loop = &exit_loop_label;
  vixl::aarch64::Label* cmp_failure = &exit_loop_label;

  if (kEmitCompilerReadBarrier && value_type == DataType::Type::kReference) {
    // The `old_value_temp` is used first for the marked `old_value` and then for the unmarked
    // reloaded old value for subsequent CAS in the slow path. It cannot be a scratch register.
    size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
    Register old_value_temp =
        WRegisterFrom(locations->GetTemp((expected_coordinates_count == 0u) ? 2u : 1u));
    // For strong CAS, use a scratch register for the store result in slow path.
    // For weak CAS, we need to check the store result, so store it in `store_result`.
    Register slow_path_store_result = strong ? Register() : store_result;
    ReadBarrierCasSlowPathARM64* rb_slow_path =
        new (codegen->GetScopedAllocator()) ReadBarrierCasSlowPathARM64(
            invoke,
            order,
            strong,
            target.object,
            target.offset.X(),
            expected_reg,
            new_value_reg,
            old_value,
            old_value_temp,
            slow_path_store_result,
            /*update_old_value=*/ !return_success,
            codegen);
    codegen->AddSlowPath(rb_slow_path);
    exit_loop = rb_slow_path->GetExitLabel();
    cmp_failure = rb_slow_path->GetEntryLabel();
  }

  GenerateCompareAndSet(codegen,
                        cas_type,
                        order,
                        strong,
                        cmp_failure,
                        tmp_ptr,
                        new_value_reg,
                        old_value,
                        store_result,
                        expected_reg);
  __ Bind(exit_loop);

  if (return_success) {
    if (strong) {
      __ Cset(out.W(), eq);
    } else {
      // On success, the Z flag is set and the store result is 1, see GenerateCompareAndSet().
      // On failure, either the Z flag is clear or the store result is 0.
      // Determine the final success value with a CSEL.
      __ Csel(out.W(), store_result, wzr, eq);
    }
  } else if (byte_swap) {
    // Also handles moving to FP registers.
    GenerateReverseBytes(masm, value_type, old_value, out);
  } else if (DataType::IsFloatingPointType(value_type)) {
    __ Fmov((value_type == DataType::Type::kFloat64) ? out.D() : out.S(), old_value);
  } else if (value_type == DataType::Type::kInt8) {
    __ Sxtb(out.W(), old_value);
  } else if (value_type == DataType::Type::kInt16) {
    __ Sxth(out.W(), old_value);
  }

  if (!byte_swap) {
    __ Bind(slow_path->GetExitLabel());
  }
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleCompareAndExchange(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke, /*return_success=*/ false);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleCompareAndExchange(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(
      invoke, codegen_, std::memory_order_seq_cst, /*return_success=*/ false, /*strong=*/ true);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleCompareAndExchangeAcquire(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke, /*return_success=*/ false);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleCompareAndExchangeAcquire(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(
      invoke, codegen_, std::memory_order_acquire, /*return_success=*/ false, /*strong=*/ true);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleCompareAndExchangeRelease(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke, /*return_success=*/ false);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleCompareAndExchangeRelease(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(
      invoke, codegen_, std::memory_order_release, /*return_success=*/ false, /*strong=*/ true);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleCompareAndSet(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke, /*return_success=*/ true);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleCompareAndSet(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(
      invoke, codegen_, std::memory_order_seq_cst, /*return_success=*/ true, /*strong=*/ true);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleWeakCompareAndSet(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke, /*return_success=*/ true);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleWeakCompareAndSet(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(
      invoke, codegen_, std::memory_order_seq_cst, /*return_success=*/ true, /*strong=*/ false);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleWeakCompareAndSetAcquire(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke, /*return_success=*/ true);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleWeakCompareAndSetAcquire(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(
      invoke, codegen_, std::memory_order_acquire, /*return_success=*/ true, /*strong=*/ false);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleWeakCompareAndSetPlain(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke, /*return_success=*/ true);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleWeakCompareAndSetPlain(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(
      invoke, codegen_, std::memory_order_relaxed, /*return_success=*/ true, /*strong=*/ false);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleWeakCompareAndSetRelease(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke, /*return_success=*/ true);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleWeakCompareAndSetRelease(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(
      invoke, codegen_, std::memory_order_release, /*return_success=*/ true, /*strong=*/ false);
}

static void CreateVarHandleGetAndUpdateLocations(HInvoke* invoke,
                                                 GetAndUpdateOp get_and_update_op) {
  if (!HasVarHandleIntrinsicImplementation(invoke)) {
    return;
  }

  if ((kEmitCompilerReadBarrier && !kUseBakerReadBarrier) &&
      invoke->GetType() == DataType::Type::kReference) {
    // Unsupported for non-Baker read barrier because the artReadBarrierSlow() ignores
    // the passed reference and reloads it from the field, thus seeing the new value
    // that we have just stored. (And it also gets the memory visibility wrong.) b/173104084
    return;
  }

  LocationSummary* locations = CreateVarHandleCommonLocations(invoke);

  size_t old_temp_count = locations->GetTempCount();
  DCHECK_EQ(old_temp_count, (GetExpectedVarHandleCoordinatesCount(invoke) == 0) ? 2u : 1u);
  if (DataType::IsFloatingPointType(invoke->GetType())) {
    if (get_and_update_op == GetAndUpdateOp::kAdd) {
      // For ADD, do not use ZR for zero bit pattern (+0.0f or +0.0).
      locations->SetInAt(invoke->GetNumberOfArguments() - 1u, Location::RequiresFpuRegister());
    } else {
      DCHECK(get_and_update_op == GetAndUpdateOp::kSet);
      // We can reuse the declaring class temporary if present.
      if (old_temp_count == 1u &&
          !IsConstantZeroBitPattern(invoke->InputAt(invoke->GetNumberOfArguments() - 1u))) {
        // Add a temporary for `old_value` if floating point `new_value` takes a scratch register.
        locations->AddTemp(Location::RequiresRegister());
      }
    }
  }
  // We need a temporary for the byte-swap path for bitwise operations unless the argument is a
  // zero which does not need a byte-swap. We can reuse the declaring class temporary if present.
  if (old_temp_count == 1u &&
      (get_and_update_op != GetAndUpdateOp::kSet && get_and_update_op != GetAndUpdateOp::kAdd) &&
      GetExpectedVarHandleCoordinatesCount(invoke) == 2u &&
      !IsConstantZeroBitPattern(invoke->InputAt(invoke->GetNumberOfArguments() - 1u))) {
    DataType::Type value_type =
        GetVarHandleExpectedValueType(invoke, /*expected_coordinates_count=*/ 2u);
    if (value_type != DataType::Type::kReference && DataType::Size(value_type) != 1u) {
      locations->AddTemp(Location::RequiresRegister());
    }
  }
}

static void GenerateVarHandleGetAndUpdate(HInvoke* invoke,
                                          CodeGeneratorARM64* codegen,
                                          GetAndUpdateOp get_and_update_op,
                                          std::memory_order order,
                                          bool byte_swap = false) {
  uint32_t arg_index = invoke->GetNumberOfArguments() - 1;
  DataType::Type value_type = GetDataTypeFromShorty(invoke, arg_index);

  MacroAssembler* masm = codegen->GetVIXLAssembler();
  LocationSummary* locations = invoke->GetLocations();
  CPURegister arg = InputCPURegisterOrZeroRegAt(invoke, arg_index);
  CPURegister out = helpers::OutputCPURegister(invoke);

  VarHandleTarget target = GetVarHandleTarget(invoke);
  VarHandleSlowPathARM64* slow_path = nullptr;
  if (!byte_swap) {
    slow_path = GenerateVarHandleChecks(invoke, codegen, order, value_type);
    slow_path->SetGetAndUpdateOp(get_and_update_op);
    GenerateVarHandleTarget(invoke, target, codegen);
    __ Bind(slow_path->GetNativeByteOrderLabel());
  }

  // This needs to be before the temp registers, as MarkGCCard also uses VIXL temps.
  if (CodeGenerator::StoreNeedsWriteBarrier(value_type, invoke->InputAt(arg_index))) {
    DCHECK(get_and_update_op == GetAndUpdateOp::kSet);
    // Mark card for object, the new value shall be stored.
    bool new_value_can_be_null = true;  // TODO: Worth finding out this information?
    codegen->MarkGCCard(target.object, arg.W(), new_value_can_be_null);
  }

  // Reuse the `target.offset` temporary for the pointer to the target location,
  // except for references that need the offset for the non-Baker read barrier.
  UseScratchRegisterScope temps(masm);
  Register tmp_ptr = target.offset.X();
  if ((kEmitCompilerReadBarrier && !kUseBakerReadBarrier) &&
      value_type == DataType::Type::kReference) {
    tmp_ptr = temps.AcquireX();
  }
  __ Add(tmp_ptr, target.object.X(), target.offset.X());

  // The load/store type is never floating point.
  bool is_fp = DataType::IsFloatingPointType(value_type);
  DataType::Type load_store_type = is_fp
      ? ((value_type == DataType::Type::kFloat32) ? DataType::Type::kInt32 : DataType::Type::kInt64)
      : value_type;
  // Avoid sign extension in the CAS loop. Sign-extend after the loop.
  // Note: Using unsigned values yields the same value to store (we do not store higher bits).
  if (value_type == DataType::Type::kInt8) {
    load_store_type = DataType::Type::kUint8;
  } else if (value_type == DataType::Type::kInt16) {
    load_store_type = DataType::Type::kUint16;
  }

  // Prepare register for old value.
  CPURegister old_value = out;
  if (get_and_update_op == GetAndUpdateOp::kSet) {
    // For floating point GetAndSet, do the GenerateGetAndUpdate() with core registers,
    // rather than moving between core and FP registers in the loop.
    arg = MoveToTempIfFpRegister(arg, value_type, masm, &temps);
    if (DataType::IsFloatingPointType(value_type) && !arg.IsZero()) {
      // We need a temporary register but we have already used a scratch register for
      // the new value unless it is zero bit pattern (+0.0f or +0.0) and need another one
      // in GenerateGetAndUpdate(). We have allocated a normal temporary to handle that.
      old_value = CPURegisterFrom(locations->GetTemp(1u), load_store_type);
    } else if ((kEmitCompilerReadBarrier && kUseBakerReadBarrier) &&
               value_type == DataType::Type::kReference) {
      // Load the old value initially to a scratch register.
      // We shall move it to `out` later with a read barrier.
      old_value = temps.AcquireW();
    }
  }

  if (byte_swap) {
    DCHECK_NE(value_type, DataType::Type::kReference);
    DCHECK_NE(DataType::Size(value_type), 1u);
    if (get_and_update_op == GetAndUpdateOp::kAdd) {
      // We need to do the byte swapping in the CAS loop for GetAndAdd.
      get_and_update_op = GetAndUpdateOp::kAddWithByteSwap;
    } else if (!arg.IsZero()) {
      // For other operations, avoid byte swap inside the CAS loop by providing an adjusted `arg`.
      // For GetAndSet use a scratch register; FP argument is already in a scratch register.
      // For bitwise operations GenerateGetAndUpdate() needs both scratch registers;
      // we have allocated a normal temporary to handle that.
      CPURegister temp = (get_and_update_op == GetAndUpdateOp::kSet)
          ? (is_fp ? arg : (arg.Is64Bits() ? temps.AcquireX() : temps.AcquireW()))
          : CPURegisterFrom(locations->GetTemp(1u), load_store_type);
      GenerateReverseBytes(masm, load_store_type, arg, temp);
      arg = temp;
    }
  }

  GenerateGetAndUpdate(codegen, get_and_update_op, load_store_type, order, tmp_ptr, arg, old_value);

  if (get_and_update_op == GetAndUpdateOp::kAddWithByteSwap) {
    // The only adjustment needed is sign-extension for `kInt16`.
    // Everything else has been done by the `GenerateGetAndUpdate()`.
    DCHECK(byte_swap);
    if (value_type == DataType::Type::kInt16) {
      DCHECK_EQ(load_store_type, DataType::Type::kUint16);
      __ Sxth(out.W(), old_value.W());
    }
  } else if (byte_swap) {
    // Also handles moving to FP registers.
    GenerateReverseBytes(masm, value_type, old_value, out);
  } else if (get_and_update_op == GetAndUpdateOp::kSet && value_type == DataType::Type::kFloat64) {
    __ Fmov(out.D(), old_value.X());
  } else if (get_and_update_op == GetAndUpdateOp::kSet && value_type == DataType::Type::kFloat32) {
    __ Fmov(out.S(), old_value.W());
  } else if (value_type == DataType::Type::kInt8) {
    __ Sxtb(out.W(), old_value.W());
  } else if (value_type == DataType::Type::kInt16) {
    __ Sxth(out.W(), old_value.W());
  } else if (kEmitCompilerReadBarrier && value_type == DataType::Type::kReference) {
    if (kUseBakerReadBarrier) {
      codegen->GenerateIntrinsicCasMoveWithBakerReadBarrier(out.W(), old_value.W());
    } else {
      codegen->GenerateReadBarrierSlow(
          invoke,
          Location::RegisterLocation(out.GetCode()),
          Location::RegisterLocation(old_value.GetCode()),
          Location::RegisterLocation(target.object.GetCode()),
          /*offset=*/ 0u,
          /*index=*/ Location::RegisterLocation(target.offset.GetCode()));
    }
  }

  if (!byte_swap) {
    __ Bind(slow_path->GetExitLabel());
  }
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndSet(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kSet);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndSet(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kSet, std::memory_order_seq_cst);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndSetAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kSet);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndSetAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kSet, std::memory_order_acquire);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndSetRelease(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kSet);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndSetRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kSet, std::memory_order_release);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndAdd(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kAdd);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndAdd(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kAdd, std::memory_order_seq_cst);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndAddAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kAdd);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndAddAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kAdd, std::memory_order_acquire);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndAddRelease(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kAdd);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndAddRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kAdd, std::memory_order_release);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndBitwiseAnd(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kAnd);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndBitwiseAnd(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kAnd, std::memory_order_seq_cst);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndBitwiseAndAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kAnd);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndBitwiseAndAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kAnd, std::memory_order_acquire);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndBitwiseAndRelease(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kAnd);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndBitwiseAndRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kAnd, std::memory_order_release);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndBitwiseOr(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kOr);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndBitwiseOr(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kOr, std::memory_order_seq_cst);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndBitwiseOrAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kOr);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndBitwiseOrAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kOr, std::memory_order_acquire);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndBitwiseOrRelease(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kOr);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndBitwiseOrRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kOr, std::memory_order_release);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndBitwiseXor(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kXor);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndBitwiseXor(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kXor, std::memory_order_seq_cst);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndBitwiseXorAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kXor);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndBitwiseXorAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kXor, std::memory_order_acquire);
}

void IntrinsicLocationsBuilderARM64::VisitVarHandleGetAndBitwiseXorRelease(HInvoke* invoke) {
  CreateVarHandleGetAndUpdateLocations(invoke, GetAndUpdateOp::kXor);
}

void IntrinsicCodeGeneratorARM64::VisitVarHandleGetAndBitwiseXorRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndUpdate(invoke, codegen_, GetAndUpdateOp::kXor, std::memory_order_release);
}

void VarHandleSlowPathARM64::EmitByteArrayViewCode(CodeGenerator* codegen_in) {
  DCHECK(GetByteArrayViewCheckLabel()->IsLinked());
  CodeGeneratorARM64* codegen = down_cast<CodeGeneratorARM64*>(codegen_in);
  MacroAssembler* masm = codegen->GetVIXLAssembler();
  HInvoke* invoke = GetInvoke();
  mirror::VarHandle::AccessModeTemplate access_mode_template = GetAccessModeTemplate();
  DataType::Type value_type =
      GetVarHandleExpectedValueType(invoke, /*expected_coordinates_count=*/ 2u);
  DCHECK_NE(value_type, DataType::Type::kReference);
  size_t size = DataType::Size(value_type);
  DCHECK_GT(size, 1u);
  Register varhandle = InputRegisterAt(invoke, 0);
  Register object = InputRegisterAt(invoke, 1);
  Register index = InputRegisterAt(invoke, 2);

  MemberOffset class_offset = mirror::Object::ClassOffset();
  MemberOffset array_length_offset = mirror::Array::LengthOffset();
  MemberOffset data_offset = mirror::Array::DataOffset(Primitive::kPrimByte);
  MemberOffset native_byte_order_offset = mirror::ByteArrayViewVarHandle::NativeByteOrderOffset();

  __ Bind(GetByteArrayViewCheckLabel());

  VarHandleTarget target = GetVarHandleTarget(invoke);
  {
    UseScratchRegisterScope temps(masm);
    Register temp = temps.AcquireW();
    Register temp2 = temps.AcquireW();

    // The main path checked that the coordinateType0 is an array class that matches
    // the class of the actual coordinate argument but it does not match the value type.
    // Check if the `varhandle` references a ByteArrayViewVarHandle instance.
    __ Ldr(temp, HeapOperand(varhandle, class_offset.Int32Value()));
    codegen->LoadClassRootForIntrinsic(temp2, ClassRoot::kJavaLangInvokeByteArrayViewVarHandle);
    __ Cmp(temp, temp2);
    __ B(GetEntryLabel(), ne);

    // Check for array index out of bounds.
    __ Ldr(temp, HeapOperand(object, array_length_offset.Int32Value()));
    __ Subs(temp, temp, index);
    __ Ccmp(temp, size, NoFlag, hs);  // If SUBS yields LO (C=false), keep the C flag clear.
    __ B(GetEntryLabel(), lo);

    // Construct the target.
    __ Add(target.offset, index, data_offset.Int32Value());

    // Alignment check. For unaligned access, go to the runtime.
    DCHECK(IsPowerOfTwo(size));
    if (size == 2u) {
      __ Tbnz(target.offset, 0, GetEntryLabel());
    } else {
      __ Tst(target.offset, size - 1u);
      __ B(GetEntryLabel(), ne);
    }

    // Byte order check. For native byte order return to the main path.
    if (access_mode_template == mirror::VarHandle::AccessModeTemplate::kSet &&
        IsConstantZeroBitPattern(invoke->InputAt(invoke->GetNumberOfArguments() - 1u))) {
      // There is no reason to differentiate between native byte order and byte-swap
      // for setting a zero bit pattern. Just return to the main path.
      __ B(GetNativeByteOrderLabel());
      return;
    }
    __ Ldr(temp, HeapOperand(varhandle, native_byte_order_offset.Int32Value()));
    __ Cbnz(temp, GetNativeByteOrderLabel());
  }

  switch (access_mode_template) {
    case mirror::VarHandle::AccessModeTemplate::kGet:
      GenerateVarHandleGet(invoke, codegen, order_, /*byte_swap=*/ true);
      break;
    case mirror::VarHandle::AccessModeTemplate::kSet:
      GenerateVarHandleSet(invoke, codegen, order_, /*byte_swap=*/ true);
      break;
    case mirror::VarHandle::AccessModeTemplate::kCompareAndSet:
    case mirror::VarHandle::AccessModeTemplate::kCompareAndExchange:
      GenerateVarHandleCompareAndSetOrExchange(
          invoke, codegen, order_, return_success_, strong_, /*byte_swap=*/ true);
      break;
    case mirror::VarHandle::AccessModeTemplate::kGetAndUpdate:
      GenerateVarHandleGetAndUpdate(
          invoke, codegen, get_and_update_op_, order_, /*byte_swap=*/ true);
      break;
  }
  __ B(GetExitLabel());
}

UNIMPLEMENTED_INTRINSIC(ARM64, StringStringIndexOf);
UNIMPLEMENTED_INTRINSIC(ARM64, StringStringIndexOfAfter);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBufferAppend);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBufferLength);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBufferToString);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendObject);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendString);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendCharSequence);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendCharArray);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendBoolean);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendChar);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendInt);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendLong);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendFloat);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderAppendDouble);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderLength);
UNIMPLEMENTED_INTRINSIC(ARM64, StringBuilderToString);

// 1.8.
UNIMPLEMENTED_INTRINSIC(ARM64, UnsafeGetAndAddInt)
UNIMPLEMENTED_INTRINSIC(ARM64, UnsafeGetAndAddLong)
UNIMPLEMENTED_INTRINSIC(ARM64, UnsafeGetAndSetInt)
UNIMPLEMENTED_INTRINSIC(ARM64, UnsafeGetAndSetLong)
UNIMPLEMENTED_INTRINSIC(ARM64, UnsafeGetAndSetObject)

UNIMPLEMENTED_INTRINSIC(ARM64, MethodHandleInvokeExact)
UNIMPLEMENTED_INTRINSIC(ARM64, MethodHandleInvoke)

UNREACHABLE_INTRINSICS(ARM64)

#undef __

}  // namespace arm64
}  // namespace art
