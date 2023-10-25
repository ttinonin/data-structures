#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

typedef struct ELista {
	Registro *dados;
	ELista *proximo;
} ELista;

typedef struct Lista {
	ELista *inicio;
	int qtde;
} Lista;

Data *cria_data(int dia, int mes, int ano) {
	Data *data = (Data*)malloc(sizeof(Data));

	data->dia = dia;
	data->mes = mes;
	data->ano = ano;

	return data;
}

Registro *cria_registro(Data *data, char nome[244], char rg[12], int idade) {
	Registro *registro = (Registro*)malloc(sizeof(Registro));

	registro->data = data;
	
	strcpy(registro->nome, nome);

	registro->idade = idade;
	
	strcpy(registro->rg, rg);

	return registro;
}

ELista *cria_node(Registro *registro) {
	ELista *node = (ELista*)malloc(sizeof(ELista));

	node->proximo = NULL;	
	node->dados = registro;

	return node;
}

Lista *cria_lista() {
	Lista* lista = (Lista*)malloc(sizeof(Lista));
	lista->inicio = NULL;
	lista->qtde = 0;

	return lista;
}

void insere_lista(Lista *lista, Registro *registro) {
	ELista *node = cria_node(registro);

	if(lista->inicio == NULL) {
		lista->inicio = node;
	} else {
		ELista *atual = lista->inicio;

		while(atual->proximo != NULL) {
			atual = atual->proximo;
		}

		atual->proximo = node;
	}

	lista->qtde++;
}

ELista *busca_lista(Lista *lista, char rg[13]) {
	ELista *node = lista->inicio;

	if(node == NULL) {
		printf("\nNao existem pacientes cadastrados!\n");
		return NULL;
	} else {
		while(node != NULL && strcmp(node->dados->rg, rg)) {
			node = node->proximo;
		}
	}

	return node;
}

void remove_lista(Lista *lista, char rg[13]) {
	ELista *atual = lista->inicio;
	ELista *lixo = NULL;

	while(atual != NULL) {
		if(strcmp(atual->dados->rg, rg) == 0) {
			if(lixo == NULL) {
				lista->inicio = atual->proximo;
			} else {
				lixo->proximo = atual->proximo;
			}

			free(atual);
			lista->qtde--;

			printf("\nPaciente removido da lista!\n");

			return;
		}
		lixo = atual;
		atual = atual->proximo;
	}

	printf("\nPaciente nao encontrado!\n");
}

void imprime_lista(Lista *lista) {
	ELista *node = lista->inicio;

	if(node == NULL) {
		printf("\nNenhum paciente cadastrado!\n");
		return;
	}

	while(node != NULL) {
		printf("\nNome: %s", node->dados->nome);
		printf("\nRG: %s", node->dados->rg);
		printf("\nIdade: %d", node->dados->idade);
		printf("\nData: %d/%d/%d", node->dados->data->dia, node->dados->data->mes, node->dados->data->ano);
		printf("\n");

		node = node->proximo;
	}
}
