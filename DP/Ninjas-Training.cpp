/**
 * @file Ninja's Training
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
We have a Ninja, who performs any of the 3 tasks a day. Points to each task on ith day are given
in a 2D matrix. The task performed on ith day can't be performed on i+1 th day.
Find the maximum points the Nija can earn at the end of the schedule.
*/
// Again Greedy methods will fail. Hence, we have to try out all the possible ways and take out 
// the best possible ans.

#include<bits/stdc++.h>
using namespace std;

int maxPointsByNinja(vector<vector<int>>& points, int prev, int i){
    if(i >= points.size()){
        return 0;
    }
    
    int col = points[i].size(), maxscore = 0;
    for(int j = 0; j<col; ++j){
        if(j != prev){
            maxscore = max(
                maxscore, 
                points[i][j]+maxPointsByNinja(points, j, i+1)
            );
        }
    }
    return maxscore;
}

int maxPointsByNinja(vector<vector<int>>& schedule, vector<vector<int>>& table, int i, int prev){
    if(i >= schedule.size()){
        return 0;
    }
    if(table[i][prev]){
        return table[i][prev];
    }

    int col = schedule[i].size(), maxscore = 0;
    for(int j = 0; j<col; ++j){
        if(j != prev){
            maxscore = max(
                maxscore,
                schedule[i][j]+maxPointsByNinja(schedule, table, i+1, j)
            );
        }
    }
    return table[i][prev] = maxscore;
}

int maxPointsByNinja(vector<vector<int> >& schedule){
    int n = schedule.size(), col = schedule[0].size();
    vector<vector<int>> table(n, vector<int> (col, 0));
    for(int i = 0; i<col; i++){
        int maxpoints = 0;
        for(int j = 0; j<col; ++j){
            if(i != j){
                maxpoints = max( maxpoints, schedule[n-1][j] );
            }
        }
        table[n-1][i] = maxpoints;
    }

    for(int i = n-2; i>=0; --i){
        for(int j = 0; j<col; ++j){
            int maxpoints = 0;
            for(int k = 0; k<col; ++k){
                if(j != k){
                    maxpoints = max(
                        maxpoints,
                        schedule[i][k] + table[i+1][k]
                    );
                }
            }
            table[i][j] = maxpoints;
        }
    }

    int ans = 0;
    for(int i =0; i<col; ++i){
        ans = max(ans, table[0][i]);
    }
    return ans;
}

int main(){
    vector<vector<int>> pointstable = {
        {10, 50, 12},
        {12, 13, 12},
        {25, 60, 23},
        {50, 11, 100}
    }, points2 = {
        {1, 2, 5}, 
        {3, 1, 1},
        {3, 3, 3}
    }, points3 = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    cout<<maxPointsByNinja(pointstable, 3, 0)<<endl;
    cout<<maxPointsByNinja(points2, 3, 0)<<endl;
    cout<<maxPointsByNinja(points3, 3, 0)<<endl;

    // Memoization
    vector<vector<int>> table(4, vector<int>(4, 0));
    cout<<maxPointsByNinja(pointstable, table, 0, 3)<<endl;

    // Tabulation
    cout<<maxPointsByNinja(pointstable)<<endl;
    return 0;
}