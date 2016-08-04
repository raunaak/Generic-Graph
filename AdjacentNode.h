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
    AdjacentNode(GraphNode<T>* g, AdjacentNode<T>* n);
};

template<class T>
AdjacentNode<T>::AdjacentNode(GraphNode<T>* g, AdjacentNode<T>* n){
    node = g; next = n;
}
#endif /* ADJACENTNODE_H */

