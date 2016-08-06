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
#include <time.h>
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

/* A função DIGRAPHdestroy() destrói o grafo G, liberando
 * a memória usada */

void DIGRAPHdestroy(Digraph G) {
   Vertex i;
   for (i = 0; i < G->V; i++)
      free(G->adj[i]);
   free(G->adj);
   free(G);
}

/* A função DIGRAPHindeg() calcula o grau de entrada do vértice v.
 * A função supõe que v é positivo e menor que G->V). */

int DIGRAPHindeg(Digraph G, Vertex v){
   int i, indeg = 0;
   for (i = 0; i < G->V; i++)
      indeg += G->adj[i][v];
   return indeg;
}

/* A função DIGRAPHindeg() calcula o grau de saída do vértice v.
 * A função supõe que v é positivo e menor que G->V. */

int DIGRAPHoutdeg(Digraph G, Vertex v){
   int i, outdeg = 0;
   for (i = 0; i < G->V; i++)
      outdeg += G->adj[v][i];
   return outdeg;
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

/* A função randV() devolve um vértice aleatório do 
 * digrafo G. Ela é apenas um invólucro para a função
 * rand() da biblioteca stdlib, que produz um número
 * inteiro (pseudo)aleatório no intervalo fechado 0..RAND_MAX. */

Vertex randV(Digraph G) { 
   double r;
   r = rand() / (RAND_MAX + 1.0);
   return r * G->V;
}

/* DIGRAPHrand1() constrói um digrafo aleatório com vértices 0..V-1 e 
 * exatamente A arcos. A função supõe que A <= V*(V-1). 
 * Se A for próximo de V*(V-1), a função pode consumir
 * muito tempo. (Código inspirado no Programa 17.7 de 
 * Sedgewick.) */

Digraph DIGRAPHrand1(int V, int A) { 
   Vertex v, w;
   Digraph G = DIGRAPHinit(V);
   while (G->A < A) {
      v = randV(G);
      w = randV(G);
      if (v != w) 
         DIGRAPHinsertA(G, v, w);
   }
   return G;
}

/* DIGRAPHrand2() constrói um digrafo aleatório com vértices 0..V-1.
 * Cada um dos V*(V-1) possíveis arcos é criado com probabilidade p,
 * sendo p calculado de modo que o número esperado de arcos seja A. 
 * A função supõe que V >= 2 e A <= V*(V-1). (Código inspirado no 
 * Program 17.8 de Sedgewick.) */

Digraph DIGRAPHrand2(int V, int A) { 
   Vertex v, w;
   double p = (double) A / V / (V-1);
   Digraph G = DIGRAPHinit(V);
   for (v = 0; v < V; v++)
      for (w = 0; w < V; w++)
         if (v != w && rand() < p*(RAND_MAX+1.0))
            DIGRAPHinsertA(G, v, w);
   return G;
}

/* GRAPHrand1() constrói um grafo aleatório com vértices 0..V-1 e 
 * exatamente A arcos. A função supõe que A <= V*(V-1). 
 * Se A for próximo de V*(V-1), a função pode consumir
 * muito tempo. (Código inspirado no Programa 17.7 de 
 * Sedgewick.) */

Digraph GRAPHrand1(int V, int A) { 
   Vertex v, w;
   Digraph G = DIGRAPHinit(V);
   while (G->A < A) {
      v = randV(G);
      w = randV(G);
      if (v != w){ 
         DIGRAPHinsertA(G, v, w);
         DIGRAPHinsertA(G, w, v);
      }
   }
   return G;
}

/* GRAPHrand2() constrói um grafo aleatório com vértices 0..V-1.
 * Cada um dos V*(V-1) possíveis arcos é criado com probabilidade p,
 * sendo p calculado de modo que o número esperado de arcos seja A. 
 * A função supõe que V >= 2 e A <= V*(V-1). (Código inspirado no 
 * Program 17.8 de Sedgewick.) */

Digraph GRAPHrand2(int V, int A) { 
   Vertex v, w;
   double p = (double) A / V / (V-1);
   Digraph G = DIGRAPHinit(V);
   for (v = 0; v < V; v++)
      for (w = 0; w < V; w++)
         if (v != w && rand() < p*(RAND_MAX+1.0)){
            DIGRAPHinsertA(G, v, w);
            DIGRAPHinsertA(G, w, v);
         }
   return G;
}

// int main(int argc, char *argv[]){
//    Digraph g, h;
//    Vertex v;

//    srand (time(NULL));

//    g = DIGRAPHinit(6);

//    DIGRAPHinsertA(g, 0, 1);
//    DIGRAPHinsertA(g, 0, 2);
//    DIGRAPHinsertA(g, 2, 3);
//    DIGRAPHinsertA(g, 5, 4);
//    DIGRAPHinsertA(g, 2, 5);
//    DIGRAPHinsertA(g, 1, 4);
//    DIGRAPHinsertA(g, 1, 4);

//    DIGRAPHremoveA(g, 2, 3);
//    DIGRAPHremoveA(g, 2, 4);

//    DIGRAPHshow(g);

//    printf("\nGraus de entrada:\n");
//    for (v = 0; v < g->V; v++)
//       printf("%d: %d\n", v, DIGRAPHindeg(g,v));

//    printf("\nGraus de saída:\n");
//    for (v = 0; v < g->V; v++)
//       printf("%d: %d\n", v, DIGRAPHoutdeg(g,v));

//    DIGRAPHdestroy(g);

//    printf("\nDigraph Rand 1:\n");
//    h = DIGRAPHrand1(10, 12);
//    DIGRAPHshow(h);
//    DIGRAPHdestroy(h);

//    printf("\nDigraph Rand 2:\n");
//    h = DIGRAPHrand2(10, 12);
//    DIGRAPHshow(h);

//    printf("\nGraph Rand 1:\n");
//    h = GRAPHrand1(10, 12);
//    DIGRAPHshow(h);
//    DIGRAPHdestroy(h);

//    printf("\nGraph Rand 2:\n");
//    h = GRAPHrand2(10, 12);
//    DIGRAPHshow(h);

//    DIGRAPHdestroy(h);
// }









