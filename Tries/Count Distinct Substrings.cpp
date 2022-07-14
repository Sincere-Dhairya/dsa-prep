/**
 * @file Count Distinct Substrings
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * @link https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292 @endlink
 * @copyright Copyright (c) 2022
 * @tags tries
 */
/*
*/

#include<iostream>
#include<vector>
using namespace std;


class Trie{
    public:
    bool word;
    vector<Trie*> children;
    
    Trie(){
        this->word = 0;
        int LIMIT = 26;
        this->children = vector<Trie*>(LIMIT);
        
        for(int i = 0; i<LIMIT; ++i){
            this->children[i] = NULL;
        }
    }
};

// TC: O(LogN). SC: O(26xK). K is max length of a word.
void insertion(Trie* &T, string s, int & count){
    Trie* miner = T;
    
    for(char c: s){
        if(miner->children[c-'a'] == NULL){
            miner->children[c-'a'] = new Trie;
            ++count;
        }
        miner= miner->children[c-'a'];
    }
}

// TC: O(NxN LogN)
int countDistinctSubstrings(string &s){
    Trie* Node = new Trie;
    int count = 0;
    
    for(int i =0; i<s.length(); ++i){
        string sub = "";
        for(int j=i; j<s.length(); ++j){
            sub.push_back(s[j]);
            insertion(Node, sub, count);
        }
    }
    return count+1;
}

int main(){
    string s = "abc";
    cout<< countDistinctSubstrings(s)<<endl;
    return 0;
}