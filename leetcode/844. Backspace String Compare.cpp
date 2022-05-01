/**
 * @file 844. Backspace String Compare
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-01
 * @link https://leetcode.com/problems/backspace-string-compare/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?
*/

// Tc- O(N) SC- O(1)
class Solution {
public:
    void executeBackspace(string& s, int& i){
        int count = 0;
        while(i>=0 && s[i]=='#'){
            ++count, --i;
        }
        while(i>=0 && count){
            if(s[i]=='#'){
                ++count;
            }
            else{
                --count;
            }
            --i;
        }
    }
    bool backspaceCompare(string s, string t) {
        int i = s.length()-1, j = t.length()-1;
        while(i>=0 || j>=0){
            if(i>=0 && j>=0 && s[i]==t[j] && s[i] != '#'){
                --i, --j;
            }
            else if( (i>=0 && s[i]=='#') || (j>=0 && t[j] == '#') ){
                if(i>=0 && s[i]=='#'){
                    executeBackspace(s, i);
                }
                if(j>=0 && t[j]=='#'){
                    executeBackspace(t, j);
                }
            }
            else{
                return false;
            }
        }
        return i<=0 && j<=0;
    }
};
/*
"y#fo##f"
"y#f#o##f"

*/

// TC - O(N) SC - O(N)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string t1 = "", t2 = "";
        for(auto c: s){
            if(c == '#'){
                if(!t1.empty()){
                    t1.pop_back();
                }
            }
            else{
                t1.push_back(c);
            }
        }
        for(auto c: t){
            if(c == '#'){
                if(!t2.empty()){
                    t2.pop_back();
                }
            }
            else{
                t2.push_back(c);
            }
        }
        cout<<t1<<" "<<t2<<endl;
        return t1.compare(t2)==0;
    }
};
/*
"adjfj#######"
"#####hduffd"
"ashv###soidf##"
"ao"
"ab#c"
"ad#c"
*/