/**
 * @file Find minimum integer integer
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given two string strings a and b consisting of lowercase English Letters. Let a' be the concatenation of 10^250 a copies.
Find the minimum integer i such that b is a subsequence of the string a'1.a'2.a'3... a'i (the first i characters in a')

Constraints:
1 <= |a| <= 10^5
1 <= |b| <= 10^5
a and b consists of lowercase English letters.

Examples:
Input - context, son
Output - 10
*/
#include<bits/stdc++.h>
using namespace std;

long findMinInt(string& A, string& B){
    vector<int> checkTable(26);
    
    for(char c: A){
        ++checkTable[c-'a'];
    }
    
    for(char c: B){
        if(checkTable[c-'a'] == 0){
            return -1;
        }
    }
    
    long count = 0;
    int i=0, j=0;
    while(1){
        if(i == A.size()){
            i = 0;
        }
        if(j == B.size()){
            return count;
        }
        if(B[j] == A[i]){
            ++j;
        }
        ++i;
        ++count;
    }
}

int main(){
    string A = "contest", B = "son";
    cout << findMinInt(A, B) << endl;
    return 0;
}