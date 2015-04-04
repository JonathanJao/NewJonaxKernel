#include <jonax/system.h>
#include <jonax/kprintf.h>
void panic(const char * s)
{
	kprintf("Kernel panic: %s\n",s);
	for(;;);
}

