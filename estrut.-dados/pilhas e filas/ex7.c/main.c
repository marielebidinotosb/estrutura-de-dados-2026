#include <stdio.h>
#include <stdlib.h>

#define TAM 5 

typedef struct {
    int senhas[TAM];
    int inicio;
    int fim;
} FilaSenhas;

// Inicializa a fila de senhas
void inicializar(FilaSenhas *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(FilaSenhas *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int estaCheia(FilaSenhas *f) {
    return (f->fim + 1) % TAM == f->inicio;
}

// 1. Gerar uma senha e adicioná-la à fila (apenas se a inserção for possível)
void gerarEInserir(FilaSenhas *f, int *contadorSenha) {
    if (estaCheia(f)) {
        printf("\n[AVISO] A fila esta cheia (overflow)! Nao e possivel gerar nova senha no momento.\n");
        return;
    }
    
    // A senha só é gerada e incrementada quando a inserção é garantida
    (*contadorSenha)++;
    f->senhas[f->fim] = *contadorSenha;
    f->fim = (f->fim + 1) % TAM;
    
    printf("\nSenha gerada e adicionada à fila: Senha [%d]\n", *contadorSenha);
}

// 2. Chamar a próxima senha, removendo-a da fila (não permite atendimento com a fila vazia)
void chamarProxima(FilaSenhas *f) {
    if (estaVazia(f)) {
        printf("\n[AVISO] A fila esta vazia (underflow)! Nao ha pessoas aguardando atendimento.\n");
        return;
    }
    
    int senhaAtendida = f->senhas[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    printf("\n--> A chamar para atendimento: Senha [%d]\n", senhaAtendida);
}

// 3. Consultar a próxima senha sem removê-la
void consultarProxima(FilaSenhas *f) {
    if (estaVazia(f)) {
        printf("\nA fila de atendimento esta vazia.\n");
        return;
    }
    printf("\nProxima senha a ser atendida (no topo da fila): [%d]\n", f->senhas[f->inicio]);
}

// 4. Mostrar todas as senhas aguardando atendimento[cite: 23]
void mostrarFila(FilaSenhas *f) {
    if (estaVazia(f)) {
        printf("\n[Fila Vazia] Nenhuma senha aguardando atendimento.\n");
        return;
    }
    
    printf("\n=== SENHAS AGUARDANDO ATENDIMENTO ===\n");
    int i = f->inicio;
    while (i != f->fim) {
        printf("[%d] ", f->senhas[i]);
        i = (i + 1) % TAM;
    }
    printf("\n-------------------------------------\n");
}

// Execução do Teste Obrigatório especificado no enunciado[cite: 23]
void executarTesteObigatorio() {
    FilaSenhas secretaria;
    inicializar(&secretaria);
    int contadorSenha = 0;

    printf("\n============================================\n");
    printf("INICIO DO TESTE OBRIGATORIO (ATENDIMENTO)\n");
    printf("============================================\n");

    // Gerar três senhas[cite: 23]
    printf("\n-> A gerar 3 senhas consecutivas...\n");
    gerarEInserir(&secretaria, &contadorSenha); // Senha 1
    gerarEInserir(&secretaria, &contadorSenha); // Senha 2
    gerarEInserir(&secretaria, &contadorSenha); // Senha 3

    mostrarFila(&secretaria);

    // Realizar dois atendimentos (chamadas)[cite: 23]
    printf("\n-> A realizar dois atendimentos (chamadas)...\n");
    chamarProxima(&secretaria); // Atende a Senha 1
    chamarProxima(&secretaria); // Atende a Senha 2

    // Apresentar as senhas restantes[cite: 23]
    printf("\n-> Senhas restantes aguardando na fila:\n");
    mostrarFila(&secretaria);

    printf("\n============================================\n");
    printf("FIM DO TESTE OBRIGATORIO\n");
    printf("============================================\n");
}

int main() {
    FilaSenhas f;
    inicializar(&f);
    int contadorSenha = 0;
    int opcao;

    // Executa automaticamente o teste obrigatório ao iniciar
    executarTesteObigatorio();

    // Menu interativo para uso contínuo
    do {
        printf("\n=== MENU - ATENDIMENTO POR SENHAS ===\n");
        printf("1. Gerar senha e adicionar à fila\n");
        printf("2. Chamar proxima senha (atender)\n");
        printf("3. Consultar proxima senha\n");
        printf("4. Mostrar senhas aguardando\n");
        printf("5. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                gerarEInserir(&f, &contadorSenha);
                break;
            case 2:
                chamarProxima(&f);
                break;
            case 3:
                consultarProxima(&f);
                break;
            case 4:
                mostrarFila(&f);
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