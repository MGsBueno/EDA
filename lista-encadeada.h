	
#ifndef ED_LISTA_ENCADEADA_H
#define ED_LISTA_ENCADEADA_H

#endif //ED_LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* cria_lista (void);
TLista* insere_inicio (TLista* li, int i);
TLista* insere_fim (TLista* li, int i);
TLista* insere_ordenado (TLista* li, int i);
TLista* exclui(TLista* li, int i);
TLista* altera(TLista* li, int vantigo, int vnovo);
void imprime (TLista* li);



