/**
 * @file Minimum-time-to-complete-at-least-K-tasks-when-everyone-rest-after-each-task
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * @link https://www.geeksforgeeks.org/minimum-time-to-complete-at-least-k-tasks-when-everyone-rest-after-each-task/ @endlink
 * @copyright Copyright (c) 2022
 * @tags binary-search
 */
/*
Given an array arr[] of size N representing the time taken by a person to complete a task. Also, an array restTime[] which denotes the amount of time one person takes to rest after finishing a task. Each person is independent of others i.e. they can work simultaneously on different task at the same time. Given an integer K, the task is to find at least how much time will be taken to complete all the K tasks by all the persons.

Examples:

Input: arr[] = {1, 2, 4}, restTime[] = {1, 2, 2}, K = 5
Output: 5
Explanation: At t = 1, tasks task done = [1, 0, 0], Total task = 1
At t = 2, No of tasks completed = [1, 1, 0],  
Total task = 1 + 1 = 2. Because 1st person was taking rest
At t = 3, No of tasks completed = [2, 1, 0],  
Total task = 2 + 1 = 3, Because 2nd person was taking rest
At t = 4, No of tasks completed = [2, 1, 1],  
Total task = 2 + 1 + 1 = 4, Because 1st and 2nd person was taking rest
At t = 5, No of tasks completed = [3, 1, 1]. 
Total task = 3 + 1 + 1 = 5. Minimum time taken = 5.

Input: arr[] = {1, 2, 4, 7, 8}, restTime[] = {4, 1, 2, 3, 1}, TotalTask = 2
Output: 2
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool checkLeastTime(vector<int>& work, vector<int>& rest, int& time, int & k){
    int count = 0;
    for(int i = 0; i<work.size(); ++i){
        int addedTime = (work[i]+rest[i]); 
        count += (time/ addedTime);
        count += (time% addedTime >= work[i])? 1: 0;
        if(count >= k) return 1;
    }
    return 0;
}

int minTimePossible(vector<int>& work, vector<int>& rest, int& k){
    int maxTime= 0;

    for(int i = 0; i<work.size(); ++i){
        maxTime = max(maxTime, k*(work[i]+rest[i]));
    }

    int minTime = 0, ans = INT_MAX;

    while(maxTime >= minTime){
        int midTime = (maxTime+minTime)/2;

        if(checkLeastTime(work, rest, midTime, k)){
            ans=min(ans, midTime);
            maxTime = midTime-1;
        }
        else{
            minTime = midTime+1;
        }
    }
    return ans;
}

int main(){
    vector<int> work = {1,2,4}, rest = {1,2,2};
    int k =5;
    cout<<minTimePossible(work, rest, k);
    return 0;
}