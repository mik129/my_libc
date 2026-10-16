#include "my_libc.h"

int
my_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = b1;
	p2 = b2;
	while (len > 0) {
		if (*p1 != *p2) {
			return (*p1 - *p2);
		}
		p1++;
		p2++;
		len--;
	}
	return (0);
}