/**
 * @file Count-all-triplets-from-given-Array-whose-bitwise-XOR-is-equal-to-K
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * @link https://www.geeksforgeeks.org/count-all-triplets-from-given-array-whose-bitwise-xor-is-equal-to-k/ @endlink
 * @copyright Copyright (c) 2022
 * @tags binary-search
 */
/*
Given an array arr[] which contains N positive integers and an integer K. The task is to count all triplets whose XOR is equal to the K. i.e arr[ i ] ^ arr[ j ] ^ arr[ k ] = X where 0 ≤ i < j < k < N ( 0 based indexing)

Examples:

Input: arr[] = { 2, 1, 3, 7, 5, 4}, K = 5
Output: 2
Explanation: In the above array there are two triplets whose xor is equal to K
{ 2, 3, 4}, ( 2 ^ 3 ^ 4 = 5) 
{1, 3, 7}, ( 1 ^ 3 ^ 7 = 5 )
So, output is 2. 

Input: arr[] = { 4, 1, 5, 7}, X=0
Output:1
Explanation: In the above array there is only one triplet whose xor is equal to K
{ 4, 1, 5} (4 ^ 1 ^ 5=0)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countTriplets(vector<int>& arr, int k){
    sort(arr.begin(), arr.end());
    int count = 0;

    for(int i=0; i<arr.size(); ++i){
        for(int j = i+1; j<arr.size(); ++j){
            int required = arr[i]^arr[j]^k;
            int ind = lower_bound(arr.begin()+j+1, arr.end(), required) // here we are finding the 'required' element in the remaining array, i.e., strictly after the jth element.
                        - arr.begin();
            if( ind < arr.size() && arr[ind] == required){
                ++count;
            }
        }
    }

    return count;
}

int main(){
    vector<int> arr = {2,1,3,7,5,4};
    int k = 5;
    
    cout<<countTriplets(arr, k);
    return 0;   
}