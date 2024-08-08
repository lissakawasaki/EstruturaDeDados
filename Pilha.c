#include <stdio.h>
#include <stdlib.h>

struct pilha {
    int valor;
    struct pilha *prox;
}; typedef struct pilha Pilha;

Pilha *inicioPilha;

void inserirPilha(int valor){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->valor = valor;
    p->prox = inicioPilha;
    inicioPilha = p;

}

void removerPilha(){
    if(inicioPilha == NULL){
        printf("Pilha Vazia");
    } else {
        inicioPilha = inicioPilha->prox;
    }
}

void imprimirPilha(Pilha *p) {
    while (p != NULL) {
        printf("%d\n", p->valor);
        p = p->prox;
    }
}

int main(){
    inserirPilha(5);
    inserirPilha(3);
    inserirPilha(4);
    inserirPilha(8);

    removerPilha();
    removerPilha();
    removerPilha();
    removerPilha();
    removerPilha();

    Pilha *pilhaAux = inicioPilha;
    imprimirPilha(pilhaAux);

}
