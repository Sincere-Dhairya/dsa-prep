/**
 * @file Longest String Chain
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-25
 * @link https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array ‘ARR’ of strings, where each string consists of 
English lowercase letters.
Let’s say a string ‘A’ is a predecessor of string ‘B’ if and only if we can 
add exactly one letter anywhere in ‘A’ to make it equal to ‘B’. For example 
“abd” is a predecessor of “abcd”, we can add “c” in “abd” to make a 
string “abcd”
A string chain is a sequence of strings where for every ‘i’ in [1 . . . (K - 1)], 
‘Si’ is the predecessor of ‘Si+1’. And the length of such a string chain is ‘K’.
Now your task is to find the length of the longest possible string chain.
For Example :
Let ‘ARR’ = ["x", “xx”, “y”, “xyx”] 
The longest possible string chain is “x” -> “xx” -> “xyx”
The length of the given chain is 3, hence the answer is 3.
*/

// Tabulation. TC: O(NxNxS), SC: O(N)
bool compare(string& a, string& b){
    return a.size() < b.size();
}

bool check(string& big, string& small){
    int nb = big.size(), ns = small.size();
    if(nb-ns != 1) return 0;
    
    int i = 0, j=0;
    while(i<nb){
        if(small[j]==big[i]) ++j;
        ++i;
    }
    if(i == nb && j == ns) return 1;
    return 0;
}

int longestStrChain(vector<string> &arr){
    int n = arr.size(), maxlen = 0;
    vector<int> LOS(n, 1);
    sort(arr.begin(), arr.end(), compare);
    
    for(int i=0; i<n; ++i){
        int len = LOS[i]+1;
        for(int j = i+1; j<n;    ++j){
            if(check(arr[j], arr[i]) && len > LOS[j]){
                LOS[j] = len;
            }
        }
        maxlen = max(maxlen, LOS[i]);
    }
    return maxlen;
}