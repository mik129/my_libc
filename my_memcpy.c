#include "my_libc.h"

void *
my_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	const unsigned char *s;

	d = dst;
	s = src;
	while (len > 0) {
		*d++ = *s++;
		len--;
	}
	return (dst);
}