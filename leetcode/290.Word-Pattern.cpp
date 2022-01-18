/**
 * @file 290. Word Pattern
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-17
 * @link https://leetcode.com/problems/word-pattern/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

// O(N^2)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size(), i=0;
        stringstream ss(s);
        string word;
        unordered_map<char, string> list;
        unordered_set<string> used_words;
        while(ss>>word){ // O(N)
            if(list.count(pattern[i])){
                if(word.compare(list[pattern[i]])){ // O(N)
                    return false;
                }
            }
            else{
                if(used_words.count(word)){
                    return false;
                }
                list[pattern[i]] = word;
                used_words.insert(word);
            }
            if(i == n){
                return false;
            }
            ++i;
        }

        return i == n;
    }
};