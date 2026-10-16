#include "my_libc.h"

size_t
my_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char *s;
	size_t n;

	s = src;
	n = dstsize;
	if (n != 0) {
		while (--n != 0) {
			if ((*dst++ = *s++) == '\0')
				break;
		}
	}
	if (n == 0) {
		if (dstsize != 0)
			*dst = '\0';
		while (*s++ != '\0')
			;
	}
	return (size_t)(s - src - 1);
}