	.text
	.file	"Llama program"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function main
.LCPI0_0:
	.quad	4616639978017495450     # double 4.4000000000000004
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$33, %edi
	callq	writeInteger
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	writeReal
	movl	$.Lnl, %edi
	callq	writeString
	xorl	%eax, %eax
	popq	%rcx
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
