/**
 * @file Find-the-Array-formed-by-performing-Q-queries-on-an-empty-array
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * @link https://www.geeksforgeeks.org/find-the-array-formed-by-performing-q-queries-on-an-empty-array/ @endlink
 * @copyright Copyright (c) 2022
 * @tags binary-search
 */
/*
Consider an integer sequence S, which is initially empty (i.e. S = {}). Also given are Q queries, each of which is one of the following types:

1 a b: Insert a and b into the sequence S.
2 a b: In the sequence S, among the elements that are less than or equal to a, print b-th largest element. If no such element exist, print -1.
3 a b: In the sequence S, among the elements that are greater than or equal to a, print b-th smallest element. If no such element exist, print -1
The task is to print the final sequence formed after performing all the Q queries.

Examples:

Input: Q = 7, A = {{1, {20, 10}}, {1, {30, 20}}, {3, {15, 1}}, {3, {15, 2}}, {3, {15, 3}}, {3, {15, 4}}, {2, {100, 5}} }
Output: 20, 20, 30, -1, -1
Explanation: Initially sequence S={}. 
=> After execution of initial 2 queries, it becomes: {20, 10, 30, 20}.
=> In the sequence, elements greater than 15 are 20, 20 and 30. In 3rd query, we have to print the 1st smallest number greater than or equal to 15 which is 20.
=> Similarly, 2nd and 3rd smallest integer which are greater than 15 are 20 and 30 respectively. Now, 6th query asks us the 4th smallest integer which is greater than or equal to 15. But, there are only 3 integers greater than 15, so we print -1. => The last Query asks us the 5th largest integer in the integers less than or equal to 100. But, there are only 4 integers (10, 20, 20, 30), which are less than or equal to 100. So, we print -1.

Input: Q = 6, A = {{1, {5, 7}}, {1, {2, 15}}, {1, {11, 16}}, {3, {14, 2}}, {2, {11, 3}}, {2, {10, 10}} }
Output: 16, 5, -1
*/

// Binary Search.
#include<bits/stdc++.h>
using namespace std;

void solveQueries(vector<pair<int, pair<int, int>>>& Queries, int& Q){
    vector<int> arr, response;

    for(int i = 0; i<Q; ++i){
        int q = Queries[i].first, 
        a = Queries[i].second.first,
        b = Queries[i].second.second;

        if(q == 1){
            vector<int>::iterator it = upper_bound(arr.begin(), arr.end(), a);
            arr.insert(it, a);

            it = upper_bound(arr.begin(), arr.end(), b);
            arr.insert(it, b);
        }
        else if(q == 2){
            int ind = upper_bound(arr.begin(), arr.end(), a) - arr.begin(),
            requiredInd = ind-b;

            if(requiredInd <= -1){
                response.emplace_back(-1);
            }
            else{
                response.emplace_back(arr[requiredInd]);
            }
        }
        else{
            int ind = lower_bound(arr.begin(), arr.end(), a) - arr.begin(),
            requiredInd = ind+b-1;

            if(requiredInd >= arr.size()){
                response.emplace_back(-1);
            }
            else{
                response.emplace_back(arr[requiredInd]);
            }
        }
    }

    // Printing the arr.
    for(int i : arr){
        cout<<i<<", ";
    }
    cout<<endl;

    // Printing the response array.
    for(int i: response){
        cout<<i<<", ";
    }
    cout<<endl;
    return;
}

int main(){
    // vector<pair<int, pair<int, int>>> Queries = {{1, {5, 7}}, {1, {2, 15}}, {1, {11, 16}}, {3, {14, 2}}, {2, {11, 3}}, {2, {10, 10}} };
    vector<pair<int, pair<int, int>>> Queries = {{1, {20, 10}}, {1, {30, 20}}, {3, {15, 1}}, {3, {15, 2}}, {3, {15, 3}}, {3, {15, 4}}, {2, {100, 5}}};
    int Q = Queries.size();
    solveQueries(Queries, Q);
    return 0;
}





















