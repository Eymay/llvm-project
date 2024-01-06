# Use LLVM_HEADERS for each `tablegen(LLVM)` in subdirectories
# LLVM_HEADERS_TABLEGEN points to `llvm-min-tblgen`
set(LLVM_TABLEGEN_PROJECT LLVM_HEADERS)
add_subdirectory(JITLink)
