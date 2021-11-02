/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> arr;
        int n = -1, sum2 = 0;

        for(auto i : ops){
            if(i == "C") {
                sum2 -= arr.back();
                arr.pop_back();
                --n;
            }
            else if(i == "D") {
                arr.push_back(2*arr.back());
                ++n;
                sum2 += arr.back();
            }
            else if(i == "+"){
                //int n = arr.size();
                arr.push_back(arr[n] + arr[n-1]);
                sum2 += arr.back();
                ++n;
            }
            else{
                int j = stoi(i);
                arr.push_back(j);
                sum2 += j;
                ++n;
            }
            //cout<<sum2<<" ";
        }
        //int sum = accumulate(arr.begin(), arr.end(), 0);
        return sum2;
    }
};
// @lc code=end

