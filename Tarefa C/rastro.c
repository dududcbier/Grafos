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
// Data:       Aug 16, 2016
//
// Este arquivo faz parte da Grafos
// da disciplina MAC0328.
//
////////////////////////////////////////////////////////////// */

/* //// Descrição do programa ///////////////////////////////
//
// Este programa le da entrada padrão parametros V e A e gera
// um digrafo aleatório G com V vértices e A arcos. O programa
// mostra o digrafo gerado e então mostra o rastro de uma bus-
// ca em profundidade.
//
////////////////////////////////////////////////////////////// */

#include "DIGRAPHlists.h"

#define INDENT_SIZE 2

int tabDepth = 0;

void addIdent() {
    int i;
    for (i = 0; i < tabDepth * INDENT_SIZE; i++)
        printf(" ");
}

static void dfsRTrace(Digraph G, Vertex v) {
    link a;
    pre[v] = conta++;
    printf("dfsR(G, %d)", v);
    tabDepth++;
    for (a = G->adj[v]; a != NULL; a = a->next) {
        printf("\n");
        addIdent();
        printf("%d-%d ", v, a->w);
        if (pre[a->w] == -1)
            dfsRTrace(G, a->w);
    }
    tabDepth--;
}

void DIGRAPHdfsTrace(Digraph G) {
    Vertex v;
    conta = 0;
    for (v = 0; v < G->V; v++)
        pre[v] = -1;
    for (v = 0; v < G->V; v++)
        if (pre[v] == -1) {
            dfsRTrace(G, v);
            printf("\n\n");
        }
}

int main(int argc, char *argv[]) {
    int v;
    int a;
    Digraph g;
    if (argc < 3) {
        printf("\nUsage: %s v d [-v]\n", argv[0]);
        printf("\tv: number of vertices\n");
        printf("\ta: number of arcs\n");
        return -1;
    }
    v = atoi(argv[1]);
    a = atoi(argv[2]);
    g = DIGRAPHinit(6);
    srand(time(NULL));
    g = DIGRAPHrand1(v, a);
    if (!DIGRAPHtooBig(g)) {
        DIGRAPHshow(g);
        printf("\n");
    }
    DIGRAPHdfsTrace(g);
    DIGRAPHdestroy(g);
    return 0;
}
