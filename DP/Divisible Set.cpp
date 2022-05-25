/**
 * @file Divisible Set
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-25
 * @link https://www.codingninjas.com/codestudio/problems/divisible-set_3754960 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array of distinct numbers ‘arr’. Your task is to return the 
largest subset of numbers from ‘arr’, such that any pair of numbers ‘a’ and ‘b’ 
from the subset satisfies the following: a % b == 0 or b % a == 0.
For Example:
You are given ‘arr’ = [1, 16, 7, 8, 4] as you can the set {1, 4, 8, 16}, here you 
can take any pair from the set and either one of the elements from the pair will 
divide the other.

Constraints:
1 <= T <= 10
1 <= N <= 10^3
0 <= arr[i] <= 10^8    

Time Limit: 1 sec
Note :
You do not need to print anything. It has already been taken care of. Just 
implement the given function. 
*/

// Recursion + Memoization.
// TC: O(2^N), SC: O(N)
#include<vector>
void subsetMaker(vector<int>& ans, vector<int>& arr, vector<int> &subset, int n, int i){
    if(i==n){
        if(ans.size() < subset.size()){
            ans = subset;
        }
        return;
    }
    
    // unpick
    subsetMaker(ans, arr,subset, n, i+1);
    
    //pick
    bool shallpick = true;
    for(auto j: subset){
        if(j%arr[i]==0 || arr[i]%j==0){ continue;}
        else{shallpick = false; break;}
    }
    if(shallpick){
        subset.emplace_back(arr[i]);
        subsetMaker(ans, arr, subset, n, i+1);
        subset.pop_back();
    }
    return ;
}
vector<int> divisibleSet(vector<int> &arr){
    vector<int> subset, ans;
    int len = 0;
    subsetMaker(ans, arr, subset, arr.size(), 0);
    return ans;
}

// Tabulation. Saving Index and Len of the Longest Subsequence (Subset).
// TC: O(NxN), SC: O(N)
vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size(), maxlen = 0, ind = 0;
    vector<int> indices(n), lenofSubset(n, 1);
    for(int i = 0; i<n; ++i){
        indices[i] = i;
    }
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            if(arr[j]%arr[i]==0 && lenofSubset[j] < lenofSubset[i]+1){
                indices[j] = i, lenofSubset[j] = lenofSubset[i]+1;
            }
        }
        if(maxlen < lenofSubset[i]){
            maxlen = lenofSubset[i], ind = i;
        }
    }
    vector<int> subset;
    while(indices[ind] != ind){
        //cout<<ind<<" ";
        subset.emplace_back(arr[ind]);
        ind = indices[ind];
    }
    subset.emplace_back(arr[ind]);
    return subset;
}