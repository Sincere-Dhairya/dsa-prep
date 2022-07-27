/**
 * @file 236. Lowest Common Ancestor of a Binary Tree
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * @link https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/ @endlink
 * @copyright Copyright (c) 2022
 * @tags Binary-Tree
 */
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

// TC: O(N), SC: O(N).
class Solution {
public:
    bool findPath(vector<TreeNode*>& path, TreeNode* root, TreeNode* node){
        if(!root) return 0;

        path.emplace_back(root);
        
        if(root == node){
            return 1;
        }
        
        if(findPath(path, root->left, node) || findPath(path, root->right, node)){
            return 1;
        }
        
        path.pop_back();
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        
        findPath(path1, root, p),
        findPath(path2, root, q);
        
        TreeNode* closestAncestor = root;
        for(int i = 0; i< min(path1.size(), path2.size()); ++i){
            if(path1[i] == path2[i]){
                closestAncestor = path1[i];
            }
            else{
                break;
            }
        }
        
        return closestAncestor;
    }
};