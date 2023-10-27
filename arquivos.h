#include <stdio.h>
#include <stdlib.h>

Registro *le_dado(FILE *file) {
    Registro *dado = (Registro*)malloc(sizeof(Registro));
    char lido[100];

    fread(dado->nome, sizeof(char), 244, file);

    fread(dado->rg, sizeof(char), 13, file);

    fread(dado->idade, sizeof(int), 1, file);

    dado->data = (Data*)malloc(sizeof(Data));
    fread(dado->data, sizeof(Data), 1, file);

    return dado;
}
