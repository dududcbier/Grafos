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
//  Interface para digrafos usando matriz de adjacência.
//
////////////////////////////////////////////////////////////// */
#ifndef DIGRAPHMATRIX_H_
#define DIGRAPHMATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Vertex int
#define MAX_PRINTABLE_SIZE 30
#define MAX_PRINTABLE_V 500
#define FALSE 0
#define TRUE 1
#define boolean int
#define pre G->bbbb
#define pos G->cccc
#define pai G->dddd

int verbose;
int contapre, contapos;

struct digraph {
    int     V;
    int     A;
    int   **adj;
    int     aaaa;
    int    *bbbb;
    int    *cccc;
    Vertex *dddd;
};

typedef struct digraph *Digraph;

/* A função DIGRAPHinit() cria um digrafo com vértices 0, 1..V-1 e
 * sem arcos. */
Digraph DIGRAPHinit(int V);

/* A função DIGRAPHinsertA() insere um arco v-w no digrafo G. A função
 * supõe que v e w são distintos, positivos e menores que G->V. Se o
 * digrafo já tem um arco v-w, a função não faz nada. */
void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);

/* A função DIGRAPHremoveA() remove do digrafo G o arco v-w. A função
 * supõe que v e w são distintos, positivos e menores que G->V. Se não
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

/* A função DIGRAPHoutdeg() calcula o grau de saída do vértice v.
 * A função supõe que v é positivo e menor que G->V. */
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
 * exatamente E arestas. A função supõe que 2 * E <= V*(V-1).
 * Se 2 * E for próximo de V*(V-1), a função pode consumir
 * muito tempo. (Código inspirado no Programa 17.7 de
 * Sedgewick.) */
Digraph GRAPHrand1(int V, int E);

/* GRAPHrand2() constrói um grafo aleatório com vértices 0..V-1.
 * Cada um dos V*(V-1) possíveis arcos é criado com probabilidade p,
 * sendo p calculado de modo que o número esperado de arcos seja 2 * E.
 * A função supõe que V >= 2 e 2 * E <= V*(V-1). (Código inspirado no
 * Program 17.8 de Sedgewick.) */
Digraph GRAPHrand2(int V, int E);

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

/* Esta função decide se o digrafo G tem um ciclo. A função retorna
 * um vértice pertencente a um ciclo caso ele exista. Se nenhum ciclo
 * existir, a função retorna -1 e, nesse caso, o vetor pos[] representa
 * uma ordenação topológica inversa. */
int DIGRAPHcycleOrTopo(Digraph G);

#endif /* DIGRAPHMATRIX_H_ */
