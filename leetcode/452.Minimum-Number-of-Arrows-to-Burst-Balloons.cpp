/**
 * @file 452. Minimum Number of Arrows to Burst Balloons
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-13
 * @link https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/*
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 

Constraints:

1 <= points.length <= 10^5
points[i].length == 2
-2^31 <= xstart < xend <= 2^31 - 1
*/

/** After sorting the points array according to the second element and then
 * skipping the elements whose first element is <= the ith element's second.
 * Then increasing the count.
 * */
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto & i, auto & j){ 
        return i[1]<j[1]?1:0;
        });
        
        int n = points.end() - points.begin(),count = 0, i = 0, j=0;
        
        while(i<n){
            j = i+1;
            while(j<n and points[i][1]>=points[j][0]){
                ++j;
            }
            ++count;
            i =j;
        }
        return count;
    }
};

/**
 * Sorting arranges the the array in ascending order and then we have to keep reducing 
 * the upperbarier as we travserse the array, otherwise one big element in the begining 
 * of the array can eat all the other elements. 
 */
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.end()-points.begin(), i = 0, count = 0;
        while(i<n){
            int uppbound = points[i][1];
            for(; i<n and points[i][0]<=uppbound; i++){
                uppbound = min(uppbound, points[i][1]);
            }
            ++count;
        }
        return count;
    }
};
/*
[[1,2],[1,4],[2,3],[2,4],[3,4],[5,6]]
[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
*/