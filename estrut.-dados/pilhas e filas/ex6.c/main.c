#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // Tamanho máximo do array da fila

typedef struct {
    int itens[TAM];
    int inicio;
    int fim;
} Fila;

// Inicializa a fila
void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int estaCheia(Fila *f) {
    return (f->fim + 1) % TAM == f->inicio;
}

// Inserir um elemento na fila (Enqueue)
void inserir(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("\n[ERRO] A fila esta cheia (overflow)!\n");
        return;
    }
    f->itens[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM;
    printf("\nElemento %d inserido com sucesso!\n", valor);
}

// Remover um elemento da fila (Dequeue)
void remover(Fila *f) {
    if (estaVazia(f)) {
        printf("\n[ERRO] A fila esta vazia (underflow)!\n");
        return;
    }
    int removido = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    printf("\nElemento %d removido da fila.\n", removido);
}

// 1. Consultar o próximo elemento (apresenta o primeiro elemento sem o remover)
void consultarProximo(Fila *f) {
    if (estaVazia(f)) {
        printf("\nA fila esta vazia. Nao ha elementos para consultar.\n");
        return;
    }
    printf("\nProximo elemento no inicio da fila: %d\n", f->itens[f->inicio]);
}

// 2. Mostrar a quantidade de elementos aguardando (calculada com inicio e fim, sem contador adicional)
void mostrarQuantidade(Fila *f) {
    // Fórmula matemática para calcular elementos em fila circular: (fim - inicio + TAM) % TAM
    int quantidade = (f->fim - f->inicio + TAM) % TAM;
    printf("\nQuantidade de elementos aguardando na fila: %d\n", quantidade);
}

// Listar os elementos armazenados
void listar(Fila *f) {
    if (estaVazia(f)) {
        printf("\nA fila esta vazia.\n");
        return;
    }
    printf("\n--- Elementos na Fila ---\n");
    int i = f->inicio;
    while (i != f->fim) {
        printf("[%d] ", f->itens[i]);
        i = (i + 1) % TAM;
    }
    printf("\n-------------------------\n");
}

int main() {
    Fila f;
    inicializar(&f);
    int opcao, valor;

    do {
        printf("\n=== MENU FILA ===\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Consultar proximo elemento\n");
        printf("4. Mostrar quantidade de elementos\n");
        printf("5. Listar elementos\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserir(&f, valor);
                break;
            case 2:
                remover(&f);
                break;
            case 3:
                consultarProximo(&f);
                break;
            case 4:
                mostrarQuantidade(&f);
                break;
            case 5:
                listar(&f);
                break;
            case 6:
                printf("\nA encerrar o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}