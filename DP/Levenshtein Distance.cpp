/**
 * @file Levenshtein Distance
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-24
 * @link https://www.geeksforgeeks.org/edit-distance-dp-5/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Edit Distance
Given two strings str1 and str2 and below operations that can be performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

Insert
Remove
Replace
All of the above operations are of equal cost. 

Examples: 

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a
*/

//
#include<bits/stdc++.h>
using namespace std;

auto min3(int i, int j, int k){ return min(i, min(j,k)); }

int editDistance(string &str1, string &str2, int n, int m){
    if(!n){
        return m;
    }
    if(!m){
        return n;
    }
    if(str1[n-1]==str2[m-1]){
        return editDistance(str1, str2, n-1, m-1);
    }
    return 1+min3( editDistance(str1, str2, n-1, m), editDistance(str1, str2, n, m-1), editDistance(str1, str2, n-1, m-1) );
}

int _editDistance(string &s1, string &s2, int n, int m){
    vector<vector<int> > cache(n+1, vector<int> (m+1, 0));
    for(int i= 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(!i){
                cache[i][j] = j;
            }
            else if(!j){
                cache[i][j] = i;
            }
            else if(s1[i-1]==s2[j-1]){
                cache[i][j] = cache[i-1][j-1];
            }
            else{
                cache[i][j] = 1+min3(cache[i-1][j], cache[i-1][j-1], cache[i][j-1]);
            }
        }
    }
    return cache[n][m];
}
int main(){
    vector<string> set1 = { "geek", "hello", "ramjas", "gfgfg", "ecfbefdcfca" },
                    set2= { "gesek", "hellno", "samarja", "gfgfg", "badfcbebbf"};
    
    for(int i = 0; i<5; i++){
        int n = set1[i].size(), m = set2[i].size();
        vector<vector<int>> cache(n+1, vector<int> (m+1, 0));
        cout<<editDistance(set1[i], set2[i], set1[i].size(), set2[i].size())<<endl;
        cout<<_editDistance(set1[i], set2[i], set1[i].size(), set2[i].size())<<endl<<endl;
    }
    return 0;
}