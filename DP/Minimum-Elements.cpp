/**
 * @file Minimum Elements
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-15
 * @link https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Problem Statement
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the 
target sum. You have to tell the minimum number of elements you have to take to reach 
the target sum ‘X’.
Note:
You have an infinite number of elements of each type.
For Example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.
*/
#include<iostream>
#include<vector>
using namespace std;

int minElems(vector<vector<int>>& cache, vector<int>& nums, int target, int i, int n){
	if(i == n-1){
		if(target%nums[i] == 0) return target/nums[i];
		return (int)(1e9);
	}
	if(cache[i][target]> -1) return cache[i][target];
	int unpick = minElems(cache, nums, target, i+1, n), pick = INT_MAX;
	if(target >= nums[i]) pick = 1+minElems(cache, nums, target-nums[i], i, n);
	return cache[i][target] = min(pick, unpick);
}

int minimumElements(vector<int> &num, int x){
	int n = num.end()-num.begin(), ans = 0;
	vector<vector<int>> cache(n, vector<int> (x+1, -1));
	ans = minElems(cache, num, x, 0, n);
	if(ans >= 1e9) return -1;
	return ans;
}

int minimumElements(int x, vector<int> &arr){
    int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(x+1, 0));
	
	for(int i = 0; i<= x; ++i){
		if(i%arr[n-1] == 0) dp[n-1][i] = i/arr[n-1];
		else dp[n-1][i] = 1e9;
	}
	
	for(int i = n-2; i>=0; --i){
		for(int j = 0; j<= x; ++j){
			int unpick = dp[i+1][j], pick = 1e9;
			if(arr[i] <= j) pick = 1 + dp[i][j-arr[i]];
			dp[i][j] = min(pick, unpick);
		}
	}
	
	int ans = dp[0][x];
	if(ans >= 1e9) return -1;
	return ans;
}

int MinimumElements(vector<int> &arr, int x){
    int n = arr.size();
	vector<int> prev(x+1, 0), curr(x+1, 0);
	
	for(int i = 0; i<= x; ++i){
		if(i%arr[n-1] == 0) prev[i] = i/arr[n-1];
		else prev[i] = 1e9;
	}
	
	for(int i = n-2; i>=0; --i){
		for(int j = 0; j<= x; ++j){
			int unpick = prev[j], pick = 1e9;
			if(arr[i] <= j) pick = 1 + curr[j-arr[i]];
			curr[j] = min(pick, unpick);
		}
		prev= curr;
	}
	
	int ans = prev[x];
	if(ans >= 1e9) return -1;
	return ans;
}

int main(){
    vector<int> nums = {3, 16, 21, 6, 7, 13, 1, 18, 4, 2, 10 };
    int target = 83;
    
    // Recursion + Memoization.
    cout<<minimumElements(nums, target)<<endl;

    // Tabulation.
    cout<<minimumElements(target, nums)<<endl;

    // Tabulation with Space Optimized.
    cout<<MinimumElements(nums, target)<<endl;
    return 0;
}

