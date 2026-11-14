#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // Capacidade máxima da fila de impressão

typedef struct {
    int trabalhos[TAM];
    int inicio;
    int fim;
} FilaImpressao;

// Inicializa a fila de impressão
void inicializar(FilaImpressao *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(FilaImpressao *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int estaCheia(FilaImpressao *f) {
    return (f->fim + 1) % TAM == f->inicio;
}

// 1. Adicionar trabalho à fila (Enqueue)
void adicionarTrabalho(FilaImpressao *f, int idTrabalho) {
    if (estaCheia(f)) {
        printf("\n[AVISO] A fila de impressao esta cheia (overflow)! Nao e possivel adicionar novos trabalhos.\n");
        return;
    }
    f->trabalhos[f->fim] = idTrabalho;
    f->fim = (f->fim + 1) % TAM;
    printf("\nTrabalho [%d] adicionado à fila com sucesso!\n", idTrabalho);
}

// 2. Imprimir próximo trabalho (Dequeue unitário)
void imprimirProximo(FilaImpressao *f) {
    if (estaVazia(f)) {
        printf("\n[AVISO] A fila de impressao esta vazia. Nenhum trabalho pendente.\n");
        return;
    }
    int trabalhoAtual = f->trabalhos[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    printf("\n[IMPRIMINDO] A processar o trabalho ID: [%d]...\n", trabalhoAtual);
}

// 3. Listar pendentes (mostra todos os trabalhos aguardando sem os remover)
void listarPendentes(FilaImpressao *f) {
    if (estaVazia(f)) {
        printf("\n[Fila Vazia] Nao ha trabalhos pendentes na impressora.\n");
        return;
    }
    printf("\n=== TRABALHOS PENDENTES NA FILA ===\n");
    int i = f->inicio;
    while (i != f->fim) {
        printf("[%d] ", f->trabalhos[i]);
        i = (i + 1) % TAM;
    }
    printf("\n-----------------------------------\n");
}

// 4. Imprimir todos: remove os trabalhos um a um, informando o identificador de cada um
void imprimirTodos(FilaImpressao *f) {
    if (estaVazia(f)) {
        printf("\n[AVISO] A fila de impressao esta vazia. Nada para imprimir.\n");
        return;
    }
    
    printf("\n=== A INICIAR IMPRESSAO DE TODOS OS TRABALHOS ===\n");
    while (!estaVazia(f)) {
        int trabalhoAtual = f->trabalhos[f->inicio];
        f->inicio = (f->inicio + 1) % TAM;
        printf("-> A imprimir trabalho ID: [%d]\n", trabalhoAtual);
    }
    printf("=== TODOS OS TRABALHOS FORAM PROCESSADOS ===\n");
}

int main() {
    FilaImpressao f;
    inicializar(&f);
    int opcao, idTrabalho;

    do {
        printf("\n=== MENU - FILA DE IMPRESSAO ===\n");
        printf("1. Adicionar trabalho\n");
        printf("2. Imprimir proximo trabalho\n");
        printf("3. Listar pendentes\n");
        printf("4. Imprimir todos os trabalhos\n");
        printf("5. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o identificador (numero inteiro) do trabalho: ");
                scanf("%d", &idTrabalho);
                adicionarTrabalho(&f, idTrabalho);
                break;
            case 2:
                imprimirProximo(&f);
                break;
            case 3:
                listarPendentes(&f);
                break;
            case 4:
                imprimirTodos(&f);
                break;
            case 5:
                printf("\nA encerrar o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}