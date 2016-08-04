#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include "GraphNode.h"
#include "AdjacentNode.h"
using namespace std;
template<class T>
class Graph{
    vector<GraphNode<T>*> nodeList;
    public:
    void addEdge(const T& data1, const T& data2);
    void addVertex(const T& d);
    void print();
    GraphNode<T>* findVertex(const T& d);
};

template<class T>
GraphNode<T>* Graph<T>::findVertex(const T& d){
    /* Find the vertex in vector with given data if found or returns NULL*/
    for(int i=0; i<nodeList.size(); i++){
        if(nodeList[i]->data==d)return nodeList[i];
    }
    return NULL;
}

template<class T>
void Graph<T>::addVertex(const T& d){
    /* Add graphnode at the end of vector */
    nodeList.push_back(new GraphNode<T>(d, NULL));    
}

template<class T>
void Graph<T>::print(){
    /*Print line by line all the vertices in vector along with all the neighbours */
    for(int i=0; i<nodeList.size();i++){
        cout<<nodeList[i]->data<<" ";
        AdjacentNode<T>* n = nodeList[i]->next;
        while(n){cout<<n->node->data<<" "; n = n->next;}
        cout<<endl;        
    }
}

template<class T>
void Graph<T>::addEdge(const T& data1, const T& data2){
    /* Add graphnode to vector if there is no element corresponding to data1 and data2
       Find graphnodes in vector for elements corresponding to data1 and data2
       Add adjacentnode to both of the elements of vector
    */
    if(!findVertex(data1))nodeList.push_back(new GraphNode<T>(data1,NULL));
    if(!findVertex(data2))nodeList.push_back(new GraphNode<T>(data2,NULL));
    GraphNode<T>* n1 = findVertex(data1);
    GraphNode<T>* n2 = findVertex(data2);
    n1->next = new AdjacentNode<T>(n2,n1->next);
    n2->next = new AdjacentNode<T>(n1, n2->next);
    
}

#endif /* GRAPH_H */
