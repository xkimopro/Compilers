	.text
	.file	"Llama program"
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2               # -- Begin function main
.LCPI0_0:
	.long	1082969293              # float 4.4000001
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
<<<<<<< Updated upstream
	pushq	%rax
	.cfi_def_cfa_offset 16
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
=======
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	flds	.LCPI0_0(%rip)
	fstpt	(%rsp)
>>>>>>> Stashed changes
	callq	writeReal
	movl	$.Lnl, %edi
	callq	writeString
	xorl	%edi, %edi
	callq	writeBoolean
	xorl	%edi, %edi
	callq	writeBoolean
	movl	$.Lnl, %edi
	callq	writeString
	movl	$119, %edi
	callq	writeChar
	movl	$.Lnl, %edi
	callq	writeString
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.Lvars,@object          # @vars
	.local	.Lvars
	.comm	.Lvars,104,16
	.type	.Lnl,@object            # @nl
	.section	.rodata,"a",@progbits
.Lnl:
	.asciz	"\n"
	.size	.Lnl, 2

	.section	".note.GNU-stack","",@progbits
