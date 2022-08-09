/**
 * @file Minimize-a-string
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-09
 * @link link-object @endlink
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

string smallestString(string& s){
    
    for(int i = 0; i<s.length()-1; ++i){
        if(s[i] == 'c' && s[i+1]=='b'){
            swap(s[i], s[i+1]);
        }
    }

    for(int i=0; i<s.length(); ++i){
        if(s[i] =='b' && s[i+1]=='a'){
            swap(s[i], s[i+1]);
        }
    }

    return s;
}

int main(){
    string s = "abaacbac";
    cout << smallestString(s) <<endl;
}