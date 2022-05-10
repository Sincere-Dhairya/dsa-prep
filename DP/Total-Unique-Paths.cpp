/**
 * @file Total Unique Paths
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your 
destination is point ‘B’, which is the bottom-right cell of the same matrix. Your 
task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other 
words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your 
task is to find the total number of unique paths from the cell MATRIX[0][0] to 
MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example 
in a given point MATRIX[i] [j], you can move to either 
MATRIX[i + 1][j] or MATRIX[i][j + 1].
*/

#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

int uniquePaths(int m, int n, int i, int j){
    if(i>m || j>n){
        return 0;
    }
    else if(i == m && j == n){
        return 1;
    }
    return uniquePaths(m, n, i, j+1) + uniquePaths(m, n, i+1, j);
}

int uniquePaths(vector<vector<int>>& matrix, int m, int n, int i, int j){
    if(i>m || j>n ){
        return 0;
    }
    else if(matrix[i][j]){
        return matrix[i][j];
    }

    return matrix[i][j] = uniquePaths(matrix, m, n, i, j+1)+uniquePaths(matrix, m, n, i+1, j);
}

void printing(vector<vector<int>>& arr){
    for(auto a: arr){
        for(auto i: a){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int uniquePaths(int m, int n){
    vector<vector<int>> matrix(m, vector<int> (n, 0));

    for(int i = m-1; i>=0; --i){
        matrix[i][n-1] = 1;
    }
    for(int i = n-1; i>=0; --i){
        matrix[m-1][i] = 1;
    }
    //printing(matrix);

    for(int i = m-2; i>=0; --i){
        for(int j = n-2; j>=0; --j){
            matrix[i][j] = matrix[i][j+1]+matrix[i+1][j];
        }
    }
    //printing(matrix);

    return matrix[0][0];
}

int UniquePaths(int m, int n){
    vector<int> arr(n, 1);

    for(int i = 1; i<m; ++i){
        for(int j = n-2; j>=0; --j){
            arr[j] = arr[j]+arr[j+1];
        }
    }

    return arr[0];
}

int main(){
    int m = 5, n = 5;
    // Recursion
    auto t1 = high_resolution_clock::now();
    cout<<uniquePaths(m-1, n-1, 0, 0)<<endl;
    auto t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2-t1);
    cout<<duration.count()<<endl;

    // Memoization
    vector<vector<int>> matrix (m, vector<int>(n, 0));
    matrix[m-1][n-1] = 1;
    t1 = high_resolution_clock::now();
    cout<<uniquePaths(matrix, m-1, n-1, 0, 0)<<endl;
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2-t1);
    cout<<duration.count()<<endl;

    // Tabulation
    t1 = high_resolution_clock::now();
    cout<<uniquePaths(m, n)<<endl;
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2-t1);
    cout<<duration.count()<<endl;

    // Space Optimized Tabulation
    t1 = high_resolution_clock::now();
    cout<<UniquePaths(m, n)<<endl;
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2-t1);
    cout<<duration.count()<<endl;

    return 0;
}