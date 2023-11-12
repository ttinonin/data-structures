#include<stdlib.h>
#include<stdio.h>


//estrutura para os elementos da arvore
typedef struct EABB {
    Registro *dados;
    struct EABB *filhoEsq;
    struct EABB *filhoDir;
    struct EABB *pai;

}EABB;

//estrutura para a arvore
typedef struct {
    EABB *raiz;
    int qtde;
}ABB;

//inicializa um elemento de arvore
EABB *criaEABB(Registro *dados){
    if(dados!=NULL){
        EABB *novo = (EABB*)malloc(sizeof(EABB));
        novo->dados = dados;
        novo->filhoEsq = NULL;
        novo->filhoDir = NULL;
        novo->pai = NULL;

        return novo;
    }
    printf("Dados invalidos\n");
    return NULL;
}

//inicializa uma arvore
ABB *criaABB(){
    ABB *abb = (ABB*)malloc(sizeof(ABB));
    abb->qtde = 0;
    abb->raiz = NULL;

    return abb;
}

//Faz a inserção dos elementos baseado no ano de nascimento dos pacientes
void inserirPorAnoABB(ABB *arv, Registro *dados){
    //inicializa uma nova celula com os dados do paciente
    EABB *novo = criaEABB(dados);
    if(arv->raiz == NULL){
        //se a raiz for null então o novo elemento passa a ser a raiz
        arv->raiz = novo;

    }
    else{
        //percorre a arvore ate que o atual seja null
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
        //insere o elemento na posicao correta
        if(dados->data->ano > ant->dados->data->ano){
            ant->filhoDir = novo;
            ant->filhoDir->pai = ant;
        }
        else{
            ant->filhoEsq = novo;
            ant->filhoEsq->pai = ant;
        }

    }
}

//Faz a inserção dos elementos baseado no mes de nascimento dos pacientes
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
            ant->filhoDir->pai = ant;
        }
        else{
            ant->filhoEsq = novo;
            ant->filhoEsq->pai = ant;
        }

    }
}

//Faz a inserção dos elementos baseado no dia de nascimento dos pacientes
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
            ant->filhoDir->pai = ant;
        }
        else{
            ant->filhoEsq = novo;
            ant->filhoEsq->pai = ant;
        }

    }
}

//Faz a inserção dos elementos baseado na idade dos pacientes
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
            ant->filhoDir->pai = ant;
        }
        else{
            ant->filhoEsq = novo;
            ant->filhoEsq->pai = ant;
        }

    }
}

//=========================FUNÇÕES DE REMOÇÃO DAS ARVORES==============================================

int *removerPorAno(ABB *arvore, EABB *vertice) {
  //cria um registro auxiliar para fazer as comparações dos elementos
  Registro *v = vertice->dados;
  int ano = v->data->ano;

  //verifica se o elemento é folha
  if (vertice->filhoDir == NULL && vertice->filhoEsq == NULL) {
    //verifica se é raiz
    if(vertice->pai == NULL){
      arvore->raiz = NULL;
    }
    else{
        //seta os filhos do pai do vertice como null
      if (vertice->pai->dados->data->ano >= vertice->dados->data->ano) {
        vertice->pai->filhoEsq = NULL;
      } else {
        vertice->pai->filhoDir = NULL;
      }
    }

    //libera a memoria do vertice, registro e decrementa a qtde
    arvore->qtde--;
    free(vertice);
    free(v);
    return ano;
  } else {
      //verifica se o vertice tem dois fihos
    if (vertice->filhoEsq != NULL && vertice->filhoDir != NULL) {
        //cria uma variavel auxiliar que recebe o filho da direita
      EABB *aux = vertice->filhoDir;
      //caso o filho esquerdo seja null, é conectado o filho direito do aux direto no vertice
      if(aux->filhoEsq == NULL){
            //troca de dados
        vertice->dados = aux->dados;
        aux->dados = v;
        if(aux->filhoDir != NULL){
            vertice->filhoDir = aux->filhoDir;
        }else{
            vertice->filhoDir = NULL;
        }
        //libera o aux
        arvore->qtde--;
        free(aux);
        free(v);
        return ano;
      }
        //percorre todos os filhos a esquerda do filho a direita do vertice
      while (aux->filhoEsq != NULL) {

        aux = aux->filhoEsq;
      }
      vertice->dados = aux->dados;
      aux->dados = v;
      arvore->qtde--;
      free(v);
      //remove o aux por recursao, que agora contem os dados do vertice
      return removerPorAno(arvore, aux);
    }

    else {
            //caso tenha apenas um filho
      if (vertice->filhoEsq != NULL) {
          //caso seja raiz
        if(vertice->pai == NULL){
          arvore->raiz = vertice->filhoEsq;
          vertice->filhoEsq->pai = NULL;
          free(vertice);
          arvore->qtde--;
          free(v);
          return ano;
        }
        else{
          if (vertice->pai->dados->data->ano >= vertice->dados->data->ano) {
            vertice->pai->filhoEsq = vertice->filhoEsq;
            vertice->filhoEsq->pai = vertice->pai;


          }else {

            vertice->pai->filhoDir = vertice->filhoEsq;
            vertice->filhoEsq->pai = vertice->pai;

          }
        }

      }
      else {
        if(vertice->pai == NULL){
          arvore->raiz = vertice->filhoDir;
          vertice->filhoDir->pai = NULL;
          free(vertice);
          arvore->qtde--;
          free(v);
          return ano;
        }
        else{
          if (vertice->pai->dados->data->ano >= vertice->dados->data->ano) {
            vertice->pai->filhoEsq = vertice->filhoDir;
            vertice->filhoDir->pai = vertice->pai;


          }else {

            vertice->pai->filhoDir = vertice->filhoDir;
            vertice->filhoDir->pai = vertice->pai;

          }
        }
      }
      //liberacao da memoria
      arvore->qtde--;
      free(vertice);
      free(v);
      return ano;
    }
  }
  return -1;
}

int *removerPorMes(ABB *arvore, EABB *vertice) {
  Registro *v = vertice->dados;
  int mes = v->data->mes;
  if (vertice->filhoDir == NULL && vertice->filhoEsq == NULL) {
    if(vertice->pai == NULL){
      arvore->raiz = NULL;
    }
    else{
      if (vertice->pai->dados->data->mes >= vertice->dados->data->mes) {
        vertice->pai->filhoEsq = NULL;
      } else {
        vertice->pai->filhoDir = NULL;
      }
    }

    arvore->qtde--;
    free(vertice);
    free(v);
    return mes;
  } else {
    if (vertice->filhoEsq != NULL && vertice->filhoDir != NULL) {

      EABB *aux = vertice->filhoDir;
      if(aux->filhoEsq == NULL){

        vertice->dados = aux->dados;
        aux->dados = v;
        if(aux->filhoDir != NULL){
            vertice->filhoDir = aux->filhoDir;
        }else{
            vertice->filhoDir = NULL;
        }
        arvore->qtde--;
        free(aux);
        free(v);
        return mes;
      }

      while (aux->filhoEsq != NULL) {

        aux = aux->filhoEsq;
      }
      vertice->dados = aux->dados;
      aux->dados = v;
      arvore->qtde--;
      free(v);
      return removerPorMes(arvore, aux);
    }

    else {
      if (vertice->filhoEsq != NULL) {
        if(vertice->pai == NULL){
          arvore->raiz = vertice->filhoEsq;
          vertice->filhoEsq->pai = NULL;
          free(vertice);
          arvore->qtde--;
          free(v);
          return mes;

        }
        else{
          if (vertice->pai->dados->data->mes >= vertice->dados->data->mes) {
            vertice->pai->filhoEsq = vertice->filhoEsq;
            vertice->filhoEsq->pai = vertice->pai;


          }else {

            vertice->pai->filhoDir = vertice->filhoEsq;
            vertice->filhoEsq->pai = vertice->pai;

          }
        }

      }
      else {
        if(vertice->pai == NULL){
          arvore->raiz = vertice->filhoDir;
          vertice->filhoDir->pai = NULL;
          free(vertice);
          arvore->qtde--;
          free(v);
          return mes;
        }
        else{
          if (vertice->pai->dados->data->mes >= vertice->dados->data->mes) {
            vertice->pai->filhoEsq = vertice->filhoDir;
            vertice->filhoDir->pai = vertice->pai;


          }else {

            vertice->pai->filhoDir = vertice->filhoDir;
            vertice->filhoDir->pai = vertice->pai;

          }
        }
      }
      arvore->qtde--;
      free(vertice);
      free(v);
      return mes;
    }
  }
  return -1;
}

int *removerPorDia(ABB *arvore, EABB *vertice) {
  Registro *v = vertice->dados;
  int dia = v->data->dia;

  if (vertice->filhoDir == NULL && vertice->filhoEsq == NULL) {

    if(vertice->pai == NULL){

      arvore->raiz = NULL;
    }
    else{
      if (vertice->pai->dados->data->dia >= vertice->dados->data->dia) {
        vertice->pai->filhoEsq = NULL;
      } else {
        vertice->pai->filhoDir = NULL;
      }
    }

    arvore->qtde--;

    free(vertice);

    free(v);
    return dia;
  }
  else {

    if (vertice->filhoEsq != NULL && vertice->filhoDir != NULL) {

      EABB *aux = vertice->filhoDir;
      if(aux->filhoEsq == NULL){

        vertice->dados = aux->dados;
        aux->dados = v;
        if(aux->filhoDir != NULL){
            vertice->filhoDir = aux->filhoDir;
        }else{
            vertice->filhoDir = NULL;
        }
        arvore->qtde--;
        free(aux);
        free(v);
        return dia;
      }

      while (aux->filhoEsq != NULL) {

        aux = aux->filhoEsq;
      }

      vertice->dados = aux->dados;
      aux->dados = v;


      return removerPorDia(arvore, aux);
    }

    else {

      if (vertice->filhoEsq != NULL) {

        if(vertice->pai == NULL){

          arvore->raiz = vertice->filhoEsq;
          vertice->filhoEsq->pai = NULL;
          free(vertice);
          free(v);
          arvore->qtde--;
          return dia;
        }
        else{

          if (vertice->pai->dados->data->dia >= vertice->dados->data->dia) {

            vertice->pai->filhoEsq = vertice->filhoEsq;
            vertice->filhoEsq->pai = vertice->pai;

          }
          else {

            vertice->pai->filhoDir = vertice->filhoEsq;
            vertice->filhoEsq->pai = vertice->pai;

          }
        }

      }
      else {
        if(vertice->pai == NULL){

          arvore->raiz = vertice->filhoDir;
          vertice->filhoDir->pai = NULL;
          free(vertice);
          free(v);
          arvore->qtde--;
          return dia;
        }
        else{
          if (vertice->pai->dados->data->dia >= vertice->dados->data->dia) {

            vertice->pai->filhoEsq = vertice->filhoDir;
            vertice->filhoDir->pai = vertice->pai;


          }else {

            vertice->pai->filhoDir = vertice->filhoDir;
            vertice->filhoDir->pai = vertice->pai;

          }
        }
      }
      arvore->qtde--;
      free(vertice);
      free(v);
      return dia;
    }
  }

  return -1;
}

int *removerPorIdade(ABB *arvore, EABB *vertice) {
  Registro *v = vertice->dados;
  int idade = v->idade;
  if (vertice->filhoDir == NULL && vertice->filhoEsq == NULL) {
    if(vertice->pai == NULL){
      arvore->raiz = NULL;
    }
    else{

      if (vertice->pai->dados->idade >= vertice->dados->idade) {
        vertice->pai->filhoEsq = NULL;
      } else {
        vertice->pai->filhoDir = NULL;
      }
    }

    arvore->qtde--;
    free(vertice);
    free(v);
    return idade;
  }
  else {
    if (vertice->filhoEsq != NULL && vertice->filhoDir != NULL) {
      EABB *aux = vertice->filhoDir;
      if(aux->filhoEsq == NULL){

        vertice->dados = aux->dados;
        aux->dados = v;
        if(aux->filhoDir != NULL){
            vertice->filhoDir = aux->filhoDir;
        }else{
            vertice->filhoDir = NULL;
        }

        arvore->qtde--;
        free(aux);
        free(v);
        return idade;
      }

      while (aux->filhoEsq != NULL) {

        aux = aux->filhoEsq;
      }
      vertice->dados = aux->dados;
      aux->dados = v;
      free(v);
      return removerPorIdade(arvore, aux);
    }

    else {
      if (vertice->filhoEsq != NULL) {
        if(vertice->pai == NULL){
          arvore->raiz = vertice->filhoEsq;
          vertice->filhoEsq->pai = NULL;
          free(vertice);
          arvore->qtde--;
          free(v);
          return idade;
        }
        else{
          if (vertice->pai->dados->idade >= vertice->dados->idade) {
            printf("esq esq");
            vertice->pai->filhoEsq = vertice->filhoEsq;
            vertice->filhoEsq->pai = vertice->pai;


          }else {
            printf("dir esq");
            vertice->pai->filhoDir = vertice->filhoEsq;
            vertice->filhoEsq->pai = vertice->pai;

          }
        }

      }
      else {
        if(vertice->pai == NULL){
          arvore->raiz = vertice->filhoDir;
          vertice->filhoDir->pai = NULL;
          free(vertice);
          arvore->qtde--;
          free(v);
          return idade;
        }
        else{
          if (vertice->pai->dados->idade >= vertice->dados->idade) {
            printf("esq dir");
            vertice->pai->filhoEsq = vertice->filhoDir;
            vertice->filhoDir->pai = vertice->pai;


          }else {
            printf("dir dir");
            vertice->pai->filhoDir = vertice->filhoDir;
            vertice->filhoDir->pai = vertice->pai;

          }
        }
      }
      arvore->qtde--;
      free(vertice);
      free(v);
      return idade;
    }
  }
  return -1;
}


//====================================FUNCOES DE BUSCA DE EABB===================================


EABB *buscarValorPorAno(ABB *arvore, Registro *dados) {
  //percorre a arvore a partir da raiz
  EABB *atual = arvore->raiz;
  while (atual != NULL) {
    if (dados->data->ano < atual->dados->data->ano ) {
      atual = atual->filhoEsq;
    } else {
      if (dados->data->ano  > atual->dados->data->ano ) {
        atual = atual->filhoDir;
      } else {
        if(strcmp(atual->dados->rg, dados->rg) == 0){
            //caso o rg dos dados seja igual ao rg do EABB, o EABB é retornado
            return atual;
        }
        else{
            atual = atual->filhoEsq;
        }
      }
    }
  }
  return NULL;
}

EABB *buscarValorPorMes(ABB *arvore, Registro *dados) {
  EABB *atual = arvore->raiz;
  while (atual != NULL) {
    if (dados->data->mes < atual->dados->data->mes) {
      atual = atual->filhoEsq;
    }
    else {
      if (dados->data->mes > atual->dados->data->mes) {
        atual = atual->filhoDir;
      }
      else {
        if(strcmp(atual->dados->rg, dados->rg) == 0){
            return atual;
        }
        else{
            atual = atual->filhoEsq;
        }

      }
    }
  }
  return NULL;
}

EABB *buscarValorPorDia(ABB *arvore, Registro *dados) {
  EABB *atual = arvore->raiz;
  while (atual != NULL) {
    if (dados->data->dia < atual->dados->data->dia) {
      atual = atual->filhoEsq;
    } else {
      if (dados->data->dia > atual->dados->data->dia) {
        atual = atual->filhoDir;
      } else {
        if(strcmp(atual->dados->rg, dados->rg) == 0){

            return atual;
        }
        else{
            atual = atual->filhoEsq;
        }
      }
    }
  }
  return NULL;
}

EABB *buscarValorPorIdade(ABB *arvore, Registro *dados) {
  EABB *atual = arvore->raiz;
  while (atual != NULL) {
    if (dados->idade < atual->dados->idade) {
      atual = atual->filhoEsq;
    } else {
      if (dados->idade > atual->dados->idade) {
        atual = atual->filhoDir;
      } else {
        if(strcmp(atual->dados->rg, dados->rg) == 0){
            return atual;
        }
        else{
            atual = atual->filhoEsq;
        }
      }
    }
  }
  return NULL;
}

//exibe os elementos da arvore de modo crescente
void in_ordem(EABB *raiz) {

  if (raiz != NULL) {
        //percorre todos os elementos a esqueda, até receber null
    in_ordem(raiz->filhoEsq);
    printf("Nome: %s\n", raiz->dados->nome);
    printf("RG: %s\n", raiz->dados->rg);
    printf("Idade: %d\n", raiz->dados->idade);
    printf("Data: %02d/%02d/%04d\n", raiz->dados->data->dia, raiz->dados->data->mes, raiz->dados->data->ano);
    printf("\n");
    //vai pegando os elementos da direita dos que estão a esquerda
    in_ordem(raiz->filhoDir);
  }
}


