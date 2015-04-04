#ifndef __SYSTEM_H
#define __SYSTEM_H



typedef unsigned char	uint8_t;
typedef unsigned short	uint16_t;
typedef unsigned long	uint32_t;

typedef unsigned char	u8int;
typedef unsigned short	u16int;
typedef unsigned long	u32int;

/* This defines what the stack looks like after an ISR was running */
struct regs
{
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;    
};

/* X86.C */
unsigned char inportb (unsigned short _port);
void outportb (unsigned short _port, unsigned char _data);
void disable_interrupts();
void enable_interrupts();

/* GDT.C */
void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
void gdt_install();

/* IDT.C */
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void idt_install();

/* ISRS.C */
void isrs_install();

/* IRQ.C */
void irq_install_handler(int irq, void (*handler)(struct regs *r));
void irq_uninstall_handler(int irq);
void irq_install();

/* PANIC.C */
void panic(const char * s);

/* TIMER.C */
void init_timer(u32int frequency);




#endif
