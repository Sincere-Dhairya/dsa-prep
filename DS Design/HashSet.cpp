#include<iostream>
#include<vector>

using namespace std;

class HashSet{
	private:
	vector<vector<int>> hashTable;
	const int SIZE = 10000;
	public:
	HashSet(); 
	void insert(int);
	void erase(int);
	int count(int);
	bool isEmpty();
	int size();
};

HashSet::HashSet(){
	hashTable = vector<vector<int>>(SIZE);
}

// In insertion, 2 cases. 
void HashSet::insert(int val){
	int tInd = val%SIZE;
	bool found = false;
	
	for(int &i: hashTable[tInd]){
		if(i == val){
			found = true;
			break;
		}
	}
	
	if(found){
		return ;	
    }
    
    hashTable[tInd].emplace_back(val);
    return ;
}

void HashSet::erase(int val){
	int tableInd = val%SIZE;
	bool found = false;
	
	for(int i = 0; i<hashTable[tableInd].size(); ++i){
		if(hashTable[tableInd][i] == val){
			found = true;
			hashTable[tableInd].erase(hashTable[tableInd].begin()+i);
			break;
		}
	}
	
	if(!found){
		cout << "Erase function not possible. Element does not exists in the HashTable." << endl;
	}
    return ;
}

// count : returns 1 if the value is found in the table. otherwise it returns 0.
int HashSet::count(int val){
	int tableInd = val%SIZE;
	for(int &num: hashTable[tableInd]){
		if(num == val){
			return 1;
		}
    }
    return 0;
}

bool HashSet::isEmpty(){
	bool empty = true;
	for(int i = 0; i<SIZE; ++i){
		if(hashTable[i].size()){
			empty = false;
			break;
        }
    }
    return empty;
}

int HashSet::size(){
	int totalSize = 0;
	for(int i = 0; i<SIZE; ++i){
		totalSize += hashTable[i].size();
	}
	return totalSize;
}

int main(){
	HashSet set1;
	cout << set1.isEmpty() << endl;
	set1.insert(5);
	set1.insert(500);
	set1.insert(55);
	set1.insert(45);
	set1.insert(4500);
	set1.insert(50000);
	set1.insert(0);
	set1.insert(100);
	set1.insert(1000);
	set1.insert(10000);
	set1.insert(95);
	set1.insert(5953);
	set1.insert(575);
	set1.insert(755);
	set1.insert(1255);
	set1.insert(445);
	set1.insert(5);
	set1.insert(5);
	set1.insert(445);

	set1.erase(445);
	set1.erase(95);
	set1.erase(0);
	set1.erase(445);

	set1.count(5);
	set1.count(1000);
	set1.count(1);
	
    cout << set1.isEmpty() << endl; 
    cout << set1.size() << endl;
	return 0;
}
