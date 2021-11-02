/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct compare{
        bool operator()(pair<int, string> & a, pair<int, string> & b){
            if(a.first == b.first){
                //bool sign = true;
                if(a.second.compare(b.second)> 0) return true;
                else return false; 
            }
            return a.first<b.first;
        }
    };

    // bool cmp(pair<int, string> &a, pair<int, string> & b){
    //     if(a.first > b.first) return 0;
    // }

    void printing(priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq){
        while(!pq.empty()){
            cout<<pq.top().second<<" "<<pq.top().first<<endl;
            pq.pop();
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string, int> list;

        for(string s : words) ++list[s];

        auto itr = list.begin();
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        for(auto i : list) pq.push({i.second, i.first});
        printing(pq);
        while(k != 0){
            auto temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
            --k;
        }
        return ans;
    }
};
// @lc code=end

