#include "memory.h"


unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
    register int i;
    for (i = 0; i < count; ++i)
    {
	dest[i] = src[i];
    }
    return dest;
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
     register int i;
     for (i = 0; i < count; ++i)
     {
	dest[i] = val;
     }
     return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
     register int i;
     for (i = 0; i < count; ++i)
     {
	dest[i] = val;
     }
     return dest;
}

unsigned short *memcpyw(unsigned short *dest, const unsigned short *src, int count)
{
     register int i;
     for (i = 0; i < count; ++i)
     {
	dest[i] = src[i];
     }
     return dest;
}


int strlen(const char *str)
{
     register int len = 0;
     while (str[len] != '\0')
     {
	++len;
     }
     return len;
}
