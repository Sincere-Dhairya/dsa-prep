/**
 * @file Minimum length Subarray starting from each index with maximum OR
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * @link https://www.geeksforgeeks.org/minimum-length-subarray-starting-from-each-index-with-maximum-or/ @endlink
 * @copyright Copyright (c) 2022
 * @tags arrays
 */
/*
Given an array of size N. Consider all the subarrays starting at each index from [0, N – 1]. Determine the length of the smallest subarray starting from each index whose bitwise OR  is maximum.

Examples:

Input: N = 5, A = {1, 2, 3, 4, 5}
Output: {4, 3, 2, 2, 1}
Explanation: 

For i = 1, and size of subarray = 1, score of this subarray is 1. 
For size = 2, the value is 1 | 2 = 3. 
For size = 3, the value is 1 | 2 | 3 = 3.
For size = 4, the value is 1 | 2 | 3 | 4 = 7 and 
for size = 5, the value of this subarray is 1 | 2 | 3 | 4 | 5 = 7. 
You can see that the maximum value is 7, and the smallest size 
of the subarray starting at 1 with this value is of size 4. 
So the maximum answer starting from 1st index is equal to 4.
For i = 2 and size = 1, the value is 2. 
For size = 2, the value is 2 | 3 = 3. 
For size = 3, the value is 2 | 3 | 4 = 7. 
For size = 4, the value is 2 | 3 | 4 | 5 = 7. 
You can see that the maximum score is 7, and the smallest size 
of the subarray starting at 2, with this value is of size 3. 
So the maximum answer starting from 2nd index is equal to 3.
For i = 3 and size = 1, the value is 3. 
For size = 2, the value is 3 | 4 = 7. 
For size = 3, the value is 3 | 4 | 5 = 7. 
So for i = 3 the size is 2
For i = 4 and size = 1, the score is 4 and for size = 2, the score is 4 | 1 = 5. 
So the size is equal to 2.
For i = 5 only one subarray is there of size 1.
Input: N = 7, A = {2, 4, 3, 1, 5, 4, 6}
Output: {3, 2, 3, 4, 3, 2, 1}
*/

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int* getMinLenOfMaxOR( int *arr, int n){
    int BITSIZE = 32;
    int bitset[BITSIZE];

    memset(bitset, 0, sizeof(bitset));

    int * lenArr = new int[n];
    memset(lenArr, 0, n*sizeof(int));

    for(int i=n-1; i>=0; --i){
        for(int j = 0; j<BITSIZE; ++j){
            if(arr[i] & (1<<j)){
                bitset[j] = i;
            }
        }

        int lastIndex = i;
        for(int j=0; j<BITSIZE; ++j){
            lastIndex = max(lastIndex, bitset[j]);
        }
        lenArr[i] = lastIndex-i+1;
    }
    return lenArr;
}

vector<int> getMinLenOfMaxOR( vector<int> &arr){
    int BITSIZE = 32;
    vector<int> bitset(BITSIZE, 0), lenArr(arr.size(), 0);

    // memset(bitset, 0, sizeof(bitset));

    // int * lenArr = new int[n];
    // memset(lenArr, 0, n*sizeof(int));

    for(int i=arr.size()-1; i>=0; --i){
        for(int j = 0; j<BITSIZE; ++j){
            if(arr[i] & (1<<j)){
                bitset[j] = i;
            }
        }

        int lastIndex = i;
        for(int j=0; j<BITSIZE; ++j){
            lastIndex = max(lastIndex, bitset[j]);
        }
        lenArr[i] = lastIndex-i+1;
    }
    return lenArr;
}

int main(){
    int n = 7;
    int arr[n] = {2, 4, 3, 1, 5, 4, 6};

    // set values in arr.
    for(int i=0; i<n; ++i){
        arr[i] = i+1;
    }

    int * ans = getMinLenOfMaxOR(arr, n);

    for(int i=0; i<n; ++i){
        cout << ans[i] <<" ";
    }
    cout << endl;
    vector<int> arr2  = {2, 4, 3, 1, 5, 4, 6};
    vector<int> ansarr = getMinLenOfMaxOR(arr2);
    for(int i: ansarr){
        cout << i << " ";
    }
    return 0;
}