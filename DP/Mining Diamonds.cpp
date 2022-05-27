/**
 * @file Mining Diamonds
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-27
 * @link https://www.codingninjas.com/codestudio/problems/mining-diamonds_4244494 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
There are ‘N’ diamonds in a mine. The size of each diamond is given in the form of 
integer array ‘A’. If the miner mines a diamond, then he gets 'size of previous 
unmined diamond * size of currently mined diamond * size of next unmined diamond' 
number of coins. If there isn’t any next or previous unmined diamond then their 
size is replaced by 1 while calculating the number of coins.
Vladimir, a dumb miner was assigned the task to mine all diamonds. Since he is 
dumb he asks for your help to determine the maximum number of coins that he can 
earn by mining the diamonds in an optimal order.
For Example:
Suppose ‘N’ = 3, and ‘A’ = [7, 1, 8]

The optimal order for mining diamonds will be [2, 1, 3].
State of mine -    [7, 1, 8]    [7, 8]    [8]
Coins earned -    (7*1*8) + (1*7*8) + (1*8*1)  = 56 + 56 + 8 = 120
Hence output will be 120.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100
1 ≤ ΣN ≤ 300

Time limit: 1 Sec
*/

// Recursion + Tabulation.
// TC: Exponential . SC: O(NxN)
int coinCollect(vector<vector<int>>& table, vector<int>& A, int i, int j){
    if(i>j) return 0;
    if(table[i][j]) return table[i][j];
    int point1 = A[i-1]*A[j+1], ans = 0;
    for(int k=i; k<=j; ++k){
        int point2 = point1 * A[k];
        ans = max(
            ans,
            point2+ coinCollect(table, A, i, k-1) + coinCollect(table, A, k+1, j)
        );
    }
    return table[i][j] = ans;
}

int maxCoins(vector<int>& a){
    a.insert(a.begin(), 1),
    a.emplace_back(1);
    int n = a.size();
    vector<vector<int>> table(n, vector<int> (n, 0));
    return coinCollect(table, a, 1, a.size()-2);
}

// Tabulation.
// TC: O(NxNxN), SC: O(NxN)
int maxCoins(vector<int>& A){
    A.insert(A.begin(), 1),
    A.emplace_back(1);
    int n = A.size();
    vector<vector<int>> table(n+1, vector<int> (n+1, 0));
    
    for(int i = n; i>0; --i){
        for(int j = 1; j<n-1; ++j){
            if(i>j) continue;
            int point1 = A[i-1]*A[j+1], ans = 0;
            for(int k=i; k<=j; ++k){
                int point2 = point1 * A[k];
                ans = max(
                    ans,
                    point2+ table[i][k-1] + table[k+1][j]
                );
            }
            table[i][j] = ans;
        }
    }
    return table[1][n-2];
}