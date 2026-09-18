#include "matriz.h"

static bool verticeValido(int v) {
    return v >= 0 && v < MAX_VERTICES;
}

void inicializarMatrizAdj(bool matriz[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            matriz[i][j] = false;
        }
    }
}

bool inserirArestaMatriz(bool matriz[MAX_VERTICES][MAX_VERTICES], int origem, int destino) {
    if (!verticeValido(origem) || !verticeValido(destino)) {
        return false;
    }

    matriz[origem][destino] = true;
    return true;
}

bool existeArestaMatriz(bool matriz[MAX_VERTICES][MAX_VERTICES], int origem, int destino) {
    if (!verticeValido(origem) || !verticeValido(destino)) {
        return false;
    }

    return matriz[origem][destino];
}
