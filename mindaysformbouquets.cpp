//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
//1482. Minimum Number of Days to Make m Bouquets

#include<bits/stdc++.h>

using namespace std;

int solvetheprob(vector<int> bloomday, int m, int k, int sum)
{
    int tempk = 0, tempm = 0;

    for(int i =0; i<bloomday.size();i++){
        if(tempk%k == 0) tempk = 0;
        
        if (tempm < m){
        sum -= bloomday[i];
        ++tempk;
        if(sum < 0) return -1;
    }
}

int main()
{
    vector<int> bloomDay = {1,10,2,9,3,8,4,7,5,6};
    int m = 4, k = 2;

    int low = 0, high = accumulate(bloomDay.begin(), bloomDay.end(), 0), mid = (low+high)/2;

    while(low< high){
        mid = (low+high)/2;
        int temp = solvetheprob(bloomDay, m, k, mid);

    }
}