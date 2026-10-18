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
char	*my_strchr(const char *s, int c);
char	*my_strrchr(const char *s, int c);
char	*my_strstr(const char *haystack, const char *needle);
void	*my_memset(void *b, int c, size_t len);
void	*my_memcpy(void *dst, const void *src, size_t len);
void	*my_memmove(void *dst, const void *src, size_t len);
int	 my_memcmp(const void *b1, const void *b2, size_t len);
void	*my_memchr(const void *b, int c, size_t len);
char	*my_strdup(const char *s);
char	*my_strtok(char *str, const char *delim);
size_t	 my_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	 my_strlcat(char *dst, const char *src, size_t dstsize);
void	 my_explicit_bzero(void *buf, size_t len);
void	*my_reallocarray(void *ptr, size_t nmemb, size_t size);
int	 my_isalpha(int c);

#endif