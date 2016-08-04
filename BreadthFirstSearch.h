#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H
#include"Graph.h"
#include <queue>
#include <set>
using namespace std;

template<typename T>
void breadthFirstSearch(Graph<T>* g, queue<GraphNode<T>*>* q, set<GraphNode<T>*>* gset){
    while(q->size()>0){
        GraphNode<T>* node = q->front(); q->pop(); cout<<node->data<<" ";
        AdjacentNode<T>* adjNode = node->next;
        while(adjNode){
            if(gset->find(adjNode->node)==gset->end()){
                q->push(adjNode->node); 
                gset->insert(adjNode->node);
            }
            adjNode = adjNode->next;       
        }        
    }
}

template<typename T>
void breadthFirstSearch(Graph<T>* g){
    /* Algorithm
     * Add first graph node to queue, add this node to set to mark that we have visited the node
     * while queue is not empty
     *     pop from queue and print it
     *     Go to all the neighbours of this popped node
     *     for every neighbour, 
     *         if the neighbour is not present in set, add it to queue and set
     *         else continue;
     * 
     * The graph might be disconnected, so go to every node
     *     Check if it is present in set
     *         if yes, continue
     *         if no, run breadth first search on this part
     */
    vector<GraphNode<T>*> list = g->nodeList;
    queue<GraphNode<T>*> q;  
    set<GraphNode<T>*> gset; 
    cout<<list.size()<<endl;
    for(int i=0; i<list.size(); i++){
        if(gset.find(list[i])==gset.end()){
            q.push(list[i]);
            gset.insert(list[i]);
            breadthFirstSearch(g, &q, &gset);
        }
    }    
}
#endif /* BREADTHFIRSTSEARCH_H */