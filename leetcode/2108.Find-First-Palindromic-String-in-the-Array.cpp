/**
 * @file 2108. Find First Palindromic String in the Array
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists only of lowercase English letters.
*/

//Contest Question : TC O(N1xN2)
class Solution {
public:
    bool palindrome_check(string s, int i, int j){
        if(i == j) return true;
        if(s[i] == s[j]){
            if(i+1 == j) return true;
            else
                return palindrome_check(s, i+1, j-1);
        }
        return false;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i : words){ // O(N1)
            if(palindrome_check(i, 0, i.length()-1)) //O(N2/2)
                return i;
        }
        return "";
    }
};