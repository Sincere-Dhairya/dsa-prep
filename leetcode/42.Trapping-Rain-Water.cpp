/**
 * @file 42. Trapping Rain Water
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-31
 * @link https://leetcode.com/problems/trapping-rain-water/
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/

// between O(N^2) and O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int vol = 0, sub = 0, i = 0, j = 1, 
        n = height.end()-height.begin();
        while(i<=j and j<n){
            
            for(; j<n; j++)
                if(height[i] <= height[j])
                    break;
                else
                    sub += height[j];
            
            if(j < n)
                vol += min(height[i], height[j])*(j-i-1) - sub, 
                sub = 0, i = j;
            
            if(j == n)
                --height[i], j = i+1, sub = 0;
            else
                ++j;
        }
        return vol;
    }
};

//TC - O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.end()- height.begin(), lefthigh = 0, righthigh = 0, i = 0, j = n-1, vol = 0;
        while(i <= j){
            lefthigh = max(lefthigh, height[i]);
            righthigh = max(righthigh, height[j]);
            if(lefthigh < righthigh)
                vol += (lefthigh - height[i]), ++i;
            else
                vol += (righthigh - height[j]), --j;
        }
        return vol;
    }
};