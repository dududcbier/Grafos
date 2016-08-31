/* DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.
// TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE FORAM FORNECIDAS
// PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE
// SEDGEWICK OU ROBERTS, FORAM DESENVOLVIDAS POR MIM.  DECLARO
// TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
// E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS.
//
// Autor:      Eduardo Bier
// Numero USP: 8536148
// Sigla:      EDUARDOD
// Data:       Aug 29, 2016
//
// Este arquivo faz parte da Tarefa E
// da disciplina MAC0328.
//
////////////////////////////////////////////////////////////// */

/* //// Descrição do programa ///////////////////////////////
//
//  Esse programa le da entrada padrão um digrafo e decide se
//  ele contém ou não ciclos. Se um ciclo for encontrado, o
//  programa imprime o ciclo detectado. Caso contrário, pro-
//  va que não existe nenhum ciclo, imprimindo uma numeração
//  topológica para o digrafo.
//
////////////////////////////////////////////////////////////// */

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
        printf("Não existe ciclo:\n - Numeração topológica:\n");
        for (v = 0; v < G->V; v++)
            printf("    %d: %d\n", v, G->V - 1 - pos[v]);
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
