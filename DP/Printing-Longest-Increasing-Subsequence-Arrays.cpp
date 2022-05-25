/**
 * @file Printing-Longest-Common-Subsequence-Arrays
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/* Print the Longest Increasing Subsequence in an Array. */
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> cache(n+1, 1), prevnode(n+1);
    for(int i = 0; i<=n; ++i){
        prevnode[i] = i;
    }
    int len = 1, ind = 0;
    for(int i = 1; i<n; ++i){
        for(int j = 0; j<i; ++j){
            if(arr[i] > arr[j]){
                if(cache[j]+1 > cache[i]){
                    cache[i] = cache[j]+1;
                    prevnode[i] = j;
                }
            }
        }
        if(len < cache[i]){
            ind = i, len = cache[i];
        }
    }
    cout<<arr[ind]<<" ";
    while(prevnode[ind] != ind){
        cout<<arr[prevnode[ind]]<<" ";
        ind = prevnode[ind];
    }
    return len;
}

// We can also use the Binary Search Method.