#include<stdlib.h>
#include<stdio.h>



typedef struct EABB {
    Registro *dados;
    struct EABB *filhoEsq;
    struct EABB *filhoDir;

}EABB;

typedef struct {
    EABB *raiz;
    int qtde;
}ABB;

EABB *criaEABB(Registro *dados){
    if(dados!=NULL){
        EABB *novo = (EABB*)malloc(sizeof(EABB));
        novo->dados = dados;
        novo->filhoEsq = NULL;
        novo->filhoDir = NULL;

        return novo;
    }
    printf("Dados invalidos\n");
    return NULL;
}

ABB *criaABB(){
    ABB *abb = (ABB*)malloc(sizeof(ABB));
    abb->qtde = 0;
    abb->raiz = NULL;

    return abb;
}

void inserirPorAnoABB(ABB *arv, Registro *dados){
    EABB *novo = criaEABB(dados);
    if(arv->raiz == NULL){
        arv->raiz = novo;

    }
    else{
        EABB *atual = arv->raiz;
        EABB *ant = NULL;
        while(atual != NULL){
            if(dados->data->ano > atual->dados->data->ano){
                ant = atual;
                atual = atual->filhoDir;
            }
            else{
                ant = atual;
                atual = atual->filhoEsq;
            }
        }
        if(dados->data->ano > ant->dados->data->ano){
            ant->filhoDir = novo;
        }
        else{
            ant->filhoEsq = novo;
        }

    }
}

void inserirPorMesABB(ABB *arv, Registro *dados){
    EABB *novo = criaEABB(dados);
    if(arv->raiz == NULL){
        arv->raiz = novo;

    }
    else{
        EABB *atual = arv->raiz;
        EABB *ant = NULL;
        while(atual != NULL){
            if(dados->data->mes > atual->dados->data->mes){
                ant = atual;
                atual = atual->filhoDir;
            }
            else{
                ant = atual;
                atual = atual->filhoEsq;
            }
        }
        if(dados->data->mes > ant->dados->data->mes){
            ant->filhoDir = novo;
        }
        else{
            ant->filhoEsq = novo;
        }

    }
}

void inserirPorDiaABB(ABB *arv, Registro *dados){
    EABB *novo = criaEABB(dados);
    if(arv->raiz == NULL){
        arv->raiz = novo;

    }
    else{
        EABB *atual = arv->raiz;
        EABB *ant = NULL;
        while(atual != NULL){
            if(dados->data->dia > atual->dados->data->dia){
                ant = atual;
                atual = atual->filhoDir;
            }
            else{
                ant = atual;
                atual = atual->filhoEsq;
            }
        }
        if(dados->data->dia > ant->dados->data->dia){
            ant->filhoDir = novo;
        }
        else{
            ant->filhoEsq = novo;
        }

    }
}

void inserirPorIdadeABB(ABB *arv, Registro *dados){

    EABB *novo = criaEABB(dados);
    if(arv->raiz == NULL){
        arv->raiz = novo;

    }
    else{
        EABB *atual = arv->raiz;
        EABB *ant = NULL;
        while(atual != NULL){
            if(dados->idade > atual->dados->idade){
                ant = atual;
                atual = atual->filhoDir;
            }
            else{
                ant = atual;
                atual = atual->filhoEsq;
            }
        }
        if(dados->idade > ant->dados->idade){
            ant->filhoDir = novo;
        }
        else{
            ant->filhoEsq = novo;
        }

    }
}

void in_ordem(EABB *raiz) {
  if (raiz != NULL) {
    in_ordem(raiz->filhoEsq);
    printf("Nome: %s\n", raiz->dados->nome);
    printf("RG: %s\n", raiz->dados->rg);
    printf("Idade: %d\n", raiz->dados->idade);
    printf("Data: %02d/%02d/%04d\n", raiz->dados->data->dia, raiz->dados->data->mes, raiz->dados->data->ano);
    in_ordem(raiz->filhoDir);
  }
}
