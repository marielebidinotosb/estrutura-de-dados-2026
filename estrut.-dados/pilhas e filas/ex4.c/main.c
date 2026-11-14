#include <stdio.h>
#include <stdlib.h>

#define MAX 32 // Ajustado para comportar representações binárias de números inteiros de até 32 bits

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
        printf("\n[ERRO] A pilha atingiu a capacidade máxima (overflow)!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

// Desempilhar (Pop) adaptada para retornar o valor retirado
int desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("\n[ERRO] Pilha vazia (underflow)!\n");
        return -1;
    }
    int valorRetirado = p->itens[p->topo];
    p->topo--;
    return valorRetirado;
}

int main() {
    Pilha p;
    inicializar(&p);
    
    int decimal;

    // Solicita o número inteiro não negativo e rejeita entradas negativas
    do {
        printf("Digite um numero inteiro nao negativo: ");
        scanf("%d", &decimal);
        if (decimal < 0) {
            printf("[Erro] Entrada negativa rejeitada. Por favor, digite um valor maior ou igual a 0.\n");
        }
    } while (decimal < 0);

    printf("Numero decimal informado: %d\n", decimal);

    // Tratamento específico para a entrada 0
    if (decimal == 0) {
        printf("Representacao binaria: 0\n");
        return 0;
    }

    // Divisões sucessivas por 2, empilhando os restos[cite: 20]
    int temp = decimal;
    while (temp > 0) {
        int resto = temp % 2;
        empilhar(&p, resto);
        temp = temp / 2;
    }

    // Desempilhar os valores para apresentar o resultado na ordem correcta[cite: 20]
    printf("Representacao binaria: ");
    while (!estaVazia(&p)) {
        int bit = desempilhar(&p);
        printf("%d", bit);
    }
    printf("\n");

    return 0;
}