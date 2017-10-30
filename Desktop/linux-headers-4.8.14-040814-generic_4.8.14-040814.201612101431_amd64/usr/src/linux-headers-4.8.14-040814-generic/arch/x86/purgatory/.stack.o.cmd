cmd_arch/x86/purgatory/stack.o := gcc -Wp,-MD,arch/x86/purgatory/.stack.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/6/include -I/home/kernel/COD/linux/arch/x86/include -I./arch/x86/include/generated/uapi -I./arch/x86/include/generated  -I/home/kernel/COD/linux/include -I./include -I/home/kernel/COD/linux/arch/x86/include/uapi -I/home/kernel/COD/linux/include/uapi -I./include/generated/uapi -include /home/kernel/COD/linux/include/linux/kconfig.h -D__KERNEL__ -fno-pie -D__ASSEMBLY__ -fno-PIE -fno-pie -m64 -DCONFIG_X86_X32_ABI -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_SSSE3=1 -DCONFIG_AS_CRC32=1 -DCONFIG_AS_AVX=1 -DCONFIG_AS_AVX2=1 -DCONFIG_AS_SHA1_NI=1 -DCONFIG_AS_SHA256_NI=1 -mfentry -DCC_USING_FENTRY -DCC_HAVE_ASM_GOTO   -c -o arch/x86/purgatory/stack.o /home/kernel/COD/linux/arch/x86/purgatory/stack.S

source_arch/x86/purgatory/stack.o := /home/kernel/COD/linux/arch/x86/purgatory/stack.S

deps_arch/x86/purgatory/stack.o := \

arch/x86/purgatory/stack.o: $(deps_arch/x86/purgatory/stack.o)

$(deps_arch/x86/purgatory/stack.o):
