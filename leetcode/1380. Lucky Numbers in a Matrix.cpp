/**
 * @file 1380. Lucky Numbers in a Matrix
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * @link https://leetcode.com/problems/lucky-numbers-in-a-matrix/ @endlink
 * @copyright Copyright (c) 2022
 * @tags arrays
 */
/*
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.
*/

// TC: O(NxN), SC: O(N).
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> row(matrix[0].size());
        vector<int> column (matrix.size());
        
        for(int i = 0; i<matrix.size(); ++i){
            int small = matrix[i][0];
            for(int j = 0; j<matrix[0].size(); ++j){
                small = min(small, matrix[i][j]);
            }
            column[i] = small;
        }
        
        for(int j= 0; j<matrix[0].size(); ++j){
            int bigg = matrix[0][j];
            for(int i = 0; i<matrix.size(); ++i){
                bigg = max(bigg, matrix[i][j]);
            }
            row[j] = bigg;
        }
        
        vector<int> ans;
        for(int i = 0; i<matrix.size(); ++i){
            for(int j = 0; j<matrix[0].size(); ++j){
                if(matrix[i][j] == row[j] && matrix[i][j] == column[i]){
                    ans.emplace_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};

// TC: O(NxN), SC: O(1).
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNums;
        
        for(int i = 0; i<matrix.size(); ++i){
            int minNum = matrix[i][0], ind = 0;
            for(int j = 0; j<matrix[i].size(); ++j){
                if(minNum > matrix[i][j]){
                    minNum = matrix[i][j];
                    ind = j;
                }
            }
            
            int maxNum = minNum;
            for(int j = 0; j<matrix.size(); ++j){
                if(maxNum < matrix[j][ind]){
                    maxNum = matrix[j][ind];
                    break;
                }
            }
            
            if(minNum == maxNum){
                luckyNums.emplace_back(minNum);
            }
        }
        
        return luckyNums;
    }
};