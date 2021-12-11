/**
 * @file 1971.Find-if-Path-Exists-in-Graph.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex start to vertex end.

Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, end = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= start, end <= n - 1
There are no duplicate edges.
There are no self edges.
*/
//Solved using Union Find

class Solution {
    class Union{
        public:
        vector<int> parentset;
        Union(int n){
            parentset = vector<int>(n, 0);
            for(int i =0; i<n; i++)
                parentset[i] = i;
        }
        int getparent(int u){ // best case o(1), worst case o(n);
            if(parentset[u] == u)
                return u;
            return parentset[u] = getparent(parentset[u]);
        }
        void setparent(int i, int j){ // o(n)
            i = getparent(i), j = getparent(j); //o(2n)
            if(i <= j)
                parentset[j] = getparent(i); // o(n)
            else
                parentset[i] = getparent(j); // o(n)
        }
    };
    public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        Union * unionset = new Union(n);
        
        for(auto i: edges)  //o(n^2) worst case
            unionset->setparent(i[0], i[1]);
        
        for(auto i : edges) // o(n^2) worst case
            unionset->parentset[i[0]] = unionset->getparent(i[0]), 
            unionset->parentset[i[1]] = unionset->getparent(i[1]);
        
        return unionset->parentset[start] == unionset->parentset[end];  //o(1)
    }
};

/*
10
[[2,6],[4,7],[1,2],[3,5],[7,9],[6,4],[9,8],[0,1],[3,0]]
3
5

10
[[0,7],[0,8],[6,1],[2,0],[0,4],[5,8],[4,7],[1,3],[3,5],[6,5]]
7
5
*/

//DFS Approach O(n)
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& status, int start, int end){
        //cout<<start<<endl;
        if(start == end) return true;
        if(status[start]) return false;
        status[start] = 1;
        for(int i = 0; i<graph[start].size(); i++)
            if(dfs(graph, status, graph[start][i], end))
                return true;
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int> > graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> status(n, 0);
        return dfs(graph, status, start, end);
    }
};
