/**
 * @file 30. Substring with Concatenation of All Words
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-03
 * @link https://leetcode.com/problems/substring-with-concatenation-of-all-words/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
 

Constraints:

1 <= s.length <= 10^4
s consists of lower-case English letters.
1 <= words.length <= 5000
1 <= words[i].length <= 30
words[i] consists of lower-case English letters.
*/

// Sliding Window using Hash Table.
// TC: O( (N-K)xK ), SC: O(K).
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int totalWords= words.size(),
        wordSize = words[0].size(),
        sentence = totalWords*wordSize;
        vector<int> ans;
        
        if(sentence > s.length()) return ans;
        
        unordered_map<string, int> reference;
        
        for(string& S: words) ++reference[S];
        
        for(int i = 0; i<= s.size()-sentence; ++i){
            int j = i;
            unordered_map<string, int> window(reference);
            int count = totalWords;
            
            while(j-i < sentence){
                string word = s.substr(j, wordSize);
                
                if(window.count(word) && window[word]>0){
                    --window[word];
                    --count;
                }
                else{
                    break;
                }
                j += wordSize;
            }
            
            if(!count){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};