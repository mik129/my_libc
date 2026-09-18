#include "my_libc.h"

char *
my_strcat(char *dst, const char *src)
{
	char *s;

	s = dst;
	while (*s != '\0')
		s++;
	while ((*s++ = *src++) != '\0')
		;
	return (dst);
}
