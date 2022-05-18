/**
 * @file 1192. Critical Connections in a Network
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-19
 * @link https://leetcode.com/problems/critical-connections-in-a-network/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server 
connections forming a network where connections[i] = [ai, bi] represents a connection 
between servers ai and bi. Any server can reach other servers directly or indirectly 
through the network.

A critical connection is a connection that, if removed, will make some servers unable 
to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

// O(N)
class Solution {
public:
    void DFSforNetwork(vector<vector<int>>& ans, vector<vector<int>>& graph, vector<int>& visited, vector<int>& LIT, vector<int>& IT, int timer, int curr, int par){
        ++timer;
        LIT[curr] = IT[curr] = timer, visited[curr] = 1;
        
        for(int adj: graph[curr]){
            if(adj == par) continue;
            if(!visited[adj]){
                DFSforNetwork(ans, graph, visited, LIT, IT, timer, adj, curr);
                LIT[curr] = min(LIT[curr], LIT[adj]);
                if(LIT[adj] > IT[curr]){
                    ans.push_back({curr, adj});
                }
            }
            LIT[curr] = min(LIT[curr], IT[adj]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans, graph(n);
        for(auto C: connections ){
            graph[C[0]].push_back(C[1]),
            graph[C[1]].push_back(C[0]);
        }
        vector<int> LIT(n, 0), IT(n, 0), visited(n, 0);
        DFSforNetwork(ans, graph, visited, LIT, IT, 0, 0, -1);
        return ans;
    }
};