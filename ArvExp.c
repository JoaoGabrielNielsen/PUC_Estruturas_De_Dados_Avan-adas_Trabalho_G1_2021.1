#include <stdio.h>
#include <string.h>
#include "ArvExp.h"

AvrExp *topo = NULL;

AvrExp *aux1; //criamos essess dois auxiliares para eles apontarem pro topo e ajudarem a manipular a arvore
AvrExp *aux2;

int calc_tipo(char o){
    if (o == '+' || o == '*' || o == '-' || o == '/')
        return 1;
    return 0;
}

AvrExp *cria_no(char c){
    AvrExp *aux = (AvrExp*)malloc(sizeof(AvrExp));
    aux->tipo = calc_tipo(c);
    
    if (aux->tipo){
        aux->valor = atoi(c);
        aux->oper = NULL;
    }
    else{
       aux->valor = NULL;
       aux->oper = c;
    }
    
    aux->esq = NULL;
    aux->dir = NULL;
    aux->pai = NULL;
    
    return aux;
}

//2384-*+

AvrExp faz_arvExp(char *postfix) {
    AvrExp *no;
    int i;
    
    for (i = strlen(postfix)-1; i >= 0; i--) {
        
        no = cria_no(postfix[i]);
        if(topo == NULL){
            topo = no;
            
            aux1 = aux2 = topo; //definimos os dois auxiliares como o topo
        }
        
        else{
            
            if (calc_tipo(postfix[i]) == 1 ) { // se for um operador
                
                if (aux1->dir == NULL) { //se o pai tem um filho a direita disponivel, jogamos o novo nó para la
                    
                    aux2 = no;
                    aux1->dir = aux2;
                    axu2->pai = aux1; //definimos o aux1 como pai do aux2
                    
                    aux1 = aux2; //voltamos a igualar os auxiliares
                }
                
                else if (aux1->esq == NULL) { //entramos aqui apenas se o filho a direita estiver ocupado
                    
                    aux2 = no;
                    aux1->esq = aux2;
                    axu2->pai = aux1; //definimos o aux1 como pai do aux2
                    
                    aux1 = aux2; //voltamos a igualar os auxiliares
                }
                
                else { //vamos ao ultimo caso, onde esq e dir nao estao livres
                    
                    while (aux1->esq =! NULL) {
                        
                        aux1 = aux1->pai; /* enquanto não encontramos espaço livre na esquerda, 
                        vamos subindo a arvore com o aux1, que vai apontando para o pai */
                    }
                    
                    aux2 = no;
                    aux1->esq = aux2;
                    aux2->pai = aux1;
                    
                    /* fizemos o mesmo que anteriormente, achamos um espaço para um novo no na esquerda
                    entao criamos um novo nó e adicionamos ele a esquerda e definimos seu pai como o aux1 */
                    
                }
            }
            
            else { //caso seja um operando, logo, n podera ter filhos
                
                if (aux1->dir == NULL) {
                    
                    aux2 = no;
                    aux->dir = aux2;
                    aux2->pai = aux1;
                }
                
                else if (aux1->esq == NULL) {
                    
                    aux2 = no;
                    aux->esq = aux2;
                    aux2->pai = aux1;
                    
                }
                
                else {
                    
                    while (aux1->esq != NULL) {
                        
                        aux1 = aux1->pai;
                    }
                    
                    aux2 = no;
                    aux1->esq = aux2;
                    aux2->pai = aux1;
                }
            }
        }
    }
    
    
    return topo;
}

int avr_valorEA (arvExp* arv) {
    
    if(arv == NULL || arv->tipo != 0 || arv->tipo != 1)
        return 0;
        
    else if (arv->tipo == 0)
        return arv->valor;
    
    else{
        
        if (arv->operador == '+')
            return avr_valorEA(arv->esq)+avr_valorEA(arv->dir)
    
        if (arv->operador == '-')
            return avr_valorEA(arv->esq)-avr_valorEA(arv->dir)
    
        if (arv->operador == '*')
            return avr_valorEA(arv->esq)*avr_valorEA(arv->dir)
        
        if (arv->operador == '/')
            return avr_valorEA(arv->esq)/avr_valorEA(arv->dir)
    }
}