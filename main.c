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

int main(int argc, char** argv){

    tGraph* graph = newGraph();
    
    tNode* node1 = newNode(1);
    tNode* node2 = newNode(2);
    tNode* node3 = newNode(3);

    addNode(graph,node1);
    addNode(graph,node2);
    addNode(graph,node3);

    printf("Graph nodes: %d\n",graph->nodesAmount);

    freeGraph(graph);

    freeNode(node1);
    freeNode(node2);
    freeNode(node3);

}