/**
 * @file Shortest Common Supersequence
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-19
 * @link https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493 @endlink
 * @copyright Copyright (c) 2022
 * 
 */


#include<iostream>
#include<vector>
using namespace std;

string LCSstring(string &a, string& b){
	int n = a.length(), m = b.length();
	vector<vector<int>> table(n+1, vector<int>(m+1, 0));
	
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i-1] == b[j-1]){
				table[i][j] = 1 + table[i-1][j-1];
			}
			else{
				table[i][j] = max(table[i-1][j], table[i][j-1]);
			}
		}
	}
	
	int i = n, j = m, len = table[n][m], ind = len-1;
	string lcs = "";
	for(int i = 0; i<len; ++i) lcs.push_back('%');
	while(i>0 && j>0 && ind>=0){
		if(a[i-1]==b[j-1]){
			lcs[ind--] = a[i-1], --i, --j;
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
	return lcs;
}

string superString(string& a, string& b, string& lcs){
    int n1 = a.length(), n2 = b.length(), n3 = lcs.length();
    int i = 0, j = 0, k = 0;
    string ans = "";
    while(i<n1 && j<n2 && k<n3){
        while(a[i] != lcs[k])
            ans.push_back(a[i++]);
        while(b[j] != lcs[k])
            ans.push_back(b[j++]);
        ans.push_back(lcs[k++]), ++i, ++j;
        //cout<<ans<<endl;
    }
    while(i<n1)
        ans.push_back(a[i++]);
    while(j<n2)
        ans.push_back(b[j++]);
    while(k<n3)
        ans.push_back(lcs[k++]);
    return ans;
}

int main(){
    string a = "brute", b = "groot", lcs = LCSstring(a, b);
    cout<<superString(a, b, lcs)<<endl;
}