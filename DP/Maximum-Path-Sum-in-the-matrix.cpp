/**
 * @file Maximum Path Sum in the matrix
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * @link https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998
 * @copyright Copyright (c) 2022
 * 
 */
/*
You have been given an N*M matrix filled with integer numbers, find the maximum sum 
that can be obtained from a path starting from any cell in the first row to any cell 
in the last row.
From a cell in a row, you can move to another cell directly below that row, or 
diagonally below left or right. So from a particular cell (row, col), we can move in 
three directions i.e.
Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)
*/

#include<bits/stdc++.h>
using namespace std;

int maxPathSum(vector<vector<int>>& matrix, int i, int j){
    //cout<<i<<" "<<j<<endl;
    if(i <0 || j <0 || i >= matrix.size() || j >= matrix[0].size()){
        return 0;
    }
    int count1 = maxPathSum(matrix, i+1, j),
    count2 = maxPathSum(matrix, i+1, j-1),
    count3 = maxPathSum(matrix, i+1, j+1);
    return matrix[i][j] + max(count1, max(count2, count3));
}

int maxPathSum(vector<vector<int>>& matrix){
    int n = matrix.size(), m = matrix[0].size(), ans = 0;
    
    for(int i = n-2; i>=0; --i){
        for(int j = 0; j<m; ++j){
            if(j == 0){
                matrix[i][j] += max(matrix[i+1][j], matrix[i+1][j+1]);
            }
            else if( j == m-1){
                matrix[i][j] += max(matrix[i+1][j-1], matrix[i+1][j]);
            }
            else{
                matrix[i][j] += max(matrix[i+1][j], max(matrix[i+1][j-1], matrix[i+1][j+1]));
            }
            if(!i){
                ans = max(ans, matrix[i][j]);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix1 = {
        {1,2,10,4},
        {100,3,2,1},
        {1,1,20,2},
        {1,2,2,1}
    }, matrix2 = {
        {10,2,3},
        {3,7,2},
        {8,1,5}
    };

    // Recursion.
    int ans = 0;
    for(int i = 0; i<matrix1[0].size(); ++i){
        ans = max(ans, maxPathSum(matrix1, 0, i));
    }
    cout<<ans<<endl;
    ans = 0;
    for(int i = 0; i<matrix2[0].size(); ++i){
        ans = max(ans, maxPathSum(matrix2, 0, i));
    }
    cout<<ans<<endl;

    // Tabulation.
    cout<<maxPathSum(matrix1)<<endl;
    cout<<maxPathSum(matrix2)<<endl;
    return 0;
}