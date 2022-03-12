/**
 * @file 138. Copy List with Random Pointer
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * @link https://leetcode.com/problems/copy-list-with-random-pointer/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-10^4 <= Node.val <= 10^4
Node.random is null or is pointing to some node in the linked list.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// TC - O(N) SC - O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        unordered_map<Node*, Node*> list;
        Node * trav1 = head, * head2 = new Node(head->val),
        *trav2 = head2;
        list[trav1]= trav2;
        while(trav1 and trav2){
            trav2->val = trav1->val;
            if(trav1->next){
                list[trav1->next] = new Node(trav1->next->val);
                trav2->next = list[trav1->next];
            }
            else{
                trav2->next = NULL;
            }
            trav1 = trav1->next, trav2 = trav2->next;
        }
        trav1 = head, trav2 = head2;
        while(trav1){
            trav2->random = trav1->random?list[trav1->random]:NULL;
            trav1 = trav1->next,
            trav2 = trav2->next;
        }
        return head2;
    }
};