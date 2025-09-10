#include "item.h"
#include "fila.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fila_apagar(FILA **f)
{
    if (f == NULL || *f == NULL)
    {
        return;
    }
    ITEM *frente = NULL;
    while ((frente = fila_remover(*f)) != NULL)
    {
        item_apagar(&frente);
    }

    free(*f);
    *f = NULL;
    fila_apagar(f);
}