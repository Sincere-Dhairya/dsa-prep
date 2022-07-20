/**
 * @file Minimum cost required to connect all houses in a city
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-20
 * @link https://www.geeksforgeeks.org/minimum-cost-required-to-connect-all-houses-in-a-city/ @endlink
 * @copyright Copyright (c) 2022
 * @tags mst
 */
/*
Given a 2D array houses[][] consisting of N 2D coordinates {x, y} where each coordinate represents the location of each house, the task is to find the minimum cost to connect all the houses of the city.

Cost of connecting two houses is the Manhattan Distance between the two points (xi, yi) and (xj, yj) i.e., |xi – xj| + |yi – yj|, where |p| denotes the absolute value of p.

Examples:

Input: houses[][] = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
Output: 20
Explanation:



Connect house 1 (0, 0) with house 2 (2, 2) with cost = 4
Connect house 2 (2, 2) with house 3 (3, 10) with cost =9 
Connect house 2 (2, 2) with house 4 (5, 2) with cost =3 
At last, connect house 4 (5, 2) with house 5 (7, 0) with cost 4.
All the houses are connected now.
The overall minimum cost is 4 + 9 + 3 + 4 = 20.

Input: houses[][] = [[3, 12], [-2, 5], [-4, 1]]
Output: 18
Explanation:
Connect house 1 (3, 12) with house 2 (-2, 5) with cost = 12
Connect house 2 (-2, 5) with house 3 (-4, 1) with cost = 6
All the houses are connected now.
The overall minimum cost is 12 + 6 = 18.
*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int mhDistance(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int getParent(vector<int> & parents, int& n){
    if(n == parents[n]) return n;
    return parents[n] = getParent(parents, parents[n]);
}

int unify(vector<int>& parents, vector<int>& rank, int u, int v){
    u = getParent(parents, u),
    v = getParent(parents, v);
    
    if(u == v) return 0;
    
    if(rank[u] < rank[v]) swap(u, v);
    
    rank[u] += rank[v];
    parents[v] = u;
    return 1;
}

int minCostMST(vector<vector<int>>& houses, int&N){
    vector<pair<int, pair<int, int>>> edges;
    
    // creating the graph. O(nxn)
    for(int i=0; i<N; ++i){
        for(int j = i+1; j<N; ++j){
            int dist = mhDistance(houses[i][0], houses[i][1], houses[j][0], houses[j][1]);
            edges.push_back({dist, {i, j}});
        }
    }
    
    sort(edges.begin(), edges.end()); // o nlogn
    
    vector<int> parents(N+1, 0), rank(N+1, 0);
    for(int i = 0; i<=N; ++i){
        parents[i] = i, rank[i] = 1;
    }
    
    int cost = 0;
    for(int i=0; i<edges.size(); ++i){ // o(nxn)
        if(unify(parents, rank, edges[i].second.first, edges[i].second.second)){
            cost += edges[i].first;
        }
    }
    return cost;
}

int main(){
    vector<vector<int>> houses = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    int N = houses.size();

    cout<<minCostMST(houses, N)<<endl;
    return 0;
}