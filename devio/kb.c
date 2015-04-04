/* Copyright (C) 2009-2010 Jonathan F. Jao */

#include <jonax/system.h>
#include <jonax/devio.h>
#include <jonax/kprintf.h>
#include <string.h>
#include "kb_layout.h"

unsigned char command[1024], buffer[1024];
unsigned int com_place = 0;
short int r_shift = 0, l_shift = 0, has_scan = 0, do_scanned = 0;
unsigned char scancode;

void keyboard_handler(struct regs *r)
{
	/* Transfer character from the keyboard's data buffer to scancode*/
	scancode = inportb(0x60);

	if (has_scan == 0 && do_scanned == 1)/*if the scan buffer for kb is empty and do_scan() is on */
	{
		if (scancode & 0x80)/*if key is being released*/
		{
			switch(kbdus[scancode])/*201 & 202 = shifts */
			{
				case 201:
					l_shift = 0;
					break;
				case 202:
					r_shift = 0;
					break;
			}
		}
		else/*if key is being pressed*/
		{
			switch(kbdus[scancode])
			{
				case '\b': //backspace
					if (com_place >=1)
					{
						putchar(kbdus[scancode]);
						kprintf(" ");
						putchar(kbdus[scancode]);
						com_place--;
						command[com_place] = '\0';
					}
					break;
				case '\n': //new line
					putchar(kbdus[scancode]);
					has_scan = 1; /* store in a buffer until do scan is called*/
					strcpy(buffer,command);
					while(com_place != 0)
					{
						command[com_place] = '\0';
						com_place--;
					}
					command[com_place] = '\0';
					break;
				case 201: //left shift
					l_shift = 1;
					break;
				case 202: //right shift
					r_shift = 1;
					break;
				default:
					if (l_shift == 0 && r_shift == 0)/*if shifts are not pressed*/
					{
						putchar(kbdus[scancode]);
						command[com_place] = kbdus[scancode];
					}
					else/*if one of the shifts are pressed*/
					{
						putchar(kbdus_shift[scancode]);
						command[com_place] = kbdus_shift[scancode];
					}
					com_place++;
					kprintf("");/*i have to put this here for some reason... Otherwise nothing will work(dunno y)*/
					break;
			}// switch statement
		}//if key is being pressed or released
	}// if waiting for a scan
}// keyboard handler()

int do_scan(unsigned char *input)/* equivalent of gets() ? */
{
	do_scanned = 1;
	
	do_scan_loop:/* waiting for input*/
	if (has_scan == 0) 
		goto do_scan_loop;
	
	has_scan = 0;
	do_scanned = 0;
	
	strcpy(input,buffer);
	
	return 1;/*success*/
}

/* Installs the keyboard handler into IRQ1 */
void keyboard_install()
{
	irq_install_handler(1, keyboard_handler);

}
