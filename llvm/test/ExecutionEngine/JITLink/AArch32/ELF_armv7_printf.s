// RUN: llvm-mc -triple=thumbv7-none-linux-gnueabi -arm-add-build-attributes -filetype=obj -o %t.o %s
// RUN: llvm-jitlink -noexec -slab-address 0x76ff0000 -slab-allocate 10Kb -slab-page-size 4096 \
// RUN:                           -abs printf=0x76bbe880 -show-entry-es %t.o | FileCheck %s

// Check that main and printf are arm symbols (with LSB clear)
//
// CHECK-LABEL: Symbol table:
// CHECK-NEXT:    "main":   0x{{[0-9a-f]+[02468ace]}} [Callable] Ready
// CHECK-NEXT:    "printf": 0x76bbe880 [Data] Ready


	.globl	main
	.p2align	2
	.type	main,%function
	.code	32
main:
	.fnstart
	.save	{r11, lr}
	push	{r11, lr}
	.setfp	r11, sp
	mov	r11, sp
	.pad	#8
	sub	sp, sp, #8
	movw	r0, #0
	str	r0, [sp, #4]
	ldr	r0, .LCPI0_0
.LPC0_0:
	add	r0, pc, r0
	bl	printf
	movw	r0, #0
	mov	sp, r11
	pop	{r11, pc}

	.p2align	2
.LCPI0_0:
	.long	.L.str-(.LPC0_0+8)
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cantunwind
	.fnend

	.type	.L.str,%object
	.section	.rodata.str1.1,"aMS",%progbits,1
.L.str:
	.asciz	"Hello AArch32!\n"
	.size	.L.str, 16
