/*
 * Copyright (C) 2016 The Android Open Source Project
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

#include "jni_macro_assembler_x86.h"

#include "base/casts.h"
#include "entrypoints/quick/quick_entrypoints.h"
#include "thread.h"
#include "utils/assembler.h"

namespace art {
namespace x86 {

static Register GetScratchRegister() {
  // ECX is an argument register on entry and gets spilled in BuildFrame().
  // After that, we can use it as a scratch register.
  return ECX;
}

// Slowpath entered when Thread::Current()->_exception is non-null
class X86ExceptionSlowPath final : public SlowPath {
 public:
  explicit X86ExceptionSlowPath(size_t stack_adjust) : stack_adjust_(stack_adjust) {}
  void Emit(Assembler *sp_asm) override;
 private:
  const size_t stack_adjust_;
};

static dwarf::Reg DWARFReg(Register reg) {
  return dwarf::Reg::X86Core(static_cast<int>(reg));
}

constexpr size_t kFramePointerSize = 4;

static constexpr size_t kNativeStackAlignment = 16;
static_assert(kNativeStackAlignment == kStackAlignment);

#define __ asm_.

void X86JNIMacroAssembler::BuildFrame(size_t frame_size,
                                      ManagedRegister method_reg,
                                      ArrayRef<const ManagedRegister> spill_regs) {
  DCHECK_EQ(CodeSize(), 0U);  // Nothing emitted yet.
  cfi().SetCurrentCFAOffset(4);  // Return address on stack.
  if (frame_size == kFramePointerSize) {
    // For @CriticalNative tail call.
    CHECK(method_reg.IsNoRegister());
    CHECK(spill_regs.empty());
  } else if (method_reg.IsNoRegister()) {
    CHECK_ALIGNED(frame_size, kNativeStackAlignment);
  } else {
    CHECK_ALIGNED(frame_size, kStackAlignment);
  }
  int gpr_count = 0;
  for (int i = spill_regs.size() - 1; i >= 0; --i) {
    Register spill = spill_regs[i].AsX86().AsCpuRegister();
    __ pushl(spill);
    gpr_count++;
    cfi().AdjustCFAOffset(kFramePointerSize);
    cfi().RelOffset(DWARFReg(spill), 0);
  }

  // return address then method on stack.
  int32_t adjust = frame_size - gpr_count * kFramePointerSize -
      kFramePointerSize /*return address*/ -
      (method_reg.IsRegister() ? kFramePointerSize /*method*/ : 0u);
  if (adjust != 0) {
    __ addl(ESP, Immediate(-adjust));
    cfi().AdjustCFAOffset(adjust);
  }
  if (method_reg.IsRegister()) {
    __ pushl(method_reg.AsX86().AsCpuRegister());
    cfi().AdjustCFAOffset(kFramePointerSize);
  }
  DCHECK_EQ(static_cast<size_t>(cfi().GetCurrentCFAOffset()), frame_size);
}

void X86JNIMacroAssembler::RemoveFrame(size_t frame_size,
                                       ArrayRef<const ManagedRegister> spill_regs,
                                       bool may_suspend ATTRIBUTE_UNUSED) {
  CHECK_ALIGNED(frame_size, kNativeStackAlignment);
  cfi().RememberState();
  // -kFramePointerSize for ArtMethod*.
  int adjust = frame_size - spill_regs.size() * kFramePointerSize - kFramePointerSize;
  if (adjust != 0) {
    __ addl(ESP, Immediate(adjust));
    cfi().AdjustCFAOffset(-adjust);
  }
  for (size_t i = 0; i < spill_regs.size(); ++i) {
    Register spill = spill_regs[i].AsX86().AsCpuRegister();
    __ popl(spill);
    cfi().AdjustCFAOffset(-static_cast<int>(kFramePointerSize));
    cfi().Restore(DWARFReg(spill));
  }
  __ ret();
  // The CFI should be restored for any code that follows the exit block.
  cfi().RestoreState();
  cfi().DefCFAOffset(frame_size);
}

void X86JNIMacroAssembler::IncreaseFrameSize(size_t adjust) {
  if (adjust != 0u) {
    CHECK_ALIGNED(adjust, kNativeStackAlignment);
    __ addl(ESP, Immediate(-adjust));
    cfi().AdjustCFAOffset(adjust);
  }
}

static void DecreaseFrameSizeImpl(X86Assembler* assembler, size_t adjust) {
  if (adjust != 0u) {
    CHECK_ALIGNED(adjust, kNativeStackAlignment);
    assembler->addl(ESP, Immediate(adjust));
    assembler->cfi().AdjustCFAOffset(-adjust);
  }
}

void X86JNIMacroAssembler::DecreaseFrameSize(size_t adjust) {
  DecreaseFrameSizeImpl(&asm_, adjust);
}

void X86JNIMacroAssembler::Store(FrameOffset offs, ManagedRegister msrc, size_t size) {
  X86ManagedRegister src = msrc.AsX86();
  if (src.IsNoRegister()) {
    CHECK_EQ(0u, size);
  } else if (src.IsCpuRegister()) {
    CHECK_EQ(4u, size);
    __ movl(Address(ESP, offs), src.AsCpuRegister());
  } else if (src.IsRegisterPair()) {
    CHECK_EQ(8u, size);
    __ movl(Address(ESP, offs), src.AsRegisterPairLow());
    __ movl(Address(ESP, FrameOffset(offs.Int32Value()+4)), src.AsRegisterPairHigh());
  } else if (src.IsX87Register()) {
    if (size == 4) {
      __ fstps(Address(ESP, offs));
    } else {
      __ fstpl(Address(ESP, offs));
    }
  } else {
    CHECK(src.IsXmmRegister());
    if (size == 4) {
      __ movss(Address(ESP, offs), src.AsXmmRegister());
    } else {
      __ movsd(Address(ESP, offs), src.AsXmmRegister());
    }
  }
}

void X86JNIMacroAssembler::StoreRef(FrameOffset dest, ManagedRegister msrc) {
  X86ManagedRegister src = msrc.AsX86();
  CHECK(src.IsCpuRegister());
  __ movl(Address(ESP, dest), src.AsCpuRegister());
}

void X86JNIMacroAssembler::StoreRawPtr(FrameOffset dest, ManagedRegister msrc) {
  X86ManagedRegister src = msrc.AsX86();
  CHECK(src.IsCpuRegister());
  __ movl(Address(ESP, dest), src.AsCpuRegister());
}

void X86JNIMacroAssembler::StoreImmediateToFrame(FrameOffset dest, uint32_t imm) {
  __ movl(Address(ESP, dest), Immediate(imm));
}

void X86JNIMacroAssembler::StoreStackOffsetToThread(ThreadOffset32 thr_offs, FrameOffset fr_offs) {
  Register scratch = GetScratchRegister();
  __ leal(scratch, Address(ESP, fr_offs));
  __ fs()->movl(Address::Absolute(thr_offs), scratch);
}

void X86JNIMacroAssembler::StoreStackPointerToThread(ThreadOffset32 thr_offs) {
  __ fs()->movl(Address::Absolute(thr_offs), ESP);
}

void X86JNIMacroAssembler::StoreSpanning(FrameOffset /*dst*/,
                                         ManagedRegister /*src*/,
                                         FrameOffset /*in_off*/) {
  UNIMPLEMENTED(FATAL);  // this case only currently exists for ARM
}

void X86JNIMacroAssembler::Load(ManagedRegister mdest, FrameOffset src, size_t size) {
  X86ManagedRegister dest = mdest.AsX86();
  if (dest.IsNoRegister()) {
    CHECK_EQ(0u, size);
  } else if (dest.IsCpuRegister()) {
    CHECK_EQ(4u, size);
    __ movl(dest.AsCpuRegister(), Address(ESP, src));
  } else if (dest.IsRegisterPair()) {
    CHECK_EQ(8u, size);
    __ movl(dest.AsRegisterPairLow(), Address(ESP, src));
    __ movl(dest.AsRegisterPairHigh(), Address(ESP, FrameOffset(src.Int32Value()+4)));
  } else if (dest.IsX87Register()) {
    if (size == 4) {
      __ flds(Address(ESP, src));
    } else {
      __ fldl(Address(ESP, src));
    }
  } else {
    CHECK(dest.IsXmmRegister());
    if (size == 4) {
      __ movss(dest.AsXmmRegister(), Address(ESP, src));
    } else {
      __ movsd(dest.AsXmmRegister(), Address(ESP, src));
    }
  }
}

void X86JNIMacroAssembler::LoadFromThread(ManagedRegister mdest, ThreadOffset32 src, size_t size) {
  X86ManagedRegister dest = mdest.AsX86();
  if (dest.IsNoRegister()) {
    CHECK_EQ(0u, size);
  } else if (dest.IsCpuRegister()) {
    if (size == 1u) {
      __ fs()->movzxb(dest.AsCpuRegister(), Address::Absolute(src));
    } else {
      CHECK_EQ(4u, size);
      __ fs()->movl(dest.AsCpuRegister(), Address::Absolute(src));
    }
  } else if (dest.IsRegisterPair()) {
    CHECK_EQ(8u, size);
    __ fs()->movl(dest.AsRegisterPairLow(), Address::Absolute(src));
    __ fs()->movl(dest.AsRegisterPairHigh(), Address::Absolute(ThreadOffset32(src.Int32Value()+4)));
  } else if (dest.IsX87Register()) {
    if (size == 4) {
      __ fs()->flds(Address::Absolute(src));
    } else {
      __ fs()->fldl(Address::Absolute(src));
    }
  } else {
    CHECK(dest.IsXmmRegister());
    if (size == 4) {
      __ fs()->movss(dest.AsXmmRegister(), Address::Absolute(src));
    } else {
      __ fs()->movsd(dest.AsXmmRegister(), Address::Absolute(src));
    }
  }
}

void X86JNIMacroAssembler::LoadRef(ManagedRegister mdest, FrameOffset src) {
  X86ManagedRegister dest = mdest.AsX86();
  CHECK(dest.IsCpuRegister());
  __ movl(dest.AsCpuRegister(), Address(ESP, src));
}

void X86JNIMacroAssembler::LoadRef(ManagedRegister mdest, ManagedRegister base, MemberOffset offs,
                           bool unpoison_reference) {
  X86ManagedRegister dest = mdest.AsX86();
  CHECK(dest.IsCpuRegister() && dest.IsCpuRegister());
  __ movl(dest.AsCpuRegister(), Address(base.AsX86().AsCpuRegister(), offs));
  if (unpoison_reference) {
    __ MaybeUnpoisonHeapReference(dest.AsCpuRegister());
  }
}

void X86JNIMacroAssembler::LoadRawPtr(ManagedRegister mdest,
                                      ManagedRegister base,
                                      Offset offs) {
  X86ManagedRegister dest = mdest.AsX86();
  CHECK(dest.IsCpuRegister() && dest.IsCpuRegister());
  __ movl(dest.AsCpuRegister(), Address(base.AsX86().AsCpuRegister(), offs));
}

void X86JNIMacroAssembler::LoadRawPtrFromThread(ManagedRegister mdest, ThreadOffset32 offs) {
  X86ManagedRegister dest = mdest.AsX86();
  CHECK(dest.IsCpuRegister());
  __ fs()->movl(dest.AsCpuRegister(), Address::Absolute(offs));
}

void X86JNIMacroAssembler::SignExtend(ManagedRegister mreg, size_t size) {
  X86ManagedRegister reg = mreg.AsX86();
  CHECK(size == 1 || size == 2) << size;
  CHECK(reg.IsCpuRegister()) << reg;
  if (size == 1) {
    __ movsxb(reg.AsCpuRegister(), reg.AsByteRegister());
  } else {
    __ movsxw(reg.AsCpuRegister(), reg.AsCpuRegister());
  }
}

void X86JNIMacroAssembler::ZeroExtend(ManagedRegister mreg, size_t size) {
  X86ManagedRegister reg = mreg.AsX86();
  CHECK(size == 1 || size == 2) << size;
  CHECK(reg.IsCpuRegister()) << reg;
  if (size == 1) {
    __ movzxb(reg.AsCpuRegister(), reg.AsByteRegister());
  } else {
    __ movzxw(reg.AsCpuRegister(), reg.AsCpuRegister());
  }
}

void X86JNIMacroAssembler::MoveArguments(ArrayRef<ArgumentLocation> dests,
                                         ArrayRef<ArgumentLocation> srcs) {
  DCHECK_EQ(dests.size(), srcs.size());
  bool found_hidden_arg = false;
  for (size_t i = 0, arg_count = srcs.size(); i != arg_count; ++i) {
    const ArgumentLocation& src = srcs[i];
    const ArgumentLocation& dest = dests[i];
    DCHECK_EQ(src.GetSize(), dest.GetSize());
    if (src.IsRegister()) {
      if (UNLIKELY(dest.IsRegister())) {
        // Native ABI has only stack arguments but we may pass one "hidden arg" in register.
        CHECK(!found_hidden_arg);
        found_hidden_arg = true;
        DCHECK(
            !dest.GetRegister().Equals(X86ManagedRegister::FromCpuRegister(GetScratchRegister())));
        Move(dest.GetRegister(), src.GetRegister(), dest.GetSize());
      } else {
        Store(dest.GetFrameOffset(), src.GetRegister(), dest.GetSize());
      }
    } else {
      // Delay copying until we have spilled all registers, including the scratch register ECX.
    }
  }
  for (size_t i = 0, arg_count = srcs.size(); i != arg_count; ++i) {
    const ArgumentLocation& src = srcs[i];
    const ArgumentLocation& dest = dests[i];
    DCHECK_EQ(src.GetSize(), dest.GetSize());
    if (!src.IsRegister()) {
      DCHECK(!dest.IsRegister());
      Copy(dest.GetFrameOffset(), src.GetFrameOffset(), dest.GetSize());
    }
  }
}

void X86JNIMacroAssembler::Move(ManagedRegister mdest, ManagedRegister msrc, size_t size) {
  DCHECK(!mdest.Equals(X86ManagedRegister::FromCpuRegister(GetScratchRegister())));
  X86ManagedRegister dest = mdest.AsX86();
  X86ManagedRegister src = msrc.AsX86();
  if (!dest.Equals(src)) {
    if (dest.IsCpuRegister() && src.IsCpuRegister()) {
      __ movl(dest.AsCpuRegister(), src.AsCpuRegister());
    } else if (src.IsX87Register() && dest.IsXmmRegister()) {
      // Pass via stack and pop X87 register
      IncreaseFrameSize(16);
      if (size == 4) {
        CHECK_EQ(src.AsX87Register(), ST0);
        __ fstps(Address(ESP, 0));
        __ movss(dest.AsXmmRegister(), Address(ESP, 0));
      } else {
        CHECK_EQ(src.AsX87Register(), ST0);
        __ fstpl(Address(ESP, 0));
        __ movsd(dest.AsXmmRegister(), Address(ESP, 0));
      }
      DecreaseFrameSize(16);
    } else {
      // TODO: x87, SSE
      UNIMPLEMENTED(FATAL) << ": Move " << dest << ", " << src;
    }
  }
}

void X86JNIMacroAssembler::CopyRef(FrameOffset dest, FrameOffset src) {
  Register scratch = GetScratchRegister();
  __ movl(scratch, Address(ESP, src));
  __ movl(Address(ESP, dest), scratch);
}

void X86JNIMacroAssembler::CopyRef(FrameOffset dest,
                                   ManagedRegister base,
                                   MemberOffset offs,
                                   bool unpoison_reference) {
  Register scratch = GetScratchRegister();
  __ movl(scratch, Address(base.AsX86().AsCpuRegister(), offs));
  if (unpoison_reference) {
    __ MaybeUnpoisonHeapReference(scratch);
  }
  __ movl(Address(ESP, dest), scratch);
}

void X86JNIMacroAssembler::CopyRawPtrFromThread(FrameOffset fr_offs, ThreadOffset32 thr_offs) {
  Register scratch = GetScratchRegister();
  __ fs()->movl(scratch, Address::Absolute(thr_offs));
  __ movl(Address(ESP, fr_offs), scratch);
}

void X86JNIMacroAssembler::CopyRawPtrToThread(ThreadOffset32 thr_offs,
                                              FrameOffset fr_offs,
                                              ManagedRegister mscratch) {
  X86ManagedRegister scratch = mscratch.AsX86();
  CHECK(scratch.IsCpuRegister());
  Load(scratch, fr_offs, 4);
  __ fs()->movl(Address::Absolute(thr_offs), scratch.AsCpuRegister());
}

void X86JNIMacroAssembler::Copy(FrameOffset dest, FrameOffset src, size_t size) {
  DCHECK(size == 4 || size == 8) << size;
  Register scratch = GetScratchRegister();
  __ movl(scratch, Address(ESP, src));
  __ movl(Address(ESP, dest), scratch);
  if (size == 8) {
    __ movl(scratch, Address(ESP, FrameOffset(src.Int32Value() + 4)));
    __ movl(Address(ESP, FrameOffset(dest.Int32Value() + 4)), scratch);
  }
}

void X86JNIMacroAssembler::Copy(FrameOffset /*dst*/,
                                ManagedRegister /*src_base*/,
                                Offset /*src_offset*/,
                                ManagedRegister /*scratch*/,
                                size_t /*size*/) {
  UNIMPLEMENTED(FATAL);
}

void X86JNIMacroAssembler::Copy(ManagedRegister dest_base,
                                Offset dest_offset,
                                FrameOffset src,
                                ManagedRegister scratch,
                                size_t size) {
  CHECK(scratch.IsNoRegister());
  CHECK_EQ(size, 4u);
  __ pushl(Address(ESP, src));
  __ popl(Address(dest_base.AsX86().AsCpuRegister(), dest_offset));
}

void X86JNIMacroAssembler::Copy(FrameOffset dest,
                                FrameOffset src_base,
                                Offset src_offset,
                                ManagedRegister mscratch,
                                size_t size) {
  Register scratch = mscratch.AsX86().AsCpuRegister();
  CHECK_EQ(size, 4u);
  __ movl(scratch, Address(ESP, src_base));
  __ movl(scratch, Address(scratch, src_offset));
  __ movl(Address(ESP, dest), scratch);
}

void X86JNIMacroAssembler::Copy(ManagedRegister dest,
                                Offset dest_offset,
                                ManagedRegister src,
                                Offset src_offset,
                                ManagedRegister scratch,
                                size_t size) {
  CHECK_EQ(size, 4u);
  CHECK(scratch.IsNoRegister());
  __ pushl(Address(src.AsX86().AsCpuRegister(), src_offset));
  __ popl(Address(dest.AsX86().AsCpuRegister(), dest_offset));
}

void X86JNIMacroAssembler::Copy(FrameOffset dest,
                                Offset dest_offset,
                                FrameOffset src,
                                Offset src_offset,
                                ManagedRegister mscratch,
                                size_t size) {
  Register scratch = mscratch.AsX86().AsCpuRegister();
  CHECK_EQ(size, 4u);
  CHECK_EQ(dest.Int32Value(), src.Int32Value());
  __ movl(scratch, Address(ESP, src));
  __ pushl(Address(scratch, src_offset));
  __ popl(Address(scratch, dest_offset));
}

void X86JNIMacroAssembler::MemoryBarrier(ManagedRegister) {
  __ mfence();
}

void X86JNIMacroAssembler::CreateJObject(ManagedRegister mout_reg,
                                         FrameOffset spilled_reference_offset,
                                         ManagedRegister min_reg,
                                         bool null_allowed) {
  X86ManagedRegister out_reg = mout_reg.AsX86();
  X86ManagedRegister in_reg = min_reg.AsX86();
  CHECK(in_reg.IsCpuRegister());
  CHECK(out_reg.IsCpuRegister());
  VerifyObject(in_reg, null_allowed);
  if (null_allowed) {
    Label null_arg;
    if (!out_reg.Equals(in_reg)) {
      __ xorl(out_reg.AsCpuRegister(), out_reg.AsCpuRegister());
    }
    __ testl(in_reg.AsCpuRegister(), in_reg.AsCpuRegister());
    __ j(kZero, &null_arg);
    __ leal(out_reg.AsCpuRegister(), Address(ESP, spilled_reference_offset));
    __ Bind(&null_arg);
  } else {
    __ leal(out_reg.AsCpuRegister(), Address(ESP, spilled_reference_offset));
  }
}

void X86JNIMacroAssembler::CreateJObject(FrameOffset out_off,
                                         FrameOffset spilled_reference_offset,
                                         bool null_allowed) {
  Register scratch = GetScratchRegister();
  if (null_allowed) {
    Label null_arg;
    __ movl(scratch, Address(ESP, spilled_reference_offset));
    __ testl(scratch, scratch);
    __ j(kZero, &null_arg);
    __ leal(scratch, Address(ESP, spilled_reference_offset));
    __ Bind(&null_arg);
  } else {
    __ leal(scratch, Address(ESP, spilled_reference_offset));
  }
  __ movl(Address(ESP, out_off), scratch);
}

void X86JNIMacroAssembler::VerifyObject(ManagedRegister /*src*/, bool /*could_be_null*/) {
  // TODO: not validating references
}

void X86JNIMacroAssembler::VerifyObject(FrameOffset /*src*/, bool /*could_be_null*/) {
  // TODO: not validating references
}

void X86JNIMacroAssembler::Jump(ManagedRegister mbase, Offset offset) {
  X86ManagedRegister base = mbase.AsX86();
  CHECK(base.IsCpuRegister());
  __ jmp(Address(base.AsCpuRegister(), offset.Int32Value()));
}

void X86JNIMacroAssembler::Call(ManagedRegister mbase, Offset offset) {
  X86ManagedRegister base = mbase.AsX86();
  CHECK(base.IsCpuRegister());
  __ call(Address(base.AsCpuRegister(), offset.Int32Value()));
  // TODO: place reference map on call
}

void X86JNIMacroAssembler::Call(FrameOffset base, Offset offset) {
  Register scratch = GetScratchRegister();
  __ movl(scratch, Address(ESP, base));
  __ call(Address(scratch, offset));
}

void X86JNIMacroAssembler::CallFromThread(ThreadOffset32 offset) {
  __ fs()->call(Address::Absolute(offset));
}

void X86JNIMacroAssembler::GetCurrentThread(ManagedRegister dest) {
  __ fs()->movl(dest.AsX86().AsCpuRegister(),
                Address::Absolute(Thread::SelfOffset<kX86PointerSize>()));
}

void X86JNIMacroAssembler::GetCurrentThread(FrameOffset offset) {
  Register scratch = GetScratchRegister();
  __ fs()->movl(scratch, Address::Absolute(Thread::SelfOffset<kX86PointerSize>()));
  __ movl(Address(ESP, offset), scratch);
}

void X86JNIMacroAssembler::ExceptionPoll(size_t stack_adjust) {
  X86ExceptionSlowPath* slow = new (__ GetAllocator()) X86ExceptionSlowPath(stack_adjust);
  __ GetBuffer()->EnqueueSlowPath(slow);
  __ fs()->cmpl(Address::Absolute(Thread::ExceptionOffset<kX86PointerSize>()), Immediate(0));
  __ j(kNotEqual, slow->Entry());
}

std::unique_ptr<JNIMacroLabel> X86JNIMacroAssembler::CreateLabel() {
  return std::unique_ptr<JNIMacroLabel>(new X86JNIMacroLabel());
}

void X86JNIMacroAssembler::Jump(JNIMacroLabel* label) {
  CHECK(label != nullptr);
  __ jmp(X86JNIMacroLabel::Cast(label)->AsX86());
}

void X86JNIMacroAssembler::TestGcMarking(JNIMacroLabel* label, JNIMacroUnaryCondition cond) {
  CHECK(label != nullptr);

  art::x86::Condition x86_cond;
  switch (cond) {
    case JNIMacroUnaryCondition::kZero:
      x86_cond = art::x86::kZero;
      break;
    case JNIMacroUnaryCondition::kNotZero:
      x86_cond = art::x86::kNotZero;
      break;
    default:
      LOG(FATAL) << "Not implemented condition: " << static_cast<int>(cond);
      UNREACHABLE();
  }

  // CMP self->tls32_.is_gc_marking, 0
  // Jcc <Offset>
  DCHECK_EQ(Thread::IsGcMarkingSize(), 4u);
  __ fs()->cmpl(Address::Absolute(Thread::IsGcMarkingOffset<kX86PointerSize>()), Immediate(0));
  __ j(x86_cond, X86JNIMacroLabel::Cast(label)->AsX86());
}

void X86JNIMacroAssembler::Bind(JNIMacroLabel* label) {
  CHECK(label != nullptr);
  __ Bind(X86JNIMacroLabel::Cast(label)->AsX86());
}

#undef __

void X86ExceptionSlowPath::Emit(Assembler *sasm) {
  X86Assembler* sp_asm = down_cast<X86Assembler*>(sasm);
#define __ sp_asm->
  __ Bind(&entry_);
  // Note: the return value is dead
  if (stack_adjust_ != 0) {  // Fix up the frame.
    DecreaseFrameSizeImpl(sp_asm, stack_adjust_);
  }
  // Pass exception as argument in EAX
  __ fs()->movl(EAX, Address::Absolute(Thread::ExceptionOffset<kX86PointerSize>()));
  __ fs()->call(Address::Absolute(QUICK_ENTRYPOINT_OFFSET(kX86PointerSize, pDeliverException)));
  // this call should never return
  __ int3();
#undef __
}

}  // namespace x86
}  // namespace art
