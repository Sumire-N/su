cmd_arch/x86/purgatory/string.o := gcc -Wp,-MD,arch/x86/purgatory/.string.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/6/include -I/home/kernel/COD/linux/arch/x86/include -I./arch/x86/include/generated/uapi -I./arch/x86/include/generated  -I/home/kernel/COD/linux/include -I./include -I/home/kernel/COD/linux/arch/x86/include/uapi -I/home/kernel/COD/linux/include/uapi -I./include/generated/uapi -include /home/kernel/COD/linux/include/linux/kconfig.h -I/home/kernel/COD/linux/arch/x86/purgatory -Iarch/x86/purgatory -D__KERNEL__ -fno-pie -fno-strict-aliasing -Wall -Wstrict-prototypes -fno-zero-initialized-in-bss -fno-builtin -ffreestanding -c -MD -Os -mcmodel=large -m64 -fno-PIE    -DKBUILD_BASENAME='"string"'  -DKBUILD_MODNAME='"string"' -c -o arch/x86/purgatory/.tmp_string.o /home/kernel/COD/linux/arch/x86/purgatory/string.c

source_arch/x86/purgatory/string.o := /home/kernel/COD/linux/arch/x86/purgatory/string.c

deps_arch/x86/purgatory/string.o := \
  /home/kernel/COD/linux/arch/x86/purgatory/../boot/string.c \
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
  /home/kernel/COD/linux/arch/x86/purgatory/../boot/ctype.h \

arch/x86/purgatory/string.o: $(deps_arch/x86/purgatory/string.o)

$(deps_arch/x86/purgatory/string.o):
