/**
 * @file Best Time to Buy and Sell Stock with Cooldown
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * @link https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given a list of stock prices, ‘prices’. Where ‘prices[i]’ represents the price 
on ‘i’th day. Your task is to calculate the maximum profit you can earn by trading stocks 
if you can only hold one stock at a time. After you sell your stock on the ‘i’th day, you 
can only buy another stock on ‘i + 2’ th day or later.
For Example:
You are given prices = {4, 9, 0, 4, 10}, To get maximum profits you will have to buy on day 0 
and sell on day 1 to make a profit of 5, and then you have to buy on day 3  and sell on day 4 
to make the total profit of 11. Hence the maximum profit is 11.
*/

// Recursion + Memoization.
int findMaxProfit(vector<vector<int>>& table, vector<int>& prices, int n, int i, int canBuy){
    if(i>=n) return 0;
    if(table[i][canBuy]) return table[i][canBuy];
    int profit= 0;
    if(canBuy){
        profit = max(
            -prices[i] + findMaxProfit(table, prices, n, i+1, 0),
            findMaxProfit(table, prices, n, i+1, 1)
        );
    }
    else{
        profit = max(
            prices[i] + findMaxProfit(table, prices, n, i+2, 1),
            findMaxProfit(table, prices, n, i+1, 0)
        );
    }
    return table[i][canBuy] = profit;
}

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> table(n, vector<int>(2));
    return findMaxProfit(table, prices, n, 0, 1);
}

// Tabulation.
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> table(n+2, vector<int>(2));
    
    for(int i= n-1; i>=0; --i){
        for(int j=0; j<2; ++j){
            if(!j){
                table[i][j] = max(
                    -prices[i]+table[i+1][1],
                    table[i+1][0]
                );
            }
            else{
                table[i][j] = max(
                    prices[i]+table[i+2][0],
                    table[i+1][1]
                );
            }
        }
    }
    return table[0][0];
}