#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Capacidade máxima da fila

typedef struct {
    int itens[MAX];
    int fim; // Controla o número de elementos e a próxima posição de inserção
} FilaDeslocamento;

// Inicializa a fila
void inicializar(FilaDeslocamento *f) {
    f->fim = 0; // O início é sempre o índice 0 conceptualmente
}

// Verifica se a fila está vazia
int estaVazia(FilaDeslocamento *f) {
    return f->fim == 0;
}

// Verifica se a fila está cheia
int estaCheia(FilaDeslocamento *f) {
    return f->fim == MAX;
}

// Inserir um elemento na fila (Enqueue)
void inserir(FilaDeslocamento *f, int valor) {
    if (estaCheia(f)) {
        printf("\n[AVISO] A fila esta cheia! Insercao rejeitada.\n");
        return;
    }
    f->itens[f->fim] = valor;
    f->fim++;
    printf("\nElemento %d inserido com sucesso!\n", valor);
}

// Remover um elemento da fila com deslocamento para a esquerda (mantendo inicio = 0)
void remover(FilaDeslocamento *f) {
    if (estaVazia(f)) {
        printf("\n[AVISO] A fila esta vazia! Nao ha elementos para remover.\n");
        return;
    }
    
    int removido = f->itens[0];
    
    // Deslocar todos os elementos restantes uma posicao para a esquerda
    for (int i = 0; i < f->fim - 1; i++) {
        f->itens[i] = f->itens[i + 1];
    }
    
    f->fim--; // Atualiza o campo de controle do fim
    printf("\nElemento %d removido da fila (deslocamento efetuado).\n", removido);
}

// Listar os elementos armazenados
void listar(FilaDeslocamento *f) {
    if (estaVazia(f)) {
        printf("\nA fila esta vazia.\n");
        return;
    }
    printf("\n--- Elementos na Fila (Inicio -> Fim) ---\n");
    for (int i = 0; i < f->fim; i++) {
        printf("[%d] ", f->itens[i]);
    }
    printf("\n-----------------------------------------\n");
}

// Execução do Teste Obrigatório especificado no enunciado
void executarTesteObigatorio() {
    FilaDeslocamento f;
    inicializar(&f);

    printf("\n============================================\n");
    printf("INICIO DO TESTE OBRIGATORIO (DESLOCAMENTO)\n");
    printf("============================================\n");

    // 1. Insira cinco valores
    printf("\n-> A inserir 5 valores (10, 20, 30, 40, 50)...\n");
    inserir(&f, 10);
    inserir(&f, 20);
    inserir(&f, 30);
    inserir(&f, 40);
    inserir(&f, 50);
    listar(&f);

    // 2. Remova dois
    printf("\n-> A remover dois elementos (10 e 20)...\n");
    remover(&f);
    remover(&f);
    listar(&f);

    // 3. Insira outros dois (demonstra o reaproveitamento das posições livres à esquerda)
    printf("\n-> A inserir outros dois valores (60 e 70)...\n");
    inserir(&f, 60);
    inserir(&f, 70);
    listar(&f);

    printf("\n============================================\n");
    printf("FIM DO TESTE OBRIGATORIO\n");
    printf("============================================\n");
}

int main() {
    FilaDeslocamento f;
    inicializar(&f);
    int opcao, valor;

    // Executa o teste obrigatório ao iniciar o programa
    executarTesteObigatorio();

    // Menu interativo para teste contínuo
    do {
        printf("\n=== MENU - FILA COM DESLOCAMENTO ===\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento (com deslocamento)\n");
        printf("3. Listar elementos\n");
        printf("4. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                inserir(&f, valor);
                break;
            case 2:
                remover(&f);
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