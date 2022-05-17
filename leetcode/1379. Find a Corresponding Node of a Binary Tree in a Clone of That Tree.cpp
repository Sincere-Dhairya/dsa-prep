/**
 * @file 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-17
 * @link https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

 

Example 1:


Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
Example 2:


Input: tree = [7], target =  7
Output: 7
Example 3:


Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
The values of the nodes of the tree are unique.
target node is a node from the original tree and is not null.
 

Follow up: Could you solve the problem if repeated values on the tree are allowed?
*/


// using Queue approach. O(N) in both Time and Space.
class Solution {
public:
    bool makePath(TreeNode* root, vector<int>& arr, TreeNode* &target){
        if(!root) return false;
        
        arr.push_back(root->val);
        if(root == target) return true;
        else if(makePath(root->left, arr, target)) return true;
        else if(makePath(root->right, arr, target)) return true;
        
        arr.pop_back();
        return false;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<int> treearray;
        bool check = makePath(original, treearray, target); // O(N)
        if(!check) return NULL;
        for(int i : treearray){ // O(N)
            if(i == cloned->val) continue;
            if(cloned->left && cloned->left->val == i){
                cloned = cloned->left;
            }
            else if(cloned->right && cloned->right->val == i){
                cloned = cloned->right;
            }
        }
        return cloned;
    }
};

// Recursion. DFS method. Time Space O(N).
class Solution {
public:
    bool makePath(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& ans){
        if(!original){
            return false;
        }
        if(original == target){
            ans = cloned;
            return true;
        }
        if(original->left && makePath(original->left, cloned->left, target, ans)) return true;
        else if(original->right && makePath(original->right, cloned->right, target, ans)) return true;
        
        return false;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode * ans = nullptr;
        bool check = makePath(original, cloned, target, ans);
        return ans;
    }
};