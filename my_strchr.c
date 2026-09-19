#include "my_libc.h"

char *
my_strchr(const char *s, int c)
{
	while (*s != (char)c) {
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
