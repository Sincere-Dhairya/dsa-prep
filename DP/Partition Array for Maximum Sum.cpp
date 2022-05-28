/**
 * @file Partition Array for Maximum Sum
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-28
 * @link https://www.codingninjas.com/codestudio/problems/maximum-subarray_3755255 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array of ‘N’ integers. You have to divide the array into some subarrays such that each element is present in exactly one of the subarrays. The length of each subarray should be at most ‘K’. After partitioning all the elements of each subarray will be changed to the maximum element present in that subarray. You have to maximize the sum of all the elements after partitioning.
Input is given such that the answer will fit in a 32-bit integer.
For Example:
let's take n=6, k=3, and array as [1, 20, 13, 4, 4, 1]
We can divide the array into the following subarrays
[0,1] max of this subarray is 20 so the contribution of 
this subarray in the final answer will be 20*2=40.
[2,4]  max of this subarray is 13 so the contribution of 
this subarray in the final answer will be 13*3=39.
[5,5]  max of this subarray is 1 so the contribution of this 
subarray in the final answer will be 1*1=1.

So, the answer will be 40 + 39 + 1 = 80.

Constraints:
1 <= N <= 300
0 <= arr[i] <= 10^9
1 <= k <=N

Time limit: 1 sec
*/

// Recursion + Memoization.
// TC: Exponential reduced to O(N) + O(K), SC: O(N) + O(N)
int f(vector<int>& cache, vector<int>& arr, int& k, int& n, int i){
    if(i==n) return 0;
    if(cache[i]) return cache[i];
    int maxsum = 0, subsum = 0, maxnum = arr[i];
    for(int j=i; j<n && j<i+k; ++j){
        maxnum = max(maxnum, arr[j]);
        subsum = maxnum*(j-i+1);
        int cost = subsum + f(cache, arr, k, n, j+1);
        maxsum = max(maxsum, cost);
    }
    return cache[i]=maxsum;
}

int maximumSubarray(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> cache(n+1, 0);
    return f(cache, arr, k, n, 0);
}

// Tabulation.
// TC: O(NXN), SC: O(N)
int maximumSubarray(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> cache(n+1, 0);
    for(int i=n-1; i>=0; --i){
        int maxsum = 0, subsum = 0, maxnum = arr[i];
        for(int j=i; j<n && j<i+k; ++j){
            maxnum = max(maxnum, arr[j]);
            subsum = maxnum*(j-i+1);
            int cost = subsum + cache[j+1];
            maxsum = max(maxsum, cost);
        }
        cache[i]=maxsum;
    }
    return cache[0];
}