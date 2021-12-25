/**
 * @file 56. Merge Intervals
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

//TC O(n Log n) Sorting then For Loop

//Also try using your custom sort function.
//, [](auto i, auto j){ return i[0] < j[0] || i[1] < j[1] ; }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        cout<<"pass1"<<endl;
        vector<vector<int> > ans { intervals.front() };
        for(int i = 1; i<intervals.size(); i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(ans.back()[1] >= intervals[i][0] ){
                int start = min(ans.back().front(), intervals[i][0]),
                end = max(ans.back().back(), intervals[i][1]);
                ans.pop_back();
                ans.push_back({start, end});
            }
            else
                ans.push_back(intervals[i]);
            cout<<" ans is: "<<ans.back()[0]<<" "<<ans.back()[1]<<endl;
        }
        cout<<"pass1"<<endl;
        return ans;
    }
};

/*
[[1,8],[2,4],[5,9],[0,10],[0,1]]
[[1,8],[2,4],[5,9],[0,10],[0,1],[3,4],[11,13],[20,23],[24,26],[19,25]]

*/