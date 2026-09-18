#include "grafo.h"
#include <stdlib.h>

static bool verticeValido(int v) {
    return v >= 0 && v < MAX_VERTICES;
}

Grafo *criarGrafo() {
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));
    if (g == NULL) {
        return NULL;
    }

    inicializarListaAdj(g->listaAdj);
    inicializarMatrizAdj(g->matrizAdj);

    return g;
}

bool inserirAresta(Grafo *g, int origem, int destino) {
    if (g == NULL || !verticeValido(origem) || !verticeValido(destino)) {
        return false;
    }

    No *novoNo = criarNo(destino);
    if (novoNo == NULL) {
        return false;
    }
    novoNo->proximo = g->listaAdj[origem];
    g->listaAdj[origem] = novoNo;

    inserirArestaMatriz(g->matrizAdj, origem, destino);

    return true;
}

bool existeAresta(Grafo *g, int origem, int destino) {
    if (g == NULL) {
        return false;
    }

    return existeArestaMatriz(g->matrizAdj, origem, destino);
}

void destruirGrafo(Grafo *g) {
    if (g == NULL) {
        return;
    }

    destruirListaAdj(g->listaAdj);
    free(g);
}
