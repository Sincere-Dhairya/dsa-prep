/**
 * @file Matrix Chain Multiplication
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-26
 * @link https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the 
minimum cost to multiply these matrices. The cost of matrix multiplication is 
defined as the number of scalar multiplications. A Chain of matrices A1, A2, A3,.....An 
is represented by a sequence of numbers in an array ‘arr’ where the dimension of 
1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.
For example:
For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]

Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.

Constraints:
1 <= T <= 5
2 <= N <= 100
1 <= arr[i] <= 400 

Time Limit: 1 sec.
*/

// Recursion + Memoization.
// TC: Exponential. SC: O(N) But Memoization reduces TC to O(NxN)

int partition(vector<vector<int>>& table, vector<int>& arr, int i, int j){
    if(i>=j) return 0;
    if(table[i][j]) return table[i][j];
    int steps = 1e9;
    for(int k = i; k<j; ++k){
        steps = min(steps, partition(table, arr, i, k) + partition(table, arr, k+1, j) + arr[i-1]*arr[k]*arr[j]);
    }
    return table[i][j] = steps;
}

int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> table(N, vector<int> (N));
    return partition(table, arr, 1, N-1);
}

// Tabulation. 
// TC: O(NxNxN), SC: O(NxN)
int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> table(N, vector<int> (N, 1e9));
    for(int i=0; i<N; ++i){
        table[i][i] = 0;
    }
    for(int len = 2; len<N; ++len){
        for(int i=1; i<= N-len; ++i){
            int j = i+len-1;
            for(int k = i; k<j; ++k){
                table[i][j] = min(
                    table[i][j], 
                    table[i][k] + table[k+1][j] + arr[i-1]*arr[k]*arr[j]
                );
            }
        }
    }
    return table[1][N-1];
}

// Better approach for Tabulation.
int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> table(N, vector<int> (N, 1e9));
    for(int i=0; i<N; ++i){
        table[i][i] = 0;
    }
    
    for(int i = N-2; i>0; --i){
        for(int j = i+1; j<N; ++j){
            int prod = arr[i-1]*arr[j];
            for(int k = i; k<j; ++k){
                table[i][j] = min(
                    table[i][j],
                    prod*arr[k] + table[i][k] + table[k+1][j]
                );
            }
        }
    }
    return table[1][N-1];
}