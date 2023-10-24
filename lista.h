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
	registro->nome = nome;
	registro->idade = idade;
	registro->rg = rg;

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
	}
}

void imprime_lista(Lista *lista) {
	ELista *node = lista->inicio;

	while(node != NULL) {
		printf("\nNome: %s", node->dados->nome);
		printf("\nRG: %s", node->dados->rg);
		printf("\nIdade: %d", node->dados->idade);
		printf("\n");

		node = node->proximo;
	}
}