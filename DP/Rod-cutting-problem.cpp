/**
 * @file Rod-cutting-problem
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-16
 * @link https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.
*/

// Recursion + Memoization.
int cuttingRod(vector<vector<int>>& cache, vector<int>& price, int target, int i, int n){
	if(i==n){
		return (target/i)*price[i-1];
	}
	if(cache[i][target]) return cache[i][target];
	int unpick = cuttingRod(cache, price, target, i+1, n), pick = 0;
	if(i <= target) pick = price[i-1] + cuttingRod(cache, price, target-i, i, n);
	return cache[i][target] = max(pick, unpick);
}
int cutRod(vector<int> &price, int n){
	vector<vector<int>> cache(n+1, vector<int>(n+1, 0));
	int ans = cuttingRod(cache, price, n, 1, n);
	return ans;
}

// Tabulation. + Optimized.
int cutRod(vector<int> &price, int n){
	vector<int> cache(n+1);
	for(int i = 0; i<=n; ++i){
		cache[i] = (i/n)*price[n-1];
	}
	
	for(int i = n-1; i>0; --i){
		for(int j = 0; j<=n; ++j){
			int unpick = cache[j], pick = 0;
			if(i<= j) pick = price[i-1] + cache[j-i];
			cache[j] = max(pick, unpick);
		}
	}
	return cache[n];
}
