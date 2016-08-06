#ifndef MINIMUMSPANNINGTREE_H
#define MINIMUMSPANNINGTREE_H
#include "Graph.h"
#include <map>
#include <queue>
using namespace std;

template<typename T>
void minimumSpanningTree(Graph<T>* g){
    /* Algorithm
     * Use bfs but add an additional parent map which has children as key and parents as values
     */
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
            }
            adjNode = adjNode->next;
        }
    }
    }
    }
    
    typename map<GraphNode<T>*, GraphNode<T>*>::iterator it = gmap.begin();
    for( ; it!=gmap.end(); it++){
        cout<<it->first->data;
        if(it->second)cout<<"-->"<<it->second->data;
        cout<<endl;
    }
}



#endif /* MINIMUMSPANNINGTREE_H */

