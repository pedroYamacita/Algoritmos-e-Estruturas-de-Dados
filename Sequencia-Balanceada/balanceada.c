#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Pilha.h"
#include "item.h"

bool balanceada(char *sequencia)
{

    PILHA *p = pilha_criar();

    for (int i = 0; sequencia[i] != '\0'; i++)
    {
        char c = sequencia[i];
        // vamos empilhar as aberturas e desempilhar conforme lemos fechamentos
        if (c == '(' || c == '{' || c == '[')
        {
            pilha_empilhar(p, item_criar(c));
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            // se ja começarmos fechando ou a pilha ja tiver sido esvaziada, a sequencia nao é balanceada
            if (pilha_vazia(p))
            {
                pilha_apagar(&p);
                return false;
            }
            // desempilhando quando fechamos algo
            ITEM *topo = pilha_desempilhar(p);
            char abertura = item_get_chave(topo);
            item_apagar(&topo);
            // se a ordem de fechamento e abertura nao bate a sequencia nao é balanceada
            if ((c == ')' && abertura != '(') || (c == '}' && abertura != '{') || (c == ']' && abertura != '['))
            {
                pilha_apagar(&p);
                return false;
            }
        }
    }
    bool deu_certo = pilha_vazia(p);

    if (deu_certo)
    {
        return true;
    }
    else
    {
        return false;
    }
    return deu_certo;
}