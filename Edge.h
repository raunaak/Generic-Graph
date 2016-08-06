#ifndef EDGE_H
#define EDGE_H
#include "GraphNode.h"
using namespace std;

template<class T>
class Edge{
    public:
    GraphNode<T>* node1;
    GraphNode<T>* node2;
    int weight;
    Edge(GraphNode<T>* node1, GraphNode<T>* node2, int weight);
    bool operator<(const Edge<T>& e); 
};

template<class T>
bool Edge<T>::operator <(const Edge<T>& e){
    return this->weight < e.weight;
}

template<class T>
Edge<T>::Edge(GraphNode<T>* node1, GraphNode<T>* node2, int weight){
    this->node1 = node1;
    this->node2 = node2;
    this->weight = weight;
}

#endif /* EDGE_H */

