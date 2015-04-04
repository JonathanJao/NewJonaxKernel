#include <string.h>

size_t strlen(unsigned char *str)/* modified version from some operating system online */
{
	int retval;
	for(retval = 0; *str != '\0'; str++) retval++;
	return retval;
}

int strcmp(char *s, char *t)/*strcmp written by jonathan jao for JUST(Jonathan's Uber Shell Terminal)*/
{
	int i;
	for	(i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

void strcpy(unsigned char *s, unsigned char *t)/*from "The C Programming Language" by Dennis Ritchie and Brian W. Kernighan */
{
	while ((*s++ = *t++) != '\0')
		;
}

void *memcpy(void *dest, const void *src, size_t count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

void *memset(void *dest, char val, size_t count)
{
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count)
{
    unsigned short *temp = (unsigned short *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}
