/**
 * @file Minimum Coin Change
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * @link https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/*
Given a value V, if we want to make a change for V cents, and we have an infinite supply of each of C = { C1, C2, .., Cm} valued coins, what is the minimum number of coins to make the change? If it’s not possible to make a change, print -1.

Examples:  

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
*/

#include<bits/stdc++.h>
using namespace std;

/*Test Cases
19 6
7 12 2 9 5 3
*/
int main(){
    vector<int> coins = {7,12,2,9,5,3};
    int N = 19, n=coins.size();
    vector<vector<int>> table (n, vector<int> (N+1, 0));

    // Marking the number of coins[0]'s required to make sum = 0 to N;
    table[0][coins[0]] = 1;
    for(int i=coins[0]+1; i<=N; ++i){
        if(table[0][i-coins[0]]){
            table[0][i] = table[0][i-coins[0]]+1;
        }
    }

    // 
    for(int i = 1; i<n; ++i){
        for(int j = 1; j<coins[i]; ++j){
            table[i][j] = table[i-1][j];
        }
        table[i][coins[i]] = 1;
        for(int j = coins[i]+1; j<=N; ++j){
            if(table[i-1][j]){
                if(table[i][j-coins[i]]){
                    table[i][j] = min(table[i-1][j], table[i][j-coins[i]]+1);
                }
                else{
                    table[i][j] = table[i-1][j];
                }
            }
            else{
                table[i][j] = (table[i][j-coins[i]])?(table[i][j-coins[i]]+1):0;
            }
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