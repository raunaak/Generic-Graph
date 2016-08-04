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

template<typename T>
bool cycleCheckBFS(Graph<T>* g){
    /* Idea
     * Traverse graph using BFS algorithm
     * Maintain two queues, one for current node and one for parent node
     * If any of the current node's children have already been visited and not equal to parent, yeah there is a cycle
     */
    vector<GraphNode<T>*> list = g->nodeList;
    queue<GraphNode<T>*> q, p; //q queue for current node, p queue for parent node
    set<GraphNode<T>*> gset;
    for(int i=0; i<list.size(); i++){
        if(gset.find(list[i])==gset.end()){
            gset.insert(list[i]);
            GraphNode<T>* node = NULL;
            q.push(list[i]); p.push(node);
            while(!q.empty()){
                GraphNode<T>* curr = q.front(); q.pop();
                GraphNode<T>* parent = p.front(); p.pop();
                AdjacentNode<T>* adjNode = curr->next;
                while(adjNode){
                    if(gset.find(adjNode->node)==gset.end()){ // child node is not present, add curr to p and child node to q
                        q.push(adjNode->node);
                        p.push(curr);
                        gset.insert(adjNode->node); // when node is pushed in queue q, insert in gset
                    }else if(adjNode->node!=parent)return true; //child node is already visited but is not current node's parent
                    adjNode = adjNode->next; //traverse all the adjacent elements
                }
            }
        }
    }
    return false;
}
#endif /* CYCLECHECK_H */

