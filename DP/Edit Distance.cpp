/**
 * @file Edit Distance
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-22
 * @link https://www.codingninjas.com/codestudio/problems/edit-distance_630420 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find 
the "Edit Distance" between the strings.
Edit Distance of two strings is the minimum number of steps required to make one 
string equal to the other. In order to do so, you can perform the following three 
operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note:
Strings don't contain spaces in between.
*/


// Recursion + Memoization.
// manipulation(i, j) is a function that gives us the min no. of actions taken 
// to convert a[0..i] into b[0..j].
// TC: 3^(N+M) or Exponential . SC O(N+M).
int manipulation(vector<vector<int>>& cache, string &a, string& b, int i, int j){
	if(j<0) return i+1;
	if(i<0) return j+1;
	if(cache[i][j]) return cache[i][j];
	if(a[i]==b[j]) return cache[i][j] = manipulation(cache, a, b, i-1, j-1);
	// delete
	int del = manipulation(cache, a, b, i-1, j);
	// replace
	int replace = manipulation(cache, a, b, i-1, j-1);
	// insert
	int ins = manipulation(cache, a, b, i, j-1);
	return cache[i][j]= 1+ min(del, min(replace, ins));
}

int editDistance(string str1, string str2){
	int n = str1.length(), m = str2.length();
	vector<vector<int>> cache(n, vector<int>(m, 0));
	return manipulation(cache, str1, str2, n-1, m-1);
	//return ans;
}

// Tabulation.
// TC : O(N^2)    SC : O(N^2)
int editDistance(string a, string b){
	int n = a.length(), m = b.length();
	vector<vector<int>> table(n+1, vector<int>(m+1));
	
	for(int i=0; i<=n; ++i) table[i][0] = i;
	for(int i=0; i<=m; ++i) table[0][i] = i;
	
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i-1]==b[j-1]){
				table[i][j] = table[i-1][j-1];
			}
			else{
				table[i][j] = 1+min(table[i-1][j], min(table[i-1][j-1], table[i][j-1]));
			}
		}
	}
	
	return table[n][m];
}