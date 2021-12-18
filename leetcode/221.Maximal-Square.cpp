/**
 * @file 221. Maximal Square
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/

// O(N^2) approach using dynamic programming

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), square = 0;
        vector<vector<int> > area(n, vector<int> (m, 0));
        
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){
                if(!i or !j or matrix[i][j] == '0')
                    area[i][j] = matrix[i][j] - '0';
                else
                    area[i][j] = min(min(area[i-1][j], area[i][j-1]), area[i-1][j-1])+1;
                square = max(square, area[i][j]);
            }
        return square*square;
    }
};

