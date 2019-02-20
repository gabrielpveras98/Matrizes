#include <stdio.h>
#include <stdlib.h>
#include "Linha.c"

typedef struct matriz *Matriz;

struct matriz{
    struct linha *linha;
    struct Matriz *proxima;
};

Matriz * criaMatriz(){
    Matriz * mat = (Matriz*) malloc(sizeof(Matriz));
    return mat;
}

void liberarMatriz(Matriz *mat){
    if (mat != NULL){
        Matriz no;
        while ((*mat) != NULL){
            no = (*mat);
            (*mat) = (Matriz) (*mat)->proxima;
            liberarLista((Linha *) (no)->linha);
            free(no);
        }
        free(mat);
    }
}

void gerarMatriz(int linhas, int colunas, Matriz * m){
    int l, c, resposta;
    Matriz * auxiliar = criaMatriz();

    for (l = 0; l < linhas; l++){
        (*m)->linha = (struct linha *) criarLista();
        for (c = 0; c < colunas; ++c) {
            printf("insira o elemento: ");
            scanf("%d", &resposta);
            if(c == 0){
                inserirNoInicio(resposta, (Linha *) (*m)->linha);
            }else{
                inserirNoFim(resposta, (Linha *) (*m)->linha);
            }
        }
        verLista((Linha*)(*m)->linha);
        //printf("ok");
        //(*auxiliar)->linha = (*m)->linha;
        //(*m)->proxima = auxiliar;
    }
}
