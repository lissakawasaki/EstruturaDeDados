#include <stdio.h>
#include <stdlib.h>

struct fila {
    int valor;
    struct fila *prox;
}; typedef struct fila Fila;

Fila *inicioFila = NULL;

void inserirFila(int valor) {
    Fila *p = (Fila*)malloc(sizeof(Fila));
    p->valor = valor;
    p->prox = NULL;

    if (inicioFila == NULL) {
        inicioFila = p;
    } else {
        Fila *filaAux = inicioFila;
        while (filaAux->prox != NULL) {
            filaAux = filaAux->prox;
        }
        filaAux->prox = p;
    }
}

void imprimirFila(Fila *f) {
    while (f != NULL) {
        printf("%d\n", f->valor);
        f = f->prox;
    }
}

void removerFila(){
    if(inicioFila==NULL){
        printf("Fila Vazia");
    } else {
        inicioFila = inicioFila->prox;
    }
}

int main(void) {
    inserirFila(5);
    inserirFila(2);
    inserirFila(8);
    inserirFila(10);

    Fila *filaAux = inicioFila;
    imprimirFila(filaAux);

    printf("\n");
    removerFila();
    filaAux = inicioFila;
    imprimirFila(filaAux);

    printf("\n");
    removerFila();
    filaAux = inicioFila;
    imprimirFila(filaAux);

    return 0;
}
