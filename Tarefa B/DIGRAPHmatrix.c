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
// Data:       Aug 5, 2016
// 
// Este arquivo faz parte da Tarefa B
// da disciplina MAC0328.
// 
////////////////////////////////////////////////////////////// */

/* //// Descrição do programa ///////////////////////////////
//
//
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include "DIGRAPHmatrix.h"

static int **MATRIXint(int r, int c, int val);

/* A função DIGRAPHinit() cria um digrafo com vértices 0, 1..V-1 e
 * sem arcos. */

Digraph DIGRAPHinit(int V) {
   Digraph G = malloc(sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = MATRIXint(V, V, 0);
   return G;
}

/* A função DIGRAPHinsertA() insere um arco v-w no digrafo G. A função
 * supõe que v e w são distintos, positivos e menores que G->V. Se o
 * digrafo já tem um arco v-w, a função não faz nada. */

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w) {
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->A++;
   }
}

/* A função DIGRAPHremoveA() remove do digrafo G o arco v-w. A função
 * supõe que v e w são distintos, positivos e menores que G->V. Se não
 * existe arco v-w, a função não faz nada. */

void DIGRAPHremoveA( Digraph G, Vertex v, Vertex w) {
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0;
      G->A--;
   }
}

/* A função DIGRAPHshow() imprime, para cada vértice v do digrafo G, em
 * uma linha, todos os vértices adjacentes a v. */

void DIGRAPHshow(Digraph G) {
   Vertex v, w;
   for (v = 0; v < G->V; v++) {
      printf("%2d:", v);
      for (w = 0; w < G->V; w++)
         if (G->adj[v][w] == 1)
            printf(" %2d", w);
      printf("\n");
   }
}

/* A função MATRIXint() cria uma matriz com r linhas
 * e c colunas e inicializa seus elementos com o valor val */

static int **MATRIXint(int r, int c, int val) {
   Vertex i, j;
   int **m = malloc(r * sizeof (int *));
   for (i = 0; i < r; i++)
      m[i] = malloc(c * sizeof (int));
   for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
         m[i][j] = val;
   return m;
}

int main(int argc, char *argv[]){
   Digraph g;

   g = DIGRAPHinit(6);

   DIGRAPHinsertA(g, 0, 1);
   DIGRAPHinsertA(g, 0, 2);
   DIGRAPHinsertA(g, 2, 3);
   DIGRAPHinsertA(g, 5, 4);
   DIGRAPHinsertA(g, 2, 5);
   DIGRAPHinsertA(g, 1, 4);
   DIGRAPHinsertA(g, 1, 4);

   DIGRAPHremoveA(g, 2, 3);
   DIGRAPHremoveA(g, 2, 4);

   DIGRAPHshow(g);
}









