/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int n1 = matrix.size(), n2 = matrix[0].size();
        for(int i = 0; i<n1; i++){
            for(int j = i+1; j<n2; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end

