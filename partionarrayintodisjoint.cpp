#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> & a, pair<int, int> & b){
    return a.first < b.first;
}

void sorting(unordered_map<int, int> & list){
    int n = list.size();

    vector<pair<int, int>> sample;
    auto itr = list.begin();

    for(auto& itr : list){
        sample.push_back(itr);
    }

    sort(sample.begin(), sample.end());

    //list.clear();

    //cout<<endl<<sample[0].first<<" "<<sample[0].second<<endl;

    // for(itr; itr != list.end(); itr++){
    //     cout<<itr->first<<" "<<itr->second<<endl;
    // }
    //cout<<list.bucket(5)<<endl;
}

int main(){
    // vector<int> nums = {5, 0, 3, 0, 8, 6};
    // int n = nums.size();

    // vector<int> support(n-1);

    // for(int i = 1; i<n; i++){
    //     support[i-1] = nums[i];
    // }

    // make_heap(support.begin(), support.end(), greater<int>{});

    // for(int n : support) cout<<n<<" ";
    // cout<<endl;
    // pop_heap(support.begin(), support.end());
    // for(int n : support) cout<<n<<" ";
    // cout<<endl;

    vector<int> nums = {5, 0, 3, 0, 8, 6};
    int n = nums.size();

    unordered_map<int, int> list = {{0, 2}, {3, 1}, {8, 1}, {6, 1}};
    int maxim = nums[0], i;
    sorting(list);
    
    for(auto itr = list.begin(); itr != list.end(); itr++){
        cout<<itr->first<<"  "<<itr->second<<endl;
    }
    cout<<endl;
    for(i =0; i<n ; i++){
        cout<<"i is: "<<i<<endl<<"nums[i] is: "<<nums[i]<<endl;
        maxim = max(maxim, nums[i]);

        cout<<"changing list"<<endl;
        if(list.count(nums[i])) {
            cout<<"entered else2"<<endl;
            --list[nums[i]];
            if(list[nums[i]] == 0) {
                list.erase(nums[i]);
                if(!list.count(nums[i]))
                cout<<list.count(nums[i])<<endl;
            }
        }

        cout<<"list.begin is: "<<list.begin()->first<<endl;
        if(maxim <= list.begin()->first) break;
        cout<<endl;
    }

    cout<<endl<<i+1<<" is the answer"<<endl;
    
    for(auto itr: list){
        cout<<endl<<itr.first<<" "<<itr.second;
    }
}
