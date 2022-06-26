/**
 * @file 1423. Maximum Points You Can Obtain from Cards
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * @link https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/ @endlink
 * @copyright Copyright (c) 2022
 * @tags sliding-window dp
 */
/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

Constraints:

1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length
*/

// Brute Force using Recursion and Memoization gave TLE
// TC: O(NxN) SC: O(NxN)
class Solution {
public:
    int playGame(vector<vector<int>>& table, vector<int>& C, int k, int i, int j){
        if(k<=0 || i>j) return 0;
        
        if(table[i][j] > -1) return table[i][j];
        // picking the left;
        int left = C[i] + playGame(table, C, k-1, i+1, j),
        // picking the right;
        right = C[j] + playGame(table, C, k-1, i, j-1);
        
        return table[i][j] = max(left, right);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<vector<int>> table(n, vector<int> (n, -1));
        return playGame(table, cardPoints, k, 0, cardPoints.size()-1);
    }
};

// Sliding Window.
// To find the maximum score possible, we will be finding the sub array with minimum score that will be left in the end
// then subtracting the sum from the total sum of the array will give us the answer.
class Solution {
public:
    int maxScore(vector<int>& C, int k) {
        int total = accumulate(C.begin(), C.end(), 0), res = C.size() - k, sum = 0;
        
        for(int i = 0; i<res; ++i){
            sum += C[i];
        }
        
        int minSum = sum;
        
        for(int left = 0, right= res; right < C.size(); ++right, ++left){
            sum -= C[left],
            sum += C[right];
            minSum = min(minSum, sum);
        }
        
        return total - minSum;
    }
};