/**
 * @file FrogJump
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
We are given an array of heights of different stair cases. The frog wants to go from 
0th stair to the top most stair. It can do so by jumping to the next stair or to the
next to next stair. By jumping, it uses energy = abs(height[i] - height[i+1]).
Find the minimum total energy required by the frog to reach the last stair.
*/

#include<bits/stdc++.h>
using namespace std;

int sumEnergy(vector<int> & heights, int i, int n){
    if(n <= i){
        //cout<<i<<" "<<0<<endl;
        return 0;
    }
    int oneJump = INT_MAX, twoJump = INT_MAX;
    oneJump = abs(heights[i]-heights[i+1]) + sumEnergy(heights, i+1, n);
    //if(n-1 != i){
        twoJump = abs(heights[i]-heights[i+2]) + sumEnergy(heights, i+2, n);
    //}
    //cout<<i<<" "<<min(oneJump, twoJump)<<endl;
    return min(oneJump, twoJump); 
}

int sumEnergy(vector<int>& heights, vector<int>& cache, int i, int n){
    if(i >= n){
        return 0;
    }
    if(cache[i]){
        return cache[i];
    }

    return cache[i] = min(
        abs(heights[i]-heights[i+1]) + sumEnergy(heights, cache, i+1, n),
        abs(heights[i]-heights[i+2]) + sumEnergy(heights, cache, i+2, n)
    );
}

int sumEnergy(vector<int>& heights){
    int n = heights.size();
    vector<int> cache(n,0);
    cache[n-1]=0, cache[n-2] = abs(heights[n-2]-heights[n-1]);

    for(int i = n-3; i>=0; --i){
        cache[i] = min(
            abs(heights[i]-heights[i+1])+cache[i+1],
            abs(heights[i]-heights[i+2])+cache[i+2]
        );
    }
    return cache[0];
}

int main(){
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    // find the minimum total energy required by the frog to reach the last stair.
    //recursion
    cout<<"For the given heights, the minimum total energy required by the Frog will be: "
    << endl<< sumEnergy(heights, 0, heights.size()-1);

    //memoization
    vector<int> cache(heights.size());
    cout<<endl<<endl<< sumEnergy(heights, cache, 0, heights.size()-1);

    //tabulation
    cout<<endl<<endl<<sumEnergy(heights);
    return 0;
}