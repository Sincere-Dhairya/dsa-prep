/**
 * @file Subset-Sum-Equal-To-K
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-11
 * @link https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your 
task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return 
false.
For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. 
These are {1,3} and {4}. Hence, return true.
*/

#include<iostream>
#include<vector>
using namespace std;

bool subsetAnalyser(vector<int>& arr, int k, int i){
    cout<<k<< " "<<i<<endl;
	if(!k){
		return true;
	}
	if(k<0 || i >= arr.size()){
		return false;
	}
    // unpick
    bool unpick = subsetAnalyser(arr, k, i+1), pick = false;

    if(unpick){
        return unpick;
    }
    // pick
    if(arr[i] <= k){
        pick = subsetAnalyser(arr, k-arr[i], i+1);
    }
	return pick;
}

bool subsetAnalyser(vector<int>& arr, int k){
    int n = arr.end() - arr.begin();
    vector<vector<int>> table(n, vector<int>(k+1, 0));

    // if k becomes 0, then the answer is true for all the conditions.
    for(int i = 0; i<n; ++i){
        table[i][0] = 1;
    }
    
    if(arr[n-1] <= k)
        table[n-1][arr[n-1]] = 1;

    for(int i = n-2; i>=0; --i){
        for(int j = 1; j<=k; ++j){
            bool unpick = table[i+1][j], pick = false;
            if(arr[i] <= j){
                pick = table[i+1][j-arr[i]];
            }
            table[i][j] = pick|unpick;
        }
    }

    return table[0][k];
}
int main(){
    vector<int> arr1 = {4, 3, 2, 1}, arr2 = {2, 5, 1, 6, 7}, arr3 = {6, 1, 2, 1};
    int k1 = 5, k2 = 4, k3 = 4;
    
    // Recursion.
    cout<<subsetAnalyser(arr1, k1, 0)<<endl;
    cout<<subsetAnalyser(arr2, k2, 0)<<endl;
    cout<<subsetAnalyser(arr3, k3, 0)<<endl<<endl;

    // Tabulation.
    cout<<subsetAnalyser(arr1, k1)<<endl;
    cout<<subsetAnalyser(arr2, k2)<<endl;
    cout<<subsetAnalyser(arr3, k3)<<endl;
    return 0;
}