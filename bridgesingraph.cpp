#include<bits/stdc++.h>

using namespace std;

map<int, vector<int> > graph;

vector<int> low_time_adj(100, -1), insert_time(100, -1);
vector<bool> status(100, false);
vector<pair<int, int>> bridges;

void addedge(int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int curr, int parent, int timer){
    low_time_adj[curr] = insert_time[curr] = ++timer;
    status[curr] = true;

    for(int i =0 ;i<graph[curr].size(); i++){
        int child = graph[curr][i];
        if(child == parent) continue;
        if(status[child]== 0){
            dfs(child, curr, timer);
            low_time_adj[curr] = min(low_time_adj[curr], low_time_adj[child]);
            if(low_time_adj[child] > insert_time[curr]) bridges.push_back({curr, child});
        }
        else{
            low_time_adj[curr] = min(low_time_adj[curr], insert_time[child]);
        }
    } 
 }

void printingbridge(){
    for(pair<int, int> i : bridges){
        cout<<i.first<<" - "<<i.second<<endl;
    }
}

int main(){
    int V = 12;
    addedge(1, 2);
    addedge(2, 3);
    addedge(3, 4);
    addedge(1, 4);
    addedge(4, 5);
    addedge(5, 6);
    addedge(6, 7);
    addedge(7, 8);
    addedge(6, 9);
    addedge(8, 9);
    addedge(8, 10);
    addedge(10, 11);
    addedge(11, 12);
    addedge(10, 12);

    dfs(1, -1, 0);
    printingbridge();
    return 0;
}