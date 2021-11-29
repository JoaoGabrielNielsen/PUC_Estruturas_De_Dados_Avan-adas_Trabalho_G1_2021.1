/*  João Gabriel Nielsen 1820419 
    Bernardo Ruiz Fernandes 1711180 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_lista.h"
#include "ArvExp.h"

int precedencia (char operador) {
    
    if (operador == '(' || operador == ')')
        return 0;
    if (operador == '+' || operador == '-')
        return 1;
    if (operador == '*' || operador == '/')
        return 2;
    
    return 0;
}

int isNumero(char c) {
    if (c > '0' && c < '9')
        return 1;
    return 0;
}

char* intfix_to_postfix (char* expressao) {
    
    Pilha *pilha_operadores = pilha_cria();
    char val;
    int j = 0;
    
    int tam = strlen(expressao);

    char saida[500];

    for (int i = 0; i < tam; i++) {
        
        if (expressao[i] == ' ') {
            continue;
        }
        
        else if (expressao[i] != '+' && expressao[i] != '-' && expressao[i] != '*' && expressao[i] != '/' && expressao[i] != '(' 
        && expressao[i] != ')') { 
            
            saida[j++] = expressao[i];

            if (isNumero(expressao[i+1])){
                saida[j++] = expressao[++i];
            }
            
            saida[j++] = ' ';
            
        }
        
        else if (expressao[i] == '(') {
            
            pilha_push(pilha_operadores, expressao[i]);
            /* levamos o operador ( direto para a pilha de operadores */
        }
        
        else if (expressao[i] == ')') {
            /* Como encontramos um ), precisamos jogar todos os operadores da pilha para a saida, até encontramos um ( */
            
            val = pilha_pop(pilha_operadores);
            
            while (val != '(') {
                saida[j++] = val;
                saida[j++] = ' ';
                pilha_imprimir(pilha_operadores);
                val = pilha_pop(pilha_operadores);
            }
            val = pilha_pop(pilha_operadores);
            saida[j++] = val;
            saida[j++] = ' ';
        }
        
        else {
            
            if (pilha_vazia(pilha_operadores)) {
                
                pilha_push(pilha_operadores, expressao[i]);
                printf("Elemento adicionado na pilha de operadores: %c\n", expressao[i]);
                /* Caso a pilha de operadores esteja vazia, adicionamos diretamente a ela */
            }
            
            else {
                
                if (precedencia(expressao[i]) <= precedencia(pilha_operadores->topo->info)) {
                    val = pilha_pop(pilha_operadores);
                    printf("O operador %c sai da pilha de operadores\n", val);
                    saida[j++] = val;
                    saida[j++] = ' ';

                    pilha_push(pilha_operadores, expressao[i]);
                }
                
                else {

                    pilha_push(pilha_operadores, expressao[i]);
                    pilha_imprimir(pilha_operadores);
                }
            }
        }
    }
    
    while(!pilha_vazia(pilha_operadores)){
        val = pilha_pop(pilha_operadores);
        saida[j++] =  val;
        saida[j++] = ' ';
    }
    
    saida[j++] = '_';
    printf("Saida final:\n");
    
    for (int i = 0; saida[i] != '_'; i++)
        printf("%c", saida[i]);
    
    return saida;
    
}

int main (void) {
    
    char infix[30];
    
    int resultado;
    
    printf("Digite uma infix: \n");
    gets(infix);
    
    ArvExp *Arvore1;
    Arvore1 = faz_arvExp(intfix_to_postfix(infix));
    resultado = avr_valorEA (Arvore1);
    printf("Resultado: %d\n", resultado);
    
    return 0;
    
}