/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long final = 0;
        string temp = s;
        
        cout<<temp<<endl;
        if(temp.front() == ' ') while(temp.front() == ' ') temp.erase(0,1);
        cout<<temp<<endl;

        bool sign = true;
        if(temp.front() == '-'){
            sign = false;
            cout<<"false";
        }

        if(temp.front() == '+' || temp.front() == '-') temp.erase(0,1);
        cout<<temp<<endl;

        if(int(temp.front()-48) < 0 || int(temp.front()-48) > 9) return final;
        while(temp.front() == '0') temp.erase(0,1);

        string sample = "";
        for(auto i : temp){
            if(int(i-48) < 0 || int(i-48)>9){
                if(i == temp.front()) return 0;
                break;
            }
            sample += i;
        }

        string intmax = "2147483647", intmin = "2147483648";
        cout<<temp<<endl;
        cout<<sample.length()<<endl;
        if(sample.length() > 10) {
            if(sign) return INT_MAX;
            else return INT_MIN;
        }
        
        else if(sample.length() == 10){
            if(sign){
                int val = intmax.compare(sample);
                cout<<endl<<val<<endl;
                if(val < 0) return INT_MAX;
                else final = stoi(sample);
            }
            else{
                int val = intmin.compare(sample);
                if(val<0) return INT_MIN;
                else {
                    final = stol(sample);
                    final *= -1;
                }
            }
        }
        else if(sample.length() == 0) return 0;
        else{
            final = stoi(sample);
            if(!sign) final *= -1;
        }
        return final;
    }
};
// @lc code=end

