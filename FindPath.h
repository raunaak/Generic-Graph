#ifndef FINDPATH_H
#define FINDPATH_H
#include "Graph.h"
#include <set>

template<typename T>
bool findPathDFS(Graph<T>* g, GraphNode<T>* u, GraphNode<T>* v, set<GraphNode<T>*>* gset){
    if(u==v)return true;
    AdjacentNode<T>* adjNode = u->next;
    while(adjNode){
        if(gset->find(adjNode->node)==gset->end()){
            gset->insert(adjNode->node);
            if(findPathDFS(g, adjNode->node, v, gset)){cout<<" "<<adjNode->node->data; return true;}
        }
    }
    return false;
}

template<typename T>
void findPathDFS(Graph<T>* g, const T& data1, const T& data2){
    GraphNode<T>* u = g->findVertex(data1);
    GraphNode<T>* v = g->findVertex(data2);
    if(!u||!v)return;        
    set<GraphNode<T>*> gset;
    gset.insert(u);
    if(findPathDFS(g, u, v, &gset))cout<<" "<<u->data<<endl;
}
#endif /* FINDPATH_H */

