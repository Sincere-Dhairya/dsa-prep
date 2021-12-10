/**
 * @file 790.Domino-and-Tromino-Tiling.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000
*/

//Using DP. Faster than 100% but SC is not so good.
class Solution {
public:
    #define mod 1000000007
    int calculate_the_number(int n, vector<int> & cache){
        if(cache[n]) return cache[n];
        return cache[n] = (2*(calculate_the_number(n-1, cache)%mod)%mod+(calculate_the_number(n-3, cache)%mod))%mod;
    }
    int numTilings(int n) {
        if(n <= 2) return n;
        if(n==3) return 5;

        vector<int> cache(n+1, 0);
        cache[1] = 1, cache[2] = 2, cache[3] = 5;
        return calculate_the_number(n, cache);
    }
};

//Using DP and 3 variables
class Solution {
public:
    #define mod 1000000007

    int numTilings(int n) {
        if(n <= 2) return n;
        if(n==3) return 5;
        int var1 = 1, var2 = 5, var3 = 2, res = 0;
        
        for(int i = 4; i<=n; i++)
            res = ((2*var2)%mod + var1)%mod, var1 = var3, var3 = var2, var2 = res;
        return res;
    }
};
