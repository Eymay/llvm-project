//===-- Target.cpp ----------------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include "../Target.h"
#include "ARM.h"
#include "ARMBaseRegisterInfo.h"
#include "ARMRegisterInfo.h"

#define GET_AVAILABLE_OPCODE_CHECKER
#include "ARMGenInstrInfo.inc"

namespace llvm {
namespace exegesis {

static unsigned getLoadImmediateOpcode(unsigned RegBitWidth) {
  switch (RegBitWidth) {
  case 32:
    return ARM::MOVi32imm;
  }
  llvm_unreachable("Invalid Value Width");
}

// Generates instruction to load an immediate value into a register.
static MCInst loadImmediate(unsigned Reg, unsigned RegBitWidth,
                            const APInt &Value) {
  if (Value.getBitWidth() > RegBitWidth)
    llvm_unreachable("Value must fit in the Register");
  return MCInstBuilder(getLoadImmediateOpcode(RegBitWidth))
      .addReg(Reg)
      .addImm(Value.getZExtValue());
}

#include "ARMGenExegesis.inc"

namespace {

class ExegesisARMTarget : public ExegesisTarget {
public:
  ExegesisARMTarget()
      : ExegesisTarget(ARMCpuPfmCounters, ARM_MC::isOpcodeAvailable) {}

private:
  std::vector<MCInst> setRegTo(const MCSubtargetInfo &STI, unsigned Reg,
                               const APInt &Value) const override {
    if (ARM::GPRRegClass.contains(Reg))
      return {loadImmediate(Reg, 32, Value)};
    errs() << "setRegTo is not implemented, results will be unreliable\n";
    return {};
  }

  bool matchesArch(Triple::ArchType Arch) const override {
    return Arch == Triple::arm || Arch == Triple::armeb ||
           Arch == Triple::thumb || Arch == Triple::thumbeb;
  }

  // void addTargetSpecificPasses(PassManagerBase &PM) const override {
  //   // Function return is a pseudo-instruction that needs to be expanded
  //   PM.add(createAArch64ExpandPseudoPass());
  // }
};

} // namespace

static ExegesisTarget *getTheExegesisARMTarget() {
  static ExegesisARMTarget Target;
  return &Target;
}

void InitializeARMExegesisTarget() {
  ExegesisTarget::registerTarget(getTheExegesisARMTarget());
}

} // namespace exegesis
} // namespace llvm
