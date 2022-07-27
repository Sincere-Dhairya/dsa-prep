/**
 * @file Minimum amount to be spent to connect the tourist attractions.
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are the mayor of a very old city. The city has n major tourist attractions. You are given the locations (x, y, z) for each of these tourist attractions.

To boost the tourism in your city, you plan to create new roads that cocnnect the tourist attractions.

To create a bidirectional road between tourist attraction A(located at (x1, y1, z1)) and B(locaated at (x2, y2, z2)), you need to spend 
min (|x1-x2|, |y1-y2|, |z1-z2|) dollars. Here, |x1-x2| refers to the absolute value of x1- x2 and min(x, y, z) refers to the minimum value out of x, y, z.

You need to create a network of roads such that it is possible to travel between any pair of tourist attractions using some sequence of roads. What is the minimum amount of  dollars you need to spend in order to accomplish this task?

Input : n = 3, locations = {{1,5,7}, {2,9,4}, {1,3,9}}.
Output: 1
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calcDistance(vector<int>& v1, vector<int>& v2){
    return min(abs(v1[0] - v2[0]), min(abs(v1[1] - v2[1]), abs(v1[2]-v2[2])));
}

int getParent(vector<int>& parent, int n){
    if(parent[n] == n) return n;
    return parent[n] = getParent(parent, parent[n]);
}

bool unify(vector<int>& parent, vector<int>& rank, int u, int v){
    int pu = getParent(parent, u),
    pv = getParent(parent, v);
    
    if(pu == pv) return false;
    
    if(rank[pu] > rank[pv]){
        parent[pv] = pu;
        rank[pu] += rank[pv];
    }
    else{
        parent[pu] = pv;
        rank[pv] += rank[pu];
    }
    return 1;
}

int findMinCost(int& n, vector<vector<int>>& locations){
    vector<pair<int, pair<int, int>>> edges;
    
    for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            auto v1 = locations[i], v2 = locations[j];
            int dist = calcDistance(v1, v2);
            edges.push_back({dist, {i, j}});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    vector<int> parent(n+1), rank(n+1);
    for(int i = 0; i<n; ++i){
        parent[i] = i, rank[i] = 1;
    }
    
    int minCost = 0;
    for(auto e: edges){
        if(unify(parent, rank, e.second.first, e.second.second)){
            minCost += e.first;
        }
    }
    
    return minCost;
}

int main() {
	vector<vector<int>> locations = {
	    {1,5,7}, {2,9,4}, {1,3,9}
	};
	int n = 3;
	
	cout<< findMinCost(n, locations) <<endl;
	return 0;
}