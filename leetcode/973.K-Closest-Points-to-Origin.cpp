/**
 * @file 973. K Closest Points to Origin
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 < xi, yi < 104
*/

//O(NlogN) Implementation: can't be optimised further.. Space: O(N)
class Solution {
public:
    typedef pair<int, vector<int>> pr;
    struct Compare{
        bool operator()(pr & a, pr & b){
            return a.first > b.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pr, vector<pr>, Compare> pq;
        
        for(auto i : points){
            int distance = i[0]*i[0] + i[1]*i[1];
            pq.push({distance, i});
        }
        vector<vector<int> > ans;
        while(k--)
            ans.push_back(pq.top().second), pq.pop();
        return ans;
    }
};
