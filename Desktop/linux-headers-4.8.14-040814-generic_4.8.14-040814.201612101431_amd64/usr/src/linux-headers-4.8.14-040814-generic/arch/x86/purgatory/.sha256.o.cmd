cmd_arch/x86/purgatory/sha256.o := gcc -Wp,-MD,arch/x86/purgatory/.sha256.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/6/include -I/home/kernel/COD/linux/arch/x86/include -I./arch/x86/include/generated/uapi -I./arch/x86/include/generated  -I/home/kernel/COD/linux/include -I./include -I/home/kernel/COD/linux/arch/x86/include/uapi -I/home/kernel/COD/linux/include/uapi -I./include/generated/uapi -include /home/kernel/COD/linux/include/linux/kconfig.h -I/home/kernel/COD/linux/arch/x86/purgatory -Iarch/x86/purgatory -D__KERNEL__ -fno-pie -fno-strict-aliasing -Wall -Wstrict-prototypes -fno-zero-initialized-in-bss -fno-builtin -ffreestanding -c -MD -Os -mcmodel=large -m64 -fno-PIE    -DKBUILD_BASENAME='"sha256"'  -DKBUILD_MODNAME='"sha256"' -c -o arch/x86/purgatory/.tmp_sha256.o /home/kernel/COD/linux/arch/x86/purgatory/sha256.c

source_arch/x86/purgatory/sha256.o := /home/kernel/COD/linux/arch/x86/purgatory/sha256.c

deps_arch/x86/purgatory/sha256.o := \
  /home/kernel/COD/linux/include/linux/bitops.h \
  /home/kernel/COD/linux/arch/x86/include/uapi/asm/types.h \
  /home/kernel/COD/linux/include/uapi/asm-generic/types.h \
  /home/kernel/COD/linux/include/asm-generic/int-ll64.h \
  /home/kernel/COD/linux/include/uapi/asm-generic/int-ll64.h \
  /home/kernel/COD/linux/arch/x86/include/uapi/asm/bitsperlong.h \
  /home/kernel/COD/linux/include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  /home/kernel/COD/linux/include/uapi/asm-generic/bitsperlong.h \
  /home/kernel/COD/linux/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/x86/64.h) \
    $(wildcard include/config/x86/cmov.h) \
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
  /home/kernel/COD/linux/include/uapi/linux/types.h \
  /home/kernel/COD/linux/include/uapi/linux/posix_types.h \
  /home/kernel/COD/linux/include/linux/stddef.h \
  /home/kernel/COD/linux/include/uapi/linux/stddef.h \
  /home/kernel/COD/linux/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/x86/32.h) \
  /home/kernel/COD/linux/arch/x86/include/uapi/asm/posix_types_64.h \
  /home/kernel/COD/linux/include/uapi/asm-generic/posix_types.h \
  /home/kernel/COD/linux/arch/x86/include/asm/alternative.h \
    $(wildcard include/config/smp.h) \
  /home/kernel/COD/linux/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
  /home/kernel/COD/linux/include/linux/stringify.h \
  /home/kernel/COD/linux/arch/x86/include/asm/asm.h \
  /home/kernel/COD/linux/arch/x86/include/asm/rmwcc.h \
  /home/kernel/COD/linux/arch/x86/include/asm/barrier.h \
    $(wildcard include/config/x86/ppro/fence.h) \
  /home/kernel/COD/linux/arch/x86/include/asm/nops.h \
    $(wildcard include/config/mk7.h) \
    $(wildcard include/config/x86/p6/nop.h) \
  /home/kernel/COD/linux/include/asm-generic/barrier.h \
  /home/kernel/COD/linux/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  /home/kernel/COD/linux/include/asm-generic/bitops/sched.h \
  /home/kernel/COD/linux/arch/x86/include/asm/arch_hweight.h \
  /home/kernel/COD/linux/arch/x86/include/asm/cpufeatures.h \
  /home/kernel/COD/linux/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/x86/minimum/cpu/family.h) \
    $(wildcard include/config/math/emulation.h) \
    $(wildcard include/config/x86/pae.h) \
    $(wildcard include/config/x86/cmpxchg64.h) \
    $(wildcard include/config/x86/use/3dnow.h) \
    $(wildcard include/config/matom.h) \
    $(wildcard include/config/paravirt.h) \
  /home/kernel/COD/linux/arch/x86/include/asm/disabled-features.h \
    $(wildcard include/config/x86/intel/mpx.h) \
    $(wildcard include/config/x86/intel/memory/protection/keys.h) \
  /home/kernel/COD/linux/include/asm-generic/bitops/const_hweight.h \
  /home/kernel/COD/linux/include/asm-generic/bitops/le.h \
  /home/kernel/COD/linux/arch/x86/include/uapi/asm/byteorder.h \
  /home/kernel/COD/linux/include/linux/byteorder/little_endian.h \
  /home/kernel/COD/linux/include/uapi/linux/byteorder/little_endian.h \
  /home/kernel/COD/linux/include/linux/swab.h \
  /home/kernel/COD/linux/include/uapi/linux/swab.h \
  /home/kernel/COD/linux/arch/x86/include/uapi/asm/swab.h \
  /home/kernel/COD/linux/include/linux/byteorder/generic.h \
  /home/kernel/COD/linux/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /home/kernel/COD/linux/arch/x86/purgatory/sha256.h \
  /home/kernel/COD/linux/include/crypto/sha.h \
  /home/kernel/COD/linux/arch/x86/purgatory/../boot/string.h \

arch/x86/purgatory/sha256.o: $(deps_arch/x86/purgatory/sha256.o)

$(deps_arch/x86/purgatory/sha256.o):
