#include<bits/stdc++.h>
#include"graphfunctions.cpp"

using namespace std;

map<int, vector<int> > graph;
map<int, bool> status;

void addedge(int u, int v){
    graph[u].push_back(v);
    status[u] = status[v] = false;
}

bool check_undirected(int u, int v){
    int n = graph[v].size();
    for(int i =0; i<n; i++){
        if(u == graph[v][i]) return true;
    }
    return false;
}

stack<int> topology;
void traversal(int vertex){
    
}

int main(){
}