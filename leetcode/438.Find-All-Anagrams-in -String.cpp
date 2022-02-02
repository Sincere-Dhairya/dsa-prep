/**
 * @file 438. Find All Anagrams in a String
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-02
 * @link https://leetcode.com/problems/find-all-anagrams-in-a-string/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 10^4
s and p consist of lowercase English letters.
*/

//O(N logn) Gave TLE
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int psize = p.length(), start = 0, end = psize, n = s.length();
        vector<int> ans;
        if(n<psize){
            return ans;
        }
        unordered_multiset<char> list, comp;
        for(auto i: p){
            list.insert(i);
        }
        for(int i = 0; i<psize; i++){
            comp.insert(s[i]);
        }
        if(comp == list){
            ans.push_back(start);
        }
        for(; start<=n-psize; start++, end++){
            comp.erase(comp.find(s[start]));
            comp.insert(s[end]);
            if(comp == list){
                ans.push_back(start+1);
            }
        }
        return ans;
    }
};
/*
"cbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacdcbaebabacd"
"abc"
*/

//Better way O(N)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int psize = p.length(), n = s.length();
        vector<int> ans;
        if(n<psize){
            return ans;
        }
        vector<int> mainwindow(26, 0), window(26, 0);
        for(int i = 0; i<psize; i++){
            ++mainwindow[p[i]-'a'];
        }
        for(int i = 0; i<psize; i++){
            ++window[s[i]-'a'];
        }
        if(mainwindow == window){
            ans.push_back(0);
        }
        for(int start=0, end=psize; end<n; start++, end++){
            --window[s[start]-'a'],
            ++window[s[end]-'a'];
            if(window == mainwindow){
                ans.push_back(start+1);
            }
        }
        return ans;
    }
};