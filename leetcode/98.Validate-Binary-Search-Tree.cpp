/**
 * @file 98. Validate Binary Search Tree
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-10
 * @link https://leetcode.com/problems/validate-binary-search-tree/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1
*/

//O(N) if we count the call stack of recursion.
class Solution {
public:
    bool isValidBST(TreeNode* root, long low_b, long upp_b, int par) {
        if(!root){
            return true;
        }
        
        if(root->val == par || root->val <= low_b || root->val >= upp_b){
            return false;
        }
        
        return (isValidBST(root->left, low_b, root->val, root->val) && isValidBST(root->right, root->val, upp_b, root->val));
    }
    bool isValidBST(TreeNode* root){
        long upp_b = long(INT_MAX)+1, low_b = long(INT_MIN)-1;
        return (root->left == NULL and root->right == NULL) || 
            (isValidBST(root->left, low_b, root->val, root->val) and 
             isValidBST(root->right, root->val, upp_b, root->val)
            );
    }
};

/*
[10,null,20,11,null,null,19]
[2,2,2]
*/