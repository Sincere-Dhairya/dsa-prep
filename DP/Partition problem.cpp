/**
 * @file Partition problem
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-26
 * @link https://www.geeksforgeeks.org/partition-problem-dp-18/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same. 

Examples: 

arr[] = {1, 5, 11, 5}
Output: true 
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false 
The array cannot be partitioned into equal sum sets.
*/

#include<bits/stdc++.h>
using namespace std;

bool subset_construction(vector<int> & arr, int i, int sum){
    if(!sum){
        return true;
    }
    if(sum and i <= 0){
        return false;
    }
    return subset_construction(arr, i-1, sum) || subset_construction(arr, i-1, sum-arr[i-1]);
}

bool check_equal_sum_partition(vector<int> & arr){
    int n = arr.size(), sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum&1){
        return false;
    }
    sum/=2;
    return subset_construction(arr, n, sum);
}

bool dp_subset_construction(int N, int arr[]){
    int sum = 0;
    for(int i = 0; i<N; ++i){
        sum += arr[i];
    }
    if(sum&1){
        return false;
    }
    sum /=2;
    vector<vector<bool>> cache(N+1, vector<bool>(sum+1, false));
    for(int i=0; i<N; i++){
        cache[i][0] = 1;
    }

    for(int i = 0; i<N; ++i){
        for(int j = 1; j<=sum; ++j){
            if(j<arr[i]){
                cache[i+1][j] = cache[i][j];
            }
            else{
                cache[i+1][j] = cache[i][j] || cache[i][j-arr[i]];
            }
        }
    }
    return cache[N][sum];
}

int main(){
    vector<int> arr = {1,5,11,5};
    // check if it can be partitioned into two subsets of equal sum.
    cout<<check_equal_sum_partition(arr);
    int arr2[4] = {1,5,11,5};
    cout<<dp_subset_construction(4, arr2);
}