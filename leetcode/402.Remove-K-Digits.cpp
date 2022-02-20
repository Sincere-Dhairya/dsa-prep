/**
 * @file 402. Remove K Digits
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-18
 * @link https://leetcode.com/problems/remove-k-digits/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 10^5
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size()-k;
        stack<char> s;
        for(auto d: num){   // O(n+K) as the Stack operations don't start from begining when the next iteration begins.
            while(s.size() and k and s.top()>d){
                --k, s.pop();
            }
            s.push(d);
        }
        string temp;
        while(s.size()){
            temp = s.top() + temp;
            s.pop();
        }
        if(temp.size() > n){
            temp = temp.substr(0, n);
        }
        k=0;
        while(k<temp.size() and temp[k]=='0'){
            ++k;
        }
        temp = temp.substr(k);
        return temp==""?"0":temp;
    }
};