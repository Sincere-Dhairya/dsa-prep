#include<bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens){
    unordered_map<string, function<int (int, int) > > list = {
        { "+" , [] (int a, int b) { return a + b; } },
        { "-" , [] (int a, int b) { return a - b; } },
        { "*" , [] (int a, int b) { return a * b; } },
        { "/" , [] (int a, int b) { return a / b; } }
    };

    stack<int> nums;
    for(string i : tokens){
        if(list.count(i) == 0) nums.push(stoi(i));
        else{
            int n1 = nums.top();
            nums.pop();
            int n2 = nums.top();
            nums.pop();
            nums.push(list[i](n2, n1));
        }
    }
    return nums.top();
}
int main(){
    vector<string> tokens = {"2","1","+","3","*"};
    cout<<evalRPN(tokens)<<endl;
    string var = "hellow";
    cout<<var.length()<<" "<<var[var.length()];
    return 0;
}