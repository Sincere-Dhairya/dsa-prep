/**
 * @file 211. Design Add and Search Words Data Structure
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-28
 * @link https://leetcode.com/problems/design-add-and-search-words-data-structure/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.
*/

//O(nlogN) Trie DFS method
class WordDictionary {
public:
    class Trie{
        public:
        bool end;
        set<int> list;
        vector<Trie*> alphs;
        Trie(){
            end = false;
            alphs = vector<Trie*>(26, NULL);
        }
    };
    Trie * dict;
    WordDictionary() {
        dict = new Trie;
    }
    
    void addWord(string word) {
        //cout<<word<<endl;
        Trie * saver = dict;
        for(auto c : word){
            int ind = c-'a';
            //cout<<c<<endl;
            if(!saver->alphs[ind]){
                saver->alphs[ind] = new Trie;
                saver->list.insert(ind);
            }
            saver = saver->alphs[ind];
        }
        saver->end = true;
    }
    
    bool dfs(Trie * finder, string word, int n, int i){
        //cout<<i<<endl;
        if(finder == NULL){
            return false;
        }
        if(i == n){
            return finder?finder->end:false;
        }
        
        if(isalpha(word[i])){
            return dfs(finder->alphs[word[i]-'a'], word, n, i+1);
        }
        else{
            if(finder->list.empty()){
                return false;
            }
            for(int ind: finder->list){
                if(dfs(finder->alphs[ind], word, n, i+1)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(string word) {
        Trie * finder = dict;
        if(word.find('.') != string::npos){
            //cout<<"Ander"<<endl;
            int len = word.end()-word.begin();
            return dfs(finder, word, len, 0);
        }
        else{
            //cout<<"bahar"<<endl;
            for(char c: word){
                if(finder->alphs[c-'a']){
                    finder=finder->alphs[c-'a'];
                }
                else{
                    return false;
                }
            }
            return finder->end;
        }
        return false;
    }
};
