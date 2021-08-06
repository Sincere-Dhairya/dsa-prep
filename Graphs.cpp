#include<bits/stdc++.h>
#include"graphfunctions.cpp"

using namespace std;

int main(){
    int v = 5;

/*    vector<int> * graph = new vector<int>[v];

    addedge(graph, 0, 1);
    addedge(graph, 0, 2);
    addedge(graph, 4, 2);
    //addedge(graph, 0, 3);
    addedge(graph, 1, 2);
    addedge(graph, 4, 3);
    //addedge(graph, 0, 4);
    addedge(graph, 3, 1);
    printinggraph(graph, v);
*/
    vector<graphnode> * graph = new vector<graphnode> [v];
    addedgenew(graph, 0, 1);
    addedgenew(graph, 0, 2);
    addedgenew(graph, 2, 3);
    addedgenew(graph, 1, 4);
    addtwoedgenew(graph, 3, 4);
    printingnew(graph,v);
    return 0;
}