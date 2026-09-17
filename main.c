#include <stdio.h>
#include "my_libc.h"

int
main(void)
{
        printf("%zu\n", my_strlen("hello"));
        printf("%zu\n", my_strlen(""));
        printf("%zu\n", my_strlen("Eddy"));
        return 0;
}
