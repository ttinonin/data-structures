#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

typedef struct EFila {
    Registro *dados;
    EFila *proximo;
} EFila;

typedef struct Fila {
    EFila *head;
    EFila *tail;
    int qtde;
} Fila;