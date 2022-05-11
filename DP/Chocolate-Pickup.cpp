/**
 * @file Chocolate Pickup
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * @link https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. 
Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as 
possible with the help of his friends.
Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right 
place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to 
the cells just below them. When anyone passes from any cell, he will pick all chocolates 
in it, and then the number of chocolates in that cell will become zero. If both stay in 
the same cell, only one of them will pick the chocolates in it.
If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or 
(i + 1, j + 1). They will always stay inside the ‘GRID’.
Your task is to find the maximum number of chocolates Ninja can collect with the help of 
his friends by following the above rules.
*/
#include<bits/stdc++.h>
using namespace std;

int z[3] = {-1, 0, 1};

int maxChocolates(vector<vector<int>>& grid, int r, int c, int i, int j, int k){
	if(i >= r || j >= c || j<0 ||k <0 || k >= c){
		return 0;
	}

    int countChocolates = 0;
    for(int a = 0; a<3; ++a){
        for(int b = 0; b<3; ++b){
            countChocolates = max(
                countChocolates,
                maxChocolates(grid, r, c, i+1, j+z[a], k+z[b])
            );
        }
    }

    if(j^k){
        countChocolates += (grid[i][j] + grid[i][k]);
    }
    else{
        countChocolates += grid[i][j];
    }
    //cout<<i<< " "<<j<< " "<<k<< " "<<countChocolates<<endl;
    return countChocolates;
}

int maxChocolates(
    vector<vector<vector<int>>>& chocolates, 
    vector<vector<int>>& grid, 
    int r, 
    int c, 
    int i, 
    int j, 
    int k
){
    if(i >= r || j<0 || j>= c || k<0 || k>= c){
        return 0;
    }
    if(chocolates[i][j][k]){
        return chocolates[i][j][k];
    }

    int count = 0;
    for(int a = 0; a<3; ++a){
        for(int b = 0; b<3; ++b){
            count = max(
                count,
                maxChocolates(chocolates, grid, r, c, i+1, j+z[a], k+z[b])
            );
        }
    }

    if(j^k){
        count += (grid[i][j] + grid[i][k]);
    }
    else{
        count += grid[i][j];
    }
    chocolates[i][j][k] = count;
    cout<<i<< " "<<j<< " "<<k<< " "<<count<<endl;
    return count;
}

int maxChocolates(vector<vector<int>>& grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>> chocolates(n, vector<vector<int>>(m, vector<int>(m,0)));

    for(int i = 0; i<m; ++i){
        for(int j = 0; j<m; ++j){
            if(i^j){
                chocolates[n-1][i][j] = (grid[n-1][i]+grid[n-1][j]);
            }
            else{
                chocolates[n-1][i][j] = grid[n-1][j];
            }
        }
    }

    for(int i = n-2; i>=0; --i){
        for(int j = 0; j<m; ++j){
            for(int k = 0; k<m; ++k){
                int count = 0;
                for(int a = 0; a<3; ++a){
                    for(int b = 0; b<3; ++b){
                        if(j+z[a] >= 0 && j+z[a]<m && k+z[b]>=0 && k+z[b] < m)
                            count = max(count, chocolates[i+1][j+z[a]][k+z[b]]);
                    }
                }
                if(k^j){
                    count += (grid[i][j]+grid[i][k]);
                }
                else{
                    count += grid[i][j];
                }
                chocolates[i][j][k] = count;
            }
        }
    }
    return chocolates[0][0][m-1];
}

int main(){
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    }, grid2 = {
        {4,5},
        {3,7},
        {4,2}
    };
    
    // Recursion.
    int r = grid.size(), c = grid[0].size();
    cout<<maxChocolates(grid, r, c, 0, 0, c-1)<<endl;
    vector<vector<vector<int>>> chocolates(r, vector<vector<int>>(c, vector<int>(c,0)));
    cout<<maxChocolates(chocolates, grid, r, c, 0, 0, c-1)<<endl;

    // Memoization.
    r = grid2.size(), c = grid2[0].size();
    chocolates = vector<vector<vector<int>>> (r, vector<vector<int>>(c, vector<int>(c,0)));
    cout<<maxChocolates(grid2, r, c, 0, 0, c-1)<<endl;
    cout<<maxChocolates(chocolates, grid, r, c, 0, 0, c-1)<<endl;

    // Tabulation.
    cout<<maxChocolates(grid)<<endl;
    cout<<maxChocolates(grid2)<<endl;
    return 0;
}