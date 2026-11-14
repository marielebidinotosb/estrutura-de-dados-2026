#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Capacidade máxima da fila de rodízio

typedef struct {
    int itens[MAX];
    int fim;
} FilaRodizio;

// Inicializa a fila
void inicializar(FilaRodizio *f) {
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(FilaRodizio *f) {
    return f->fim == 0;
}

// Verifica se a fila está cheia
int estaCheia(FilaRodizio *f) {
    return f->fim == MAX;
}

// Adicionar tarefa à fila (Enqueue)
void inserir(FilaRodizio *f, int idTarefa) {
    if (estaCheia(f)) {
        printf("\n[AVISO] A fila esta cheia! Nao e possivel adicionar.\n");
        return;
    }
    f->itens[f->fim] = idTarefa;
    f->fim++;
    printf("\nTarefa [%d] inserida com sucesso!\n", idTarefa);
}

// Remover tarefa com deslocamento (disponibiliza o identificador removido ao programa)
int remover(FilaRodizio *f) {
    if (estaVazia(f)) {
        return -1; // Retorna -1 se estiver vazia
    }
    
    int tarefaRemovida = f->itens[0];
    
    // Deslocar todos os elementos restantes uma posição para a esquerda
    for (int i = 0; i < f->fim - 1; i++) {
        f->itens[i] = f->itens[i + 1];
    }
    
    f->fim--;
    return tarefaRemovida;
}

// Listar as tarefas pendentes na fila
void listar(FilaRodizio *f) {
    if (estaVazia(f)) {
        printf("\n[Fila Vazia] Nao ha tarefas pendentes.\n");
        return;
    }
    printf("\n=== TAREFAS EM RODIZIO (Inicio -> Fim) ===\n");
    for (int i = 0; i < f->fim; i++) {
        printf("[%d] ", f->itens[i]);
    }
    printf("\n-----------------------------------------\n");
}

// Executar uma rodada de rodízio
void executarRodada(FilaRodizio *f) {
    if (estaVazia(f)) {
        printf("\n[AVISO] A fila esta vazia. Nao ha tarefas para executar na rodada.\n");
        return;
    }
    
    // Retira a primeira tarefa da fila
    int tarefaAtual = remover(f);
    printf("\n-----------------------------------------\n");
    printf("Tarefa em execucao: [%d]\n", tarefaAtual);
    
    int resposta;
    printf("A tarefa foi concluida?\n");
    printf("1. Sim (mantê-la fora da fila)\n");
    printf("2. Nao (coloca-la novamente no final da fila)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &resposta);
    
    if (resposta == 1) {
        printf("-> Tarefa [%d] concluida e removida definitivamente do rodizio.\n", tarefaAtual);
    } else {
        // Se não foi concluída, insere novamente no final da fila.
        // Como 'remover' já abriu espaço com o deslocamento, a inserção é garantida mesmo se estivesse cheia.
        f->itens[f->fim] = tarefaAtual;
        f->fim++;
        printf("-> Tarefa [%d] NAO concluida. Reinserida no final da fila de rodizio.\n", tarefaAtual);
    }
    printf("-----------------------------------------\n");
}

int main() {
    FilaRodizio f;
    inicializar(&f);
    int opcao, idTarefa;

    do {
        printf("\n=== MENU - SIMULACAO DE RODIZIO DE TAREFAS ===\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Executar uma rodada\n");
        printf("3. Listar tarefas pendentes\n");
        printf("4. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o identificador (numero inteiro) da tarefa: ");
                scanf("%d", &idTarefa);
                inserir(&f, idTarefa);
                break;
            case 2:
                executarRodada(&f);
                break;
            case 3:
                listar(&f);
                break;
            case 4:
                printf("\nA encerrar o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}