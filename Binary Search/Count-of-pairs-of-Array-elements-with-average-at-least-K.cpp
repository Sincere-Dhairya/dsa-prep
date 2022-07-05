/**
 * @file Count-of-pairs-of-Array-elements-with-average-at-least-K
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * @link https://www.geeksforgeeks.org/count-of-pairs-of-array-elements-with-average-at-least-k/ @endlink
 * @copyright Copyright (c) 2022
 * @tags binary-search
 */
/*
Given an array A[] of size N consisting of N integers, the task is to count the number of pairs such that their average is greater or equal to K.

Example:

Input: N = 4, K = 3, A = {5, 1, 3, 4}
Output: 4
Explanation: (5, 1), (5, 3), (5, 4) and (3, 4) are the required pairs with average greater or equal to K = 3.

Input: N = 3, K = 3, A = {1, 2, 3}
Output: 0
Explanation: No pairs exist with average greater or equal to K = 3.
*/

#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int k){
    sort(arr.begin(), arr.end());
    int count = 0;

    for(int i=0; i<arr.size(); ++i){
        int required = (2*k - arr[i]);
        count += arr.end()- lower_bound(arr.begin()+i+1, arr.end(), required);
    }
    return count;
}

int main(){
    vector<int> arr = {1,2,3};
    int k=3;
    cout<<countPairs(arr, k);
    return 0;
}