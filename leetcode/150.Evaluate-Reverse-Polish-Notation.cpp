/**
 * @file 150.Evaluate-Reverse-Polish-Notation.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 *Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

*/
class Solution {
public:
    void operation(vector<int> & stack, string op){
        int n1 = stack.back();
        stack.pop_back();
        int n2 = stack.back();
        stack.pop_back();
        if(op.compare("*") == 0)
            stack.push_back(n1*n2);
        else if(op.compare("+") == 0)
            stack.push_back(n1+n2);
        else if(op.compare("-") == 0)
            stack.push_back(n2-n1);
        else stack.push_back(n2/n1);
    }
   
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(auto i : tokens){
            cout<<i<<" ";
            if(i == "+" || i == "*" || i == "/" || i == "-")
                operation(stack, i);
            else{
                stack.push_back(stoi(i));
            }
            cout<<stack.back()<<endl;
        }
        return stack.back();
    }
};