#include "my_libc.h"

char *
my_strcpy(char *dst, const char *src)
{
	char *save;

	save = dst;
	while ((*dst++ = *src++) != '\0')
		;
	return (save);
}
