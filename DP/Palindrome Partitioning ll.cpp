/**
 * @file Palindrome Partitioning ll
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-28
 * @link https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_873266 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a string ‘str’. Find the minimum number of partitions to make in the string such that every partition of the string is a palindrome.
Given a string, make cuts in that string to make partitions containing substrings with size at least 1, and also each partition is a palindrome. For example, consider “AACCB” we can make a valid partition like A | A | CC | B. Among all such valid partitions, return the minimum number of cuts to be made such that the resulting substrings in the partitions are palindromes.
The minimum number of cuts for the above example will be AA | CC | B. i.e 2 cuts
Note :
1) We can partition the string after the first index and before the last index.

2) Each substring after partition must be a palindrome.

3) For a string of length ‘n’, if the string is a palindrome, then a minimum 0 cuts are needed.  

4) If the string contains all different characters, then ‘n-1’ cuts are needed.

5) The string consists of upper case English alphabets only with no spaces.

Constraints :
1 <= T <= 50
1 <= length(string) <= 100


Where ‘T’ is the total number of test cases, ‘length(string)’ denotes the length of the string.

Time limit: 1 second
*/

// Recursion + Memoization.
// TC: Exponential, SC: O(N)
bool checkPalindrome(string& s, int i, int j){
    if(s[i]!=s[j]) return false;
    else if(i==j) return true;
    else if(i+1 == j && s[i]==s[j]) return true;
    return checkPalindrome(s, i+1, j-1);
}

int f(vector<int>& cache, string& s, int& n, int i){
    if(i==n) return 0;
    if(cache[i]) return cache[i];
    int ans = 1e8;
    for(int j=i; j<n; ++j){
        if(checkPalindrome(s, i, j)){
            int cuts = 1+f(cache, s, n, j+1);
            ans = min(ans, cuts);
        }
    }
    return cache[i] = ans;
}

int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> cache(n+1);
    return f(cache, str, n, 0)-1;
}

// Optimized PalindroemCheck
int f(vector<vector<int>>& palin, vector<int>& cache, string& s, int& n, int i){
    if(i==n) return 0;
    if(cache[i]) return cache[i];
    int ans = 1e8;
    for(int j=i; j<n; ++j){
        if(palin[i][j]){
            int cuts = 1+f(palin, cache, s, n, j+1);
            ans = min(ans, cuts);
        }
    }
    return cache[i] = ans;
}
void PalindromeMaker(vector<vector<int>>& palin, int& n, string& s){
    for(int i=n-1; i>=0; --i){
        for(int j=0; j<n; ++j){
            if(i>j) continue;
            else if(i==j) palin[i][i]=1;
            else{
                if(s[i]==s[j]){
                    if(i+1 == j) palin[i][j] = 1;
                    else palin[i][j] = palin[i+1][j-1];
                }
            }
        }
    }
}
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> cache(n+1);
    vector<vector<int>> palin(n+1, vector<int>(n+1, 0));
    PalindromeMaker(palin, n, str);
    
    return f(palin, cache, str, n, 0)-1;
}

// Tabulation.
// TC: O(N^2), SC: O(N^2)
void PalindromeMaker(vector<vector<int>>& palin, int& n, string& s){
    for(int i=n-1; i>=0; --i){
        for(int j=0; j<n; ++j){
            if(i>j) continue;
            else if(i==j) palin[i][i]=1;
            else{
                if(s[i]==s[j]){
                    if(i+1 == j) palin[i][j] = 1;
                    else palin[i][j] = palin[i+1][j-1];
                }
            }
        }
    }
}

int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> cache(n+1);
    vector<vector<int>> palin(n+1, vector<int>(n+1, 0));
    PalindromeMaker(palin, n, str);
    for(int i = n-1; i>=0; --i){
        int ans = 1e8;
        for(int j=i; j<n; ++j){
            if(palin[i][j]){
                int cuts = 1+cache[j+1];
                ans = min(ans, cuts);
            }
        }
        cache[i] = ans;
    }
    return cache[0]-1;
}