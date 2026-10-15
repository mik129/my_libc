#include "my_libc.h"

char *
my_strrchr(const char *s, int c)
{
	const char *last;

	last = NULL;
	do {
		if (*s == (char)c)
			last = s;
	} while (*s++ != '\0');
	return ((char *)last);
}