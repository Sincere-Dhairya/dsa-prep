/**
 * @file Ways To Make Coin Change
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-15
 * @link https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an infinite supply of coins of each of denominations 
D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, 
in which you can make a change for value V using coins of denominations from D. 
Print 0, if a change isn't possible.
*/
#include<iostream>
#include<vector>
using namespace std;

long countWays(vector<vector<long>>& cache, int* denos, int n, int target, int i){
	if(i == n-1){
		return target%denos[n-1]==0;
	}
	if(cache[i][target]) return cache[i][target];
	long unpick = countWays(cache, denos, n, target, i+1), pick = 0;
	if(denos[i] <= target) pick = countWays(cache, denos,n,target-denos[i], i);
	return cache[i][target] = pick+unpick;
}

long countWaysToMakeChange(int *denominations, int n, int value){
	vector<vector<long>> cache(n, vector<long>(value+1));
    return countWays(cache, denominations, n, value, 0);
}
long countWaysToMakeChange(int *arr, int n, int value){
	int total = 0;
	for(int i = 0; i<n; ++i) total += arr[i];
	int tar = value;
	
	vector<vector<long>> cache(n, vector<long>(tar+1, 0));
	for(int i = 0; i<= tar; ++i){
		if(i%arr[n-1] == 0) cache[n-1][i] = 1;
	}
	
	for(int i = n-2; i>=0; --i){
		for(int j = 0; j<= tar; ++j){
			long unpick = cache[i+1][j], pick = 0;
			if(arr[i] <= j) pick = cache[i][j-arr[i]];
			cache[i][j] = pick+unpick;
		}
	}

	return cache[0][tar];
}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10, target = 1000, *ptr = arr;
    // Recursion.
    cout<<countWaysToMakeChange(arr, n, target)<<endl;
    return 0;
}