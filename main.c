#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "fila.h"
#include "arquivos.h"
#include "arvore.h"

void cadastrar(Lista *lista, ABB *apa, ABB *apm, ABB *apd, ABB *api) {
	int resposta;
	//EABB's e Registro utilizados na remoção dos elementos das arvores
	Registro *d;
    EABB *elementoAno;
    EABB *elementoMes;
    EABB *elementoDia;
    EABB *elementoIdade;

	char rg_atualiza[13];
	char rg_remove[13];
	char rg_busca[13];

	char nome[244];
	char rg[13];
	int idade;
	int dia, mes, ano;

	char rg_novo[13];
	char nome_novo[244];
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
			scanf(" %243[^\n]", nome);

			printf("\nRG: ");
			scanf("%s", rg);

			printf("\nIdade: ");
			scanf("%d", &idade);

			printf("\nData atual (dia/mes/ano): ");
			scanf("%d/%d/%d", &dia, &mes, &ano);

            if(busca_lista(lista, rg) != NULL) {
                printf("\nPACIENTE COM RG JA CADASTRADO!\n");
                break;
            }

			data = cria_data(dia, mes, ano);
			registro = cria_registro(data, nome, rg, idade);

			insere_lista(lista, registro);

            //insercao dos pacientes nas arvores
			inserirPorAnoABB(apa, registro);
			inserirPorMesABB(apm, registro);
			inserirPorDiaABB(apd, registro);
			inserirPorIdadeABB(api, registro);

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
			} else {
                printf("\nNao existem pacientes cadastrados!\n");
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
			scanf(" %243[^\n]", nome_novo);

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

            //a funcao remove_lista retorna um registro que é utilizado na remoção
            //dos pacientes nas arvores
            d = remove_lista(lista, rg_remove);
            if(d != NULL){

                elementoAno = buscarValorPorAno(apa, d);
                elementoMes = buscarValorPorMes(apm, d);
                elementoDia = buscarValorPorDia(apd, d);
                elementoIdade = buscarValorPorIdade(api, d);
                removerPorAno(apa, elementoAno);
                removerPorMes(apm, elementoMes);
                removerPorDia(apd, elementoDia);
                removerPorIdade(api, elementoIdade);

            }
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

void carregar(ABB *apa, ABB *apm, ABB *apd, ABB *api, Lista *lista) {
    FILE *arq;
    char nome[50];
    char caminho_bin[55];

    strcpy(caminho_bin, "bin/");

    printf("\nNome do arquivo a ser carregado: ");
    scanf("%s", nome);

    strcat(caminho_bin, nome);
    strcat(caminho_bin, ".bin");

    arq = fopen(caminho_bin, "rb");

    if(arq == NULL) {
        printf("\nArquivo nao encontrado!\n");
        return;
    }

    ELista *node;
    Registro *reg;
    Data *data;

    while(!feof(arq)) {
        char nome_read[244];
        char rg_read[13];
        int idade_read;
        int dia_read, mes_read, ano_read;

        fread(&nome_read, sizeof(char), 244, arq);
        fread(&rg_read, sizeof(char), 13, arq);
        fread(&idade_read, sizeof(int), 1, arq);
        fread(&dia_read, sizeof(int), 1, arq);
        fread(&mes_read, sizeof(int), 1, arq);
        fread(&ano_read, sizeof(int), 1, arq);

        data = cria_data(dia_read, mes_read, ano_read);

        reg = cria_registro(data, nome_read, rg_read, idade_read);

        if(busca_lista(lista, rg_read) != NULL) {
            break;
        }

        insere_lista(lista, reg);

        //insercao dos registros que estavam gravados nos arquivos nas arvores
        inserirPorAnoABB(apa, reg);
        inserirPorMesABB(apm, reg);
        inserirPorDiaABB(apd, reg);
        inserirPorIdadeABB(api, reg);
    }

    fclose(arq);

}

void salvar(Lista *lista) {
    FILE *file_bin, *file_output;
    char arquivo[50];
    char caminho_bin[55];
    char caminho_txt[60];

    strcpy(caminho_bin, "bin/");
    strcpy(caminho_txt, "arquivos/");

    printf("\nQual nome voce deseja salvar para o arquivo? (limite de 50 caracteres): ");
    scanf("%s", arquivo);

    strcat(caminho_bin, arquivo);
    strcat(caminho_bin, ".bin");

    strcat(caminho_txt, arquivo);
    strcat(caminho_txt, ".txt");

    file_bin = fopen(caminho_bin, "wb");

    if(file_bin == NULL) {
        printf("\nERRO AO ABRIR O ARQUIVO!\n");
        return;
    }

    ELista *node = lista->inicio;

    while(node != NULL) {
        fwrite(&(node->dados->nome), sizeof(char), 244, file_bin);
        fwrite(&(node->dados->rg), sizeof(char), 13, file_bin);
        fwrite(&(node->dados->idade), sizeof(int), 1, file_bin);
        fwrite(&(node->dados->data->dia), sizeof(int), 1, file_bin);
        fwrite(&(node->dados->data->mes), sizeof(int), 1, file_bin);
        fwrite(&(node->dados->data->ano), sizeof(int), 1, file_bin);

        node = node->proximo;
    }

    fclose(file_bin);

    file_output = fopen(caminho_txt, "w");

    fprintf(file_output, "\n=========================");
    fprintf(file_output, "\n= PACIENTES CADASTRADOS =");
    fprintf(file_output, "\n=========================");
    fprintf(file_output, "\n");

    ELista *no = lista->inicio;
    while(no != NULL) {
        fprintf(file_output, "\nNome: %s", no->dados->nome);
        fprintf(file_output, "\nRG: %s", no->dados->rg);
        fprintf(file_output, "\nIdade: %d", no->dados->idade);
        fprintf(file_output, "\nData: %d/%d/%d", no->dados->data->dia, no->dados->data->mes, no->dados->data->ano);
        fprintf(file_output, "\n");

        no = no->proximo;
    }

    fclose(file_output);
}

int main() {
	Lista *lista = cria_lista();
	Fila *fila = cria_fila();
	//declaração de uma arvore para cada ordem especifica
    ABB *arvorePorAno = criaABB();
    ABB *arvorePorMes = criaABB();
    ABB *arvorePorDia = criaABB();
    ABB *arvorePorIdade = criaABB();

	int resposta, resposta_arquivo, resposta2;
	char confirmacao;

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
			cadastrar(lista, arvorePorAno, arvorePorMes, arvorePorDia, arvorePorIdade);

			break;
        case 2:
            atendimento(lista, fila);
            break;
        case 3:
                printf("\n===========================");
                printf("\n= PESQUISA =");
                printf("\n===========================");

                printf("\n1-Mostrar registros ordenados por ano de registro\n");
                printf("\n2-Mostrar registros ordenados por mês de registro\n");
                printf("\n3-Mostrar registros ordenados por dia de registro\n");
                printf("\n4-Mostrar registros ordenados por idade do paciente\n");
                scanf("%d", &resposta2);
                printf("\n");

                switch(resposta2){
                    //exibição das arvores com suas respectivas ordens
                    case 1:
                        printf("Registros ordenados por ano:\n\n");
                        in_ordem(arvorePorAno->raiz);
                        break;
                    case 2:
                        printf("Registros ordenados por mes:\n\n");
                        in_ordem(arvorePorMes->raiz);
                        break;
                    case 3:
                        printf("Registros ordenados por dia:\n\n");
                        in_ordem(arvorePorDia->raiz);

                        break;
                    case 4:
                        printf("Registros ordenados por idade:\n\n");
                        in_ordem(arvorePorIdade->raiz);
                        break;
                    default:
                        printf("Opção indisponível");
                        break;
                }

            break;
        case 4:
            printf("\n===========================");
            printf("\n= GERENCIADOR DE ARQUIVOS =");
            printf("\n===========================");

            printf("\nDeseja salvar ou carregar um arquivo? [1/2] (Respectivamente): ");
            scanf("%d", &resposta_arquivo);

            if(resposta_arquivo == 1) {
                salvar(lista);
            } else {
                printf("\nATENCAO: Ao carregar um arquivo de dados");
                printf("\nATENCAO: Todos os dados nao salvos serao perdidos");
                printf("\nATENCAO: Deseja continuar? [s/n]: ");
                getchar();
                scanf("%c", &confirmacao);

                if(confirmacao == 'n') {
                    printf("\nOperacao cancelada!\n");
                    break;
                }

                carregar(arvorePorAno, arvorePorMes, arvorePorDia, arvorePorIdade, lista);
            }

            break;
		case 5:
			sobre();
			break;
		default:
			break;
		}
	} while(resposta != 0);

}
