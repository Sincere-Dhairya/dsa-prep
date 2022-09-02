/**
 * @file 79. Word Search
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * @link https://leetcode.com/problems/word-search/ @endlink
 * @copyright Copyright (c) 2022
 * @tags dfs backtracking
 */
/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

// TC: O(NxN ^4), SC: O(1).
class Solution {
public:
    bool searchUsingDFS(vector<vector<char>>& board, string & word, int x, int i, int j){
        if(i <0 || i == board.size() || j<0 || j== board[0].size() ){
            return 0;
        }
        if(x == word.size()) return 1;
        
        if(board[i][j] == word[x]){
            if(x == word.size()-1){
                return 1;
            }
            
            board[i][j] = '0';
            
            bool ans = searchUsingDFS( board, word, x+1, i, j+1) ||
                searchUsingDFS( board, word, x+1, i+1, j)||
                searchUsingDFS( board, word, x+1, i, j-1)||
                searchUsingDFS( board, word, x+1, i-1, j);
            
            board[i][j] = word[x];
            return ans;
        }
        return 0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for(int i=0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(board[i][j] != word[0]) continue;
                
                if(searchUsingDFS(board, word, 0, i, j)){
                    return 1;
                }
            }
        }
        return 0;
    }
};