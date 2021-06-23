#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> arr ={-2, -3, 4, -1, -2, 1, 5, -3};
    int k;
    cin>>k;
    int flag = 0;
    
    for (int i = 0; i< arr.size(); i++){
        if(arr[i] >0) {
            flag = 1;
            break;
        }

    }
    if (flag == 0 | k == 0) {
        cout<<0<<endl;
        return 0;
    }
    /*
    vector<int> sumarr;
    sumarr.push_back(0);
    int n = arr.size();
    for(int i = 0, j = 0; i<(n*k); ++i, ++j){
        if(i%n == 0) j = 0;
        cout<<i<<" "<<j<<" ";
        sumarr.push_back(max(arr[j], (arr[j] + sumarr[i])%1000000007));
        cout<<sumarr[i+1]<<endl;
    }
    cout<<*max_element(sumarr.begin(), sumarr.end());
    */
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if(sum >= 0){
        vector<int> sumarr;
        sumarr.push_back(0);
        for(int i = 0, j = 0; i<(n*2); ++i, ++j){
            if(i%n == 0) j = 0;
            cout<<i<<" "<<j<<" ";
            sumarr.push_back(max(arr[j], (arr[j] + sumarr[i])%1000000007));
            cout<<sumarr[i+1]<<endl;
        }
        cout<<*max_element(sumarr.begin(), sumarr.end())+(k-2)*sum<<endl;
        return (*max_element(sumarr.begin(), sumarr.end())+(k-2)*sum);

    }
    else{
        vector<int> sumarr;
        sumarr.push_back(0);
        for(int i = 0, j = 0; i<(n*2); ++i, ++j){
            if(i%n == 0) j = 0;
            cout<<i<<" "<<j<<" ";
            sumarr.push_back(max(arr[j], (arr[j] + sumarr[i])%1000000007));
            cout<<sumarr[i+1]<<endl;
        }
        cout<<*max_element(sumarr.begin(), sumarr.end())<<endl;
        return (*max_element(sumarr.begin(), sumarr.end()));

    }

}