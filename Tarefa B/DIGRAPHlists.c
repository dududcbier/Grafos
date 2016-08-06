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
// Data:       Aug 6, 2016
// 
// Este arquivo faz parte da Grafos
// da disciplina MAC0328.
// 
////////////////////////////////////////////////////////////// */

/* //// Descrição do programa ///////////////////////////////
//
//
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include "DIGRAPHlists.h"

/* A função NEWnode() recebe um vértice w e o endereço next de um
 * nó e devolve o endereço a de um novo nó tal que a->w == w e
 * a->next == next. */

static link NEWnode(Vertex w, link next) {
   link a = malloc(sizeof (struct node));
   a->w = w;
   a->next = next;
   return a;
}

/* A função DIGRAPHinit() constrói um digrafo com vértices 0 1 .. V-1
 * e nenhum arco. */

Digraph DIGRAPHinit(int V) {
   Vertex v;
   Digraph G = malloc(sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = malloc(V * sizeof (link));
   for (v = 0; v < V; v++)
      G->adj[v] = NULL;
   return G;
}

/* A função DIGRAPHinsertA() insere um arco v-w no digrafo G. A função
 *  supõe que v e w são distintos, positivos e menores que G->V. Se o
 *  digrafo já tem um arco v-w, a função não faz nada. */

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w) {
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next)
      if (a->w == w) return;
   G->adj[v] = NEWnode(w, G->adj[v]);
   G->A++;
}

/* A função DIGRAPHremoveA() remove do digrafo G o arco v-w. Se não
 * existe arco v-w, a função não faz nada. */

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w) {
    link p, q;

    q = G->adj[v];
    if (q != NULL && q->w == w){
      G->adj[v] = q->next;
      free(q);
      q = NULL;
      G->A--;
    }

    for (p = G->adj[v]; p!= NULL && q != NULL; p = p->next){
        q = p->next;

        if (q != NULL && q->w == w){
            p->next = q->next;
            free(q);
            q = NULL;
            G->A--;
        }
    }
}


/* A função DIGRAPHshow() imprime, para cada vértice v do digrafo G, em
 * uma linha, todos os vértices adjacentes a v. */

void DIGRAPHshow(Digraph G) {
   Vertex v, w;
   link a;
   for (v = 0; v < G->V; v++) {
      printf("%2d:", v);
      for (a = G->adj[v]; a != NULL; a = a->next)
          printf(" %2d", a->w);
      printf("\n");
   }
}

int main(int argc, char *argv[]){
    Digraph g;


    printf("Digraph Lists\n\n");
    g = DIGRAPHinit(6);

    DIGRAPHinsertA(g, 0, 1);
    DIGRAPHinsertA(g, 0, 2);
    DIGRAPHinsertA(g, 2, 3);
    DIGRAPHinsertA(g, 5, 4);
    DIGRAPHinsertA(g, 2, 5);
    DIGRAPHinsertA(g, 1, 4);
    DIGRAPHinsertA(g, 1, 4);

    DIGRAPHremoveA(g, 5, 4);
    DIGRAPHremoveA(g, 2, 3);
    DIGRAPHremoveA(g, 0, 1);
    DIGRAPHremoveA(g, 0, 6);
    DIGRAPHremoveA(g, 0, 2);
    DIGRAPHremoveA(g, 1, 4);
    DIGRAPHremoveA(g, 2, 5);
    DIGRAPHremoveA(g, 1, 4);

    DIGRAPHshow(g);
}
