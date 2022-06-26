/**
 * @file Maximum of minimum for every window size
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * @link https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453 @endlink
 * @copyright Copyright (c) 2022
 * @tags stack nearest-smaller-on-both-sides
 */
/*
Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Example 1:

Input:
N = 7
arr[] = {10,20,30,50,10,70,30}
Output: 70 30 20 10 10 10 10 
Explanation: 
1.First element in output
indicates maximum of minimums of all
windows of size 1.
2.Minimums of windows of size 1 are {10},
 {20}, {30}, {50},{10}, {70} and {30}. 
 Maximum of these minimums is 70. 
3. Second element in output indicates
maximum of minimums of all windows of
size 2. 
4. Minimums of windows of size 2
are {10}, {20}, {30}, {10}, {10}, and
{30}.
5. Maximum of these minimums is 30 
Third element in output indicates
maximum of minimums of all windows of
size 3. 
6. Minimums of windows of size 3
are {10}, {20}, {10}, {10} and {10}.
7.Maximum of these minimums is 20. 
Similarly other elements of output are
computed.
Example 2:

Input:
N = 3
arr[] = {10,20,30}
Output: 30 20 10
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1.Minimums of windows
of size 1 are {10} , {20} , {30}.
Maximum of these minimums are 30 and
similarly other outputs can be computed
Your Task:
The task is to complete the function maxOfMin() which takes the array arr[] and its size N as inputs and finds the maximum of minimum of every window size and returns an array containing the result. 

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^6
*/

// Nearest Smaller on both sides.
// TC: O(N), SC: O(N).
vector <int> maxOfMin(int arr[], int n){
    vector<int> left(n, 0), right(n, n-1);
    stack<int> s;
    
    for(int i =0; i<n; ++i){
        while(s.size() && arr[s.top()] > arr[i]){
            right[s.top()] = i-1;
            s.pop();
        }
        s.push(i);
    }
    
    s = stack<int> ();
    
    for(int i= n-1; i>=0; --i){
        while(s.size() && arr[s.top()] > arr[i]){
            left[s.top()] = i+1;
            s.pop();
        }
        s.push(i);
    }
    
    vector<int> ans(n);
    for(int i = 0; i<n; ++i){
        int len = right[i]-left[i];
        ans[len] = max(ans[len], arr[i]);
    }
    
    for(int i = n-2; i>=0; --i){
        ans[i] = max(ans[i], ans[i+1]);
    }
    return ans;
    
}