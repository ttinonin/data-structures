#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EFila {
    Registro *dados;
    struct EFila *proximo;
} EFila;

typedef struct Fila {
    EFila *head;
    EFila *tail;
    int qtde;
} Fila;

Fila *cria_fila() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));

    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;

    return fila;
}

void enqueue(Fila *fila, Registro *registro) {
	EFila *node = (EFila*)malloc(sizeof(EFila));

	node->dados = registro;
	node->proximo = NULL;

	if(fila->head == NULL) {
		fila->head = node;
		fila->tail = node;
	} else {
		fila->tail->proximo = node;
		fila->tail = node;
	}

	fila->qtde++;
}

Registro *dequeue(Fila *fila) {
	EFila *aux = fila->head;

	Registro *registro;

	fila->head = aux->proximo;
	aux->proximo = NULL;

	registro = aux->dados;
	free(aux);

	if(fila->head == NULL) {
		fila->tail = NULL;
	}

	fila->qtde--;
	return registro;
}

void imprime_fila(Fila *fila) {
	int contador = 1;
	EFila *node = fila->head;

	if(node == NULL) {
		printf("\nSem pacientes na fila!\n");
		return;
	}

	while(node != NULL) {
		printf("\nPosicao: %d", contador);
		printf("\nNome: %s", node->dados->nome);
		printf("\nRG: %s", node->dados->rg);
		printf("\n");

		contador++;
		node = node->proximo;
	}
}
