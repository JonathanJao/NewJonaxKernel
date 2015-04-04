#ifndef _STRING_H_
#define _STRING_H_

#ifndef NULL
#define NULL ((void *) 0)
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef int size_t;
#endif

int strcmp(char *s, char *t);
void strcpy(unsigned char *s, unsigned char *t);
size_t strlen(unsigned char *str);
void *memcpy(void *dest, const void *src, size_t count);
void *memset(void *dest, char val, size_t count);
unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);

#endif
