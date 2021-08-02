#include<bits/stdc++.h>

using namespace std;

int permutations(int n){
    if(n==1) return 1;
    else return n*permutations(n-1);
}

int calcpermutations(string s){
    int len = s.length();
    map<char, int> list;
    for(auto it:s) ++list[it];
    
    int ans = permutations(s.length());

    for(auto itr:list){
        if(itr.second != 1) ans /= permutations(itr.second);
    }

}
int amtpermutations(
    vector<int> arr, 
    int n, 
    int val
    ){
    vector<int> dparr(val+1, 0);
    dparr[0] = 1;
    for(int i = 1; i<val+1; i++){
        int sum_of_perms = 0;
        for(int j = 0; arr[j]<=i && j<n; j++) sum_of_perms += dparr[i-arr[j]];
        dparr[i] = sum_of_perms;
    }
    return dparr[val];
}
int main(){
    int n = 4;
    //cin>>n;
    vector<int> arr(n, 0);
    // for(int i =0; i<n; i++) 
    //     cin>>arr[i];
    arr = {2,3,5,6};
    int amt = 7;
    //cin>>amt;
    
    int k = amtpermutations(arr, n, amt);
    cout<<k;
    return 0;
}