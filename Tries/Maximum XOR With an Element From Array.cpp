/**
 * @file Maximum XOR With an Element From Array
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * @link https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020 @endlink
 * @copyright Copyright (c) 2022
 * @tags tries
 */
/*
You are given an array/list ‘ARR’ consisting of ‘N’ non-negative integers. You are also given a list ‘QUERIES’ consisting of ‘M’ queries, where the ‘i-th’ query is a list/array of two non-negative integers ‘Xi’, ‘Ai’, i.e ‘QUERIES[i]’ = [‘Xi’, ‘Ai’].
The answer to the ith query, i.e ‘QUERIES[i]’ is the maximum bitwise xor value of ‘Xi’ with any integer less than or equal to ‘Ai’ in ‘ARR’.
You should return an array/list consisting of ‘N’ integers where the ‘i-th’ integer is the answer of ‘QUERIES[i]’.
Note:
1. If all integers are greater than ‘Ai’ in array/list ‘ARR’  then the answer to this ith query will be -1.

Constraints:
1 <= T <= 50
1 <= N, M <= 10000
0 <= ARR[i], Xi, Ai <= 10^9

Where ‘T’ is the number of test cases, 'N' is the size of ‘ARR’, ‘M’  is the number of queries, ‘ARR[i]’ is an element of array/list ‘ARR’ and ‘Xi’, ‘Ai’ are the integers in ‘QUERIES[i]’.  

Time limit: 1 sec
*/
#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>

using namespace std;

#define BITSIZE 32

class Trie{
    public:
    vector<Trie* > bits;

    Trie(){
        const int LIMIT = 2;
        this->bits = vector<Trie*>(LIMIT);

        for(int i=0; i<LIMIT; ++i){
            this->bits[i] = NULL;
        }
    }
};

void insertion(Trie* &T, int & num){
    bitset<BITSIZE> num_in_bits(num);
    Trie* miner = T;

    for(int i = BITSIZE-1; i>=0; --i){
        int bit = num_in_bits[i];
        if(miner->bits[bit] == NULL){
            miner->bits[bit] = new Trie;
        }
        miner = miner->bits[bit];
    }
}

int findMaxXOR(Trie* &T, int & num){
    bitset<BITSIZE> num_in_bits(num);
    Trie* finder = T;

    int number = 0;

    for(int i=BITSIZE-1; i>=0; --i){
        int bit = num_in_bits[i];
        if(finder->bits[!bit] != NULL){
            if(bit == 0){
                number |= (1<<i);
            }
            finder = finder->bits[!bit];
        }
        else if(finder->bits[bit] != NULL){
            if(bit == 1){
                number |= (1<<i);
            }
            finder = finder->bits[bit];
        }
    }
    // cout<<" The number is: "<<number<<endl;
    return num^number;
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	    sort(arr.begin(), arr.end());
    
    vector<pair<int, pair<int, int>>> ordered_queries;
    for(int i=0; i<queries.size(); ++i){
        ordered_queries.push_back({queries[i][1], {queries[i][0], i}});
    }

    sort(ordered_queries.begin(), ordered_queries.end(),
        [](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){ return a.first < b.first? 1:0; }
    );

    Trie* number_tree = new Trie;
    vector<int> ans(ordered_queries.size(), 0);
    for(int i=0, j=0; i<ordered_queries.size(); ++i){
        while(j<arr.size() && arr[j] <= ordered_queries[i].first){
            insertion(number_tree, arr[j]);
            ++j;
        }
        if(j == 0) {
            ans[ordered_queries[i].second.second] = -1;
        }
        else{
            ans[ordered_queries[i].second.second] = findMaxXOR(number_tree, ordered_queries[i].second.first);
        }
    }

    return ans;
}