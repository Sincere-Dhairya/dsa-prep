/**
 * @file 520. Detect Capital
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-24
 * @link https://leetcode.com/problems/detect-capital/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
*/

//Array question: TC: O(N) and SC O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        int i = 1, n = word.size();
        if(isupper(word.front())){
            while(i<n and isupper(word[i])){
                ++i;
            }
            if(i == 1){
                while(i<n and islower(word[i])){
                    ++i;
                }
                if(i < n){
                    return false;
                }
            }
            else if(i<n){
                return false;
            }
            return true;
        }
        else{
            while(i<n and islower(word[i])){
                ++i;
            }
            if(i <n){
                return false;
            }
            return true;
        }
    }
};

/*
Test Cases
"USA"
"FlaG"
"leetode"
"Google"
"GOOGLE"
"GoogLe"
"gGoogle"
"mL"
"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv"
"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuZ"
*/