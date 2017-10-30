cmd_scripts/mod/devicetable-offsets.s := gcc -Wp,-MD,scripts/mod/.devicetable-offsets.s.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/6/include -I/home/kernel/COD/linux/arch/x86/include -I./arch/x86/include/generated/uapi -I./arch/x86/include/generated  -I/home/kernel/COD/linux/include -I./include -I/home/kernel/COD/linux/arch/x86/include/uapi -I/home/kernel/COD/linux/include/uapi -I./include/generated/uapi -include /home/kernel/COD/linux/include/linux/kconfig.h -I/home/kernel/COD/linux/scripts/mod -Iscripts/mod -D__KERNEL__ -fno-pie -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -fno-pie -no-pie -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time -maccumulate-outgoing-args -DCONFIG_X86_X32_ABI -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_SSSE3=1 -DCONFIG_AS_CRC32=1 -DCONFIG_AS_AVX=1 -DCONFIG_AS_AVX2=1 -DCONFIG_AS_SHA1_NI=1 -DCONFIG_AS_SHA256_NI=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -fno-delete-null-pointer-checks -Wno-maybe-uninitialized -Wno-frame-address -O2 --param=allow-store-data-races=0 -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -pg -mfentry -DCC_USING_FENTRY -fno-inline-functions-called-once -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -DCC_HAVE_ASM_GOTO    -DKBUILD_BASENAME='"devicetable_offsets"'  -DKBUILD_MODNAME='"devicetable_offsets"'  -fverbose-asm -S -o scripts/mod/devicetable-offsets.s /home/kernel/COD/linux/scripts/mod/devicetable-offsets.c

source_scripts/mod/devicetable-offsets.s := /home/kernel/COD/linux/scripts/mod/devicetable-offsets.c

deps_scripts/mod/devicetable-offsets.s := \
  /home/kernel/COD/linux/include/linux/kbuild.h \
  /home/kernel/COD/linux/include/linux/mod_devicetable.h \
  /home/kernel/COD/linux/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/kernel/COD/linux/include/uapi/linux/types.h \
  /home/kernel/COD/linux/arch/x86/include/uapi/asm/types.h \
  /home/kernel/COD/linux/include/uapi/asm-generic/types.h \
  /home/kernel/COD/linux/include/asm-generic/int-ll64.h \
  /home/kernel/COD/linux/include/uapi/asm-generic/int-ll64.h \
  /home/kernel/COD/linux/arch/x86/include/uapi/asm/bitsperlong.h \
  /home/kernel/COD/linux/include/asm-generic/bitsperlong.h \
  /home/kernel/COD/linux/include/uapi/asm-generic/bitsperlong.h \
  /home/kernel/COD/linux/include/uapi/linux/posix_types.h \
  /home/kernel/COD/linux/include/linux/stddef.h \
  /home/kernel/COD/linux/include/uapi/linux/stddef.h \
  /home/kernel/COD/linux/include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/kasan.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  /home/kernel/COD/linux/include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /home/kernel/COD/linux/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/x86/32.h) \
  /home/kernel/COD/linux/arch/x86/include/uapi/asm/posix_types_64.h \
  /home/kernel/COD/linux/include/uapi/asm-generic/posix_types.h \
  /home/kernel/COD/linux/include/linux/uuid.h \
  /home/kernel/COD/linux/include/uapi/linux/uuid.h \
  /home/kernel/COD/linux/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /usr/lib/gcc/x86_64-linux-gnu/6/include/stdarg.h \
  /home/kernel/COD/linux/include/uapi/linux/string.h \
  /home/kernel/COD/linux/arch/x86/include/asm/string.h \
  /home/kernel/COD/linux/arch/x86/include/asm/string_64.h \
    $(wildcard include/config/kmemcheck.h) \

scripts/mod/devicetable-offsets.s: $(deps_scripts/mod/devicetable-offsets.s)

$(deps_scripts/mod/devicetable-offsets.s):
