/**
 * @file Minimize colours to paint graph such that no path have same colour
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * @link https://www.geeksforgeeks.org/minimize-colours-to-paint-graph-such-that-no-path-have-same-colour/ @endlink
 * @copyright Copyright (c) 2022
 * @tags topological-sort
 */
/*
Given a directed graph with N nodes and M connections shown in the matrix mat[] where each element is of the form {xi, yi} denoting a directed edge from yi to xi. The task is to use the minimum number of colours to paint the nodes of the graph such that no two nodes in a path have the same colour. 

Examples:

Input: N = 5, M = 6, mat = {{1, 3},  {2, 3},  {3, 4}, {1, 4},  {2, 5},  {3, 5}}
Output: 3
Explanation: The graph nodes can be coloured as shown below
and that is the minimum number of colours possible.
 

Example 1
Example 1

Input: N = 3, M = 2, mat = {{1, 3}, {2, 3}}
Output: 2
Explanation: Here 1 and 2 can be assigned same colour and 3 another colour.
*/

// TC: O(N+M). SC: O(N+M).

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int minColors(vector<vector<int>>& mat, int N, int M){
    vector<vector<int> > graph(N+1);
    vector<int> indegrees(N+1, 0), visited(N+1, 0);

    int colors = 0;
    for(int i=0; i<M; ++i){
        graph[mat[i][0]].emplace_back(mat[i][1]);
        ++indegrees[mat[i][1]];
    }

    queue<int> q;

    for(int i=1; i<=N; ++i){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }

    while(q.size()){
        int n = q.size();
        ++colors;

        for(int i = 0; i<n; ++i){
            int curr = q.front();
            q.pop();
            visited[curr] = 1;

            for(int ch: graph[curr]){
                if(--indegrees[ch] == 0 && visited[ch] == 0){
                    q.push(curr);
                }
            }
        }
    }
    return colors;
}

int main(){
    vector<vector<int>> mat = {{1,3}, {2,3}, {3,4}, {1,4}, {2,5}, {3,5}};
    int N = 5, M = 6;
    cout << minColors(mat, N, M) << endl;
}