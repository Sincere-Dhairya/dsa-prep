/**
 * @file 105. Construct Binary Tree from Preorder and Inorder Traversal
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/

//Recursive- Divide and Conquer O(n);
class Solution {
public:
    typedef TreeNode tn;
    tn * treemaker(vector<int> pre, int a, int b, vector<int> in, int i, int j){
        cout<<a<<" "<<b<<" "<<i<<" "<<j<<endl;
        if(a == b and i == j)
            return new tn(pre[a]);
        if(a>b || i > j)
            return NULL;
        int x = i;
        while(in[x] != pre[a])
            ++x;
        tn * root = new tn(pre[a]);
        root->left = treemaker(pre, a+1, a+(x-i), in, i, x-1);
        root->right = treemaker(pre, a+1+(x-i), b, in, x+1, j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return treemaker(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};