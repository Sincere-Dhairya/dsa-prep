/**
 * @file Maximum Sum of Non-Adjacent Elements
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array. you need to calculate maximum sum of a sequence that exists in the array provided no two elements
are adjacent to each other in the array.
Return the maximum sum.
*/
#include<bits/stdc++.h>
using namespace std;


int sumSequence(vector<int>& arr, int i){
    if(i >= arr.size()){
        return 0;
    }

    int pick = arr[i] + sumSequence(arr, i+2),
    unpick = sumSequence(arr, i+1);
    return max(pick, unpick);
}

int sumSequence(vector<int>& arr, vector<int>& cache, int i){
    if(i >= arr.size()){
        return 0;
    }
    if(cache[i]){
        return cache[i];
    }

    return cache[i] = max(
        arr[i] + sumSequence(arr, cache, i+2),
        sumSequence(arr, cache, i+1)
    );
}

int sumSequence(vector<int>& arr){
    int n = arr.end()-arr.begin();
    vector<int> cache(n,0);
    cache[n-1] = max(0, arr.back()),
    cache[n-2] = max(arr[n-2], cache[n-1]);

    for(int i = n-3; i>=0; --i){
        cache[i] = max(
            arr[i] + cache[i+2],
            cache[i+1]
        );
    }
    return cache[0];
}

int main(){
    vector<int> arr = {10,-10,-20,30,60,30,40};
    // Recursion
    cout<<sumSequence(arr, 0)<<endl;

    // Memoization
    vector<int> cache(arr.size());
    cout<<sumSequence(arr, cache, 0)<<endl;

    // Tabulation
    cout<<sumSequence(arr);
    return 0;
}