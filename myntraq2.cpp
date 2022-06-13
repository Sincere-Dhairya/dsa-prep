/**
 * @file myntraq2
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-13
 * @link https://www.geeksforgeeks.org/longest-subsegment-1s-formed-changing-k-0s/ @endlink
 * @copyright Copyright (c) 2022
 * @tags sliding-window
 */

/*
You are given an array of 0's and 1's and a number k that are number of moves to make a 0 a 1.
You have to find the longest length 1's possible with K replacments.
*/

#include<bits/stdc++.h>
using namespace std;

int countMaxLengthofOnes(vector<int> & arr, int & k){
    int n = arr.size(), zeroCount = 0, left = 0, maxlen = 0;
    
    for(int i=0; i<n; ++i){
        if(!arr[i]){
            ++zeroCount;
        }
        
        while(zeroCount > k){
            if(!arr[left]){
                --zeroCount;
            }
            ++left;
        }
        
        maxlen = max(maxlen, i-left +1);
    }
    return maxlen;
}

int main(){
    int k = 3;
    vector<int> arr = {1,0,0,1,1,1,0,1,0,0,0,1,1,0,1};
    
    int ans = countMaxLengthofOnes(arr, k);
    cout<<ans<<endl;
    return 0;
}