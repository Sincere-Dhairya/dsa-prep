/**
 * @file Fractional Knapsack
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-18
 * @link https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/# @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given weights and values of N items, we need to put these items in a knapsack of 
capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
 

Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array of 
structure/class and size n and returns a double value representing the maximum value 
in knapsack.
Note: The details of structure/class is defined in the comments above the given function.


Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)


Constraints:
1 <= N <= 10^5
1 <= W <= 10^5
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

// Keep it out of the Solution Class.
bool Compare(struct Item & a, struct Item& b){
    double a1 = double(a.value)/double(a.weight), b1= double(b.value)/double(b.weight);
    return a1>b1;
}

double fractionalKnapsack(int W, Item arr[], int n){
    // Your code here
    sort(arr, arr+n, Compare);
    double finalvalue = 0;
    for(int i = 0; i<n; ++i){
        if(arr[i].weight <= W){
            finalvalue += arr[i].value;
            W -= arr[i].weight;
        }
        else{
            finalvalue += arr[i].value * ((double)W/ (double)arr[i].weight);
            W = 0;
            break;
        }
    }
    return finalvalue;
}