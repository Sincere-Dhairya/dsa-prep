#include<bits/stdc++.h>

using namespace std;

map<int, vector<int>> graph;
map<int, bool> status;

void addedge(int u, int v){
    graph[u].push_back(v);
    status[u] = status[v] = false;
}

void min_distance_by_bfs(vector<int> & dist, int src){
    dist[src] = min(0, dist[src]);
    queue <int> Q;
    Q.push(src);

    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(int i =0; i<graph[curr].size(); i++){
            int temp = graph[curr][i];
            if(status[temp] == 0){
                status[temp] = true;
                dist[temp] = min(dist[temp], dist[curr]+1);
                Q.push(temp);
            }
        }
    }
}

int main(){
    int v = 10;

    addedge(1,2);
    //addedge(2,1);
    addedge(2,3);
    //addedge(3,2);
    addedge(3,4);
    //addedge(4,3);
    addedge(3,8);
    //addedge(8,3);
    addedge(4,5);
    //addedge(5,4);
    addedge(8,7);
    //addedge(7,8);
    addedge(5,6);
    //addedge(6,5);
    addedge(6,7);
    //addedge(7,6);
    addedge(5,9);
    //addedge(9,5);
    addedge(9,10);
    //addedge(10,9);
    //addedge(4,10);
    addedge(10,4);

    vector<int> distance(v+1, INT_MAX);

    min_distance_by_bfs(distance,1);

    for(int i =1; i<=v; i++){
        cout<<distance[i]<<" ";
    }
}