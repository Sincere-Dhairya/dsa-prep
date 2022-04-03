/**
 * @file Strings Interleaving
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * @link https://www.geeksforgeeks.org/find-if-a-string-is-interleaved-of-two-other-strings-dp-33/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/*
Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. C is said to be interleaving A and B, if it contains all and only characters of A and B and order of all characters in individual strings is preserved. 

Example:

Input: strings: "XXXXZY", "XXY", "XXZ"
Output: XXXXZY is interleaved of XXY and XXZ
The string XXXXZY can be made by 
interleaving XXY and XXZ
String:    XXXXZY
String 1:    XX Y
String 2:  XX  Z

Input: strings: "XXY", "YX", "X"
Output: XXY is not interleaved of YX and X
XXY cannot be formed by interleaving YX and X.
The strings that can be formed are YXX and XYX
*/

#include<bits/stdc++.h>
using namespace std;

bool checkinterleave(string A, string B, string C, int la, int lb, int lc, int i, int j, int k){
    if(i == la and j == lb and k == lc){
        return true;
    }
    else if(i>la || j>lb || k>lc){
        return false;
    }
    
    if(i<la && k<lc && A[i]==C[k] && checkinterleave(A, B, C, la, lb, lc, i+1, j, k+1)){
        return true;
    }
    else if(j< lb && k<lc && B[j]==C[k] && checkinterleave(A, B, C, la, lb, lc, i, j+1, k+1)){
        return true;
    }
    return false;
}
bool isInterleave(string A, string B, string C) {
    //Your code here
    int la = A.size(), lb = B.size(), lc = C.size();
    return checkinterleave(A,B,C,la,lb,lc,0,0,0);
}

int main(){
    string a = "XXY", b = "XXZ", c = "XXZXXY";
    cout<<isInterleave(a,b,c);
    return 0;
}