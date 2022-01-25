/**
 * @file 240. Search a 2D Matrix II
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-25
 * @link https://leetcode.com/problems/search-a-2d-matrix-ii/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
*/

// O(m+n) time complexity.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), col = n-1, row = 0;
        while(row<m and col>= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col]>target){
                --col;
            }
            else {
                ++row;
            }
        }
        cout<<row<<endl;
        return false;
    }
};