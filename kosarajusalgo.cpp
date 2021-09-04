#include<bits/stdc++.h>

using namespace std;

map<int, vector<int>> graph;
vector<bool> status(100, false);

map<int, vector<int> > transpose;

void addedge1(int u, int v){
    graph[u].push_back(v);
}

void make_transpose(int u, int v){
    transpose[u].push_back(v);
}

stack<int> topological;

void dfs(int curr){
    status[curr] = true;

    for(int i : graph[curr]){
        if(!status[i]) dfs(i);
    }
    topological.push(curr);
}

void another_dfs(int curr){
    status[curr] = true;
    cout<<curr<<" ";

    for(int i : transpose[curr]){
        if(!status[i]) another_dfs(i);
    }
}

int main(){
    addedge1(1,2 );
    addedge1(2, 3);
    addedge1(3, 1);
    addedge1(3, 4);
    addedge1(4, 5);

    //dfs(1);

    int V = 5;
    for(int i = 1; i<V+1; i++){
        status[i] = false;
        for(int j : graph[i]) make_transpose(j, i);
    }
    
    for(int i = 1; i<= V; i++){
        if(status[i] == 0){
            another_dfs(i);
        }
        cout<<endl;
    }
    return 0;
}