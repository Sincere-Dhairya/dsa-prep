/**
 * @file Partitions With Given Difference
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-14
 * @link https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their 
union is the original array. Let the sum of the elements of these two subsets be ‘S1’ 
and ‘S2’.
Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than 
or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the 
answer may be too large, return it modulo ‘10^9 + 7’.
If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 
are considered different if:
1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices 
set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the 
elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.
For Example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: 
(5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: 
(5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, 
S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
*/
#include<iostream>
#include<vector>
using namespace std;


#define mod (int)1e8+9
int countParts(vector<int>& arr, vector<vector<int>>& cache, int n, int i, int target){
	if(i == n-1){
		if(target == 0 && arr[n-1]==0) return 2;
		if(target==0 || target == arr[n-1]) return 1;
		return 0;
	}
	if(cache[i][target]>-1){
		return cache[i][target];
	}
	long unpick = 0, pick = 0;
	unpick = countParts(arr, cache, n, i+1, target);
	if(target >= arr[i]){
		pick = countParts(arr, cache, n, i+1, target-arr[i]);
	}
	return cache[i][target] = (pick+unpick);
}

int countPartitions(int n, int d, vector<int> &arr){
	int total = 0, sum = 0;
	for(int i: arr) total+= i;
	sum = (total-d)/2;
	if(d>total || (total-d)%2 ) return 0;
	int target = (total-d)/2;
    vector<vector<int>> cache(n, vector<int> (target+1, -1));
    return countParts(arr, cache, n, 0, target);
}

int countPartitions(vector<int>& arr, int d){
    int n = arr.size();
	int total = 0, sum = 0;
	for(int i: arr) total+= i;
	sum = (total-d)/2;
	if(d>total || (total-d)%2 ) return 0;
	int target = (total-d)/2;
    
    vector<vector<int>> cache(n, vector<int>(target+1, 0));

    if(arr[n-1] == 0) cache[n-1][0] = 2;
    else cache[n-1][0] = 1;

    if(arr[n-1] != 0 && arr[n-1] <= target) cache[n-1][arr[n-1]] = 1;

    for(int i = n-2; i>=0; --i){
        for(int j = 1; j<= target; ++j){
            int unpick = cache[i+1][j], pick = 0;
            if(arr[i] <= j) pick = cache[i+1][j-arr[i]];
            cache[i][j] = pick+unpick;
        }
    }
    return cache[0][target];
}

int main(){
    vector<int> arr = {5, 2, 5, 1};
    int d = 3;

    // Recursion.
    cout<<countPartitions(arr.size(), d, arr)<<endl;

    // Tabulation.
    cout<<countPartitions(arr, d)<<endl;
    return 0;
}