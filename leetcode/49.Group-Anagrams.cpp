/**
 * @file 49. Group Anagrams
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-13
 * @link https://leetcode.com/problems/group-anagrams/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

// Sorting the individual string, checking it in map, then inserting the unsorted into the map.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> list;
        for(auto &s: strs){// o(n)
            string t = s;
            sort(t.begin(), t.end()); //( o(nlogn))
            list[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto p : list){
            ans.push_back(p.second);
        }
        return ans;
    }
};