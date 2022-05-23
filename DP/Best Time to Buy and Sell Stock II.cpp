/**
 * @file Best Time to Buy and Sell Stock II
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-23
 * @link https://www.codingninjas.com/codestudio/problems/selling-stock_630282 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You have been given stock values/prices for N number of days. Every i-th day signifies 
the price of a stock on that day. Your task is to find the maximum profit which you can 
make by buying and selling the stocks.
 Note :
You may make as many transactions as you want but can not have more than one transaction 
at a time i.e, if you have the stock, you need to sell it first, and then only you can 
buy it again.
*/

// Recursion + Memoization. 
// TC: O(2^N), SC: O(N)
long maxProfit(vector<vector<long>>& cache, long* values, int i, bool canBuy, int& n){
    if(i==n){
        return 0;
    }
    if(cache[i][canBuy]) return cache[i][canBuy];
    long profit = 0;
    if(canBuy){
        profit = max(-values[i]+maxProfit(cache, values, i+1, 0, n), maxProfit(cache, values, i+1, 1, n));
    }
    else{
        profit = max(values[i]+maxProfit(cache, values, i+1, 1, n), maxProfit(cache, values, i+1, 0, n));
    }
    return cache[i][canBuy]=profit;
}

long getMaximumProfit(long *values, int n){
    vector<vector<long>> cache(n, vector<long>(2));
    return maxProfit(cache, values, 0, 1, n);
}

// Tabulation. 
// TC: O(N), SC:O(N).
long getMaximumProfit(long *values, int n){
    vector<vector<long>> cache(n+1, vector<long>(2));
    for(int i=n-1; i>=0; --i){
        for(int j=0; j<2; ++j){
            if(j){
                cache[i][j] = max(-values[i]+cache[i+1][0], cache[i+1][1]);
            }
            else{
                cache[i][j] = max(values[i]+cache[i+1][1], cache[i+1][0]);
            }
        }
    }
    return cache[0][1];
}

// Space Optimization can be done easily with the help of 2: 1x2 matrices, prev and curr.