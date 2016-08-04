#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H
#include "Graph.h"
#include <set>
using namespace std;

template<typename T>
void depthFirstSearch(Graph<T>* g, GraphNode<T>* node, set<GraphNode<T>*>* gset){
    if(node){
        if(gset->find(node)==gset->end()){
            cout<<node->data<<" ";
            gset->insert(node);
            AdjacentNode<T>* adjNode = node->next;
            while(adjNode){depthFirstSearch(g, adjNode->node, gset); adjNode = adjNode->next;}
        }
    }
}
template<typename T>
void depthFirstSearch(Graph<T>* g){
    vector<GraphNode<T>*> list = g->nodeList;
    set<GraphNode<T>*> gset;
    for(int i=0; i<list.size(); i++)
    depthFirstSearch(g, list[i], &gset);
}
#endif /* DEPTHFIRSTSEARCH_H */

