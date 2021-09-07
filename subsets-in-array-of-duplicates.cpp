#include<bits/stdc++.h>

using namespace std;
//subsets.count(arr)
void create_subsets(int i, vector<int> arr, vector<int> A, vector<vector<int>> &ans, set<vector<int>> & subsets){
    vector<bool> check(20, false);
    for(int j = i+1; j<A.size(); j++){
        arr.push_back(A[j]);
        
        if(check[A[j]] == 0){
			//cout<<endl<<A[j];
            ans.push_back(arr);
            //subsets.insert(arr);
            check[A[j]] = true;
            create_subsets(j, arr, A, ans, subsets);
        }
        arr.pop_back();
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &A) {
    set<vector<int>> subsets;
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    ans.push_back({});
    subsets.insert({});
    for(int i = 0; i<A.size(); i++){
        if(i != 0 && A[i] == A[i-1]) continue;
        //cout<<endl<<A[i]<<" ->";
		vector<int> arr = {A[i]};
        ans.push_back(arr);
        subsets.insert(arr);
        create_subsets(i, arr, A, ans, subsets);
    }
    return ans;
}

void printing(vector<vector<int> > arr){
	for(int i =0; i<arr.size(); i++){
        if(arr[i].size() == 0){
            cout<<'@'<<endl;
            continue;
        }
		for(int j =0; j<arr[i].size(); j++) cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

int main() {
	// your code goes here
	vector<int> arr = {5,5,1,2};
	auto ans = subsetsWithDup(arr);
	//cout<<endl;
	printing(ans);
	return 0;
}

