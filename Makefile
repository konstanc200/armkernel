main:
	arm-linux-gnueabi-as --warn --fatal-warnings -march=armv5t src/boot.s -o build/boot.o
	arm-linux-gnueabi-ld build/boot.o -Ttext=0 -o build/boot.elf
	arm-linux-gnueabi-objdump -D build/boot.elf > build/boot.list

run: 
	qemu-system-arm -M versatilepb -m 128M -nographic -kernel build/boot.elf

clear: 
	find build -mindepth 1 -delete

