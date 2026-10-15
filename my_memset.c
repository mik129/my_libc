#include "my_libc.h"

void *
my_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = b;
	while (len > 0) {
		*p++ = (unsigned char)c;
		len--;
	}
	return (b);
}