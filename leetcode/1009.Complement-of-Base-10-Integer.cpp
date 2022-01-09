/**
 * @file 1009. Complement of Base 10 Integer
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-04
 * @link https://leetcode.com/problems/complement-of-base-10-integer/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.

 

Example 1:

Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
Example 2:

Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
Example 3:

Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
 

Constraints:

0 <= n < 10^9
*/

//O(logn) tc and sc O(N)
class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0, len = 0, num = n;
        if(n == 0){
            return 1;
        }
        vector<int> bits;
        while(num){
            bits.push_back(num&1);
            num>>=1;
            ++len;
        }
        if(bits.empty()){
            bits = {0};
        }
        int tens = 1;
        for(int i = 0; i<len; i++){
            if(bits[i]){
                bits[i] = 0;
            }
            else{
                bits[i] = 1;
            }
            int s = bits[i]<<i;
            ans += s;
        }
        return ans;
    }
};

//Optimized solution - SC- O(1), TC - O(LogN)
class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0, len = 0, num = n, i =0;
        if(n == 0){
            return 1;
        }
        while(n){
            int b = n&1;
            if(b){
                b = 0;
            }
            else{
                b = 1;
            }
            b = b<<i;
            ans += b;
            ++i;
            n>>=1;
        }
        return ans;
    }
};
/* Test Cases
0
99999999
10251683
*/