/**
 * @file 695. Max Area of Island
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * @link https://leetcode.com/problems/max-area-of-island/ @endlink
 * @copyright Copyright (c) 2022
 * @tags dfs
 */
/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/
// TC: O(NxN x 4^N), SC: O(NxN)
class Solution {
public:
    int areaByDFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
        if(i == grid.size() || j == grid[0].size() || i<0 || j<0 || visited[i][j] || grid[i][j] == 0) return 0;
        
        visited[i][j] = 1;
        
        int left = areaByDFS(grid, visited, i, j-1);
        int right = areaByDFS(grid, visited, i, j+1);
        int up = areaByDFS(grid, visited, i-1, j);
        int down = areaByDFS(grid, visited, i+1, j);
        
        int area = left+right+up+down+1;
        
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size()));
        int maxArea=0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                maxArea = max(maxArea, areaByDFS(grid, visited, i, j));
            }
        }
        return maxArea;
    }
};