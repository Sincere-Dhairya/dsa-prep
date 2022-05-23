/**
 * @file Best Time to Buy and Sell Stock III
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-23
 * @link https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
/*
Problem Statement
You are Harshad Mehta’s friend. He told you the price of a particular stock for 
the next ‘N’ days. You can either buy or sell a stock. Also, you can only complete 
at most 2-transactions. Find the maximum profit that you can earn from these 
transactions. You can take help from Mr. Mehta as well.
Note
1. Buying a stock and then selling it is called one transaction. 
2. You are not allowed to do multiple transactions at the same time. This means 
you have to sell the stock before buying it again.
*/

// Recurion + Memoization.
// TC: Exponential , SC: O(N)
int f(vector<vector<vector<int>>>& cache, vector<int>& prices, int n, int i, int canBuy, int limit){
    if(i==n || limit==2){
        return 0;
    }
    if(cache[i][canBuy][limit]) return cache[i][canBuy][limit];
    int profit = 0;
    if(canBuy){
        profit = max(-prices[i]+f(cache, prices, n, i+1, 0, limit), f(cache, prices, n, i+1, 1, limit));
    }
    else{
        profit = max(prices[i]+f(cache, prices, n, i+1, 1, limit+1), f(cache, prices, n, i+1, 0, limit));
    }
    return cache[i][canBuy][limit] = profit;
}

int maxProfit(vector<int>& prices, int n){
    vector<vector<vector<int>>> cache(n+1, vector<vector<int>>( 2, vector<int>(3)));
    return f(cache, prices, n, 0, 1, 0);
}

/// Tabulation.
// TC: O(Nx2x3),  SC: O(Nx2x3)
int maxProfit(vector<int>& prices, int n){
    vector<vector<vector<int>>> cache(n+1, vector<vector<int>>( 2, vector<int>(3)));
    for(int i=n-1; i>=0; --i){
        for(int j = 0; j<2; ++j){
            for(int lt =0; lt<2;++lt){
                if(j){
                    cache[i][j][lt] = max(-prices[i]+cache[i+1][0][lt], cache[i+1][1][lt]);
                }
                else{
                    cache[i][j][lt] = max(prices[i]+cache[i+1][1][lt+1], cache[i+1][0][lt]);
                }
            }
        }
    }
    return cache[0][1][0];
}

// Better Space Optimized Approach. Recursion and Memoization.
int f(vector<vector<int>>& table, vector<int>& prices, int &n, int i, int limit){
    if(i==n || limit==4) return 0;
    if(table[i][limit]) return table[i][limit];
    int profit = 0;
    if(limit%2){
        profit = max(prices[i] + f(table, prices, n, i+1, limit+1), f(table, prices, n, i+1, limit));
    }
    else{
        profit = max(-prices[i]+f(table, prices, n, i+1, limit+1), f(table, prices, n, i+1, limit));
    }
    return table[i][limit] = profit;
}

int maxProfit(vector<int>& prices, int n){
    vector<vector<int>>table (n+1, vector<int>(4));
    return f(table, prices, n, 0, 0);
}

// Tabulation.
// TC: O(Nx4), SC: O(Nx4) that can be further reduced to O(1) by using next and curr 2d vectors.
int maxProfit(vector<int>& prices, int n){
    vector<vector<int>>table (n+1, vector<int>(5));
    for(int i=n-1; i>=0; --i){
        for(int j=0; j<4; ++j){
            if(j%2){
                table[i][j] = max(prices[i]+table[i+1][j+1], table[i+1][j]);
            }
            else{
                table[i][j] = max(-prices[i]+table[i+1][j+1], table[i+1][j]);
            }
        }
    }
    
    return table[0][0];
}