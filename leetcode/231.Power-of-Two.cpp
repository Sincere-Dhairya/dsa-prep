/**
 * @file 231. Power of Two
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
Follow up: Could you solve it without loops/recursion?
*/

//Recursion O(N)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        else return isPowerOfTwo(n/2);
    }
};

//Binary Search in a Table: O(LogN) SC: O(1);
class Solution {
public:
    bool isPowerOfTwo(int n) {
        vector<int> arr = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
        int ind = lower_bound(arr.begin(), arr.end(), n)-arr.begin();
        return ind < 31 and arr[ind] == n;
    }
};

//Recursion using Bit Manipulation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        else if(n == 1) return true;
        else if(n&1) return false;
        else return isPowerOfTwo(n>>1);
    }
};

//Counting the nums of 1 in the binary form of n.
//the number of ones for a 2 power should be always 1.
//TC = O(N)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 and bitset<32>(n).count() == 1;
    }
}; 


//O(1) using Bit manipulation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) and ((n&(n-1)) == 0);
    }
};
/*
8 -> 1000
7 -> 0111
8 & 7 = 0
*/