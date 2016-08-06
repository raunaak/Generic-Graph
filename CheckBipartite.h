#ifndef CHECKBIPARTITE_H
#define CHECKBIPARTITE_H
#include "Graph.h"
#include <set>
#include <queue>
using namespace std;

template<typename T>
bool isBipartiteDFS(Graph<T>* g, GraphNode<T>* node, set<GraphNode<T>*>* gset1, set<GraphNode<T>*>* gset2){
    AdjacentNode<T>* adjNode = node->next;
    while(adjNode){
        if(gset1->find(adjNode->node)==gset1->end()&&gset2->find(adjNode->node)==gset2->end()){
            if(gset1->find(node)!=gset1->end())gset2->insert(adjNode->node);
            else gset1->insert(adjNode->node);
            isBipartiteDFS(g, adjNode->node, gset1, gset2);
        }else if(gset1->find(adjNode->node)!=gset1->end()&&gset1->find(node)!=gset1->end())return false;
        else if(gset2->find(adjNode->node)!=gset2->end()&&gset2->find(node)!=gset2->end())return false;
        adjNode = adjNode->next;
    }
    return true;
}

template<typename T>
bool isBipartiteDFS(Graph<T>* g){
    vector<GraphNode<T>*> list = g->getList();
    set<GraphNode<T>*> gset1;
    set<GraphNode<T>*> gset2;
    for(int i=0; i<list.size(); i++){
        if(gset1.find(list[i])==gset1.end()&&gset2.find(list[i])==gset2.end()){
            gset1.insert(list[i]);
            if(!isBipartiteDFS(g, list[i], &gset1, &gset2))return false;
        }
    }
    return true;
}

template<typename T>
bool isBipartiteBFS(Graph<T>* g){
    vector<GraphNode<T>*> list = g->getList();
    set<GraphNode<T>*> gset1;
    set<GraphNode<T>*> gset2;
    queue<GraphNode<T>*> q;
    for(int i=0; i<list.size(); i++){
        if(gset1.find(list[i])==gset1.end()&&gset2.find(list[i])==gset2.end()){
            gset1.insert(list[i]);
            q.push(list[i]);
            while(q.empty()==false){
                GraphNode<T>* node = q.front(); q.pop();
                AdjacentNode<T>* adjNode = node->next;
                while(adjNode){
                    if(gset1.find(adjNode->node)==gset1.end()&&gset2.find(adjNode->node)==gset2.end()){
                        if(gset1.find(node)!=gset1.end())gset2.insert(adjNode->node);
                        else gset1.insert(adjNode->node);
                        q.push(adjNode->node);
                    }else if(gset1.find(adjNode->node)!=gset1.end()&&gset1.find(node)!=gset1.end())return false;
                    else if(gset2.find(adjNode->node)!=gset2.end()&&gset2.find(node)!=gset2.end())return false;
                    adjNode = adjNode->next;
                }
            }
        }
    }
    return true;
}
#endif /* CHECKBIPARTITE_H */

