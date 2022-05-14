/**
 * @file Partition a set into two subsets such that the difference of subset sums is minimum
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-11
 * @link https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494 @endlink
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>

using namespace std;


// Recursion.
int subsetDifference(vector<int>& arr, int n, int i, int sum, int total){
	if(i == n){
		return abs(total - 2*sum);
	}
	int diffwithpick = subsetDifference(arr, n, i+1, sum+arr[i], total),
	diffwithoutpick = subsetDifference(arr, n, i+1, sum, total),
	diff = abs(total - 2*sum);
	return min(diffwithpick, min(diffwithoutpick, diff));
}

// Tabulation.
int minSubsetSumDifference(vector<int>& arr, int n){
	// Write your code here.
	int sum = 0;
	for(int i: arr)
		sum+= i;
	vector<vector<bool>> table(n, vector<bool>(sum+1,0));
	for(int i=0; i<n; ++i){
		table[i][0] = 1;
		if(arr[i] <= sum)
			table[i][arr[i]] = 1;
	}
	
	for(int i = n-2; i>=0; --i){
		for(int j = 1; j<= sum; ++j){
			bool unpick = table[i+1][j], pick = false;
			if(arr[i] <= j)
				pick = table[i+1][j-arr[i]];
			table[i][j] = pick|unpick;
		}
	}
	
	int minsum = 1e9;
	for(int i = 0; i<sum/2; ++i){
		if(table[0][i])
			minsum = min(minsum, abs(sum- 2*i));
	}
	return minsum;
}

bool minSubsetSumDifference(vector<int> &arr){
	int n = arr.size(), sum = 0;
	for(int i: arr)
		sum+= i;
	vector<bool> table(sum+1,0);

	table[0] = 1;

	if(arr[n-1] <= sum)
		table[arr[n-1]] = 1;
	
	for(int i = n-2; i>=0; --i){
		for(int j = 1; j<= sum; ++j){
			bool unpick = table[j], pick = false;
			if(arr[i] <= j)
				pick = table[j-arr[i]];
			table[j] = table[j]|pick;
		}
	}
	
	int minsum = 1e9;
	for(int i = 0; i<sum/2; ++i){
		if(table[i])
			minsum = min(minsum, abs(sum- 2*i));
		//cout<<minsum<<endl;
	}
	return minsum;
}

int main(){
	vector<int> arr = {3,2,7};

	// Recursion.
	int n = arr.size(), sum = 0;
	cout<<subsetDifference(arr, n, 0, 0, 12)<<endl;

	// Tabulation.
	cout<<minSubsetSumDifference(arr)<<endl;

	// Tabulation Space Optimized.
	cout<<minSubsetSumDifference(arr)<<endl;
	return 0;
}