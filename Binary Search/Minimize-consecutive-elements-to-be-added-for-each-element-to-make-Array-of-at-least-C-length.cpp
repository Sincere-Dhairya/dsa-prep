/**
 * @file Minimize consecutive elements to be added for each element to make Array of at least C length
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * @link https://www.geeksforgeeks.org/minimize-consecutive-elements-to-be-added-for-each-element-to-make-array-of-at-least-c-length/ @endlink
 * @copyright Copyright (c) 2022
 * @tags binary-search
 */
/*
Given a sorted array arr[] of size N, where arr[i] denotes the starting position of a sequence, the task is to find the minimum number of consecutive elements (say K) that can be added for each Array element to make the Array length at least C.

Note: The consecutive numbers can be added till minimum of arr[i]+K or (arr[i+1]-1).

Examples:

Input: arr[] = { 1, 2, 4, 5, 7}, C = 3
Output: 1
Explanation: For K = 1, 5 numbers are possible(one from each position).
From position 1 –  select ‘1’.
From position 2 – select ‘2’
From position 4 – select ‘4’
From position 5 – select ‘5’
From position 7 – select ‘7’
Total elements of sequence =5, which is greater than 3

Input: arr [] = {2, 4, 10}, C = 10
Output: 4
Explanation:  Given sequences are: {2, 3}, {4, 5, 6, 7, 8, 9}, {10, 11, 12, 13, 14 . . . }
Selected elements = { 2, 3, 4, 5, 6, 7, 10, 11, 12, 13}
Minimum value should be 4.
From position 2 -> 2, 3 because 
the next sequence starts at 4 so 4 elements cannot be selected from this sequence
From position 4 – 4, 5, 6, 7
From position 10 – 10, 11, 12, 13
Total elements of sequence = 10 { 2, 3, 4, 5, 6, 7, 10, 11, 12, 13}.
*/

#include<bits/stdc++.h>
using namespace std;

bool possibleConsecutives(vector<int>& arr, int C, int consecutive){
    int count = 0;
    for(int i = 0; i<arr.size()-1; ++i){
        int nums = min(arr[i+1]-arr[i], consecutive);
        count += nums;
        if(count >= C){
            return 1;
        }
    }
    count += consecutive;

    return count >= C;
}

int minConsecutives (vector<int>& arr, int C){
    int high = C, low = 0, minConsecutive = 1e9;

    while(high >= low){
        int mid = (high+low)/2;

        if(possibleConsecutives(arr, C, mid)){
            high = mid-1;
            minConsecutive = min(minConsecutive, mid);
        }
        else{
            low = mid+1;
        }
    }
    
    return minConsecutive;
}

int main(){
    // vector<int> arr = {2,4,10};
    vector<int> arr = {1,2,4,5,7};
    int C=3;
    cout<<minConsecutives(arr, C)<<endl;
    return 0;
}