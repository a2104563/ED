//
// Created by a2104563 on 01/10/19.
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
void destroiArvore(PtrArvore *arvore);
void preOrdem(PtrArvore *arvore);
void posOrdem(PtrArvore *arvore);
void EmOrdem(PtrArvore *arvore);
bool insereItem(PtrArvore *arvore, Objeto x){
    PtrArvore raiz;
    if (estaVazia(arvore)){
        raiz= (PtrArvore)malloc(sizeof(NoArvore));
        raiz->elemento=x;
        raiz->direita=raiz->esquerda=NULL;
        raiz->elemento=x;
        return (true);
    }
    if ()


};
bool procuraItem(PtrArvore *arvore, int key, Objeto *ret);

bool removeItem(PtrArvore *arvore, int key);
PtrArvore maximo(PtrArvore *arvore);
PtrArvore maximoIterativo(PtrArvore *arvore);
PtrArvore minimo(PtrArvore *arvore);
PtrArvore minimoIterativo(PtrArvore *arvore);
PtrArvore getMinAux(PtrArvore *arvore); //usado na remoção
PtrArvore getMaxAux(PtrArvore *arvore); //usado na remoção


#endif //UNTITLED_ARVORE_H
