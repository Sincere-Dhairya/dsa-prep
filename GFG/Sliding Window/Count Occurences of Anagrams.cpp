/**
 * @file Count Occurences of Anagrams
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * @link https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1# @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 10^5
Both string contains lowercase english letters.
*/

// Sliding Window of vector of 26 for alphabets
// TC: O(Nx26) for comparing 26 indices again n again.
// SC: O(26x2) for the 2 vectors. So constant Space Complexity.
class Solution{
public:
	int search(string pat, string txt) {
	    vector<int> word(26), temp(26);
	    for(auto c: pat){
	        ++word[c-'a'];
	    }
	    
	    for(int i = 0; i<pat.size(); ++i){
	        ++temp[txt[i]-'a'];
	    }
	    int count = 0;
	    if(word == temp) ++count;
	    
	    for(int i = 0, j = pat.size(); j<txt.size(); ++i, ++j){
	        --temp[txt[i]-'a'],
	        ++temp[txt[j]-'a'];
	        
	        if(word == temp) ++count;
	    }
	    return count;
	}

};