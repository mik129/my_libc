#include "my_libc.h"

char *
my_strtok(char *str, const char *delim)
{
	static char *last;
	char *token;

	if (str == NULL)
		str = last;
	if (str == NULL)
		return (NULL);
	while (*str != '\0' && my_strchr(delim, *str) != NULL)
		str++;
	if (*str == '\0') {
		last = NULL;
		return (NULL);
	}
	token = str;
	while (*str != '\0' && my_strchr(delim, *str) == NULL)
		str++;
	if (*str != '\0') {
		*str = '\0';
		last = str + 1;
	} else {
		last = NULL;
	}
	return (token);
}