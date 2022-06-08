/**
 * @file Validate an IP Address
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-08
 * @link link-object @endlink
 * @copyright Copyright (c) 2022
 * @tags ```strings```
 */
/*
Write a program to Validate an IPv4 Address.
According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 .
A valid IPv4 Address is of the form x1.x2.x3.x4 where 0 <= (x1, x2, x3, x4) <= 255.
Thus, we can write the generalized form of an IPv4 address as (0-255).(0-255).(0-255).(0-255).
Note: Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.

Your task is to complete the function isValid which returns 1 if the given IPv4 address is valid else returns 0. The function takes the IPv4 address as the only argument in the form of string.

This question has many Corner Cases, be ware.

Expected Time Complexity: O(N), N = length of the string.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of string <=50

*/

// TC: O(NLogN), SC: O(1).

#include<bits/stdc++.h>
class Solution {
    public:
        int numOfDigits(int num){
            if(!num) return 1;
            int count = 0;
            while(num){
                ++count;
                num /= 10;
            }
            return count;
        }
        bool checkSequence(string& s){
            if(s.length()>3 || s.length() <1) return 0;
            int num = stoi(s), digits = numOfDigits(num);
            if(num>255) return 0;
            return s.length() == digits;
        }
        int isValid(string s) {
            // code here
            s.push_back('.');
            if(s.length() > 16) return 0;
            string temp = "";
            int points = 0;
            for(int i=0; i<s.length(); ++i){
                if(s[i] !='.' && (s[i]-'0' < 0 || s[i]-'0' > 9)){
                    return 0;
                }
                if(s[i] == '.'){
                    ++points;
                    if(!checkSequence(temp)){
                        return 0;
                    }
                    temp = "";
                }
                else{
                    temp.push_back(s[i]);
                }
            }
            
            return points==4;
        }
};