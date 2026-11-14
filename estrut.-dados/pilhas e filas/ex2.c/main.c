#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // Capacidade máxima de 5 bandejas

typedef struct {
    int itens[TAM];
    int topo; // Índice do topo (-1 quando a pilha está vazia)
} PilhaBandejas;

// Inicializa a pilha de bandejas
void inicializar(PilhaBandejas *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(PilhaBandejas *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int estaCheia(PilhaBandejas *p) {
    return p->topo == TAM - 1;
}

// 1. Adicionar uma bandeja (Push)
void adicionarBandeja(PilhaBandejas *p, int numero) {
    if (estaCheia(p)) {
        printf("\n[AVISO] A pilha de bandejas esta cheia! Nao e possivel adicionar mais no momento.\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = numero;
    printf("\nBandeja %d adicionada ao topo da pilha.\n", numero);
}

// 2. Retirar a bandeja do topo, informando o seu número (Pop)
void retirarBandeja(PilhaBandejas *p) {
    if (estaVazia(p)) {
        printf("\n[AVISO] A pilha de bandejas esta vazia! Nao ha bandejas para retirar.\n");
        return;
    }
    int retirada = p->itens[p->topo];
    p->topo--;
    printf("\nBandeja retirada do topo: %d\n", retirada);
}

// 3. Consultar a próxima bandeja disponível, sem retirá-la (Peek)
void consultarProxima(PilhaBandejas *p) {
    if (estaVazia(p)) {
        printf("\nA pilha de bandejas esta vazia.\n");
        return;
    }
    printf("\nProxima bandeja disponivel no topo: %d\n", p->itens[p->topo]);
}

// 4. Mostrar as bandejas do topo até à base
void mostrarBandejas(PilhaBandejas *p) {
    if (estaVazia(p)) {
        printf("\nA pilha de bandejas esta vazia.\n");
        return;
    }
    printf("\n=== PILHA DE BANDEJAS (DO TOPO ATE A BASE) ===\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("[Bandeja %d]", p->itens[i]);
        if (i == p->topo) {
            printf(" <-- TOPO");
        }
        printf("\n");
    }
    printf("---------------------------------------------\n");
}

// Execução do Teste Obrigatório especificado no enunciado
void executarTesteObigatorio() {
    PilhaBandejas lanchonete;
    inicializar(&lanchonete);

    printf("\n========================================\n");
    printf("INICIO DO TESTE OBRIGATORIO (LANCHONETE)\n");
    printf("========================================\n");

    // Adicionando as bandejas 101, 102 e 103[cite: 18]
    printf("\n-> A adicionar as bandejas 101, 102 e 103...\n");
    adicionarBandeja(&lanchonete, 101);
    adicionarBandeja(&lanchonete, 102);
    adicionarBandeja(&lanchonete, 103);

    mostrarBandejas(&lanchonete);

    // Realizando duas retiradas[cite: 18]
    printf("\n-> A realizar duas retiradas consecutivas do topo...\n");
    retirarBandeja(&lanchonete); // Retira a 103
    retirarBandeja(&lanchonete); // Retira a 102

    printf("\n-> Estado final apos as retiradas:\n");
    mostrarBandejas(&lanchonete);
    consultarProxima(&lanchonete);
    
    printf("\n========================================\n");
    printf("FIM DO TESTE OBRIGATORIO\n");
    printf("========================================\n");
}

int main() {
    PilhaBandejas p;
    inicializar(&p);
    int opcao, numero;

    // Executa automaticamente o teste obrigatório ao iniciar o programa
    executarTesteObigatorio();

    // Menu interativo para uso contínuo
    do {
        printf("\n=== MENU - PILHA DE BANDEJAS (LANCHONETE) ===\n");
        printf("1. Adicionar uma bandeja\n");
        printf("2. Retirar a bandeja do topo\n");
        printf("3. Consultar a proxima bandeja disponivel\n");
        printf("4. Mostrar bandejas (do topo ate a base)\n");
        printf("5. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero de identificacao da bandeja: ");
                scanf("%d", &numero);
                adicionarBandeja(&p, numero);
                break;
            case 2:
                retirarBandeja(&p);
                break;
            case 3:
                consultarProxima(&p);
                break;
            case 4:
                mostrarBandejas(&p);
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