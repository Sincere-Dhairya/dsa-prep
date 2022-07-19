/**
 * @file Number of distinct Shortest Paths from Node 1 to N in a Weighted and Directed Graph
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-19
 * @link https://www.geeksforgeeks.org/number-of-distinct-shortest-paths-from-node-1-to-n-in-a-weighted-and-directed-graph/ @endlink
 * @copyright Copyright (c) 2022
 * @tags Dijkestra
 */
/*
Given a directed and weighted graph of N nodes and M edges, the task is to count the number of shortest length paths between node 1 to N.

Examples:

Input: N = 4, M = 5, edges = {{1, 4, 5}, {1, 2, 4}, {2, 4, 5}, {1, 3, 2}, {3, 4, 3}}
Output: 2
Explanation: The number of shortest path from node 1 to node 4 is 2, having cost 5.



Input: N = 3, M = 2, edges = {{1, 2, 4}, {1, 3, 5}}
Output: 1
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define MAX_DIST (int)(1e9)

int numOfDistinctShortestPaths(vector<vector<int>>& edges, int N, int M){
    // DEFINING THE GRAPH WITH N NODES.
    vector<vector<pair<int, int>>> graph(N+1);
    // DEFINING THE DISTANCES VECTOR WITH 'MAX_DIST' VALUE.
    vector<int> distances(N+1, MAX_DIST);

    // CONSTRUCTING THE GRAPH WITH THE HELP OF EDGES.
    for(int i=0; i<edges.size(); ++i){
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    const int SOURCE = 1,    // SOURCE NODE.
    TARGET = N,     // TARGET NODE.
    SOURCE_DISTANCE = 0;    // DISTANCE OF SOURCE NODE.

    int distance = MAX_DIST, count = 1; // SETTING PATH DISTANCE AND PATH COUNT FOR THE TARGET NODE.

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // DEFINING MIN_HEAP FOR GREEDY APPROACH TO THE PROBLEM.
    q.push({SOURCE_DISTANCE, SOURCE}); // PUSHING THE SOURCE DISTANCE AND SOURCE NODE.
    distances[SOURCE] = 0;

    while(q.size()){
        // ACCESSING THE CURRENT NODE.
        int curr = q.top().second;
        int dist = q.top().first;
        q.pop();

        for(pair<int, int> adj : graph[curr]){
            // ACCESSING THE ADJACENT NODES OF THE CURRENT NODE.
            int adj_node = adj.first;
            int adj_dist = adj.second; 

            // COMPARING THE DISTANCE OF ADJACENT NODE SAVED IN DISTANCES VECTOR WITH THE DISTANCE FROM THE SOURCE NODE.
            if(dist + adj_dist <= distances[adj_node]){
                bool equals = false; // THIS BOOLEAN HELPS US TO RESTRICT PUSHING THE NODE WHOSE DISTANCE DOES NOT CHANGE WITH RESPECT TO THE DISTANCES VECTOR.
                if(dist + adj_dist == distances[adj_node]) 
                    equals = true; // BOOLEAN SET TRUE WHEN THE DISTANCE DOES NOT CHANGE FROM THE SOURCE NODE.

                distances[adj_node] = dist+adj_dist; // ASSIGING THE NEW VALUE TO DISTANCES VECTOR AT INDEX = NODE.
                
                if(adj_node == TARGET){ // CHECK IF THE CURRENT ADJACENT NODE IS TARGET NODE.
                    if(distances[adj_node] == distance) ++count; // INCREAMENT THE COUNT IF THE DISTANCE IS NOT DECREASING THIS TIME.
                    else if(distances[adj_node] < distance){  // OTHERWISE SET RESET THE COUNT TO 1 AFTER CHANGING THE DISTANCE.
                        distance = distances[adj_node];
                        count = 1;
                    }
                }
                if(!equals) // THE BOOLEAN NOW CONTROLS THE PUSHING OF THE DISTANCE, NODE PAIR INTO THE MIN_HEAP.
                    q.push({distances[adj_node], adj_node}); 
            }
        }

    }
    // RETURNING THE COUNT.
    return count;
}

int main(){
    vector<vector<int>> edges = {{1, 4, 5}, {1, 2, 4}, {2, 4, 5}, {1, 3, 2}, {3, 4, 3}}; // LIST OF EDGES.
    int N = 4, M = 5; // NO OF NODES AND EDGES.
    cout<< numOfDistinctShortestPaths(edges, N, M) <<endl; // FUNCTION CALL AND PRINTING THE RESPONSE.

    return 0;

}