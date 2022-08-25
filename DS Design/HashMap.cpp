#include<iostream>
#include<vector>

using namespace std;

class HashMap{
	private:
	const int SIZE = 10000;
	vector<vector<pair<int, int>>> hashTable;
	
	public:
	HashMap();
	void insert(int, int);
	void erase(int);
	int getVal(int);
	int size();
	int count(int);
};

HashMap::HashMap(){
	hashTable = vector<vector<pair<int, int>>> (SIZE);
}

// 2 cases, either the key already exists, then we need to update the value, else we nee to insert the key value pair.

void HashMap::insert(int key, int val){
	int tableInd = key%SIZE;
	
	bool found = false;
	for(pair<int, int>& data: hashTable[tableInd]){
		if(data.first == key){
			data.second = val;
			found = true;
			break;
		}
}

if(!found){
	hashTable[tableInd].emplace_back(make_pair(key, val));
}
return ;
}

void HashMap::erase(int key){
	int tableInd = key%SIZE;
	bool found = false;
	
	for(int i= 0; i<hashTable[tableInd].size(); ++i){
		if(hashTable[tableInd][i].first == key){
			hashTable[tableInd].erase(hashTable[tableInd].begin()+i);
			found = 1;
			break;
		}
	}
	if(!found){
		cout << "Erase operation not possible. Key doesnt exists in the HashMap." << endl;
}
return ;
}

int HashMap::getVal(int key){
	int tableInd = key%SIZE;
	
	for(pair<int, int> & data: hashTable[tableInd]){
		if(data.first == key){
			return data.second;
		}
	}
	
	cout << "The key doesnt exists in the HashMap." << endl;
	return -1;
}

int HashMap::size(){
	int totalSize = 0;
	for(int i = 0; i<SIZE; ++i){
		totalSize += hashTable[i].size();
	}
	return totalSize;
}

int HashMap::count(int key){
	int tableInd = key%SIZE;

	for(pair<int, int> data: hashTable[tableInd]){
		if(data.first == key){
			return 1;
		}
	}
	return 0;
}

int main(){
	HashMap map;
	
	map.insert(5,101);
	map.insert(500,101);
	map.insert(55,101);
	map.insert(45,101);
	map.insert(4500,101);
	map.insert(50000,101);
	map.insert(0,101);
	map.insert(100,101);
	map.insert(1000,101);
	map.insert(10000,101);
	map.insert(95,101);
	map.insert(5953,101);
	map.insert(575,101);
	map.insert(755,101);
	map.insert(1255,101);
	map.insert(445,101);
	map.insert(5,101);
	map.insert(5,101);
	map.insert(445,101);

	map.erase(445);
	map.erase(95);
	map.erase(0);
	map.erase(445);

	map.count(5);
	map.count(1000);
	map.count(1);
	
    cout << map.size() << endl; 
    cout << map.getVal(1255) << endl;
	return 0;
}
