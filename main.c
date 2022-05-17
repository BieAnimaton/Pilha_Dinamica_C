#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct pilha {
    int dado;
    struct pilha *prox;
} Pilha;

int inicializar (Pilha **pilha) {
    *pilha = NULL;
    return 0;
}

int inserir_topo (Pilha **pilha, int info) {
    Pilha *elemento;

    elemento = (Pilha*)malloc(sizeof(Pilha));
    elemento->dado = info;

    if (*pilha == NULL) {
        elemento->prox = NULL; // Inserção em pilha vazia
        *pilha = elemento;
    } else {
        elemento->prox = *pilha; // Inserção no início
        *pilha = elemento;
    }
    return 0;
}

int remover_topo (Pilha **pilha) {
    Pilha *aux;
    if (*pilha == NULL) {
        return 1;
    } else {
        aux = *pilha;
        *pilha = (*pilha)->prox;
        free(aux);
        return 0;
    }
}

int obter_topo(Pilha *pilha, int *dado) {
    if (pilha != NULL)
    {
       *dado = pilha -> dado;
       return 0;
    }
    else
       return 1; // Pilha Vazia
}

int verifica_vazio (Pilha *pilha, int *resp) {
    if (pilha != NULL)
        *resp = 0;
    else
        *resp = 1;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    Pilha *p1;
    int topo;

    inicializar(&p1);

    inserir_topo(&p1, 10);
    inserir_topo(&p1, 54);
    inserir_topo(&p1, 87);
    inserir_topo(&p1, 4);

    obter_topo(p1, &topo);
    printf("O topo é %d. \n\n", topo);

    printf("Removendo.\n");
    remover_topo(&p1);

    obter_topo(p1, &topo);
    printf("O topo é %d. \n\n", topo);

    return 0;
}
