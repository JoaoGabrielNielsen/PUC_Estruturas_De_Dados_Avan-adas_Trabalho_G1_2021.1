#include "listas.h"

typedef struct pilha {
    Lista* topo; 
} Pilha;


Pilha* pilha_cria (void);

void pilha_push (Pilha* p, char valor);

char pilha_pop (Pilha* p);

int pilha_vazia (Pilha* p);

void pilha_libera (Pilha* p);

void pilha_imprimir(Pilha * p);
