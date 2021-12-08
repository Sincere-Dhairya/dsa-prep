/**
 * @file 227.Basic-Calculator-II.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.

*/
class Solution {
public:
    int calculate(string s) {
        s+='+';
        stack<int> buffer;
        buffer.push(0);
        char op = '+';
        string num = "";
        for(char c: s){
            //cout<<c<<" ";
            if(isdigit(c))
                num += c;
            else if(c == ' ')
                continue;
            else{
                //cout<<op<<" ";
                if(op == '+')
                    buffer.push(stoi(num));
                else if(op == '-')
                    buffer.push(-1*stoi(num));
                else if(op == '*'){
                    int n1 = buffer.top(), n2 = stoi(num);
                    buffer.pop(), buffer.push(n1*n2);
                }
                else{
                    int n1 = buffer.top(), n2 = stoi(num);
                    buffer.pop(), buffer.push(n1/n2);
                }
                num = "";
                op = c;
            }
            //cout<<buffer.top()<<endl;
        }
        int sum = 0;
        while(buffer.size())
            sum += buffer.top(), buffer.pop();
        return sum;
    }
};