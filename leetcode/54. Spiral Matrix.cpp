/**
 * @file 54. Spiral Matrix
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * @link https://leetcode.com/problems/spiral-matrix/ @endlink
 * @copyright Copyright (c) 2022
 * @tags arrays
 */
/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

// TC: O(NxM), SC: O(1).
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rows(n), columns(m);
        bool rowChance = 1, colChance = 0, reverseRow = 0, reverseCol = 0;
        int i = 0, j = 0;
        
        while(1){
            if(rowChance){
                rows[i] = 1;
                if(reverseRow){ 
                    for(; j>=0 and columns[j] != 1; --j)
                        ans.emplace_back(matrix[i][j]);
                    ++j, --i;
                }
                else{ 
                    for(; j<m and columns[j] != 1; ++j)
                        ans.emplace_back(matrix[i][j]);
                    --j, ++i;
                }
                if(columns[j]){
                    return ans;
                }
                rowChance = 0, colChance = 1, 
                reverseRow = !reverseRow;
            }
            if(colChance){
                columns[j] = 1;
                if(reverseCol){
                    for(; i>=0 and rows[i] != 1; --i)
                        ans.emplace_back(matrix[i][j]);
                    ++i, ++j;
                }
                else {
                    for(; i<n and rows[i] != 1; ++i)
                        ans.emplace_back(matrix[i][j]);
                    --i, --j;
                }
                if(rows[i]){
                    return ans;
                }
                rowChance = 1, colChance = 0,
                reverseCol = !reverseCol;
            }
        }
        return {};
    }
};