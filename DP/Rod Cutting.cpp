/**
 * @file Rod Cutting
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * @link https://www.geeksforgeeks.org/cutting-a-rod-dp-13/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is the cost of sub-length.

Time limit: 1 sec.
*/
#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int> & prices){
    int n = prices.size();
    vector<int> bestPrice(n+1, 0);
    bestPrice[1] = prices[0];

    for(int i = 2; i<=n; ++i){
        for(int j = i; j>0; --j){
            bestPrice[i] = max(bestPrice[i], prices[j-1]+bestPrice[i-j]);
        }
    }
    return bestPrice[n];
}

int main(){
    vector<int> prices = {3, 5, 8, 9, 10, 17, 17, 20};
    cout<<cutRod(prices)<<endl;
}