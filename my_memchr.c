#include "my_libc.h"

void *
my_memchr(const void *b, int c, size_t len)
{
	const unsigned char *p;

	p = b;
	while (len > 0) {
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
		len--;
	}
	return (NULL);
}