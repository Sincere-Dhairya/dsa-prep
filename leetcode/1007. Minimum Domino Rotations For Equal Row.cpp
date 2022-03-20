/**
 * @file 1007. Minimum Domino Rotations For Equal Row
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * @link https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= tops.length <= 2 * 10^4
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6
*/

// TC - O(N)
class Solution {
public:
    int calcrotations(vector<int> & tops, vector<int> &bottoms, int num){
        int total = 0, tcount = 0, bcount =0, n = tops.size();
        for(int i=0; i<n; ++i){
            if(tops[i] == num || bottoms[i] == num){
                ++total;
            }
            if(tops[i]==num){
                ++tcount;
            }
            if(bottoms[i]==num){
                ++bcount;
            }
        }
        if(total != n){
            return -1;
        }
        return min(total-tcount, total-bcount);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = calcrotations(tops, bottoms, tops.front());
        return ans==-1?calcrotations(tops, bottoms, bottoms.front()):ans;
    }
};