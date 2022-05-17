/**
 * @file Longest Common Subsequence
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-17
 * @link https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 
'Longest Common Subsequence'.
For a string 'str'(per se) of length K, the subsequences are the strings containing 
characters in the same relative order as they are present in 'str,' but not 
necessarily contiguous. Subsequences contain all the strings of length varying 
from 0 to K.
Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
*/

// Recursion + Memoization.
int ssLen(vector<vector<int>>& cache, string& s, string& t, int i, int j){
	if(i<0 || j<0) return 0;
	if(cache[i][j]) return cache[i][j];
	if(s[i] == t[j]){
		return cache[i][j] = 1+ssLen(cache, s, t, i-1, j-1);
	}
	else{
		return cache[i][j] = max(ssLen(cache, s, t, i-1, j), ssLen(cache, s, t, i, j-1));
	}
	return 0;
}

int lcs(string s, string t){
	int ns = s.length(), nt = t.length();
	vector<vector<int>> cache(ns, vector<int> (nt));
	return ssLen(cache, s, t, s.length()-1, t.length()-1);
}

// Tabulation.
int lcs(string s, string t){
	int ns = s.length(), nt = t.length();
	vector<vector<int>> table(ns, vector<int>(nt));
	
	for(int i = 0; i<ns; ++i){
		if(s[i] == t[0]) table[i][0] = 1;
	}
	for(int i = 0; i<nt; ++i){
		if(s[0] == t[i]) table[0][i] = 1;
	}
	
	for(int i = 1; i<ns; ++i){
		for(int j = 1; j<nt; ++j){
			if(s[i] == t[j]) table[i][j] = 1 + table[i-1][j-1];
			else table[i][j] = max(table[i-1][j], table[i][j-1]);
		}
	}
	
	return table[ns-1][nt-1];
}

// Tabulation Space optimized.
int lcs(string s, string t){
	int ns = s.length(), nt = t.length();
	vector<int> prev(nt+1), curr(nt+1);
	
	for(int i = 1; i<=ns; ++i){
		for(int j = 1; j<=nt; ++j){
			if(s[i-1] == t[j-1]) curr[j] = 1+ prev[j-1];
			else curr[j] = max(prev[j], curr[j-1]);
		}
		prev= curr;
	}
	return prev[nt];
}