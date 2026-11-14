#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct {
    int itens[TAM];
    int inicio;
    int fim;
    int quantidade;
} FilaCircular;

void inicializar(FilaCircular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

int estaCheia(FilaCircular *f) {
    return f->quantidade == TAM;
}

int estaVazia(FilaCircular *f) {
    return f->quantidade == 0;
}

void inserir(FilaCircular *f, int valor) {
    if (estaCheia(f)) {
        printf("\n[ERRO] Overflow: A fila esta cheia!\n");
        return;
    }
    f->itens[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM;
    f->quantidade++;
    printf("\nElemento %d inserido com sucesso!\n", valor);
}

void remover(FilaCircular *f) {
    if (estaVazia(f)) {
        printf("\n[ERRO] Underflow: A fila esta vazia!\n");
        return;
    }
    int removido = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->quantidade--;
    printf("\nElemento %d removido da fila.\n", removido);
}

void listar(FilaCircular *f) {
    if (estaVazia(f)) {
        printf("\nA fila esta vazia.\n");
        return;
    }
    printf("\n--- Elementos na Fila ---\n");
    int i = f->inicio;
    for (int c = 0; c < f->quantidade; c++) {
        printf("[%d] ", f->itens[i]);
        i = (i + 1) % TAM;
    }
    printf("\n-------------------------\n");
}

void exibirStatus(FilaCircular *f) {
    printf("Status atual -> inicio: %d | fim: %d | quantidade: %d\n", f->inicio, f->fim, f->quantidade);
}

int main() {
    FilaCircular f;
    inicializar(&f);
    int opcao, valor;

    do {
        printf("\nMENU FILA CIRCULAR \n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Listar elementos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserir(&f, valor);
                exibirStatus(&f);
                break;
            case 2:
                remover(&f);
                exibirStatus(&f);
                break;
            case 3:
                listar(&f);
                exibirStatus(&f);
                break;
            case 4:
                printf("\nEncerrando o programa 1...\n");
                break;
            default:
                printf("\nOpção invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}