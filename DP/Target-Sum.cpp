/**
 * @file Target Sum
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-15
 * @link https://www.codingninjas.com/codestudio/problems/target-sum_4127362 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your task is to build an expression out of an array by adding one of the symbols '+' and '-' before each integer in an array, and then by concatenating all the integers, you want to achieve a target. You have to return the number of ways the target can be achieved.
For Example :
You are given the array ‘ARR’ = [1, 1, 1, 1, 1], ‘TARGET’ = 3. The number of ways this target can be achieved is:
1. -1 + 1 + 1 + 1 + 1 = 3
2. +1 - 1 + 1 + 1 + 1 = 3
3. +1 + 1 - 1 + 1 + 1 = 3
4. +1 + 1 + 1 - 1 + 1 = 3
5. +1 + 1 + 1 + 1 - 1 = 3
These are the 5 ways to make. Hence the answer is 5.
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// Noob way out.
/*
int numberOfWays(vector<vector<int>>& cache, vector<int>& arr, int i, int sum, int n){
	if(i == n){
		if(sum == 0) return 1;
		return 0;
	}
	if(cache[i][1000+sum]) return cache[i][1000+sum];
	int plus = numberOfWays(cache, arr, i+1, sum+arr[i], n),
	minus = numberOfWays(cache, arr, i+1, sum -arr[i], n);
	return cache[i][1000+sum] = plus+minus;
}

int targetSum(int n, int target, vector<int>& arr) {
	vector<vector<int>> cache(n, vector<int>(2001));
    return numberOfWays(cache, arr, 0, target, n);
}
*/
// Recurion.
/*
if we have a sequence like 1,2,3,1. We are interested in finding the number of expressions
that can built by applying + or - sign to the numbers such that the total of the 
expression is the target value. 
Hence it can be mathematically represented as: {x + y} - { z + a} type. 
this means it can be also represented as S1 - S2 = target.
Now the problem becomes finding the number of subsets with sum = target value.
*/
int pathToTarget(vector<int>& arr, int &n, int tar, int i){
	if(i == n-1){
		if(!tar || tar == arr[i]) return 1;
		return 0;
	}
	int unpick = pathToTarget(arr, n, tar, i+1), pick = 0;
	if(arr[i]<= tar) pick = pathToTarget(arr, n, tar-arr[i], i+1);
	return pick+unpick;
}
int targetSum(int n, int target, vector<int>& arr) {
	int total = accumulate(arr.begin(), arr.end(), 0);
	if(total < target || (total-target)%2) return 0;
	int tar = (total-target)/2;
	return pathToTarget(arr, n, tar, 0);
}

// Tabulation.
int TargetSum(int n, int target, vector<int>& arr) {
    int total = 0;
	for(int i: arr) total += i;
	if(total < target || (total+target)%2) return 0;
	int t = (total-target)/2;
	
	vector<vector<int>>dp(n, vector<int>(t+1, 0));
	for(int i = 0; i<n; ++i) dp[i][0] = 1;
	if(arr[n-1]<= t) dp[n-1][arr[n-1]] = 1;
	
	for(int i = n-2; i>=0; --i){
		for(int j = t; j>0; --j){
			int unpick = dp[i+1][j], pick = 0;
			if(arr[i] <= j) pick = dp[i+1][j-arr[i]];
			dp[i][j] = pick+unpick;
		}
	}
	return dp[0][t];
}

int main(){
    vector<int> arr = {12, 17, 4, 7, 21, 23, 0, 25, 20, 19};
    int target = -38;
    int n = arr.size();
    // Recursion.
    cout<<targetSum(n, target, arr)<<endl;

	// Tabulation.
	cout<<TargetSum(n, target, arr)<<endl;
    return 0;
}