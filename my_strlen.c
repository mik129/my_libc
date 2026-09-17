#include "my_libc.h"

size_t
my_strlen(const char *s)
{
 size_t compteur = 0;

 while (*s != '\0') {
 compteur += 1;
 s++;
 }
 return compteur;
}
