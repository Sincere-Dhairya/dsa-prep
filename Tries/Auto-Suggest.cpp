/**
 * @file Auto-Suggest
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * @link link-object @endlink
 * @copyright Copyright (c) 2022
 * @tags tries dynamic-programming urban-company
 */
/*
Given an array of words, and another word. Return the list of words that should be suggested to the user that have least Levenshtein Distance.
Levenshtien Distance is the minimum steps taken using delete, replace and insert to convert String A to String B.

Constraint:
1 <= N <= 100
1 <= words[i].length <= 10
1 <= S.length <= 10

Example:
3
"hey", "hello", "world"
"helto"

Output: 
Hello
*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Trie{
    public:
    string end;
    unordered_map<char, Trie*> children;

    Trie(){
        end = "";
        children.clear();
    }
};

int getMinLevenshteinDistance(vector<vector<int>>&table, string& A, string& B, int i, int j){
    // base cases.
    if(i == A.size() && j == B.size()){
        return 0;
    }

    if(i == A.size()){
        return B.size()-j;
    }

    if(j == B.size()){
        return A.size() -i;
    }
    if(table[i][j] > -1) return table[i][j];
    int ans = 0;
    if(A[i] == B[j]){
        ans = getMinLevenshteinDistance(table, A, B, i+1, j+1);
    }
    else{
        ans = 1+min(
            getMinLevenshteinDistance(table, A, B, i+1, j+1), // replace
            min(
                getMinLevenshteinDistance(table, A, B, i, j+1), // deletion
                getMinLevenshteinDistance(table, A, B, i+1, j) // insertion.
            )
        );
    }
    return table[i][j] = ans;
}

int findLevenshteinDistance(string A, string B){
    vector<vector<int>> table(A.size(), vector<int>(B.size(), -1));
    return getMinLevenshteinDistance(table, A, B, 0, 0);
}

void insertion(Trie * &root, string &word){
    Trie* postman = root;

    for(char &c: word){
        if(postman->children.count(c) == 0){
            postman->children[c] = new Trie();
        }
        postman = postman->children[c];
    }
    postman->end = word;
    return;
}

// function to get all the words in the trie passed to this function.
void getWords(Trie* root, vector<string>& arr){
    if(root->end.size()){
        arr.emplace_back(root->end);
    }

    for(auto P: root->children){
        getWords(P.second, arr);
    }
    return ;
}

vector<string> autoSuggest(vector<string>& words, Trie* &T, string& word){
    Trie* miner = T;
    vector<string> ans, similarWords;

    for(char &c: word){
        if(miner->children.count(c) == 0){
            similarWords = vector<string>();
            getWords(miner, similarWords);
            int minCost = 1e9;
            for(string w: similarWords){
                int cost = findLevenshteinDistance(word, w);
                if(cost < minCost){
                    minCost = cost;
                    ans = {w};
                }
                else if(cost == minCost){
                    ans.emplace_back(w);
                }
            }
            break;
        }
        else{
            miner = miner->children[c];
        }
    }
    return ans;
}

int main(){
    vector<string> words = {"hey", "hello", "world"};
    // cout << findLevenshteinDistance("helto", "hello") << endl;
    string word = "helto";
    Trie* T = new Trie();

    for(string &s: words){
        insertion(T, s);
    }

    vector<string> ans = autoSuggest(words, T, word);

    for(auto s: ans){
        cout << s <<" ";
    }

    return 0;
}