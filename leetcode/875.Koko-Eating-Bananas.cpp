/**
 * @file 875. Koko Eating Bananas
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-20
 * @link https://leetcode.com/problems/koko-eating-bananas/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 10^4
piles.length <= h <= 10^9
1 <= piles[i] <= 10^9
*/

// Binary Search O(NlogN)
class Solution {
public:
    long time_required(vector<int> piles, long speed){
        long time = 0;
        for(auto i: piles){
            if(i<speed){
                time += 1;
            }
            else {
                time += i/speed;
                if(i%speed){
                    ++time;
                }
            }
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long high = *max_element(piles.begin(), piles.end()), low = 1;
        while(high >= low){
            long mid = (high + low)/2;
            if(time_required(piles, mid) > h){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};
/*
[3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000,3,6,7,11,10000,100,1001,10001,100000,5000000]
15000
[332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184]
823855818
*/