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
//  Implementação de funções básicas para manipulação de di-
//  grafos usando matriz de adjacência. O programa é capaz de:
//
//  - Inicializar digrafos vazios
//  - Inserir e remover vértices
//  - Destruir digrafos
//  - Calcular graus de entrada/saída
//  - Inicializar digrafos e grafos aleatórios
//
////////////////////////////////////////////////////////////// */

#include "DIGRAPHmatrix.h"

static int **MATRIXint(int r, int c, int val);

Digraph DIGRAPHinit(int V) {
    Digraph G = malloc(sizeof * G);
    G->V = V;
    G->A = 0;
    G->adj = MATRIXint(V, V, 0);
    return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w) {
    if (G->adj[v][w] == 0) {
        G->adj[v][w] = 1;
        G->A++;
    }
}

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w) {
    if (G->adj[v][w] == 1) {
        G->adj[v][w] = 0;
        G->A--;
    }
}

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

void DIGRAPHdestroy(Digraph G) {
    Vertex i;
    for (i = 0; i < G->V; i++)
        free(G->adj[i]);
    free(G->adj);
    free(G);
}

int DIGRAPHindeg(Digraph G, Vertex v) {
    int i, indeg = 0;
    for (i = 0; i < G->V; i++)
        indeg += G->adj[i][v];
    return indeg;
}

int DIGRAPHoutdeg(Digraph G, Vertex v) {
    int i, outdeg = 0;
    for (i = 0; i < G->V; i++)
        outdeg += G->adj[v][i];
    return outdeg;
}

/* A função MATRIXint() cria uma matriz com r linhas
 * e c colunas e inicializa seus elementos com o valor val */

static int **MATRIXint(int r, int c, int val) {
    Vertex i, j;
    int **m = malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
        m[i] = malloc(c * sizeof(int));
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            m[i][j] = val;
    return m;
}

Vertex randV(Digraph G) {
    double r;
    r = rand() / (RAND_MAX + 1.0);
    return r * G->V;
}

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

Digraph DIGRAPHrand2(int V, int A) {
    Vertex v, w;
    double p = (double) A / V / (V - 1);
    Digraph G = DIGRAPHinit(V);
    for (v = 0; v < V; v++)
        for (w = 0; w < V; w++)
            if (v != w && rand() < p * (RAND_MAX + 1.0))
                DIGRAPHinsertA(G, v, w);
    return G;
}

Digraph GRAPHrand1(int V, int E) {
    Vertex v, w;
    Digraph G = DIGRAPHinit(V);
    while (G->A < 2 * E) {
        v = randV(G);
        w = randV(G);
        if (v != w) {
            DIGRAPHinsertA(G, v, w);
            DIGRAPHinsertA(G, w, v);
        }
    }
    return G;
}

Digraph GRAPHrand2(int V, int E) {
    Vertex v, w;
    double p = (double) 2 * E / V / (V - 1);
    Digraph G = DIGRAPHinit(V);
    for (v = 0; v < V; v++)
        for (w = 0; w < V; w++)
            if (v != w && rand() < p * (RAND_MAX + 1.0)) {
                DIGRAPHinsertA(G, v, w);
                DIGRAPHinsertA(G, w, v);
            }
    return G;
}

void randP(double p[2]) {
    p[0] = rand() / (RAND_MAX + 1.0);
    p[1] = rand() / (RAND_MAX + 1.0);
}

double dist2(double p[2], double q[2]) {
    double deltaX = p[0] - q[0];
    double deltaY = p[1] - q[1];

    return deltaX * deltaX + deltaY * deltaY;
}

Digraph GRAPHrelativeNeighborhood(int V, double D) {

    Digraph G = DIGRAPHinit(V);
    double **p = malloc(V * sizeof(double *));
    Vertex i, j;

    for (i = 0; i < V; i++)
        p[i] = malloc(2 * sizeof(double));

    for (i = 0; i < V; i++)
        randP(p[i]);

    if (verbose)
        for (i = 0; i < V; i++) {
            for (j = 0; j < 2; j++)
                printf("%f ", p[i][j]);
            printf("\n");
        }

    D *= D;
    for (i = 0; i < V; i++)
        for (j = i + 1; j < V; j++)
            if (dist2(p[i], p[j]) <= D) {
                DIGRAPHinsertA(G, i, j);
                DIGRAPHinsertA(G, j, i);
            }

    for (i = 0; i < 2; i++)
        free(p[i]);

    return G;
}

int DIGRAPHmaxIndeg(Digraph G, int *indeg) {
    int i, max = -1;

    for (i = 0; i < G->V; i++) {
        indeg[i] = DIGRAPHindeg(G, i);
        if (indeg[i] > max)
            max = indeg[i];
    }

    return max;
}

int DIGRAPHtooBig(Digraph G) {
    int *indeg = malloc(G->V * sizeof(int));
    if (G->V > MAX_PRINTABLE_V
            || DIGRAPHmaxIndeg(G, indeg) > MAX_PRINTABLE_SIZE) {
        free(indeg);
        return 1;
    }
    free(indeg);
    return 0;
}
