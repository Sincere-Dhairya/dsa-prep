/**
 * @file Partition Equal Subset Sum
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-11
 * @link https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can 
partition the given array into two subsets such that the sum of elements in both 
subsets is equal.
For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can be 
partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.
Follow Up:
Can you solve this using not more than O(S) extra space, where S is the sum of all 
elements of the given array?
*/
#include<iostream>
#include<vector>
using namespace std;

bool sequenceAnaliser(vector<int>& arr, int n, int sum, int i){
	if(sum<0 || i >= arr.size()){
		return false;
	}
	if(!sum){
		return true;
	}
	bool unpick = sequenceAnaliser(arr, n, sum, i+1), pick = false;
	if(arr[i] <= sum){
		pick = sequenceAnaliser(arr, n, sum-arr[i], i+1);
	}
	return unpick|pick;
}

bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i: arr){
		sum += i;
	}
	if(sum&1){
		return false;
	}
	sum /= 2;
	return sequenceAnaliser(arr, n, sum, 0);
}

bool canPartition(vector<int> &arr)
{
	int n = arr.size(), sum = 0;
	for(int i: arr){
		sum += i;
	}
	if(sum&1){
		return false;
	}
	sum /= 2;
	
	vector<vector<bool>> table(n, vector<bool>(sum+1, 0));
	for(int i=0; i<n; ++i){
		table[i][0] = 1;
	}
	
	if(arr[n-1] <= sum){
		table[n-1][arr[n-1]] = 1;
	}
	
	for(int i = n-2; i>=0; --i){
		for(int j = 1; j<=sum; ++j){
			bool unpick = table[i+1][j], pick = false;
			if(arr[i] <= j){
				pick = table[i+1][j-arr[i]];
			}
			table[i][j] = pick|unpick;
		}
	}
	return table[0][sum];
}

bool CanPartition(vector<int> &arr){
	int n = arr.size();
	int sum = 0;
	for(int i: arr){
		sum += i;
	}
	if(sum&1){
		return false;
	}
	sum /= 2;
	
	vector<bool> table(sum+1, 0);
	table[0] = 1;
	
	if(arr[n-1] <= sum){
		table[arr[n-1]] = 1;
	}
	
	for(int i = n-2; i>=0; --i){
		for(int j = 1; j<=sum; ++j){
			bool unpick = table[j], pick = false;
			if(arr[i] <= j){
				pick = table[j-arr[i]];
			}
			table[j] = pick|unpick;
		}
	}
	return table[sum];
}

int main(){
	vector<int> arr = {4,3,2,1};

	// Recursion.
	int n = arr.size();
	cout<<canPartition(arr, n)<<endl;

	// Tabulation.
	cout<<canPartition(arr)<<endl;

	// Tabulation Space Optimized.
	cout<<CanPartition(arr)<<endl;
	return 0;
}