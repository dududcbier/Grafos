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
// Este arquivo faz parte da Tarefa B
// da disciplina MAC0328.
// 
////////////////////////////////////////////////////////////// */

/* //// Descrição do programa ///////////////////////////////
//
// Este programa recebe os valores v e d da linha de comando,
// sorteia v pontos no quadrado [0,1)×[0,1) e liga os pontos 
// que estiverem à distância <= d um ao outro. O programa e-
// xibe o grafo caso ele caiba na tela e imprime o número de
// arestas construídas.
//
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DIGRAPHlists.h"
#include "grafoDistancia.h"
#include <math.h>

Point randP(){
   Point p;
   p.x = rand() / (RAND_MAX + 1.0);
   p.y = rand() / (RAND_MAX + 1.0);
   return p;
}

double dist2(Point p, Point q){
   double deltaX = p.x - q.x;
   double deltaY = p.y - q.y;

   return deltaX * deltaX + deltaY * deltaY;
}

Digraph GRAPHdistance(int V, double D){

   Digraph G = DIGRAPHinit(V);
   Point *p;
   Vertex i, j;

   p = malloc(V * sizeof(Point));
   D *= D;

   for (i = 0; i < V; i++)
      p[i] = randP();

   for (i = 0; i < V; i++)
      for (j = i + 1; j < V; j++)
         if (dist2(p[i], p[j]) <= D){
            DIGRAPHinsertA(G, i, j);
            DIGRAPHinsertA(G, j, i);
         }

   return G;

}

int main(int argc, char *argv[]){

   int v;
   double d;
   Digraph g;

   if (argc < 3) {
      printf("\nUsage: %s v d\n", argv[0]);
      printf("\tv: number of vertices\n");
      printf("\td: critical distance\n\n");
      return -1;
   }

   v = atoi(argv[1]);
   d = atof(argv[2]);

   srand(time(NULL));

   g = GRAPHdistance(v, d);
   if (v <= 100)
      DIGRAPHshow(g);


   printf("\nNúmero de arestas: %d\n", g->A);
   DIGRAPHdestroy(g);

   return 0;
}
