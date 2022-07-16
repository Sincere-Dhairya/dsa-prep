/**
 * @file Find whether it is possible to finish all tasks or not from given dependencies
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-16
 * @link https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/ @endlink
 * @copyright Copyright (c) 2022
 * @tags topological-sort
 */
/*
There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisites, for example to pick task 0 you have to first pick task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks and a list of prerequisite pairs, is it possible for you to finish all tasks?
Examples:
 

Input: 2, [[1, 0]] 
Output: true 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0. So it is possible.
Input: 2, [[1, 0], [0, 1]] 
Output: false 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0, and to pick task 0 you should also have finished task 1. So it is impossible.
Input: 3, [[1, 0], [2, 1], [3, 2]] 
Output: true 
Explanation: There are a total of 3 tasks to pick. To pick tasks 1 you should have finished task 0, and to pick task 2 you should have finished task 1 and to pick task 3 you should have finished task 2. So it is possible.

Asked In: Google, Twitter, Amazon and many more companies.
*/

// TC: O(N). SC: O(N).

#include<bits/stdc++.h>
using namespace std;

bool canTasksComplete(vector<vector<int>>& tasksList, int& tasksToComplete){
    vector<vector<int>> graph(tasksToComplete+1);
    vector<int> indegrees(tasksToComplete+1);

    for(int i=0; i<tasksList.size(); ++i){
        graph[tasksList[i][1]].emplace_back(tasksList[i][0]);
        ++indegrees[tasksList[i][0]];
    }

    queue<int> q;
    for(int i=0; i<tasksToComplete+1; ++i){
        if(indegrees[i] == 0) q.push(i);
    }

    while(q.size()){
        int current_task = q.front();
        q.pop();

        for(int childTask : graph[current_task]){
            if(--indegrees[childTask] == 0){
                q.push(childTask);
            }
        }
    }

    for(int i = 0; i<=tasksToComplete; ++i){
        if(indegrees[i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    vector<vector<int>> tasksList = {{1, 0}, {0,1}};
    int tasksToComplete = 2;
    cout << canTasksComplete(tasksList, tasksToComplete)<<endl;

    return 0;
}