/**
 * @file Single source shortest path between two cities
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-20
 * @link https://www.geeksforgeeks.org/single-source-shortest-path-between-two-cities/ @endlink
 * @copyright Copyright (c) 2022
 * @tags dijkestra
 */
/*
Given a graph of N Nodes and E edges in form of {U, V, W} such that there exists an edge between U and V with weight W. You are given an integer K and source src and destination dst. The task is to find the cheapest cost path from given source to destination from K stops.
Examples: 
 

Input: N = 3, edges = [[0, 1, 100], [1, 2, 100], [0, 2, 500]], src = 0, dst = 2, k = 1 
Output: 200 
Explanation: 
The Cheapest Price is from City 0 to City 2. With just one stop, it just costs 200 which is our Output.
Input: N = 3, edges = [[0, 1, 100], [1, 2, 100], [0, 2, 500]], src = 0, dst = 2, k = 0 
Output: 500 
*/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define INF (int)(1e9)

// TC: O((V+E)Log(V)), SC: O(V).
int minPathCost(vector<vector<int>>& edges, int& N, int& SOURCE, int& DEST, int& COUNT){
    vector<vector<pair<int, int>>> graph(N+1);
    vector<int> costs(N+1, INF);

    // TC: O(E)
    for(int i = 0; i<edges.size(); ++i){
        graph[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {SOURCE, COUNT}});
    costs[SOURCE] = 0;

    while(q.size()){
        int curr_cost = q.top().first,
        curr = q.top().second.first,
        curr_count = q.top().second.second;
        q.pop(); // log n

        if(curr_count >= 0){
            for(auto& adj: graph[curr]){ 
                int adj_node = adj.first,
                adj_cost = adj.second;

                if(costs[adj_node] > adj_cost+curr_cost){
                    costs[adj_node] = adj_cost+curr_cost;
                    q.push({costs[adj_node], {adj_node, curr_count-1}});
                }
            }
        }
    }

    return costs[DEST];
}

int main(){
    vector<vector<int>> edges = {{0,1,4}, {2,1,1}, {1,4,5}, {1,3,2}, {3,2,3}, {3,4,1}, {4,5,5}, {2,5,6}, {4,6,2}, {6,5,2}};
    int N = 6, SOURCE = 1, DEST = 5, COUNT = 3;
    cout << minPathCost(edges, N, SOURCE, DEST, COUNT);
    return 0;
}