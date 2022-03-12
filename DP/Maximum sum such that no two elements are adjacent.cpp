/**
 * @file Maximum sum such that no two elements are adjacent
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-03-11
 * @link https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int non_adjacent_sum(vector<int> &arr){
    int n = arr.size(),
    including = 0,
    excluding = 0,
    exclude_now = 0;
    
    for(int i = 1; i<n; i++){
        exclude_now = including>excluding?including:excluding;

        including = excluding + arr[i];
        excluding = exclude_now;
    }
    return max(including, excluding);
}

int non_adjacent_sum_dp(vector<int> & arr){
    vector<int> record(arr.size()+1, 0);
    int n = arr.size();
    if(n==1){
        return arr[0];
    }
    else if(n==2){
        return max(arr[0], arr[1]);
    }
    else {
        record[0] = arr[0], record[1] = arr[1], record[2] = arr[0]+arr[2];
        for(int i=3; i<n; i++){
            record[i] = arr[i]+max(record[i-2], record[i-3]);
        }
        return max(record[n-1], record[n-2]);
    }
}
int main(){
    vector<int> arr = {5,5,10,100,10,5}, arr2={5,5,10,40,50,35};
    cout<<"The maximum non adjacent sum is: "<<non_adjacent_sum(arr)<<endl;
    cout<<"The maximum non adjacent sum is: "<<non_adjacent_sum_dp(arr)<<endl;
    cout<<"The maximum non adjacent sum is: "<<non_adjacent_sum(arr2)<<endl;
    cout<<"The maximum non adjacent sum is: "<<non_adjacent_sum_dp(arr2)<<endl;
    return 0;
}