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
// Interface para digrafos usando lista de adjacência.
//
////////////////////////////////////////////////////////////// */
#ifndef TAREFA_B_DIGRAPHLISTS_H_
#define TAREFA_B_DIGRAPHLISTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Vertex int
#define MAX_PRINTABLE_SIZE 30
#define MAX_PRINTABLE_V 500
#define FALSE 0
#define TRUE 1

int verbose;

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

/* A função DIGRAPHinit() constrói um digrafo com vértices 0 1 .. V-1
 * e nenhum arco. */

Digraph DIGRAPHinit(int V);

/* A função DIGRAPHinsertA() insere um arco v-w no digrafo G. A função
 *  supõe que v e w são distintos, positivos e menores que G->V. Se o
 *  digrafo já tem um arco v-w, a função não faz nada. */

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);

/* A função DIGRAPHremoveA() remove do digrafo G o arco v-w. Se não
 * existe arco v-w, a função não faz nada. */

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w);

/* A função DIGRAPHshow() imprime, para cada vértice v do digrafo G, em
 * uma linha, todos os vértices adjacentes a v. */

void DIGRAPHshow(Digraph G);

/* A função DIGRAPHdestroy() destrói o grafo G, liberando
 * a memória usada */

void DIGRAPHdestroy(Digraph G);

/* A função DIGRAPHindeg() calcula o grau de entrada do vértice v.
 * A função supõe que v é positivo e menor que G->V. */

int DIGRAPHindeg(Digraph G, Vertex v);

/* A função DIGRAPHindeg() calcula o grau de saída do vértice v.
 * A função supõe que v é positivo e menor que G->V). */

int DIGRAPHoutdeg(Digraph G, Vertex v);

/* DIGRAPHrand1() constrói um digrafo aleatório com vértices 0..V-1 e
 * exatamente A arcos. A função supõe que A <= V*(V-1).
 * Se A for próximo de V*(V-1), a função pode consumir
 * muito tempo. (Código inspirado no Programa 17.7 de
 * Sedgewick.) */

Digraph DIGRAPHrand1(int V, int A);

/* DIGRAPHrand2() constrói um digrafo aleatório com vértices 0..V-1.
 * Cada um dos V*(V-1) possíveis arcos é criado com probabilidade p,
 * sendo p calculado de modo que o número esperado de arcos seja A.
 * A função supõe que V >= 2 e A <= V*(V-1). (Código inspirado no
 * Program 17.8 de Sedgewick.) */

Digraph DIGRAPHrand2(int V, int A);

/* GRAPHrand1() constrói um grafo aleatório com vértices 0..V-1 e
 * exatamente A arcos. A função supõe que A <= V*(V-1).
 * Se A for próximo de V*(V-1), a função pode consumir
 * muito tempo. (Código inspirado no Programa 17.7 de
 * Sedgewick.) */

Digraph GRAPHrand1(int V, int A);

/* GRAPHrand2() constrói um grafo aleatório com vértices 0..V-1.
 * Cada um dos V*(V-1) possíveis arcos é criado com probabilidade p,
 * sendo p calculado de modo que o número esperado de arcos seja A.
 * A função supõe que V >= 2 e A <= V*(V-1). (Código inspirado no
 * Program 17.8 de Sedgewick.) */

Digraph GRAPHrand2(int V, int A);

/* A função GRAPHrelativeNeighborhood escolhe V pontos aleatórios e devolve
 * um grafo cujas arestas ligam pontos que estão a uma distância
 * <= D um do outro */

Digraph GRAPHrelativeNeighborhood(int V, double D);

/* A função randV() devolve um vértice aleatório do
 * digrafo G. Ela é apenas um invólucro para a função
 * rand() da biblioteca stdlib, que produz um número
 * inteiro (pseudo)aleatório no intervalo fechado 0..RAND_MAX. */

Vertex randV(Digraph G);

/* A função DIGRAPHmaxIndeg calcula o maior grau de entrada do di-
 * grafo G. Os graus de entrada calculados são inseridos no vetor
 * indeg. */

int DIGRAPHmaxIndeg(Digraph G, int indeg[]);

/* A função tooBig retorna verdadeiro se o digrafo G é grande demais
 * para ser impresso. Um digrafo é considerado muito grande para ser
 * impresso se existe um vértice com um número grande demais de ares-
 * tas para caber em uma mesma linha do terminal ou se o número total
 * de vértices for muito grande. */

int DIGRAPHtooBig(Digraph G);

#endif /* TAREFA_B_DIGRAPHLISTS_H_ */
