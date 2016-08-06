#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#include "Graph.h"
#include <queue>
#include <map>
using namespace std;

template<typename T>
void shortestPath(Graph<T>* g, const T& data1, const T& data2){
    /* Algorithm
     * Use bfs but add an additional parent map which has children as key and parents as values
     */
    GraphNode<T>* n1 = g->findVertex(data1);
    GraphNode<T>* n2 = g->findVertex(data2);
    if(!n1||!n2)return;
    vector<GraphNode<T>*> list = g->getList();
    queue<GraphNode<T>*> q;
    map<GraphNode<T>*, GraphNode<T>*> gmap;
    for(int i=0; i<list.size(); i++){
    if(gmap.find(list[i])==gmap.end()){
    q.push(list[i]);
    gmap[list[i]]=NULL;
    while(q.empty()==false){
        GraphNode<T>* node = q.front(); q.pop();
        AdjacentNode<T>* adjNode = node->next;
        while(adjNode){
            if(gmap.find(adjNode->node)==gmap.end()){
                q.push(adjNode->node);
                gmap[adjNode->node] = node;
                if(gmap.find(n1)!=gmap.end()&&gmap.find(n2)!=gmap.end())goto stop;
            }
            adjNode = adjNode->next;
        }
    }
    }
    }
    stop:
    GraphNode<T>* node = n2;
    while(n2&&n2!=n1){
        cout<<n2->data<<"-->"<<gmap[n2]->data<<endl;
        n2 = gmap[n2];
    }
}

#endif /* SHORTESTPATH_H */