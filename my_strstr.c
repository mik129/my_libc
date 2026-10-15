#include "my_libc.h"

char *
my_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0') {
		const char *h;
		const char *n;

		h = haystack;
		n = needle;
		while (*h != '\0' && *n != '\0' && *h == *n) {
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}