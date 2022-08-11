/**
 * @file Minimum cost of reducing Array by merging any adjacent elements repetitively
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * @link https://www.geeksforgeeks.org/minimum-cost-of-reducing-array-by-merging-any-adjacent-elements-repetitively/#:~:text=We%20can%20merge%20two%20adjacent,of%20merging%20all%20the%20numbers.&text=Hence%20the%20total%20cost%20is%2010%20%2B%2010%20%2B%2020%20%3D%2040.&text=Hence%20the%20total%20cost%20is%205%20%2B%205%20%2B%2010%20%3D%2020. @endlink
 * @copyright Copyright (c) 2022
 * @tags dynamic-programming
 */
/*Given an array arr[] of N numbers. We can merge two adjacent numbers into one and the cost of merging the two numbers is equal to the sum of the two values. The task is to find the total minimum cost of merging all the numbers.
Examples: 
 

Input: arr[] = { 6, 4, 4, 6 } 
Output: 40 
Explanation: 
Following is the optimal way of merging numbers to get the total minimum cost of merging of numbers: 
1. Merge (6, 4), then array becomes, arr[] = {10, 4, 6} and cost = 10 
2. Merge (4, 6), then array becomes, arr[] = {10, 10} and cost = 10 
3. Merge (10, 10), then array becomes, arr[] = {20} and cost = 20 
Hence the total cost is 10 + 10 + 20 = 40.
Input: arr[] = { 3, 2, 4, 1 } 
Output: 20 
Explanation: 
Following is the optimal way of merging numbers to get the total minimum cost of merging of numbers: 
1. Merge (3, 2), then array becomes, arr[] = {5, 4, 1} and cost = 5 
2. Merge (4, 1), then array becomes, arr[] = {5, 5} and cost = 5 
3. Merge (5, 5), then array becomes, arr[] = {10} and cost = 10 
Hence the total cost is 5 + 5 + 10 = 20.
*/
#include <iostream>
#include<vector>

using namespace std;

int getMinCost(vector<vector<int>> &table, vector<int>& arr, int left, int right){
    // base case 1.
    if(left == right){
        return arr[left];
    }
    
    if(table[left][right] > -1) return table[left][right];
    int minCost = 1e9;
    
    for(int i = left+1; i<=right; ++i){
        int leftSum = getMinCost(table, arr, left, i-1),
        rightSum = getMinCost(table, arr, i, right);
        int hiddenCost = 0;
        if(left != i-1){ hiddenCost += leftSum; }
        if(right != i) { hiddenCost += rightSum; }
        hiddenCost += (leftSum + rightSum);
        minCost = min(minCost, hiddenCost);
    }
    return table[left][right] = minCost;
}

int main() {
	vector<int> arr = {3,2,4,1};//{6,4,4,6};
	vector<vector<int>> table(arr.size(), vector<int>(arr.size(), -1));
	int minCost = getMinCost(table, arr, 0, arr.size()-1);
	cout << minCost <<endl;
	return 0;
}