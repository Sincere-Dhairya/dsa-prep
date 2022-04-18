/**
 * @file 230. Kth Smallest Element in a BST
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-04-18
 * @link https://leetcode.com/problems/kth-smallest-element-in-a-bst/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
*/

// TC -> O(N) - Inorder Traversal. SC -> O(N) [ for Recusrion ]
class Solution {
public:
    int traversal(TreeNode* root, int & k, int & i){
        if(!root){
            return -1;
        }
        int left = traversal(root->left, k, i);
        if(left > -1){
            return left;
        }
        ++i;
        if(i == k){
            return root->val;
        }
        int right = traversal(root->right, k, i);
        if(right > -1){
            return right;
        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return traversal(root, k, i);
    }
};