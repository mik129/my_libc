#ifndef MY_LIBC_H
#define MY_LIBC_H

#include <stddef.h>

size_t	 my_strlen(const char *s);
char	*my_strcpy(char *dst, const char *src);
char	*my_strncpy(char *dst, const char *src, size_t n);

#endif
