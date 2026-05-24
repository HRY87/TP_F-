#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"

int copiarCadena(char* dest, const char* src, size_t n)
{
    char* d = dest;
    char* s = (char*)src;
    size_t cont = 0;

    if(!d || !src)
        return ERR_CAD;

    /**Es n - 1, ya que hay que dejar espacio para el \0**/
    while(*s && cont < n - 1)
    {
        *d = *s;
        d++;
        s++;
        cont++;
    }

    *d = '\0';

    return TODO_OK;
}
