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
#include<iostream>
#include<vector>
using namespace std;

class STN{
    public:
    int start, end, sum;
    STN* left, *right;

    STN(){
        start = end = sum = 0;
        left = right = NULL;
    }

    STN(int s, int e){
        start = s, end = e, sum = 0;
        left = right = nullptr;
    }
};

STN * buildTree(vector<int>& nums, int s, int e){
    if(s > e) return NULL;

    STN* node = new STN(s, e);
    if(s == e){
        node->sum = nums[s];
        return node;
    }

    int mid = (s+e)/2;
    node->left = buildTree(nums, s, mid);
    node->right = buildTree(nums, mid+1, e);
    node->sum = node->left->sum + node->right->sum;

    return node;
}

void updateTree(STN* root, int ind, int val){
    if(root->start == ind && root->end == ind){
        root->sum = val;
        return;
    }

    int mid = (root->start + root->end)/2;
    if(ind <= mid){
        updateTree(root->left, ind, val);
    }
    else{
        updateTree(root->right, ind, val);
    }
    root->sum = root->left->sum + root->right->sum;
    return;
}

int findRangeSum(STN* root, int s, int e){
    if(root->start <= s && root->end >= e){
        cout << root->sum << " ";
        return root->sum;
    }

    int mid = (root->start + root->end)/2;

    if(e <= mid){
        return findRangeSum(root->left, s, e);
    }
    else if(s >= mid+1){
        return findRangeSum(root->right, s, e);
    }
    else{
        return (findRangeSum(root->left, s, mid) + findRangeSum(root->right, mid+1, e));
    }
    return 0;
}

int main(){
    vector<int> nums = {1,5,4,23,4,56,78,98,7654,323,4,5,6,7};
    STN* root = buildTree(nums, 0, nums.size()-1);
    cout << "Sum in range: (0, 5) is: "<< endl<< findRangeSum(root, 0, 5) << endl;
    
    cout << "Sum in range: (0, 8) is: "<< endl<< findRangeSum(root, 0, 8) << endl;

    cout<<"Updating the number at index 7 to  40"<<endl;
    updateTree(root, 7, 40);

    cout << "Sum in range: (0, 8) is: "<< endl<< findRangeSum(root, 0, 8) << endl;
    return 0;
}