#include<bits/stdc++.h>

using namespace std;

map<int, vector<int>> graph;
vector<bool> status(100, false);

vector<int> low_time_adj(100, -1), insert_time(100, -1);

void addedge(int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

set<int> articulationpoints;

void dfs(int curr, int parent, int timer){
    low_time_adj[curr] = insert_time[curr] = ++timer;
    status[curr] = true;

    for(int i : graph[curr]){
        if(i == parent) continue;

        if(!status[i]){
            dfs(i, curr, timer);
            low_time_adj[curr] = min(low_time_adj[curr], low_time_adj[i]);
            if(low_time_adj[i] > insert_time[curr]) {
                articulationpoints.insert(curr);
                articulationpoints.insert(i);
            }
        }
        else{
            low_time_adj[curr] = min(low_time_adj[curr], insert_time[i]);
        }
    }
}

void printing_articulation_points(){
    for(auto itr : articulationpoints)
        cout<<itr<<" ";
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
    printing_articulation_points();
    return 0;
}