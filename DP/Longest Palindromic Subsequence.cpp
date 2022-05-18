/**
 * @file Longest Palindromic Subsequence
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-18
 * @link https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1/# @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a String, find the longest palindromic subsequence.


Example 1:

Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.
Example 2:

Input: 
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.


Expected Time Complexity: O(|S|*|S|).
Expected Auxiliary Space: O(|S|*|S|).


Constraints:
1 ≤ |S| ≤ 1000
*/
/*
What we have done in finding the length of longest common subsequence in two strings. 
We will do the same in this case, the two strings being original one and its reverse.
The palindrome part will be same in reverse of the string and in the original string.
*/

// Tabulation.
// TC: O(N^2) SC: O(N^2)
class Solution{
    public:
    int longestPalinSubseq(string A) {
        int n = A.length(), lpsLen = 0;
        vector<vector<int>> table(n+1, vector<int>(n+1));
        string B = A;
        reverse(A.begin(), A.end());
        
        for(int i =1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(A[i-1] == B[j-1]){
                    table[i][j] = 1+table[i-1][j-1];
                }
                else{
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
                lpsLen = max(lpsLen, table[i][j]);
            }
        }
        
        return lpsLen;
    }
};

// Recursion. Memoization
class Solution{
    public:
    int lpsLength(vector<vector<int>>& table, string& p, string& q, int i, int j){
        if(i<0 || j<0) return 0;
        if(table[i][j]) return table[i][j];
        if(p[i] == q[j]){
            return table[i][j] = 1 + lpsLength(table, p, q, i-1, j-1);
        }
        else{
            return table[i][j] = max(lpsLength(table, p, q, i-1, j), lpsLength(table, p, q, i, j-1));
        }
        return 0;
    }
    int longestPalinSubseq(string A) {
        int n = A.length();
        vector<vector<int>> table(n, vector<int>(n, 0));
        string B = A;
        reverse(A.begin(), A.end());
        
        return lpsLength(table, A, B, n-1, n-1);
    }
};