/**
 * @file Check if given Arrays have a Unique Shortest Common Super-sequence
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * @link https://www.geeksforgeeks.org/check-if-given-arrays-have-a-unique-shortest-common-super-sequence/ @endlink
 * @copyright Copyright (c) 2022
 * @tags topological-sort
 */
/*
Given a 2D array arr[][] of size N*M which denotes N arrays, each of size M. The task is to check if all these arrays have a unique common supersequence.

Examples:

Input: N = 2, M = 2, arr[][] = { { 1, 2 }, {1, 3 } }
Output: False
Explanation: There are two possible supersequence: {1, 3, 2 } and {1, 2, 3}.

Input: N = 3, M = 2, arr[][] = { { 1, 2 }, {1, 3}, {2, 3 } }
Output: True
Explanation: { 1, 2, 3 } is the only shortest common supersequence of {1, 2}, {1, 3} and {2, 3}.
*/

// THE KEY HERE IS THAT FOR THE GIVEN GRAPH, THERE SHOULD EXIST ONLY ONE TOPOLOGICALLY SORTED SEQUENCE, IF THE NUMBER OF TOPOLOGICALLY SORTED SEQUENCE EXCEEDS 1, THEN THERE WILL NOT BE A UNIQUE COMMON SUPERSEQUENCE HAVING ALL NODES AND EDGES.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool checkForSupesequence(vector<vector<int>>& arr, int & n, int & m){
    vector<vector<int>> graph(n+m);
    vector<int> indegrees(n+m);

    for(int i=0; i<arr.size(); ++i){
        graph[arr[i][0]].emplace_back(arr[i][1]);
        ++indegrees[arr[i][1]];
    }

    queue<int> q;

    for(int i = 1; i<indegrees.size(); ++i){
        if(indegrees[i] == 0) q.push(i);
    }

    // NO NEED TO DECLARE THE ARRAY AND SAVE THE SORTING SEQUENCE AS WE ONLY NEED TO CHECK IF THE SIZE OF THE QUEUE AT ANY TIME IS NOT GREATER THAN 1.
    while(q.size()){
        if(q.size() > 1) return 0;

        int curr = q.front();
        q.pop();

        for(int child: graph[curr]){
            if(--indegrees[child] == 0){
                q.push(child);
            }
        }
    }

    // IF INDEGREE OF ANY VERTEX IS NOT ZERO, THEN WE DONT HAVE UNIQUE SUPERSEQUENCE IN COMMON.
    // THIS CASE IS FOR CYCLIC GRAPHS WHERE THE CASE IS POSSIBLE THAT EVERY TIME ONLY ONE ELEMENT IS PUSHED INTO THE QUEUE AND IT EXITS THE LOOP FOR SIZE == 0.
    for(int i = 0; i<indegrees.size(); ++i){
        if(indegrees[i] != 0) return 0;
    }

    return 1;
}

int main(){
    vector<vector<int>> arr = {{1,2}, {1,3}};
    int N = 2, M = 2;
    cout<< checkForSupesequence(arr, N, M)<<endl;
    return 0;
}