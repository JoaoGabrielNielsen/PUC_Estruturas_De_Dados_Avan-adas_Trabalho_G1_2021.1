#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Lista* lista_cria (void)
{
    return NULL;
}


Lista* lista_insere (Lista* lista, char c)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = c;
    novo->prox = lista;
    return novo;
}


Lista* lista_retira_primeiro (Lista* lista)
{
    Lista* p = lista; /* ponteiro para percorrer a lista */

    /* retira Lista */
    lista = p->prox; /* retira Lista do inicio */
    free(p);
    return lista;
}

void lista_imprime (Lista* lista)
{
    Lista* p;
    for (p = lista; p != NULL; p = p->prox){
        printf("%c\n", p->info);
    }
}


int lista_vazia (Lista* lista)
{
    if (lista == NULL)
        return 1;
    else
        return 0;
}



void lista_libera (Lista* lista) //, void (* libera)(void *))
{
    Lista* p = lista;
    Lista* t;
    while (p != NULL)
    {
        t = p->prox; /* guarda referência p/ próx. Lista */
        //libera(p->info);
        free(p); /* libera a memória apontada por p */
        p = t; /* faz p apontar para o próximo */
    }
}