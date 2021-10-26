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
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	flds	.LCPI0_0(%rip)
	fstpt	(%rsp)
	callq	writeReal
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
	.asciz	"\n\n"
	.size	.Lnl, 3

	.section	".note.GNU-stack","",@progbits
