#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

typedef struct EFila {
    Registro *dados;
    EFila *proximo;
} EFila;

typedef struct Fila {
    EFila *head;
    EFila *tail;
    int qtde;
} Fila;

void enqueue(Fila *fila, Registro *registro) {
	EFila *node = (EFila*)malloc(sizeof(EFila));
	
	node->dados = registro;
	node->proximo = NULL;

	if(fila->head == NULL) {
		fila->head = node;
		fila->tail = node;
	} else {
		fila->tail->proximo = node;
	}

	fila->qtde++;
}

EFila *dequeue(FIla *fila) {
	EFila *aux = fila->head;

	EFila *registro;

	fila->head = aux->proximo;
	aux->proximo = NULL;

	registro = aux->dados;
	free(aux);

	if(fila->head == NULL) {
		fila->tail = NULL;
	}

	return registro;
}

void imprime_fila() {
	int contador = 1;
	EFila *node = fila->head;

	if(node == NULL) {
		printf("\nSem pacientes na fila!\n");
		return;
	}

	while(node != NULL) {
		printf("\nPosicao: %dº", contador);
		printf("\nNome: %sº", node->dados->nome);
		printf("\nRG: %sº", node->dados->rg);
		printf("\n");
		
		contador++;
		node = node->proximo;
	}
}
