/**
 * @file Minimum work to be done per day to finish given tasks within D days
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * @link https://www.geeksforgeeks.org/minimum-work-to-be-done-per-day-to-finish-given-tasks-within-d-days/ @endlink
 * @copyright Copyright (c) 2022
 * @tags binary-search
 */
/*
Given an array task[] of size N denoting amount of work to be done for each task, the problem is to find the minimum amount of work to be done on each day so that all the tasks can be completed in at most D days.

Note: On one day work can be done for only one task.

Examples:

Input: task[] = [3, 4, 7, 15],  D = 10
Output: 4
Explanation:  Here minimum work to be done is 4.
On 1st day, task[0] = 3 < 4 so this task can only be completed. Because work can be done for only one task on one day.
For task[1] = 4 the task can be completed in 1 day.
Task[2] = 7. Now 4 amount of work can be done in 1 day so to complete this task 2 days are required.
Task[3] = 15, 4 additional days are required.
Total number of days required = 1 + 1 + 2 + 4 = 8 days < D. 
So 4 value would be the minimum value.

Input: task[] = [30, 20, 22, 4, 21], D = 6
Output: 22
*/

#include<bits/stdc++.h>
using namespace std;

bool workIsComplete(vector<int> & work, int& time, int& workUnit){
    int counter = 0;
    for(int i = 0; i<work.size(); ++i){
        counter += ceil((float)(work[i])/(float)(workUnit));
        if(counter > time) return 0;
    }
    return counter<=time;
}

int minTask(vector<int> & work, int& time){
    int high = *max_element(work.begin(), work.end()), low = 0, ans = INT_MAX;

    while(high >= low){
        int mid = (high+low)/2;
        if(workIsComplete(work, time, mid)){
            ans= min(ans, mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    // vector<int> work = {3,4,7,15};
    // int D = 10;
    vector<int> work = {30, 20, 22, 4, 21};
    int D =6;
    cout<<minTask(work, D);
    
    string name = "Minimum work to be done per day to finish given tasks within D days";

    for(char &c: name){
        if(c == ' ') c='-';
    }
    cout<<name<<endl;
    return 0;
}