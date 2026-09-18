#include "my_libc.h"

char *
my_strncat(char *dst, const char *src, size_t n)
{
	if (n != 0) {
		char *d;
		const char *s;

		d = dst;
		s = src;
		while (*d != '\0')
			d++;
		do {
			if ((*d++ = *s++) == '\0') {
				return (dst);
			}
		} while (--n != 0);
		*d = '\0';
	}
	return (dst);
}
