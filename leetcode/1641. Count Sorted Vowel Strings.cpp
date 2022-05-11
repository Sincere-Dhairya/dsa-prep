/**
 * @file 1641. Count Sorted Vowel Strings
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-11
 * @link https://leetcode.com/problems/count-sorted-vowel-strings/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045
 

Constraints:

1 <= n <= 50 
*/

// Recursion. TC -> O(2^n). SC -> O(n)
class Solution {
public:
    void stringCounter(int& ans, int i, int n){
        if(i>=5){
            return;
        }
        if(!n){
            ++ans;
            return;
        }
        
        //Pick up.
        stringCounter(ans, i, n-1);
        
        //Not pickup
        stringCounter(ans, i+1, n);
        return ;
    }
    int countVowelStrings(int n) {
        int ans = 0;
        stringCounter(ans, 0, n);
        return ans;
    }
};

// Tabulation. TC O(5*N). SC - O(5*n)
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> table(5, vector<int>(n));
        
        for(int i = 0; i<5; ++i){
            table[i][0] = 5-i;
        }
        
        for(int i = 0; i<n; ++i){
            table[4][i] = 1;
        }
        
        for(int i = 1; i<n; ++i){
            for(int j = 3; j>=0; --j){
                table[j][i] = table[j][i-1] + table[j+1][i];
            }
        }
        return table[0][n-1];
    }
};