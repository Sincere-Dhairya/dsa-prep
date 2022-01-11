/**
 * @file 67. Add Binary
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-10
 * @link https://leetcode.com/problems/add-binary/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

//o(N) Tc and sc also o(n): Gave Runtime Integer Overflow error.
class Solution {
public:
    string addBinary(string a, string b) {
        int num1 = 0, num2 = 0, pow2 = 1;
        while(a.empty() == 0){
            num1 += pow2*(a.back()-'0');
            pow2 *= 2;
            a.pop_back();
        }
        pow2= 1;
        while(!b.empty()){
            num2 += pow2*(b.back()-'0');
            pow2 *= 2;
            b.pop_back();
        }
        int sum = num1 + num2;
        string total = "";
        while(sum){
            total.push_back((char)((sum%2) +'0'));
            sum /= 2;
        }
        if(total.empty()){
            total.push_back('0');
        }
        else {
            reverse(total.begin(), total.end());
        }
        return total;
    }
};
/*
"10001111"
"100"

"0"
"0"

"1"
"0"

"10001111"
"0"
*/

//O(N) Using Full-Adder
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.length()-1, j = b.length()-1, carry = 0;
        while(i>=0 && j>=0){
            bool num1 = a[i]-'0', num2 = b[j]-'0';
            --i, --j;
            bool xor1 = num1^num2, xor2 = xor1^carry;
            bool and1 = xor1&carry, and2 = num1&num2;
            carry = and1|and2;
            ans.push_back(char(xor2 + '0'));
        }
        while(i>=0){
            bool bita = a[i]-'0';
            bool sumbit = bita^carry;
            ans.push_back(char(sumbit+'0'));
            carry = carry&bita;
            --i;
        }
        while(j>=0){
            bool bitb = b[j]-'0';
            bool sumbit = bitb^carry;
            ans.push_back(char(sumbit+'0'));
            carry = carry&bitb;
            --j;
        }
        if(carry){
            ans.push_back(char(carry+'0'));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};