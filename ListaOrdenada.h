//
// Created by a2104563 on 17/09/19.
//

#ifndef UNTITLED_LISTAORDENADA_H
#define UNTITLED_LISTAORDENADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  {
    int chave;
} Objeto;

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    Objeto obj;
    PtrNoLista proximo;
} NoLista;

typedef struct {
    PtrNoLista inicio;
    int tamanho;
} Lista;

void iniciaLista(Lista *list){
    list->inicio=NULL;
    list->tamanho = 0;
};
bool estaVazia(Lista *list) {
    if (list->inicio == NULL) {
        return true;
    } else {
        return false;
    }
}
void inserir(Lista *list, Objeto x){

    PtrNoLista novo;
    novo=(PtrNoLista)malloc(sizeof(NoLista));
    novo->obj=x;

    if ((estaVazia(list)==true) || (x.chave<list->inicio->obj.chave)){
        novo->proximo = list->inicio;
        list->inicio= novo;
    }
    else{
        PtrNoLista aux;
        aux = list->inicio;
        while (aux->proximo != NULL && x.chave> aux->obj.chave) {
            aux = aux->proximo;
        }
        novo->proximo= aux->proximo;
        aux->proximo= novo;

    }
    list->tamanho++;

};
void imprimirLista(Lista *list){
    PtrNoLista aux;
    for (aux= list->inicio; aux != NULL ; aux=aux->proximo) {
        printf("%d\n", aux->obj.chave);
    }
    printf("\n");
};
void destruirLista(Lista *list){;

};
bool pesquisar(Lista *list, Objeto chave){
    if (estaVazia(list)== true){
        return false;
    }
    PtrNoLista aux;
    aux= list->inicio;
    while (aux!=NULL && chave.chave > aux->obj.chave){
        aux= aux->proximo;
    }
    if (aux==NULL || aux->obj.chave > chave.chave){
        return false;
    }
    return true;

};
int tamanhoLista(Lista *list){
    return (list->tamanho);
};
void removeElemento(Lista *list, int chave, Objeto *item);
void removePrimeiro(Lista *list, Objeto *item);
void removeUltimo(Lista *list, Objeto *item);
Objeto primeiro(Lista *list);
Objeto ultimo(Lista *list);

#endif //UNTITLED_LISTAORDENADA_H
