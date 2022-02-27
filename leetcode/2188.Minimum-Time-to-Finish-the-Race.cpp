/**
 * @file 2188. Minimum Time to Finish the Race
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-27
 * @link https://leetcode.com/problems/minimum-time-to-finish-the-race/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*You are given a 0-indexed 2D integer array tires where tires[i] = [fi, ri] indicates that the ith tire can finish its xth successive lap in fi * ri(x-1) seconds.

For example, if fi = 3 and ri = 2, then the tire would finish its 1st lap in 3 seconds, its 2nd lap in 3 * 2 = 6 seconds, its 3rd lap in 3 * 22 = 12 seconds, etc.
You are also given an integer changeTime and an integer numLaps.

The race consists of numLaps laps and you may start the race with any tire. You have an unlimited supply of each tire and after every lap, you may change to any given tire (including the current tire type) if you wait changeTime seconds.

Return the minimum time to finish the race.

 

Example 1:

Input: tires = [[2,3],[3,4]], changeTime = 5, numLaps = 4
Output: 21
Explanation: 
Lap 1: Start with tire 0 and finish the lap in 2 seconds.
Lap 2: Continue with tire 0 and finish the lap in 2 * 3 = 6 seconds.
Lap 3: Change tires to a new tire 0 for 5 seconds and then finish the lap in another 2 seconds.
Lap 4: Continue with tire 0 and finish the lap in 2 * 3 = 6 seconds.
Total time = 2 + 6 + 5 + 2 + 6 = 21 seconds.
The minimum time to complete the race is 21 seconds.
Example 2:

Input: tires = [[1,10],[2,2],[3,4]], changeTime = 6, numLaps = 5
Output: 25
Explanation: 
Lap 1: Start with tire 1 and finish the lap in 2 seconds.
Lap 2: Continue with tire 1 and finish the lap in 2 * 2 = 4 seconds.
Lap 3: Change tires to a new tire 1 for 6 seconds and then finish the lap in another 2 seconds.
Lap 4: Continue with tire 1 and finish the lap in 2 * 2 = 4 seconds.
Lap 5: Change tires to tire 0 for 6 seconds then finish the lap in another 1 second.
Total time = 2 + 4 + 6 + 2 + 4 + 6 + 1 = 25 seconds.
The minimum time to complete the race is 25 seconds. 
 

Constraints:

1 <= tires.length <= 10^5
tires[i].length == 2
1 <= fi, changeTime <= 10^5
2 <= ri <= 10^5
1 <= numLaps <= 1000
*/

//O(N^2) Time and Constant Space
class Solution {
public:
    int dfs(vector<int> &min_time_laps, vector<int>& best_time, int max_laps_tires, int CT, int NLaps){
        if(NLaps == 0){
            min_time_laps[NLaps] = -CT;
        }
        if(!min_time_laps[NLaps]){
            min_time_laps[NLaps] = INT_MAX;
            for(int lps = 1; lps <= min(NLaps, max_laps_tires); ++lps){
                min_time_laps[NLaps] = min(min_time_laps[NLaps], best_time[lps] + CT + dfs(min_time_laps, best_time, max_laps_tires, CT, NLaps-lps));
            }
        }
        return min_time_laps[NLaps];
    }
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<int> min_time_laps(1001, 0), best_time(1001, 0);
        int max_laps_tires = 0;
        for(auto s: tires){
            long laptime = s[0], time_taken = s[0];
            for(int lap=1; lap <= numLaps and laptime< s[0]+changeTime; ++lap){
                max_laps_tires = max(max_laps_tires, lap);
                if(!best_time[lap] or best_time[lap]>time_taken){
                    best_time[lap]=time_taken;
                }
                laptime *= (long)s[1], time_taken += (long)laptime;
            }
        }
        int ans = dfs(min_time_laps, best_time, max_laps_tires, changeTime, numLaps);
        return ans;
    }
};
/*
Test Case
[[99,7]]
85
95
*/