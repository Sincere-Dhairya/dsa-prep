/**
 * @file Smallest window in a string containing all the characters of another string
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * @link https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/ @endlink
 * @copyright Copyright (c) 2022
 * @tags sliding-window
 */

/*
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)
*/

// TC: O(N) rarely O(N^2), SC: O(K).
#include<bits/stdc++.h>
using namespace std;

string smallestWindow (string s, string p){
    unordered_map<int, int> window;
    int len = 1e8, count = p.length();
    string ans = "-1";
    
    for(auto &c: p){
        ++window[c];
    }
    
    int left = 0;
    for(int right =0; right<s.length(); ++right){
        if(window[s[right]] > 0){
            --count;
        }
        --window[s[right]];
        
        while(window[s[left]] < 0){
            ++window[s[left]];
            ++left;
        }
        int length = right-left+1;
        if(count == 0 && length < len){
            len = length;
            ans = s.substr(left, length);
        }
    }
    
    return ans;
}

int main(){
    cout<<smallestWindow("timetopractice", "toc")<<endl;
    return 0;
}