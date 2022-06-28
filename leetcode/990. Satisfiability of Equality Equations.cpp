/**
 * @file 990. Satisfiability of Equality Equations
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-28
 * @link https://leetcode.com/problems/satisfiability-of-equality-equations/ @endlink
 * @copyright Copyright (c) 2022
 * @tags union-find
 */
/*
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 

Constraints:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.
*/

// Union Find.
// TC: O(NxN), SC: O(N) Call Stack + O(N) Parent + Rank.
class Solution {
public:
    int getParent( int i, vector<int>& parent){
        if(parent[i] == i) return i;
        return parent[i] = getParent(parent[i], parent);
    }
    void setParent(int i, int j, vector<int>& parent, vector<int>& rank){
        int u = getParent(i, parent), v = getParent(j, parent);
        if(u == v){
            return;
        }
        
        if(rank[u] > rank[v]){
            parent[v] = u;
            rank[u] += rank[v];
        }
        else{
            parent[u] = v;
            rank[v] += rank[u];
        }
        return;
    }
    void initParent(vector<int>& parents){
        for(int i =0; i<26; ++i){
            parents[i] = i;
        }
        return;
    }
    bool equationsPossible(vector<string>& E) {
        vector<int> parent(26, 0), rank(26, 1);
        initParent(parent);
        
        unordered_map<int, unordered_set<int>> list;
        for(int i = 0; i<E.size(); ++i){
            int a = E[i][0]-'a', b = E[i][3]-'a';
            int pa = getParent(a, parent), pb = getParent(b, parent);
            if(E[i][1] == '='){
                setParent(a, b, parent, rank);
            }
        }
        
        for(int i =0; i<E.size(); ++i){
            int a = E[i][0]-'a', b = E[i][3]-'a';
            int pa = getParent(a, parent), pb = getParent(b, parent);
            if(E[i][1] == '!'){
                if(pa == pb) return 0;
            }
        }
        return 1;
    }
};