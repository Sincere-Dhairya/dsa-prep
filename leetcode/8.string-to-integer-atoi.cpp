/**
 * @file 8.String to Integer (atoi)
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//Brute Force:
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

//Optimized - less code
class Solution {
public:
    long mainconvertor(stack<int> seq){
        long power = 1, sum = 0;
        while(seq.size()){
            long num = power*seq.top();
            seq.pop(), sum += num, power *= 10;
        }
        return sum;
    }
    int myAtoi(string s) {
        int limit = 10, n = s.length();
        stack<int> seq;
        int sign = 1, i = 0;
        while(i < n and s[i] == ' ')
            ++i;
        //cout<<i<<endl;
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-')
                sign = -1;
            ++i;
        }
        //cout<<sign<<" "<<i<<endl;
        while(i < n and s[i] == '0')
            ++i;
        if(!isdigit(s[i]))
            return 0;
        while(seq.size() <= limit and i < n and isdigit(s[i]))
            seq.push(s[i]-'0'), ++i;
        
        long ans = mainconvertor(seq) * (long)sign;
        
        if(sign and ans > 2147483647)
            ans = 2147483647;
        else if(sign < 0 and ans < -2147483648)
            ans = -2147483648;
        return (int)ans;
    }
};

//Test Case: "   +00000000000000214748364780000000000000021474836478"
// @lc code=end

