/**
 * @file 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.cpp
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-02
 * @link https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/ @endlink
 * @copyright Copyright (c) 2022
 * @tags sorting
 */
/*
You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.

 

Example 1:


Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
Example 2:


Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
 

Constraints:

2 <= h, w <= 10^9
1 <= horizontalCuts.length <= min(h - 1, 10^5)
1 <= verticalCuts.length <= min(w - 1, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
All the elements in horizontalCuts are distinct.
All the elements in verticalCuts are distinct.
*/

// Brute Force
// TC: O(NxN), SC: O(1) TLE.
/**
 * Insert the boundary indexes of the board in to the respective arrays, Sort them,
 * then run two iterations one inside the other.
 * the outer iteration will be for height and the inner iteration will be for width 
 * and both of them will be calculated by difference between the consecutive elements.
 * then multiply them and compare it with the global file.
 */

class Solution {
public:
    #define mod (int)(1e9+7)
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        H.insert(H.begin(), 0), H.emplace_back(h),
        V.insert(V.begin(), 0), V.emplace_back(w);
        sort(H.begin(), H.end()),
        sort(V.begin(), V.end());
        int maxArea = 0;
        for(int i = 1; i<V.size(); ++i){
            int width = V[i]-V[i-1];
            for(int j = 1; j<H.size(); ++j){
                int height = H[j] - H[j-1];
                int area = (height*width)%mod;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

// Greedy: Sorting and Maths
// Sort the vectors and find the max width and max height and calculate the max area.
// TC: O(NlogN), SC: O(1).
class Solution {
public:
    #define mod (int)(1e9+7)
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        H.insert(H.begin(), 0), H.emplace_back(h),
        V.insert(V.begin(), 0), V.emplace_back(w);
        
        sort(H.begin(), H.end()),
        sort(V.begin(), V.end());
        
        long maxHeight= 0, maxWidth = 0;
        for(int i = 1; i<H.size(); ++i){
            maxHeight = max(maxHeight, long(H[i]-H[i-1]));
        }
        
        for(int i=1; i<V.size(); ++i){
            maxWidth = max(maxWidth, long(V[i] - V[i-1]));
        }
        
        return (maxHeight*maxWidth)%mod;
    }
};