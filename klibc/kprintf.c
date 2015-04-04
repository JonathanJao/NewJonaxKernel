#include <stdio.h>
#include <stdarg.h>
#include <jonax/kprintf.h>
int kprintf(const char *fmt, ...)
{
	va_list args;
	int ret_val;

	va_start(args, fmt);
	ret_val = printf(fmt, args);
	va_end(args);
	return ret_val;
}
