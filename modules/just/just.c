/* 
 * Copyright (C) 2009-2010 Jonathan F. Jao
 * Jonathan's Uber Shell Terminal Module for New Jonax Kernel
 * Transition to kernel module on Saturday January 16th 2009
 *
 */
#include <jonax/kprintf.h>
#include <jonax/system.h>
#include <jonax/devio.h>
#include <string.h>


void JUST(unsigned char *command)
{
	if(strcmp(command,"hello")==0)
	{
		kprintf("Hello World!!!");
	}
	else if(strcmp(command,"help")==0)
	{
		kprintf("Help!!!");
	}
	else if(strcmp(command,"man")==0)
	{
		kprintf("Which manual page do you want?");
	}
	else if(strcmp(command,"cls")==0)
	{
		cls();
	}
	else if(strcmp(command,"info")==0)
	{
		kprintf("\nWelcome to the New Jonax Kernel\n");
		kprintf("(c) 2009-2010 Jonathan Jao\n\n\n");
		kprintf("You are using Jonathan Jao's Uber Shell Terminal");
	}
	else if(strcmp(command,"shutdown")==0)
	{

	}
	else if(strcmp(command,"kill_cpu")==0)
	{
		cls();
		kprintf("You may power off now.");
		asm volatile("HLT");
	}
	else
	{
		kprintf("Unrecognized Command");
	}

}
