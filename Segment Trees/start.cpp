/**
 * @file start
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * @tags segment-tree
 */
/* Segment Trees are used in Range Query based questions. */

#include<bits/stdc++.h>

using namespace std;

int build(vector<int>& segment, vector<int>& arr, int ind, int left, int right){
    if(left == right){
        segment[ind] = arr[left];
    }

    int mid = left + (right-left)/2;
    int minLeft = build(segment, arr, left, mid);
    int minRight = build(segment, arr, mid+1, right);
    segment[ind] = min(minLeft, minRight);
}
int main(){
    vector<int> arr = {2, 1, 0, 4, 3, 7};
}