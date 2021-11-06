/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
//#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs_tracking(vector<vector<int>> grid, int x, int y, int zeros){
        // end cases.
        if(x<0 || y<0 || x==grid.size() || y == grid[0].size() || zeros <-1 || grid[x][y] == -1) return 0;
        if(grid[x][y] == 2) return (zeros==-1)? 1: 0;

        // the function operation
        --zeros;
        grid[x][y] = -1;
        int pathnos = dfs_tracking(grid, x-1, y, zeros) +
                        dfs_tracking(grid, x+1, y, zeros) +
                        dfs_tracking(grid, x, y-1, zeros) +
                        dfs_tracking(grid, x, y+1, zeros);
        
        return pathnos;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
       int zeros = 0; // for counting number of zeroes.
       int sr, sc;

       for(int i = 0; i<grid.size(); i++){
           for(int j =0; j<grid[0].size(); j++){
               if(grid[i][j] == 0) ++zeros;
               if(grid[i][j] == 1) sr = i, sy = j;
           }
       }
       
       int count = dfs_tracking(grid, sr, sc, zeroes);
       return count;
    }
};
// @lc code=end

