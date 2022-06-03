 /**
 * @file 304. Range Sum Query 2D - Immutable
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-03
 * @link https://leetcode.com/problems/range-sum-query-2d-immutable/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 

Example 1:


Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-105 <= matrix[i][j] <= 105
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 104 calls will be made to sumRegion.
*/

// Prefix Sum.
// O(N).
class NumMatrix {
public:
    vector<vector<int>> table;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        table = vector<vector<int>> (n, vector<int> (m,0));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                table[i][j] = matrix[i][j];
                if(j)
                    table[i][j] += table[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(row1; row1<= row2; ++row1){
            sum += col1?table[row1][col2]-table[row1][col1-1]: table[row1][col2];
        }
        return sum;
    }
};

// Dynamic Programming.
// O(1).
class NumMatrix {
public:
    vector<vector<long>> table;
    int n=0, m=0;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size()+1, m = matrix[0].size()+1;
        table = vector<vector<long>>(n, vector<long>(m));
        for(int i=1; i<n; ++i){
            for(int j=1; j<m; ++j){
                table[i][j] = matrix[i-1][j-1]+table[i-1][j]+table[i][j-1]-table[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int area1 = table[row2+1][col2+1], area2 = table[row1][col2+1], 
        area3 = table[row2+1][col1], area4= table[row1][col1];
        return area1 - area2 - area3 + area4;
    }
};