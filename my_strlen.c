#include "my_libc.h"

size_t
my_strlen(const char *s)
{
        size_t n;

        n = 0;
        while (s[n] != '\0')
                n++;
        return n;
}
