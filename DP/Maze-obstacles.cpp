/**
 * @file Maze obstacles
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a ‘N’ * ’M’ maze with obstacles, count and return the number of paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value -1 if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
*/
#include<bits/stdc++.h>
using namespace std;

int mazePaths( vector<vector<int>>& maze, int m, int n, int i, int j){
    if(i >= m || j >= n || maze[i][j] == -1){
        return 0;
    }
    if(i == m-1 || j == n-1){
        return 1;
    }
    return mazePaths(maze, m, n, i, j+1) + mazePaths(maze, m, n, i+1, j);
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

int mazePaths(vector<vector<int>>& maze){
    int m = maze.size(), n = maze[0].size();
    if(maze[m-1][n-1]==-1){
        return 0;
    }

    for(int i = n-1; i>=0; --i){
        if(maze[i][n-1] != -1){
            maze[i][n-1] = 1;
        }
    }
    for(int i = m-1; i>=0; --i){
        if(maze[m-1][i] != -1){
            maze[m-1][i] = 1;
        }
    }

    for(int i = m-2; i>=0; --i){
        for(int j = n-2; j>=0; --j){
            if(maze[i][j] != -1){
                int add1 = 0, add2 = 0;
                add1 = (maze[i][j+1]>0? maze[i][j+1]: 0),
                add2 = (maze[i+1][j]>0? maze[i+1][j]: 0);
                maze[i][j] = add1+add2;
            }
        }
    }

    return maze[0][0];
}

int main(){
    vector<vector<int>> maze = {
        {0,0,0},
        {0,-1,0},
        {0,0,0}
    }, maze2 = {
        {0, 0, -1, 0},
        {0, 0, 0, 0},
        {0, -1, -1, 0},
        {0, 0, 0, 0}
    }, maze3 = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,-1},
    };
    cout<<mazePaths(maze, 3, 3, 0,0)<<endl;
    cout<<mazePaths(maze2, 4, 4, 0,0)<<endl;

    // Tabulation
    cout<<mazePaths(maze2)<<endl;
    cout<<mazePaths(maze)<<endl;

    cout<<mazePaths(maze3);
    return 0;
}