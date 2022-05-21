/**
 * @file 322. Coin Change
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-21
 * @link https://leetcode.com/problems/coin-change/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
*/

// TC- O(2^N). SC - O(Amount/smallest(Coins)) + O(Amount*N).
// Recursion. + Memoization.
class Solution {
public:
    int countCoins(vector<vector<int>>& table, vector<int>& coins, int amount, int i){
        if(i==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }
        if(table[i][amount]) return table[i][amount];
        int unpick = countCoins(table, coins, amount, i-1), pick = 1e9;
        if(coins[i] <= amount){
            pick = 1 + countCoins(table, coins, amount-coins[i], i);
        }
        return table[i][amount] = min(pick, unpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> table(n, vector<int>(amount+1));
        int ans = countCoins(table, coins, amount, coins.size()-1);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

// Tabulation.
// TC - O(N*Amount). SC - O(N*Amount).
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> table(n, vector<int>(amount+1));
        
        for(int i = 0; i<=amount; ++i){
            if(i%coins[0] == 0){
                table[0][i] = i/coins[0];
            }
            else{
                table[0][i] = 1e9;
            }
        }
        
        for(int i = 1; i<n; ++i){
            for(int j = 0; j<= amount; ++j){
                int unpick = table[i-1][j], pick = 1e9;
                if(coins[i] <= j){
                    pick = 1+table[i][j-coins[i]];
                }
                table[i][j] = min(pick, unpick);
            }
        }
        
        if(table[n-1][amount] >= 1e9) return -1;
        return table[n-1][amount];
    }
};

// Space Optimized Tabulation. SC - O(Amount).
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> table(amount+1);
        
        for(int i = 0; i<=amount; ++i){
            if(i%coins[0] == 0){
                table[i] = i/coins[0];
            }
            else{
                table[i] = 1e9;
            }
        }
        
        for(int i = 1; i<n; ++i){
            for(int j = 0; j<= amount; ++j){
                int unpick = table[j], pick = 1e9;
                if(coins[i] <= j){
                    pick = 1+table[j-coins[i]];
                }
                table[j] = min(pick, unpick);
            }
        }
        
        if(table[amount] >= 1e9) return -1;
        return table[amount];
    }
};