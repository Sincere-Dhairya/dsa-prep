/**
 * @file Minimum Subset Sum Difference
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * @link https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example: 

Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
*/

#include<bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n; ++i){
        sum += arr[i];
    }

    vector<vector<bool>> cache(n+1, vector<bool> (sum+1, 0));
    for(int j = 0; j<=n; j++){
        cache[j][0] = 1;
    }

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=sum; j++){
            cache[i][j] = cache[i-1][j];
            if(j>=arr[i-1]){
                cache[i][j] = cache[i][j] || cache[i-1][j-arr[i-1]];
            }
        }
    }

    int diff = INT_MAX;
    for(int j = sum/2; j>=0; --j){
        if(cache[n][j]){
            diff = min(diff, sum-2*j);
        }
    }
    return diff;
}
int main(){
    //cout<<minDifference({arr}, N);
    int arr1[4] = {1,6,11,5}, arr2[2] = {1,4};
    cout<<minDifference(arr1, 4)<<endl;
    cout<<minDifference(arr2, 2)<<endl;
}