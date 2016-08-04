#ifndef CYCLECHECK_H
#define CYCLECHECK_H
#include "Graph.h"
using namespace std;

template<typename T>
bool cycleCheckDFS(Graph<T>* g, set<GraphNode<T>*>* gset, GraphNode<T>* curr, GraphNode<T>* parent){
    AdjacentNode<T>* adjNode = curr->next;
    while(adjNode){
        if(gset->find(adjNode->node)==gset->end()){
        gset->insert(adjNode->node);
        if(cycleCheckDFS(g, gset, adjNode->node, curr))return true;
        }else if(adjNode->node!=parent)return true;
        adjNode = adjNode->next;
    }
    return false;
}

template<typename T>
bool cycleCheckDFS(Graph<T>* g){
    /* Algorithm
     * Go to all the connected components of graph
     * Visit node in dfs fashion but also add a parent argument
     * if adjacent node has already been visited and it is neither the parent of current node, boom we have found the cycle     
     */ 
    vector<GraphNode<T>*> list = g->nodeList;
    set<GraphNode<T>*> gset; 
    for(int i=0; i<list.size(); i++){
        if(gset.find(list[i])==gset.end()){
            gset.insert(list[i]);
            GraphNode<T>* node = NULL;
            if(cycleCheckDFS(g, &gset, list[i], node))return true;
        }
    }
    return false;
}


#endif /* CYCLECHECK_H */

