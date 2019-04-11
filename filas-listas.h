typedef struct fila {
    TLista *inicio;
    TLista *fim;
} TFila;

TFila* inicializaf(void);
int fila_vazia(TFila *f);
void insere(TFila *f, int elem);
int retira(TFila *f);
void liberaf(TFila *f);
void imprime_fila(TFila *f);

