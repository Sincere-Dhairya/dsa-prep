#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> & a, pair<int, int> &b){
    return a.first>b.first;
}
int main(){
    vector<int> arr = {7, 8, 9, 4, 4, 5, 5, 5, 6};
    int k =2;

    map<int, int> list;

    for(int i = 0; i<arr.size() ; i++) ++list[arr[i]];

    vector< pair<int, int> > pairlist;
    vector<int> ans(k);
    
    auto itr = list.begin();
    for(int i =0; i<list.size(); i++){
        pairlist.push_back(make_pair(itr->second, itr->first));
        ++itr;
    }
    //cout<<"Pass2"<<endl;

    sort(pairlist.begin(), pairlist.end(), cmp);
    cout<<"Pass3"<<endl;
    for(int i =0; i<pairlist.size(); i++){
        //cout<<pairlist[i].first<<"  "<<pairlist[i].second<<endl;
    }
    
    for(int i =0; i<k; i++){
        ans[i] = pairlist[i].second;
        cout<<ans[i]<<" ";
    }
    cout<<"Pass1"<<endl;

}

struct node{
    int val;
    int freq;

    node(int a, int b){
        val = a;
        freq = b;
    }
};

struct compare{
    bool operator()(node const & a, node const & b){
        return a.freq<b.freq;
    }
};

//void sort( map<int, int> )
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> list;
    
    for(int i =0; i<nums.size(); i++) ++list[nums[i]];
    
    priority_queue<node, vector<node>, compare> pq;
    
    for(auto itr = list.begin(); itr != list.end(); itr++){
        pq.push(node(itr->first, itr->second));
    }
    
    cout<<pq.top().val;
    
    vector<int> ans;
    for(int i = 0; i<k; i++){
        ans.push_back(pq.top().val);
        pq.pop();
    }
    return ans;
}