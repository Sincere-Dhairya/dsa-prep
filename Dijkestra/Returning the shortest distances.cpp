/**
 * @file Dijkestra's Algorithm returning the shortest distances
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-19
 * @link  @endlink
 * @copyright Copyright (c) 2022
 * @tags dijkestra
 */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> dijkestra_fn(vector<vector<pair<int, int>>>& graph, int&N, int& start){
    int INF = 1e9;
    vector<int> distances(N+1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    distances[start] = 0;
    q.push({distances[start], start});

    while(q.size()){
        int curr = q.top().second,
        dist = q.top().first;
        q.pop();
        
        for(pair<int, int> adj: graph[curr]){
            int adj_node = adj.first,
            adj_dist = adj.second;

            if(distances[adj_node] > dist+adj_dist){
                distances[adj_node] = dist+adj_dist;
                q.push({distances[adj_node], adj_node});
            }
        }
    }

    return distances;
}
int main(){
    vector<vector<pair<int, int>>> graph = {
        {{1,1}, {2,4}}, {{2,2}, {3,6}}, {{3,3}}
    };
    int N = 3, source = 0;
    vector<int> distances = dijkestra_fn(graph, N, source);
    for(int i: distances) cout<< i << " ";
    return 0;
}