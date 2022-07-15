/**
 * @file Topological Sorting by DFS
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-16
 * @link  @endlink
 * @copyright Copyright (c) 2022
 * @tags topological-sort
 */
/**
 * SORTING THE GIVEN GRAPH VIA DFS TOPOLOGICAL SORT. WE NEED TO KEEP AN ARRAY FOR VISITED STATUS AND A STACK VECTOR THAT WILL BE PUSHED WITH AN ELEMENT WHEN A RECURSIVE FUNCTION CALL EXPIRES.
 */

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void DFS(vector<vector<int>>& graph, vector<int>& visited, int curr, vector<int>& ans){
    visited[curr] = 1;
    for(int child: graph[curr]){
        if(!visited[child]){
            DFS(graph, visited, child, ans);
        }
    }
    ans.emplace_back(curr);
}

vector<int> topologicalSort(vector<vector<int>>& edges, int N){
    vector<vector<int>> graph(N+1);
    vector<int> visited(N+1), ans;

    for(int i=0 ;i<edges.size(); ++i){
        graph[edges[i][0]].emplace_back(edges[i][1]);
    }

    for(int i=1; i<=N; ++i){
        if(visited[i] == 0 && graph[i].size()){
            DFS(graph, visited, i, ans);
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> edges = {
        {1, 2}, {1, 3}, {2,6}, {3,6}, {3,5}, {6,7}, {6,10}
    };
    int N = 10;

    vector<int> ans = topologicalSort(edges, N);

    for(int i: ans){
        cout<< i<<" ";
    }
    return 0;
}