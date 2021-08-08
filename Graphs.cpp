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
    addtwoedgenew(graph, 0, 1);
    addtwoedgenew(graph, 0, 2);
    addtwoedgenew(graph, 2, 3);
    addtwoedgenew(graph, 1, 4);
    //addtwoedgenew(graph, 3, 4);
    printingnew(graph,v);
    //bfs(graph, v);
    cout<<endl;
    vector<bool> status(v, false);
    //dfs(graph, 0, status, v);
    topologicalsort(graph, v, status, 0);
    cout<<endl;
    return 0;
}