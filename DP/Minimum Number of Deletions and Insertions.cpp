/**
 * @file Minimum Number of Deletions and Insertions
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-19
 * @link https://www.codingninjas.com/codestudio/problems/can-you-make_4244510 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given 2 non-empty strings “str” and “ptr” consisting of lowercase English alphabets 
only. Your task is to convert string “str” into string “ptr”. In one operation you can do either 
of the following on “str”:
Remove a character from any position in “str”.
Add a character to any position in “str”.
You have to find the minimum number of operations required to convert string “str” into “ptr”.
For Example:
If str = “abcd”, ptr = “anc”
In one operation remove str[3], after this operation str becomes “abc”.    
In the second operation remove str[1], after this operation str becomes “ac”.
In the third operation add ‘n’ in str[1], after this operation str becomes “anc”.

Hence, the output will be 3.
*/

// TC: O(N^2) SC: O(N^2).
int LPSLength(vector<vector<int>>& cache, string& s, string& t, int i, int j){
	if(i<0 || j<0) return 0;
	if(cache[i][j]) return cache[i][j];
	if(s[i] == t[j]){
		return cache[i][j] = 1+ LPSLength(cache, s, t, i-1, j-1);
	}
	else{
		return cache[i][j] = max(LPSLength(cache, s, t, i-1, j), 
								LPSLength(cache, s, t, i, j-1));
	}
	return 0;
}

int canYouMake(string &str, string &ptr){
    int n1 = str.length(), n2 = ptr.length();
	vector<vector<int>> cache(n1, vector<int>(n2, 0));
	int lpslen = LPSLength(cache, str, ptr, n1-1, n2-1);
	return n1-lpslen + n2-lpslen;
}