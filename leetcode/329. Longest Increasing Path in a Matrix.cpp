/**
 * @file 329. Longest Increasing Path in a Matrix
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-19
 * @link https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 2^31 - 1
*/

// TC: O(N^3) SC: O(N^2)
class Solution {
public:
    int DFSforPath(vector<vector<int>>& cache, vector<vector<int>>& matrix, int& n, int& m, int i, int j){
        //cout<<i<<" "<<j<<endl;
        if(i==n || i<0 || j==m || j<0) return 0;
        if(cache[i][j] > -1) return cache[i][j];
        int left = 0, right = 0, top = 0, bottom = 0;
        // left
        if(j>0 && matrix[i][j] > matrix[i][j-1])
            left = DFSforPath(cache, matrix, n, m, i, j-1);
        //cout<<i<<" "<<j<<endl;
        //right
        if(j <m-1 && matrix[i][j] > matrix[i][j+1])
            right = DFSforPath(cache, matrix, n, m, i, j+1);
        //cout<<i<<" "<<j<<endl;
        // top
        if(i>0 && matrix[i][j] > matrix[i-1][j])
            top = DFSforPath(cache, matrix, n, m, i-1, j);
        //cout<<i<<" "<<j<<endl;
        //bottom
        if(i<n-1 && matrix[i][j] > matrix[i+1][j])
            bottom = DFSforPath(cache, matrix, n, m, i+1, j);
        //cout<<i<<" "<<j<<endl;
        return cache[i][j] = 1 + max(left, max(right, max(top, bottom)));
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> cache(201, vector<int>(201, -1));
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                //cout<<i<<" "<<j<<endl;
                ans = max(ans, DFSforPath(cache, matrix, n, m, i, j));
            }
        }
        return ans;
    }
};
/*
[[7,7,5],[2,4,6],[8,2,0]]
*/