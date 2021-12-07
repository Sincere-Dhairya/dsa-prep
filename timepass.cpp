#include<bits/stdc++.h>

//#include"buysellstock.cpp"

using namespace std;
bool cmp(pair<string, int> & a, pair<string, int> & b)
{
    return a.second < b.second;
}
/*
int main()
{
    cout<<"Hello World\n";
    map<string, int> map1 = {{"he", 1}, {"she",0}, {"oth",3}};
    vector<pair<string, int>> temp;
    auto itr = map1.begin();
    for(itr; itr!=map1.end(); itr++){
        temp.push_back(make_pair(itr->first, itr->second));
    }

    sort(temp.begin(), temp.end(), cmp);
    for(int i =0; i<temp.size(); i++){
        cout<<temp[i].first<<" "<<temp[i].second<<endl;
    }

    
}
*/
void func(int n, vector<int> &nums) {

	vector<int> arr;
	arr.push_back(nums[0]);
	cout<<1<<" ";
	for(int i = 1; i < n; i++) {
        if(nums[i] < arr[arr.size() - 1]) {
			int ind = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
            cout<<typeid(lower_bound(arr.begin(), arr.end(), nums[i])).name();
			arr[ind] = nums[i];
		} else {
			arr.push_back(nums[i]);
		}
		cout<<arr.size()<<" ";
	}
}
bool cmp(pair<int, int> & a, pair<int, int> & b){
    return a.first<b.first;
}
int main() {
    
    vector<int> nums = {1,2, 0};
    if(nums[0] == 1 && nums[1] == 2) return 1;

    int n = nums.size();
    set<int> list;

    map<int, int> map1;
    
    for(int i =0; i<n; i++){
        ++map1[nums[i]];
    }
    
    //sort(map1.begin(), map1.end(), cmp);

    auto itr = map1.begin();
    cout<<itr->first<<endl;

    for(int i =1; i<n; i++)
        list.insert(nums[i]);
    
    int maxim = nums[0], i;

    for(i =0; i<n; i++){
        auto tempitr = list.find(nums[i]);
        //cout<<"Tempitr exits: "<<*tempitr<<endl;
        if(tempitr == list.end()){
            //cout<<"entered"<<endl;
            if(nums[i] == *tempitr) list.erase(tempitr);
            //cout<<"exited"<<endl;
        }
        else list.erase(tempitr);
        
        maxim = max(maxim, nums[i]);
        if(list.empty()) break;
        if(maxim <= *list.begin()) break;
    }
    cout<<i+1;
    return i+1;
	//int n;
	//cin>>n;
    /*
	vector<int> nums = {2,5,4,90,7,1};
    sort(nums.begin()+2, nums.begin()+5);
    
    for(int i =0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
		int a;*/
	// for(int i = 0; i < n; i++) {
	// 	cin>>a;
	// 	nums[i] = a;
	// }

    //for(int i =0; i<)
    //func(n, nums);
    /*
    vector<int> A = {1, 3, 5, 5, 7, 9};
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i =0; i<A.size(); i++){
        pq.push(A[i]);
    }
    for(int i =1; i<4; i++){
        pq.pop();
    }
    cout<<pq.top()<<endl;*/

    return 0;
}
