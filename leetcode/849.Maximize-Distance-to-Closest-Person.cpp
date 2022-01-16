/**
 * @file 849. Maximize Distance to Closest Person
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-16
 * @link https://leetcode.com/problems/maximize-distance-to-closest-person/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

 

Example 1:


Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Example 3:

Input: seats = [0,1]
Output: 1
 

Constraints:

2 <= seats.length <= 2 * 10^4
seats[i] is 0 or 1.
At least one seat is empty.
At least one seat is occupied.
*/

//O(N) approach. considering 0's at the begining and endind that don't have 1 on both sides 
// as pre_zeroes and suff_zeros and counting maximum zero length in between the array as well/
// and in the end, returniing the max of the above two and maxzeroes +1 /2.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), prec0 = -1, succ0 = -1, max0 = 0, empty = 0;
        
        for(int i =0; i<seats.size(); i++){
            if(seats[i]){
                if(prec0==-1){
                    prec0 = empty;
                }
                else{
                    max0 = max(max0, empty);
                }
                empty = 0;
            }
            else{
                ++empty;
            }
        }
        succ0 = empty;
        
        return max((max0+1)/2, max(prec0, succ0));
    }
};