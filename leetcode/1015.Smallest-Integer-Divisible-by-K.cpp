/**
 * @file 1015. Smallest Integer Divisible by K
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-30
 * @link https://leetcode.com/problems/smallest-integer-divisible-by-k/
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.

 

Example 1:

Input: k = 1
Output: 1
Explanation: The smallest answer is n = 1, which has length 1.
Example 2:

Input: k = 2
Output: -1
Explanation: There is no such positive integer n divisible by 2.
Example 3:

Input: k = 3
Output: 3
Explanation: The smallest answer is n = 111, which has length 3.
 

Constraints:

1 <= k <= 105
*/

//O(N) approach
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 || k%5 == 0)
            return -1;
        for(int r = 0, N = 1; N<=k; N++)
            if((r=(r*10+1)%k) == 0)
                return N;
        return -1;
    }
};
/*
17
23
2
*/
/** Logic
 *  A = P % k.
 * B = (P x 10 + 1)% k
 *   = ( (P % k)x(10%k) + 1 % k )% k
 *   = ( Ax10 + 1)% k
 * .'. (P x 10 + 1) % k = (A x 10 + 1) % k
**/
// Used this logic because there is no limit over the length of the required integer and 
// as the size of the integer increases, the * operation's complexity increases.