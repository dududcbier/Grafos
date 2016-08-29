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
//  Implementação de funções básicas para manipulação de di-
//  grafos usando lista de adjacência. O programa é capaz de:
//
//  - Inicializar digrafos vazios
//  - Inserir e remover vértices
//  - Destruir digrafos
//  - Calcular graus de entrada/saída
//  - Inicializar digrafos e grafos aleatórios
//
////////////////////////////////////////////////////////////// */

#include "DIGRAPHlists.h"

static boolean cycleOrTopoR(Digraph G, Vertex v);

/* A função NEWnode() recebe um vértice w e o endereço next de um
 * nó e devolve o endereço a de um novo nó tal que a->w == w e
 * a->next == next. */
static link NEWnode(Vertex w, link next) {
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    return a;
}

Digraph DIGRAPHinit(int V) {
    Vertex v;
    Digraph G = malloc(sizeof * G);
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));
    for (v = 0; v < V; v++)
        G->adj[v] = NULL;
    G->bbbb = NULL;
    G->cccc = NULL;
    G->dddd = NULL;
    return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w) {
    link a;
    for (a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->A++;
}

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w) {
    link p, q;
    q = G->adj[v];
    if (q != NULL && q->w == w) {
        G->adj[v] = q->next;
        free(q);
        q = NULL;
        G->A--;
    }
    for (p = G->adj[v]; p != NULL && q != NULL; p = p->next) {
        q = p->next;
        if (q != NULL && q->w == w) {
            p->next = q->next;
            free(q);
            q = NULL;
            G->A--;
        }
    }
}

void DIGRAPHshow(Digraph G) {
    Vertex v;
    link a;
    for (v = 0; v < G->V; v++) {
        printf("%2d:", v);
        for (a = G->adj[v]; a != NULL; a = a->next)
            printf(" %2d", a->w);
        printf("\n");
    }
}

void DIGRAPHdestroy(Digraph G) {
    Vertex v;
    link a, next;
    for (v = 0; v < G->V; v++)
        for (a = G->adj[v]; a != NULL; a = next) {
            next = a->next;
            free(a);
        }
    free(G->adj);
    free(G->bbbb);
    free(G->cccc);
    free(G->dddd);
    free(G);
}

int DIGRAPHindeg(Digraph G, Vertex v) {
    int i, indeg = 0;
    link a;
    for (i = 0; i < v; i++)
        for (a = G->adj[i]; a != NULL; a = a->next)
            if (a->w == v) {
                indeg++;
                break;
            }
    for (i = v + 1; i < G->V; i++)
        for (a = G->adj[i]; a != NULL; a = a->next)
            if (a->w == v) {
                indeg++;
                break;
            }
    return indeg;
}

int DIGRAPHoutdeg(Digraph G, Vertex v) {
    int outdeg = 0;
    link a;
    for (a = G->adj[v]; a != NULL; a = a->next)
        outdeg++;
    return outdeg;
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

/* A função randP() escolhe um ponto aleatório no quadrado
 * [0,1) x [0,1) */

void randP(double p[2]) {
    p[0] = rand() / (RAND_MAX + 1.0);
    p[1] = rand() / (RAND_MAX + 1.0);
}

/* A função dist2() calcula o quadrado da distância entre os
 * pontos p e q */

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
    link a;
    for (i = 0; i < G->V; i++)
        indeg[i] = 0;
    for (i = 0; i < G->V; i++)
        for (a = G->adj[i]; a != NULL; a = a->next) {
            indeg[a->w]++;
            if (indeg[a->w] > max)
                max = indeg[a->w];
        }
    return max;
}

int DIGRAPHtooBig(Digraph G) {
    int *indeg = malloc(G->V * sizeof(int));
    if (G->V > MAX_PRINTABLE_V
            || DIGRAPHmaxIndeg(G, indeg) > MAX_PRINTABLE_SIZE) {
        free(indeg);
        return TRUE;
    }
    free(indeg);
    return FALSE;
}

int DIGRAPHcycleOrTopo(Digraph G) {
    Vertex v, u;
    contapre = contapos = 0;
    if (pre != NULL) {
        free(pre);
        pre = NULL;
        printf("Warning: vetor 'bbbb' já estava alocado!\n");
    }
    if (pos != NULL) {
        free(pos);
        pos = NULL;
        printf("Warning: vetor 'cccc' já estava alocado!\n");
    }
    if (pai != NULL) {
        free(pai);
        pai = NULL;
        printf("Warning: vetor 'dddd' já estava alocado!\n");
    }
    pre = malloc(G->V * sizeof(int));
    pos = malloc(G->V * sizeof(int));
    pai = malloc(G->V * sizeof(Vertex));
    for (v = 0; v < G->V; v++)
        pre[v] = pos[v] = pai[v] = -1;
    for (v = 0; v < G->V; v++)
        if (pre[v] == -1) {
            pai[v] = v;
            u = cycleOrTopoR(G, v);
            if (u != -1) return u;
        }
    return -1;
}

/* A função cycleR() devolve TRUE se encontra um ciclo ao percorrer G a partir do vértice v e devolve FALSE em caso contrário. */
static boolean cycleOrTopoR(Digraph G, Vertex v) {
    link a;
    Vertex u;
    pre[v] = contapre++;
    for (a = G->adj[v]; a != NULL; a = a->next) {
        Vertex w = a->w;
        if (pre[w] == -1) {
            pai[w] = v;
            u = cycleOrTopoR(G, w);
            if (u != -1) return u;
        } else if (pos[w] <= -1) return v;
    }
    pos[v] = contapos++;
    return -1;
}
