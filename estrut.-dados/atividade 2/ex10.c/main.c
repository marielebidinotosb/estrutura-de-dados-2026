#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefa {
    char nome[30];
    int prioridade;
    struct Tarefa *prox;
} Tarefa;

Tarefa *inserirTarefa(Tarefa *inicio, char nome[], int prioridade) {

    Tarefa *novo = (Tarefa *)malloc(sizeof(Tarefa));
    strcpy(novo->nome, nome);
    novo->prioridade = prioridade;
    novo->prox = NULL;
    
    if (inicio == NULL || prioridade < inicio->prioridade) {
        novo->prox = inicio;
        return novo;
    }
    
    Tarefa *atual = inicio;
    while (atual->prox != NULL && atual->prox->prioridade <= prioridade) {
        atual = atual->prox;
    }
    
    novo->prox = atual->prox;
    atual->prox = novo;
    
    return inicio;
}

void imprimirLista(Tarefa *inicio) {

    Tarefa *atual = inicio;
    while (atual != NULL) {
        printf("%s (%d)\n", atual->nome, atual->prioridade);
        atual = atual->prox;
    }
}

int main() {
    Tarefa *fila = NULL;
    Tarefa *p;

    fila = inserirTarefa(fila, "Corrigir bug critico", 1);
    fila = inserirTarefa(fila, "Responder e-mails", 5);
    fila = inserirTarefa(fila, "Preparar aula", 2);
    fila = inserirTarefa(fila, "Revisar artigo", 3);

    imprimirLista(fila);

    while (fila != NULL) {
        p = fila;
        fila = fila->prox;
        free(p);
    }
    return 0;
}