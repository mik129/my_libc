#include "my_libc.h"

void *
my_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	const unsigned char *s;

	d = dst;
	s = src;
	if (d < s) {
		while (len > 0) {
			*d++ = *s++;
			len--;
		}
	} else if (d > s) {
		d += len;
		s += len;
		while (len > 0) {
			*--d = *--s;
			len--;
		}
	}
	return (dst);
}