/**
 * @file 318. Maximum Product of Word Lengths
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-29
 * @link https://leetcode.com/problems/maximum-product-of-word-lengths/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

 

Example 1:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
 

Constraints:

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists only of lowercase English letters.
*/

// TC: O(N^2), SC: O(Nx26)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), maxmul = 0;
        vector<vector<int>> arrs;
        for(int i=0 ;i<n; ++i){
            vector<int> arr1 (26);
            for(auto c: words[i]){
                ++arr1[c-'a'];
            }
            arrs.emplace_back(arr1);
        }
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i==j) continue;
                bool flag = 1;
                for(int k=0; k<26; ++k){
                    if(arrs[i][k] && arrs[j][k]){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    int prod = accumulate(arrs[i].begin(), arrs[i].end(), 0)*
                                accumulate(arrs[j].begin(), arrs[j].end(), 0);
                    maxmul = max(maxmul, prod);
                }
            }
        }
        return maxmul;
    }
};  