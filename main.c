#include <stdio.h>
#include <stdlib.h>
#include "Matriz.c"

int main() {
    Matriz *m;

    m = criaMatriz();

    gerarMatriz(3, 3, &m);

    liberarMatriz(m);

    printf("Okay");

    return 0;
}