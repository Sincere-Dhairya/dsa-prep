/**
 * @file 4. Median of Two Sorted Arrays
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.


Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


 
Constraints:


	nums1.length == m
	nums2.length == n
	0 <= m <= 1000
	0 <= n <= 1000
	1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106
*/

//Brute Force: Two pointer, form a new array and take out the median.
//TC: o n1+n2 and SC: o n1 +n2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.end()- nums1.begin(), n2 = nums2.end() - nums2.begin();
        vector<int> sorted(n1+n2);
        int i = 0, j = 0, k = 0;
        while(i < n1 and j < n2)
            if(nums1[i] <= nums2[j])
                sorted[k++] = nums1[i], ++i;
            else
                sorted[k++] = nums2[j], ++j;

        while(i < n1)
            sorted[k++] = nums1[i++];
        while(j < n2)
            sorted[k++] = nums2[j++];
        
        double median;
        if((n1+n2)%2)
            median = sorted[(n1+n2+1)/2 - 1];
        else
            median = (double)(sorted[(n1+n2)/2 -1] + sorted[(n1+n2)/2])/2;
        return median;
    }
};

/**
 * Optimized approach:
 * Since we know the indices of values that will help us calculate the median, we will focus on reaching out to the values by incrementing the counter and break the loop and calculate our answer.
 */

