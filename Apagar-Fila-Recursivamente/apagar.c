#include "item.h"
#include "fila.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apagar_nos_recursivamente(NO *no);

void fila_apagar(FILA **f)
{
    if (f == NULL || *f == NULL)
    {
        return;
    }

    apagar_nos_recursivamente((*f)->inicio);

    free(*f);
    *f = NULL;
}

void apagar_nos_recursivamente(NO *no)
{
    if (no == NULL)
    {
        return;
    }
    apagar_nos_recursivamente(no->proximo);
    item_apagar(&no->item);
    free(no);
    no = NULL;
}
