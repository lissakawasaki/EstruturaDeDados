#include <stdio.h>
#include <stdlib.h>

struct ponto {
    float x;
    float y;
    struct ponto *prox;
};
typedef struct ponto Ponto;

Ponto *listaPontos; // aponta para o primeiro elemento da lista

void inserirListaInicio(float x, float y){
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->prox = listaPontos;
    listaPontos = p;
}

void inserirListaFinal(float x, float y){
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->prox = NULL;
    if(listaPontos == NULL){
        listaPontos = p;
    } else {
        Ponto *listaAux = listaPontos;
        while(listaAux->prox != NULL){
            listaAux = listaAux->prox;
        }
        listaAux->prox = p;
    }
}

void removerPonto(float x, float y) {
    Ponto *atual = listaPontos;
    Ponto *anterior = NULL;

    while(atual != NULL) {
        if(atual->x == x && atual->y == y) {
            if(anterior == NULL) {
                // Remover o primeiro ponto da lista
                listaPontos = atual->prox;
            } else {
                // Remover um ponto do meio ou do final da lista
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("\nPonto(%.1f, %.1f) removido com sucesso.", x, y);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("\nPonto(%.1f, %.1f) não encontrado.", x, y);
}

void imprimirLista() {
    Ponto *auxLista = listaPontos;
    while(auxLista != NULL) {
        printf("\nPonto(%.1f, %.1f)", auxLista->x, auxLista->y);
        auxLista = auxLista->prox; // armazena o próximo elemento
    }
}

int main() {
    inserirListaFinal(6,7);
    inserirListaInicio(1,2);
    imprimirLista();

    printf("\n\nRemovendo ponto (1, 2):");
    removerPonto(1, 2);
    imprimirLista();

    printf("\n\nRemovendo ponto (6, 7):");
    removerPonto(6, 7);
    imprimirLista();

    return 0;
}
