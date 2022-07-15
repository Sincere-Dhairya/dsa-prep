/**
 * @file Detect cycle in Directed Graph using Topological Sort
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * @link https://www.geeksforgeeks.org/detect-cycle-in-directed-graph-using-topological-sort/ @endlink
 * @copyright Copyright (c) 2022
 * @tags topological-sort
 */
/*
Given a Directed Graph consisting of N vertices and M edges and a set of Edges[][], the task is to check whether the graph contains a cycle or not using Topological sort.

Topological sort of directed graph is a linear ordering of its vertices such that, for every directed edge U -> V from vertex U to vertex V, U comes before V in the ordering. 
 

Examples: 

Input: N = 4, M = 6, Edges[][] = {{0, 1}, {1, 2}, {2, 0}, {0, 2}, {2, 3}, {3, 3}} 
Output: Yes 
Explanation: 
A cycle 0 -> 2 -> 0 exists in the given graph

Input: N = 4, M = 3, Edges[][] = {{0, 1}, {1, 2}, {2, 3}, {0, 2}} 
Output: No 
*/

// THE IDEA IS TO DO TOPOLOGICAL SORTING IN THE GRAPH VIA THA KAHANE'S ALGORITHM AND THEN KEEP ON MAINTAING THE INDEGREES ARRAY. IF THE CYCLE EXISTS THEE INDEGREE OF ATLEAST ONE NODE WILL BE POSITIVE NUMBER, OTHERWISE ALL WILL BE ZERO.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool checkCycle(vector<vector<int>>& edges, int& N){
    vector<vector<int>> graph(N+1);
    vector<int> indegree(N+1);

    for(int i=0; i<edges.size(); ++i){
        graph[edges[i][0]].emplace_back(edges[i][1]);
        ++indegree[edges[i][1]];
    }

    queue<int> q;

    for(int i = 0; i<indegree.size(); ++i){
        if(indegree[i] == 0) q.push(i);
    }

    while(q.size()){
        int curr = q.front();
        q.pop();

        for(int child: graph[curr]){
            if(--indegree[child] == 0){
                q.push(child);
            }
        }
    }

    for(int i: indegree){
        if(i) return 1;
    }
    return 0;
}

int main(){
    vector<vector<int>> edges = //{{0, 1}, {1, 2}, {2, 3}, {0, 2}}; 
    { {0, 1}, {1, 2}, {2, 0}, {0, 2}, {2, 3}, {3, 3}};
    int N = 4;

    cout<< checkCycle(edges, N) <<endl;
    return 0;
}