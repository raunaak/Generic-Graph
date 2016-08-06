#ifndef ADJACENTNODE_H
#define ADJACENTNODE_H
#include "GraphNode.h"
template<class T>
class GraphNode;
template<class T>
class AdjacentNode{
    public:
    GraphNode<T>* node;
    AdjacentNode<T>* next;
    int weight;
    AdjacentNode(GraphNode<T>* g, AdjacentNode<T>* n);
    AdjacentNode(GraphNode<T>* g, AdjacentNode<T>* n, int weight);
};

template<class T>
AdjacentNode<T>::AdjacentNode(GraphNode<T>* g, AdjacentNode<T>* n){
    node = g; next = n; 
    weight = 0;
}

template<class T>
AdjacentNode<T>::AdjacentNode(GraphNode<T>* g, AdjacentNode<T>* n, int weight){
    node = g; next = n;
    this->weight = weight;
}
#endif /* ADJACENTNODE_H */

