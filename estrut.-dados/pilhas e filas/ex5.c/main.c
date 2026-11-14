#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Capacidade máxima do histórico de alterações

typedef struct {
    int itens[MAX];
    int topo;
} PilhaHistorico;

// Inicializa a pilha do histórico
void inicializar(PilhaHistorico *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(PilhaHistorico *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int estaCheia(PilhaHistorico *p) {
    return p->topo == MAX - 1;
}

// Empilhar no histórico
void empilhar(PilhaHistorico *p, int valor) {
    if (estaCheia(p)) {
        return; // Pilha cheia tratada na função de alteração
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

// Desempilhar do histórico (retorna o valor anterior)
int desempilhar(PilhaHistorico *p) {
    if (estaVazia(p)) {
        return -1;
    }
    int valorRetirado = p->itens[p->topo];
    p->topo--;
    return valorRetirado;
}

// 1. Alterar valor: guarda o valor atual na pilha antes de substituí-lo pelo novo valor
void alterarValor(PilhaHistorico *p, int *valorAtual) {
    if (estaCheia(p)) {
        printf("\n[AVISO] Historico cheio! Nao e possivel guardar mais alteracoes (overflow). Valor atual preservado.\n");
        return;
    }

    int novoValor;
    printf("Digite o novo valor inteiro: ");
    scanf("%d", &novoValor);

    // Guarda o valor atual na pilha (histórico) antes de atualizar
    empilhar(p, *valorAtual);

    // Substitui pelo novo valor
    *valorAtual = novoValor;
    printf("\nValor alterado com sucesso para: %d\n", *valorAtual);
}

// 2. Desfazer: recuperar da pilha o valor anterior e torná-lo o valor atual
void desfazer(PilhaHistorico *p, int *valorAtual) {
    if (estaVazia(p)) {
        printf("\n[AVISO] Nao ha historico disponivel. Nao e possivel desfazer!\n");
        return;
    }

    // Recupera o valor anterior do topo da pilha e torna-o o valor atual
    *valorAtual = desempilhar(p);
    printf("\n[Desfeito] A operacao foi revertida. O valor atual e agora: %d\n", *valorAtual);
}

// 3. Consultar: mostrar o valor atual e o histórico disponível
void consultar(PilhaHistorico *p, int valorAtual) {
    printf("\n========================================\n");
    printf("VALOR ATUAL: %d\n", valorAtual);
    printf("----------------------------------------\n");
    if (estaVazia(p)) {
        printf("Historico: Vazio (sem alteracoes anteriores guardadas).\n");
    } else {
        printf("Historico de estados anteriores (do mais recente para o mais antigo):\n");
        for (int i = p->topo; i >= 0; i--) {
            printf(" -> [%d]\n", p->itens[i]);
        }
    }
    printf("========================================\n");
}

int main() {
    PilhaHistorico historico;
    inicializar(&historico);

    int valorAtual = 0; // Valor inteiro inicialmente igual a zero
    int opcao;

    do {
        printf("\n=== MENU - HISTORICO COM DESFAZER ===\n");
        printf("1. Alterar valor\n");
        printf("2. Desfazer alteracao\n");
        printf("3. Consultar valor atual e historico\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                alterarValor(&historico, &valorAtual);
                break;
            case 2:
                desfazer(&historico, &valorAtual);
                break;
            case 3:
                consultar(&historico, valorAtual);
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