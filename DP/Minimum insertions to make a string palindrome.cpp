/**
 * @file Minimum insertions to make a string palindrome
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-19
 * @link https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
A palindrome string is one that reads the same backward as well as forward. Given a string 'STR', 
you need to tell the minimum number of characters needed to insert into it to make it a 
palindromic string.
For example:
String 'STR' = “abcaa” can be converted into a palindrome by inserting 2 characters. So the final 
string becomes “aabcbaa”.
*/

// TC: O(N^2), SC: O(N^2).
int LPSLength(string& s, string& t, int n, int m){
	vector<int> prev(m+1, 0), curr(m+1, 0);
	int lpslen = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(s[i-1]==t[j-1]){ 
				curr[j] = 1+prev[j-1];
			}	
			else{
				curr[j] = max(curr[j-1], prev[j]);
			}
			lpslen = max(lpslen, curr[j]);
		}
		prev= curr;
	}
	return lpslen;
}

int minInsertion(string &s){
    // Write your code here.
	int n = s.length();
	string t = s;
	reverse(s.begin(), s.end());
	int lpsLen = LPSLength(s, t, n, n);
	return n-lpsLen;
}