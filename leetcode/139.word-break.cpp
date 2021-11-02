/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    class trie{
        public:
        bool end;
        trie * alphas[26];
        trie(){
            end = false;
            for(int i = 0; i<26; i++){
                alphas[i] = nullptr;
            }
        }
    };

    void addword(trie * &dict, string word){
        trie * trav = dict;
        for(auto i : word){
            if(trav->alphas[i-'a'] == NULL){
                trav->alphas[i-'a'] = new trie;
            }
            trav = trav->alphas[i-'a'];
        }
        trav->end = true;
        //cout<<word<<" marked true"<<endl;
    }
/*
    this searching method wrong for a case when the strings are
    of same alphabet just like in a test case.

    bool searchword(trie * dict, string word){
        trie * root = dict;
        for(auto s : word){
            cout<<s<<" "<<root->end<<endl;
            if(root->end == true && (root->alphas[s-'a'] == NULL || dict->alphas[s-'a'] != NULL)){
                root = dict;
                cout<<"found"<<endl;
                //continue;
            }
            if(root->alphas[s-'a'] == NULL) {
                cout<<"executed"<<endl;
                return false;
            }
            root = root->alphas[s-'a'];
        }
        return root->end;
        //return (root==dict)?true:false;
    }
*/
    bool searchword(trie * dict, string word){
        for(auto s : word){
            if(dict->alphas[s-'a'] == NULL) return false;
            dict = dict->alphas[s-'a'];
        }
        return dict->end;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        trie * root = new trie;
        for(auto w : wordDict){
            addword(root, w);
        }
        int n = s.size();
        vector<bool> possible(n+1, 0);
        possible[0]=1;

        for(int i = 1; i<=n; i++){
            for(int j = 0; j<i; j++){
                if(possible[j] && searchword(root, s.substr(j, i-j))){
                    possible[i] = 1;
                    break;
                }
            }
        }
        return possible[n];
    }
};
/*
"leetcode"\n["leet","leetcode"]
"leetcode"\n["leetcode","code"]
"leetcode"\n["leet","leetco","code"]
"applepenapple"\n["apple","pen"]
"catsandog"\n["cats","dog","sand","and","cat"]
"helloworldiamdhairya"\n["dhairya","varshney","btech","i","am","iama","world","hello"]
"aaaaaaa"\n["aaaa","aaa"]

*/
// @lc code=end

