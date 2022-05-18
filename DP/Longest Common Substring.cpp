/**
 * @file Longest Common Substring
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-18
 * @link https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You have been given two strings 'STR1' and 'STR2'. You have to find the length of the 
longest common substring.
A string “s1” is a substring of another string “s2” if “s2” contains the same characters 
as in “s1”, in the same order and in continuous fashion also.
For Example :
If 'STR1' = “abcjklp” and 'STR2' = “acjkp”  then the output will be 3.

Explanation: The longest common substring is “cjk” which is of length 3.
*/

/* Solution: We record whether the common string is being made or not on the table. the 
0 represent that there is no common substring being made till that index from both 
strings. And the non zeroes represent that the corresponding characters match and 
are the previous characters matching or not.
*/

int lcs(string &s1, string &s2){
	int n = s1.size(), m = s2.size(), lcsLen = 0;
	vector<int> prev(m+1), curr(m+1);

	for(int i=1; i<=n; ++i){
		for(int j = 1; j<=m; ++j){
			if(s1[i-1]==s2[j-1]) curr[j] = 1+prev[j-1];
			else curr[j] = 0;
			lcsLen = max(lcsLen, curr[j]);
		}
		prev = curr;
	}
	return lcsLen;
}