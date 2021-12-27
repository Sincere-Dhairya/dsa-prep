/**
 * @file 476. Number Complement
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-27
 * @link https://leetcode.com/problems/number-complement/
 * @copyright Copyright (c) 2021
 * 
 */
/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

1 <= num < 231
 

Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
*/

//TC: O(Logn) Space O(Logn)
class Solution {
public:
    int findComplement(int num) {
        int comp = 0;
        stack<int> s;
        while(num){
            s.push(num&1), num>>=1;
        }
        while(s.size()){
            int biti = s.top();
            s.pop();
            comp <<= 1;
            if(biti == 0)
                comp |= 1;
        }
        return comp;
    }
};

//TC: O(logN) and SC O(1)
class Solution {
public:
    int findComplement(int num) {
        for(long i = 1; i<= num; i*=2)
            num = num^i;
        return num;
    }
};