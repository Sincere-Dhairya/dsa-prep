/**
 * @file 116. Populating Next Right Pointers in Each Node
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-29
 * @link https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * @copyright Copyright (c) 2021
 * 
 */
/**
 * You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 212 - 1].
-1000 <= Node.val <= 1000
*/

//Brute Force using level order traversal: TC: O(N), SC O(N)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        if(root->right == NULL || root->left == NULL)
            return root;
        queue<Node*> q;
        q.push(root->left), q.push(root->right);
        while(q.size()){
            int n = q.size();
            Node * one = q.front();
            q.pop();
            if(one->left)
                q.push(one->left);
            if(one->right)
                q.push(one->right);
            for(int i =1; i<n; i++){
                Node * two = q.front();
                q.pop();
                one->next = two;
                one = two;
                if(one->left)
                    q.push(one->left);
                if(one->right)
                    q.push(one->right);            
            }
        }
        return root;
    }
};

//Optimized Solution: TC- O(N) , SC- O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root or(root->left == NULL or root->right == NULL)) 
            return root;
        Node * saveroot = root;
        while(root->left){
            Node * node = root;
            while(node){
                node->left->next = node->right;
                if(node->next)
                    node->right->next = node->next->left;
                node = node->next;
            }
            root = root->left;
        }
        return saveroot;
    }
};