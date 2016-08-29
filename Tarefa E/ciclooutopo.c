#include <stdio.h>
#include "DIGRAPHmatrix.h"

int main() {
    Digraph G;
    int V, A, i;
    Vertex v, w;
    Vertex *ciclo;
    scanf("%d", &V);
    G = DIGRAPHinit(V);
    scanf("%d", &A);
    for (i = 0; i < A; i++) {
        scanf("%d %d", &v, &w);
        DIGRAPHinsertA(G, v, w);
    }
    DIGRAPHshow(G);
    v = DIGRAPHcycleOrTopo(G);
    if (v == -1) {
        printf("Não existe ciclo.\nNumeração topológica:\n");
        for (v = 0; v < G->V; v++)
            printf("%d: %d\n", v, G->V - 1 - pos[v]);
    } else {
        ciclo = malloc((V + 1) * sizeof(Vertex));
        ciclo[0] = -1;
        i = 0;
        printf("Ciclo encontrado: ");
        for (w = 0; w < G->V && ciclo[0] == -1; w++)
            if (G->adj[v][w] && pre[w] != -1 && pos[w] == -1)
                ciclo[i++] = w;
        ciclo[i++] = v;
        for (w = pai[v]; w != ciclo[0]; w = pai[w])
            ciclo[i++] = w;
        ciclo[i] = w;
        for (; i > 0; i--) {
            printf("%d -> ", ciclo[i]);
        }
        printf("%d\n", ciclo[0]);
        free(ciclo);
    }
    DIGRAPHdestroy(G);
    return 0;
}
