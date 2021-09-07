#include<bits/stdc++.h>

using namespace std;

void create_subsets(int one, int i, vector<int> arr, vector<int> A, vector<vector<int>> & ans){
    //if(i == arr.size()) return;
    for(int j = i+1; j<A.size(); j++){
        arr.push_back(A[j]);
        ans.push_back(arr);
        cout<<"Pushed"<<endl;
        create_subsets(A[j], j, arr, A, ans);
        arr.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &A) {
    vector<vector<int>> ans;
    ans.push_back({});
    for(int i =0 ;i<A.size(); i++){
        vector<int> arr;
        arr.push_back(A[i]);
        ans.push_back(arr);
        create_subsets(A[i], i, arr, A, ans);
    }
    return ans;
}

int main(){
    vector<int> arr = {5,1,4,2,3};
    sort(arr.begin(), arr.end());
    auto ans_arr = subsets(arr);

    for(int i = 0; i<ans_arr.size(); i++){
        for(int j = 0; j<ans_arr[i].size(); j++) cout<<ans_arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<ans_arr.size()<<endl;
    vector<int> arr2 = {5,1,4,2,3};
    if(arr2 == arr) cout<<"same";
}