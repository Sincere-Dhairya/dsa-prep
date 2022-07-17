/**
 * @file Minimum cost of path between given nodes containing at most K nodes in a directed and weighted graph
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-17
 * @link https://www.geeksforgeeks.org/minimum-cost-of-path-between-given-nodes-containing-at-most-k-nodes-in-a-directed-and-weighted-graph/ @endlink
 * @copyright Copyright (c) 2022
 * @tags dijkestra
 */
/*
Given a directed weighted graph represented by a 2-D array graph[][] of size n and 3 integers src, dst, and k representing the source point, destination point, and the available number of stops. The task is to minimize the cost of the path between two nodes containing at most K nodes in a directed and weighted graph. If there is no such route, return -1.

Examples:

Input: n=6, graph[][] = [[0, 1, 10], [1, 2, 20], [1, 3, 10], [2, 5, 30], [3, 4, 10], [4, 5, 10]], src=0, dst=5, k=2
Output: 60
Explanation:


Src = 0, Dst = 5 and k = 2

There can be a route marked with a green arrow that takes cost =  10+10+10+10=40 using three stops. And route marked with red arrow takes cost = 10+20+30=60 using two stops. But since there can be at most 2 stops, the answer will be 60.

Input: n=3, graph[][] = [[0, 1, 10], [0, 2, 50], [1, 2, 10], src=0, dst=2, k=1
Output:  20
Explanation:


Src=0 and Dst=2

Since the k is 1, then the green-colored path can be taken with a minimum cost of 20.
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int minDistanceToDestination(int N, vector<vector<int>>& list, int src, int dst, int k){
    vector<vector<pair<int, int>>> graph(N+1);
    vector<int> minDistance(N+1, -1);

    for(int i=0; i<list.size(); ++i){
        graph[list[i][0]].push_back({list[i][1], list[i][2]});
    }

    queue<pair<int, int>> q;
    q.push({src, 0});
    minDistance[src] = 0;
    ++k;

    while(k){
        int n = q.size();
        if(!k) break;
        for(int i=0; i<n; ++i){
            int curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(pair<int, int> child : graph[curr]){
                int child_node = child.first;
                int child_dist = child.second;

                if(minDistance[child_node] == -1 || minDistance[child_node] > dist + child_dist){
                    minDistance[child_node] = dist+child_dist;
                    q.push({child_node, minDistance[child_node]});
                }
            }
        }
        --k;
    }

    return minDistance[dst];
}

int main(){
    // vector<vector<int>> graph = {{0,1,10}, {1,2,20}, {2,5,30}, {1,3,10}, {3,4,10}, {4,5,10}};
    // int src = 0, dst = 5, k = 2;
    vector<vector<int>> graph = {{0,1,10}, {0,2,50}, {1,2,10}};
    int src = 0, dst = 2, k = 1;
    cout << minDistanceToDestination(2, graph, src, dst, k);
    return 0;
}
// [[0, 1, 10], [0, 2, 50], [1, 2, 10], src=0, dst=2, k=1