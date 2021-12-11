/**
 * @file 878.Nth-Magical-Number.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, a = 2, b = 3
Output: 2
Example 2:

Input: n = 4, a = 2, b = 3
Output: 6
Example 3:

Input: n = 5, a = 2, b = 4
Output: 10
Example 4:

Input: n = 3, a = 6, b = 4
Output: 8
 

Constraints:

1 <= n <= 109
2 <= a, b <= 4 * 104
*/

//I learned about a way to calculate GCD and LCM in programming.

class Solution {
public:
    #define mod 1000000007
    int get_gcd(int a, int b){
        if(b%a == 0)
            return a;
        return gcd(b%a, a);
    }
    int nthMagicalNumber(int n, int a, int b) {
        long gcd = get_gcd(a,b), lcm = a*b/gcd, h = 1e14, l = min(a,b);
        while(h>=l){
            long m = (h+l)/2;
            if(m/a + m/b - m/lcm < n) l = m+1;
            else h = m-1;
        }
        return l%mod;
    }
};