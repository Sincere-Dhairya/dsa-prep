/**
 * @file 103. Binary Tree Zigzag Level Order Traversal
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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

//O(N) TC: Breadth First Search using deque.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool flag = 0;
        vector<vector<int> > ans;
        deque<TreeNode*> next;
        if(root) next.push_back(root);
        while(next.size()){
            vector<int> arr;
            int n = next.size();
            for(int i = 0; i<n; i++){
                if(flag){
                    TreeNode* node = next.back();
                    next.pop_back();
                    if(node->right) next.push_front(node->right);
                    if(node->left) next.push_front(node->left);
                    arr.push_back(node->val);
                }
                else{
                    TreeNode * node = next.front();
                    next.pop_front();
                    if(node->left) next.push_back(node->left);
                    if(node->right) next.push_back(node->right);
                    arr.push_back(node->val);
                }
            }
            ans.push_back(arr);
            flag = flag?0:1;
        }
        return ans;
    }
};
/*
[3,9,20,5,19,15,7,4,2,1,100,6,24,40,50]
*/