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
//
////////////////////////////////////////////////////////////// */

struct point {
    double x;
    double y;
};

typedef struct point Point;

/* A função randP() escolhe um ponto aleatório no quadrado 
 * [0,1) x [0,1) */

Point randP();

/* A função dist2() calcula o quadrado da distância entre os
 * pontos p e q */

double dist2(Point p, Point q);

/* A função GRAPHdistance escolhe V pontos aleatórios e devolve
 * um grafo cujas arestas ligam pontos que estão a uma distância
 * <= D um do outro */

Digraph GRAPHdistance(int V, double D);
