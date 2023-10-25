#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
	int dia;
	int mes;
	int ano;
} Data; 

typedef struct Registro {
	char nome[244];
	int idade;
	char rg[13];
	Data *data;
} Registro;
