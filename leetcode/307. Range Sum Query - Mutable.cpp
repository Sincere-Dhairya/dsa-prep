/**
 * @file 307. Range Sum Query - Mutable
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-23
 * @link link-object @endlink
 * @copyright Copyright (c) 2022
 * @tags segment-tree
 */
/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.
*/

class NumArray {
public:
    class STN{
        public:
        int start, end, sum;
        STN* left, *right;
        
        STN(){
            start = end = sum = 0;
            left = NULL, right = NULL;
        }
        
        STN(int start, int end){
            this->start = start, this->end = end;
            this->left = NULL, this->right = NULL;
            this->sum = 0;
        }
    };
    STN * root = nullptr;
    
    // TC: O(N).
    STN * buildTree(vector<int> & nums, int s, int e){
        if(s>e) return NULL;
        
        STN* node = new STN(s, e);
        if(s == e){
            node->sum = nums[s];
            return node;
        }
        
        int mid = (s+e)/2;
        node->left = buildTree(nums, s, mid),
        node->right = buildTree(nums, mid+1, e);
        node->sum = node->left->sum + node->right->sum;
        
        return node;
    }
    
    // TC: O(LogN).
    void updateTree(STN* root, int val, int pos){
        if(root->start == pos && root->end == pos){
            root->sum = val;
            return ;
        }
        
        int mid = (root->start + root->end)/2;
        if(pos <= mid){
            updateTree(root->left, val, pos);
        }
        else {
            updateTree(root->right, val, pos);
        }
        root->sum = root->left->sum + root->right->sum;
        return;
    }
    
    // TC: O(Log N).
    int rangeSum(STN* root, int s, int e){
        if(root->start == s && root->end == e){
            return root->sum;
        }
        
        int mid = (root->start + root->end)/2;
        if(e <= mid){
            return rangeSum(root->left, s, e);
        }
        else if(s >= mid+1){
            return rangeSum(root->right, s, e);
        }
        else{
            return rangeSum(root->left, s, mid) + rangeSum(root->right, mid+1, e);
        }
        return 0;
    }
    
    NumArray(vector<int>& nums) {
        // cout<< "inside NumArray"<<endl;
        // this->root = new STN();
        this->root = buildTree(nums, 0, nums.size()-1);
        // cout<< "exit NumArray"<<endl;
    }
    
    // O(LogN)
    void update(int index, int val) {
        // cout<< "inside update"<<endl;
        updateTree(this->root, val, index);
        // cout<< "end update"<<endl;
    }
    
    // O(LogN)
    int sumRange(int left, int right) {
        // cout<< "inside sumRange"<<endl;
        return rangeSum(this->root, left, right);
    }
};