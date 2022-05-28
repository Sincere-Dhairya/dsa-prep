/**
 * @file Count Square Submatrices with all Ones
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-29
 * @link https://www.codingninjas.com/codestudio/problems/count-square-submatrices-with-all-ones_3751502 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
A matrix ‘ARR’ with ‘N’ rows and ‘M’ columns is given.
Count the number of square submatrices in matrix ‘ARR’ that have all ones. A square matrix is a matrix with equal numbers of rows and columns.
For Example :
If N = 2, M = 2 and ARR = [ [1, 1], [1, 1] ],
Then we have four square submatrices of size 1*1 and one square submatrix of size 2*2. So, the answer is 5.
Constraints :
1 ≤ T ≤ 10      
1 ≤ N, M ≤ 1000
0 ≤ ARR[i][j] ≤ 1

Time limit: 1 sec
*/

// Prefix Sum
int countSquares(int n, int m, vector<vector<int>> &arr) {
    for(int i = 1; i<n; ++i){
        for(int j = 1; j<m; ++j){
            if(arr[i][j]){
                arr[i][j] = 1+min(arr[i-1][j], min(arr[i-1][j-1], arr[i][j-1]));
            }
        }
    }
    int sum = 0;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            sum += arr[i][j];
        }
    }
    return sum;
}


/* Explaination.
As on every cell, we store the dimension of the largest square matrix possible by including that cell.
We may encounter a situation like:
. . . . .
. 1 2 2 .
. 0 1 X 
and we are required to fill X. 
This means that on top and top left of X, we do have a 2x2 +ve matrix, but not on the exact left 
of the X. Due to this reason, if we are supposed to follow:
if(arr[i-1][j]>0 && arr[i-1][j-1]>0 && arr[i][j-1]>0) then arr[i][j] = arr[i-1][j-1]+1.
Such a solution will prove to be wrong one, because of the above case.

One thing we can understand from this case that since on the left of X, we have 0, which means we 
can surely have matrix of size 1 secured by the cell X. 
Hence arr[i][j] = min(arr[i-1][j], arr[i-1][j-1], arr[i][j-1]).
*/
