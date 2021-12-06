/**
 * @file 856.Score-of-Parentheses.cpp
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
Example 4:

Input: s = "(()(()))"
Output: 6
 

Constraints:

2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.
*/

class Solution {
public:
    int scoreOfParentheses(string combo) {
        stack<int> s;
        int ans = 0;
        for(int i = 0; i<combo.size(); i++){
            if(combo[i] == '(')
                s.push(-1);
            else{
                if(s.top() == -1)
                    s.pop(), s.push(1);
                else{
                    while(s.size() and s.top() != -1)
                        ans += s.top(), s.pop();
                    if(s.size()) s.pop();
                    //cout<<"ans is: "<<ans<<endl;
                    s.push(2*ans), ans = 0;
                }
            }
        }
        if(s.size() > 1){
            while(s.size())
                ans += s.top(), s.pop();
            return ans;
        }
        return s.top();
    }
};

/*
Push -1 for every '(' encountered.
for ')' :check if the top is -1 or not.
for -1 pop -1 and push 1
for not -1, keep adding the top value while popping and stop at -1 and then push 2*sum into the stack.
*/