/**
 * @file Generate lexicographically smallest Permutation of 1 to N where elements follow given relation
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * @link https://www.geeksforgeeks.org/generate-lexicographically-smallest-permutation-of-1-to-n-where-elements-follow-given-relation/ @endlink
 * @copyright Copyright (c) 2022
 * @tags topological-sort
 */
/*
Given an integer N and an array arr[] of M pairs of type (Ai, Bi), the task is to generate the lexicographically smallest possible permutation of 1 to N such that every Ai, occurs before every Bi.

Examples:

Input: N = 4, arr[] = { {2, 1}, {3, 4}, {2, 4} }
Output: 2 1 3 4
Explanation: The following five permutations P satisfy the condition: 
(2, 1, 3, 4), (2, 3, 1, 4), (2, 3, 4, 1), (3, 2, 1, 4), (3, 2, 4, 1). 
The lexicographically smallest among them is (2, 1, 3, 4).

Input: N = 2, arr[] = { {2, 1} }
Output: 2 1
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> LSPM(vector<vector<int>> & arr, int N){
    vector<vector<int> > graph(N+1);
    vector<int> indegrees(N+1);

    for(int i = 0; i<arr.size(); ++i){
        graph[arr[i][0]].emplace_back(arr[i][1]);
        ++indegrees[arr[i][1]];
    }

    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 1; i<indegrees.size(); ++i){
        if(indegrees[i] == 0)
            q.push(i);
    }

    while(q.size()){
        int curr = q.top();
        q.pop();

        for(int child: graph[curr]){
            if(--indegrees[child] == 0){
                q.push(child);
            }
        }
        ans.emplace_back(curr);
    }

    return ans;
}

int main(){
    vector<vector<int> > arr = { {2, 1}, {3, 4}, {2, 4} };
    int N = 4;
    vector<int> ans = LSPM(arr, N);

    for(int i: ans) cout<< i << " ";
    cout<<endl;
    return 0;

}