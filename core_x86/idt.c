/* Copyright (C) 2009-2010 Jonathan F. Jao */
#include <jonax/system.h>
#include <string.h>

/* Defines an IDT entry */
struct idt_entry
{
    unsigned short base_lo;
    unsigned short sel;
    unsigned char always0;
    unsigned char flags;
    unsigned short base_hi;
} __attribute__((packed));

struct idt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

/* Only First 32 of 256 entries used. if any undefined IDT entry is hit, it normally
*  will cause an "Unhandled Interrupt" exception. Any descriptor
*  for which the 'presence' bit is cleared (0) will generate an
*  "Unhandled Interrupt" exception */
struct idt_entry idt[256];
struct idt_ptr idtp;

/* This exists in 'interrupt.asm', and is used to load our IDT */
extern void idt_load();

/* Use this function to set an entry in the IDT. Alot simpler
*  than twiddling with the GDT ;) */
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
    /* The interrupt routine's base address */
    idt[num].base_lo = (base & 0xFFFF);
    idt[num].base_hi = (base >> 16) & 0xFFFF;

    /* The segment or 'selector' that this IDT entry will use
    *  is set here, along with any access flags */
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}


static inline void lidt(void* base, uint16_t size)
{
    struct
    {
        uint16_t length;
        uint32_t base;
    } __attribute__((packed)) IDTR;
 
    IDTR.length = size;
    IDTR.base = (uint32_t) base;
    asm ( "lidt (%0)" : : "p"(&IDTR) );
}

/* Installs the IDT */
void idt_install()
{
    /* Sets the special IDT pointer up, just like in 'gdt.c' */
    idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
    idtp.base = &idt;

    /* Clear out the entire IDT, initializing it to zeros */
    memset(&idt, 0, sizeof(struct idt_entry) * 256);

    /* Add any new ISRs to the IDT here using idt_set_gate */



    /* Points the processor's internal register to the new IDT */
    lidt(idtp.base,idtp.limit);
    //idt_load();
    
}

