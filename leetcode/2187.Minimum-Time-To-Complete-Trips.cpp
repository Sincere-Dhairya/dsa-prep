/**
 * @file 2187. Minimum Time to Complete Trips
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-27
 * @link https://leetcode.com/problems/minimum-time-to-complete-trips/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

 

Example 1:

Input: time = [1,2,3], totalTrips = 5
Output: 3
Explanation:
- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.
Example 2:

Input: time = [2], totalTrips = 1
Output: 2
Explanation:
There is only one bus, and it will complete its first trip at t = 2.
So the minimum time needed to complete 1 trip is 2.
 

Constraints:

1 <= time.length <= 10^5
1 <= time[i], totalTrips <= 10^7
*/

//O(N) + O(LogN) approach.
class Solution {
public:
    bool validate_time(vector<int> time, int totaltrips, long mid){  
        int count = 0;
        for(int i: time){
            count += (mid/i);
            if(count >= totaltrips){
                return true;
            }
        }
        if(count >= totaltrips){
            return true;
        }
        else{
            return false;
        }
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long high = INT_MIN, low = 0;
        for(auto i: time){
            if(high < i){
                high = i;
            }
        }
        high *= (long)totalTrips;
        while(high >= low){
            long mid = (high+low)/2;
            if(validate_time(time, totalTrips, mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};