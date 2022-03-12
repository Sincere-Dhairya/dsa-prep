/**
 * @file Count number of ways to reach a given score in a game
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * @link https://www.geeksforgeeks.org/count-number-ways-reach-given-score-game/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/*
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of ways to reach the given score.
Examples: 
 

Input: n = 20
Output: 4
There are following 4 ways to reach 20
(10, 10)
(5, 5, 10)
(5, 5, 5, 5)
(3, 3, 3, 3, 3, 5)

Input: n = 13
Output: 2
There are following 2 ways to reach 13
(3, 5, 5)
(3, 10)
*/

#include<bits/stdc++.h>

using namespace std;

int calculateWays(vector<int> & nums, int total){
    vector<int> cache(total+1, 0);

    for(int n : nums){
        cache[n] += 1;
        for(int j = n; j<=total; ++j){
            cache[j] += cache[j-n];
        }
    }
    return cache[total];
}
int main(){
    vector<int> nums = {3, 5, 10};
    int score_total = 13;
    cout<<"The number of ways of getting a score "<<score_total<<" is : "<<calculateWays(nums, score_total)<<endl;
}