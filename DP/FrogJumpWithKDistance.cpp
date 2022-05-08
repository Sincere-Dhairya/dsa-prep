/**
 * @file FrogJump With K Distance
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
Same Question as we have in Frog Jump. Now the frog can have k jumps as:
i->i+1
i->i+2
i->i+3
.
.
.
i->i+k
Calculate the minimum total energy the frog should have to reach the top.
*/

#include<bits/stdc++.h>
using namespace std;

int sumEnergy(vector<int>& heights, int k, int n, int i){
    if(i >= n){
        //cout<<i<<" "<<0<<endl;
        return 0;
    }
    
    int energy = INT16_MAX, end = min(n, i+k);
    for(int j = i+1; j<=end; ++j){
        energy = min(
            energy,
            abs(heights[i]-heights[j])+sumEnergy(heights, k, n, j)
        );
    }
    //cout<<i<<" "<<energy<<endl;
    return energy;
}

int sumEnergy(vector<int>& heights, vector<int>& cache, int k, int n, int i){
    if(i >= n){
        return 0;
    }
    if(cache[i]){
        return cache[i];
    }
    int end = min(n, i+k), energy = INT16_MAX;
    for(int j = i+1; j<=end; ++j){
        energy = min(
            energy,
            abs(heights[i]-heights[j])+sumEnergy(heights, cache, k, n, j)
        );
    }
    return cache[i] = energy;
}

int sumEnergy(vector<int>& heights, int k){
    int n = heights.end()- heights.begin();
    vector<int> cache(n);
    cache[n-1] = 0, cache[n-2] = abs(heights[n-1]-heights[n-2]);
    for(int i = n-3; i>=0; --i){
        int energy = INT16_MAX;
        for(int j = i+1; j<n && j<= i+k; ++j){
            energy = min(
                energy,
                abs(heights[i]-heights[j])+cache[j]
            );
        }
        cache[i] = energy;
    }
    return cache[0];
}

int main(){
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int n = heights.size();
    vector<int> cache(n, 0);
    cout<<sumEnergy(heights, 4, n-1, 0)<<endl<<endl;
    cout<<sumEnergy(heights, cache, 4, n-1, 0)<<endl<<endl;
    cout<<sumEnergy(heights, 4)<<endl<<endl;
    return 0;
}