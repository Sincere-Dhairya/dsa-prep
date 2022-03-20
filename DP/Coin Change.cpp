/**
 * @file Coin Change
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * @link https://www.geeksforgeeks.org/coin-change-dp-7/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N=4, n=3;
    vector<int> coins = {1,2,3};
    vector<vector<int>> table(n, vector<int> (N+1, 0));

    // Marking the number of currencies required to make sum = 0 as 1.
    for(int i = 0; i<n; i++){
        table[i][0] = 1;
    }

    // Marking the number of coins[0]'s required to make sum from 0 to N.
    for(int j = coins[0]; j<=N; ++j){
        table[0][j] = table[0][j-coins[0]];
    }
    
    // Marking the number of rest of currencies required to make sum from 0 to N.
    for(int i=1; i<n; ++i){
        for(int j=1; j<coins[i]; ++j){
            table[i][j] = table[i-1][j];
        }
        for(int j = coins[i]; j<=N; ++j){
            table[i][j] = table[i-1][j]+table[i][j-coins[i]];
        }
    }

    // Printing the table.
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=N; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Ans is : "<<table[n-1][N];
    return 0;
}