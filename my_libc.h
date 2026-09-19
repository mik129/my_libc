#ifndef MY_LIBC_H
#define MY_LIBC_H

#include <stddef.h>

size_t	 my_strlen(const char *s);
char	*my_strcpy(char *dst, const char *src);
char	*my_strncpy(char *dst, const char *src, size_t n);
char	*my_strcat(char *dst, const char *src);
char	*my_strncat(char *dst, const char *src, size_t n);
int	 my_strcmp(const char *s1, const char *s2);
int	 my_strncmp(const char *s1, const char *s2, size_t n);

#endif
