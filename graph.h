#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {

    int code;

    int neighborsAmount;

    struct tNode** neighbors;

} tNode;

typedef struct tGraph {

    int nodesAmount;

    tNode** nodes;

} tGraph;


tNode* newNode(int code);

void freeNode(tNode* node);

void addNeighbor(tNode* node,tNode* neighbor);

tGraph* newGraph();

void freeGraph(tGraph* graph);

void addNode(tGraph* graph, tNode* node);

void printGraph(tGraph* graph);