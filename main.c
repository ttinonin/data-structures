#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "fila.h"

void cadastrar(Lista *lista) {
	int resposta;

	char rg_atualiza[13];
	char rg_remove[13];
	char rg_busca[13];

	char nome[244];
	char rg[12];
	int idade;
	int dia, mes, ano;

	char rg_novo[13];
	char nome_novo[13];
	int idade_novo;
	Data *data_nova;
	int dia_novo, mes_novo, ano_novo;

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
        case 4:
            printf("\n======================");
            printf("\n= ATUALIZAR PACIENTE =");
            printf("\n======================");

            printf("\nRG do paciente a ser atualizado: ");
            scanf("%s", rg_atualiza);

            if(busca_lista(lista, rg_atualiza) == NULL) {
                printf("\nRG nao encontrado\n");
                break;
            }

            printf("\nNome (novo): ");
			scanf("%s", nome_novo);

			printf("\nRG (novo): ");
			scanf("%s", rg_novo);

			printf("\nIdade (novo): ");
			scanf("%d", &idade_novo);

			printf("\nData atual (dia/mes/ano): ");
			scanf("%d/%d/%d", &dia_novo, &mes_novo, &ano_novo);

			data_nova = cria_data(dia_novo, mes_novo, ano_novo);

            atualiza_registro(lista, rg_atualiza, rg_novo, nome_novo, idade_novo, data_nova);

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

void atendimento(Lista *lista, Fila *fila) {
    int resposta;

    char rg_enfilera[13];
    ELista *busca_paciente;
    Registro *removido;

    do {
        printf("\n=======================");
        printf("\n= FILA DE ATENDIMENTO =");
        printf("\n=======================");

        printf("\n1 - Enfileirar paciente");
        printf("\n2 - Desenfileirar paciente");
        printf("\n3 - Mostrar fila");
        printf("\n0 - Voltar");
        printf("\nResposta: ");
        scanf("%d", &resposta);

        switch(resposta) {
        case 1:
            printf("\nRG do paciente a ser enfileirado: ");
            scanf("%s", rg_enfilera);

            busca_paciente = busca_lista(lista, rg_enfilera);

            if(busca_paciente == NULL) {
                break;
            }

            enqueue(fila, busca_paciente->dados);

            break;
        case 2:
            removido = dequeue(fila);

            if(removido != NULL) {
                printf("\n===========================");
                printf("\n= DADOS PACIENTE REMOVIDO =");
                printf("\n===========================");

                printf("\nNome: %s", removido->nome);
                printf("\nRG: %s", removido->rg);
                printf("\nIdade: %d", removido->idade);
                printf("\nData: %d/%d/%d", removido->data->dia, removido->data->mes, removido->data->ano);
            }

            break;
        case 3:
            printf("\n==========================");
            printf("\n= PACIENTES ENFILEIRADOS =");
            printf("\n==========================");
            imprime_fila(fila);
            break;
        default:
            break;
        }
    } while(resposta != 0);
}

int main() {
	Lista *lista = cria_lista();
	Fila *fila = cria_fila();

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
        case 2:
            atendimento(lista, fila);
            break;
		case 5:
			sobre();
		default:
			break;
		}
	} while(resposta != 0);
}
