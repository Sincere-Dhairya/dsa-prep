#include <bits/stdc++.h>
using namespace std;

class trie{
    public:
    bool word;
    trie * arr[26];
    trie(){
        word = false;

        for(int i =0 ; i<26; i++){
            arr[i] = NULL;
        }
    }
};

void insertion(trie * & root, string s){
    trie * trav = root;
    for(auto i : s){
        if(trav->arr[i-'a'] == NULL){
            trav->arr[i-'a'] = new trie;
        }
        trav = trav->arr[i-'a'];
    }
    trav->word = true;
}

void search(trie * root, string s){
    for(auto i : s){
        if(root->arr[i-'a'] == NULL){
            //cout<<"Not Found!";
            break;
        }
        root = root->arr[i-'a'];
    }
    if(root->word) cout<<"Found";
    else cout<<"Not Found";
}
int main() {
	// your code goes here
	trie * root = new trie;
	vector<string> arr = {"hello", "golu"};
	for(auto s : arr){
	    insertion(root, s);
	}
	
	string s = "helll";
	search(root, s);
	return 0;
}