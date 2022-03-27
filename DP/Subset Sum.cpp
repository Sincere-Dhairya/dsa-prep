/**
 * @file Subset Sum
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-26
 * @dvbuiilds
 * @copyright Copyright (c) 2022
 * @link https://www.geeksforgeeks.org/subset-sum-problem-dp-25/ @endlink
 * 
 */

/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Example: 

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
*/

#include<bits/stdc++.h>
using namespace std;

void printing(vector<int> & arr){
    for(int i=0; i<arr.size(); ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printing(vector<vector<bool>> & arr){
    for(int i = 0; i<arr.size(); i++){
        for(int j = 0; j<arr[0].size(); ++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool recursive_construction(vector<int> & arr, int sum, int n){
    if(sum==0){
        return true;
    }
    else if(sum != 0 and n == 0){
        return false;
    }
    if(arr[n-1] > sum){
        return recursive_construction(arr, sum, n-1);
    }
    return recursive_construction(arr, sum, n-1) || recursive_construction(arr, sum-arr[n-1], n-1);
}

bool check_subset(vector<int> & arr, int sum){
    return recursive_construction(arr, sum, arr.size());
}

bool dp_construction(vector<int> & arr, int sum){
    int n = arr.size();

    printing(arr);

    vector<vector<bool>> cache(n+1, vector<bool>(sum+1, 0));

    for(int i = 0; i<=n ; ++i){
        cache[i][0] = 1;
    }

    printing(cache);

    for(int i = 0; i<n; i++){
        for(int j=1; j<=sum ; ++j){
            if(j<arr[i]){
                cache[i+1][j] = cache[i][j];
            }
            else{
                cache[i+1][j] = cache[i][j] || cache[i][j-arr[i]];
            }
        }
    }

    printing(cache);

    return cache[n][sum];
}

int main(){
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout<<check_subset(arr, sum)<<endl;
    cout<<dp_construction(arr, sum)<<endl;
}