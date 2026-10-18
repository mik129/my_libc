#include "my_libc.h"
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

#define MUL_NO_OVERFLOW ((size_t)1 << (sizeof(size_t) * 4))

void *
my_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) &&
	    nmemb > 0 && SIZE_MAX / nmemb < size) {
		errno = ENOMEM;
		return (NULL);
	}
	return (realloc(ptr, nmemb * size));
}