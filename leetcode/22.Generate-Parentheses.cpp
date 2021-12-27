/**
 * @file 22. Generate Parentheses
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/
//Brute Force Solution - 2^n TC and SC.
class Solution {
public:
    void generate(vector<string> & arr, string s, int left, int right){
        if(left == 0 and right == 0){
            arr.push_back(s);
            return;
        }
        if(left > 0)
            generate(arr, s+'(', left-1, right);
        if(right>left)
            generate(arr, s+')', left, right-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        generate(arr, "", n, n);
        return arr;
    }
};