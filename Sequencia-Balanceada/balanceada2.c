#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Pilha.h"
#include "item.h"

bool balanceada(char *sequencia)
{
    char *original = sequencia;
    char chave;
    PILHA *p = pilha_criar();

    while (*sequencia != '\0')
    {
        chave = *sequencia;
        pilha_empilhar(p, item_criar(chave));
        sequencia++;
    }
    int tamanho = pilha_tamanho(p);

    if (tamanho % 2 != 0)
    {
        // printf("NÃO BALANCEADO");
        for (int k = 0; k < tamanho; k++)
        {
            ITEM *item = pilha_desempilhar(p);
            item_apagar(&item);
        }
        pilha_apagar(&p);
        return false;
    }

    for (int j = 0; j < tamanho / 2; j++)
    {

        if (original[j] != original[tamanho - j - 1])
        {
            // printf("NÃO BALANCEADO");
            for (int k = 0; k < tamanho; k++)
            {
                ITEM *item = pilha_desempilhar(p);
                item_apagar(&item);
            }
            pilha_apagar(&p);
            return false;
        }
        else
            continue;
    }
    // printf("BALANCEADO");
    for (int k = 0; k < tamanho; k++)
    {
        ITEM *item = pilha_desempilhar(p);
        item_apagar(&item);
    }
    pilha_apagar(&p);
    return true;
}