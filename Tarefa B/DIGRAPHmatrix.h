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
#ifndef DIGRAPHMATRIX_H_
#define DIGRAPHMATRIX_H_

#define Vertex int

struct digraph {
   int V;
   int A;
   int **adj;
};

typedef struct digraph *Digraph;

/* A função DIGRAPHinit() cria um digrafo com vértices 0, 1..V-1 e
 * sem arcos. */

Digraph DIGRAPHinit(int V);


void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);
void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w);
void DIGRAPHshow(Digraph G);
void DIGRAPHdestroy(Digraph G);
int DIGRAPHindeg(Digraph G, Vertex v);
int DIGRAPHoutdeg(Digraph G, Vertex v);
Digraph DIGRAPHrand1(int V, int A);
Digraph DIGRAPHrand2(int V, int A);

#endif /* DIGRAPHMATRIX_H_ */
