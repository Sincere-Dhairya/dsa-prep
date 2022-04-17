/**
 * @file 897. Increasing Order Search Tree
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-04-17
 * @link https://leetcode.com/problems/increasing-order-search-tree/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]
 

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
*/

// TC- O(N) 
class Solution {
public:
    void flatten(TreeNode * root, TreeNode * &head){
        if(!root){
            return;
        }
        flatten(root->left, head);
        head->right = root, root->left = NULL, head = head->right;
        flatten(root->right, head);
        return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * head = new TreeNode(INT_MIN), * trav = head;
        flatten(root, trav);
        return head->right;
    }
};