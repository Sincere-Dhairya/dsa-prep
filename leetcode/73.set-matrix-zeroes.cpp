/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool fr = false, fc = false;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if(i == 0) fr = 1;
                    if(j == 0) fc = 1;
                }
            }
        }

        for(int i= 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][0] == 0) matrix[i][j] = 0;
                if(matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        if(fr){
            for(int j = 0; j<m; j++) matrix[0][j] = 0;
        }

        if(fc) {
            for(int i = 0; i<n; i++) matrix[i][0] = 0;
        }
    }
};
// @lc code=end

