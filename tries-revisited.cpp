#include <iostream>
#include<vector>
using namespace std;

class Trie{
	public:
	bool end;
	vector<Trie*> children;

	Trie(){
		cout << "Trie instance being created!" <<endl;
		end = 0;
		const int LIMIT = 26; 

		children = vector<Trie*> (LIMIT);
		for(int i=0; i<LIMIT; ++i){
			children[i] = NULL;
		}
	}
};

void insertion(Trie* & T, string S){
	Trie* postman = T;

	for(char &c: S){
		if(postman->children[c-'a'] == NULL){
			postman->children[c-'a'] = new Trie;
		}
		postman = postman->children[c-'a'];
	}

	postman->end = true;

	return;
}

bool searching(Trie* & T, string S){
	Trie* finder = T;

	for(char &c: S){
		if(finder->children[c-'a'] == NULL) return false;
		finder = finder->children[c-'a'];
	}

	return finder->end;
}

int main() {
	cout << "Let's Implement Tries. "<<endl;
	cout << "Enter a string to save it inside a Trie Class instance. "<<endl;
	string s;
	cin >> s;

	Trie *T = new Trie;
	insertion(T, s);
	
	cout<<searching(T, s)<<endl;

	return 0;
}