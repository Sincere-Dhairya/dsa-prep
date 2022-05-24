/**
 * @file Best Time to Buy and Sell Stock IV
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * @link https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You have been given an array 'PRICES' consisting of 'N' integers where PRICES[i] denotes
 the price of a given stock on the i-th day. You are also given an integer 'K' denoting 
 the number of possible transactions you can make.
Your task is to find the maximum profit in at most K transactions. A valid transaction 
involves buying a stock and then selling it.
Note
You can’t engage in multiple transactions simultaneously, i.e. you must sell the stock 
before rebuying it.
For Example
Input: N = 6 , PRICES = [3, 2, 6, 5, 0, 3] and K = 2.
Output: 7

Explanation : The optimal way to get maximum profit is to buy the stock on day 2(price = 2) 
and sell it on day 3(price = 6) and rebuy it on day 5(price = 0) and sell it on 
day 6(price = 3). The maximum profit will be (6 - 2) + (3 - 0) = 7.
*/

// Recursion + Memoization.
int findMaxProfit(vector<vector<vector<int>>>& table, vector<int>& prices, int& n, int i, int canBuy, int k){
    if(k==0 || i==n){
        return 0;
    }
    if(table[i][canBuy][k]) return table[i][canBuy][k];
    int profit = 0;
    if(canBuy){
        profit = max(
            -prices[i]+findMaxProfit(table, prices, n, i+1, 0, k),
            findMaxProfit(table, prices, n, i+1, 1, k)
        );
    }
    else{
        profit = max(
            prices[i]+findMaxProfit(table, prices, n, i+1, 1, k-1),
            findMaxProfit(table, prices, n, i+1, 0, k)
        );
    }
    return table[i][canBuy][k] = profit;
}

int maximumProfit(vector<int> &prices, int n, int k){
    vector<vector<vector<int>>> table(n, vector<vector<int>>(2, vector<int>(k+1)));
    return findMaxProfit(table, prices, n, 0, 1, k);
}

// 2 D vector approach
int findMaxProfit(vector<vector<int>>& table, vector<int>& prices, int n, int i, int k){
    if(i==n || k==0){
        return 0;
    }
    
    int profit = 0;
    if(k%2){
        profit = max(
            prices[i]+ findMaxProfit(table, prices, n, i+1, k-1),
            findMaxProfit(table, prices, n, i+1, k)
        );
    }
    else{
        profit = max(
            -prices[i]+findMaxProfit(table, prices, n, i+1, k-1),
            findMaxProfit(table, prices, n, i+1, k)
        );
    }
    return profit;
}

int maximumProfit(vector<int> &prices, int n, int k){
    vector<vector<int>>table (n, vector<int>(2*k+1));
    return findMaxProfit(table, prices, n, 0, 2*k);
}

// Tabulation.
int maximumProfit(vector<int> &prices, int n, int k){
    vector<vector<int>> table(n+1, vector<int>(2*k+1));
    
    for(int i=n-1; i>=0; --i){
        for(int j=0; j<2*k; ++j){
            if(j%2){
                table[i][j] = max(
                    prices[i]+table[i+1][j+1],
                    table[i+1][j]
                );
            }
            else{
                table[i][j] = max(
                    -prices[i]+table[i+1][j+1],
                    table[i+1][j]
                );
            }
        }
    }
    return table[0][0];
}
