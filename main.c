#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main(int argc, char** argv){

    tGraph* graph = newGraph();
    
    tNode* node1 = newNode(1);
    tNode* node2 = newNode(2);
    tNode* node3 = newNode(3);

    addNeighbor(node1,node2);
    addNeighbor(node1,node3);

    addNeighbor(node2,node1);
    addNeighbor(node2,node3);

    addNeighbor(node3,node1);
    addNeighbor(node3,node2);




    addNode(graph,node1);
    addNode(graph,node2);
    addNode(graph,node3);

    printGraph(graph);

    freeGraph(graph);

    freeNode(node1);
    freeNode(node2);
    freeNode(node3);
    
    return EXIT_SUCCESS;

}
