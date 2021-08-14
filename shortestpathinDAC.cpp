#include<bits/stdc++.h>

using namespace std;

map<int, vector<pair<int, int>>> graph;
map<int, bool> status;
map<int, int> distances;

void addedge(int u, int v, int x){
    graph[u].push_back({v, x});
    status[u] = status[v] = false;
    distances[u] = distances[v] = INT_MAX;
}

void topologicalorder(int curr, stack<int> & S){

    for(int i =0 ;i<graph[curr].size(); i++){
        int adj = graph[curr][i].first;
        if(status[adj] == false){
            status[adj] = true;
            topologicalorder(adj, S);
        }
    }
    S.push(curr);
}

void printing(stack<int> sample){
    while(!sample.empty()){
        cout<<sample.top()<<" ";
        sample.pop();
    }
}

void shortestpath(stack<int> S){
    distances[S.top()] = 0;
    while(!S.empty()){
        int curr = S.top();
        S.pop();
        for(int i =0; i<graph[curr].size(); i++){
            int adj = graph[curr][i].first;
            int dist = graph[curr][i].second;
            distances[adj] = min(distances[adj], distances[curr] + dist);
        }
    }
}

void printing_distances(){
    for(auto itr:distances){
        cout<<itr.first<< " "<<itr.second<<endl;
    }
}

int main(){
    cout<<"Part0"<<endl;
    addedge(0, 1, 2);
    addedge(0, 4, 1);
    addedge(1, 2, 3);
    addedge(2, 3, 6);
    addedge(4, 2, 2);
    addedge(4, 5, 4);
    addedge(5, 3, 1);
    stack<int> S;
    cout<<"Part1"<<endl;
    topologicalorder(0, S);
    cout<<"Part2"<<endl;
    //printing(S);
    shortestpath(S);
    printing_distances();
    
}