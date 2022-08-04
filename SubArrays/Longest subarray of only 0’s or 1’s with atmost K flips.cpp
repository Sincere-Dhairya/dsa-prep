/**
 * @file Longest subarray of only 0’s or 1’s with atmost K flips
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-04
 * @link https://www.geeksforgeeks.org/longest-subarray-of-only-0s-or-1s-with-atmost-k-flips/ @endlink
 * @copyright Copyright (c) 2022
 * @tags sliding-window.
 */

#include<iostream>
using namespace std;

int findLongestSubarray(int *arr, int k, int n){
    // firstly finding the longest subarray possible for 0s.
    int ones = 0, subarraySize = 1;
    for(int right = 0, left = 0; right < n; ++right){
        if(arr[right] == 1){
            ++ones;
        }
        while(ones > k){
            if(arr[left] == 1){
                --ones;
            }
            ++left;
        }
        subarraySize = max(subarraySize, right-left+1);
    }

    // secondly finding the longest subarray possible for 1s.
    int zeroes = 0;
    for(int right= 0, left = 0; right<n; ++right){
        if(arr[right] == 0){
            ++zeroes;
        }
        while(zeroes > k){
            if(arr[left] == 0){
                --zeroes;
            }
            ++left;
        }
        subarraySize = max(subarraySize, right-left+1);
    }
    return subarraySize;
}

int main(){
    int arr[] = {1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
    int k = 2;
    cout << findLongestSubarray(arr, k, 10) << endl;
    return 0;
}