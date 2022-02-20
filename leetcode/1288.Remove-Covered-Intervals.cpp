/**
 * @file 1288. Remove Covered Intervals
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-20
 * @link https://leetcode.com/problems/remove-covered-intervals/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
 

Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= li <= ri <= 10^5
All the given intervals are unique.
*/

//N log N approach using custom sort
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](auto &i, auto &j){return i[0]<j[0]?1: (i[0]==j[0] and i[1]>j[1])?1: 0; });
        int n = intervals.size();
        for(auto i: intervals){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        int count = 0, lb =intervals[0][0], rb = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(intervals[i][0]>=lb and intervals[i][1]<= rb){
                ++count;
            }
            else if(intervals[i][0]>=lb and intervals[i][1]>rb){
                if(lb == intervals[i][0]){
                    ++count;
                }
                rb = intervals[i][1];
            }
            else if(intervals[i][0]>rb){
                lb = intervals[i][0],
                rb = intervals[i][1];
            }
            
        }
        return n-count;
        
    }
};
/* Test Cases
[[2,14],[1,4],[3,6],[2,8],[2,3],[5,15]]
[[1,2],[2,3],[3,4],[4,7],[1,7]]
[[1,3],[2,4],[3,5],[3,6]]
[[1,10],[2,5],[6,9],[10,12],[9,12]]
[[0,1]]
[[1,6],[2,4],[5,7],[9,13],[9,10],[12,13],[12,15]]
*/