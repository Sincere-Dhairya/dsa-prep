/**
 * @file 1026. Maximum Difference Between Node and Ancestor
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-31
 * @link https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

 

Example 1:


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
Example 2:


Input: root = [1,null,2,null,0,3]
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 10^5
*/
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
class Solution { //O(N^2) O(N) without including recursion call stack.
public:
    void dfs(TreeNode * root, vector<int> &ancestors, int & maxdiff){
        if(!root)
            return;
        for(int i : ancestors)
            maxdiff = max(maxdiff, abs(i - root->val));
        ancestors.push_back(root->val);
        dfs(root->left, ancestors, maxdiff);
        dfs(root->right, ancestors, maxdiff);
        ancestors.pop_back();
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxdiff = 0;
        vector<int> arr;
        dfs(root, arr, maxdiff);
        return maxdiff;
    }
};

//O(N) approach.
class Solution {
public:
    void dfs(TreeNode* root, int & maxdiff, int max_num, int min_num){
        if(!root) return;
        max_num = max(max_num, root->val);
        min_num = min(min_num, root->val);
        maxdiff = max(maxdiff, max_num - min_num);
        dfs(root->left, maxdiff, max_num, min_num);
        dfs(root->right, maxdiff, max_num, min_num);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxdiff = 0;
        dfs(root, maxdiff, root->val, root->val);
        return maxdiff;
    }
};