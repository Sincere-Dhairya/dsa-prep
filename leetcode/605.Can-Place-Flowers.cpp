/**
 * @file 605. Can Place Flowers
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 * @link https://leetcode.com/problems/can-place-flowers/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 10^4
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
*/

//O(N) Solution
class Solution {
public:
    bool canPlaceFlowers(vector<int>& F, int n) {
        int nf = F.size();
        
        if((nf == 1 and F[0] == 0) || n == 0){
            return true;
        }

        for(int i = 0; i<nf; i++){
            if(F[i] == 0){
                if(i == 0){
                    if(F[i+1] == 0){
                        F[i] = 1;
                        --n;
                    }
                }
                else if(i == nf-1){
                    if(F[i-1] == 0){
                        F[i] = 1;
                        --n;
                    }
                }
                else{
                    if(F[i-1] == 0 and F[i+1] == 0){
                        F[i] = 1;
                        --n;
                    }
                }
                
            }

            if(!n){
                break;
            }
        }
        return !n;
    }
};
/*
Test Cases
[0]
1
[1,0,0,0,1]
1
[1,0,0,0,1]
3
[1,0,1,0,1]
1
[1,0,0,0,1,0,0]
2
*/