/**
 * @file 2139. Minimum Moves to Reach Target Score
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-16
 * @link https://leetcode.com/problems/minimum-moves-to-reach-target-score/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are playing a game with integers. You start with the integer 1 and you want to reach the integer target.

In one move, you can either:

Increment the current integer by one (i.e., x = x + 1).
Double the current integer (i.e., x = 2 * x).
You can use the increment operation any number of times, however, you can only use the double operation at most maxDoubles times.

Given the two integers target and maxDoubles, return the minimum number of moves needed to reach target starting with 1.

 

Example 1:

Input: target = 5, maxDoubles = 0
Output: 4
Explanation: Keep incrementing by 1 until you reach target.
Example 2:

Input: target = 19, maxDoubles = 2
Output: 7
Explanation: Initially, x = 1
Increment 3 times so x = 4
Double once so x = 8
Increment once so x = 9
Double again so x = 18
Increment once so x = 19
Example 3:

Input: target = 10, maxDoubles = 4
Output: 4
Explanation: Initially, x = 1
Increment once so x = 2
Double once so x = 4
Increment once so x = 5
Double again so x = 10
 

Constraints:

1 <= target <= 10^9
0 <= maxDoubles <= 100
*/

//Recusion: giving TLE TC: 2^N
class Solution {
public:
    int movescalc(int target, int md, int sum, int countmoves){
        if(sum > target){
            return INT_MAX;
        }
        if(sum == target){
            return countmoves;
        }
        
        int val1 = INT_MAX, val2 = INT_MAX;
        
        if(md){
            val2 = movescalc(target, md-1, sum*2, countmoves+1);
        }
         
        val1 = movescalc(target, md, sum+1, countmoves+1);
        
        return min(val1, val2);
    }
    int minMoves(int target, int maxDoubles) {
        if(target == 1){
            return 0;
        }
        return movescalc(target, maxDoubles, 2, 1);
    }
};


//O(N)
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while(target != 1){
            if(!maxDoubles){
                ans += target-1;
                break;
            }
            if(target&1){
                --target;
                ++ans;
            }
            else{
                target /= 2;
                ++ans;
                --maxDoubles;
            }
        }
        return ans;
    }
};