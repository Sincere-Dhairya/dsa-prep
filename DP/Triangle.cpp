/**
 * @file Triangle
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * @link https://www.codingninjas.com/codestudio/problems/triangle_1229398 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given a triangular array/list 'TRIANGLE'. Your task is to return the 
minimum path sum to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0 <= i < N will 
have i + 1 elements.
You can move only to the adjacent number of row below each step. For example, 
if you are at index j in row i, then you can move to i or i + 1 index in 
row j + 1 in each step.
*/
#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& triangle, int n, int i, int j){
    if(i >= n || j > i){
        return 0;
    }
    if(i == n-1){
        return triangle[i][j];
    }
    int cost1 = minPathSum(triangle, n, i+1, j),
    cost2 = minPathSum(triangle, n, i+1, j+1);
    return triangle[i][j] + min(cost1, cost2);
}

int minPathSum(vector<vector<int>>& triangle){
    int n = triangle.size();

    for(int i = n-2; i>=0; --i){
        int m = triangle[i].end()-triangle[i].begin();
        for(int j = i; j>=0; --j){
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}

int main(){
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    // Recursion.
    cout<<minPathSum(triangle, triangle.size(), 0, 0)<<endl;

    // Tabulation.
    cout<<minPathSum(triangle)<<endl;
    return 0;
}