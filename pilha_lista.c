#include <stdio.h>
#include <stdlib.h>
#include "pilha_lista.h"

Pilha* pilha_cria ()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p==NULL) exit (1);
    p->topo = NULL;
    return p;
}

void pilha_push (Pilha* p, char valor)
{
    p->topo = lista_insere (p->topo, valor);
}


char pilha_pop (Pilha* p)
{
    char *v;
    if (pilha_vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    v = (char*)p->topo;
    p->topo = lista_retira_primeiro (p->topo);
    
    return *v;
}

int pilha_vazia (Pilha* p)
{
    return lista_vazia(p->topo);
}

void pilha_libera (Pilha* p)
{
    lista_libera(p->topo);
    free(p);
}

void pilha_imprimir(Pilha * p) {
    lista_imprime (p->topo);
}

