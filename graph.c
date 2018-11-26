#include "graph.h"

tNode* newNode(int code){

    tNode* node = (tNode*)malloc(sizeof(tNode));

    node->code = code;
    node->neighborsAmount = 0;
    node->neighbors = NULL; //For the first neighbor, realloc will work like malloc

    return node;

}

void freeNode(tNode* node){

    free(node->neighbors);

    free(node);

}

void addNeighbor(tNode* node,tNode* neighbor){

    node->neighbors = (tNode**)realloc(node->neighbors,(sizeof(tNode*))*(node->neighborsAmount++));
    node->neighbors[node->neighborsAmount - 1] = neighbor;


}

tGraph* newGraph(){

    tGraph* graph = (tGraph*)malloc(sizeof(tGraph));

    graph->nodesAmount = 0;

    graph->nodes = NULL;

    return graph;
}

void freeGraph(tGraph* graph){

    free(graph->nodes);

    free(graph);

}

void addNode(tGraph* graph, tNode* node){

    graph->nodes = (tNode**)realloc(graph->nodes,(sizeof(tNode*))*(graph->nodesAmount++));
    graph->nodes[graph->nodesAmount - 1] = node;


}

void printGraph(tGraph* graph){

    printf("\n\n\n");

    for(int i = 0; i < graph->nodesAmount;i++){

        printf("[%d]", graph->nodes[i]->code);

        for(int j = 0; j < graph->nodes[i]->neighborsAmount; j++){

            printf(" \u27ff  [%d]", graph->nodes[i]->neighbors[j]->code);

        }

        printf("\n");


    }

    printf("\n\n\n");


}