#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[30];
    Data data;
} Evento;

int dataMaior(Data d1, Data d2) {
    // Compara os anos
    if (d1.ano > d2.ano) return 1;
    if (d1.ano < d2.ano) return 0;
    
    // Se os anos forem iguais, compara os meses
    if (d1.mes > d2.mes) return 1;
    if (d1.mes < d2.mes) return 0;
    
    // Se os meses também forem iguais, compara os dias
    if (d1.dia > d2.dia) return 1;
    
    // Se for igual ou menor, retorna 0
    return 0;
}

Evento *eventoMaisRecente(Evento v[], int n) {
    if (n <= 0) return NULL;
    
    int maisRecenteIdx = 0;
    
    // Percorre o vetor de eventos para encontrar o que possui a data mais recente
    for (int i = 1; i < n; i++) {
        if (dataMaior(v[i].data, v[maisRecenteIdx].data)) {
            maisRecenteIdx = i;
        }
    }
    
    // Retorna o endereço do evento com a data mais recente
    return &v[maisRecenteIdx];
}

int main() {
    Evento agenda[4] = {
        {"Reuniao de projeto", {10, 3, 2026}},
        {"Entrega do TCC",     {21, 9, 2026}},
        {"Seminario de pesquisa",{5, 9, 2026}},
        {"Banca",              {2, 12, 2025}}
    };
    Evento *e;

    e = eventoMaisRecente(agenda, 4);
    printf("Mais recente: %s (%d/%d/%d)\n", e->nome, e->data.dia, e->data.mes, e->data.ano);
    return 0;
}