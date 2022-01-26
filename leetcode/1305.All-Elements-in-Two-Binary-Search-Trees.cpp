/**
 * @file 1305. All Elements in Two Binary Search Trees
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-26
 * @link https://leetcode.com/problems/all-elements-in-two-binary-search-trees/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

The number of nodes in each tree is in the range [0, 5000].
-10^5 <= Node.val <= 10^5
*/

//O(N) time & space
class Solution {
public:
    void inorder_trav(TreeNode * root, vector<int> & arr){
        if(!root){
            return;
        }
        inorder_trav(root->left, arr);
        arr.push_back(root->val);
        inorder_trav(root->right, arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2, ansarr;
        inorder_trav(root1, arr1),
        inorder_trav(root2, arr2);
        int n1 = arr1.size(), n2 = arr2.size(), i=0, j=0;
        while(i<n1 and j<n2){
            ansarr.push_back(arr1[i]<arr2[j]?arr1[i++]:arr2[j++]);
        }
        while(i<n1){
            ansarr.push_back(arr1[i++]);
        }
        while(j<n2){
            ansarr.push_back(arr2[j++]);
        }
        return ansarr;
    }
};

//Using Stack - Same time but less memory
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void stackfiller(stack<TreeNode*> &s, TreeNode * root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        stackfiller(s1, root1),
        stackfiller(s2, root2);
        vector<int> ans;
        
        while(!s1.empty() || !s2.empty()){
            stack<TreeNode*> &s = s1.empty()?s2:s2.empty()?s1:s1.top()->val<s2.top()->val?s1:s2;
            TreeNode *  node = s.top();
            s.pop();
            ans.push_back(node->val);
            stackfiller(s, node->right);
        }
        return ans;
    }
};