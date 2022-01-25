/**
 * @file 191. Number of 1 Bits
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-25
 * @link https://leetcode.com/problems/number-of-1-bits/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 

Constraints:

The input must be a binary string of length 32.
 

Follow up: If this function is called many times, how would you optimize it?
*/

//O(N)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            if(n&1){
                ++count;
            }
            n>>=1;
        }
        return count;
    }
};

//O(Logn)
class Solution{
public:
    int hammingWeight(uint32_t n){
        return bitset<32>(n).count();
    }
}