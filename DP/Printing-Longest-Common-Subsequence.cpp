/**
 * @file Printing Longest Common Subsequence
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-17
 * @link link-object @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>

using namespace std;
using namespace chrono;


// Recursion.
string generateSubsequence(string& s, string& t, int i, int j){
    if(i<0 || j<0){
        return "";
    }
    if(s[i]==t[j]){
        return generateSubsequence(s, t, i-1, j-1) + s[i];
    }
    else{
        string s1 = generateSubsequence(s, t, i-1, j),
        s2 = generateSubsequence(s, t, i, j-1);
        if(s1.size() > s2.size()) return s1;
        else return s2;
    }
    return "";
}

void printing(vector<vector<int>>& table){
    for(auto v: table){
        for(auto i: v)
        cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl;
}
// Tabulation.
// string generateSubsequence(vector<vector<int>>& table, string& s, string& t){
//     int n = table.size(), m = table[0].size();
//     int i =n-1, j = m-1, ind = table[n-1][m-1]-1;

// }

string lcs(string s, string t){
	int ns = s.length(), nt = t.length();
	vector<vector<int>> table(ns+1, vector<int>(nt+1, 0));
	
	for(int i = 1; i<=ns; ++i){
		for(int j = 1; j<=nt; ++j){
			if(s[i-1] == t[j-1]) table[i][j] = 1 + table[i-1][j-1];
			else table[i][j] = max(table[i-1][j], table[i][j-1]);
		}
	}

    string ans = "";
    for(int i = 0; i<table[ns][nt]; ++i) ans.push_back('&');

    int i = ns, j = nt, ind = table[ns][nt]-1;

    while(i>0 && j>0 && ind >=0){
        if(s[i-1] == t[j-1]){
            ans[ind] = s[i-1]; --i, --j, --ind;
        }
        else{
            if(table[i-1][j] > table[i][j-1]){
                --i;
            }
            else{
                --j;
            }
        }
    }

    return ans;
}

int main(){
    string s = "abcde", t = "bgdek";
    int ns = s.size(), nt = t.size();
    // Recursion.
    auto t1 = high_resolution_clock::now();
    cout<<generateSubsequence(s, t, ns-1, nt-1)<<endl;
    auto t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2-t1);
    cout<<duration.count()<<endl;

    // Tabulation.
    t1 = high_resolution_clock::now();
    cout<<lcs(s, t)<<endl;
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2-t1);
    cout<<duration.count()<<endl;
    
    return 0;
}