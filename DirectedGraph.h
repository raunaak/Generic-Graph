#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include "Graph.h"
using namespace std;
template<class T>
class DirectedGraph: public Graph<T>{
    public:
        using Graph<T>::addEdge;
        void addEdge(const T& data1, const T& data2);
};
template<class T>
void DirectedGraph<T>::addEdge(const T& data1, const T& data2){
    if(!findVertex(data1))addVertex(data1);
    if(!findVertex(data2))addVertex(data2);
    GraphNode<T>* n1 = findVertex(data1);
    GraphNode<T>* n2 = findVertex(data2);
    n1->next = new AdjacentNode(n2, n1->next);
}
#endif /* DIRECTEDGRAPH_H */

