#ifndef ED_PILHA_LISTA_H
#define ED_PILHA_LISTA_H

#endif //ED_PILHA_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include "lista-encadeada.h"

typedef struct pilha{
    TLista *topo;
} TPilha;

TPilha *inicializa();
void libera(TPilha *pilha);
int pilha_vazia(TPilha *p);
void push(TPilha *pilha, int elem);
int pop(TPilha *pilha);
int peek(TPilha *pilha);
void imprime_pilha(TPilha *pilha);
//void altera(TPilha *pilha, int novo); comentei para não haver duas funcoes com mesmo nome "FORBIDDEM"
