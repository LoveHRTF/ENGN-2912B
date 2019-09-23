	.text
	.align 4,0x90
	.globl __Z4funci
__Z4funci:
LFB1505:
	imull	%edi, %edi
	movl	%edi, %eax
	ret
LFE1505:
	.section __TEXT,__text_startup,regular,pure_instructions
	.align 4
	.globl _main
_main:
LFB1506:
	subq	$8, %rsp
LCFI0:
	movq	8(%rsi), %rdi
	call	_atoi
	movq	__ZSt4cout@GOTPCREL(%rip), %rdi
	movl	%eax, %esi
	imull	%eax, %esi
	imull	%esi, %esi
	imull	%esi, %esi
	call	__ZNSolsEi
	movq	%rax, %rdi
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	xorl	%eax, %eax
	addq	$8, %rsp
LCFI1:
	ret
LFE1506:
	.align 4
__GLOBAL__sub_I_main.cpp:
LFB1829:
	leaq	__ZStL8__ioinit(%rip), %rdi
	subq	$8, %rsp
LCFI2:
	call	__ZNSt8ios_base4InitC1Ev
	movq	__ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	addq	$8, %rsp
LCFI3:
	leaq	___dso_handle(%rip), %rdx
	leaq	__ZStL8__ioinit(%rip), %rsi
	jmp	___cxa_atexit
LFE1829:
	.static_data
__ZStL8__ioinit:
	.space	1
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB1505-.
	.set L$set$2,LFE1505-LFB1505
	.quad L$set$2
	.byte	0
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$3,LEFDE3-LASFDE3
	.long L$set$3
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB1506-.
	.set L$set$4,LFE1506-LFB1506
	.quad L$set$4
	.byte	0
	.byte	0x4
	.set L$set$5,LCFI0-LFB1506
	.long L$set$5
	.byte	0xe
	.byte	0x10
	.byte	0x4
	.set L$set$6,LCFI1-LCFI0
	.long L$set$6
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$7,LEFDE5-LASFDE5
	.long L$set$7
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB1829-.
	.set L$set$8,LFE1829-LFB1829
	.quad L$set$8
	.byte	0
	.byte	0x4
	.set L$set$9,LCFI2-LFB1829
	.long L$set$9
	.byte	0xe
	.byte	0x10
	.byte	0x4
	.set L$set$10,LCFI3-LCFI2
	.long L$set$10
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE5:
	.mod_init_func
	.align 3
	.quad	__GLOBAL__sub_I_main.cpp
	.constructor
	.destructor
	.align 1
	.subsections_via_symbols
