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
int main(){
    vector<int> arr = {1,5,11,5};
    // check if it can be partitioned into two subsets of equal sum.
    cout<<check_equal_sum_partition(arr);
}