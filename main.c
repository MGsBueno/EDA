#include "pilha-lista.h"
#include <stdio.h>
#include "filas-listas.h"
/*
 *  ------ Início das funções da pilha ------  *
 */
TPilha *inicializa() {
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

void libera(TPilha *p) {
    TLista *q = p->topo;
    TLista *r;
    while(q != NULL){
        r = q;
        q=q->prox;
        free(r);
    }
    free(p);
}

int pilha_vazia(TPilha *pilha) {
    if (pilha->topo==NULL)
        return 1;
    return 0;
}

/* *
 * Insere elem no topo da pilha
 * */
void push(TPilha *pilha, int elem) {
    TLista *novo = (TLista*) malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

/* *
 * Exclui o elemento do topo da pilha
 * retorna o info do elemento excluído
 */
int pop(TPilha *pilha) {
    if (pilha == NULL)
        return (1);
    TLista *temp = pilha->topo;
    int val = temp->info;
    pilha->topo = temp->prox;
    return val;
}

/* *
 * Consulta o elemento do topo da pilha
 * retorna NULL caso pilha esteja vazia
 *         info do elemento do topo caso contrário
 */
int peek(TPilha *pilha) {
    return  pilha->topo->info;
}

void imprime_pilha(TPilha *pilha) {
    int x;
    printf("\nEstado atual da Pilha:\n");
    TPilha *aux = inicializa();
    while (!pilha_vazia(pilha)) {
        x = pop(pilha);
        printf("%d\n", x);
        push(aux, x);
    }
    while (!pilha_vazia(aux)) {
        push(pilha, pop(aux));
    }
    libera(aux);
    printf("\n");
}
/*
void altera(TPilha *pilha, int novo){
    if (pilha-> topo == NULL)
        return;
    TLista *temp = pilha->topo;
    temp->info = novo;
}
 */

/*
 *  ------ Fim das funções pilha ------ *
 *
 ------------------------------------------------------------------------------
 *
 * * ------ Início das funções Lista ------ *
 */

TLista* cria_lista(void){
    return NULL;
}

TLista* insere_inicio(TLista *li, int i){
    TLista *novo = (TLista*)malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;

}

TLista *insere_fim (TLista *li, int i) {
    TLista *novo = (TLista *) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    if (li) {
        TLista *p = li;
        while (p->prox)
            p = p->prox;
        p->prox = novo;
        return li;
    }


}

TLista *insere_ordenado(TLista *li, int i) {
    if (!li || li->info > i)
        return insere_inicio(li, i);
    else {
        if (li->info < i)
            insere_ordenado(li->prox, i);
        TLista *novo = (TLista *) malloc(sizeof(TLista));
        novo->info = i;
        novo->prox = li->prox;
        li->prox = novo;
    }
}

TLista *exclui(TLista *li, int i) {
    if (li)
        if (li->info < i) {
            if (li->prox->info < i)
                exclui(li->prox, i);
            TLista *aux = li->prox;
            li->prox = aux->prox;
            free(aux);
        }
}

TLista* altera(TLista* li, int vantigo, int vnovo) {
    if (li) {
        if (li->info != vantigo)
            altera(li->prox, vantigo, vnovo);
        if (li->info == vantigo)
            li->info = vnovo;
    }
}



void imprime(TLista *li) {
    if (li)
        printf("%d ", li->info);
    if (li->prox)imprime(li->prox);
    printf("\n");

}
/*
 * ------ Fim das funchoes Lista ------ * *
 */



/*
 * ------ Início das funchoes Fila ------ * *
 */
TFila* inicializaf(void){
    TFila *f = (TFila *)malloc(sizeof(TFila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int fila_vazia(TFila *f){
    if (f->inicio == NULL) {
        return 1;
    }
    else return 0;
}

void insere(TFila *f, int elem){
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL; //inserção no fim da fila
    if (!fila_vazia(f)){
        f->fim->prox = novo;
    }
    else{
        f->inicio = novo;
    }
    f->fim = novo; //elemento inserido é o novo fim da fila
}

/*
 * Remove elemento da fila e retorna info do elemento excluído
 */
int retira(TFila *f){
    if (fila_vazia(f)){
        exit(1);
    }
    int info = f->inicio->info;

    TLista *aux = f->inicio;
    f->inicio=f->inicio->prox;
    //se elemento removido era o único da fila
    //faz fim apontar para NULL também
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(aux);
    return info;
}

void liberaf(TFila *f){
    TLista *q, *p = f->inicio;
    while(p != NULL){
        q = p;
        p = p->prox;
        free(q);
    }
    free(f);
}

void imprime_fila(TFila *f) {
    if (f->inicio!=NULL){
        printf("%d",f->inicio->info);
    TLista* q = f->inicio;
        if (q->prox!=NULL) {
            f->inicio = q->prox;
            imprime_fila(f);
            f->inicio = q;
        }
    }
}

/*
 * ------ Fim das funchoes Lista ------ * *
 */

int main() {
    TFila *fila = inicializaf();
    insere(fila, 5);
    insere(fila, 3);
    insere(fila, 2);
    imprime_fila(fila);

    int x = retira(fila);
    printf("\nelemento %d retirado da fila\n", x);
    imprime_fila(fila);

    liberaf(fila);



    /*
    printf("exercicio de lista encadeada\n");
    TLista *lista;
    lista = cria_lista();

    printf("insere no comeco 10\n");
    lista = insere_inicio(lista, 10);
    printf("atual\n");
    imprime(lista);

    printf("insere no comeco 5\n");
    lista = insere_inicio(lista, 5);
    printf("atual\n");
    imprime(lista);

    printf("insere ordenado 7\n");
    lista = insere_ordenado(lista, 7);
    printf("atual\n");
    imprime(lista);

    printf("insere no fim 11\n");
    lista = insere_fim(lista, 11);
    printf("atual\n");
    imprime(lista);

    printf("exclui 7\n");
    exclui(lista, 7);
    printf("atual\n");
    imprime(lista);

    printf("altera 11 para 15\n");
    altera(lista, 11,15);
    printf("atual\n");
    imprime(lista);
    */


    /*
    TPilha *pilha;
    pilha = inicializa();
    push(pilha, 5);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 4);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 3);
    printf("topo: %d\n", peek(pilha));

    imprime_pilha(pilha);

    int info = pop(pilha);
    printf("elemento removido: %d\n", info);

    imprime_pilha(pilha);
    altera(pilha,25);
    imprime_pilha(pilha);
    */
}
