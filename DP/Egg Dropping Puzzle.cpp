/**
 * @file Egg Dropping Puzzle
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * @link https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620 @endlink
 * @copyright Copyright (c) 2022
 * @tags recursion, dynamic-programming
 */
/*
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

For more description on this problem see wiki page

Example 1:

Input:
N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
Example 2:

Input:
N = 2, K = 10
Output: 4
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*(K^2))
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=200
1<=K<=200
*/

#include<iostream>
#include<vector>

using namespace std;

int getMinTrials(int ** table, int eggs, int floors){
    if(eggs == 1){
        return table[eggs][floors] = floors;
    }
    if(floors == 0){
        return table[eggs][floors] = 0;
    }

    int minTrials = 1e9;
    for(int i  =1; i<= floors; ++i){
        minTrials = min(
            minTrials,
            1 + max( getMinTrials(table, eggs-1, i-1), getMinTrials(table, eggs, floors-i))
        );
    }
    return table[eggs][floors] = minTrials;
}

int main(){
    int eggs = 1, floors = 2;
    int ** table = new int* [eggs+1];
    for(int i = 0; i<= eggs; ++i){
        table[i] = new int[floors+1];
        for(int j=0; j<=floors; ++j){
            table[i][j] = -1;
        }
    }
    cout << getMinTrials(table, eggs, floors);
    return 0;
}