#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Este arquivo define structs que serão uteis para todos os outros arquivos
// Como a de data e a de Registro
typedef struct{
	int dia;
	int mes;
	int ano;
}Data;

typedef struct Registro {
	char nome[244];
	int idade;
	char rg[13];
	Data *data;
} Registro;
