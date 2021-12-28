/**
 * @file 876. Middle of the Linked List
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-28
 * @link https://leetcode.com/problems/middle-of-the-linked-list/
 * @copyright Copyright (c) 2021
 * 
 */

/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

//Using Fast Row Method
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* rabbit = head;
        while(rabbit and rabbit->next){
            rabbit = rabbit->next->next;
            head = head->next;
        }
        return head;
    }
};