/**
 * @file House-Robber-2
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
We have a Robber and a some houses. The houses are arranged in a circle
such that the first house and the last house are the neighbours.
We are given the array containing the amount present with ith home. 
the robber is required to rob non adjacent houses.
Find the maximum wealth the robber can take out.
*/

#include<bits/stdc++.h>
using namespace std;

int maxRoberry(vector<int>& money, int n, int i){
    if(i >= n){
        return 0;
    }
    return max(
        money[i]+maxRoberry(money, n, i+2),
        maxRoberry(money, n, i+1)
    );
}

int maxRobbery(vector<int>& money, vector<int>& cache, int n, int i){
    if(i >= n){
        return 0;
    }
    if(cache[i]){
        return cache[i];
    }
    return max(
        money[i]+maxRobbery(money, cache, n, i+2),
        maxRobbery(money, cache, n, i+1)
    );
}

int maxRobbery(vector<int>& money){
    int n = money.end()-money.begin();
    vector<int> cache(n,0);
    
    // Considering first home to be robbed.
    cache[n-2] = money[n-2], cache[n-3] = max(money[n-3], cache[n-2]);
    for(int i = n-4; i>=0; --i){
        cache[i] = max(
            money[i]+cache[i+2],
            cache[i+1]
        );
    }
    int ans = cache[0];

    // Considering the last home to be robbed.
    cache[n-1] = money[n-1], cache[n-2] = max(money[n-2], cache[n-1]);
    for(int i = n-2; i>0; --i){
        cache[i] = max(
            money[i]+cache[i+2],
            cache[i+1]
        );
    }
    ans = max(ans, cache[1]);
    return ans;
}

int main(){
    vector<int> arr = {10,20,10,30,0,0,8,24,25};
    // Recursion.
    int n = arr.size();
    cout<< maxRoberry(arr, n-1, 0)<<" "<< maxRoberry(arr, n, 1)<<endl;

    // Memoization
    vector<int> cache(n,0);
    cout<<maxRobbery(arr, cache, n-1, 0)<<" "<<maxRobbery(arr, cache, n, 1)<< endl;

    // Tabulation
    cout<<maxRobbery(arr)<<endl;
    return 0;
}