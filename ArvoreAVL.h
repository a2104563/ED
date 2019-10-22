#ifndef UNTITLED_ARVOREAVL_H
#define UNTITLED_ARVOREAVL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
} Objeto;

typedef struct NoArvoreAVL *PtrArvoreAVL;

typedef struct NoArvoreAVL {
    Objeto elemento;
    PtrArvoreAVL esquerda;
    PtrArvoreAVL direita;
    int tamanho;
} NoArvoreAVL;

void RSimpDir(PtrArvoreAVL *arvore){
    PtrArvoreAVL u;
    u = (*arvore)->esquerda;
    (*arvore)->esquerda = u->direita;
    u->direita = (*arvore);
    (*arvore) = u;
}
void RDuplaEsq(PtrArvoreAVL *arvore){
    PtrArvoreAVL v;
    PtrArvoreAVL u;
    u = (*arvore)->direita;
    v = u->esquerda;
    (*arvore)->direita = v->esquerda;
    u->esquerda = v->direita;
    v->direita = u;
    v->esquerda = (*arvore);
    //recalc
    (*arvore)= v;
}
void RDuplaDir(PtrArvoreAVL *arvore){
    PtrArvoreAVL u;
    PtrArvoreAVL v;
    u = (*arvore)->esquerda;
    v = u->direita;
    u->direita = v->esquerda;
    (*arvore)->esquerda = v->direita;
    v->direita = (*arvore);
    v->esquerda = u;
    //recalc
    (*arvore)= v;
}

#endif //UNTITLED_ARVOREAVL_H
