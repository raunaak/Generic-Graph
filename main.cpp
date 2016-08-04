#include <iostream>
#include "Graph.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "CycleCheck.h"
using namespace std;
int main(){
    /*Graph<int> g1;
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    if(cycleCheckDFS(&g1))cout<<"Cycle is present";
    else cout<<"Cycle is not present";
    */        
    Graph<int> g2;
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    if(cycleCheckDFS(&g2))cout<<"Cycle is present";
    else cout<<"Cycle is not present";
 
    /*
    Graph<int> g;
    g.addEdge( 0, 1);
    g.addEdge( 0, 4);
    g.addEdge( 1, 2);
    g.addEdge( 1, 3);
    g.addEdge( 1, 4);
    g.addEdge( 2, 3);
    g.addEdge( 3, 4);
    */
    
    //Depth First Search
    //depthFirstSearch(&g);
    //cout<<endl;
    
    //Breadth First Search
    //breadthFirstSearch(&g);
    //cout<<endl;
    
    // Print graph line by line such that each line contains node and all of its neighbours
    //g.print();
     
    return 0;
}