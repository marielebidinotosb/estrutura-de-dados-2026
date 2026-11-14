#include <stdio.h>

typedef struct {
    float x;
    float y;
} Vetor2D;

Vetor2D somar(Vetor2D a, Vetor2D b) {
    Vetor2D r;
    // Soma as coordenadas correspondentes de a e b
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

float produtoEscalar(Vetor2D a, Vetor2D b) {
    // Retorna o produto escalar entre os vetores (x1*x2 + y1*y2)
    return (a.x * b.x) + (a.y * b.y);
}

void escalar(Vetor2D *v, float k) {
    // Multiplica as coordenadas do vetor apontado por k usando o ponteiro
    v->x *= k;
    v->y *= k;
}

int main() {
    Vetor2D u = {3.0f, 4.0f};
    Vetor2D w = {1.0f, 2.0f};
    Vetor2D soma;

    soma = somar(u, w);
    printf("Soma: (%.1f, %.1f)\n", soma.x, soma.y);
    printf("Produto escalar: %.1f\n", produtoEscalar(u, w));
    escalar(&u, 2.0f);
    printf("u escalado: (%.1f, %.1f)\n", u.x, u.y);
    printf("Produto escalar apos escalar: %.1f\n", produtoEscalar(u, w));
    return 0;
}