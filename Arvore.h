//
// Created by a2104563 on 04/10/19.
//

#ifndef UNTITLED_ARVORE_H
#define UNTITLED_ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
} Objeto;

typedef struct NoArvore *PtrArvore;

typedef struct NoArvore {
    Objeto elemento;
    PtrArvore esquerda;
    PtrArvore direita;
} NoArvore;

int numeroNosArvore(PtrArvore *arvore);
int alturaArvore(PtrArvore *arvore);
void iniciaArvore(PtrArvore *arvore){
    *arvore=NULL;
};
bool estaVazia(PtrArvore *arvore){
    return (*arvore==NULL);
};
bool insereItem(PtrArvore *arvore, Objeto x){

    if ((*arvore)==NULL){
        (*arvore)= (PtrArvore)malloc(sizeof(NoArvore));
        (*arvore)->elemento=x;
        (*arvore)->direita=(*arvore)->esquerda=NULL;
        (*arvore)->elemento=x;
        return (true);
    }
    if ((*arvore)->elemento.chave == x.chave){
        return (false);
    }
    if ((*arvore)->elemento.chave > x.chave){
        return (insereItem(&(*arvore)->esquerda, x));
    }
    else{
        return (insereItem(&(*arvore)->direita, x));
    }
};
void destroiArvore(PtrArvore *arvore);
void preOrdem(PtrArvore *arvore){
    if (*arvore== NULL){
        return;
    }
    else{
        printf("%d,", (*arvore)->elemento.chave);
        preOrdem(&(*arvore)->esquerda);
        preOrdem(&(*arvore)->direita);
    }
};
void posOrdem(PtrArvore *arvore){
    if ((*arvore)==NULL){
        return;
    }
    else {
        posOrdem(&(*arvore)->esquerda);
        posOrdem(&(*arvore)->direita);
        printf("%d,", (*arvore)->elemento.chave);
    }
};
void EmOrdem(PtrArvore *arvore){
    if ((*arvore)==NULL){
        return;
    }
    else {
        EmOrdem(&(*arvore)->esquerda);
        printf("%d,", (*arvore)->elemento.chave);
        EmOrdem(&(*arvore)->direita);
    }

};

bool procuraItem(PtrArvore *arvore, int key, Objeto *ret){
    if ((*arvore)==NULL){
        return (false);
    }
    if ((*arvore)->elemento.chave == key){
        return (true);
    }
    if (key < (*arvore)->elemento.chave){
        return procuraItem(&(*arvore)->esquerda, key, ret);
    }
    else{
        return procuraItem(&(*arvore)->direita, key, ret);
    }
};

bool removeItem(PtrArvore *arvore, int key);
PtrArvore maximo(PtrArvore *arvore){

};
PtrArvore maximoIterativo(PtrArvore *arvore);
PtrArvore minimo(PtrArvore *arvore){
    PtrArvore aux=NULL;
    while ((*arvore)->esquerda != NULL){
        aux= ((*arvore)->esquerda);
    }
    printf("%d", aux);


};
PtrArvore minimoIterativo(PtrArvore *arvore);
PtrArvore getMinAux(PtrArvore *arvore); //usado na remoção
PtrArvore getMaxAux(PtrArvore *arvore); //usado na remoção

#endif //UNTITLED_ARVORE_H
