#ifndef STRONGLYCONNECTEDCOMPONENTS_H
#define STRONGLYCONNECTEDCOMPONENTS_H
#include "DirectedGraph.h"
#include <queue>
#include <set>
using namespace std;

template<typename T>
void printStronglyConnectedComponent(DirectedGraph<T>* g, GraphNode<T>* node, queue<GraphNode<T>*>* q, set<GraphNode<T>*>* gset){
    q->push(node);
    gset->insert(node);
    AdjacentNode<T>* adjNode = node->next;
    while(adjNode){
        if(gset->find(adjNode->node)==gset->end())printStronglyConnectedComponent(g, adjNode->node, q, gset);        
        adjNode = adjNode->next;
    }
}

template<typename T>
void getTranspose(DirectedGraph<T>* g, set<GraphNode<T>*>* gset){
    vector<GraphNode<T>*> list = g->getList();
    for(int i=0; i<list.size(); i++){
        while(list[i]->next&&gset->find(list[i]->next->node)!=gset->end())list[i]->next=list[i]->next->next;
        AdjacentNode<T>* adjNode = (list[i])->next;
        while(adjNode){
            if(gset->find(adjNode->node)==gset->end())g->addEdge(adjNode->node->data, list[i]->data);
            if(adjNode->next&&gset->find(adjNode->next->node)!=gset->end())adjNode->next = adjNode->next->next;
            else adjNode = adjNode->next;
        }
        gset->insert(list[i]);
    }
}

template<typename T>
void depthFirstSearch(DirectedGraph<T>* g, GraphNode<T>* node, set<GraphNode<T>*>* gset){
    cout<<node->data<<" ";
    gset->insert(node);
    AdjacentNode<T>* adjNode = node->next;
    while(adjNode){
        cout<<"YES"<<adjNode->node->data<<" ";
        if(gset->find(adjNode->node)==gset->end())depthFirstSearch(g, adjNode->node, gset);
        adjNode = adjNode->next;
    }
}

template<typename T>
void printStronglyConnectedComponent(DirectedGraph<T>* g){
    /* Kosaraju Algorithm
     * Perform DFS on directed graph, but also add node to queue after adding the node to set (marking as visited)
     * Get the transpose of graph
     * Perform DFS on every node by popping every node one by one from stack
     */
    g->print();
    //step 1: perform dfs
    queue<GraphNode<T>*> q;
    set<GraphNode<T>*> gset;
    vector<GraphNode<T>*> list = g->getList();
    for(int i=0; i<list.size(); i++){
        if(gset.find(list[i])==gset.end())printStronglyConnectedComponent(g, list[i], &q, &gset);        
    }
    gset.clear();
    cout<<"OK"<<endl;
    //step 2: reverse edges
    getTranspose(g, &gset);
    g->print();
    cout<<"OK"<<endl;
    
    //step 3: pop out of queue and apply dfs by marking elements
    while(q.empty()==false){
        GraphNode<T>* node = q.front(); q.pop();
        if(gset.find(node)==gset.end()){
            depthFirstSearch(g, node, &gset);
            cout<<"AD"<<endl;            
        }
    }   
    gset.clear();
    getTranspose(g, &gset);
}
#endif /* STRONGLYCONNECTEDCOMPONENTS_H */

