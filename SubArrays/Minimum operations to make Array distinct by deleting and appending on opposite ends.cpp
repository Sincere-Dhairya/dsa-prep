/**
 * @file Minimum operations to make Array distinct by deleting and appending on opposite ends
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-12
 * @link https://www.geeksforgeeks.org/minimum-operations-to-make-array-distinct-by-deleting-and-appending-on-opposite-ends/ @endlink
 * @copyright Copyright (c) 2022
 * @tags sliding-window
 */
/*
Given an array arr[] of N integers. the task is to find the minimum number of operations required to make all the elements of the array distinct using the following operations. 

Remove one element from the starting of the array arr[] and append any integer to the end.
Remove one element from the end of the array arr[] and prepend any integer to the beginning.
Examples:

Input: arr[] = {1, 3, 3, 5, 1, 9, 4, 1}
Output: 4
Explanation: Remove 1 from end and add 5 at starting [5, 1, 3, 3, 5, 1, 9, 4]
Remove 5 from start and add 7 at end [1, 3, 3, 5, 1, 9, 4, 7]
Remove 1 from start and add 8 at end [3, 3, 5, 1, 9, 4, 7, 8]
Remove 3 from start and add 2 at end [3, 5, 1, 9, 4, 7, 8, 2]

Input: arr[] = {1, 2, 3, 5, 4}
Output: 0
*/

#include<bits/stdc++.h>
using namespace std;

int getMinOperations(int* arr, int & n){
    unordered_map<int, int> indices;
    int len = 0, start = -1, end = -1;
    
    for(int right = 0, left = 0; right< n; ++right){
        left = max(left, indices[arr[right]]);
        
        int instantLen = right-left+1;
        if(instantLen >= len){
            if(instantLen > len){
                len = instantLen;
                start = left, end = right;
            }
        }
        indices[arr[right]] = right+1;
    }
    
    return 2*min(start, n-end-1) + max(start, n-end-1);
}
int main(){
    int arr1[] = {1,3,3,5,1,9,4,1}, arr2[] = {1,2,3,4}, n1 = 8, n2 = 4;
    cout << getMinOperations(arr1, n1) << endl;
    cout << getMinOperations(arr2, n2) <<endl;
}