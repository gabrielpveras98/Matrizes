#include <stdio.h>
#include <stdlib.h>

typedef struct linha * Linha;

struct linha{
    int conteudo;
    struct linha *proximo;
};

Linha * criarLista(){
    Linha * li = (Linha *) malloc(sizeof(Linha));
    return li;
}

void liberarLista(Linha * li){
    if (li != NULL){
        Linha no;
        while ((*li) != NULL){
            no = *li;
            (*li) = (*li)->proximo;
            free(no);
        }
        free(li);
    }
}

int inserirNoInicio(int valor, Linha * li){
    if(li == NULL){
        return 0;
    }
    Linha no = (Linha *) malloc(sizeof(Linha));
    if (no == NULL){
        return 0;
    }
    no->proximo = (*li);
    no->conteudo = valor;
    (*li) = no;
    return 1;
}

int inserirNoFim(int valor, Linha *li){
    if (li == NULL){
        return 0;
    }
    if ((*li) == NULL){
        return 0;
    }
    Linha no = (*li);
    while (no->proximo != NULL){
        //anterior = no;
        no = (*no).proximo;
    }
    Linha novo = (Linha *) malloc(sizeof(Linha));
    no->proximo = novo;
    novo->conteudo = valor;
}

void verLista(Linha * li){
    Linha no = (*li);
    while (no != NULL){
        printf("%d ", no->conteudo);
        no = (*no).proximo;
    }
    printf("\n");
}
