#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // Tamanho máximo da pilha

typedef struct {
    int itens[TAM];
    int topo; // Índice do topo (-1 quando a pilha está vazia)
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int estaCheia(Pilha *p) {
    return p->topo == TAM - 1;
}

// Empilhar (Push)
void empilhar(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("\n[ERRO] Pilha cheia (overflow)!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
    printf("\nElemento %d empilhado com sucesso!\n", valor);
}

// Desempilhar (Pop)
void desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("\n[ERRO] Pilha vazia (underflow)!\n");
        return;
    }
    printf("\nElemento %d removido do topo.\n", p->itens[p->topo]);
    p->topo--;
}

// 1. Consultar o topo (sem remover)
void consultarTopo(Pilha *p) {
    if (estaVazia(p)) {
        printf("\nA pilha esta vazia. Nao ha elementos para consultar.\n");
        return;
    }
    printf("\nValor no topo da pilha: %d\n", p->itens[p->topo]);
}

// 2. Mostrar a quantidade de elementos (calculada a partir do campo topo)
void mostrarQuantidade(Pilha *p) {
    // Como o topo armazena o índice (-1 se vazia, 0 para 1 elemento, etc.), 
    // a quantidade total de elementos é (topo + 1).
    int quantidade = p->topo + 1;
    printf("\nQuantidade de elementos na pilha: %d\n", quantidade);
}

// Listar os elementos da pilha
void listar(Pilha *p) {
    if (estaVazia(p)) {
        printf("\nA pilha esta vazia.\n");
        return;
    }
    printf("\n--- Elementos da Pilha (Topo para a Base) ---\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%d]\n", p->itens[i]);
    }
    printf("---------------------------------------------\n");
}

int main() {
    Pilha p;
    inicializar(&p);
    int opcao, valor;

    do {
        printf("\n=== MENU PILHA ===\n");
        printf("1. Empilhar (Push)\n");
        printf("2. Desempilhar (Pop)\n");
        printf("3. Consultar o topo\n");
        printf("4. Mostrar quantidade de elementos\n");
        printf("5. Listar elementos\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilhar(&p, valor);
                break;
            case 2:
                desempilhar(&p);
                break;
            case 3:
                consultarTopo(&p);
                break;
            case 4:
                mostrarQuantidade(&p);
                break;
            case 5:
                listar(&p);
                break;
            case 6:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}