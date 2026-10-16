#include "my_libc.h"
#include <stdlib.h>

char *
my_strdup(const char *s)
{
	size_t len;
	char *copy;

	len = my_strlen(s) + 1;
	copy = malloc(len);
	if (copy == NULL)
		return (NULL);
	my_memcpy(copy, s, len);
	return (copy);
}