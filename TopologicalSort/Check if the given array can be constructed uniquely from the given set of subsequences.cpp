/**
 * @file Check if the given array can be constructed uniquely from the given set of subsequences
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-16
 * @link https://www.geeksforgeeks.org/check-if-the-given-array-can-be-constructed-uniquely-from-the-given-set-of-subsequences/ @endlink
 * @copyright Copyright (c) 2022
 * @tags topological-sort
 */

/*
Given an array arr of distinct elements and a list of subsequences seqs of the array, the task is to check whether the given array can be uniquely constructed from the given set of subsequences.
Examples: 
 

Input : arr[] = {1, 2, 3, 4}, seqs[][] = {{1, 2}, {2, 3}, {3, 4}} 
Output: Yes 
Explanations: The sequences [1, 2], [2, 3], and [3, 4] can uniquely reconstruct 
the original array {1, 2, 3, 4}. 
Input: arr[] = {1, 2, 3, 4}, seqs[][] = {{1, 2}, {2, 3}, {2, 4}} 
Output: No 
Explanations : The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely reconstruct 
{1, 2, 3, 4}. There are two possible sequences that can be constructed from the given sequences: 
1) {1, 2, 3, 4} 
2) {1, 2, 4, 3} 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool checkForArray(vector<vector<int>>& sequence, vector<int> & arr){
    int index = arr.size()-1;

    vector<vector<int>> graph(5);
    vector<int> indegrees(5), ans;

    for(int i =0; i<sequence.size(); ++i){
        graph[sequence[i][0]].emplace_back(sequence[i][1]);
        ++indegrees[sequence[i][1]];
    }

    queue<int> q;
    for(int i =1; i<indegrees.size(); ++i){
        if(indegrees[i]==0){
            q.push(i);
        }
    }

    while(q.size()){
        if(q.size() > 1) return 0;

        int curr = q.front();
        q.pop();

        for(int child: graph[curr]){
            if(--indegrees[child] == 0){
                q.push(child);
            }
        }

        ans.emplace_back(curr);
    }

    for(int i: indegrees){
        if(i) return 0;
    }

    if(arr.size() != ans.size()){
        return 0;
    }

    for(int i = arr.size()-1, j = ans.size()-1; i>=0 && j >=0; --i, --j){
        if(arr[i] != ans[j]) return 0;
    }

    return 1;
}

int main(){
    vector<vector<int>> sequences = {
        {1,2}, {2,3}, {2,4}
    };
    vector<int> arr = {1,2,3,4};
    cout << checkForArray(sequences, arr) << endl;

    return 0;
}