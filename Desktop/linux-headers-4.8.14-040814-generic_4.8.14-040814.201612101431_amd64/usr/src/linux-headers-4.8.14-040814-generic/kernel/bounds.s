	.file	"bounds.c"
# GNU C89 (Ubuntu 6.2.0-5ubuntu12) version 6.2.0 20161005 (x86_64-linux-gnu)
#	compiled by GNU C version 6.2.0 20161005, GMP version 6.1.1, MPFR version 3.1.5, MPC version 1.0.3, isl version 0.15
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -nostdinc -I /home/kernel/COD/linux/arch/x86/include
# -I ./arch/x86/include/generated/uapi -I ./arch/x86/include/generated
# -I /home/kernel/COD/linux/include -I ./include
# -I /home/kernel/COD/linux/arch/x86/include/uapi
# -I /home/kernel/COD/linux/include/uapi -I ./include/generated/uapi
# -I /home/kernel/COD/linux/. -I . -imultiarch x86_64-linux-gnu
# -D __KERNEL__ -D CONFIG_X86_X32_ABI -D CONFIG_AS_CFI=1
# -D CONFIG_AS_CFI_SIGNAL_FRAME=1 -D CONFIG_AS_CFI_SECTIONS=1
# -D CONFIG_AS_FXSAVEQ=1 -D CONFIG_AS_SSSE3=1 -D CONFIG_AS_CRC32=1
# -D CONFIG_AS_AVX=1 -D CONFIG_AS_AVX2=1 -D CONFIG_AS_SHA1_NI=1
# -D CONFIG_AS_SHA256_NI=1 -D CC_USING_FENTRY -D CC_HAVE_ASM_GOTO
# -D KBUILD_BASENAME="bounds" -D KBUILD_MODNAME="bounds"
# -isystem /usr/lib/gcc/x86_64-linux-gnu/6/include
# -include /home/kernel/COD/linux/include/linux/kconfig.h
# -MD kernel/.bounds.s.d /home/kernel/COD/linux/kernel/bounds.c -mno-sse
# -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -m64 -mno-80387 -mno-fp-ret-in-387
# -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic
# -mno-red-zone -mcmodel=kernel -maccumulate-outgoing-args -mfentry
# -march=x86-64 -auxbase-strip kernel/bounds.s -O2 -Wall -Wundef
# -Wstrict-prototypes -Wno-trigraphs -Werror=implicit-function-declaration
# -Wno-format-security -Wno-sign-compare -Wno-maybe-uninitialized
# -Wno-frame-address -Wframe-larger-than=1024 -Wno-unused-but-set-variable
# -Wunused-const-variable=0 -Wdeclaration-after-statement -Wno-pointer-sign
# -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time
# -Werror=incompatible-pointer-types -std=gnu90 -p -fno-strict-aliasing
# -fno-common -fno-pie -falign-jumps=1 -falign-loops=1 -funit-at-a-time
# -fno-asynchronous-unwind-tables -fno-delete-null-pointer-checks
# -fstack-protector-strong -fno-omit-frame-pointer
# -fno-optimize-sibling-calls -fno-var-tracking-assignments
# -fno-inline-functions-called-once -fno-strict-overflow -fconserve-stack
# -fverbose-asm --param allow-store-data-races=0 -fstack-protector-strong
# options enabled:  -faggressive-loop-optimizations -falign-labels
# -fauto-inc-dec -fbranch-count-reg -fcaller-saves
# -fchkp-check-incomplete-type -fchkp-check-read -fchkp-check-write
# -fchkp-instrument-calls -fchkp-narrow-bounds -fchkp-optimize
# -fchkp-store-bounds -fchkp-use-static-bounds
# -fchkp-use-static-const-bounds -fchkp-use-wrappers
# -fcombine-stack-adjustments -fcompare-elim -fcprop-registers
# -fcrossjumping -fcse-follow-jumps -fdefer-pop -fdevirtualize
# -fdevirtualize-speculatively -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -fexpensive-optimizations
# -fforward-propagate -ffunction-cse -fgcse -fgcse-lm -fgnu-runtime
# -fgnu-unique -fguess-branch-probability -fhoist-adjacent-loads -fident
# -fif-conversion -fif-conversion2 -findirect-inlining -finline
# -finline-atomics -finline-small-functions -fipa-cp -fipa-cp-alignment
# -fipa-icf -fipa-icf-functions -fipa-icf-variables -fipa-profile
# -fipa-pure-const -fipa-reference -fipa-sra -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots
# -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flra-remat -flto-odr-type-merging
# -fmath-errno -fmerge-constants -fmerge-debug-strings
# -fmove-loop-invariants -foptimize-strlen -fpartial-inlining -fpeephole
# -fpeephole2 -fplt -fprefetch-loop-arrays -fprofile -free
# -freg-struct-return -freorder-blocks -freorder-functions
# -frerun-cse-after-loop -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fschedule-insns2 -fsemantic-interposition -fshow-column -fshrink-wrap
# -fsigned-zeros -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-backprop
# -fssa-phiopt -fstack-protector-strong -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
# -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
# -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim
# -ftree-dce -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pre
# -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr
# -ftree-sra -ftree-switch-conversion -ftree-tail-merge -ftree-ter
# -ftree-vrp -funit-at-a-time -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -maccumulate-outgoing-args -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store -mfentry
# -mfxsr -mglibc -mieee-fp -mlong-double-80 -mno-fancy-math-387
# -mno-red-zone -mno-sse4 -mpush-args -mskip-rax-setup
# -mtls-direct-seg-refs -mvzeroupper

	.text
	.p2align 4,,15
	.globl	foo
	.type	foo, @function
foo:
1:	call	__fentry__
	pushq	%rbp	#
	movq	%rsp, %rbp	#,
#APP
# 18 "/home/kernel/COD/linux/kernel/bounds.c" 1
	
->NR_PAGEFLAGS $25 __NR_PAGEFLAGS	#
# 0 "" 2
# 19 "/home/kernel/COD/linux/kernel/bounds.c" 1
	
->MAX_NR_ZONES $5 __MAX_NR_ZONES	#
# 0 "" 2
# 21 "/home/kernel/COD/linux/kernel/bounds.c" 1
	
->NR_CPUS_BITS $8 ilog2(CONFIG_NR_CPUS)	#
# 0 "" 2
# 23 "/home/kernel/COD/linux/kernel/bounds.c" 1
	
->SPINLOCK_SIZE $4 sizeof(spinlock_t)	#
# 0 "" 2
#NO_APP
	popq	%rbp	#
	ret
	.size	foo, .-foo
	.ident	"GCC: (Ubuntu 6.2.0-5ubuntu12) 6.2.0 20161005"
	.section	.note.GNU-stack,"",@progbits
