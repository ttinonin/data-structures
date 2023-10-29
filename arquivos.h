#include <stdio.h>
#include <stdlib.h>


Registro *le_dado(FILE *file) {
    Registro *dado = (Registro*)malloc(sizeof(Registro));
    char lido[100];

    //printf("%d\n", fread(dado, sizeof(Registro), 1, file));

    printf("%d\n", fread(dado->nome, sizeof(char), 244, file));
    printf("%c\n", dado->nome[50]);

    printf("%d\n", fread(dado->rg, sizeof(char), 13, file));
    printf("%s\n", dado->rg);

    printf("%d\n", fread(dado->idade, sizeof(int), 1, file));

    dado->data = (Data*)malloc(sizeof(Data));
    printf("%d\n", fread(dado->data, sizeof(Data), 1, file));

    return dado;
}
