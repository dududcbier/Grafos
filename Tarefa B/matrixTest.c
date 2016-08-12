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
// Data:       Aug 8, 2016
// 
// Este arquivo faz parte da Tarefa B
// da disciplina MAC0328.
// l
////////////////////////////////////////////////////////////// */

/* //// Descrição do programa ///////////////////////////////
//
//  Este programa usa as principais funções implementadas em
//  DIGRAPHmatrix.c para testá-las.
//
////////////////////////////////////////////////////////////// */

#include "DIGRAPHmatrix.h"

int main(int argc, char *argv[]) {
   Digraph g, h;
   Vertex v;

   srand (time(NULL));

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

   printf("\nGraus de entrada:\n");
   for (v = 0; v < g->V; v++)
      printf("%d: %d\n", v, DIGRAPHindeg(g,v));

   printf("\nGraus de saída:\n");
   for (v = 0; v < g->V; v++)
      printf("%d: %d\n", v, DIGRAPHoutdeg(g,v));

   DIGRAPHdestroy(g);

   printf("\nDigraph Rand 1:\n");
   h = DIGRAPHrand1(10, 12);
   DIGRAPHshow(h);
   printf("%d arcos\n", g->A);
   DIGRAPHdestroy(h);

   printf("\nDigraph Rand 2:\n");
   h = DIGRAPHrand2(10, 12);
   DIGRAPHshow(h);
   printf("%d arcos\n", g->A);
   DIGRAPHdestroy(h);

   printf("\nGraph Rand 1:\n");
   h = GRAPHrand1(10, 6);
   DIGRAPHshow(h);
   printf("%d arestas\n", g->A / 2);
   DIGRAPHdestroy(h);

   printf("\nGraph Rand 2:\n");
   h = GRAPHrand2(10, 6);
   DIGRAPHshow(h);
   printf("%d arestas\n", g->A / 2);
   DIGRAPHdestroy(h);
}
