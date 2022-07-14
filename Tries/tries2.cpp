
#include <bits/stdc++.h>
using namespace std;

#define BITSIZE 4

class Trie{
	public:
	vector<Trie*> bits;

	Trie(){
		bits = vector<Trie*>(2);
		const int LIMIT = 2;

		for(int i=0; i<LIMIT; ++i){
			bits[i] = NULL;
		}
	}
};

void insertion(Trie * &T, bitset<BITSIZE> b){
	Trie* postman = T;
	int bits = BITSIZE;
	cout<< (int)b.to_ulong() <<endl;
	while(bits){
		int bit = b[bits-1];
		if(postman->bits[bit] == NULL){
			postman->bits[bit] = new Trie;
			cout<< bit<< " node created! "<<endl;
		}
		else{
			cout<< bit<< " node exists! "<<endl;
		}
		postman = postman->bits[bit];
		
		--bits;
	}
	cout<< endl;
	return ;
}

int searchMaximumXOR(Trie* &T, bitset<BITSIZE> b){
	Trie * finder = T;
	int bits = BITSIZE, number = 0;
	cout<< (int)b.to_ulong() << endl;
	while(bits){
		bool bitOfb = b[bits-1];
		cout<< bits<<" "<<bitOfb<<endl;
		if(finder->bits[!bitOfb] == NULL && finder->bits[bitOfb] == NULL){
			cout<< "Nothing found! "<<endl;
			return number;
		}
		else if(finder->bits[!bitOfb]){
			cout<< " Anti exists!" <<endl;
			// number |= ((!bitOfb)<<bits);
			if(!bitOfb){
				number |= (1<<(bits-1));
			}
			// else{
			// 	number |= (0<<bits);
			// }
			finder = finder->bits[!bitOfb];
		}
		else{
			cout<< " Same exists!" <<endl;
			if(bitOfb){
				number |= (1<<(bits-1));
			}
			finder = finder->bits[bitOfb];
		}
		cout<<number<<endl;
		--bits;
	}
	cout<<endl;

	return number;
}

int main() {
	vector<int> arr= {2,5,3,1};

	Trie * T = new Trie;

	for(int i =0; i<arr.size(); ++i){
		bitset<BITSIZE> b(arr[i]);
		insertion(T, b);
	}

	bitset<BITSIZE> b(2);

	cout << searchMaximumXOR(T, b);

	return 0;
}

// int main() {
// 	vector<int> arr= {2,5,3,1};

// 	Trie * T = new Trie;

// 	for(int i =0; i<arr.size(); ++i){
// 		bitset<BITSIZE> b(arr[i]);
// 		insertion(T, b);
// 	}

// 	bitset<BITSIZE> b(2);

// 	cout << searchMaximumXOR(T, b);

// 	return 0;
// }


// #include <iostream>
// #include<bitset>

// using namespace std;

// int main() {
// 	// your code goes here
// 	bitset<4> b(5);
// 	cout<<b<<endl;
// 	b[1] = 1;
// 	cout<< b<<endl;
// 	cout<< (int)b.to_ulong()<<endl;
// 	return 0;
// }

