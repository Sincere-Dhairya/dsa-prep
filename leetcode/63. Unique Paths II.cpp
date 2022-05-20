/**
 * @file 63. Unique Paths II
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-20
 * @link https://leetcode.com/problems/unique-paths-ii/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

// DP approach Tabulation. TC: O(N^2). No extra space.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        if(grid[n-1][m-1] || grid[0][0]){
            return 0;
        }
        grid[n-1][m-1] = 1;
        for(int i = n-2; i>=0; --i){
            if(grid[i][m-1]){
                grid[i][m-1] = 0;
            }
            else{
                grid[i][m-1] = grid[i+1][m-1];
            }
        }
        for(int i = m-2; i>=0; --i){
            if(grid[n-1][i]){
                grid[n-1][i] = 0;
            }
            else{
                grid[n-1][i] = grid[n-1][i+1];
            }
        }
        
        for(int i = n-2; i>=0; --i){
            for(int j = m-2; j>=0; --j){
                if(grid[i][j]){
                    grid[i][j] = 0;
                }
                else{
                    grid[i][j] = (int)( (long)grid[i+1][j] + (long)grid[i][j+1] );
                }
            }
        }
        
        return grid[0][0];
    }
};