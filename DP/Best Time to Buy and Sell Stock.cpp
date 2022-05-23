/**
 * @file Best Time to Buy and Sell Stock
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-23
 * @link https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array/list 'prices' where the elements of the array represent the prices of the stock as they were yesterday and indices of the array represent minutes. Your task is to find and return the maximum profit you can make by buying and selling the stock. You can buy and sell the stock only once.
Note:
You can’t sell without buying first.
For Example:
For the given array [ 2, 100, 150, 120],
The maximum profit can be achieved by buying the stock at minute 0 when its price is Rs. 2 and selling it at minute 2 when its price is Rs. 150.
So, the output will be 148.
*/

// TC: O(N). SC: O(1)
int maximumProfit(vector<int> &prices){
    int maxProfit = 0, maxTillNow = prices.back(), n = prices.end()-prices.begin();
    for(int i = n-2; i>=0; --i){
        maxTillNow = max(maxTillNow, prices[i]);
        maxProfit = max(maxProfit, maxTillNow - prices[i]);
    }
    return maxProfit;
}
