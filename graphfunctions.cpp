#include<bits/stdc++.h>

using namespace std;

struct graphnode{
    int val;
    bool status;

    graphnode();
};

graphnode::graphnode(){
    status = false;
    cout<<"Status set to False"<<endl;
}

void addedgenew(vector<graphnode> * graph, int u, int v){
    graphnode node;
    node.val = v;
    graph[u].push_back(node);
}

void addtwoedgenew(vector<graphnode> * graph, int u, int v){
    graphnode node1;
    node1.val = v;
    graph[u].push_back(node1);
    graphnode node2;
    node2.val = u;
    graph[v].push_back(node2);
    
}

void printingnew(vector<graphnode> *graph, int v){
    for(int i =0; i<v; i++){
        cout<< i <<" -> ";
        for(int j = 0; j<graph[i].size(); j++){
            cout<<graph[i][j].val<<": ";
        }
        cout<<endl;
    }
}



//<-----------------------Simple List Functions ------------------------------>

void addtwoedge(vector<int> * graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void addedge(vector<int> *graph, int u, int v){
    graph[u].push_back(v);
}

void printinggraph(vector<int> *graph, int v){
    for(int i =0; i <v; i++){
        cout<< i <<" -> ";
        for(int j = 0; j<graph[i].size(); j++){
            cout<< graph[i][j] <<", ";
        }
        cout<<endl;
    }
}