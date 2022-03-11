/**
 * @file 2. Add Two Numbers
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-03-10
 * @link https://leetcode.com/problems/add-two-numbers/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

//O(N+M)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num = l1->val + l2->val, carry = num/10;
        num %= 10;
        ListNode * head = new ListNode(num), *trav = head, *trav1 = l1->next, *trav2 = l2->next;
        while(trav1 or trav2){
            num = trav1?trav1->val:0;
            num += trav2?trav2->val:0;
            if(trav1){
                trav1= trav1->next;
            }
            if(trav2){
                trav2=trav2->next;
            }
            num += carry;
            carry = num/10;
            num %=10;
            trav->next = new ListNode(num);
            trav = trav->next;
        }
        if(carry){
            trav->next = new ListNode(carry);
        }
        return head;
    }
};

/* test Cases
[5,6,4]
[0]
[0]
[9,9,9,9,9,9,9]
[9,9,9,9]
[9,9,9]
[0]
[0]
[9,8,9,8,9,8]
*/