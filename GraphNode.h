#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include "AdjacentNode.h"
template<class T>
class AdjacentNode;
template<class T>
class GraphNode{
    public:
    T data;
    AdjacentNode<T>* next;
    GraphNode(const T& d, AdjacentNode<T>* n);
};

template<class T>
GraphNode<T>::GraphNode(const T& d, AdjacentNode<T>* n){
    data = d; next = n;
}
#endif /* GRAPHNODEE_H */

