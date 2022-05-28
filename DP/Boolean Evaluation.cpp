/**
 * @file Boolean Evaluation
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-28
 * @link https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an expression ‘EXP’ in the form of a string where operands will be : (TRUE and FALSE) and operators will be : (AND, OR, XOR). Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.
Note :
‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
For example :
 Input: 
 'EXP’ = T|T & F
 There are total 2  ways to parenthesize this expression:
 (i) (T | T) & (F) = F
 (ii) (T) | (T & F) = T
 Out of 2 ways, one will result in True, so we will return 1.

 Output :
 1

 Constraints:
1 <= T <= 10
3 <= |‘EXP’| <= 200    
Where |EXP| denotes the length of 'EXP'.

Time Limit: 1 sec
*/

// Recursion + Memoization.
// TC: Exponential reduced to O(N^3), SC: O(NxNx2).
int f(vector<vector<vector<int>>>& table, string& E, int i, int j, bool isTrue){
    //cout<<i<<" "<<j<<endl;
    if(i>j) return 0;
    if(i==j){
        if(isTrue){
            return E[i]=='T';
        }
        else{
            return E[i]=='F';
        }
    }
    if(table[i][j][isTrue]) return table[i][j][isTrue];
    long ans=0;
    for(int k = i+1; k<=j-1; k+=2){
        long LT = f(table, E, i, k-1, 1), LF = f(table, E, i, k-1, 0),
             RT = f(table, E, k+1, j, 1), RF = f(table, E, k+1, j, 0);
        if(E[k]=='&'){
            if(isTrue) ans = (ans + (LT*RT)%mod)%mod;
            else ans = (ans + ((LF*RT)%mod + (LF*RF)%mod + (LT*RF)%mod)%mod)%mod;
            //cout<<"& used and ans is: "<<ans<<endl;
        }
        else if(E[k]=='|'){
            if(isTrue) ans = (ans + ((LT*RF)%mod + (LT*RT)%mod + (LF*RT)%mod)%mod)%mod;
            else ans = (ans + (LF*RF)%mod)%mod;
            //cout<<"| used and ans is: "<<ans<<endl;
        }
        else{
            if(isTrue) ans = (ans + ((LT*RF)%mod + (LF*RT)%mod)%mod)%mod;
            else ans = (ans + ((LT*RT)%mod + (LF*RF)%mod)%mod)%mod;
            //cout<<"^ used and ans is: "<<ans<<endl;
        }
    }
    return table[i][j][isTrue] = ans;
}
int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<int>>> table(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
    return f(table, exp, 0, n-1, 1);
}
/*
4
T&T
T^T^F
F|T^F
F&T
*/

// Tabulation.
// TC: O(N^3), SC: O(N^2)
int evaluateExp(string & E) {
    int n = E.size();
    vector<vector<vector<long>>> table(n+2, vector<vector<long>>(n+2, vector<long>(2, 0)));
    
    for(int i = n-1; i>=0; i-= 2){
        for(int j = 0; j< n; j+=2){
            if(i>j) continue;
            else if(i==j){
                table[i][j][1] = E[i]=='T';
                table[i][j][0] = E[i]=='F';
                continue;
            }
            for(int isTrue = 0; isTrue<2; ++isTrue){
                long ans=0;
                for(int k = i+1; k<=j-1; k+=2){
                    long LT = table[i][k-1][1], LF = table[i][k-1][0],
                         RT = table[k+1][j][1], RF = table[k+1][j][0];
                    if(E[k]=='&'){
                        if(isTrue) ans = (ans + (LT*RT)%mod)%mod;
                        else ans = (ans + ((LF*RT)%mod + (LF*RF)%mod + (LT*RF)%mod)%mod)%mod;
                        //cout<<"& used and ans is: "<<ans<<endl;
                    }
                    else if(E[k]=='|'){
                        if(isTrue) ans = (ans + ((LT*RF)%mod + (LT*RT)%mod + (LF*RT)%mod)%mod)%mod;
                        else ans = (ans + (LF*RF)%mod)%mod;
                        //cout<<"| used and ans is: "<<ans<<endl;
                    }
                    else{
                        if(isTrue) ans = (ans + ((LT*RF)%mod + (LF*RT)%mod)%mod)%mod;
                        else ans = (ans + ((LT*RT)%mod + (LF*RF)%mod)%mod)%mod;
                        //cout<<"^ used and ans is: "<<ans<<endl;
                    }
                }
                table[i][j][isTrue] = ans;
            }
        }
    }
    return table[0][n-1][1];
}