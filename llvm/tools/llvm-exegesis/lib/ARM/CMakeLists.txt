include_directories(
  ${LLVM_MAIN_SRC_DIR}/lib/Target/ARM
  ${LLVM_BINARY_DIR}/lib/Target/ARM
  )

set(LLVM_LINK_COMPONENTS
  ARM
  CodeGenTypes
  Core
  Exegesis
  MC
  Support
  )

add_llvm_library(LLVMExegesisARM
  DISABLE_LLVM_LINK_LLVM_DYLIB
  STATIC
  Target.cpp

  DEPENDS
  intrinsics_gen
  ARMCommonTableGen
  )
