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
    int altura;
} NoArvoreAVL;

void iniciaArvoreAVL(PtrArvoreAVL *arvore){
    *arvore=NULL;
}
bool estaVaziaArvoreAVL(PtrArvoreAVL *arvore){
    return ((*arvore)==NULL);
}

void preOrdem(PtrArvoreAVL *arvore){
    if (*arvore== NULL){
        return;
    }
    else{
        printf("%d  ", (*arvore)->elemento.chave);
        preOrdem(&(*arvore)->esquerda);
        preOrdem(&(*arvore)->direita);
    }
}
void posOrdem(PtrArvoreAVL *arvore){
    if ((*arvore)==NULL){
        return;
    }
    else {
    posOrdem(&(*arvore)->esquerda);
    posOrdem(&(*arvore)->direita);
    printf("%d  ", (*arvore)->elemento.chave);
    }
}
void EmOrdem(PtrArvoreAVL *arvore){
    if ((*arvore)==NULL){
        return;
    }
    else {
        EmOrdem(&(*arvore)->esquerda);
        printf("%d  ", (*arvore)->elemento.chave);
        EmOrdem(&(*arvore)->direita);
    }
}
int alturaArvoreAVL(PtrArvoreAVL *arvore){
    return ((*arvore)->altura);
}
int atualizaAlturaArvoreAVL(PtrArvoreAVL esquerda, PtrArvoreAVL direita){

}
void RSimpDir(PtrArvoreAVL *arvore){
    PtrArvoreAVL u;
    u = (*arvore)->esquerda;
    (*arvore)->esquerda = u->direita;
    u->direita = (*arvore);
    (*arvore) = u;
}
void RSimpEsq(PtrArvoreAVL *arvore){
    PtrArvoreAVL u;
    u=(*arvore)->direita;
    (*arvore)->direita=u->esquerda;
    u->esquerda= (*arvore);
    (*arvore)= u;
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
    (*arvore)= v;
}

void RDuplaDir(PtrArvoreAVL *arvore) {
    PtrArvoreAVL u;
    PtrArvoreAVL v;
    u = (*arvore)->esquerda;
    v = u->direita;
    u->direita = v->esquerda;
    (*arvore)->esquerda = v->direita;
    v->direita = (*arvore);
    v->esquerda = u;
    (*arvore) = v;
}
void aplicarRotacoes(PtrArvoreAVL *arvore, int bf){
    if ((bf == 2) && (alturaArvoreAVL(&(*arvore)->direita) > alturaArvoreAVL(&(*arvore)->esquerda))){
        printf("ROTAÇÃO SIMPLES P/ ESQUERDA...\n");
        RSimpEsq(&(*arvore));
    }
    else if ((bf == -2) && (alturaArvoreAVL(&(*arvore)->esquerda) > alturaArvoreAVL(&(*arvore)->direita))){
        printf("ROTAÇÃO SIMPLES P/ DIREITA...\n");
        RSimpDir(&(*arvore));
    }
    else if ((bf == 2) && (alturaArvoreAVL(&(*arvore)->esquerda) > alturaArvoreAVL(&(*arvore)->direita))){
        printf("ROTAÇÃO DUPLA P/ ESQUERDA...\n");
        RDuplaEsq(&(*arvore));
    }
    else if ((bf == -2) && (alturaArvoreAVL(&(*arvore)->direita) > alturaArvoreAVL(&(*arvore)->esquerda))){
        printf("ROTAÇÃO DUPLA P/ DIREITA...\n");
        RDuplaDir(&(*arvore));
    }

};


bool inserirArvoreAVL(PtrArvoreAVL *arvore, Objeto x){
    bool aux=0;
    if ((*arvore)==NULL){
        (*arvore)= (PtrArvoreAVL)malloc(sizeof(NoArvoreAVL));
        (*arvore)->elemento=x;
        (*arvore)->direita=(*arvore)->esquerda=NULL;
        (*arvore)->elemento=x;

        return (true);
    }
    else if ((*arvore)->elemento.chave == x.chave){
        return (false);
    }
    else if ((*arvore)->elemento.chave > x.chave){
        aux= inserirArvoreAVL(&(*arvore)->esquerda, x);
    }
    else if((*arvore)->elemento.chave < x.chave){
        aux= inserirArvoreAVL(&(*arvore)->direita, x);
    }
    if (aux == false) return (false);

    int hdir, hesq, bf;
    hdir= alturaArvoreAVL(&(*arvore)->direita);
    hesq= alturaArvoreAVL(&(*arvore)->esquerda);
    bf = hdir - hesq;
    if ((bf == -2) || (bf ==2)){
        printf("APLICANDO ROTAÇÃO\n");
        aplicarRotacoes(&(*arvore), bf);
    }
    (*arvore)->altura= atualizaAlturaArvoreAVL((*arvore)->esquerda,(*arvore)->direita);
    return (true);
}


void imprimeArvoreAVLNivel(PtrArvoreAVL *arvore);

#endif //UNTITLED_ARVOREAVL_H
