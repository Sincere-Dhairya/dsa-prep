/**
 * @file 114. Flatten Binary Tree to Linked List
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * @link https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ @endlink
 * @copyright Copyright (c) 2022
 * @tags recursion, binary-search-tree
 */
/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 

Follow up: Can you flatten the tree in-place (with O(1) extra space)?
*/

// TC: O(NxN), SC: O(1).
class Solution {
public:
    TreeNode* flattening(TreeNode* root){
        if(!root) return NULL;
        
        TreeNode* leftNode = flattening(root->left),
        * rightNode = flattening(root->right);
        
        root->left = NULL;
        if(leftNode){
            root->right = leftNode;
            auto tempnode = leftNode;
            while(tempnode->right){
                tempnode = tempnode->right;
            }
            tempnode->right = rightNode;
        }
        else{
            root->right = rightNode;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        root = flattening(root);
        return;
    }
};

// TC: O(N), SC: O(N).
class Solution {
public:
    void DFSForArray(TreeNode* root, vector<TreeNode*>& arr){
        if(root == NULL)return;
        arr.emplace_back(root);
        
        DFSForArray(root->left, arr);
        DFSForArray(root->right, arr);
        
        return ;
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> arr;
        DFSForArray(root, arr);
        for(int i = 0; i<arr.size(); ++i){
            arr[i]->left = nullptr;
            arr[i]->right = (i == arr.size()-1)?NULL: arr[i+1];
        }
        return ;
    }
};