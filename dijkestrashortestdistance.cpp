#include<bits/stdc++.h>

using namespace std;

map<int, vector<pair<int, int>>> graph;
//map<int, bool> status;
map<int, int> distances;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;

void addedge(int u, int v, int x){
    graph[u].push_back({v, x});
    //status[u] = status[v] = false;
    distances[u] = distances[v] = 1000000;
}

void dijkestra_short_distance(){
    while(!pq.empty()){
        pair<int, int> adj_pair = pq.top();
        pq.pop();
        int adj = adj_pair.second;
        int dist = adj_pair.first;
        for(int i =0 ;i <graph[adj].size(); i++){
            int next = graph[adj][i].first;
            int next_dis = graph[adj][i].second;
            if(distances[next]> dist + next_dis){
                distances[next] = dist+next_dis;
                pq.push({dist+next_dis, next});
            }
        }
    }
}

void display(){
    for(auto itr:distances) cout<<itr.first<<" : "<<itr.second<<endl;
}

int main(){
    cout<<"Part0"<<endl;
    addedge(0, 1, 4);
    addedge(1, 0, 4);
    addedge(0, 7, 8);
    addedge(7, 0, 8);
    addedge(1, 7, 11);
    addedge(7, 1, 11);
    addedge(1, 2, 8);
    addedge(2, 1, 8);
    addedge(2, 8, 2);
    addedge(8, 2, 2);
    addedge(7, 8, 7);
    addedge(8, 7, 7);
    addedge(7, 6, 1);
    addedge(6, 7, 1);
    addedge(8, 6, 6);
    addedge(6, 8, 6);
    addedge(6, 5, 2);
    addedge(5, 6, 2);
    addedge(2, 5, 4);
    addedge(5, 2, 4);
    addedge(2, 3, 7);
    addedge(3, 2, 7);
    addedge(3, 5, 14);
    addedge(5, 3, 14);
    addedge(5, 4, 10);
    addedge(4, 5, 10);
    addedge(3, 4, 9);
    addedge(4, 3, 9);

    distances[0] = 0;
    pq.push({0, 0});

    dijkestra_short_distance();
    display();
}