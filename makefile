SOURCES=./core_x86/gdt.o ./core_x86/idt.o ./core_x86/interrupt.o ./core_x86/irq.o ./core_x86/isrs.o ./core_x86/main.o ./core_x86/start.o ./core_x86/timer.o ./core_x86/x86.o ./devio/console.o ./devio/devio.o ./devio/kb.o ./klibc/kprintf.o ./klibc/panic.o ./klibc/stdio.o ./klibc/string.o ./klibc/vsprintf.o ./modules/just/just.o

CC=gcc
CFLAGS=-m32 -I ./include -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-m elf_i386 -T ./tools/x86_32.ld
ASFLAGS=-felf -dx86_32

all: $(SOURCES) link

qemu:
	qemu-system-x86_64 -fda tools/floppy.img

link:
	ld $(LDFLAGS) -o kernel.bin $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<

image:
	#!/bin/bash
	sudo /sbin/losetup /dev/loop0 tools/floppy.img
	sudo mount /dev/loop0 /mnt
	sudo cp kernel.bin /mnt/kernel.bin
	sudo umount /dev/loop0
	sudo /sbin/losetup -d /dev/loop0

clean:
	rm *.o ./*/*.o ./*/*/*.o ./*/*/*/*.o kernel.bin *~ */*~ */*/*~ */*/*/*~
