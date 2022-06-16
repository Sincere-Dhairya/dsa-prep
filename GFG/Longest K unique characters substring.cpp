/**
 * @file Longest K unique characters substring
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-16
 * @link https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1# @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.


Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.
Example 2:

Input: 
S = "aaaa", K = 2
Output: -1
Explanation: There's no substring with K
distinct characters.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestKSubstr() which takes the string S and an integer K as input and returns the length of the longest substring with exactly K distinct characters. If there is no substring with exactly K distinct characters then return -1.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ |S| ≤ 10^5
1 ≤ K ≤ 10^5
*/

// Sliding Window.
// TC: O(N), SC: O(N)
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> list;
        int left = 0, right = 0, sum = 0, maxLen = -1;
        while(right < s.length()){
            ++list[s[right]];
            while(list.size() > k){
                if(--list[s[left]] == 0){
                    list.erase(s[left]);
                }
                ++left;
            }
            if(list.size() == k){
                maxLen = max(maxLen, right-left +1);
                
            }
            ++right;
        }
        return maxLen;
    }
};