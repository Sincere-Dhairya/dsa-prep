/**
 * @file 662. Maximum Width of Binary Tree
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-28
 * @link https://leetcode.com/problems/maximum-width-of-binary-tree/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
*/

//O(N) approach.
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long width = 0;
        queue<pair<TreeNode*, unsigned long>> q;
        q.push({root, 0});
        while(q.size()){
            unsigned long start = q.front().second;
            auto currnode = q.front();
            int s = q.size();
            for(int i=0 ;i<s; ++i){
                currnode = q.front(), q.pop();
                if(currnode.first->left){
                    q.push({currnode.first->left, 2*currnode.second});
                }
                if(currnode.first->right){
                    q.push({currnode.first->right, 2*currnode.second+1});
                }
            }
            unsigned long end = currnode.second;
            width = max(width, end-start+1);
        }
        return width;
    }
};

/*
Test Cases
[0,0,0,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null]
[1,2,3,4,5,6,7,8,9,null,null,10,null,null,11]
[1,3,2,5,3,null,9]
*/