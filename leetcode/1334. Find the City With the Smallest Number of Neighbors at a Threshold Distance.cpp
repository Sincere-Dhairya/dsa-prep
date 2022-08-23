/**
 * @file 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-23
 * @link https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/ @endlink
 * @copyright Copyright (c) 2022
 * @tags dijkestra
 */
/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:


Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
 

Constraints:

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct.
*/
// TC: O(Nx(N+M)) where N is no of nodes and M is no of edges.
// SC: O(N+M).
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        
        for(vector<int>& edge: edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int minNeighbours = 1e8, city = 0;
        for(int i = 0; i<n; ++i){
            vector<int> distance(n, 1e7);
            distance[i] = 0;
            queue<int> q;
            q.push(i);
            
            while(q.size()){
                int qSize = q.size();
                for(int j=0; j<qSize; ++j){
                    int curr = q.front();
                    q.pop();
                    for(auto ch: graph[curr]){
                        int child = ch.first, weight = ch.second;
                        if(distance[curr]+weight <= distanceThreshold &&
                            distance[curr]+weight < distance[child]
                          ){
                            distance[child] = distance[curr] + weight;
                            q.push(child);
                        }
                    }
                }
            }
            
            int count = 0;
            for(int d : distance){
                if(d <= distanceThreshold) ++count;
            }
            // cout << i << ":-> " << count << endl;
            if(minNeighbours > count){
                minNeighbours = count, city = i;
            }
            else if(minNeighbours == count){
                city = i;
            }
        }
        return city;
    }
};
