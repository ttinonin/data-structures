#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structs escenciais para a fila
// com seu elemento sendo EFila
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
    // Alocamos dinamicamente uma fila na memoria
	// e a inicializamos
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
        // Caso a fila esteja vazia, o elemento e adicionado em seu inicio
		fila->head = node;
		fila->tail = node;
	} else {
	    // Caso contrario o elemento vai para o fim da fila
		fila->tail->proximo = node;
		fila->tail = node;
	}

	fila->qtde++;
}

Registro *dequeue(Fila *fila) {
	EFila *aux = fila->head;

	if(aux == NULL) {
        printf("\nFila vazia!\n");
        return;
	}

	Registro *registro;

    // Respeitando a ordem da fila o primeiro sai
	fila->head = aux->proximo;
	aux->proximo = NULL;

	registro = aux->dados;
	free(aux);

	if(fila->head == NULL) {
		fila->tail = NULL;
	}

	fila->qtde--;

	// o paciente excluido sera retornado
	return registro;
}

void imprime_fila(Fila *fila) {
    // O contador indica a posição do paciente na fila
	int contador = 1;
	EFila *node = fila->head;

	if(node == NULL) {
		printf("\nSem pacientes na fila!\n");
		return;
	}

	// Iteramos a fila e a mostramos para o usuário
	while(node != NULL) {
		printf("\nPosicao: %d", contador);
		printf("\nNome: %s", node->dados->nome);
		printf("\nRG: %s", node->dados->rg);
		printf("\n");

		contador++;
		node = node->proximo;
	}
}
