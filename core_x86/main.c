/* Copyright (C) 2009-2010 Jonathan F. Jao */

#include <jonax/system.h>
#include <jonax/devio.h>
#include <jonax/kprintf.h>

int main()
{
	int i;

	gdt_install();
	idt_install();
	isrs_install();
	irq_install();
	__asm__ __volatile__ ("sti");
	
	init_dev();
	init_timer(50); // Initialise timer to 50Hz

	unsigned char command[1024];
	kprintf("Welcome to the New Jonax Kernel\n");
	kprintf("Copyright (C) 2009-2010, 2015 Jonathan Jao\n\n\n");
	do
	{
		kprintf("\nJUST~$:");
		do_scan(command);
		JUST(command);
	}
	while(1);

}

