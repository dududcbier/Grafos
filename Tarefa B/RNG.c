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
// arestas construídas. Caso o modo verbose seja habilitado,
// os pontos sorteados e o grafo serão impressos (independen-
// te do tamanho).
//
////////////////////////////////////////////////////////////// */

#include "DIGRAPHlists.h"
#include <string.h>

int main(int argc, char *argv[]) {

   int v;
   double d;
   Digraph g;

   if (argc < 3) {
      printf("\nUsage: %s v d [-v]\n", argv[0]);
      printf("\tv: number of vertices\n");
      printf("\td: critical distance\n");
      printf("\t-v: verbose\n\n");
      return -1;
   }

   if (argc == 4 && strcmp(argv[3],"-v") == 0) {
      verbose = TRUE;
   }

   v = atoi(argv[1]);

   d = atof(argv[2]);

   srand(time(NULL));

   g = GRAPHrelativeNeighborhood(v, d);
   if (verbose || ! DIGRAPHtooBig(g)) {
      DIGRAPHshow(g);
   }

   printf("\nNúmero de arestas: %d\n", g->A / 2);
   DIGRAPHdestroy(g);

   return 0;
}
