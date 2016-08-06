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
#ifndef TAREFA_B_DIGRAPHLISTS_H_
#define TAREFA_B_DIGRAPHLISTS_H_

#define Vertex int

/* A lista de adjacência de um vértice v é composta por nós do tipo
 * node. Cada nó da lista corresponde a um arco e contém um vizinho
 * w de v e o endereço do nó seguinte da lista. Um link é um ponteiro
 * para um node. */

typedef struct node *link;
struct node {
   Vertex w;
   link next;
};

/* A estrutura digraph representa um digrafo. O campo adj é um ponteiro
 *  para o vetor de listas de adjacência, o campo V contém o número de
 *  vértices e o campo A contém o número de arcos do digrafo. */

struct digraph {
   int V;
   int A;
   link *adj;
};

/* Um Digraph é um ponteiro para um digraph. */

typedef struct digraph *Digraph;

Digraph DIGRAPHinit(int V);
void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);
void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w);
void DIGRAPHshow(Digraph G);
void DIGRAPHdestroy(Digraph G);
int DIGRAPHindeg(Digraph G, Vertex v);
int DIGRAPHoutdeg(Digraph G, Vertex v);

#endif /* TAREFA_B_DIGRAPHLISTS_H_ */
