#include "my_libc.h"

size_t
my_strlen(const char *s)
{
    size_t n = 0;

    while (*s) {
        n++;
        s++;
    }
    return n;
}
