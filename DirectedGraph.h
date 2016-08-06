#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include "Graph.h"
using namespace std;

template<class T>
class DirectedGraph: public Graph<T>{
    public:
        using Graph<T>::addEdge;
        void addEdge(const T& data1, const T& data2, int w);
};

template<class T>
void DirectedGraph<T>::addEdge(const T& data1, const T& data2, int w){
    if(!this->findVertex(data1))this->addVertex(data1);
    if(!this->findVertex(data2))this->addVertex(data2);
    GraphNode<T>* n1 = this->findVertex(data1);
    GraphNode<T>* n2 = this->findVertex(data2);
    n1->next = new AdjacentNode<T>(n2, n1->next, 0);
}

#endif /* DIRECTEDGRAPH_H */

