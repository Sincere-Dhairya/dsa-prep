/**
 * @file Maximum Size Rectangle Sub-matrix With All 1's
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-28
 * @link https://www.codingninjas.com/codestudio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an 'N' * 'M' sized binary-valued matrix 'MAT, where 'N' is the number of rows and 'M' is the number of columns. You need to return the maximum size (area) of the submatrix which consists of all 1’s i.e. the maximum area of a submatrix in which each cell has only the value ‘1’.
Constraints:
1 <= 'T' <= 50
1 <= 'N', 'M' <= 100

Time Limit: 1 sec
*/

// Using Prefix Sum DP
// TC: O(N^3), SC: O(N^2).
int maxAreaRectangle(vector<int>& heights, int n){
    vector<int> right(n), left(n);
    stack<int> s;
    for(int i = 0; i<n; ++i){
        while(s.size() && heights[s.top()]>heights[i]){
            right[s.top()] = i-1, s.pop();
        }
        s.push(i);
    }
    while(s.size()){
        right[s.top()] = n-1, s.pop();
    }
    
    for(int i = n-1; i>=0; --i){
        while(s.size() && heights[s.top()]>heights[i]){
            left[s.top()] = i+1, s.pop();
        }
        s.push(i);
    }
    
    int area=0;
    for(int i=0; i<n; ++i){
        //cout<<left[i]<<" "<<right[i]<<" "<<heights[i]<<endl;
        area = max(area, heights[i]*(right[i]-left[i]+1));
    }
    return area;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
    int maxarea = 0;
    vector<int> heights(m,0);
    for(int i=0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(mat[i][j]) ++heights[j];
            else heights[j] = 0;
        }
        int area = maxAreaRectangle(heights, m);
        //cout<<area<<endl;
        maxarea = max(maxarea, area);
    }
    return maxarea;
}