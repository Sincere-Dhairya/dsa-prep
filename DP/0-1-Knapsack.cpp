/**
 * @file 0 1 Knapsack
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-14
 * @link https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Problem Statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and the ith item weighs wi and is of value vi. Considering the 
constraints of the maximum weight that a knapsack can carry, you have to find and 
return the maximum value that a thief can generate by stealing items.
*/
#include<iostream>
#include<vector>
using namespace std;


int maxValueKnapsack(vector<vector<int>>& cache, vector<int>& weight, vector<int>& value, int &n, int target, int i){
	if(i == n-1){
		if(target >= weight[i]) return cache[i][target] = value[i];
		return cache[i][target] = 0;
	}
    if(cache[i][target] > -1) return cache[i][target];
	int unpick = maxValueKnapsack(cache, weight, value, n, target, i+1), pick = 0;
	if(weight[i] <= target) 
		pick = value[i] + maxValueKnapsack(cache, weight, value, n, target-weight[i], i+1);
	return cache[i][target] = max(pick, unpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
	vector<vector<int>> cache(n, vector<int> (maxWeight+1, -1));
	return maxValueKnapsack(cache, weight, value, n, maxWeight, 0);
}

int knapsack(vector<int>& weight, vector<int>& value, int target ){
    int n = weight.size();
    vector<vector<int>> cache(n, vector<int>( target+1, 0));
    for(int i = weight[n-1]; i<=target; ++i) cache[n-1][i] = value[n-1];

    for(int i = n-2; i>=0; --i){
        for(int j = 1; j<= target; ++j){
            int unpick = cache[i+1][j], pick = 0;
            if(weight[i] <= j) pick = value[i] + cache[i+1][j-weight[i]];
            cache[i][j] = max(pick, unpick);
        }
    }
    return cache[0][target];
}

int KnapSack(vector<int>& weight, vector<int>& value,  int target){
    int n = weight.size();
    vector<int> dp(target+1, 0);

    for(int i = weight[n-1]; i<= target; ++i) dp[i] = value[n-1];

    for(int i = n-2; i>=0; --i){
        for(int j = target; j>= 0; --j){
            int unpick = dp[j], pick = 0;
            if(weight[i] <= j) pick = value[i]+dp[j-weight[i]];
            dp[j] = max(pick, unpick);
        }
    }
    return dp[target];
}

int main(){
    vector<int> weight = {
        25, 4, 25, 49, 9, 11, 31, 5, 37, 7, 11, 47, 37, 1, 33, 25, 29, 11, 1, 41, 19, 14, 43, 21, 1 ,21, 23 ,37, 12 ,11 ,45 ,13 ,36 ,11 ,17
    }, value = {
        86, 55, 17 ,31 ,88 ,82 ,27 ,57 ,18 ,1, 61, 56, 36, 82 ,51 ,85 ,55 ,21 ,11 ,76, 91, 36, 85, 32, 99, 43, 41, 61, 41, 28, 83, 27, 35, 61 ,16    
    };
    int n = weight.size(), maxWeight = 869;
    
    // Recursion.
    cout<<knapsack(weight, value, n, maxWeight)<<endl;

    // Tabulation.
    cout<<knapsack(weight, value, maxWeight)<<endl;

    // Tabulation. Optimized space
    cout<<KnapSack(weight, value, maxWeight)<<endl;
    return 0;
}