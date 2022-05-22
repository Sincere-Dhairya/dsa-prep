/**
 * @file Wildcard Pattern Matching
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-22
 * @link https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a text and a wildcard pattern of size N and M respectively, implement a 
wildcard pattern matching algorithm that finds if the wildcard pattern is matched 
with the text. The matching should cover the entire text not partial text.
The wildcard pattern can include the characters ‘?’ and ‘*’
 ‘?’ – matches any single character 
 ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)
 Note:
You do not need to print anything, it has already been taken care of. Just implement 
the function.
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= 200

Where 'N' denotes the length of 'TEXT' and 'M' denotes the length of 'PATTERN'.

'TEXT' and 'PATTERN' contain only lowercase letters and patterns may contain 
special characters ‘*’ and ‘?’

Time Limit: 1sec
*/

// Recursion + Memoization.
// TC Exponential. SC - O(N+M).
bool stringMatch(vector<vector<bool>>& cache, string& a, string& b, int i, int j){
	if(i<0 && j<0){
		return true;
	}
	if(i<0) return false;
	if(j<0){
		for(; i>=0; --i){
			if(a[i] != '*') return false;
		}
		return true;
	}
	if(cache[i][j]) return cache[i][j];
	if(a[i]==b[j] || a[i]=='?'){
		return cache[i][j] = stringMatch(cache, a, b, i-1, j-1);
	}
	else if(a[i]=='*'){
		return cache[i][j] = stringMatch(cache, a, b, i-1, j)|stringMatch(cache, a, b, i, j-1);
	}
	return false;
}

bool wildcardMatching(string pattern, string text){
	int n = pattern.size(), m = text.size();
	vector<vector<bool>> table(n, vector<bool>(m, 0));
	return stringMatch(table, pattern, text, n-1, m-1);
}

// TC: O(N*M) SC: O(N).
// Tabulation.
bool wildcardMatching(string pattern, string text){
	int n = pattern.size(), m = text.size();
	vector<vector<int>> table(n+1, vector<int>(m+1));
	
	table[0][0] = 1;
	for(int j=1; j<=n; ++j){
		bool flag = true;
		for(int i=j; i>0; --i){
			if(pattern[i-1]!='*') {
				flag = 0;
				break;
			}
		}
		table[j][0] = flag;
	}
	
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(pattern[i-1]==text[j-1] || pattern[i-1]=='?'){
				table[i][j] = table[i-1][j-1];
			}
			else if(pattern[i-1] == '*'){
				table[i][j] = table[i-1][j]|table[i][j-1];
			}
		}
	}
	return table[n][m];
}

// Tabulation Space Optimized.
bool wildcardMatching(string pattern, string text){
	int n = pattern.size(), m = text.size();
	vector<bool> prev(m+1, 0), curr(m+1, 0);
	prev[0]= 1;
	
	for(int i=1; i<=n; ++i){
		bool flag = true;
		for(int j = 1; j<=i; ++j){
			if(pattern[j-1]!='*'){
				flag = false;
				break;
			}
		}
		curr[0] = flag;
		for(int j=1; j<=m; ++j){
			if(pattern[i-1] == text[j-1] || pattern[i-1]=='?'){
				curr[j]= prev[j-1];
			}
			else if(pattern[i-1]=='*'){
				curr[j]= prev[j] | curr[j-1];
			}
			else curr[j] = false;
		}
		prev = curr;
	}
	return prev[m];
}