/* Copyright (C) 2009-2010 Jonathan F. Jao */

#include <jonax/system.h>

unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}void disable_interrupts()
{
	asm volatile("cli");
}

void enable_interrupts()
{
	asm volatile("sti");
}
