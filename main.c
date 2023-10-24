#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void cadastrar(Lista *lista) {
	int resposta;

	char nome[244];
	char rg[12];
	int idade;
	int dia, mes, ano;

	Data* data;
	Registro* registro;

	do {
		printf("1 - Cadastrar novo paciente");
		printf("2 - Consultar paciente cadastrado");
		printf("3 - Mostrar lista completa");
		printf("4 - Atualizar dados de paciente");
		printf("5 - Remover paciente");
		printf("0 - Voltar");

		scanf("%d", &resposta);

		switch (resposta)
		{
		case 1:
			printf("\n===============================");
			printf("\n= INSIRA OS DADOS DO PACIENTE =");
			printf("\n===============================");

			printf("\nNome: ");
			scanf("%s", nome);

			printf("\nRG: ");
			scanf("%s", rg);

			printf("\nIdade: ");
			scanf("%d", &idade);

			printf("\nData atual (dia/mes/ano): ");
			scanf("%d/%d/%d", &dia, &mes, &ano);

			data = cria_data(dia, mes, ano);
			registro = cria_registro(data, nome, rg, idade);

			insere_lista(lista, registro);

			break;
		case 3:
			printf("\n======================");
			printf("\n= LISTA DE PACIENTES =");
			printf("\n======================");
			imprime_lista(lista);
			break;
		default:
			break;
		}
	} while(resposta != 0 );
}

void atendimento(Lista *lista) {
	
}

int main() {
	Lista *lista = cria_lista();

	int resposta;

	do {
		printf("1 - Cadastrar");
		printf("2 - Atendimento");
		printf("3 - Pesquisa");
		printf("4 - Carregar / Salvar");
		printf("5 - Sobre");
		printf("0 - Sair");
		scanf("%d", &resposta);

		switch (resposta)
		{
		case 1:
			cadastrar(lista);
			break;
		default:
			break;
		}
	} while(resposta != 0);
}
