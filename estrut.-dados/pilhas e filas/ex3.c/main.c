#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Capacidade máxima da pilha

typedef struct {
    int itens[MAX];
    int topo;
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
    return p->topo == MAX - 1;
}

// Empilhar (Push)
void empilhar(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("\n[ERRO] Pilha cheia (overflow)!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

// Desempilhar (Pop) adaptada para retornar o valor retirado para utilização no programa
int desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("\n[ERRO] Pilha vazia (underflow)!\n");
        return -1; // Valor de controlo em caso de erro
    }
    int valorRetirado = p->itens[p->topo];
    p->topo--;
    return valorRetirado;
}

int main() {
    Pilha p;
    inicializar(&p);
    
    int n, i, valor;

    // Solicitar a quantidade de números entre 1 e MAX
    do {
        printf("Digite a quantidade de numeros (entre 1 e %d): ", MAX);
        scanf("%d", &n);
        if (n < 1 || n > MAX) {
            printf("Quantidade invalida! Deve estar entre 1 e %d.\n", MAX);
        }
    } while (n < 1 || n > MAX);

    // Ler e empilhar os valores
    printf("\nDigite os %d numeros inteiros:\n", n);
    for (i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &valor);
        empilhar(&p, valor);
    }

    // Retirar os elementos da pilha e apresentá-los na ordem inversa (ordem de retirada)
    printf("\nSequencia na ordem inversa:\n");
    while (!estaVazia(&p)) {
        int elemento = desempilhar(&p);
        printf("%d ", elemento);
    }
    printf("\n");

    // Verificar se a pilha está vazia no final
    if (estaVazia(&p)) {
        printf("\n[Info] A pilha encontra-se totalmente vazia no final do processo.\n");
    }

    return 0;
}