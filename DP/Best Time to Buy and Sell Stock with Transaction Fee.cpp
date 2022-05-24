/**
 * @file Best Time to Buy and Sell Stock with Transaction Fee
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * @link https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given chocolate and its prices change each day. Rahul can buy one chocolate at a time, and 
he must sell it before buying chocolate on another day.
To sell and buy the chocolate requires some transaction fee. Given 'N' number of days and an 
array 'PRICES' of size 'N' price of the chocolate each day. and variable 'FEE' fee for the 
transaction. Find the maximum profit Rahul can achieve by trading on the chocolate.
Example:
Input: 'N' = 3, 'PRICES' = [1, 2, 3], 'FEE' = 1
Output: 1

We can generate the maximum profit of 1 cent by buying the chocolate on the first day for 
price = 1 and then selling it on the third day for price = 3.                                                                                                     
The profit will be: 3 - 1 - 1(transaction fee) = 1
*/

// Recursion + Memoization.
// TC: O(2^n), SC: O(N)
int findMaxProfit(vector<vector<int>>& table, vector<int>& prices, int n, int fee, int i, int canBuy){
    if(i==n) return 0;
    if(table[i][canBuy]) return table[i][canBuy];
    int profit = 0;
    if(canBuy){
        profit = max(
            -prices[i]+findMaxProfit(table, prices, n, fee, i+1, 0),
            findMaxProfit(table, prices, n, fee, i+1, 1)
        );
    }
    else{
        profit = max(
            prices[i]+findMaxProfit(table, prices, n, fee, i+1, 1)-fee,
            findMaxProfit(table, prices, n, fee, i+1, 0)
        );
    }
    return table[i][canBuy] = profit;
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> table(n+1, vector<int>(2));
    return findMaxProfit(table, prices, n, fee, 0, 1);
}

// Tabulation.
// TC: O(N), SC: O(Nx2).
int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> table(n+1, vector<int>(2));
    
    for(int i = n-1; i>=0; --i){
        for(int canBuy = 1; canBuy >=0; --canBuy){
            if(canBuy){
                table[i][canBuy] = max(
                    -prices[i]+table[i+1][0],
                    table[i+1][1]
                );
            }
            else{
                table[i][canBuy] = max(
                    prices[i]+table[i+1][1]-fee,
                    table[i+1][0]
                );
            }
        }
    }
    return table[0][1];
}

// Space Optimized
int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> table(n+1, vector<int>(2));
    vector<int> curr(2), next(2);
    for(int i = n-1; i>=0; --i){
        curr[1] = max(-prices[i]+next[0], next[1]);
        curr[0] = max(prices[i]+next[1]-fee, next[0]);
        next = curr;
    }
    return curr[1];
}