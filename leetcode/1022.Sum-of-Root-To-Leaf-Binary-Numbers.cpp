/**
 * @file 1022. Sum of Root To Leaf Binary Numbers
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-12
 * @link https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

 

Example 1:


Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
Example 2:

Input: root = [0]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.
*/
class Solution {
public:
    void calcsum(TreeNode * root, int & sum, int num){
        num |= root->val;
        if(root->left == NULL and root->right == NULL){
            sum += num;
            return;
        }
        if(root->left){
            calcsum(root->left, sum, num<<1);
        }
        if(root->right){
            calcsum(root->right, sum, num<<1);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int number = 0, sum = 0;
        calcsum(root, sum, number);
        return sum;
    }
};