/**
 * @file 2338. Count the Number of Ideal Arrays
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * @link https://leetcode.com/problems/count-the-number-of-ideal-arrays/ @endlink
 * @copyright Copyright (c) 2022
 * @tags recursion
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric> // for accumulate.
using namespace std;
#define mod 1000000007

long returnNums(vector<long>& indexVals, int n, int maxVal){
    if(n == 2){
        vector<long> arr(maxVal+1, 0);
        long sum = 0;
        for(int i = 1; i<= maxVal; ++i){
            arr[i] = maxVal/i;
            sum = (sum + arr[i])%mod;
        }
        indexVals = arr;
        return sum;
    }
    
    long forOnes = returnNums(indexVals, n-1, maxVal), total = forOnes;
    vector<long> arr(maxVal+1, 0);
    
    arr[1] = forOnes;
    for(int i=2; i<= maxVal; ++i){
        long count = indexVals[i];
        int j = i;
        long sum = 0;
        while(count--){
            sum = (sum+indexVals[j])%mod;
            j += i;
            if(j > maxVal) break;
        }
        arr[i] = sum;
        total = (total + arr[i])%mod;
    }
    
    indexVals = arr;
    return total;
}

int idealArrays(int n, int maxValue) {
    vector<long> indexVals;
    return returnNums(indexVals, n, maxValue);
}

int main(){
    cout<<idealArrays(100, 900)<<endl;
    return 0;
}