/**
 * @file Find Maximum Shortest Distance in Each Component of a Graph
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-18
 * @link https://www.geeksforgeeks.org/find-maximum-shortest-distance-in-each-component-of-a-graph/ @endlink
 * @copyright Copyright (c) 2022
 * @tags floyd-warshall
 */
/*
Given an adjacency matrix graph[][] of a weighted graph consisting of N nodes and positive weights, the task for each connected component of the graph is to find the maximum among all possible shortest distances between every pair of nodes.

Examples:

Input:



Output:

8 0 11 

Explanation: There are three components in the graph namely a, b, c. In component (a) the shortest paths are following:

The shortest distance between 3 and 4 is 5 units.
The shortest distance between 3 and 1 is 1+5=6 units.
The shortest distance between 3 and 5 is 5+3=8 units.
The shortest distance between 1 and 4 is 1 unit.
The shortest distance between 1 and 5 is 1+3=4 units.
The shortest distance between 4 and 5 is 3 units.
Out of these shortest distances:
The maximum shortest distance in component (a) is 8 units between node 3 and node 5.
Similarly, 
The maximum shortest distance in component (b) is 0 units.
The maximum shortest distance in component (c) is 11 units between nodes 2 and 6.

Input:



Output:

7 

Explanation: Since, there is only one component with 2 nodes having an edge between them of distance 7. Therefore, the answer will be 7.
*/

#include<iostream>
#include<vector>

using namespace std;
#define inf (int)(1e9)

void dfs(vector<vector<int>>& graph, int& N, vector<int>& visited, vector<int>& component, int curr){
    visited[curr] = 1;
    component.emplace_back(curr);

    for(int i=0; i<N; ++i){
        if(graph[curr][i] >= inf) continue;
        if(!visited[i]){
            dfs(graph, N, visited, component, i);
        }
    }
    return ;
}

void floydWarshall(vector<vector<int>>& graph, int& N){
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<N; ++k){
                if(i==k || j==k) continue;
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}

int maxInComponent(vector<vector<int>>& graph, vector<int>& component){
    int n = component.size();
    int maxDistance = -1e9;

    for(int i=0; i<component.size(); ++i){
        for(int j=0; j<component.size(); ++j){
            maxDistance = max(maxDistance, graph[component[i]][component[j]]);
        }
    }

    return maxDistance >= 1e9? 0: maxDistance;
}

vector<int> findMaxofMinDistances(vector<vector<int>>& graph, int& N){
    // finding the connected components first.
    vector<int> visited(N);
    vector<int> component;
    vector<vector<int>> connected;

    for(int i=0; i<N; ++i){
        if(!visited[i]){
            dfs(graph, N, visited, component, i);
            // dfs will fill the vector 'component' with connected nodes to ith node.
            // then we will push that component into vector 'connected' that maintains
            // all connected component nodes on seperate indices.
            connected.push_back(component);
            // erasing all the nodes in 'component' for new begining in the next iteration.
            component = vector<int>();
        }
    }

    floydWarshall(graph, N);

    int connSize = connected.size();
    vector<int> distances (connSize);

    // finding the max minimums for the components in the iteration.
    for(int i=0; i<connSize; ++i){
        distances[i] = maxInComponent(graph, connected[i]);
    }

    return distances;
}

int main(){
    int N = 8;
 
    // Adjacency Matrix for the first
    // graph in the examples
    vector<vector<int> > graph = {
        { 0, inf, 9, inf, inf, inf, 3, inf },
        { inf, 0, inf, 10, 1, 8, inf, inf },
        { 9, inf, 0, inf, inf, inf, 11, inf },
        { inf, 10, inf, 0, 5, 13, inf, inf },
        { inf, 1, inf, 5, 0, 3, inf, inf },
        { 8, inf, inf, 13, 3, 0, inf, inf },
        { 3, inf, 11, inf, inf, inf, 0, inf },
        { inf, inf, inf, inf, inf, inf, inf, 0 },
    };

    vector<int> maxDistances = findMaxofMinDistances(graph, N);

    for(int i: maxDistances) cout<< i << " ";
    return 0;
}