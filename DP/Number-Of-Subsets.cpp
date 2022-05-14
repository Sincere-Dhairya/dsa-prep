/**
 * @file Number Of Subsets
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-12
 * @link https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array (0-based indexing) of positive integers and you have to tell 
how many different ways of selecting the elements from the array are there such that 
the sum of chosen elements is equal to the target number “tar”.
Note:
Two ways are considered different if sets of indexes of elements chosen by these ways 
are different.

Input is given such that the answer will fit in a 32-bit integer.

If N = 4 and tar = 3 and the array elements are [1, 2, 2, 3], then the number of 
possible ways are:
{1, 2}
{3}
{1, 2}
Hence the output will be 3.
*/
#include<iostream>
#include<vector>

using namespace std;

int numOfSubsets(vector<int>& nums, int n, int i, int sum){
	if(!sum){
		return 1;
	}
	if(i >= n || sum <0){
		return 0;
	}

	int unpick = numOfSubsets(nums, n, i+1, sum),
	pick = 0;
	if(nums[i] <= sum){
		pick = numOfSubsets(nums, n, i+1, sum-nums[i]);
	}
	return pick+unpick;
}

int numOfSubsets(vector<int>& nums, int tar){
	int n = nums.end()-nums.begin();
	vector<vector<int>> cache(n, vector<int>(tar+1, 0));
	for(int i = 0; i<n; ++i) cache[i][0] = 1;
	if(nums[n-1] <= tar) cache[n-1][nums[n-1]] = 1;
	
	for(int i = n-2; i>=0; --i){
		for(int j = 1; j<=tar; ++j){
			int unpick = cache[i+1][j], pick= 0;
			if(nums[i] <= j) pick = cache[i+1][j-nums[i]];
			cache[i][j] = pick+unpick;
		}
	}
	return cache[0][tar];
}

int NumOfSubsets(vector<int>& num, int& tar){
	int n = num.size();
	vector<int> prev(tar+1,0), curr(tar+1,0);
	prev[0] = 1, curr[0] = 1;
	if(num[n-1] <= tar) prev[num[n-1]] = 1;
	
	for(int i = n-2; i>=0; --i){
		for(int j = 1; j<=tar; ++j){
			int notpick = prev[j], pick = 0;
			if(num[i] <= j) pick = prev[j-num[i]];
			curr[j] = pick+notpick;
		}
		prev = curr;
	}
	return prev[tar];
}

int main()
{
    // Write your code here.
    vector<int> num = {1,2,2,3};
    int tar = 3;
	int n = num.end()-num.begin();

    // Recursion.
    cout<<numOfSubsets(num, tar)<<endl;

    // Tabulation.
    cout<<NumOfSubsets(num, tar)<<endl;
	return 0;
}