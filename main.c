#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void cadastrar(Lista *lista) {
	int resposta;

	char rg_remove[13];
	char rg_busca[13];

	char nome[244];
	char rg[12];
	int idade;
	int dia, mes, ano;

	Data* data;
	Registro* registro;

	ELista *busca;

	do {
		printf("\n1 - Cadastrar novo paciente");
		printf("\n2 - Consultar paciente cadastrado");
		printf("\n3 - Mostrar lista completa");
		printf("\n4 - Atualizar dados de paciente");
		printf("\n5 - Remover paciente");
		printf("\n0 - Voltar");
		printf("\nResposta: ");
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
		case 2:
			printf("\nDigite o RG do paciente: ");
			scanf("%s", rg_busca);
			
			busca = busca_lista(lista, rg_busca);

			if(busca != NULL) {
				printf("\n=======================");
				printf("\n= PACIENTE ENCONTRADO =");
				printf("\n=======================");
				printf("\nNome: %s", busca->dados->nome);	
				printf("\nRG: %s", busca->dados->rg);	
				printf("\nIdade: %d", busca->dados->idade);	
				printf("\nData: %d/%d/%d", busca->dados->data->dia, busca->dados->data->mes, busca->dados->data->ano);	
				printf("\n");
			}

			break;
		case 3:
			printf("\n======================");
			printf("\n= LISTA DE PACIENTES =");
			printf("\n======================");
			imprime_lista(lista);
			break;
		case 5:
			printf("\nDigite o RG do paciente: ");
			scanf("%s", rg_remove);

			remove_lista(lista, rg_remove);
			break;
		default:
			break;
		}
	} while(resposta != 0 );
}

void sobre() {
	printf("\n===================");
	printf("\n= DESENVOLVEDORES =");
	printf("\n===================");

	printf("\nNOME: THIAGO MONTEIRO TINONIN");
	printf("\nRA: 22.122.044-5");
	printf("\nCICLO: 4º (QUARTO)");
	printf("\nCURSO: CIENCIA DA COMPUTACAO");
	printf("\nDISCIPLINA: ESTRUTURA DE DADOS");
	printf("\nDATA: 24/10/2023");

	printf("\n");
	printf("\nNOME: ANGELO GABRIEL VASCONCELOS BAPTISTA");
	printf("\nRA: 22.122.081-7");
	printf("\nCICLO: 4º (QUARTO)");
	printf("\nCURSO: CIENCIA DA COMPUTACAO");
	printf("\nDISCIPLINA: ESTRUTURA DE DADOS");
	printf("\nDATA: 24/10/2023\n");
}

void atendimento(Lista *lista) {
	
}

int main() {
	Lista *lista = cria_lista();

	int resposta;

	do {
		printf("\n1 - Cadastrar");
		printf("\n2 - Atendimento");
		printf("\n3 - Pesquisa");
		printf("\n4 - Carregar / Salvar");
		printf("\n5 - Sobre");
		printf("\n0 - Sair");
		printf("\nResposta: ");
		scanf("%d", &resposta);

		switch (resposta)
		{
		case 1:
			cadastrar(lista);
			break;
		case 5:
			sobre();
		default:
			break;
		}
	} while(resposta != 0);
}
