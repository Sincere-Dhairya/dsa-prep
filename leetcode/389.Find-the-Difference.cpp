/**
 * @file 389. Find the Difference
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-07
 * @link https://leetcode.com/problems/find-the-difference/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

 

Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.
Example 2:

Input: s = "", t = "y"
Output: "y"
 

Constraints:

0 <= s.length <= 1000
t.length == s.length + 1
s and t consist of lowercase English letters.
*/

// O(N logN) using sorting
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end()),
        sort(t.begin(), t.end());
        
        for(int i = 0; i<s.length(); i++){
            if(s[i]!=t[i]){
                return t[i];
            }
        }
        return t.back();
    }
};

//O(N) Approach using sieve.
class Solution {
public:
    char findTheDifference(string s, string t) {
        int alphabets[26] = {0};
        for(char cs: s){
            ++alphabets[cs-'a'];
        }
        for(char ct: t){
            if(alphabets[ct-'a']-- == 0){
                return ct;
            }
        }
        return 'a';
    }
};

//O(N) using bit manipulation: XOR - Duplicates
class Solution {
public:
    char findTheDifference(string s, string t) {
        int xorval = 0;
        for(auto i: s){
            xorval ^= i;
        }
        for(auto i: t){
            xorval ^= i;
        }
        return xorval;
    }
};