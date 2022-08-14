/**
 * @file Solve the Dependency
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * @tags topological-sort
 */
/* Question:
Tony was part of Software Management System project team. There was a feature to be added to a system where given the N modules to be developed of a project, the system must be able to present the order in which the modules to be developed. The module cannot be started unless the dependent modules are completed. There is no way the modules can be completed, it must warn the user.

The modules are numbered from 1 to N. The every input consists of two values A and B, which translates to A module is dependent on B. Given the inputs, your task is to print the order in which the modules must be developed. If not possible it must warn saying "NOT POSSIBLE". If there are two modules which are independent (or can be developed ), then print in ascending order.

Input Format

The First line contains a single integer N.

The Next line contains a single integer I, denoting number

of inputs

The next I lines contains space separated values denoting A and B.

Output Format
Space seperated integers denoting the correct order of Modules.

Example:
3
1
1 2

Output
2 1 3
*/

// Topological Sort using DFS
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& visited, vector<vector<int>>& graph, vector<int>& indegrees, int u, vector<int>& order){
    visited[u] = 1;
    if(indegrees[u]) --indegrees[u];
    for(int ch: graph[u]){
        if(visited[ch] == 0 && indegrees[ch]){
            dfs(visited, graph, indegrees, ch, order);
        }
    }
    order.push_back(u);
}

bool getOrder(vector<vector<int>>& graph, vector<int>& indegrees, int& N){
    vector<int> order, visited(N+1);
    for(int i = 1; i<=N; ++i){
        if(visited[i] == 0)
            dfs(visited, graph, indegrees, i, order);
    }
    for(int i: indegrees){
        if(i) return 0;
    }
    
    for(int i: order){
        cout << i << " ";
    }
    return 1;
}

int main() {
	int N;
	cin >> N;
	int I ;
	cin >> I;
	vector<vector<int>> graph(N+1);
	vector<int> indegrees(N+1);
	while(I--){
	    int a, b;
	    cin >> a >> b;
	    graph[a].emplace_back(b);
	    ++indegrees[b];
	}
	if(getOrder(graph, indegrees, N) == 0){
	    cout << "NOT POSSIBLE";
	}
	return 0;
}