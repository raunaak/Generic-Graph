#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "GraphNode.h"
#include "AdjacentNode.h"
#include "Edge.h"
using namespace std;

template<class T>
class Graph{
    public:
    vector<GraphNode<T>*> nodeList;
    vector<Edge<T>*> edgeList;
    void addEdge(const T& data1, const T& data2);
    void addEdge(const T& data1, const T& data2, int w);
    void addVertex(const T& d);
    void print();
    GraphNode<T>* findVertex(const T& d);
    vector<GraphNode<T>*>& getList();
    vector<Edge<T>*>& getEdge();
    void sortEdgesByWeight();
};

template<class T>
GraphNode<T>* Graph<T>::findVertex(const T& d){
    /*Find the vertex in vector with given data if found or returns NULL*/
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
void Graph<T>::addEdge(const T& data1, const T& data2, int w){
    /* Add graphnode to vector if there is no element corresponding to data1 and data2
       Find graphnodes in vector for elements corresponding to data1 and data2
       Add adjacentnode to both of the elements of vector
    */
    if(!findVertex(data1))nodeList.push_back(new GraphNode<T>(data1,NULL));
    if(!findVertex(data2))nodeList.push_back(new GraphNode<T>(data2,NULL));
    GraphNode<T>* n1 = findVertex(data1);
    GraphNode<T>* n2 = findVertex(data2);
    n1->next = new AdjacentNode<T>(n2,n1->next,w);
    n2->next = new AdjacentNode<T>(n1, n2->next,w);
    this->edgeList.push_back(new Edge<T>(n1, n2, w));    
}

template<class T>
void Graph<T>::addEdge(const T& data1, const T& data2){
    this->addEdge(data1, data2, 0);
}


template<class T>
vector<GraphNode<T>*>& Graph<T>::getList(){
    return this->nodeList;
}

template<class T>
vector<Edge<T>*>& Graph<T>::getEdge(){
    return this->edgeList;
}

template<class T>
void Graph<T>::sortEdgesByWeight(){
    sort(edgeList.begin(), edgeList.end());
}

#endif /* GRAPH_H */

