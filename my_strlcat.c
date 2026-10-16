#include "my_libc.h"

size_t
my_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char *s;
	char *d;
	size_t n;
	size_t dlen;

	d = dst;
	s = src;
	n = dstsize;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = (size_t)(d - dst);
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + my_strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (size_t)(s - src));
}