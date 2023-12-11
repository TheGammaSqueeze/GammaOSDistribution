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

#include "intrinsics_x86.h"

#include <limits>

#include "arch/x86/instruction_set_features_x86.h"
#include "art_method.h"
#include "base/bit_utils.h"
#include "code_generator_x86.h"
#include "data_type-inl.h"
#include "entrypoints/quick/quick_entrypoints.h"
#include "heap_poisoning.h"
#include "intrinsics.h"
#include "intrinsics_utils.h"
#include "lock_word.h"
#include "mirror/array-inl.h"
#include "mirror/object_array-inl.h"
#include "mirror/reference.h"
#include "mirror/string.h"
#include "mirror/var_handle.h"
#include "scoped_thread_state_change-inl.h"
#include "thread-current-inl.h"
#include "utils/x86/assembler_x86.h"
#include "utils/x86/constants_x86.h"

namespace art {

namespace x86 {

IntrinsicLocationsBuilderX86::IntrinsicLocationsBuilderX86(CodeGeneratorX86* codegen)
  : allocator_(codegen->GetGraph()->GetAllocator()),
    codegen_(codegen) {
}


X86Assembler* IntrinsicCodeGeneratorX86::GetAssembler() {
  return down_cast<X86Assembler*>(codegen_->GetAssembler());
}

ArenaAllocator* IntrinsicCodeGeneratorX86::GetAllocator() {
  return codegen_->GetGraph()->GetAllocator();
}

bool IntrinsicLocationsBuilderX86::TryDispatch(HInvoke* invoke) {
  Dispatch(invoke);
  LocationSummary* res = invoke->GetLocations();
  if (res == nullptr) {
    return false;
  }
  return res->Intrinsified();
}

using IntrinsicSlowPathX86 = IntrinsicSlowPath<InvokeDexCallingConventionVisitorX86>;

// NOLINT on __ macro to suppress wrong warning/fix (misc-macro-parentheses) from clang-tidy.
#define __ down_cast<X86Assembler*>(codegen->GetAssembler())->  // NOLINT

// Slow path implementing the SystemArrayCopy intrinsic copy loop with read barriers.
class ReadBarrierSystemArrayCopySlowPathX86 : public SlowPathCode {
 public:
  explicit ReadBarrierSystemArrayCopySlowPathX86(HInstruction* instruction)
      : SlowPathCode(instruction) {
    DCHECK(kEmitCompilerReadBarrier);
    DCHECK(kUseBakerReadBarrier);
  }

  void EmitNativeCode(CodeGenerator* codegen) override {
    CodeGeneratorX86* x86_codegen = down_cast<CodeGeneratorX86*>(codegen);
    LocationSummary* locations = instruction_->GetLocations();
    DCHECK(locations->CanCall());
    DCHECK(instruction_->IsInvokeStaticOrDirect())
        << "Unexpected instruction in read barrier arraycopy slow path: "
        << instruction_->DebugName();
    DCHECK(instruction_->GetLocations()->Intrinsified());
    DCHECK_EQ(instruction_->AsInvoke()->GetIntrinsic(), Intrinsics::kSystemArrayCopy);

    int32_t element_size = DataType::Size(DataType::Type::kReference);
    uint32_t offset = mirror::Array::DataOffset(element_size).Uint32Value();

    Register src = locations->InAt(0).AsRegister<Register>();
    Location src_pos = locations->InAt(1);
    Register dest = locations->InAt(2).AsRegister<Register>();
    Location dest_pos = locations->InAt(3);
    Location length = locations->InAt(4);
    Location temp1_loc = locations->GetTemp(0);
    Register temp1 = temp1_loc.AsRegister<Register>();
    Register temp2 = locations->GetTemp(1).AsRegister<Register>();
    Register temp3 = locations->GetTemp(2).AsRegister<Register>();

    __ Bind(GetEntryLabel());
    // In this code path, registers `temp1`, `temp2`, and `temp3`
    // (resp.) are not used for the base source address, the base
    // destination address, and the end source address (resp.), as in
    // other SystemArrayCopy intrinsic code paths.  Instead they are
    // (resp.) used for:
    // - the loop index (`i`);
    // - the source index (`src_index`) and the loaded (source)
    //   reference (`value`); and
    // - the destination index (`dest_index`).

    // i = 0
    __ xorl(temp1, temp1);
    NearLabel loop;
    __ Bind(&loop);
    // value = src_array[i + src_pos]
    if (src_pos.IsConstant()) {
      int32_t constant = src_pos.GetConstant()->AsIntConstant()->GetValue();
      int32_t adjusted_offset = offset + constant * element_size;
      __ movl(temp2, Address(src, temp1, ScaleFactor::TIMES_4, adjusted_offset));
    } else {
      __ leal(temp2, Address(src_pos.AsRegister<Register>(), temp1, ScaleFactor::TIMES_1, 0));
      __ movl(temp2, Address(src, temp2, ScaleFactor::TIMES_4, offset));
    }
    __ MaybeUnpoisonHeapReference(temp2);
    // TODO: Inline the mark bit check before calling the runtime?
    // value = ReadBarrier::Mark(value)
    // No need to save live registers; it's taken care of by the
    // entrypoint. Also, there is no need to update the stack mask,
    // as this runtime call will not trigger a garbage collection.
    // (See ReadBarrierMarkSlowPathX86::EmitNativeCode for more
    // explanations.)
    DCHECK_NE(temp2, ESP);
    DCHECK(0 <= temp2 && temp2 < kNumberOfCpuRegisters) << temp2;
    int32_t entry_point_offset = Thread::ReadBarrierMarkEntryPointsOffset<kX86PointerSize>(temp2);
    // This runtime call does not require a stack map.
    x86_codegen->InvokeRuntimeWithoutRecordingPcInfo(entry_point_offset, instruction_, this);
    __ MaybePoisonHeapReference(temp2);
    // dest_array[i + dest_pos] = value
    if (dest_pos.IsConstant()) {
      int32_t constant = dest_pos.GetConstant()->AsIntConstant()->GetValue();
      int32_t adjusted_offset = offset + constant * element_size;
      __ movl(Address(dest, temp1, ScaleFactor::TIMES_4, adjusted_offset), temp2);
    } else {
      __ leal(temp3, Address(dest_pos.AsRegister<Register>(), temp1, ScaleFactor::TIMES_1, 0));
      __ movl(Address(dest, temp3, ScaleFactor::TIMES_4, offset), temp2);
    }
    // ++i
    __ addl(temp1, Immediate(1));
    // if (i != length) goto loop
    x86_codegen->GenerateIntCompare(temp1_loc, length);
    __ j(kNotEqual, &loop);
    __ jmp(GetExitLabel());
  }

  const char* GetDescription() const override { return "ReadBarrierSystemArrayCopySlowPathX86"; }

 private:
  DISALLOW_COPY_AND_ASSIGN(ReadBarrierSystemArrayCopySlowPathX86);
};

#undef __

#define __ assembler->

static void CreateFPToIntLocations(ArenaAllocator* allocator, HInvoke* invoke, bool is64bit) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresFpuRegister());
  locations->SetOut(Location::RequiresRegister());
  if (is64bit) {
    locations->AddTemp(Location::RequiresFpuRegister());
  }
}

static void CreateIntToFPLocations(ArenaAllocator* allocator, HInvoke* invoke, bool is64bit) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetOut(Location::RequiresFpuRegister());
  if (is64bit) {
    locations->AddTemp(Location::RequiresFpuRegister());
    locations->AddTemp(Location::RequiresFpuRegister());
  }
}

static void MoveFPToInt(LocationSummary* locations, bool is64bit, X86Assembler* assembler) {
  Location input = locations->InAt(0);
  Location output = locations->Out();
  if (is64bit) {
    // Need to use the temporary.
    XmmRegister temp = locations->GetTemp(0).AsFpuRegister<XmmRegister>();
    __ movsd(temp, input.AsFpuRegister<XmmRegister>());
    __ movd(output.AsRegisterPairLow<Register>(), temp);
    __ psrlq(temp, Immediate(32));
    __ movd(output.AsRegisterPairHigh<Register>(), temp);
  } else {
    __ movd(output.AsRegister<Register>(), input.AsFpuRegister<XmmRegister>());
  }
}

static void MoveIntToFP(LocationSummary* locations, bool is64bit, X86Assembler* assembler) {
  Location input = locations->InAt(0);
  Location output = locations->Out();
  if (is64bit) {
    // Need to use the temporary.
    XmmRegister temp1 = locations->GetTemp(0).AsFpuRegister<XmmRegister>();
    XmmRegister temp2 = locations->GetTemp(1).AsFpuRegister<XmmRegister>();
    __ movd(temp1, input.AsRegisterPairLow<Register>());
    __ movd(temp2, input.AsRegisterPairHigh<Register>());
    __ punpckldq(temp1, temp2);
    __ movsd(output.AsFpuRegister<XmmRegister>(), temp1);
  } else {
    __ movd(output.AsFpuRegister<XmmRegister>(), input.AsRegister<Register>());
  }
}

void IntrinsicLocationsBuilderX86::VisitDoubleDoubleToRawLongBits(HInvoke* invoke) {
  CreateFPToIntLocations(allocator_, invoke, /* is64bit= */ true);
}
void IntrinsicLocationsBuilderX86::VisitDoubleLongBitsToDouble(HInvoke* invoke) {
  CreateIntToFPLocations(allocator_, invoke, /* is64bit= */ true);
}

void IntrinsicCodeGeneratorX86::VisitDoubleDoubleToRawLongBits(HInvoke* invoke) {
  MoveFPToInt(invoke->GetLocations(), /* is64bit= */ true, GetAssembler());
}
void IntrinsicCodeGeneratorX86::VisitDoubleLongBitsToDouble(HInvoke* invoke) {
  MoveIntToFP(invoke->GetLocations(), /* is64bit= */ true, GetAssembler());
}

void IntrinsicLocationsBuilderX86::VisitFloatFloatToRawIntBits(HInvoke* invoke) {
  CreateFPToIntLocations(allocator_, invoke, /* is64bit= */ false);
}
void IntrinsicLocationsBuilderX86::VisitFloatIntBitsToFloat(HInvoke* invoke) {
  CreateIntToFPLocations(allocator_, invoke, /* is64bit= */ false);
}

void IntrinsicCodeGeneratorX86::VisitFloatFloatToRawIntBits(HInvoke* invoke) {
  MoveFPToInt(invoke->GetLocations(), /* is64bit= */ false, GetAssembler());
}
void IntrinsicCodeGeneratorX86::VisitFloatIntBitsToFloat(HInvoke* invoke) {
  MoveIntToFP(invoke->GetLocations(), /* is64bit= */ false, GetAssembler());
}

static void CreateIntToIntLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetOut(Location::SameAsFirstInput());
}

static void CreateLongToIntLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetOut(Location::RequiresRegister());
}

static void CreateLongToLongLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetOut(Location::RequiresRegister(), Location::kOutputOverlap);
}

static void GenReverseBytes(LocationSummary* locations,
                            DataType::Type size,
                            X86Assembler* assembler) {
  Register out = locations->Out().AsRegister<Register>();

  switch (size) {
    case DataType::Type::kInt16:
      // TODO: Can be done with an xchg of 8b registers. This is straight from Quick.
      __ bswapl(out);
      __ sarl(out, Immediate(16));
      break;
    case DataType::Type::kInt32:
      __ bswapl(out);
      break;
    default:
      LOG(FATAL) << "Unexpected size for reverse-bytes: " << size;
      UNREACHABLE();
  }
}

void IntrinsicLocationsBuilderX86::VisitIntegerReverseBytes(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitIntegerReverseBytes(HInvoke* invoke) {
  GenReverseBytes(invoke->GetLocations(), DataType::Type::kInt32, GetAssembler());
}

void IntrinsicLocationsBuilderX86::VisitLongReverseBytes(HInvoke* invoke) {
  CreateLongToLongLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitLongReverseBytes(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  Location input = locations->InAt(0);
  Register input_lo = input.AsRegisterPairLow<Register>();
  Register input_hi = input.AsRegisterPairHigh<Register>();
  Location output = locations->Out();
  Register output_lo = output.AsRegisterPairLow<Register>();
  Register output_hi = output.AsRegisterPairHigh<Register>();

  X86Assembler* assembler = GetAssembler();
  // Assign the inputs to the outputs, mixing low/high.
  __ movl(output_lo, input_hi);
  __ movl(output_hi, input_lo);
  __ bswapl(output_lo);
  __ bswapl(output_hi);
}

void IntrinsicLocationsBuilderX86::VisitShortReverseBytes(HInvoke* invoke) {
  CreateIntToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitShortReverseBytes(HInvoke* invoke) {
  GenReverseBytes(invoke->GetLocations(), DataType::Type::kInt16, GetAssembler());
}

static void CreateFPToFPLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresFpuRegister());
  locations->SetOut(Location::RequiresFpuRegister());
}

void IntrinsicLocationsBuilderX86::VisitMathSqrt(HInvoke* invoke) {
  CreateFPToFPLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathSqrt(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  XmmRegister in = locations->InAt(0).AsFpuRegister<XmmRegister>();
  XmmRegister out = locations->Out().AsFpuRegister<XmmRegister>();

  GetAssembler()->sqrtsd(out, in);
}

static void CreateSSE41FPToFPLocations(ArenaAllocator* allocator,
                                       HInvoke* invoke,
                                       CodeGeneratorX86* codegen) {
  // Do we have instruction support?
  if (!codegen->GetInstructionSetFeatures().HasSSE4_1()) {
    return;
  }

  CreateFPToFPLocations(allocator, invoke);
}

static void GenSSE41FPToFPIntrinsic(HInvoke* invoke, X86Assembler* assembler, int round_mode) {
  LocationSummary* locations = invoke->GetLocations();
  DCHECK(!locations->WillCall());
  XmmRegister in = locations->InAt(0).AsFpuRegister<XmmRegister>();
  XmmRegister out = locations->Out().AsFpuRegister<XmmRegister>();
  __ roundsd(out, in, Immediate(round_mode));
}

void IntrinsicLocationsBuilderX86::VisitMathCeil(HInvoke* invoke) {
  CreateSSE41FPToFPLocations(allocator_, invoke, codegen_);
}

void IntrinsicCodeGeneratorX86::VisitMathCeil(HInvoke* invoke) {
  GenSSE41FPToFPIntrinsic(invoke, GetAssembler(), 2);
}

void IntrinsicLocationsBuilderX86::VisitMathFloor(HInvoke* invoke) {
  CreateSSE41FPToFPLocations(allocator_, invoke, codegen_);
}

void IntrinsicCodeGeneratorX86::VisitMathFloor(HInvoke* invoke) {
  GenSSE41FPToFPIntrinsic(invoke, GetAssembler(), 1);
}

void IntrinsicLocationsBuilderX86::VisitMathRint(HInvoke* invoke) {
  CreateSSE41FPToFPLocations(allocator_, invoke, codegen_);
}

void IntrinsicCodeGeneratorX86::VisitMathRint(HInvoke* invoke) {
  GenSSE41FPToFPIntrinsic(invoke, GetAssembler(), 0);
}

void IntrinsicLocationsBuilderX86::VisitMathRoundFloat(HInvoke* invoke) {
  // Do we have instruction support?
  if (!codegen_->GetInstructionSetFeatures().HasSSE4_1()) {
    return;
  }

  HInvokeStaticOrDirect* static_or_direct = invoke->AsInvokeStaticOrDirect();
  DCHECK(static_or_direct != nullptr);
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresFpuRegister());
  if (static_or_direct->HasSpecialInput() &&
      invoke->InputAt(
          static_or_direct->GetSpecialInputIndex())->IsX86ComputeBaseMethodAddress()) {
    locations->SetInAt(1, Location::RequiresRegister());
  }
  locations->SetOut(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresFpuRegister());
  locations->AddTemp(Location::RequiresFpuRegister());
}

void IntrinsicCodeGeneratorX86::VisitMathRoundFloat(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  DCHECK(!locations->WillCall());

  XmmRegister in = locations->InAt(0).AsFpuRegister<XmmRegister>();
  XmmRegister t1 = locations->GetTemp(0).AsFpuRegister<XmmRegister>();
  XmmRegister t2 = locations->GetTemp(1).AsFpuRegister<XmmRegister>();
  Register out = locations->Out().AsRegister<Register>();
  NearLabel skip_incr, done;
  X86Assembler* assembler = GetAssembler();

  // Since no direct x86 rounding instruction matches the required semantics,
  // this intrinsic is implemented as follows:
  //  result = floor(in);
  //  if (in - result >= 0.5f)
  //    result = result + 1.0f;
  __ movss(t2, in);
  __ roundss(t1, in, Immediate(1));
  __ subss(t2, t1);
  if (locations->GetInputCount() == 2 && locations->InAt(1).IsValid()) {
    // Direct constant area available.
    HX86ComputeBaseMethodAddress* method_address =
        invoke->InputAt(1)->AsX86ComputeBaseMethodAddress();
    Register constant_area = locations->InAt(1).AsRegister<Register>();
    __ comiss(t2, codegen_->LiteralInt32Address(bit_cast<int32_t, float>(0.5f),
                                                method_address,
                                                constant_area));
    __ j(kBelow, &skip_incr);
    __ addss(t1, codegen_->LiteralInt32Address(bit_cast<int32_t, float>(1.0f),
                                               method_address,
                                               constant_area));
    __ Bind(&skip_incr);
  } else {
    // No constant area: go through stack.
    __ pushl(Immediate(bit_cast<int32_t, float>(0.5f)));
    __ pushl(Immediate(bit_cast<int32_t, float>(1.0f)));
    __ comiss(t2, Address(ESP, 4));
    __ j(kBelow, &skip_incr);
    __ addss(t1, Address(ESP, 0));
    __ Bind(&skip_incr);
    __ addl(ESP, Immediate(8));
  }

  // Final conversion to an integer. Unfortunately this also does not have a
  // direct x86 instruction, since NaN should map to 0 and large positive
  // values need to be clipped to the extreme value.
  __ movl(out, Immediate(kPrimIntMax));
  __ cvtsi2ss(t2, out);
  __ comiss(t1, t2);
  __ j(kAboveEqual, &done);  // clipped to max (already in out), does not jump on unordered
  __ movl(out, Immediate(0));  // does not change flags
  __ j(kUnordered, &done);  // NaN mapped to 0 (just moved in out)
  __ cvttss2si(out, t1);
  __ Bind(&done);
}

static void CreateFPToFPCallLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kCallOnMainOnly, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, Location::FpuRegisterLocation(calling_convention.GetFpuRegisterAt(0)));
  locations->SetOut(Location::FpuRegisterLocation(XMM0));
}

static void GenFPToFPCall(HInvoke* invoke, CodeGeneratorX86* codegen, QuickEntrypointEnum entry) {
  LocationSummary* locations = invoke->GetLocations();
  DCHECK(locations->WillCall());
  DCHECK(invoke->IsInvokeStaticOrDirect());
  X86Assembler* assembler = codegen->GetAssembler();

  // We need some place to pass the parameters.
  __ subl(ESP, Immediate(16));
  __ cfi().AdjustCFAOffset(16);

  // Pass the parameters at the bottom of the stack.
  __ movsd(Address(ESP, 0), XMM0);

  // If we have a second parameter, pass it next.
  if (invoke->GetNumberOfArguments() == 2) {
    __ movsd(Address(ESP, 8), XMM1);
  }

  // Now do the actual call.
  codegen->InvokeRuntime(entry, invoke, invoke->GetDexPc());

  // Extract the return value from the FP stack.
  __ fstpl(Address(ESP, 0));
  __ movsd(XMM0, Address(ESP, 0));

  // And clean up the stack.
  __ addl(ESP, Immediate(16));
  __ cfi().AdjustCFAOffset(-16);
}

static void CreateLowestOneBitLocations(ArenaAllocator* allocator, bool is_long, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  if (is_long) {
    locations->SetInAt(0, Location::RequiresRegister());
  } else {
    locations->SetInAt(0, Location::Any());
  }
  locations->SetOut(Location::RequiresRegister(), Location::kOutputOverlap);
}

static void GenLowestOneBit(X86Assembler* assembler,
                      CodeGeneratorX86* codegen,
                      bool is_long,
                      HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  Location src = locations->InAt(0);
  Location out_loc = locations->Out();

  if (invoke->InputAt(0)->IsConstant()) {
    // Evaluate this at compile time.
    int64_t value = Int64FromConstant(invoke->InputAt(0)->AsConstant());
    if (value == 0) {
      if (is_long) {
        __ xorl(out_loc.AsRegisterPairLow<Register>(), out_loc.AsRegisterPairLow<Register>());
        __ xorl(out_loc.AsRegisterPairHigh<Register>(), out_loc.AsRegisterPairHigh<Register>());
      } else {
        __ xorl(out_loc.AsRegister<Register>(), out_loc.AsRegister<Register>());
      }
      return;
    }
    // Nonzero value.
    value = is_long ? CTZ(static_cast<uint64_t>(value))
                    : CTZ(static_cast<uint32_t>(value));
    if (is_long) {
      if (value >= 32) {
        int shift = value-32;
        codegen->Load32BitValue(out_loc.AsRegisterPairLow<Register>(), 0);
        codegen->Load32BitValue(out_loc.AsRegisterPairHigh<Register>(), 1 << shift);
      } else {
        codegen->Load32BitValue(out_loc.AsRegisterPairLow<Register>(), 1 << value);
        codegen->Load32BitValue(out_loc.AsRegisterPairHigh<Register>(), 0);
      }
    } else {
      codegen->Load32BitValue(out_loc.AsRegister<Register>(), 1 << value);
    }
    return;
  }
  // Handle non constant case
  if (is_long) {
    DCHECK(src.IsRegisterPair());
    Register src_lo = src.AsRegisterPairLow<Register>();
    Register src_hi = src.AsRegisterPairHigh<Register>();

    Register out_lo = out_loc.AsRegisterPairLow<Register>();
    Register out_hi = out_loc.AsRegisterPairHigh<Register>();

    __ movl(out_lo, src_lo);
    __ movl(out_hi, src_hi);

    __ negl(out_lo);
    __ adcl(out_hi, Immediate(0));
    __ negl(out_hi);

    __ andl(out_lo, src_lo);
    __ andl(out_hi, src_hi);
  } else {
    if (codegen->GetInstructionSetFeatures().HasAVX2() && src.IsRegister()) {
      Register out = out_loc.AsRegister<Register>();
      __ blsi(out, src.AsRegister<Register>());
    } else {
      Register out = out_loc.AsRegister<Register>();
      // Do tmp & -tmp
      if (src.IsRegister()) {
        __ movl(out, src.AsRegister<Register>());
      } else {
        DCHECK(src.IsStackSlot());
        __ movl(out, Address(ESP, src.GetStackIndex()));
      }
      __ negl(out);

      if (src.IsRegister()) {
        __ andl(out, src.AsRegister<Register>());
      } else {
        __ andl(out, Address(ESP, src.GetStackIndex()));
      }
    }
  }
}

void IntrinsicLocationsBuilderX86::VisitMathCos(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathCos(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickCos);
}

void IntrinsicLocationsBuilderX86::VisitMathSin(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathSin(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickSin);
}

void IntrinsicLocationsBuilderX86::VisitMathAcos(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathAcos(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickAcos);
}

void IntrinsicLocationsBuilderX86::VisitMathAsin(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathAsin(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickAsin);
}

void IntrinsicLocationsBuilderX86::VisitMathAtan(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathAtan(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickAtan);
}

void IntrinsicLocationsBuilderX86::VisitMathCbrt(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathCbrt(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickCbrt);
}

void IntrinsicLocationsBuilderX86::VisitMathCosh(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathCosh(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickCosh);
}

void IntrinsicLocationsBuilderX86::VisitMathExp(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathExp(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickExp);
}

void IntrinsicLocationsBuilderX86::VisitMathExpm1(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathExpm1(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickExpm1);
}

void IntrinsicLocationsBuilderX86::VisitMathLog(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathLog(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickLog);
}

void IntrinsicLocationsBuilderX86::VisitMathLog10(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathLog10(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickLog10);
}

void IntrinsicLocationsBuilderX86::VisitMathSinh(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathSinh(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickSinh);
}

void IntrinsicLocationsBuilderX86::VisitMathTan(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathTan(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickTan);
}

void IntrinsicLocationsBuilderX86::VisitMathTanh(HInvoke* invoke) {
  CreateFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathTanh(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickTanh);
}

void IntrinsicLocationsBuilderX86::VisitIntegerLowestOneBit(HInvoke* invoke) {
  CreateLowestOneBitLocations(allocator_, /*is_long=*/ false, invoke);
}
void IntrinsicCodeGeneratorX86::VisitIntegerLowestOneBit(HInvoke* invoke) {
  GenLowestOneBit(GetAssembler(), codegen_, /*is_long=*/ false, invoke);
}

void IntrinsicLocationsBuilderX86::VisitLongLowestOneBit(HInvoke* invoke) {
  CreateLowestOneBitLocations(allocator_, /*is_long=*/ true, invoke);
}

void IntrinsicCodeGeneratorX86::VisitLongLowestOneBit(HInvoke* invoke) {
  GenLowestOneBit(GetAssembler(), codegen_, /*is_long=*/ true, invoke);
}

static void CreateFPFPToFPCallLocations(ArenaAllocator* allocator, HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kCallOnMainOnly, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, Location::FpuRegisterLocation(calling_convention.GetFpuRegisterAt(0)));
  locations->SetInAt(1, Location::FpuRegisterLocation(calling_convention.GetFpuRegisterAt(1)));
  locations->SetOut(Location::FpuRegisterLocation(XMM0));
}

void IntrinsicLocationsBuilderX86::VisitMathAtan2(HInvoke* invoke) {
  CreateFPFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathAtan2(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickAtan2);
}

void IntrinsicLocationsBuilderX86::VisitMathPow(HInvoke* invoke) {
  CreateFPFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathPow(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickPow);
}

void IntrinsicLocationsBuilderX86::VisitMathHypot(HInvoke* invoke) {
  CreateFPFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathHypot(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickHypot);
}

void IntrinsicLocationsBuilderX86::VisitMathNextAfter(HInvoke* invoke) {
  CreateFPFPToFPCallLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMathNextAfter(HInvoke* invoke) {
  GenFPToFPCall(invoke, codegen_, kQuickNextAfter);
}

void IntrinsicLocationsBuilderX86::VisitSystemArrayCopyChar(HInvoke* invoke) {
  // We need at least two of the positions or length to be an integer constant,
  // or else we won't have enough free registers.
  HIntConstant* src_pos = invoke->InputAt(1)->AsIntConstant();
  HIntConstant* dest_pos = invoke->InputAt(3)->AsIntConstant();
  HIntConstant* length = invoke->InputAt(4)->AsIntConstant();

  int num_constants =
      ((src_pos != nullptr) ? 1 : 0)
      + ((dest_pos != nullptr) ? 1 : 0)
      + ((length != nullptr) ? 1 : 0);

  if (num_constants < 2) {
    // Not enough free registers.
    return;
  }

  // As long as we are checking, we might as well check to see if the src and dest
  // positions are >= 0.
  if ((src_pos != nullptr && src_pos->GetValue() < 0) ||
      (dest_pos != nullptr && dest_pos->GetValue() < 0)) {
    // We will have to fail anyways.
    return;
  }

  // And since we are already checking, check the length too.
  if (length != nullptr) {
    int32_t len = length->GetValue();
    if (len < 0) {
      // Just call as normal.
      return;
    }
  }

  // Okay, it is safe to generate inline code.
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  // arraycopy(Object src, int srcPos, Object dest, int destPos, int length).
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RegisterOrConstant(invoke->InputAt(1)));
  locations->SetInAt(2, Location::RequiresRegister());
  locations->SetInAt(3, Location::RegisterOrConstant(invoke->InputAt(3)));
  locations->SetInAt(4, Location::RegisterOrConstant(invoke->InputAt(4)));

  // And we need some temporaries.  We will use REP MOVSW, so we need fixed registers.
  locations->AddTemp(Location::RegisterLocation(ESI));
  locations->AddTemp(Location::RegisterLocation(EDI));
  locations->AddTemp(Location::RegisterLocation(ECX));
}

static void CheckPosition(X86Assembler* assembler,
                          Location pos,
                          Register input,
                          Location length,
                          SlowPathCode* slow_path,
                          Register temp,
                          bool length_is_input_length = false) {
  // Where is the length in the Array?
  const uint32_t length_offset = mirror::Array::LengthOffset().Uint32Value();

  if (pos.IsConstant()) {
    int32_t pos_const = pos.GetConstant()->AsIntConstant()->GetValue();
    if (pos_const == 0) {
      if (!length_is_input_length) {
        // Check that length(input) >= length.
        if (length.IsConstant()) {
          __ cmpl(Address(input, length_offset),
                  Immediate(length.GetConstant()->AsIntConstant()->GetValue()));
        } else {
          __ cmpl(Address(input, length_offset), length.AsRegister<Register>());
        }
        __ j(kLess, slow_path->GetEntryLabel());
      }
    } else {
      // Check that length(input) >= pos.
      __ movl(temp, Address(input, length_offset));
      __ subl(temp, Immediate(pos_const));
      __ j(kLess, slow_path->GetEntryLabel());

      // Check that (length(input) - pos) >= length.
      if (length.IsConstant()) {
        __ cmpl(temp, Immediate(length.GetConstant()->AsIntConstant()->GetValue()));
      } else {
        __ cmpl(temp, length.AsRegister<Register>());
      }
      __ j(kLess, slow_path->GetEntryLabel());
    }
  } else if (length_is_input_length) {
    // The only way the copy can succeed is if pos is zero.
    Register pos_reg = pos.AsRegister<Register>();
    __ testl(pos_reg, pos_reg);
    __ j(kNotEqual, slow_path->GetEntryLabel());
  } else {
    // Check that pos >= 0.
    Register pos_reg = pos.AsRegister<Register>();
    __ testl(pos_reg, pos_reg);
    __ j(kLess, slow_path->GetEntryLabel());

    // Check that pos <= length(input).
    __ cmpl(Address(input, length_offset), pos_reg);
    __ j(kLess, slow_path->GetEntryLabel());

    // Check that (length(input) - pos) >= length.
    __ movl(temp, Address(input, length_offset));
    __ subl(temp, pos_reg);
    if (length.IsConstant()) {
      __ cmpl(temp, Immediate(length.GetConstant()->AsIntConstant()->GetValue()));
    } else {
      __ cmpl(temp, length.AsRegister<Register>());
    }
    __ j(kLess, slow_path->GetEntryLabel());
  }
}

void IntrinsicCodeGeneratorX86::VisitSystemArrayCopyChar(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register src = locations->InAt(0).AsRegister<Register>();
  Location srcPos = locations->InAt(1);
  Register dest = locations->InAt(2).AsRegister<Register>();
  Location destPos = locations->InAt(3);
  Location length = locations->InAt(4);

  // Temporaries that we need for MOVSW.
  Register src_base = locations->GetTemp(0).AsRegister<Register>();
  DCHECK_EQ(src_base, ESI);
  Register dest_base = locations->GetTemp(1).AsRegister<Register>();
  DCHECK_EQ(dest_base, EDI);
  Register count = locations->GetTemp(2).AsRegister<Register>();
  DCHECK_EQ(count, ECX);

  SlowPathCode* slow_path = new (codegen_->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen_->AddSlowPath(slow_path);

  // Bail out if the source and destination are the same (to handle overlap).
  __ cmpl(src, dest);
  __ j(kEqual, slow_path->GetEntryLabel());

  // Bail out if the source is null.
  __ testl(src, src);
  __ j(kEqual, slow_path->GetEntryLabel());

  // Bail out if the destination is null.
  __ testl(dest, dest);
  __ j(kEqual, slow_path->GetEntryLabel());

  // If the length is negative, bail out.
  // We have already checked in the LocationsBuilder for the constant case.
  if (!length.IsConstant()) {
    __ cmpl(length.AsRegister<Register>(), length.AsRegister<Register>());
    __ j(kLess, slow_path->GetEntryLabel());
  }

  // We need the count in ECX.
  if (length.IsConstant()) {
    __ movl(count, Immediate(length.GetConstant()->AsIntConstant()->GetValue()));
  } else {
    __ movl(count, length.AsRegister<Register>());
  }

  // Validity checks: source. Use src_base as a temporary register.
  CheckPosition(assembler, srcPos, src, Location::RegisterLocation(count), slow_path, src_base);

  // Validity checks: dest. Use src_base as a temporary register.
  CheckPosition(assembler, destPos, dest, Location::RegisterLocation(count), slow_path, src_base);

  // Okay, everything checks out.  Finally time to do the copy.
  // Check assumption that sizeof(Char) is 2 (used in scaling below).
  const size_t char_size = DataType::Size(DataType::Type::kUint16);
  DCHECK_EQ(char_size, 2u);

  const uint32_t data_offset = mirror::Array::DataOffset(char_size).Uint32Value();

  if (srcPos.IsConstant()) {
    int32_t srcPos_const = srcPos.GetConstant()->AsIntConstant()->GetValue();
    __ leal(src_base, Address(src, char_size * srcPos_const + data_offset));
  } else {
    __ leal(src_base, Address(src, srcPos.AsRegister<Register>(),
                              ScaleFactor::TIMES_2, data_offset));
  }
  if (destPos.IsConstant()) {
    int32_t destPos_const = destPos.GetConstant()->AsIntConstant()->GetValue();

    __ leal(dest_base, Address(dest, char_size * destPos_const + data_offset));
  } else {
    __ leal(dest_base, Address(dest, destPos.AsRegister<Register>(),
                               ScaleFactor::TIMES_2, data_offset));
  }

  // Do the move.
  __ rep_movsw();

  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitStringCompareTo(HInvoke* invoke) {
  // The inputs plus one temp.
  LocationSummary* locations = new (allocator_) LocationSummary(
      invoke, LocationSummary::kCallOnMainAndSlowPath, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, Location::RegisterLocation(calling_convention.GetRegisterAt(0)));
  locations->SetInAt(1, Location::RegisterLocation(calling_convention.GetRegisterAt(1)));
  locations->SetOut(Location::RegisterLocation(EAX));
}

void IntrinsicCodeGeneratorX86::VisitStringCompareTo(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  // Note that the null check must have been done earlier.
  DCHECK(!invoke->CanDoImplicitNullCheckOn(invoke->InputAt(0)));

  Register argument = locations->InAt(1).AsRegister<Register>();
  __ testl(argument, argument);
  SlowPathCode* slow_path = new (codegen_->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen_->AddSlowPath(slow_path);
  __ j(kEqual, slow_path->GetEntryLabel());

  codegen_->InvokeRuntime(kQuickStringCompareTo, invoke, invoke->GetDexPc(), slow_path);
  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitStringEquals(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RequiresRegister());

  // Request temporary registers, ECX and EDI needed for repe_cmpsl instruction.
  locations->AddTemp(Location::RegisterLocation(ECX));
  locations->AddTemp(Location::RegisterLocation(EDI));

  // Set output, ESI needed for repe_cmpsl instruction anyways.
  locations->SetOut(Location::RegisterLocation(ESI), Location::kOutputOverlap);
}

void IntrinsicCodeGeneratorX86::VisitStringEquals(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register str = locations->InAt(0).AsRegister<Register>();
  Register arg = locations->InAt(1).AsRegister<Register>();
  Register ecx = locations->GetTemp(0).AsRegister<Register>();
  Register edi = locations->GetTemp(1).AsRegister<Register>();
  Register esi = locations->Out().AsRegister<Register>();

  NearLabel end, return_true, return_false;

  // Get offsets of count, value, and class fields within a string object.
  const uint32_t count_offset = mirror::String::CountOffset().Uint32Value();
  const uint32_t value_offset = mirror::String::ValueOffset().Uint32Value();
  const uint32_t class_offset = mirror::Object::ClassOffset().Uint32Value();

  // Note that the null check must have been done earlier.
  DCHECK(!invoke->CanDoImplicitNullCheckOn(invoke->InputAt(0)));

  StringEqualsOptimizations optimizations(invoke);
  if (!optimizations.GetArgumentNotNull()) {
    // Check if input is null, return false if it is.
    __ testl(arg, arg);
    __ j(kEqual, &return_false);
  }

  if (!optimizations.GetArgumentIsString()) {
    // Instanceof check for the argument by comparing class fields.
    // All string objects must have the same type since String cannot be subclassed.
    // Receiver must be a string object, so its class field is equal to all strings' class fields.
    // If the argument is a string object, its class field must be equal to receiver's class field.
    //
    // As the String class is expected to be non-movable, we can read the class
    // field from String.equals' arguments without read barriers.
    AssertNonMovableStringClass();
    // Also, because we use the loaded class references only to compare them, we
    // don't need to unpoison them.
    // /* HeapReference<Class> */ ecx = str->klass_
    __ movl(ecx, Address(str, class_offset));
    // if (ecx != /* HeapReference<Class> */ arg->klass_) return false
    __ cmpl(ecx, Address(arg, class_offset));
    __ j(kNotEqual, &return_false);
  }

  // Reference equality check, return true if same reference.
  __ cmpl(str, arg);
  __ j(kEqual, &return_true);

  // Load length and compression flag of receiver string.
  __ movl(ecx, Address(str, count_offset));
  // Check if lengths and compression flags are equal, return false if they're not.
  // Two identical strings will always have same compression style since
  // compression style is decided on alloc.
  __ cmpl(ecx, Address(arg, count_offset));
  __ j(kNotEqual, &return_false);
  // Return true if strings are empty. Even with string compression `count == 0` means empty.
  static_assert(static_cast<uint32_t>(mirror::StringCompressionFlag::kCompressed) == 0u,
                "Expecting 0=compressed, 1=uncompressed");
  __ jecxz(&return_true);

  if (mirror::kUseStringCompression) {
    NearLabel string_uncompressed;
    // Extract length and differentiate between both compressed or both uncompressed.
    // Different compression style is cut above.
    __ shrl(ecx, Immediate(1));
    __ j(kCarrySet, &string_uncompressed);
    // Divide string length by 2, rounding up, and continue as if uncompressed.
    __ addl(ecx, Immediate(1));
    __ shrl(ecx, Immediate(1));
    __ Bind(&string_uncompressed);
  }
  // Load starting addresses of string values into ESI/EDI as required for repe_cmpsl instruction.
  __ leal(esi, Address(str, value_offset));
  __ leal(edi, Address(arg, value_offset));

  // Divide string length by 2 to compare characters 2 at a time and adjust for lengths not
  // divisible by 2.
  __ addl(ecx, Immediate(1));
  __ shrl(ecx, Immediate(1));

  // Assertions that must hold in order to compare strings 2 characters (uncompressed)
  // or 4 characters (compressed) at a time.
  DCHECK_ALIGNED(value_offset, 4);
  static_assert(IsAligned<4>(kObjectAlignment), "String of odd length is not zero padded");

  // Loop to compare strings two characters at a time starting at the beginning of the string.
  __ repe_cmpsl();
  // If strings are not equal, zero flag will be cleared.
  __ j(kNotEqual, &return_false);

  // Return true and exit the function.
  // If loop does not result in returning false, we return true.
  __ Bind(&return_true);
  __ movl(esi, Immediate(1));
  __ jmp(&end);

  // Return false and exit the function.
  __ Bind(&return_false);
  __ xorl(esi, esi);
  __ Bind(&end);
}

static void CreateStringIndexOfLocations(HInvoke* invoke,
                                         ArenaAllocator* allocator,
                                         bool start_at_zero) {
  LocationSummary* locations = new (allocator) LocationSummary(invoke,
                                                               LocationSummary::kCallOnSlowPath,
                                                               kIntrinsified);
  // The data needs to be in EDI for scasw. So request that the string is there, anyways.
  locations->SetInAt(0, Location::RegisterLocation(EDI));
  // If we look for a constant char, we'll still have to copy it into EAX. So just request the
  // allocator to do that, anyways. We can still do the constant check by checking the parameter
  // of the instruction explicitly.
  // Note: This works as we don't clobber EAX anywhere.
  locations->SetInAt(1, Location::RegisterLocation(EAX));
  if (!start_at_zero) {
    locations->SetInAt(2, Location::RequiresRegister());          // The starting index.
  }
  // As we clobber EDI during execution anyways, also use it as the output.
  locations->SetOut(Location::SameAsFirstInput());

  // repne scasw uses ECX as the counter.
  locations->AddTemp(Location::RegisterLocation(ECX));
  // Need another temporary to be able to compute the result.
  locations->AddTemp(Location::RequiresRegister());
  if (mirror::kUseStringCompression) {
    // Need another temporary to be able to save unflagged string length.
    locations->AddTemp(Location::RequiresRegister());
  }
}

static void GenerateStringIndexOf(HInvoke* invoke,
                                  X86Assembler* assembler,
                                  CodeGeneratorX86* codegen,
                                  bool start_at_zero) {
  LocationSummary* locations = invoke->GetLocations();

  // Note that the null check must have been done earlier.
  DCHECK(!invoke->CanDoImplicitNullCheckOn(invoke->InputAt(0)));

  Register string_obj = locations->InAt(0).AsRegister<Register>();
  Register search_value = locations->InAt(1).AsRegister<Register>();
  Register counter = locations->GetTemp(0).AsRegister<Register>();
  Register string_length = locations->GetTemp(1).AsRegister<Register>();
  Register out = locations->Out().AsRegister<Register>();
  // Only used when string compression feature is on.
  Register string_length_flagged;

  // Check our assumptions for registers.
  DCHECK_EQ(string_obj, EDI);
  DCHECK_EQ(search_value, EAX);
  DCHECK_EQ(counter, ECX);
  DCHECK_EQ(out, EDI);

  // Check for code points > 0xFFFF. Either a slow-path check when we don't know statically,
  // or directly dispatch for a large constant, or omit slow-path for a small constant or a char.
  SlowPathCode* slow_path = nullptr;
  HInstruction* code_point = invoke->InputAt(1);
  if (code_point->IsIntConstant()) {
    if (static_cast<uint32_t>(code_point->AsIntConstant()->GetValue()) >
    std::numeric_limits<uint16_t>::max()) {
      // Always needs the slow-path. We could directly dispatch to it, but this case should be
      // rare, so for simplicity just put the full slow-path down and branch unconditionally.
      slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
      codegen->AddSlowPath(slow_path);
      __ jmp(slow_path->GetEntryLabel());
      __ Bind(slow_path->GetExitLabel());
      return;
    }
  } else if (code_point->GetType() != DataType::Type::kUint16) {
    __ cmpl(search_value, Immediate(std::numeric_limits<uint16_t>::max()));
    slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
    codegen->AddSlowPath(slow_path);
    __ j(kAbove, slow_path->GetEntryLabel());
  }

  // From here down, we know that we are looking for a char that fits in 16 bits.
  // Location of reference to data array within the String object.
  int32_t value_offset = mirror::String::ValueOffset().Int32Value();
  // Location of count within the String object.
  int32_t count_offset = mirror::String::CountOffset().Int32Value();

  // Load the count field of the string containing the length and compression flag.
  __ movl(string_length, Address(string_obj, count_offset));

  // Do a zero-length check. Even with string compression `count == 0` means empty.
  static_assert(static_cast<uint32_t>(mirror::StringCompressionFlag::kCompressed) == 0u,
                "Expecting 0=compressed, 1=uncompressed");
  // TODO: Support jecxz.
  NearLabel not_found_label;
  __ testl(string_length, string_length);
  __ j(kEqual, &not_found_label);

  if (mirror::kUseStringCompression) {
    string_length_flagged = locations->GetTemp(2).AsRegister<Register>();
    __ movl(string_length_flagged, string_length);
    // Extract the length and shift out the least significant bit used as compression flag.
    __ shrl(string_length, Immediate(1));
  }

  if (start_at_zero) {
    // Number of chars to scan is the same as the string length.
    __ movl(counter, string_length);

    // Move to the start of the string.
    __ addl(string_obj, Immediate(value_offset));
  } else {
    Register start_index = locations->InAt(2).AsRegister<Register>();

    // Do a start_index check.
    __ cmpl(start_index, string_length);
    __ j(kGreaterEqual, &not_found_label);

    // Ensure we have a start index >= 0;
    __ xorl(counter, counter);
    __ cmpl(start_index, Immediate(0));
    __ cmovl(kGreater, counter, start_index);

    if (mirror::kUseStringCompression) {
      NearLabel modify_counter, offset_uncompressed_label;
      __ testl(string_length_flagged, Immediate(1));
      __ j(kNotZero, &offset_uncompressed_label);
      // Move to the start of the string: string_obj + value_offset + start_index.
      __ leal(string_obj, Address(string_obj, counter, ScaleFactor::TIMES_1, value_offset));
      __ jmp(&modify_counter);

      // Move to the start of the string: string_obj + value_offset + 2 * start_index.
      __ Bind(&offset_uncompressed_label);
      __ leal(string_obj, Address(string_obj, counter, ScaleFactor::TIMES_2, value_offset));

      // Now update ecx (the repne scasw work counter). We have string.length - start_index left to
      // compare.
      __ Bind(&modify_counter);
    } else {
      __ leal(string_obj, Address(string_obj, counter, ScaleFactor::TIMES_2, value_offset));
    }
    __ negl(counter);
    __ leal(counter, Address(string_length, counter, ScaleFactor::TIMES_1, 0));
  }

  if (mirror::kUseStringCompression) {
    NearLabel uncompressed_string_comparison;
    NearLabel comparison_done;
    __ testl(string_length_flagged, Immediate(1));
    __ j(kNotZero, &uncompressed_string_comparison);

    // Check if EAX (search_value) is ASCII.
    __ cmpl(search_value, Immediate(127));
    __ j(kGreater, &not_found_label);
    // Comparing byte-per-byte.
    __ repne_scasb();
    __ jmp(&comparison_done);

    // Everything is set up for repne scasw:
    //   * Comparison address in EDI.
    //   * Counter in ECX.
    __ Bind(&uncompressed_string_comparison);
    __ repne_scasw();
    __ Bind(&comparison_done);
  } else {
    __ repne_scasw();
  }
  // Did we find a match?
  __ j(kNotEqual, &not_found_label);

  // Yes, we matched.  Compute the index of the result.
  __ subl(string_length, counter);
  __ leal(out, Address(string_length, -1));

  NearLabel done;
  __ jmp(&done);

  // Failed to match; return -1.
  __ Bind(&not_found_label);
  __ movl(out, Immediate(-1));

  // And join up at the end.
  __ Bind(&done);
  if (slow_path != nullptr) {
    __ Bind(slow_path->GetExitLabel());
  }
}

void IntrinsicLocationsBuilderX86::VisitStringIndexOf(HInvoke* invoke) {
  CreateStringIndexOfLocations(invoke, allocator_, /* start_at_zero= */ true);
}

void IntrinsicCodeGeneratorX86::VisitStringIndexOf(HInvoke* invoke) {
  GenerateStringIndexOf(invoke, GetAssembler(), codegen_, /* start_at_zero= */ true);
}

void IntrinsicLocationsBuilderX86::VisitStringIndexOfAfter(HInvoke* invoke) {
  CreateStringIndexOfLocations(invoke, allocator_, /* start_at_zero= */ false);
}

void IntrinsicCodeGeneratorX86::VisitStringIndexOfAfter(HInvoke* invoke) {
  GenerateStringIndexOf(invoke, GetAssembler(), codegen_, /* start_at_zero= */ false);
}

void IntrinsicLocationsBuilderX86::VisitStringNewStringFromBytes(HInvoke* invoke) {
  LocationSummary* locations = new (allocator_) LocationSummary(
      invoke, LocationSummary::kCallOnMainAndSlowPath, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, Location::RegisterLocation(calling_convention.GetRegisterAt(0)));
  locations->SetInAt(1, Location::RegisterLocation(calling_convention.GetRegisterAt(1)));
  locations->SetInAt(2, Location::RegisterLocation(calling_convention.GetRegisterAt(2)));
  locations->SetInAt(3, Location::RegisterLocation(calling_convention.GetRegisterAt(3)));
  locations->SetOut(Location::RegisterLocation(EAX));
}

void IntrinsicCodeGeneratorX86::VisitStringNewStringFromBytes(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register byte_array = locations->InAt(0).AsRegister<Register>();
  __ testl(byte_array, byte_array);
  SlowPathCode* slow_path = new (codegen_->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen_->AddSlowPath(slow_path);
  __ j(kEqual, slow_path->GetEntryLabel());

  codegen_->InvokeRuntime(kQuickAllocStringFromBytes, invoke, invoke->GetDexPc());
  CheckEntrypointTypes<kQuickAllocStringFromBytes, void*, void*, int32_t, int32_t, int32_t>();
  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitStringNewStringFromChars(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kCallOnMainOnly, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, Location::RegisterLocation(calling_convention.GetRegisterAt(0)));
  locations->SetInAt(1, Location::RegisterLocation(calling_convention.GetRegisterAt(1)));
  locations->SetInAt(2, Location::RegisterLocation(calling_convention.GetRegisterAt(2)));
  locations->SetOut(Location::RegisterLocation(EAX));
}

void IntrinsicCodeGeneratorX86::VisitStringNewStringFromChars(HInvoke* invoke) {
  // No need to emit code checking whether `locations->InAt(2)` is a null
  // pointer, as callers of the native method
  //
  //   java.lang.StringFactory.newStringFromChars(int offset, int charCount, char[] data)
  //
  // all include a null check on `data` before calling that method.
  codegen_->InvokeRuntime(kQuickAllocStringFromChars, invoke, invoke->GetDexPc());
  CheckEntrypointTypes<kQuickAllocStringFromChars, void*, int32_t, int32_t, void*>();
}

void IntrinsicLocationsBuilderX86::VisitStringNewStringFromString(HInvoke* invoke) {
  LocationSummary* locations = new (allocator_) LocationSummary(
      invoke, LocationSummary::kCallOnMainAndSlowPath, kIntrinsified);
  InvokeRuntimeCallingConvention calling_convention;
  locations->SetInAt(0, Location::RegisterLocation(calling_convention.GetRegisterAt(0)));
  locations->SetOut(Location::RegisterLocation(EAX));
}

void IntrinsicCodeGeneratorX86::VisitStringNewStringFromString(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register string_to_copy = locations->InAt(0).AsRegister<Register>();
  __ testl(string_to_copy, string_to_copy);
  SlowPathCode* slow_path = new (codegen_->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen_->AddSlowPath(slow_path);
  __ j(kEqual, slow_path->GetEntryLabel());

  codegen_->InvokeRuntime(kQuickAllocStringFromString, invoke, invoke->GetDexPc());
  CheckEntrypointTypes<kQuickAllocStringFromString, void*, void*>();
  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitStringGetCharsNoCheck(HInvoke* invoke) {
  // public void getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin);
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetInAt(1, Location::RegisterOrConstant(invoke->InputAt(1)));
  // Place srcEnd in ECX to save a move below.
  locations->SetInAt(2, Location::RegisterLocation(ECX));
  locations->SetInAt(3, Location::RequiresRegister());
  locations->SetInAt(4, Location::RequiresRegister());

  // And we need some temporaries.  We will use REP MOVSW, so we need fixed registers.
  // We don't have enough registers to also grab ECX, so handle below.
  locations->AddTemp(Location::RegisterLocation(ESI));
  locations->AddTemp(Location::RegisterLocation(EDI));
}

void IntrinsicCodeGeneratorX86::VisitStringGetCharsNoCheck(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  size_t char_component_size = DataType::Size(DataType::Type::kUint16);
  // Location of data in char array buffer.
  const uint32_t data_offset = mirror::Array::DataOffset(char_component_size).Uint32Value();
  // Location of char array data in string.
  const uint32_t value_offset = mirror::String::ValueOffset().Uint32Value();

  // public void getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin);
  Register obj = locations->InAt(0).AsRegister<Register>();
  Location srcBegin = locations->InAt(1);
  int srcBegin_value =
    srcBegin.IsConstant() ? srcBegin.GetConstant()->AsIntConstant()->GetValue() : 0;
  Register srcEnd = locations->InAt(2).AsRegister<Register>();
  Register dst = locations->InAt(3).AsRegister<Register>();
  Register dstBegin = locations->InAt(4).AsRegister<Register>();

  // Check assumption that sizeof(Char) is 2 (used in scaling below).
  const size_t char_size = DataType::Size(DataType::Type::kUint16);
  DCHECK_EQ(char_size, 2u);

  // Compute the number of chars (words) to move.
  // Save ECX, since we don't know if it will be used later.
  __ pushl(ECX);
  int stack_adjust = kX86WordSize;
  __ cfi().AdjustCFAOffset(stack_adjust);
  DCHECK_EQ(srcEnd, ECX);
  if (srcBegin.IsConstant()) {
    __ subl(ECX, Immediate(srcBegin_value));
  } else {
    DCHECK(srcBegin.IsRegister());
    __ subl(ECX, srcBegin.AsRegister<Register>());
  }

  NearLabel done;
  if (mirror::kUseStringCompression) {
    // Location of count in string
    const uint32_t count_offset = mirror::String::CountOffset().Uint32Value();
    const size_t c_char_size = DataType::Size(DataType::Type::kInt8);
    DCHECK_EQ(c_char_size, 1u);
    __ pushl(EAX);
    __ cfi().AdjustCFAOffset(stack_adjust);

    NearLabel copy_loop, copy_uncompressed;
    __ testl(Address(obj, count_offset), Immediate(1));
    static_assert(static_cast<uint32_t>(mirror::StringCompressionFlag::kCompressed) == 0u,
                  "Expecting 0=compressed, 1=uncompressed");
    __ j(kNotZero, &copy_uncompressed);
    // Compute the address of the source string by adding the number of chars from
    // the source beginning to the value offset of a string.
    __ leal(ESI, CodeGeneratorX86::ArrayAddress(obj, srcBegin, TIMES_1, value_offset));

    // Start the loop to copy String's value to Array of Char.
    __ leal(EDI, Address(dst, dstBegin, ScaleFactor::TIMES_2, data_offset));
    __ Bind(&copy_loop);
    __ jecxz(&done);
    // Use EAX temporary (convert byte from ESI to word).
    // TODO: Use LODSB/STOSW (not supported by X86Assembler) with AH initialized to 0.
    __ movzxb(EAX, Address(ESI, 0));
    __ movw(Address(EDI, 0), EAX);
    __ leal(EDI, Address(EDI, char_size));
    __ leal(ESI, Address(ESI, c_char_size));
    // TODO: Add support for LOOP to X86Assembler.
    __ subl(ECX, Immediate(1));
    __ jmp(&copy_loop);
    __ Bind(&copy_uncompressed);
  }

  // Do the copy for uncompressed string.
  // Compute the address of the destination buffer.
  __ leal(EDI, Address(dst, dstBegin, ScaleFactor::TIMES_2, data_offset));
  __ leal(ESI, CodeGeneratorX86::ArrayAddress(obj, srcBegin, TIMES_2, value_offset));
  __ rep_movsw();

  __ Bind(&done);
  if (mirror::kUseStringCompression) {
    // Restore EAX.
    __ popl(EAX);
    __ cfi().AdjustCFAOffset(-stack_adjust);
  }
  // Restore ECX.
  __ popl(ECX);
  __ cfi().AdjustCFAOffset(-stack_adjust);
}

static void GenPeek(LocationSummary* locations, DataType::Type size, X86Assembler* assembler) {
  Register address = locations->InAt(0).AsRegisterPairLow<Register>();
  Location out_loc = locations->Out();
  // x86 allows unaligned access. We do not have to check the input or use specific instructions
  // to avoid a SIGBUS.
  switch (size) {
    case DataType::Type::kInt8:
      __ movsxb(out_loc.AsRegister<Register>(), Address(address, 0));
      break;
    case DataType::Type::kInt16:
      __ movsxw(out_loc.AsRegister<Register>(), Address(address, 0));
      break;
    case DataType::Type::kInt32:
      __ movl(out_loc.AsRegister<Register>(), Address(address, 0));
      break;
    case DataType::Type::kInt64:
      __ movl(out_loc.AsRegisterPairLow<Register>(), Address(address, 0));
      __ movl(out_loc.AsRegisterPairHigh<Register>(), Address(address, 4));
      break;
    default:
      LOG(FATAL) << "Type not recognized for peek: " << size;
      UNREACHABLE();
  }
}

void IntrinsicLocationsBuilderX86::VisitMemoryPeekByte(HInvoke* invoke) {
  CreateLongToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMemoryPeekByte(HInvoke* invoke) {
  GenPeek(invoke->GetLocations(), DataType::Type::kInt8, GetAssembler());
}

void IntrinsicLocationsBuilderX86::VisitMemoryPeekIntNative(HInvoke* invoke) {
  CreateLongToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMemoryPeekIntNative(HInvoke* invoke) {
  GenPeek(invoke->GetLocations(), DataType::Type::kInt32, GetAssembler());
}

void IntrinsicLocationsBuilderX86::VisitMemoryPeekLongNative(HInvoke* invoke) {
  CreateLongToLongLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMemoryPeekLongNative(HInvoke* invoke) {
  GenPeek(invoke->GetLocations(), DataType::Type::kInt64, GetAssembler());
}

void IntrinsicLocationsBuilderX86::VisitMemoryPeekShortNative(HInvoke* invoke) {
  CreateLongToIntLocations(allocator_, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMemoryPeekShortNative(HInvoke* invoke) {
  GenPeek(invoke->GetLocations(), DataType::Type::kInt16, GetAssembler());
}

static void CreateLongIntToVoidLocations(ArenaAllocator* allocator,
                                         DataType::Type size,
                                         HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  HInstruction* value = invoke->InputAt(1);
  if (size == DataType::Type::kInt8) {
    locations->SetInAt(1, Location::ByteRegisterOrConstant(EDX, value));
  } else {
    locations->SetInAt(1, Location::RegisterOrConstant(value));
  }
}

static void GenPoke(LocationSummary* locations, DataType::Type size, X86Assembler* assembler) {
  Register address = locations->InAt(0).AsRegisterPairLow<Register>();
  Location value_loc = locations->InAt(1);
  // x86 allows unaligned access. We do not have to check the input or use specific instructions
  // to avoid a SIGBUS.
  switch (size) {
    case DataType::Type::kInt8:
      if (value_loc.IsConstant()) {
        __ movb(Address(address, 0),
                Immediate(value_loc.GetConstant()->AsIntConstant()->GetValue()));
      } else {
        __ movb(Address(address, 0), value_loc.AsRegister<ByteRegister>());
      }
      break;
    case DataType::Type::kInt16:
      if (value_loc.IsConstant()) {
        __ movw(Address(address, 0),
                Immediate(value_loc.GetConstant()->AsIntConstant()->GetValue()));
      } else {
        __ movw(Address(address, 0), value_loc.AsRegister<Register>());
      }
      break;
    case DataType::Type::kInt32:
      if (value_loc.IsConstant()) {
        __ movl(Address(address, 0),
                Immediate(value_loc.GetConstant()->AsIntConstant()->GetValue()));
      } else {
        __ movl(Address(address, 0), value_loc.AsRegister<Register>());
      }
      break;
    case DataType::Type::kInt64:
      if (value_loc.IsConstant()) {
        int64_t value = value_loc.GetConstant()->AsLongConstant()->GetValue();
        __ movl(Address(address, 0), Immediate(Low32Bits(value)));
        __ movl(Address(address, 4), Immediate(High32Bits(value)));
      } else {
        __ movl(Address(address, 0), value_loc.AsRegisterPairLow<Register>());
        __ movl(Address(address, 4), value_loc.AsRegisterPairHigh<Register>());
      }
      break;
    default:
      LOG(FATAL) << "Type not recognized for poke: " << size;
      UNREACHABLE();
  }
}

void IntrinsicLocationsBuilderX86::VisitMemoryPokeByte(HInvoke* invoke) {
  CreateLongIntToVoidLocations(allocator_, DataType::Type::kInt8, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMemoryPokeByte(HInvoke* invoke) {
  GenPoke(invoke->GetLocations(), DataType::Type::kInt8, GetAssembler());
}

void IntrinsicLocationsBuilderX86::VisitMemoryPokeIntNative(HInvoke* invoke) {
  CreateLongIntToVoidLocations(allocator_, DataType::Type::kInt32, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMemoryPokeIntNative(HInvoke* invoke) {
  GenPoke(invoke->GetLocations(), DataType::Type::kInt32, GetAssembler());
}

void IntrinsicLocationsBuilderX86::VisitMemoryPokeLongNative(HInvoke* invoke) {
  CreateLongIntToVoidLocations(allocator_, DataType::Type::kInt64, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMemoryPokeLongNative(HInvoke* invoke) {
  GenPoke(invoke->GetLocations(), DataType::Type::kInt64, GetAssembler());
}

void IntrinsicLocationsBuilderX86::VisitMemoryPokeShortNative(HInvoke* invoke) {
  CreateLongIntToVoidLocations(allocator_, DataType::Type::kInt16, invoke);
}

void IntrinsicCodeGeneratorX86::VisitMemoryPokeShortNative(HInvoke* invoke) {
  GenPoke(invoke->GetLocations(), DataType::Type::kInt16, GetAssembler());
}

void IntrinsicLocationsBuilderX86::VisitThreadCurrentThread(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetOut(Location::RequiresRegister());
}

void IntrinsicCodeGeneratorX86::VisitThreadCurrentThread(HInvoke* invoke) {
  Register out = invoke->GetLocations()->Out().AsRegister<Register>();
  GetAssembler()->fs()->movl(out, Address::Absolute(Thread::PeerOffset<kX86PointerSize>()));
}

static void GenUnsafeGet(HInvoke* invoke,
                         DataType::Type type,
                         bool is_volatile,
                         CodeGeneratorX86* codegen) {
  X86Assembler* assembler = down_cast<X86Assembler*>(codegen->GetAssembler());
  LocationSummary* locations = invoke->GetLocations();
  Location base_loc = locations->InAt(1);
  Register base = base_loc.AsRegister<Register>();
  Location offset_loc = locations->InAt(2);
  Register offset = offset_loc.AsRegisterPairLow<Register>();
  Location output_loc = locations->Out();

  switch (type) {
    case DataType::Type::kInt32: {
      Register output = output_loc.AsRegister<Register>();
      __ movl(output, Address(base, offset, ScaleFactor::TIMES_1, 0));
      break;
    }

    case DataType::Type::kReference: {
      Register output = output_loc.AsRegister<Register>();
      if (kEmitCompilerReadBarrier) {
        if (kUseBakerReadBarrier) {
          Address src(base, offset, ScaleFactor::TIMES_1, 0);
          codegen->GenerateReferenceLoadWithBakerReadBarrier(
              invoke, output_loc, base, src, /* needs_null_check= */ false);
        } else {
          __ movl(output, Address(base, offset, ScaleFactor::TIMES_1, 0));
          codegen->GenerateReadBarrierSlow(
              invoke, output_loc, output_loc, base_loc, 0U, offset_loc);
        }
      } else {
        __ movl(output, Address(base, offset, ScaleFactor::TIMES_1, 0));
        __ MaybeUnpoisonHeapReference(output);
      }
      break;
    }

    case DataType::Type::kInt64: {
        Register output_lo = output_loc.AsRegisterPairLow<Register>();
        Register output_hi = output_loc.AsRegisterPairHigh<Register>();
        if (is_volatile) {
          // Need to use a XMM to read atomically.
          XmmRegister temp = locations->GetTemp(0).AsFpuRegister<XmmRegister>();
          __ movsd(temp, Address(base, offset, ScaleFactor::TIMES_1, 0));
          __ movd(output_lo, temp);
          __ psrlq(temp, Immediate(32));
          __ movd(output_hi, temp);
        } else {
          __ movl(output_lo, Address(base, offset, ScaleFactor::TIMES_1, 0));
          __ movl(output_hi, Address(base, offset, ScaleFactor::TIMES_1, 4));
        }
      }
      break;

    default:
      LOG(FATAL) << "Unsupported op size " << type;
      UNREACHABLE();
  }
}

static void CreateIntIntIntToIntLocations(ArenaAllocator* allocator,
                                          HInvoke* invoke,
                                          DataType::Type type,
                                          bool is_volatile) {
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
  }
  locations->SetInAt(0, Location::NoLocation());        // Unused receiver.
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetInAt(2, Location::RequiresRegister());
  if (type == DataType::Type::kInt64) {
    if (is_volatile) {
      // Need to use XMM to read volatile.
      locations->AddTemp(Location::RequiresFpuRegister());
      locations->SetOut(Location::RequiresRegister(), Location::kNoOutputOverlap);
    } else {
      locations->SetOut(Location::RequiresRegister(), Location::kOutputOverlap);
    }
  } else {
    locations->SetOut(Location::RequiresRegister(),
                      (can_call ? Location::kOutputOverlap : Location::kNoOutputOverlap));
  }
}

void IntrinsicLocationsBuilderX86::VisitUnsafeGet(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(
      allocator_, invoke, DataType::Type::kInt32, /* is_volatile= */ false);
}
void IntrinsicLocationsBuilderX86::VisitUnsafeGetVolatile(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(allocator_, invoke, DataType::Type::kInt32, /* is_volatile= */ true);
}
void IntrinsicLocationsBuilderX86::VisitUnsafeGetLong(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(
      allocator_, invoke, DataType::Type::kInt64, /* is_volatile= */ false);
}
void IntrinsicLocationsBuilderX86::VisitUnsafeGetLongVolatile(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(allocator_, invoke, DataType::Type::kInt64, /* is_volatile= */ true);
}
void IntrinsicLocationsBuilderX86::VisitUnsafeGetObject(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(
      allocator_, invoke, DataType::Type::kReference, /* is_volatile= */ false);
}
void IntrinsicLocationsBuilderX86::VisitUnsafeGetObjectVolatile(HInvoke* invoke) {
  CreateIntIntIntToIntLocations(
      allocator_, invoke, DataType::Type::kReference, /* is_volatile= */ true);
}


void IntrinsicCodeGeneratorX86::VisitUnsafeGet(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kInt32, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafeGetVolatile(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kInt32, /* is_volatile= */ true, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafeGetLong(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kInt64, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafeGetLongVolatile(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kInt64, /* is_volatile= */ true, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafeGetObject(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kReference, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafeGetObjectVolatile(HInvoke* invoke) {
  GenUnsafeGet(invoke, DataType::Type::kReference, /* is_volatile= */ true, codegen_);
}


static void CreateIntIntIntIntToVoidPlusTempsLocations(ArenaAllocator* allocator,
                                                       DataType::Type type,
                                                       HInvoke* invoke,
                                                       bool is_volatile) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::NoLocation());        // Unused receiver.
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetInAt(2, Location::RequiresRegister());
  locations->SetInAt(3, Location::RequiresRegister());
  if (type == DataType::Type::kReference) {
    // Need temp registers for card-marking.
    locations->AddTemp(Location::RequiresRegister());  // Possibly used for reference poisoning too.
    // Ensure the value is in a byte register.
    locations->AddTemp(Location::RegisterLocation(ECX));
  } else if (type == DataType::Type::kInt64 && is_volatile) {
    locations->AddTemp(Location::RequiresFpuRegister());
    locations->AddTemp(Location::RequiresFpuRegister());
  }
}

void IntrinsicLocationsBuilderX86::VisitUnsafePut(HInvoke* invoke) {
  CreateIntIntIntIntToVoidPlusTempsLocations(
      allocator_, DataType::Type::kInt32, invoke, /* is_volatile= */ false);
}
void IntrinsicLocationsBuilderX86::VisitUnsafePutOrdered(HInvoke* invoke) {
  CreateIntIntIntIntToVoidPlusTempsLocations(
      allocator_, DataType::Type::kInt32, invoke, /* is_volatile= */ false);
}
void IntrinsicLocationsBuilderX86::VisitUnsafePutVolatile(HInvoke* invoke) {
  CreateIntIntIntIntToVoidPlusTempsLocations(
      allocator_, DataType::Type::kInt32, invoke, /* is_volatile= */ true);
}
void IntrinsicLocationsBuilderX86::VisitUnsafePutObject(HInvoke* invoke) {
  CreateIntIntIntIntToVoidPlusTempsLocations(
      allocator_, DataType::Type::kReference, invoke, /* is_volatile= */ false);
}
void IntrinsicLocationsBuilderX86::VisitUnsafePutObjectOrdered(HInvoke* invoke) {
  CreateIntIntIntIntToVoidPlusTempsLocations(
      allocator_, DataType::Type::kReference, invoke, /* is_volatile= */ false);
}
void IntrinsicLocationsBuilderX86::VisitUnsafePutObjectVolatile(HInvoke* invoke) {
  CreateIntIntIntIntToVoidPlusTempsLocations(
      allocator_, DataType::Type::kReference, invoke, /* is_volatile= */ true);
}
void IntrinsicLocationsBuilderX86::VisitUnsafePutLong(HInvoke* invoke) {
  CreateIntIntIntIntToVoidPlusTempsLocations(
      allocator_, DataType::Type::kInt64, invoke, /* is_volatile= */ false);
}
void IntrinsicLocationsBuilderX86::VisitUnsafePutLongOrdered(HInvoke* invoke) {
  CreateIntIntIntIntToVoidPlusTempsLocations(
      allocator_, DataType::Type::kInt64, invoke, /* is_volatile= */ false);
}
void IntrinsicLocationsBuilderX86::VisitUnsafePutLongVolatile(HInvoke* invoke) {
  CreateIntIntIntIntToVoidPlusTempsLocations(
      allocator_, DataType::Type::kInt64, invoke, /* is_volatile= */ true);
}

// We don't care for ordered: it requires an AnyStore barrier, which is already given by the x86
// memory model.
static void GenUnsafePut(LocationSummary* locations,
                         DataType::Type type,
                         bool is_volatile,
                         CodeGeneratorX86* codegen) {
  X86Assembler* assembler = down_cast<X86Assembler*>(codegen->GetAssembler());
  Register base = locations->InAt(1).AsRegister<Register>();
  Register offset = locations->InAt(2).AsRegisterPairLow<Register>();
  Location value_loc = locations->InAt(3);

  if (type == DataType::Type::kInt64) {
    Register value_lo = value_loc.AsRegisterPairLow<Register>();
    Register value_hi = value_loc.AsRegisterPairHigh<Register>();
    if (is_volatile) {
      XmmRegister temp1 = locations->GetTemp(0).AsFpuRegister<XmmRegister>();
      XmmRegister temp2 = locations->GetTemp(1).AsFpuRegister<XmmRegister>();
      __ movd(temp1, value_lo);
      __ movd(temp2, value_hi);
      __ punpckldq(temp1, temp2);
      __ movsd(Address(base, offset, ScaleFactor::TIMES_1, 0), temp1);
    } else {
      __ movl(Address(base, offset, ScaleFactor::TIMES_1, 0), value_lo);
      __ movl(Address(base, offset, ScaleFactor::TIMES_1, 4), value_hi);
    }
  } else if (kPoisonHeapReferences && type == DataType::Type::kReference) {
    Register temp = locations->GetTemp(0).AsRegister<Register>();
    __ movl(temp, value_loc.AsRegister<Register>());
    __ PoisonHeapReference(temp);
    __ movl(Address(base, offset, ScaleFactor::TIMES_1, 0), temp);
  } else {
    __ movl(Address(base, offset, ScaleFactor::TIMES_1, 0), value_loc.AsRegister<Register>());
  }

  if (is_volatile) {
    codegen->MemoryFence();
  }

  if (type == DataType::Type::kReference) {
    bool value_can_be_null = true;  // TODO: Worth finding out this information?
    codegen->MarkGCCard(locations->GetTemp(0).AsRegister<Register>(),
                        locations->GetTemp(1).AsRegister<Register>(),
                        base,
                        value_loc.AsRegister<Register>(),
                        value_can_be_null);
  }
}

void IntrinsicCodeGeneratorX86::VisitUnsafePut(HInvoke* invoke) {
  GenUnsafePut(invoke->GetLocations(), DataType::Type::kInt32, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafePutOrdered(HInvoke* invoke) {
  GenUnsafePut(invoke->GetLocations(), DataType::Type::kInt32, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafePutVolatile(HInvoke* invoke) {
  GenUnsafePut(invoke->GetLocations(), DataType::Type::kInt32, /* is_volatile= */ true, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafePutObject(HInvoke* invoke) {
  GenUnsafePut(
      invoke->GetLocations(), DataType::Type::kReference, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafePutObjectOrdered(HInvoke* invoke) {
  GenUnsafePut(
      invoke->GetLocations(), DataType::Type::kReference, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafePutObjectVolatile(HInvoke* invoke) {
  GenUnsafePut(
      invoke->GetLocations(), DataType::Type::kReference, /* is_volatile= */ true, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafePutLong(HInvoke* invoke) {
  GenUnsafePut(invoke->GetLocations(), DataType::Type::kInt64, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafePutLongOrdered(HInvoke* invoke) {
  GenUnsafePut(invoke->GetLocations(), DataType::Type::kInt64, /* is_volatile= */ false, codegen_);
}
void IntrinsicCodeGeneratorX86::VisitUnsafePutLongVolatile(HInvoke* invoke) {
  GenUnsafePut(invoke->GetLocations(), DataType::Type::kInt64, /* is_volatile= */ true, codegen_);
}

static void CreateIntIntIntIntIntToInt(ArenaAllocator* allocator,
                                       DataType::Type type,
                                       HInvoke* invoke) {
  bool can_call = kEmitCompilerReadBarrier &&
      kUseBakerReadBarrier &&
      (invoke->GetIntrinsic() == Intrinsics::kUnsafeCASObject);
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke,
                                      can_call
                                          ? LocationSummary::kCallOnSlowPath
                                          : LocationSummary::kNoCall,
                                      kIntrinsified);
  locations->SetInAt(0, Location::NoLocation());        // Unused receiver.
  locations->SetInAt(1, Location::RequiresRegister());
  // Offset is a long, but in 32 bit mode, we only need the low word.
  // Can we update the invoke here to remove a TypeConvert to Long?
  locations->SetInAt(2, Location::RequiresRegister());
  // Expected value must be in EAX or EDX:EAX.
  // For long, new value must be in ECX:EBX.
  if (type == DataType::Type::kInt64) {
    locations->SetInAt(3, Location::RegisterPairLocation(EAX, EDX));
    locations->SetInAt(4, Location::RegisterPairLocation(EBX, ECX));
  } else {
    locations->SetInAt(3, Location::RegisterLocation(EAX));
    locations->SetInAt(4, Location::RequiresRegister());
  }

  // Force a byte register for the output.
  locations->SetOut(Location::RegisterLocation(EAX));
  if (type == DataType::Type::kReference) {
    // Need temporary registers for card-marking, and possibly for
    // (Baker) read barrier.
    locations->AddTemp(Location::RequiresRegister());  // Possibly used for reference poisoning too.
    // Need a byte register for marking.
    locations->AddTemp(Location::RegisterLocation(ECX));
  }
}

void IntrinsicLocationsBuilderX86::VisitUnsafeCASInt(HInvoke* invoke) {
  CreateIntIntIntIntIntToInt(allocator_, DataType::Type::kInt32, invoke);
}

void IntrinsicLocationsBuilderX86::VisitUnsafeCASLong(HInvoke* invoke) {
  CreateIntIntIntIntIntToInt(allocator_, DataType::Type::kInt64, invoke);
}

void IntrinsicLocationsBuilderX86::VisitUnsafeCASObject(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // UnsafeCASObject intrinsic is the Baker-style read barriers.
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  CreateIntIntIntIntIntToInt(allocator_, DataType::Type::kReference, invoke);
}

static void GenPrimitiveLockedCmpxchg(DataType::Type type,
                                      CodeGeneratorX86* codegen,
                                      Location expected_value,
                                      Location new_value,
                                      Register base,
                                      Register offset,
                                      // Only necessary for floating point
                                      Register temp = Register::kNoRegister) {
  X86Assembler* assembler = down_cast<X86Assembler*>(codegen->GetAssembler());

  if (DataType::Kind(type) == DataType::Type::kInt32) {
    DCHECK_EQ(expected_value.AsRegister<Register>(), EAX);
  }

  // The address of the field within the holding object.
  Address field_addr(base, offset, TIMES_1, 0);

  switch (type) {
    case DataType::Type::kBool:
    case DataType::Type::kInt8:
      __ LockCmpxchgb(field_addr, new_value.AsRegister<ByteRegister>());
      break;
    case DataType::Type::kInt16:
    case DataType::Type::kUint16:
      __ LockCmpxchgw(field_addr, new_value.AsRegister<Register>());
      break;
    case DataType::Type::kInt32:
      __ LockCmpxchgl(field_addr, new_value.AsRegister<Register>());
      break;
    case DataType::Type::kFloat32: {
      // cmpxchg requires the expected value to be in EAX so the new value must be elsewhere.
      DCHECK_NE(temp, EAX);
      // EAX is both an input and an output for cmpxchg
      codegen->Move32(Location::RegisterLocation(EAX), expected_value);
      codegen->Move32(Location::RegisterLocation(temp), new_value);
      __ LockCmpxchgl(field_addr, temp);
      break;
    }
    case DataType::Type::kInt64:
      // Ensure the expected value is in EAX:EDX and that the new
      // value is in EBX:ECX (required by the CMPXCHG8B instruction).
      DCHECK_EQ(expected_value.AsRegisterPairLow<Register>(), EAX);
      DCHECK_EQ(expected_value.AsRegisterPairHigh<Register>(), EDX);
      DCHECK_EQ(new_value.AsRegisterPairLow<Register>(), EBX);
      DCHECK_EQ(new_value.AsRegisterPairHigh<Register>(), ECX);
      __ LockCmpxchg8b(field_addr);
      break;
    default:
      LOG(FATAL) << "Unexpected CAS type " << type;
  }
  // LOCK CMPXCHG/LOCK CMPXCHG8B have full barrier semantics, and we
  // don't need scheduling barriers at this time.
}

static void GenPrimitiveCAS(DataType::Type type,
                            CodeGeneratorX86* codegen,
                            Location expected_value,
                            Location new_value,
                            Register base,
                            Register offset,
                            Location out,
                            // Only necessary for floating point
                            Register temp = Register::kNoRegister,
                            bool is_cmpxchg = false) {
  X86Assembler* assembler = down_cast<X86Assembler*>(codegen->GetAssembler());

  if (!is_cmpxchg || DataType::Kind(type) == DataType::Type::kInt32) {
    DCHECK_EQ(out.AsRegister<Register>(), EAX);
  }

  GenPrimitiveLockedCmpxchg(type, codegen, expected_value, new_value, base, offset, temp);

  if (is_cmpxchg) {
    // Sign-extend, zero-extend or move the result if necessary
    switch (type) {
      case DataType::Type::kBool:
        __ movzxb(out.AsRegister<Register>(), out.AsRegister<ByteRegister>());
        break;
      case DataType::Type::kInt8:
        __ movsxb(out.AsRegister<Register>(), out.AsRegister<ByteRegister>());
        break;
      case DataType::Type::kInt16:
        __ movsxw(out.AsRegister<Register>(), out.AsRegister<Register>());
        break;
      case DataType::Type::kUint16:
        __ movzxw(out.AsRegister<Register>(), out.AsRegister<Register>());
        break;
      case DataType::Type::kFloat32:
        __ movd(out.AsFpuRegister<XmmRegister>(), EAX);
        break;
      default:
        // Nothing to do
        break;
    }
  } else {
    // Convert ZF into the Boolean result.
    __ setb(kZero, out.AsRegister<Register>());
    __ movzxb(out.AsRegister<Register>(), out.AsRegister<ByteRegister>());
  }
}

static void GenReferenceCAS(HInvoke* invoke,
                            CodeGeneratorX86* codegen,
                            Location expected_value,
                            Location new_value,
                            Register base,
                            Register offset,
                            Register temp,
                            Register temp2,
                            bool is_cmpxchg = false) {
  X86Assembler* assembler = down_cast<X86Assembler*>(codegen->GetAssembler());
  LocationSummary* locations = invoke->GetLocations();
  Location out = locations->Out();

  // The address of the field within the holding object.
  Address field_addr(base, offset, TIMES_1, 0);

  Register value = new_value.AsRegister<Register>();
  Register expected = expected_value.AsRegister<Register>();
  DCHECK_EQ(expected, EAX);
  DCHECK_NE(temp, temp2);

  if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
    // Need to make sure the reference stored in the field is a to-space
    // one before attempting the CAS or the CAS could fail incorrectly.
    codegen->GenerateReferenceLoadWithBakerReadBarrier(
        invoke,
        // Unused, used only as a "temporary" within the read barrier.
        Location::RegisterLocation(temp),
        base,
        field_addr,
        /* needs_null_check= */ false,
        /* always_update_field= */ true,
        &temp2);
  }
  bool base_equals_value = (base == value);
  if (kPoisonHeapReferences) {
    if (base_equals_value) {
      // If `base` and `value` are the same register location, move
      // `value` to a temporary register.  This way, poisoning
      // `value` won't invalidate `base`.
      value = temp;
      __ movl(value, base);
    }

    // Check that the register allocator did not assign the location
    // of `expected` (EAX) to `value` nor to `base`, so that heap
    // poisoning (when enabled) works as intended below.
    // - If `value` were equal to `expected`, both references would
    //   be poisoned twice, meaning they would not be poisoned at
    //   all, as heap poisoning uses address negation.
    // - If `base` were equal to `expected`, poisoning `expected`
    //   would invalidate `base`.
    DCHECK_NE(value, expected);
    DCHECK_NE(base, expected);
    __ PoisonHeapReference(expected);
    __ PoisonHeapReference(value);
  }
  __ LockCmpxchgl(field_addr, value);

  // LOCK CMPXCHG has full barrier semantics, and we don't need
  // scheduling barriers at this time.

  if (is_cmpxchg) {
    DCHECK_EQ(out.AsRegister<Register>(), EAX);
    __ MaybeUnpoisonHeapReference(out.AsRegister<Register>());
  } else {
    // Convert ZF into the Boolean result.
    __ setb(kZero, out.AsRegister<Register>());
    __ movzxb(out.AsRegister<Register>(), out.AsRegister<ByteRegister>());
  }

  // Mark card for object if the new value is stored.
  bool value_can_be_null = true;  // TODO: Worth finding out this information?
  NearLabel skip_mark_gc_card;
  __ j(kNotZero, &skip_mark_gc_card);
  codegen->MarkGCCard(temp, temp2, base, value, value_can_be_null);
  __ Bind(&skip_mark_gc_card);

  // If heap poisoning is enabled, we need to unpoison the values
  // that were poisoned earlier.
  if (kPoisonHeapReferences) {
    if (base_equals_value) {
      // `value` has been moved to a temporary register, no need to
      // unpoison it.
    } else {
      // Ensure `value` is different from `out`, so that unpoisoning
      // the former does not invalidate the latter.
      DCHECK_NE(value, out.AsRegister<Register>());
      __ UnpoisonHeapReference(value);
    }
  }
  // Do not unpoison the reference contained in register
  // `expected`, as it is the same as register `out` (EAX).
}

static void GenCAS(DataType::Type type, HInvoke* invoke, CodeGeneratorX86* codegen) {
  LocationSummary* locations = invoke->GetLocations();

  Register base = locations->InAt(1).AsRegister<Register>();
  Register offset = locations->InAt(2).AsRegisterPairLow<Register>();
  Location expected_value = locations->InAt(3);
  Location new_value = locations->InAt(4);
  Location out = locations->Out();
  DCHECK_EQ(out.AsRegister<Register>(), EAX);

  if (type == DataType::Type::kReference) {
    // The only read barrier implementation supporting the
    // UnsafeCASObject intrinsic is the Baker-style read barriers.
    DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

    Register temp = locations->GetTemp(0).AsRegister<Register>();
    Register temp2 = locations->GetTemp(1).AsRegister<Register>();
    GenReferenceCAS(invoke, codegen, expected_value, new_value, base, offset, temp, temp2);
  } else {
    DCHECK(!DataType::IsFloatingPointType(type));
    GenPrimitiveCAS(type, codegen, expected_value, new_value, base, offset, out);
  }
}

void IntrinsicCodeGeneratorX86::VisitUnsafeCASInt(HInvoke* invoke) {
  GenCAS(DataType::Type::kInt32, invoke, codegen_);
}

void IntrinsicCodeGeneratorX86::VisitUnsafeCASLong(HInvoke* invoke) {
  GenCAS(DataType::Type::kInt64, invoke, codegen_);
}

void IntrinsicCodeGeneratorX86::VisitUnsafeCASObject(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // UnsafeCASObject intrinsic is the Baker-style read barriers.
  DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

  GenCAS(DataType::Type::kReference, invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitIntegerReverse(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetOut(Location::SameAsFirstInput());
  locations->AddTemp(Location::RequiresRegister());
}

static void SwapBits(Register reg, Register temp, int32_t shift, int32_t mask,
                     X86Assembler* assembler) {
  Immediate imm_shift(shift);
  Immediate imm_mask(mask);
  __ movl(temp, reg);
  __ shrl(reg, imm_shift);
  __ andl(temp, imm_mask);
  __ andl(reg, imm_mask);
  __ shll(temp, imm_shift);
  __ orl(reg, temp);
}

void IntrinsicCodeGeneratorX86::VisitIntegerReverse(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register reg = locations->InAt(0).AsRegister<Register>();
  Register temp = locations->GetTemp(0).AsRegister<Register>();

  /*
   * Use one bswap instruction to reverse byte order first and then use 3 rounds of
   * swapping bits to reverse bits in a number x. Using bswap to save instructions
   * compared to generic luni implementation which has 5 rounds of swapping bits.
   * x = bswap x
   * x = (x & 0x55555555) << 1 | (x >> 1) & 0x55555555;
   * x = (x & 0x33333333) << 2 | (x >> 2) & 0x33333333;
   * x = (x & 0x0F0F0F0F) << 4 | (x >> 4) & 0x0F0F0F0F;
   */
  __ bswapl(reg);
  SwapBits(reg, temp, 1, 0x55555555, assembler);
  SwapBits(reg, temp, 2, 0x33333333, assembler);
  SwapBits(reg, temp, 4, 0x0f0f0f0f, assembler);
}

void IntrinsicLocationsBuilderX86::VisitLongReverse(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  locations->SetOut(Location::SameAsFirstInput());
  locations->AddTemp(Location::RequiresRegister());
}

void IntrinsicCodeGeneratorX86::VisitLongReverse(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register reg_low = locations->InAt(0).AsRegisterPairLow<Register>();
  Register reg_high = locations->InAt(0).AsRegisterPairHigh<Register>();
  Register temp = locations->GetTemp(0).AsRegister<Register>();

  // We want to swap high/low, then bswap each one, and then do the same
  // as a 32 bit reverse.
  // Exchange high and low.
  __ movl(temp, reg_low);
  __ movl(reg_low, reg_high);
  __ movl(reg_high, temp);

  // bit-reverse low
  __ bswapl(reg_low);
  SwapBits(reg_low, temp, 1, 0x55555555, assembler);
  SwapBits(reg_low, temp, 2, 0x33333333, assembler);
  SwapBits(reg_low, temp, 4, 0x0f0f0f0f, assembler);

  // bit-reverse high
  __ bswapl(reg_high);
  SwapBits(reg_high, temp, 1, 0x55555555, assembler);
  SwapBits(reg_high, temp, 2, 0x33333333, assembler);
  SwapBits(reg_high, temp, 4, 0x0f0f0f0f, assembler);
}

static void CreateBitCountLocations(
    ArenaAllocator* allocator, CodeGeneratorX86* codegen, HInvoke* invoke, bool is_long) {
  if (!codegen->GetInstructionSetFeatures().HasPopCnt()) {
    // Do nothing if there is no popcnt support. This results in generating
    // a call for the intrinsic rather than direct code.
    return;
  }
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  if (is_long) {
    locations->AddTemp(Location::RequiresRegister());
  }
  locations->SetInAt(0, Location::Any());
  locations->SetOut(Location::RequiresRegister());
}

static void GenBitCount(X86Assembler* assembler,
                        CodeGeneratorX86* codegen,
                        HInvoke* invoke, bool is_long) {
  LocationSummary* locations = invoke->GetLocations();
  Location src = locations->InAt(0);
  Register out = locations->Out().AsRegister<Register>();

  if (invoke->InputAt(0)->IsConstant()) {
    // Evaluate this at compile time.
    int64_t value = Int64FromConstant(invoke->InputAt(0)->AsConstant());
    int32_t result = is_long
        ? POPCOUNT(static_cast<uint64_t>(value))
        : POPCOUNT(static_cast<uint32_t>(value));
    codegen->Load32BitValue(out, result);
    return;
  }

  // Handle the non-constant cases.
  if (!is_long) {
    if (src.IsRegister()) {
      __ popcntl(out, src.AsRegister<Register>());
    } else {
      DCHECK(src.IsStackSlot());
      __ popcntl(out, Address(ESP, src.GetStackIndex()));
    }
  } else {
    // The 64-bit case needs to worry about two parts.
    Register temp = locations->GetTemp(0).AsRegister<Register>();
    if (src.IsRegisterPair()) {
      __ popcntl(temp, src.AsRegisterPairLow<Register>());
      __ popcntl(out, src.AsRegisterPairHigh<Register>());
    } else {
      DCHECK(src.IsDoubleStackSlot());
      __ popcntl(temp, Address(ESP, src.GetStackIndex()));
      __ popcntl(out, Address(ESP, src.GetHighStackIndex(kX86WordSize)));
    }
    __ addl(out, temp);
  }
}

void IntrinsicLocationsBuilderX86::VisitIntegerBitCount(HInvoke* invoke) {
  CreateBitCountLocations(allocator_, codegen_, invoke, /* is_long= */ false);
}

void IntrinsicCodeGeneratorX86::VisitIntegerBitCount(HInvoke* invoke) {
  GenBitCount(GetAssembler(), codegen_, invoke, /* is_long= */ false);
}

void IntrinsicLocationsBuilderX86::VisitLongBitCount(HInvoke* invoke) {
  CreateBitCountLocations(allocator_, codegen_, invoke, /* is_long= */ true);
}

void IntrinsicCodeGeneratorX86::VisitLongBitCount(HInvoke* invoke) {
  GenBitCount(GetAssembler(), codegen_, invoke, /* is_long= */ true);
}

static void CreateLeadingZeroLocations(ArenaAllocator* allocator, HInvoke* invoke, bool is_long) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  if (is_long) {
    locations->SetInAt(0, Location::RequiresRegister());
  } else {
    locations->SetInAt(0, Location::Any());
  }
  locations->SetOut(Location::RequiresRegister());
}

static void GenLeadingZeros(X86Assembler* assembler,
                            CodeGeneratorX86* codegen,
                            HInvoke* invoke, bool is_long) {
  LocationSummary* locations = invoke->GetLocations();
  Location src = locations->InAt(0);
  Register out = locations->Out().AsRegister<Register>();

  if (invoke->InputAt(0)->IsConstant()) {
    // Evaluate this at compile time.
    int64_t value = Int64FromConstant(invoke->InputAt(0)->AsConstant());
    if (value == 0) {
      value = is_long ? 64 : 32;
    } else {
      value = is_long ? CLZ(static_cast<uint64_t>(value)) : CLZ(static_cast<uint32_t>(value));
    }
    codegen->Load32BitValue(out, value);
    return;
  }

  // Handle the non-constant cases.
  if (!is_long) {
    if (src.IsRegister()) {
      __ bsrl(out, src.AsRegister<Register>());
    } else {
      DCHECK(src.IsStackSlot());
      __ bsrl(out, Address(ESP, src.GetStackIndex()));
    }

    // BSR sets ZF if the input was zero, and the output is undefined.
    NearLabel all_zeroes, done;
    __ j(kEqual, &all_zeroes);

    // Correct the result from BSR to get the final CLZ result.
    __ xorl(out, Immediate(31));
    __ jmp(&done);

    // Fix the zero case with the expected result.
    __ Bind(&all_zeroes);
    __ movl(out, Immediate(32));

    __ Bind(&done);
    return;
  }

  // 64 bit case needs to worry about both parts of the register.
  DCHECK(src.IsRegisterPair());
  Register src_lo = src.AsRegisterPairLow<Register>();
  Register src_hi = src.AsRegisterPairHigh<Register>();
  NearLabel handle_low, done, all_zeroes;

  // Is the high word zero?
  __ testl(src_hi, src_hi);
  __ j(kEqual, &handle_low);

  // High word is not zero. We know that the BSR result is defined in this case.
  __ bsrl(out, src_hi);

  // Correct the result from BSR to get the final CLZ result.
  __ xorl(out, Immediate(31));
  __ jmp(&done);

  // High word was zero.  We have to compute the low word count and add 32.
  __ Bind(&handle_low);
  __ bsrl(out, src_lo);
  __ j(kEqual, &all_zeroes);

  // We had a valid result.  Use an XOR to both correct the result and add 32.
  __ xorl(out, Immediate(63));
  __ jmp(&done);

  // All zero case.
  __ Bind(&all_zeroes);
  __ movl(out, Immediate(64));

  __ Bind(&done);
}

void IntrinsicLocationsBuilderX86::VisitIntegerNumberOfLeadingZeros(HInvoke* invoke) {
  CreateLeadingZeroLocations(allocator_, invoke, /* is_long= */ false);
}

void IntrinsicCodeGeneratorX86::VisitIntegerNumberOfLeadingZeros(HInvoke* invoke) {
  GenLeadingZeros(GetAssembler(), codegen_, invoke, /* is_long= */ false);
}

void IntrinsicLocationsBuilderX86::VisitLongNumberOfLeadingZeros(HInvoke* invoke) {
  CreateLeadingZeroLocations(allocator_, invoke, /* is_long= */ true);
}

void IntrinsicCodeGeneratorX86::VisitLongNumberOfLeadingZeros(HInvoke* invoke) {
  GenLeadingZeros(GetAssembler(), codegen_, invoke, /* is_long= */ true);
}

static void CreateTrailingZeroLocations(ArenaAllocator* allocator, HInvoke* invoke, bool is_long) {
  LocationSummary* locations =
      new (allocator) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  if (is_long) {
    locations->SetInAt(0, Location::RequiresRegister());
  } else {
    locations->SetInAt(0, Location::Any());
  }
  locations->SetOut(Location::RequiresRegister());
}

static void GenTrailingZeros(X86Assembler* assembler,
                             CodeGeneratorX86* codegen,
                             HInvoke* invoke, bool is_long) {
  LocationSummary* locations = invoke->GetLocations();
  Location src = locations->InAt(0);
  Register out = locations->Out().AsRegister<Register>();

  if (invoke->InputAt(0)->IsConstant()) {
    // Evaluate this at compile time.
    int64_t value = Int64FromConstant(invoke->InputAt(0)->AsConstant());
    if (value == 0) {
      value = is_long ? 64 : 32;
    } else {
      value = is_long ? CTZ(static_cast<uint64_t>(value)) : CTZ(static_cast<uint32_t>(value));
    }
    codegen->Load32BitValue(out, value);
    return;
  }

  // Handle the non-constant cases.
  if (!is_long) {
    if (src.IsRegister()) {
      __ bsfl(out, src.AsRegister<Register>());
    } else {
      DCHECK(src.IsStackSlot());
      __ bsfl(out, Address(ESP, src.GetStackIndex()));
    }

    // BSF sets ZF if the input was zero, and the output is undefined.
    NearLabel done;
    __ j(kNotEqual, &done);

    // Fix the zero case with the expected result.
    __ movl(out, Immediate(32));

    __ Bind(&done);
    return;
  }

  // 64 bit case needs to worry about both parts of the register.
  DCHECK(src.IsRegisterPair());
  Register src_lo = src.AsRegisterPairLow<Register>();
  Register src_hi = src.AsRegisterPairHigh<Register>();
  NearLabel done, all_zeroes;

  // If the low word is zero, then ZF will be set.  If not, we have the answer.
  __ bsfl(out, src_lo);
  __ j(kNotEqual, &done);

  // Low word was zero.  We have to compute the high word count and add 32.
  __ bsfl(out, src_hi);
  __ j(kEqual, &all_zeroes);

  // We had a valid result.  Add 32 to account for the low word being zero.
  __ addl(out, Immediate(32));
  __ jmp(&done);

  // All zero case.
  __ Bind(&all_zeroes);
  __ movl(out, Immediate(64));

  __ Bind(&done);
}

void IntrinsicLocationsBuilderX86::VisitIntegerNumberOfTrailingZeros(HInvoke* invoke) {
  CreateTrailingZeroLocations(allocator_, invoke, /* is_long= */ false);
}

void IntrinsicCodeGeneratorX86::VisitIntegerNumberOfTrailingZeros(HInvoke* invoke) {
  GenTrailingZeros(GetAssembler(), codegen_, invoke, /* is_long= */ false);
}

void IntrinsicLocationsBuilderX86::VisitLongNumberOfTrailingZeros(HInvoke* invoke) {
  CreateTrailingZeroLocations(allocator_, invoke, /* is_long= */ true);
}

void IntrinsicCodeGeneratorX86::VisitLongNumberOfTrailingZeros(HInvoke* invoke) {
  GenTrailingZeros(GetAssembler(), codegen_, invoke, /* is_long= */ true);
}

static bool IsSameInput(HInstruction* instruction, size_t input0, size_t input1) {
  return instruction->InputAt(input0) == instruction->InputAt(input1);
}

// Compute base address for the System.arraycopy intrinsic in `base`.
static void GenSystemArrayCopyBaseAddress(X86Assembler* assembler,
                                          DataType::Type type,
                                          const Register& array,
                                          const Location& pos,
                                          const Register& base) {
  // This routine is only used by the SystemArrayCopy intrinsic at the
  // moment. We can allow DataType::Type::kReference as `type` to implement
  // the SystemArrayCopyChar intrinsic.
  DCHECK_EQ(type, DataType::Type::kReference);
  const int32_t element_size = DataType::Size(type);
  const ScaleFactor scale_factor = static_cast<ScaleFactor>(DataType::SizeShift(type));
  const uint32_t data_offset = mirror::Array::DataOffset(element_size).Uint32Value();

  if (pos.IsConstant()) {
    int32_t constant = pos.GetConstant()->AsIntConstant()->GetValue();
    __ leal(base, Address(array, element_size * constant + data_offset));
  } else {
    __ leal(base, Address(array, pos.AsRegister<Register>(), scale_factor, data_offset));
  }
}

// Compute end source address for the System.arraycopy intrinsic in `end`.
static void GenSystemArrayCopyEndAddress(X86Assembler* assembler,
                                         DataType::Type type,
                                         const Location& copy_length,
                                         const Register& base,
                                         const Register& end) {
  // This routine is only used by the SystemArrayCopy intrinsic at the
  // moment. We can allow DataType::Type::kReference as `type` to implement
  // the SystemArrayCopyChar intrinsic.
  DCHECK_EQ(type, DataType::Type::kReference);
  const int32_t element_size = DataType::Size(type);
  const ScaleFactor scale_factor = static_cast<ScaleFactor>(DataType::SizeShift(type));

  if (copy_length.IsConstant()) {
    int32_t constant = copy_length.GetConstant()->AsIntConstant()->GetValue();
    __ leal(end, Address(base, element_size * constant));
  } else {
    __ leal(end, Address(base, copy_length.AsRegister<Register>(), scale_factor, 0));
  }
}

void IntrinsicLocationsBuilderX86::VisitSystemArrayCopy(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // SystemArrayCopy intrinsic is the Baker-style read barriers.
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  CodeGenerator::CreateSystemArrayCopyLocationSummary(invoke);
  if (invoke->GetLocations() != nullptr) {
    // Need a byte register for marking.
    invoke->GetLocations()->SetTempAt(1, Location::RegisterLocation(ECX));

    static constexpr size_t kSrc = 0;
    static constexpr size_t kSrcPos = 1;
    static constexpr size_t kDest = 2;
    static constexpr size_t kDestPos = 3;
    static constexpr size_t kLength = 4;

    if (!invoke->InputAt(kSrcPos)->IsIntConstant() &&
        !invoke->InputAt(kDestPos)->IsIntConstant() &&
        !invoke->InputAt(kLength)->IsIntConstant()) {
      if (!IsSameInput(invoke, kSrcPos, kDestPos) &&
          !IsSameInput(invoke, kSrcPos, kLength) &&
          !IsSameInput(invoke, kDestPos, kLength) &&
          !IsSameInput(invoke, kSrc, kDest)) {
        // Not enough registers, make the length also take a stack slot.
        invoke->GetLocations()->SetInAt(kLength, Location::Any());
      }
    }
  }
}

void IntrinsicCodeGeneratorX86::VisitSystemArrayCopy(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // SystemArrayCopy intrinsic is the Baker-style read barriers.
  DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  uint32_t class_offset = mirror::Object::ClassOffset().Int32Value();
  uint32_t super_offset = mirror::Class::SuperClassOffset().Int32Value();
  uint32_t component_offset = mirror::Class::ComponentTypeOffset().Int32Value();
  uint32_t primitive_offset = mirror::Class::PrimitiveTypeOffset().Int32Value();
  uint32_t monitor_offset = mirror::Object::MonitorOffset().Int32Value();

  Register src = locations->InAt(0).AsRegister<Register>();
  Location src_pos = locations->InAt(1);
  Register dest = locations->InAt(2).AsRegister<Register>();
  Location dest_pos = locations->InAt(3);
  Location length_arg = locations->InAt(4);
  Location length = length_arg;
  Location temp1_loc = locations->GetTemp(0);
  Register temp1 = temp1_loc.AsRegister<Register>();
  Location temp2_loc = locations->GetTemp(1);
  Register temp2 = temp2_loc.AsRegister<Register>();

  SlowPathCode* intrinsic_slow_path =
      new (codegen_->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen_->AddSlowPath(intrinsic_slow_path);

  NearLabel conditions_on_positions_validated;
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
        __ cmpl(src, dest);
        __ j(kEqual, intrinsic_slow_path->GetEntryLabel());
      }
    } else {
      if (!optimizations.GetDestinationIsSource()) {
        __ cmpl(src, dest);
        __ j(kNotEqual, &conditions_on_positions_validated);
      }
      __ cmpl(dest_pos.AsRegister<Register>(), Immediate(src_pos_constant));
      __ j(kGreater, intrinsic_slow_path->GetEntryLabel());
    }
  } else {
    if (!optimizations.GetDestinationIsSource()) {
      __ cmpl(src, dest);
      __ j(kNotEqual, &conditions_on_positions_validated);
    }
    if (dest_pos.IsConstant()) {
      int32_t dest_pos_constant = dest_pos.GetConstant()->AsIntConstant()->GetValue();
      __ cmpl(src_pos.AsRegister<Register>(), Immediate(dest_pos_constant));
      __ j(kLess, intrinsic_slow_path->GetEntryLabel());
    } else {
      __ cmpl(src_pos.AsRegister<Register>(), dest_pos.AsRegister<Register>());
      __ j(kLess, intrinsic_slow_path->GetEntryLabel());
    }
  }

  __ Bind(&conditions_on_positions_validated);

  if (!optimizations.GetSourceIsNotNull()) {
    // Bail out if the source is null.
    __ testl(src, src);
    __ j(kEqual, intrinsic_slow_path->GetEntryLabel());
  }

  if (!optimizations.GetDestinationIsNotNull() && !optimizations.GetDestinationIsSource()) {
    // Bail out if the destination is null.
    __ testl(dest, dest);
    __ j(kEqual, intrinsic_slow_path->GetEntryLabel());
  }

  Location temp3_loc = locations->GetTemp(2);
  Register temp3 = temp3_loc.AsRegister<Register>();
  if (length.IsStackSlot()) {
    __ movl(temp3, Address(ESP, length.GetStackIndex()));
    length = Location::RegisterLocation(temp3);
  }

  // If the length is negative, bail out.
  // We have already checked in the LocationsBuilder for the constant case.
  if (!length.IsConstant() &&
      !optimizations.GetCountIsSourceLength() &&
      !optimizations.GetCountIsDestinationLength()) {
    __ testl(length.AsRegister<Register>(), length.AsRegister<Register>());
    __ j(kLess, intrinsic_slow_path->GetEntryLabel());
  }

  // Validity checks: source.
  CheckPosition(assembler,
                src_pos,
                src,
                length,
                intrinsic_slow_path,
                temp1,
                optimizations.GetCountIsSourceLength());

  // Validity checks: dest.
  CheckPosition(assembler,
                dest_pos,
                dest,
                length,
                intrinsic_slow_path,
                temp1,
                optimizations.GetCountIsDestinationLength());

  if (!optimizations.GetDoesNotNeedTypeCheck()) {
    // Check whether all elements of the source array are assignable to the component
    // type of the destination array. We do two checks: the classes are the same,
    // or the destination is Object[]. If none of these checks succeed, we go to the
    // slow path.

    if (!optimizations.GetSourceIsNonPrimitiveArray()) {
      if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
        // /* HeapReference<Class> */ temp1 = src->klass_
        codegen_->GenerateFieldLoadWithBakerReadBarrier(
            invoke, temp1_loc, src, class_offset, /* needs_null_check= */ false);
        // Bail out if the source is not a non primitive array.
        // /* HeapReference<Class> */ temp1 = temp1->component_type_
        codegen_->GenerateFieldLoadWithBakerReadBarrier(
            invoke, temp1_loc, temp1, component_offset, /* needs_null_check= */ false);
        __ testl(temp1, temp1);
        __ j(kEqual, intrinsic_slow_path->GetEntryLabel());
        // If heap poisoning is enabled, `temp1` has been unpoisoned
        // by the the previous call to GenerateFieldLoadWithBakerReadBarrier.
      } else {
        // /* HeapReference<Class> */ temp1 = src->klass_
        __ movl(temp1, Address(src, class_offset));
        __ MaybeUnpoisonHeapReference(temp1);
        // Bail out if the source is not a non primitive array.
        // /* HeapReference<Class> */ temp1 = temp1->component_type_
        __ movl(temp1, Address(temp1, component_offset));
        __ testl(temp1, temp1);
        __ j(kEqual, intrinsic_slow_path->GetEntryLabel());
        __ MaybeUnpoisonHeapReference(temp1);
      }
      __ cmpw(Address(temp1, primitive_offset), Immediate(Primitive::kPrimNot));
      __ j(kNotEqual, intrinsic_slow_path->GetEntryLabel());
    }

    if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
      if (length.Equals(Location::RegisterLocation(temp3))) {
        // When Baker read barriers are enabled, register `temp3`,
        // which in the present case contains the `length` parameter,
        // will be overwritten below.  Make the `length` location
        // reference the original stack location; it will be moved
        // back to `temp3` later if necessary.
        DCHECK(length_arg.IsStackSlot());
        length = length_arg;
      }

      // /* HeapReference<Class> */ temp1 = dest->klass_
      codegen_->GenerateFieldLoadWithBakerReadBarrier(
          invoke, temp1_loc, dest, class_offset, /* needs_null_check= */ false);

      if (!optimizations.GetDestinationIsNonPrimitiveArray()) {
        // Bail out if the destination is not a non primitive array.
        //
        // Register `temp1` is not trashed by the read barrier emitted
        // by GenerateFieldLoadWithBakerReadBarrier below, as that
        // method produces a call to a ReadBarrierMarkRegX entry point,
        // which saves all potentially live registers, including
        // temporaries such a `temp1`.
        // /* HeapReference<Class> */ temp2 = temp1->component_type_
        codegen_->GenerateFieldLoadWithBakerReadBarrier(
            invoke, temp2_loc, temp1, component_offset, /* needs_null_check= */ false);
        __ testl(temp2, temp2);
        __ j(kEqual, intrinsic_slow_path->GetEntryLabel());
        // If heap poisoning is enabled, `temp2` has been unpoisoned
        // by the the previous call to GenerateFieldLoadWithBakerReadBarrier.
        __ cmpw(Address(temp2, primitive_offset), Immediate(Primitive::kPrimNot));
        __ j(kNotEqual, intrinsic_slow_path->GetEntryLabel());
      }

      // For the same reason given earlier, `temp1` is not trashed by the
      // read barrier emitted by GenerateFieldLoadWithBakerReadBarrier below.
      // /* HeapReference<Class> */ temp2 = src->klass_
      codegen_->GenerateFieldLoadWithBakerReadBarrier(
          invoke, temp2_loc, src, class_offset, /* needs_null_check= */ false);
      // Note: if heap poisoning is on, we are comparing two unpoisoned references here.
      __ cmpl(temp1, temp2);

      if (optimizations.GetDestinationIsTypedObjectArray()) {
        NearLabel do_copy;
        __ j(kEqual, &do_copy);
        // /* HeapReference<Class> */ temp1 = temp1->component_type_
        codegen_->GenerateFieldLoadWithBakerReadBarrier(
            invoke, temp1_loc, temp1, component_offset, /* needs_null_check= */ false);
        // We do not need to emit a read barrier for the following
        // heap reference load, as `temp1` is only used in a
        // comparison with null below, and this reference is not
        // kept afterwards.
        __ cmpl(Address(temp1, super_offset), Immediate(0));
        __ j(kNotEqual, intrinsic_slow_path->GetEntryLabel());
        __ Bind(&do_copy);
      } else {
        __ j(kNotEqual, intrinsic_slow_path->GetEntryLabel());
      }
    } else {
      // Non read barrier code.

      // /* HeapReference<Class> */ temp1 = dest->klass_
      __ movl(temp1, Address(dest, class_offset));
      if (!optimizations.GetDestinationIsNonPrimitiveArray()) {
        __ MaybeUnpoisonHeapReference(temp1);
        // Bail out if the destination is not a non primitive array.
        // /* HeapReference<Class> */ temp2 = temp1->component_type_
        __ movl(temp2, Address(temp1, component_offset));
        __ testl(temp2, temp2);
        __ j(kEqual, intrinsic_slow_path->GetEntryLabel());
        __ MaybeUnpoisonHeapReference(temp2);
        __ cmpw(Address(temp2, primitive_offset), Immediate(Primitive::kPrimNot));
        __ j(kNotEqual, intrinsic_slow_path->GetEntryLabel());
        // Re-poison the heap reference to make the compare instruction below
        // compare two poisoned references.
        __ PoisonHeapReference(temp1);
      }

      // Note: if heap poisoning is on, we are comparing two poisoned references here.
      __ cmpl(temp1, Address(src, class_offset));

      if (optimizations.GetDestinationIsTypedObjectArray()) {
        NearLabel do_copy;
        __ j(kEqual, &do_copy);
        __ MaybeUnpoisonHeapReference(temp1);
        // /* HeapReference<Class> */ temp1 = temp1->component_type_
        __ movl(temp1, Address(temp1, component_offset));
        __ MaybeUnpoisonHeapReference(temp1);
        __ cmpl(Address(temp1, super_offset), Immediate(0));
        __ j(kNotEqual, intrinsic_slow_path->GetEntryLabel());
        __ Bind(&do_copy);
      } else {
        __ j(kNotEqual, intrinsic_slow_path->GetEntryLabel());
      }
    }
  } else if (!optimizations.GetSourceIsNonPrimitiveArray()) {
    DCHECK(optimizations.GetDestinationIsNonPrimitiveArray());
    // Bail out if the source is not a non primitive array.
    if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
      // /* HeapReference<Class> */ temp1 = src->klass_
      codegen_->GenerateFieldLoadWithBakerReadBarrier(
          invoke, temp1_loc, src, class_offset, /* needs_null_check= */ false);
      // /* HeapReference<Class> */ temp1 = temp1->component_type_
      codegen_->GenerateFieldLoadWithBakerReadBarrier(
          invoke, temp1_loc, temp1, component_offset, /* needs_null_check= */ false);
      __ testl(temp1, temp1);
      __ j(kEqual, intrinsic_slow_path->GetEntryLabel());
      // If heap poisoning is enabled, `temp1` has been unpoisoned
      // by the the previous call to GenerateFieldLoadWithBakerReadBarrier.
    } else {
      // /* HeapReference<Class> */ temp1 = src->klass_
      __ movl(temp1, Address(src, class_offset));
      __ MaybeUnpoisonHeapReference(temp1);
      // /* HeapReference<Class> */ temp1 = temp1->component_type_
      __ movl(temp1, Address(temp1, component_offset));
      __ testl(temp1, temp1);
      __ j(kEqual, intrinsic_slow_path->GetEntryLabel());
      __ MaybeUnpoisonHeapReference(temp1);
    }
    __ cmpw(Address(temp1, primitive_offset), Immediate(Primitive::kPrimNot));
    __ j(kNotEqual, intrinsic_slow_path->GetEntryLabel());
  }

  const DataType::Type type = DataType::Type::kReference;
  const int32_t element_size = DataType::Size(type);

  // Compute the base source address in `temp1`.
  GenSystemArrayCopyBaseAddress(GetAssembler(), type, src, src_pos, temp1);

  if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
    // If it is needed (in the case of the fast-path loop), the base
    // destination address is computed later, as `temp2` is used for
    // intermediate computations.

    // Compute the end source address in `temp3`.
    if (length.IsStackSlot()) {
      // Location `length` is again pointing at a stack slot, as
      // register `temp3` (which was containing the length parameter
      // earlier) has been overwritten; restore it now
      DCHECK(length.Equals(length_arg));
      __ movl(temp3, Address(ESP, length.GetStackIndex()));
      length = Location::RegisterLocation(temp3);
    }
    GenSystemArrayCopyEndAddress(GetAssembler(), type, length, temp1, temp3);

    // SystemArrayCopy implementation for Baker read barriers (see
    // also CodeGeneratorX86::GenerateReferenceLoadWithBakerReadBarrier):
    //
    //   if (src_ptr != end_ptr) {
    //     uint32_t rb_state = Lockword(src->monitor_).ReadBarrierState();
    //     lfence;  // Load fence or artificial data dependency to prevent load-load reordering
    //     bool is_gray = (rb_state == ReadBarrier::GrayState());
    //     if (is_gray) {
    //       // Slow-path copy.
    //       for (size_t i = 0; i != length; ++i) {
    //         dest_array[dest_pos + i] =
    //             MaybePoison(ReadBarrier::Mark(MaybeUnpoison(src_array[src_pos + i])));
    //       }
    //     } else {
    //       // Fast-path copy.
    //       do {
    //         *dest_ptr++ = *src_ptr++;
    //       } while (src_ptr != end_ptr)
    //     }
    //   }

    NearLabel loop, done;

    // Don't enter copy loop if `length == 0`.
    __ cmpl(temp1, temp3);
    __ j(kEqual, &done);

    // Given the numeric representation, it's enough to check the low bit of the rb_state.
    static_assert(ReadBarrier::NonGrayState() == 0, "Expecting non-gray to have value 0");
    static_assert(ReadBarrier::GrayState() == 1, "Expecting gray to have value 1");
    constexpr uint32_t gray_byte_position = LockWord::kReadBarrierStateShift / kBitsPerByte;
    constexpr uint32_t gray_bit_position = LockWord::kReadBarrierStateShift % kBitsPerByte;
    constexpr int32_t test_value = static_cast<int8_t>(1 << gray_bit_position);

    // if (rb_state == ReadBarrier::GrayState())
    //   goto slow_path;
    // At this point, just do the "if" and make sure that flags are preserved until the branch.
    __ testb(Address(src, monitor_offset + gray_byte_position), Immediate(test_value));

    // Load fence to prevent load-load reordering.
    // Note that this is a no-op, thanks to the x86 memory model.
    codegen_->GenerateMemoryBarrier(MemBarrierKind::kLoadAny);

    // Slow path used to copy array when `src` is gray.
    SlowPathCode* read_barrier_slow_path =
        new (codegen_->GetScopedAllocator()) ReadBarrierSystemArrayCopySlowPathX86(invoke);
    codegen_->AddSlowPath(read_barrier_slow_path);

    // We have done the "if" of the gray bit check above, now branch based on the flags.
    __ j(kNotZero, read_barrier_slow_path->GetEntryLabel());

    // Fast-path copy.
    // Compute the base destination address in `temp2`.
    GenSystemArrayCopyBaseAddress(GetAssembler(), type, dest, dest_pos, temp2);
    // Iterate over the arrays and do a raw copy of the objects. We don't need to
    // poison/unpoison.
    __ Bind(&loop);
    __ pushl(Address(temp1, 0));
    __ cfi().AdjustCFAOffset(4);
    __ popl(Address(temp2, 0));
    __ cfi().AdjustCFAOffset(-4);
    __ addl(temp1, Immediate(element_size));
    __ addl(temp2, Immediate(element_size));
    __ cmpl(temp1, temp3);
    __ j(kNotEqual, &loop);

    __ Bind(read_barrier_slow_path->GetExitLabel());
    __ Bind(&done);
  } else {
    // Non read barrier code.
    // Compute the base destination address in `temp2`.
    GenSystemArrayCopyBaseAddress(GetAssembler(), type, dest, dest_pos, temp2);
    // Compute the end source address in `temp3`.
    GenSystemArrayCopyEndAddress(GetAssembler(), type, length, temp1, temp3);
    // Iterate over the arrays and do a raw copy of the objects. We don't need to
    // poison/unpoison.
    NearLabel loop, done;
    __ cmpl(temp1, temp3);
    __ j(kEqual, &done);
    __ Bind(&loop);
    __ pushl(Address(temp1, 0));
    __ cfi().AdjustCFAOffset(4);
    __ popl(Address(temp2, 0));
    __ cfi().AdjustCFAOffset(-4);
    __ addl(temp1, Immediate(element_size));
    __ addl(temp2, Immediate(element_size));
    __ cmpl(temp1, temp3);
    __ j(kNotEqual, &loop);
    __ Bind(&done);
  }

  // We only need one card marking on the destination array.
  codegen_->MarkGCCard(temp1, temp2, dest, Register(kNoRegister), /* value_can_be_null= */ false);

  __ Bind(intrinsic_slow_path->GetExitLabel());
}

static void RequestBaseMethodAddressInRegister(HInvoke* invoke) {
  LocationSummary* locations = invoke->GetLocations();
  if (locations != nullptr) {
    HInvokeStaticOrDirect* invoke_static_or_direct = invoke->AsInvokeStaticOrDirect();
    // Note: The base method address is not present yet when this is called from the
    // PCRelativeHandlerVisitor via IsCallFreeIntrinsic() to determine whether to insert it.
    if (invoke_static_or_direct->HasSpecialInput()) {
      DCHECK(invoke_static_or_direct->InputAt(invoke_static_or_direct->GetSpecialInputIndex())
                 ->IsX86ComputeBaseMethodAddress());
      locations->SetInAt(invoke_static_or_direct->GetSpecialInputIndex(),
                         Location::RequiresRegister());
    }
  }
}

void IntrinsicLocationsBuilderX86::VisitIntegerValueOf(HInvoke* invoke) {
  DCHECK(invoke->IsInvokeStaticOrDirect());
  InvokeRuntimeCallingConvention calling_convention;
  IntrinsicVisitor::ComputeIntegerValueOfLocations(
      invoke,
      codegen_,
      Location::RegisterLocation(EAX),
      Location::RegisterLocation(calling_convention.GetRegisterAt(0)));
  RequestBaseMethodAddressInRegister(invoke);
}

void IntrinsicCodeGeneratorX86::VisitIntegerValueOf(HInvoke* invoke) {
  DCHECK(invoke->IsInvokeStaticOrDirect());
  IntrinsicVisitor::IntegerValueOfInfo info =
      IntrinsicVisitor::ComputeIntegerValueOfInfo(invoke, codegen_->GetCompilerOptions());
  LocationSummary* locations = invoke->GetLocations();
  X86Assembler* assembler = GetAssembler();

  Register out = locations->Out().AsRegister<Register>();
  auto allocate_instance = [&]() {
    DCHECK_EQ(out, InvokeRuntimeCallingConvention().GetRegisterAt(0));
    codegen_->LoadIntrinsicDeclaringClass(out, invoke->AsInvokeStaticOrDirect());
    codegen_->InvokeRuntime(kQuickAllocObjectInitialized, invoke, invoke->GetDexPc());
    CheckEntrypointTypes<kQuickAllocObjectWithChecks, void*, mirror::Class*>();
  };
  if (invoke->InputAt(0)->IsConstant()) {
    int32_t value = invoke->InputAt(0)->AsIntConstant()->GetValue();
    if (static_cast<uint32_t>(value - info.low) < info.length) {
      // Just embed the j.l.Integer in the code.
      DCHECK_NE(info.value_boot_image_reference, IntegerValueOfInfo::kInvalidReference);
      codegen_->LoadBootImageAddress(
          out, info.value_boot_image_reference, invoke->AsInvokeStaticOrDirect());
    } else {
      DCHECK(locations->CanCall());
      // Allocate and initialize a new j.l.Integer.
      // TODO: If we JIT, we could allocate the j.l.Integer now, and store it in the
      // JIT object table.
      allocate_instance();
      __ movl(Address(out, info.value_offset), Immediate(value));
    }
  } else {
    DCHECK(locations->CanCall());
    Register in = locations->InAt(0).AsRegister<Register>();
    // Check bounds of our cache.
    __ leal(out, Address(in, -info.low));
    __ cmpl(out, Immediate(info.length));
    NearLabel allocate, done;
    __ j(kAboveEqual, &allocate);
    // If the value is within the bounds, load the j.l.Integer directly from the array.
    constexpr size_t kElementSize = sizeof(mirror::HeapReference<mirror::Object>);
    static_assert((1u << TIMES_4) == sizeof(mirror::HeapReference<mirror::Object>),
                  "Check heap reference size.");
    if (codegen_->GetCompilerOptions().IsBootImage()) {
      DCHECK_EQ(invoke->InputCount(), invoke->GetNumberOfArguments() + 1u);
      size_t method_address_index = invoke->AsInvokeStaticOrDirect()->GetSpecialInputIndex();
      HX86ComputeBaseMethodAddress* method_address =
          invoke->InputAt(method_address_index)->AsX86ComputeBaseMethodAddress();
      DCHECK(method_address != nullptr);
      Register method_address_reg =
          invoke->GetLocations()->InAt(method_address_index).AsRegister<Register>();
      __ movl(out,
              Address(method_address_reg, out, TIMES_4, CodeGeneratorX86::kPlaceholder32BitOffset));
      codegen_->RecordBootImageIntrinsicPatch(method_address, info.array_data_boot_image_reference);
    } else {
      // Note: We're about to clobber the index in `out`, so we need to use `in` and
      // adjust the offset accordingly.
      uint32_t mid_array_boot_image_offset =
              info.array_data_boot_image_reference - info.low * kElementSize;
      codegen_->LoadBootImageAddress(
          out, mid_array_boot_image_offset, invoke->AsInvokeStaticOrDirect());
      DCHECK_NE(out, in);
      __ movl(out, Address(out, in, TIMES_4, 0));
    }
    __ MaybeUnpoisonHeapReference(out);
    __ jmp(&done);
    __ Bind(&allocate);
    // Otherwise allocate and initialize a new j.l.Integer.
    allocate_instance();
    __ movl(Address(out, info.value_offset), in);
    __ Bind(&done);
  }
}

void IntrinsicLocationsBuilderX86::VisitReferenceGetReferent(HInvoke* invoke) {
  IntrinsicVisitor::CreateReferenceGetReferentLocations(invoke, codegen_);
  RequestBaseMethodAddressInRegister(invoke);
}

void IntrinsicCodeGeneratorX86::VisitReferenceGetReferent(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Location obj = locations->InAt(0);
  Location out = locations->Out();

  SlowPathCode* slow_path = new (GetAllocator()) IntrinsicSlowPathX86(invoke);
  codegen_->AddSlowPath(slow_path);

  if (kEmitCompilerReadBarrier) {
    // Check self->GetWeakRefAccessEnabled().
    ThreadOffset32 offset = Thread::WeakRefAccessEnabledOffset<kX86PointerSize>();
    __ fs()->cmpl(Address::Absolute(offset), Immediate(0));
    __ j(kEqual, slow_path->GetEntryLabel());
  }

  // Load the java.lang.ref.Reference class, use the output register as a temporary.
  codegen_->LoadIntrinsicDeclaringClass(out.AsRegister<Register>(),
                                        invoke->AsInvokeStaticOrDirect());

  // Check static fields java.lang.ref.Reference.{disableIntrinsic,slowPathEnabled} together.
  MemberOffset disable_intrinsic_offset = IntrinsicVisitor::GetReferenceDisableIntrinsicOffset();
  DCHECK_ALIGNED(disable_intrinsic_offset.Uint32Value(), 2u);
  DCHECK_EQ(disable_intrinsic_offset.Uint32Value() + 1u,
            IntrinsicVisitor::GetReferenceSlowPathEnabledOffset().Uint32Value());
  __ cmpw(Address(out.AsRegister<Register>(), disable_intrinsic_offset.Uint32Value()),
          Immediate(0));
  __ j(kNotEqual, slow_path->GetEntryLabel());

  // Load the value from the field.
  uint32_t referent_offset = mirror::Reference::ReferentOffset().Uint32Value();
  if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
    codegen_->GenerateFieldLoadWithBakerReadBarrier(invoke,
                                                    out,
                                                    obj.AsRegister<Register>(),
                                                    referent_offset,
                                                    /*needs_null_check=*/ true);
    // Note that the fence is a no-op, thanks to the x86 memory model.
    codegen_->GenerateMemoryBarrier(MemBarrierKind::kLoadAny);  // `referent` is volatile.
  } else {
    __ movl(out.AsRegister<Register>(), Address(obj.AsRegister<Register>(), referent_offset));
    codegen_->MaybeRecordImplicitNullCheck(invoke);
    // Note that the fence is a no-op, thanks to the x86 memory model.
    codegen_->GenerateMemoryBarrier(MemBarrierKind::kLoadAny);  // `referent` is volatile.
    codegen_->MaybeGenerateReadBarrierSlow(invoke, out, out, obj, referent_offset);
  }
  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitReferenceRefersTo(HInvoke* invoke) {
  IntrinsicVisitor::CreateReferenceRefersToLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitReferenceRefersTo(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();

  Register obj = locations->InAt(0).AsRegister<Register>();
  Register other = locations->InAt(1).AsRegister<Register>();
  Register out = locations->Out().AsRegister<Register>();

  uint32_t referent_offset = mirror::Reference::ReferentOffset().Uint32Value();
  uint32_t monitor_offset = mirror::Object::MonitorOffset().Int32Value();

  __ movl(out, Address(obj, referent_offset));
  codegen_->MaybeRecordImplicitNullCheck(invoke);
  __ MaybeUnpoisonHeapReference(out);
  // Note that the fence is a no-op, thanks to the x86 memory model.
  codegen_->GenerateMemoryBarrier(MemBarrierKind::kLoadAny);  // `referent` is volatile.

  NearLabel end, return_true, return_false;
  __ cmpl(out, other);

  if (kEmitCompilerReadBarrier) {
    DCHECK(kUseBakerReadBarrier);

    __ j(kEqual, &return_true);

    // Check if the loaded reference is null.
    __ testl(out, out);
    __ j(kZero, &return_false);

    // For correct memory visibility, we need a barrier before loading the lock word
    // but we already have the barrier emitted for volatile load above which is sufficient.

    // Load the lockword and check if it is a forwarding address.
    static_assert(LockWord::kStateShift == 30u);
    static_assert(LockWord::kStateForwardingAddress == 3u);
    __ movl(out, Address(out, monitor_offset));
    __ cmpl(out, Immediate(static_cast<int32_t>(0xc0000000)));
    __ j(kBelow, &return_false);

    // Extract the forwarding address and compare with `other`.
    __ shll(out, Immediate(LockWord::kForwardingAddressShift));
    __ cmpl(out, other);
  }

  __ j(kNotEqual, &return_false);

  // Return true and exit the function.
  __ Bind(&return_true);
  __ movl(out, Immediate(1));
  __ jmp(&end);

  // Return false and exit the function.
  __ Bind(&return_false);
  __ xorl(out, out);
  __ Bind(&end);
}

void IntrinsicLocationsBuilderX86::VisitThreadInterrupted(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetOut(Location::RequiresRegister());
}

void IntrinsicCodeGeneratorX86::VisitThreadInterrupted(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  Register out = invoke->GetLocations()->Out().AsRegister<Register>();
  Address address = Address::Absolute(Thread::InterruptedOffset<kX86PointerSize>().Int32Value());
  NearLabel done;
  __ fs()->movl(out, address);
  __ testl(out, out);
  __ j(kEqual, &done);
  __ fs()->movl(address, Immediate(0));
  codegen_->MemoryFence();
  __ Bind(&done);
}

void IntrinsicLocationsBuilderX86::VisitReachabilityFence(HInvoke* invoke) {
  LocationSummary* locations =
      new (allocator_) LocationSummary(invoke, LocationSummary::kNoCall, kIntrinsified);
  locations->SetInAt(0, Location::Any());
}

void IntrinsicCodeGeneratorX86::VisitReachabilityFence(HInvoke* invoke ATTRIBUTE_UNUSED) { }

void IntrinsicLocationsBuilderX86::VisitIntegerDivideUnsigned(HInvoke* invoke) {
  LocationSummary* locations = new (allocator_) LocationSummary(invoke,
                                                                LocationSummary::kCallOnSlowPath,
                                                                kIntrinsified);
  locations->SetInAt(0, Location::RegisterLocation(EAX));
  locations->SetInAt(1, Location::RequiresRegister());
  locations->SetOut(Location::SameAsFirstInput());
  // Intel uses edx:eax as the dividend.
  locations->AddTemp(Location::RegisterLocation(EDX));
}

void IntrinsicCodeGeneratorX86::VisitIntegerDivideUnsigned(HInvoke* invoke) {
  X86Assembler* assembler = GetAssembler();
  LocationSummary* locations = invoke->GetLocations();
  Location out = locations->Out();
  Location first = locations->InAt(0);
  Location second = locations->InAt(1);
  Register edx = locations->GetTemp(0).AsRegister<Register>();
  Register second_reg = second.AsRegister<Register>();

  DCHECK_EQ(EAX, first.AsRegister<Register>());
  DCHECK_EQ(EAX, out.AsRegister<Register>());
  DCHECK_EQ(EDX, edx);

  // Check if divisor is zero, bail to managed implementation to handle.
  __ testl(second_reg, second_reg);
  SlowPathCode* slow_path = new (codegen_->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen_->AddSlowPath(slow_path);
  __ j(kEqual, slow_path->GetEntryLabel());

  __ xorl(edx, edx);
  __ divl(second_reg);

  __ Bind(slow_path->GetExitLabel());
}

static bool IsValidFieldVarHandleExpected(HInvoke* invoke) {
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  if (expected_coordinates_count > 1u) {
    // Only static and instance fields VarHandle are supported now.
    return false;
  }

  if (expected_coordinates_count == 1u &&
      invoke->InputAt(1)->GetType() != DataType::Type::kReference) {
    // For instance fields, the source object must be a reference
    return false;
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
  }

  return true;
}

static void GenerateVarHandleAccessModeCheck(Register varhandle_object,
                                             mirror::VarHandle::AccessMode access_mode,
                                             SlowPathCode* slow_path,
                                             X86Assembler* assembler) {
  const uint32_t access_modes_bitmask_offset =
      mirror::VarHandle::AccessModesBitMaskOffset().Uint32Value();
  const uint32_t access_mode_bit = 1u << static_cast<uint32_t>(access_mode);

  // If the access mode is not supported, bail to runtime implementation to handle
  __ testl(Address(varhandle_object, access_modes_bitmask_offset), Immediate(access_mode_bit));
  __ j(kZero, slow_path->GetEntryLabel());
}

static void GenerateVarHandleStaticFieldCheck(Register varhandle_object,
                                              SlowPathCode* slow_path,
                                              X86Assembler* assembler) {
  const uint32_t coordtype0_offset = mirror::VarHandle::CoordinateType0Offset().Uint32Value();

  // Check that the VarHandle references a static field by checking that coordinateType0 == null.
  // Do not emit read barrier (or unpoison the reference) for comparing to null.
  __ cmpl(Address(varhandle_object, coordtype0_offset), Immediate(0));
  __ j(kNotEqual, slow_path->GetEntryLabel());
}

static void GenerateSubTypeObjectCheck(Register object,
                                       Register temp,
                                       Address type_address,
                                       SlowPathCode* slow_path,
                                       X86Assembler* assembler,
                                       bool object_can_be_null = true) {
  const uint32_t class_offset = mirror::Object::ClassOffset().Uint32Value();
  const uint32_t super_class_offset = mirror::Class::SuperClassOffset().Uint32Value();
  NearLabel check_type_compatibility, type_matched;

  // If the object is null, there is no need to check the type
  if (object_can_be_null) {
    __ testl(object, object);
    __ j(kZero, &type_matched);
  }

  // Do not unpoison for in-memory comparison.
  // We deliberately avoid the read barrier, letting the slow path handle the false negatives.
  __ movl(temp, Address(object, class_offset));
  __ Bind(&check_type_compatibility);
  __ cmpl(temp, type_address);
  __ j(kEqual, &type_matched);
  // Load the super class.
  __ MaybeUnpoisonHeapReference(temp);
  __ movl(temp, Address(temp, super_class_offset));
  // If the super class is null, we reached the root of the hierarchy without a match.
  // We let the slow path handle uncovered cases (e.g. interfaces).
  __ testl(temp, temp);
  __ j(kEqual, slow_path->GetEntryLabel());
  __ jmp(&check_type_compatibility);
  __ Bind(&type_matched);
}

static void GenerateVarHandleInstanceFieldObjectCheck(Register varhandle_object,
                                                      Register object,
                                                      Register temp,
                                                      SlowPathCode* slow_path,
                                                      X86Assembler* assembler) {
  const uint32_t coordtype0_offset = mirror::VarHandle::CoordinateType0Offset().Uint32Value();
  const uint32_t coordtype1_offset = mirror::VarHandle::CoordinateType1Offset().Uint32Value();

  // Check that the VarHandle references an instance field by checking that
  // coordinateType1 == null. coordinateType0 should be not null, but this is handled by the
  // type compatibility check with the source object's type, which will fail for null.
  __ cmpl(Address(varhandle_object, coordtype1_offset), Immediate(0));
  __ j(kNotEqual, slow_path->GetEntryLabel());

  // Check if the object is null
  __ testl(object, object);
  __ j(kZero, slow_path->GetEntryLabel());

  // Check the object's class against coordinateType0.
  GenerateSubTypeObjectCheck(object,
                             temp,
                             Address(varhandle_object, coordtype0_offset),
                             slow_path,
                             assembler,
                             /* object_can_be_null= */ false);
}

static void GenerateVarTypePrimitiveTypeCheck(Register varhandle_object,
                                              Register temp,
                                              DataType::Type type,
                                              SlowPathCode* slow_path,
                                              X86Assembler* assembler) {
  const uint32_t var_type_offset = mirror::VarHandle::VarTypeOffset().Uint32Value();
  const uint32_t primitive_type_offset = mirror::Class::PrimitiveTypeOffset().Uint32Value();
  const uint32_t primitive_type = static_cast<uint32_t>(DataTypeToPrimitive(type));

  // We do not need a read barrier when loading a reference only for loading a constant field
  // through the reference.
  __ movl(temp, Address(varhandle_object, var_type_offset));
  __ MaybeUnpoisonHeapReference(temp);
  __ cmpw(Address(temp, primitive_type_offset), Immediate(primitive_type));
  __ j(kNotEqual, slow_path->GetEntryLabel());
}

static void GenerateVarHandleCommonChecks(HInvoke *invoke,
                                          Register temp,
                                          SlowPathCode* slow_path,
                                          X86Assembler* assembler) {
  LocationSummary* locations = invoke->GetLocations();
  Register vh_object = locations->InAt(0).AsRegister<Register>();
  mirror::VarHandle::AccessMode access_mode =
      mirror::VarHandle::GetAccessModeByIntrinsic(invoke->GetIntrinsic());

  GenerateVarHandleAccessModeCheck(vh_object,
                                   access_mode,
                                   slow_path,
                                   assembler);

  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  switch (expected_coordinates_count) {
    case 0u:
      GenerateVarHandleStaticFieldCheck(vh_object, slow_path, assembler);
      break;
    case 1u: {
      Register object = locations->InAt(1).AsRegister<Register>();
      GenerateVarHandleInstanceFieldObjectCheck(vh_object, object, temp, slow_path, assembler);
      break;
    }
    default:
      // Unimplemented
      UNREACHABLE();
  }

  // Check the return type and varType parameters.
  mirror::VarHandle::AccessModeTemplate access_mode_template =
      mirror::VarHandle::GetAccessModeTemplate(access_mode);
  DataType::Type type = invoke->GetType();

  switch (access_mode_template) {
    case mirror::VarHandle::AccessModeTemplate::kGet:
      // Check the varType.primitiveType against the type we're trying to retrieve. Reference types
      // are also checked later by a HCheckCast node as an additional check.
      GenerateVarTypePrimitiveTypeCheck(vh_object, temp, type, slow_path, assembler);
      break;
    case mirror::VarHandle::AccessModeTemplate::kSet:
    case mirror::VarHandle::AccessModeTemplate::kGetAndUpdate: {
      uint32_t value_index = invoke->GetNumberOfArguments() - 1;
      DataType::Type value_type = GetDataTypeFromShorty(invoke, value_index);

      // Check the varType.primitiveType against the type of the value we're trying to set.
      GenerateVarTypePrimitiveTypeCheck(vh_object, temp, value_type, slow_path, assembler);
      if (value_type == DataType::Type::kReference) {
        const uint32_t var_type_offset = mirror::VarHandle::VarTypeOffset().Uint32Value();

        // If the value type is a reference, check it against the varType.
        GenerateSubTypeObjectCheck(locations->InAt(value_index).AsRegister<Register>(),
                                   temp,
                                   Address(vh_object, var_type_offset),
                                   slow_path,
                                   assembler);
      }
      break;
    }
    case mirror::VarHandle::AccessModeTemplate::kCompareAndSet:
    case mirror::VarHandle::AccessModeTemplate::kCompareAndExchange: {
      uint32_t new_value_index = invoke->GetNumberOfArguments() - 1;
      uint32_t expected_value_index = invoke->GetNumberOfArguments() - 2;
      DataType::Type value_type = GetDataTypeFromShorty(invoke, new_value_index);
      DCHECK_EQ(value_type, GetDataTypeFromShorty(invoke, expected_value_index));

      // Check the varType.primitiveType against the type of the expected value.
      GenerateVarTypePrimitiveTypeCheck(vh_object, temp, value_type, slow_path, assembler);
      if (value_type == DataType::Type::kReference) {
        const uint32_t var_type_offset = mirror::VarHandle::VarTypeOffset().Uint32Value();

        // If the value type is a reference, check both the expected and the new value against
        // the varType.
        GenerateSubTypeObjectCheck(locations->InAt(new_value_index).AsRegister<Register>(),
                                   temp,
                                   Address(vh_object, var_type_offset),
                                   slow_path,
                                   assembler);
        GenerateSubTypeObjectCheck(locations->InAt(expected_value_index).AsRegister<Register>(),
                                   temp,
                                   Address(vh_object, var_type_offset),
                                   slow_path,
                                   assembler);
      }
      break;
    }
  }
}

// This method loads the field's address referred by a field VarHandle (base + offset).
// The return value is the register containing object's reference (in case of an instance field)
// or the declaring class (in case of a static field). The declaring class is stored in temp
// register. Field's offset is loaded to the `offset` register.
static Register GenerateVarHandleFieldReference(HInvoke* invoke,
                                                CodeGeneratorX86* codegen,
                                                Register temp,
                                                /*out*/ Register offset) {
  X86Assembler* assembler = codegen->GetAssembler();
  LocationSummary* locations = invoke->GetLocations();
  const uint32_t artfield_offset = mirror::FieldVarHandle::ArtFieldOffset().Uint32Value();
  const uint32_t offset_offset = ArtField::OffsetOffset().Uint32Value();
  const uint32_t declaring_class_offset = ArtField::DeclaringClassOffset().Uint32Value();
  Register varhandle_object = locations->InAt(0).AsRegister<Register>();

  // Load the ArtField and the offset
  __ movl(temp, Address(varhandle_object, artfield_offset));
  __ movl(offset, Address(temp, offset_offset));
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  if (expected_coordinates_count == 0) {
    // For static fields, load the declaring class
    InstructionCodeGeneratorX86* instr_codegen =
        down_cast<InstructionCodeGeneratorX86*>(codegen->GetInstructionVisitor());
    instr_codegen->GenerateGcRootFieldLoad(invoke,
                                           Location::RegisterLocation(temp),
                                           Address(temp, declaring_class_offset),
                                           /* fixup_label= */ nullptr,
                                           kCompilerReadBarrierOption);
    return temp;
  }

  // For instance fields, return the register containing the object.
  DCHECK_EQ(expected_coordinates_count, 1u);

  return locations->InAt(1).AsRegister<Register>();
}

static void CreateVarHandleGetLocations(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  if (!IsValidFieldVarHandleExpected(invoke)) {
    return;
  }

  ArenaAllocator* allocator = invoke->GetBlock()->GetGraph()->GetAllocator();
  LocationSummary* locations = new (allocator) LocationSummary(
      invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  if (expected_coordinates_count == 1u) {
    // For instance fields, this is the source object.
    locations->SetInAt(1, Location::RequiresRegister());
  }
  locations->AddTemp(Location::RequiresRegister());

  DataType::Type type = invoke->GetType();
  switch (DataType::Kind(type)) {
    case DataType::Type::kInt64:
      locations->AddTemp(Location::RequiresRegister());
      if (invoke->GetIntrinsic() != Intrinsics::kVarHandleGet) {
        // We need an XmmRegister for Int64 to ensure an atomic load
        locations->AddTemp(Location::RequiresFpuRegister());
      }
      FALLTHROUGH_INTENDED;
    case DataType::Type::kInt32:
    case DataType::Type::kReference:
      locations->SetOut(Location::RequiresRegister());
      break;
    default:
      DCHECK(DataType::IsFloatingPointType(type));
      locations->AddTemp(Location::RequiresRegister());
      locations->SetOut(Location::RequiresFpuRegister());
  }
}

static void GenerateVarHandleGet(HInvoke* invoke, CodeGeneratorX86* codegen) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

  X86Assembler* assembler = codegen->GetAssembler();
  LocationSummary* locations = invoke->GetLocations();
  DataType::Type type = invoke->GetType();
  DCHECK_NE(type, DataType::Type::kVoid);
  Register temp = locations->GetTemp(0).AsRegister<Register>();
  SlowPathCode* slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen->AddSlowPath(slow_path);

  GenerateVarHandleCommonChecks(invoke, temp, slow_path, assembler);

  Location out = locations->Out();
  // Use 'out' as a temporary register if it's a core register
  Register offset =
      out.IsRegister() ? out.AsRegister<Register>() : locations->GetTemp(1).AsRegister<Register>();

  // Get the field referred by the VarHandle. The returned register contains the object reference
  // or the declaring class. The field offset will be placed in 'offset'. For static fields, the
  // declaring class will be placed in 'temp' register.
  Register ref = GenerateVarHandleFieldReference(invoke, codegen, temp, offset);
  Address field_addr(ref, offset, TIMES_1, 0);

  // Load the value from the field
  if (type == DataType::Type::kReference && kCompilerReadBarrierOption == kWithReadBarrier) {
    codegen->GenerateReferenceLoadWithBakerReadBarrier(
        invoke, out, ref, field_addr, /* needs_null_check= */ false);
  } else if (type == DataType::Type::kInt64 &&
             invoke->GetIntrinsic() != Intrinsics::kVarHandleGet) {
    XmmRegister xmm_temp = locations->GetTemp(2).AsFpuRegister<XmmRegister>();
    codegen->LoadFromMemoryNoBarrier(type, out, field_addr, xmm_temp, /* is_atomic_load= */ true);
  } else {
    codegen->LoadFromMemoryNoBarrier(type, out, field_addr);
  }

  if (invoke->GetIntrinsic() == Intrinsics::kVarHandleGetVolatile ||
      invoke->GetIntrinsic() == Intrinsics::kVarHandleGetAcquire) {
    // Load fence to prevent load-load reordering.
    // Note that this is a no-op, thanks to the x86 memory model.
    codegen->GenerateMemoryBarrier(MemBarrierKind::kLoadAny);
  }

  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGet(HInvoke* invoke) {
  CreateVarHandleGetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGet(HInvoke* invoke) {
  GenerateVarHandleGet(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetVolatile(HInvoke* invoke) {
  CreateVarHandleGetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetVolatile(HInvoke* invoke) {
  GenerateVarHandleGet(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAcquire(HInvoke* invoke) {
  CreateVarHandleGetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAcquire(HInvoke* invoke) {
  GenerateVarHandleGet(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetOpaque(HInvoke* invoke) {
  CreateVarHandleGetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetOpaque(HInvoke* invoke) {
  GenerateVarHandleGet(invoke, codegen_);
}

static void CreateVarHandleSetLocations(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  if (!IsValidFieldVarHandleExpected(invoke)) {
    return;
  }

  // The last argument should be the value we intend to set.
  uint32_t value_index = invoke->GetNumberOfArguments() - 1;
  HInstruction* value = invoke->InputAt(value_index);
  DataType::Type value_type = GetDataTypeFromShorty(invoke, value_index);
  bool needs_atomicity = invoke->GetIntrinsic() != Intrinsics::kVarHandleSet;
  if (value_type == DataType::Type::kInt64 && (!value->IsConstant() || needs_atomicity)) {
    // We avoid the case of a non-constant (or volatile) Int64 value because we would need to
    // place it in a register pair. If the slow path is taken, the ParallelMove might fail to move
    // the pair according to the X86DexCallingConvention in case of an overlap (e.g., move the
    // int64 value from <EAX, EBX> to <EBX, ECX>). (Bug: b/168687887)
    return;
  }

  ArenaAllocator* allocator = invoke->GetBlock()->GetGraph()->GetAllocator();
  LocationSummary* locations = new (allocator) LocationSummary(
      invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  locations->SetInAt(0, Location::RequiresRegister());
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  if (expected_coordinates_count == 1u) {
    // For instance fields, this is the source object
    locations->SetInAt(1, Location::RequiresRegister());
  }

  switch (value_type) {
    case DataType::Type::kBool:
    case DataType::Type::kInt8:
    case DataType::Type::kUint8:
      // Ensure the value is in a byte register
      locations->SetInAt(value_index, Location::ByteRegisterOrConstant(EBX, value));
      break;
    case DataType::Type::kInt16:
    case DataType::Type::kUint16:
    case DataType::Type::kInt32:
      locations->SetInAt(value_index, Location::RegisterOrConstant(value));
      break;
    case DataType::Type::kInt64:
      // We only handle constant non-atomic int64 values.
      DCHECK(value->IsConstant());
      locations->SetInAt(value_index, Location::ConstantLocation(value->AsConstant()));
      break;
    case DataType::Type::kReference:
      locations->SetInAt(value_index, Location::RequiresRegister());
      break;
    default:
      DCHECK(DataType::IsFloatingPointType(value_type));
      if (needs_atomicity && value_type == DataType::Type::kFloat64) {
        locations->SetInAt(value_index, Location::RequiresFpuRegister());
      } else {
        locations->SetInAt(value_index, Location::FpuRegisterOrConstant(value));
      }
  }

  locations->AddTemp(Location::RequiresRegister());
  // This temporary register is also used for card for MarkGCCard. Make sure it's a byte register
  locations->AddTemp(Location::RegisterLocation(EAX));
  if (expected_coordinates_count == 0 && value_type == DataType::Type::kReference) {
    // For static reference fields, we need another temporary for the declaring class. We set it
    // last because we want to make sure that the first 2 temps are reserved for HandleFieldSet.
    locations->AddTemp(Location::RequiresRegister());
  }
}

static void GenerateVarHandleSet(HInvoke* invoke, CodeGeneratorX86* codegen) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

  X86Assembler* assembler = codegen->GetAssembler();
  LocationSummary* locations = invoke->GetLocations();
  // The value we want to set is the last argument
  uint32_t value_index = invoke->GetNumberOfArguments() - 1;
  DataType::Type value_type = GetDataTypeFromShorty(invoke, value_index);
  Register temp = locations->GetTemp(0).AsRegister<Register>();
  Register temp2 = locations->GetTemp(1).AsRegister<Register>();
  SlowPathCode* slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen->AddSlowPath(slow_path);

  GenerateVarHandleCommonChecks(invoke, temp, slow_path, assembler);

  // For static reference fields, we need another temporary for the declaring class. But since
  // for instance fields the object is in a separate register, it is safe to use the first
  // temporary register for GenerateVarHandleFieldReference.
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  if (value_type == DataType::Type::kReference && expected_coordinates_count == 0) {
    temp = locations->GetTemp(2).AsRegister<Register>();
  }

  Register offset = temp2;
  // Get the field referred by the VarHandle. The returned register contains the object reference
  // or the declaring class. The field offset will be placed in 'offset'. For static fields, the
  // declaring class will be placed in 'temp' register.
  Register reference = GenerateVarHandleFieldReference(invoke, codegen, temp, offset);

  bool is_volatile = false;
  switch (invoke->GetIntrinsic()) {
    case Intrinsics::kVarHandleSet:
    case Intrinsics::kVarHandleSetOpaque:
      // The only constraint for setOpaque is to ensure bitwise atomicity (atomically set 64 bit
      // values), but we don't treat Int64 values because we would need to place it in a register
      // pair. If the slow path is taken, the Parallel move might fail to move the register pair
      // in case of an overlap (e.g., move from <EAX, EBX> to <EBX, ECX>). (Bug: b/168687887)
      break;
    case Intrinsics::kVarHandleSetRelease:
      // setRelease needs to ensure atomicity too. See the above comment.
      codegen->GenerateMemoryBarrier(MemBarrierKind::kAnyStore);
      break;
    case Intrinsics::kVarHandleSetVolatile:
      is_volatile = true;
      break;
    default:
      LOG(FATAL) << "GenerateVarHandleSet received non-set intrinsic " << invoke->GetIntrinsic();
  }

  InstructionCodeGeneratorX86* instr_codegen =
        down_cast<InstructionCodeGeneratorX86*>(codegen->GetInstructionVisitor());
  // Store the value to the field
  instr_codegen->HandleFieldSet(invoke,
                                value_index,
                                value_type,
                                Address(reference, offset, TIMES_1, 0),
                                reference,
                                is_volatile,
                                /* value_can_be_null */ true);

  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitVarHandleSet(HInvoke* invoke) {
  CreateVarHandleSetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleSet(HInvoke* invoke) {
  GenerateVarHandleSet(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleSetVolatile(HInvoke* invoke) {
  CreateVarHandleSetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleSetVolatile(HInvoke* invoke) {
  GenerateVarHandleSet(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleSetRelease(HInvoke* invoke) {
  CreateVarHandleSetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleSetRelease(HInvoke* invoke) {
  GenerateVarHandleSet(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleSetOpaque(HInvoke* invoke) {
  CreateVarHandleSetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleSetOpaque(HInvoke* invoke) {
  GenerateVarHandleSet(invoke, codegen_);
}

static void CreateVarHandleGetAndSetLocations(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  if (!IsValidFieldVarHandleExpected(invoke)) {
    return;
  }

  uint32_t number_of_arguments = invoke->GetNumberOfArguments();
  uint32_t value_index = number_of_arguments - 1;
  DataType::Type value_type = GetDataTypeFromShorty(invoke, value_index);

  if (DataType::Is64BitType(value_type)) {
    // We avoid the case of an Int64/Float64 value because we would need to place it in a register
    // pair. If the slow path is taken, the ParallelMove might fail to move the pair according to
    // the X86DexCallingConvention in case of an overlap (e.g., move the 64 bit value from
    // <EAX, EBX> to <EBX, ECX>).
    return;
  }

  ArenaAllocator* allocator = invoke->GetBlock()->GetGraph()->GetAllocator();
  LocationSummary* locations = new (allocator) LocationSummary(
      invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  // We use this temporary for the card, so we need a byte register
  locations->AddTemp(Location::RegisterLocation(EBX));
  locations->SetInAt(0, Location::RequiresRegister());
  if (GetExpectedVarHandleCoordinatesCount(invoke) == 1u) {
    // For instance fields, this is the source object
    locations->SetInAt(1, Location::RequiresRegister());
  } else {
    // For static fields, we need another temp because one will be busy with the declaring class.
    locations->AddTemp(Location::RequiresRegister());
  }
  if (value_type == DataType::Type::kFloat32) {
    locations->AddTemp(Location::RegisterLocation(EAX));
    locations->SetInAt(value_index, Location::FpuRegisterOrConstant(invoke->InputAt(value_index)));
    locations->SetOut(Location::RequiresFpuRegister());
  } else {
    locations->SetInAt(value_index, Location::RegisterLocation(EAX));
    locations->SetOut(Location::RegisterLocation(EAX));
  }
}

static void GenerateVarHandleGetAndSet(HInvoke* invoke, CodeGeneratorX86* codegen) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

  X86Assembler* assembler = codegen->GetAssembler();
  LocationSummary* locations = invoke->GetLocations();
  // The value we want to set is the last argument
  uint32_t value_index = invoke->GetNumberOfArguments() - 1;
  Location value = locations->InAt(value_index);
  DataType::Type value_type = GetDataTypeFromShorty(invoke, value_index);
  Register temp = locations->GetTemp(1).AsRegister<Register>();
  Register temp2 = locations->GetTemp(2).AsRegister<Register>();
  SlowPathCode* slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen->AddSlowPath(slow_path);

  GenerateVarHandleCommonChecks(invoke, temp, slow_path, assembler);

  Register offset = locations->GetTemp(0).AsRegister<Register>();
  // Get the field referred by the VarHandle. The returned register contains the object reference
  // or the declaring class. The field offset will be placed in 'offset'. For static fields, the
  // declaring class will be placed in 'temp' register.
  Register reference = GenerateVarHandleFieldReference(invoke, codegen, temp, offset);
  Address field_addr(reference, offset, TIMES_1, 0);

  if (invoke->GetIntrinsic() == Intrinsics::kVarHandleGetAndSetRelease) {
    codegen->GenerateMemoryBarrier(MemBarrierKind::kAnyStore);
  }

  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  // For static fields, we need another temporary for the declaring class. But since for instance
  // fields the object is in a separate register, it is safe to use the first temporary register.
  temp = expected_coordinates_count == 1u ? temp : locations->GetTemp(3).AsRegister<Register>();
  // No need for a lock prefix. `xchg` has an implicit lock when it is used with an address.
  switch (value_type) {
    case DataType::Type::kBool:
      __ xchgb(value.AsRegister<ByteRegister>(), field_addr);
      __ movzxb(locations->Out().AsRegister<Register>(),
                locations->Out().AsRegister<ByteRegister>());
      break;
    case DataType::Type::kInt8:
      __ xchgb(value.AsRegister<ByteRegister>(), field_addr);
      __ movsxb(locations->Out().AsRegister<Register>(),
                locations->Out().AsRegister<ByteRegister>());
      break;
    case DataType::Type::kUint16:
      __ xchgw(value.AsRegister<Register>(), field_addr);
      __ movzxw(locations->Out().AsRegister<Register>(), locations->Out().AsRegister<Register>());
      break;
    case DataType::Type::kInt16:
      __ xchgw(value.AsRegister<Register>(), field_addr);
      __ movsxw(locations->Out().AsRegister<Register>(), locations->Out().AsRegister<Register>());
      break;
    case DataType::Type::kInt32:
      __ xchgl(value.AsRegister<Register>(), field_addr);
      break;
    case DataType::Type::kFloat32:
      codegen->Move32(Location::RegisterLocation(EAX), value);
      __ xchgl(EAX, field_addr);
      __ movd(locations->Out().AsFpuRegister<XmmRegister>(), EAX);
      break;
    case DataType::Type::kReference: {
      if (kEmitCompilerReadBarrier && kUseBakerReadBarrier) {
        // Need to make sure the reference stored in the field is a to-space
        // one before attempting the CAS or the CAS could fail incorrectly.
        codegen->GenerateReferenceLoadWithBakerReadBarrier(
            invoke,
            // Unused, used only as a "temporary" within the read barrier.
            Location::RegisterLocation(temp),
            reference,
            field_addr,
            /* needs_null_check= */ false,
            /* always_update_field= */ true,
            &temp2);
      }
      codegen->MarkGCCard(
          temp, temp2, reference, value.AsRegister<Register>(), /* value_can_be_null= */ false);
      if (kPoisonHeapReferences) {
        __ movl(temp, value.AsRegister<Register>());
        __ PoisonHeapReference(temp);
        __ xchgl(temp, field_addr);
        __ UnpoisonHeapReference(temp);
        __ movl(locations->Out().AsRegister<Register>(), temp);
      } else {
        __ xchgl(locations->Out().AsRegister<Register>(), field_addr);
      }
      break;
    }
    default:
      UNREACHABLE();
  }

  if (invoke->GetIntrinsic() == Intrinsics::kVarHandleGetAndSetAcquire) {
    codegen->GenerateMemoryBarrier(MemBarrierKind::kLoadAny);
  }

  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndSet(HInvoke* invoke) {
  CreateVarHandleGetAndSetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndSet(HInvoke* invoke) {
  GenerateVarHandleGetAndSet(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndSetAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndSetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndSetAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndSet(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndSetRelease(HInvoke* invoke) {
  CreateVarHandleGetAndSetLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndSetRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndSet(invoke, codegen_);
}

static void CreateVarHandleCompareAndSetOrExchangeLocations(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  if (!IsValidFieldVarHandleExpected(invoke)) {
    return;
  }

  uint32_t number_of_arguments = invoke->GetNumberOfArguments();
  uint32_t expected_value_index = number_of_arguments - 2;
  uint32_t new_value_index = number_of_arguments - 1;
  DataType::Type value_type = GetDataTypeFromShorty(invoke, expected_value_index);
  DCHECK_EQ(value_type, GetDataTypeFromShorty(invoke, new_value_index));

  if (DataType::Is64BitType(value_type)) {
    // We avoid the case of an Int64/Float64 value because we would need to place it in a register
    // pair. If the slow path is taken, the ParallelMove might fail to move the pair according to
    // the X86DexCallingConvention in case of an overlap (e.g., move the 64 bit value from
    // <EAX, EBX> to <EBX, ECX>).
    return;
  }

  ArenaAllocator* allocator = invoke->GetBlock()->GetGraph()->GetAllocator();
  LocationSummary* locations = new (allocator) LocationSummary(
      invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  // We use this temporary for the card, so we need a byte register
  locations->AddTemp(Location::RegisterLocation(EBX));
  locations->SetInAt(0, Location::RequiresRegister());
  if (GetExpectedVarHandleCoordinatesCount(invoke) == 1u) {
    // For instance fields, this is the source object
    locations->SetInAt(1, Location::RequiresRegister());
  } else {
    // For static fields, we need another temp because one will be busy with the declaring class.
    locations->AddTemp(Location::RequiresRegister());
  }
  if (DataType::IsFloatingPointType(value_type)) {
    // We need EAX for placing the expected value
    locations->AddTemp(Location::RegisterLocation(EAX));
    locations->SetInAt(new_value_index,
                       Location::FpuRegisterOrConstant(invoke->InputAt(new_value_index)));
    locations->SetInAt(expected_value_index,
                       Location::FpuRegisterOrConstant(invoke->InputAt(expected_value_index)));
  } else {
    // Ensure it's in a byte register
    locations->SetInAt(new_value_index, Location::RegisterLocation(ECX));
    locations->SetInAt(expected_value_index, Location::RegisterLocation(EAX));
  }

  mirror::VarHandle::AccessModeTemplate access_mode_template =
      mirror::VarHandle::GetAccessModeTemplateByIntrinsic(invoke->GetIntrinsic());

  if (access_mode_template == mirror::VarHandle::AccessModeTemplate::kCompareAndExchange &&
      value_type == DataType::Type::kFloat32) {
    locations->SetOut(Location::RequiresFpuRegister());
  } else {
    locations->SetOut(Location::RegisterLocation(EAX));
  }
}

static void GenerateVarHandleCompareAndSetOrExchange(HInvoke* invoke, CodeGeneratorX86* codegen) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

  X86Assembler* assembler = codegen->GetAssembler();
  LocationSummary* locations = invoke->GetLocations();
  uint32_t number_of_arguments = invoke->GetNumberOfArguments();
  uint32_t expected_value_index = number_of_arguments - 2;
  uint32_t new_value_index = number_of_arguments - 1;
  DataType::Type type = GetDataTypeFromShorty(invoke, expected_value_index);
  DCHECK_EQ(type, GetDataTypeFromShorty(invoke, new_value_index));
  Location expected_value = locations->InAt(expected_value_index);
  Location new_value = locations->InAt(new_value_index);
  Register offset = locations->GetTemp(0).AsRegister<Register>();
  Register temp = locations->GetTemp(1).AsRegister<Register>();
  Register temp2 = locations->GetTemp(2).AsRegister<Register>();
  SlowPathCode* slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen->AddSlowPath(slow_path);

  GenerateVarHandleCommonChecks(invoke, temp, slow_path, assembler);

  // Get the field referred by the VarHandle. The returned register contains the object reference
  // or the declaring class. The field offset will be placed in 'offset'. For static fields, the
  // declaring class will be placed in 'temp' register.
  Register reference = GenerateVarHandleFieldReference(invoke, codegen, temp, offset);

  uint32_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  // For generating the compare and exchange, we need 2 temporaries. In case of a static field, the
  // first temporary contains the declaring class so we need another temporary. In case of an
  // instance field, the object comes in a separate register so it's safe to use the first temp.
  temp = (expected_coordinates_count == 1u) ? temp : locations->GetTemp(3).AsRegister<Register>();
  DCHECK_NE(temp, reference);

  // We are using `lock cmpxchg` in all cases because there is no CAS equivalent that has weak
  // failure semantics. `lock cmpxchg` has full barrier semantics, and we don't need scheduling
  // barriers at this time.

  mirror::VarHandle::AccessModeTemplate access_mode_template =
      mirror::VarHandle::GetAccessModeTemplateByIntrinsic(invoke->GetIntrinsic());
  bool is_cmpxchg =
      access_mode_template == mirror::VarHandle::AccessModeTemplate::kCompareAndExchange;

  if (type == DataType::Type::kReference) {
    GenReferenceCAS(
        invoke, codegen, expected_value, new_value, reference, offset, temp, temp2, is_cmpxchg);
  } else {
    Location out = locations->Out();
    GenPrimitiveCAS(
        type, codegen, expected_value, new_value, reference, offset, out, temp, is_cmpxchg);
  }

  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitVarHandleCompareAndSet(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleCompareAndSet(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleWeakCompareAndSet(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleWeakCompareAndSet(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleWeakCompareAndSetPlain(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleWeakCompareAndSetPlain(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleWeakCompareAndSetAcquire(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleWeakCompareAndSetAcquire(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleWeakCompareAndSetRelease(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleWeakCompareAndSetRelease(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleCompareAndExchange(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleCompareAndExchange(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleCompareAndExchangeAcquire(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleCompareAndExchangeAcquire(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleCompareAndExchangeRelease(HInvoke* invoke) {
  CreateVarHandleCompareAndSetOrExchangeLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleCompareAndExchangeRelease(HInvoke* invoke) {
  GenerateVarHandleCompareAndSetOrExchange(invoke, codegen_);
}

static void CreateVarHandleGetAndAddLocations(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  if (!IsValidFieldVarHandleExpected(invoke)) {
    return;
  }

  // The last argument should be the value we intend to set.
  uint32_t value_index = invoke->GetNumberOfArguments() - 1;
  DataType::Type value_type = GetDataTypeFromShorty(invoke, value_index);
  if (DataType::Is64BitType(value_type)) {
    // We avoid the case of an Int64/Float64 value because we would need to place it in a register
    // pair. If the slow path is taken, the ParallelMove might fail to move the pair according to
    // the X86DexCallingConvention in case of an overlap (e.g., move the 64 bit value from
    // <EAX, EBX> to <EBX, ECX>). (Bug: b/168687887)
    return;
  }

  ArenaAllocator* allocator = invoke->GetBlock()->GetGraph()->GetAllocator();
  LocationSummary* locations = new (allocator) LocationSummary(
      invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  locations->AddTemp(Location::RequiresRegister());
  locations->AddTemp(Location::RequiresRegister());
  locations->SetInAt(0, Location::RequiresRegister());
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  if (expected_coordinates_count == 1u) {
    // For instance fields, this is the source object
    locations->SetInAt(1, Location::RequiresRegister());
  } else {
    // For static fields, we need another temp because one will be busy with the declaring class.
    locations->AddTemp(Location::RequiresRegister());
  }

  if (DataType::IsFloatingPointType(value_type)) {
    locations->AddTemp(Location::RequiresFpuRegister());
    locations->AddTemp(Location::RegisterLocation(EAX));
    locations->SetInAt(value_index, Location::RequiresFpuRegister());
    locations->SetOut(Location::RequiresFpuRegister());
  } else {
    // xadd updates the register argument with the old value. ByteRegister required for xaddb.
    locations->SetInAt(value_index, Location::RegisterLocation(EAX));
    locations->SetOut(Location::RegisterLocation(EAX));
  }
}

static void GenerateVarHandleGetAndAdd(HInvoke* invoke, CodeGeneratorX86* codegen) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

  X86Assembler* assembler = codegen->GetAssembler();
  LocationSummary* locations = invoke->GetLocations();
  uint32_t number_of_arguments = invoke->GetNumberOfArguments();
  uint32_t value_index = number_of_arguments - 1;
  DataType::Type type = GetDataTypeFromShorty(invoke, value_index);
  DCHECK_EQ(type, invoke->GetType());
  Location value_loc = locations->InAt(value_index);
  Register temp = locations->GetTemp(0).AsRegister<Register>();
  SlowPathCode* slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen->AddSlowPath(slow_path);

  GenerateVarHandleCommonChecks(invoke, temp, slow_path, assembler);

  Register offset = locations->GetTemp(1).AsRegister<Register>();
  // Get the field referred by the VarHandle. The returned register contains the object reference
  // or the declaring class. The field offset will be placed in 'offset'. For static fields, the
  // declaring class will be placed in 'temp' register.
  Register reference = GenerateVarHandleFieldReference(invoke, codegen, temp, offset);

  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  temp = (expected_coordinates_count == 1u) ? temp : locations->GetTemp(2).AsRegister<Register>();
  DCHECK_NE(temp, reference);
  Address field_addr(reference, offset, TIMES_1, 0);

  switch (type) {
    case DataType::Type::kInt8:
      __ LockXaddb(field_addr, value_loc.AsRegister<ByteRegister>());
      __ movsxb(locations->Out().AsRegister<Register>(),
                locations->Out().AsRegister<ByteRegister>());
      break;
    case DataType::Type::kInt16:
      __ LockXaddw(field_addr, value_loc.AsRegister<Register>());
      __ movsxw(locations->Out().AsRegister<Register>(), locations->Out().AsRegister<Register>());
      break;
    case DataType::Type::kUint16:
      __ LockXaddw(field_addr, value_loc.AsRegister<Register>());
      __ movzxw(locations->Out().AsRegister<Register>(), locations->Out().AsRegister<Register>());
      break;
    case DataType::Type::kInt32:
      __ LockXaddl(field_addr, value_loc.AsRegister<Register>());
      break;
    case DataType::Type::kFloat32: {
      Location temp_float =
          (expected_coordinates_count == 1u) ? locations->GetTemp(2) : locations->GetTemp(3);
      DCHECK(temp_float.IsFpuRegister());
      Location eax = Location::RegisterLocation(EAX);
      NearLabel try_again;
      __ Bind(&try_again);
      __ movss(temp_float.AsFpuRegister<XmmRegister>(), field_addr);
      __ movd(EAX, temp_float.AsFpuRegister<XmmRegister>());
      __ addss(temp_float.AsFpuRegister<XmmRegister>(),
               value_loc.AsFpuRegister<XmmRegister>());
      GenPrimitiveLockedCmpxchg(type,
                                codegen,
                                /* expected_value= */ eax,
                                /* new_value= */ temp_float,
                                reference,
                                offset,
                                temp);
      __ j(kNotZero, &try_again);

      // The old value is present in EAX.
      codegen->Move32(locations->Out(), eax);
      break;
    }
    default:
      UNREACHABLE();
  }

  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndAdd(HInvoke* invoke) {
  CreateVarHandleGetAndAddLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndAdd(HInvoke* invoke) {
  GenerateVarHandleGetAndAdd(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndAddAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndAddLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndAddAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndAdd(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndAddRelease(HInvoke* invoke) {
  CreateVarHandleGetAndAddLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndAddRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndAdd(invoke, codegen_);
}

static void CreateVarHandleGetAndBitwiseOpLocations(HInvoke* invoke) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  if (kEmitCompilerReadBarrier && !kUseBakerReadBarrier) {
    return;
  }

  if (!IsValidFieldVarHandleExpected(invoke)) {
    return;
  }

  // The last argument should be the value we intend to set.
  uint32_t value_index = invoke->GetNumberOfArguments() - 1;
  if (DataType::Is64BitType(GetDataTypeFromShorty(invoke, value_index))) {
    // We avoid the case of an Int64 value because we would need to place it in a register pair.
    // If the slow path is taken, the ParallelMove might fail to move the pair according to the
    // X86DexCallingConvention in case of an overlap (e.g., move the 64 bit value from
    // <EAX, EBX> to <EBX, ECX>). (Bug: b/168687887)
    return;
  }

  ArenaAllocator* allocator = invoke->GetBlock()->GetGraph()->GetAllocator();
  LocationSummary* locations = new (allocator) LocationSummary(
      invoke, LocationSummary::kCallOnSlowPath, kIntrinsified);
  // We need a byte register temp to store the result of the bitwise operation
  locations->AddTemp(Location::RegisterLocation(EBX));
  locations->AddTemp(Location::RequiresRegister());
  locations->SetInAt(0, Location::RequiresRegister());
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  if (expected_coordinates_count == 1u) {
    // For instance fields, this is the source object
    locations->SetInAt(1, Location::RequiresRegister());
  } else {
    // For static fields, we need another temp because one will be busy with the declaring class.
    locations->AddTemp(Location::RequiresRegister());
  }

  locations->SetInAt(value_index, Location::RegisterOrConstant(invoke->InputAt(value_index)));
  locations->SetOut(Location::RegisterLocation(EAX));
}

static void GenerateBitwiseOp(HInvoke* invoke,
                              CodeGeneratorX86* codegen,
                              Register left,
                              Register right) {
  X86Assembler* assembler = codegen->GetAssembler();

  switch (invoke->GetIntrinsic()) {
    case Intrinsics::kVarHandleGetAndBitwiseOr:
    case Intrinsics::kVarHandleGetAndBitwiseOrAcquire:
    case Intrinsics::kVarHandleGetAndBitwiseOrRelease:
      __ orl(left, right);
      break;
    case Intrinsics::kVarHandleGetAndBitwiseXor:
    case Intrinsics::kVarHandleGetAndBitwiseXorAcquire:
    case Intrinsics::kVarHandleGetAndBitwiseXorRelease:
      __ xorl(left, right);
      break;
    case Intrinsics::kVarHandleGetAndBitwiseAnd:
    case Intrinsics::kVarHandleGetAndBitwiseAndAcquire:
    case Intrinsics::kVarHandleGetAndBitwiseAndRelease:
      __ andl(left, right);
      break;
    default:
      UNREACHABLE();
  }
}

static void GenerateVarHandleGetAndBitwiseOp(HInvoke* invoke, CodeGeneratorX86* codegen) {
  // The only read barrier implementation supporting the
  // VarHandleGet intrinsic is the Baker-style read barriers.
  DCHECK(!kEmitCompilerReadBarrier || kUseBakerReadBarrier);

  X86Assembler* assembler = codegen->GetAssembler();
  LocationSummary* locations = invoke->GetLocations();
  uint32_t value_index = invoke->GetNumberOfArguments() - 1;
  DataType::Type type = GetDataTypeFromShorty(invoke, value_index);
  DCHECK_EQ(type, invoke->GetType());
  Register temp = locations->GetTemp(0).AsRegister<Register>();
  SlowPathCode* slow_path = new (codegen->GetScopedAllocator()) IntrinsicSlowPathX86(invoke);
  codegen->AddSlowPath(slow_path);

  GenerateVarHandleCommonChecks(invoke, temp, slow_path, assembler);

  Register offset = locations->GetTemp(1).AsRegister<Register>();
  size_t expected_coordinates_count = GetExpectedVarHandleCoordinatesCount(invoke);
  // For static field, we need another temporary because the first one contains the declaring class
  Register reference =
      (expected_coordinates_count == 1u) ? temp : locations->GetTemp(2).AsRegister<Register>();
  // Get the field referred by the VarHandle. The returned register contains the object reference
  // or the declaring class. The field offset will be placed in 'offset'. For static fields, the
  // declaring class will be placed in 'reference' register.
  reference = GenerateVarHandleFieldReference(invoke, codegen, reference, offset);
  DCHECK_NE(temp, reference);
  Address field_addr(reference, offset, TIMES_1, 0);

  Register out = locations->Out().AsRegister<Register>();
  DCHECK_EQ(out, EAX);

  if (invoke->GetIntrinsic() == Intrinsics::kVarHandleGetAndBitwiseOrRelease ||
      invoke->GetIntrinsic() == Intrinsics::kVarHandleGetAndBitwiseXorRelease ||
      invoke->GetIntrinsic() == Intrinsics::kVarHandleGetAndBitwiseAndRelease) {
    codegen->GenerateMemoryBarrier(MemBarrierKind::kAnyStore);
  }

  NearLabel try_again;
  __ Bind(&try_again);
  // Place the expected value in EAX for cmpxchg
  codegen->LoadFromMemoryNoBarrier(type, locations->Out(), field_addr);
  codegen->Move32(locations->GetTemp(0), locations->InAt(value_index));
  GenerateBitwiseOp(invoke, codegen, temp, out);
  GenPrimitiveLockedCmpxchg(type,
                            codegen,
                            /* expected_value= */ locations->Out(),
                            /* new_value= */ locations->GetTemp(0),
                            reference,
                            offset);
  // If the cmpxchg failed, another thread changed the value so try again.
  __ j(kNotZero, &try_again);

  // The old value is present in EAX.

  if (invoke->GetIntrinsic() == Intrinsics::kVarHandleGetAndBitwiseOrAcquire ||
      invoke->GetIntrinsic() == Intrinsics::kVarHandleGetAndBitwiseXorAcquire ||
      invoke->GetIntrinsic() == Intrinsics::kVarHandleGetAndBitwiseAndAcquire) {
    codegen->GenerateMemoryBarrier(MemBarrierKind::kLoadAny);
  }

  __ Bind(slow_path->GetExitLabel());
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndBitwiseOr(HInvoke* invoke) {
  CreateVarHandleGetAndBitwiseOpLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndBitwiseOr(HInvoke* invoke) {
  GenerateVarHandleGetAndBitwiseOp(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndBitwiseOrAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndBitwiseOpLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndBitwiseOrAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndBitwiseOp(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndBitwiseOrRelease(HInvoke* invoke) {
  CreateVarHandleGetAndBitwiseOpLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndBitwiseOrRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndBitwiseOp(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndBitwiseXor(HInvoke* invoke) {
  CreateVarHandleGetAndBitwiseOpLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndBitwiseXor(HInvoke* invoke) {
  GenerateVarHandleGetAndBitwiseOp(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndBitwiseXorAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndBitwiseOpLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndBitwiseXorAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndBitwiseOp(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndBitwiseXorRelease(HInvoke* invoke) {
  CreateVarHandleGetAndBitwiseOpLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndBitwiseXorRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndBitwiseOp(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndBitwiseAnd(HInvoke* invoke) {
  CreateVarHandleGetAndBitwiseOpLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndBitwiseAnd(HInvoke* invoke) {
  GenerateVarHandleGetAndBitwiseOp(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndBitwiseAndAcquire(HInvoke* invoke) {
  CreateVarHandleGetAndBitwiseOpLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndBitwiseAndAcquire(HInvoke* invoke) {
  GenerateVarHandleGetAndBitwiseOp(invoke, codegen_);
}

void IntrinsicLocationsBuilderX86::VisitVarHandleGetAndBitwiseAndRelease(HInvoke* invoke) {
  CreateVarHandleGetAndBitwiseOpLocations(invoke);
}

void IntrinsicCodeGeneratorX86::VisitVarHandleGetAndBitwiseAndRelease(HInvoke* invoke) {
  GenerateVarHandleGetAndBitwiseOp(invoke, codegen_);
}

UNIMPLEMENTED_INTRINSIC(X86, MathRoundDouble)
UNIMPLEMENTED_INTRINSIC(X86, FloatIsInfinite)
UNIMPLEMENTED_INTRINSIC(X86, DoubleIsInfinite)
UNIMPLEMENTED_INTRINSIC(X86, IntegerHighestOneBit)
UNIMPLEMENTED_INTRINSIC(X86, LongHighestOneBit)
UNIMPLEMENTED_INTRINSIC(X86, LongDivideUnsigned)
UNIMPLEMENTED_INTRINSIC(X86, CRC32Update)
UNIMPLEMENTED_INTRINSIC(X86, CRC32UpdateBytes)
UNIMPLEMENTED_INTRINSIC(X86, CRC32UpdateByteBuffer)
UNIMPLEMENTED_INTRINSIC(X86, FP16ToFloat)
UNIMPLEMENTED_INTRINSIC(X86, FP16ToHalf)
UNIMPLEMENTED_INTRINSIC(X86, FP16Floor)
UNIMPLEMENTED_INTRINSIC(X86, FP16Ceil)
UNIMPLEMENTED_INTRINSIC(X86, FP16Rint)
UNIMPLEMENTED_INTRINSIC(X86, FP16Greater)
UNIMPLEMENTED_INTRINSIC(X86, FP16GreaterEquals)
UNIMPLEMENTED_INTRINSIC(X86, FP16Less)
UNIMPLEMENTED_INTRINSIC(X86, FP16LessEquals)
UNIMPLEMENTED_INTRINSIC(X86, MathMultiplyHigh)

UNIMPLEMENTED_INTRINSIC(X86, StringStringIndexOf);
UNIMPLEMENTED_INTRINSIC(X86, StringStringIndexOfAfter);
UNIMPLEMENTED_INTRINSIC(X86, StringBufferAppend);
UNIMPLEMENTED_INTRINSIC(X86, StringBufferLength);
UNIMPLEMENTED_INTRINSIC(X86, StringBufferToString);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendObject);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendString);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendCharSequence);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendCharArray);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendBoolean);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendChar);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendInt);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendLong);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendFloat);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderAppendDouble);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderLength);
UNIMPLEMENTED_INTRINSIC(X86, StringBuilderToString);

// 1.8.
UNIMPLEMENTED_INTRINSIC(X86, UnsafeGetAndAddInt)
UNIMPLEMENTED_INTRINSIC(X86, UnsafeGetAndAddLong)
UNIMPLEMENTED_INTRINSIC(X86, UnsafeGetAndSetInt)
UNIMPLEMENTED_INTRINSIC(X86, UnsafeGetAndSetLong)
UNIMPLEMENTED_INTRINSIC(X86, UnsafeGetAndSetObject)

UNIMPLEMENTED_INTRINSIC(X86, MethodHandleInvokeExact)
UNIMPLEMENTED_INTRINSIC(X86, MethodHandleInvoke)

UNREACHABLE_INTRINSICS(X86)

#undef __

}  // namespace x86
}  // namespace art
