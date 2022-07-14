/**
 * @file Find-Maximum-XOR
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * @tags tries
 */
/*
Given an array of integers, find the maximum XOR value possible by performing the XOR operation betweenn any two integers of the array.
*/
#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

#define BITS 2
#define BITSIZE 32

class TRIE{
    public:
    vector<TRIE*> bits;
    
    TRIE(){
        bits = vector<TRIE*>(BITS);
        for(int i=0; i<BITS; ++i){
            bits[i] = NULL;
        }
    }
};

void insertion(TRIE* &T, int num){
    bitset<BITSIZE> b(num);
    TRIE* postman = T;
    
    for(int i=BITSIZE-1; i>=0; --i){
        int bit = b[i];
        if(postman->bits[bit] == NULL){
            postman->bits[bit] = new TRIE;
        }
        postman = postman->bits[bit];
    }
}

int findMaxXOR(TRIE* &T, int num){
    bitset<BITSIZE> b(num);
    TRIE* finder = T;
    int number = 0;
    
    for(int i = BITSIZE-1; i>=0; --i){
        int bit = b[i];
        if(finder->bits[bit]==NULL && finder->bits[!bit] == NULL){
            return number;
        }
        else if(finder->bits[!bit]){
            if(!bit) number |= (1<<i);
            finder = finder->bits[!bit];
        }
        else{
            if(bit) number |= (1<<i);
            finder = finder->bits[bit];
        }
    }
    return number;
}

int main(){
    TRIE * tree = new TRIE;
    vector<int> arr = {6, 6, 0, 6, 8, 5, 6, 3};

    for(int i: arr){
        insertion(tree, i);
    }

    int maxXOR = 0;
    for(int i=0; i<arr.size(); ++i){
        int number = findMaxXOR(tree, arr[i]);
        maxXOR = max(maxXOR, arr[i]^number);
        cout<<arr[i]<<" ^ "<<number<<" = "<<(arr[i]^number)<<endl;
    }

    cout<<maxXOR<<endl;
    return 0;
}

/**
 * The above approach uses O(NlogN) TC and O(Nx32x2) at max SC, will be less than that.
 */