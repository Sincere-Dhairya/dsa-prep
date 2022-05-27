/**
 * @file Cost to Cut a Chocolate
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-26
 * @link https://www.codingninjas.com/codestudio/problems/cost-to-cut-a-chocolate_3208460 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given chocolate of ‘N’ length. The chocolate is labeled from 0 to ‘N’. You are also given an array ‘CUTS’ of size ‘C’, denoting the positions at which you can do a cut. The order of cuts can be changed. The cost of one cut is the length of the chocolate to be cut. Therefore, the total cost is the sum of all the cuts. Print the minimum cost to cut the chocolate.
Note:
All the integers in the ‘CUTS’ array are distinct.
For Example:
Let ‘N’ be: 4
Let the ‘CUTS’ array be: [1, 3].

Let the order of doing the cut be [1, 3].
The first cut of 1 on length 4 results in a cost of 4, and chocolate is split into two parts of the length of 1 and 3.
The second cut of 3 on length 3 results in a cost of 3, and chocolate is split into two parts again of the length of 2 and 1. So the total cost is 7.

The cost will remain the same if we change the order of cutting. So the result is 7.
*/

// Recursion + Tabulation.
// TC: Exponential. SC: O(NxN) + callstack of O(N).
int costCalc(vector<vector<int>>& table, vector<int>cuts, int i, int j){
    if(j<i) return 0;
    if(table[i][j]) return table[i][j];
    int mincost = 1e9;
    for(int k = i; k<=j; ++k){
        mincost = min(mincost, costCalc(table, cuts, i, k-1)+ costCalc(table, cuts, k+1, j));
    }
    return table[i][j] = mincost+cuts[j+1]-cuts[i-1];
}

int cost(int n, int c, vector<int> &cuts){
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0),
    cuts.emplace_back(n);
    vector<vector<int>>  table(n, vector<int> (n, 0));
    return costCalc(table, cuts, 1, c);
}

// Tabulation. 
// TC: O(NxNxN), SC: O(NxN)
int cost(int n, int c, vector<int> &cuts){
    cuts.insert(cuts.begin(), 0),
    cuts.emplace_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> table(c+2, vector<int> (c+2, 0));
    
    for(int i = c; i>0; --i){
        for(int j = 1; j<=c; ++j){
            if(j<i) continue;
            int mincost = 1e7;
            for(int k = i; k<=j; ++k){
                mincost = min(
                    mincost, 
                    table[i][k-1]+ table[k+1][j]
                );
            }
            table[i][j] = mincost + cuts[j+1]-cuts[i-1];
        }
    }
    return table[1][c];
}