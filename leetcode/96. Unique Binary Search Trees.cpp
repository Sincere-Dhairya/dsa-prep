/**
 * @file 96. Unique Binary Search Trees
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-03-08
 * @link https://leetcode.com/problems/unique-binary-search-trees/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/* 
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19
*/

/**O(N^2) Approach using Catalan Numbers.
 * The Number of bst's generated with the given number of nodes are in Catalan Sequence.
 * Cn = C0.Cn-1 + C1.Cn-2 + C2.Cn-3 +... + Cn-1.C0
 */

class Solution {
public:
    int numTrees(int n) {
        int BSTS[21] = {0};
        BSTS[0] = BSTS[1] = 1;
        for(int i=2; i<=n; ++i){
            int factor = i-1;
            for(int j = 0; j<=factor; ++j){
                BSTS[i] += (BSTS[j]*BSTS[factor-j]);
            }
        }
        return BSTS[n];
    }
};

// Using Recursion.
class Solution {
public:
    int treecalc(int BSTS[], int i){
        if(BSTS[i]){
            return BSTS[i];
        }
        for(int j = 0; j<i; j++){
            BSTS[i] += treecalc(BSTS, j)*treecalc(BSTS, i-j-1);
        }
        return BSTS[i];
    }
    int numTrees(int n) {
        if(n<3){
            return n;
        }
        int BSTS[21]={0};
        BSTS[0] = BSTS[1] = 1, BSTS[2]=2;
        return treecalc(BSTS, n);
    }
};
