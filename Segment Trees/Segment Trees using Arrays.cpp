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

void buildTree(vector<int>& segmentTree, vector<int>& nums, int start, int end, int i){
    if(start > end) return;

    if(start == end){
        segmentTree[i] = nums[start];
        return;
    }
    
    int mid = (start+end)>>1;
    buildTree(segmentTree, nums, start, mid, 2*i +1);
    buildTree(segmentTree, nums, mid+1, end, 2*i +2);
    segmentTree[i] = segmentTree[2*i +1]+segmentTree[2*i +2];
    return;
}

void updateTree(vector<int>& segmentTree, int ind, int val, int start, int end, int i){
    if(start == end && start == ind){
        segmentTree[i] = val;
        return;
    }

    int mid = (start+end)>>1;
    if(ind <= mid){
        updateTree(segmentTree, ind, val, start, mid, 2*i +1);
    }
    else{
        updateTree(segmentTree, ind, val, mid+1, end, 2*i +2);
    }
    segmentTree[i] = segmentTree[2*i +1] + segmentTree[2*i +2];
    return;
}

int findRangeSum(vector<int>& segmentTree, int s, int e, int start, int end, int i){
    if(s <= start && e >= end){
        cout<< segmentTree[i]<<" ";
        return segmentTree[i];
    }

    int mid = (start+end)>>1;
    if(e <= mid){
        return findRangeSum(segmentTree, s, e, start, mid, 2*i +1);
    }
    else if(s >= mid+1){
        return findRangeSum(segmentTree, s, e, mid+1, end, 2*i +2);
    }
    else{
        return findRangeSum(segmentTree, s, mid, start, mid, 2*i +1) +
        findRangeSum(segmentTree, mid+1, e, mid+1, end, 2*i +2);
    }

    return 0;
}

int main(){
    vector<int> nums = {1,5,4,23,4,56,78,98,7654,323,4,5,6,7};
    vector<int> segmentTree(100);
    buildTree(segmentTree, nums, 0, nums.size()-1, 0);
    cout << "Sum in range: (0, 5) is: "<< endl << findRangeSum(segmentTree, 0, 5, 0, nums.size()-1, 0) << endl;
    
    cout << "Sum in range: (0, 8) is: "<< endl << findRangeSum(segmentTree, 0, 8, 0, nums.size()-1, 0) << endl;

    cout<<"Updating the number at index 7 to  40"<<endl;
    updateTree(segmentTree, 7, 40, 0, nums.size(), 0);

    cout << "Sum in range: (0, 8) is: "<< endl << findRangeSum(segmentTree, 0, 8, 0, nums.size()-1, 0) << endl;
    return 0;
}