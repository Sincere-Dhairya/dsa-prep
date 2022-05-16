/**
 * @file Unbounded Knapsack
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-16
 * @link https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with 
weight capacity ‘W’. You need to fill the knapsack with the items in such a way 
that you get the maximum profit. You are allowed to take one item multiple times.
Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
'PROFIT' = { 5, 11, 13 }
'WEIGHT' = { 2, 4, 6 }

We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 i.e ‘27’. Therefore maximum profit = 27.
*/
#include<iostream>
#include<vector>
using namespace std;


// Recursion + Memoization.
int Path(vector<vector<int>>& cache, vector<int>& weights, vector<int>& profit, int i, int n, int target){
	if(i==n-1){
		return cache[i][target] = (target/weights[n-1])*profit[n-1];
	}
	if(cache[i][target]) return cache[i][target];
	int unpick = Path(cache, weights, profit, i+1, n, target), pick = 0;
	if(target >= weights[i]) pick = Path(cache, weights, profit, i, n, target-weights[i])+profit[i];
	return cache[i][target] = max(pick, unpick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
	vector<vector<int>> cache(n, vector<int> (w+1, 0));
    return Path(cache, weight, profit, 0, n, w);
}

// Tabulation.
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> cache(n, vector<int>(w+1));
	
	for(int i = 0; i<= w; ++i){
		cache[n-1][i] = (i/weight[n-1])*profit[n-1];
	}
	
	for(int i = n-2; i>=0; --i){
		for(int j = 0; j<= w; ++j){
			int unpick = cache[i+1][j], pick = 0;
			if(weight[i] <= j) pick = profit[i]+cache[i][j-weight[i]];
			cache[i][j] = max(pick, unpick);
		}
	}
	
	return cache[0][w];
}

// Tabulation Space optimized
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> cache(w+1);
	
	for(int i = 0; i<= w; ++i){
		cache[i] = (i/weight[n-1])*profit[n-1];
	}
	
	for(int i = n-2; i>=0; --i){
		for(int j = 0; j<= w; ++j){
			int unpick = cache[j], pick = 0;
			if(weight[i] <= j) pick = profit[i]+cache[j-weight[i]];
			cache[j] = max(pick, unpick);
		}
	}
	
	return cache[w];
}
