/**
 * @file Minimum Path Sum
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.
*/

#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>>& matrix, int n, int m, int i, int j){
    if(i>=n || j>=m){
        return INT_MAX;
    }
    if(i == n-1 && j == m-1){
        return matrix[i][j];
    }
    int cost1 = minCost(matrix, n, m, i, j+1), cost2 = minCost(matrix, n, m, i+1, j);
    int total = matrix[i][j] + min(cost1, cost2);
    return total;
}

int minCost(vector<vector<int>>& matrix){
    int n = matrix.size(), m = matrix[0].size();

    for(int i = n-2; i>=0; --i){
        matrix[i][m-1] += matrix[i+1][m-1];
    }
    for(int i = m-2; i>=0; --i){
        matrix[n-1][i] += matrix[n-1][i+1];
    }

    for(int i = n-2; i>=0; --i){
        for(int j = m-2; j>=0; --j){
            matrix[i][j] += min(matrix[i+1][j], matrix[i][j+1]);
        }
    }
    return matrix[0][0];
}

int main(){
    vector<vector<int>> matrix1 = {
        {5,9,6},
        {11,5,2}
    }, matrix2 = {
        {1,2,3},
        {4,5,4},
        {7,5,9}
    };
    // Recursion.
    int n = matrix1.size(), m = matrix1[0].size();
    cout<<minCost(matrix1, n, m, 0, 0)<<endl;
    cout<<minCost(matrix2, matrix2.size(), matrix2[0].size(), 0, 0)<<endl;

    // Tabulation.
    cout<<minCost(matrix1)<<endl;
    cout<<minCost(matrix2)<<endl;
    return 0;
}