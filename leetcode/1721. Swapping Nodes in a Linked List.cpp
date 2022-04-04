/**
 * @file 1721. Swapping Nodes in a Linked List
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-04-04
 * @link https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 10^5
0 <= Node.val <= 100
*/

/* test cases
6
[1,2,3,4,5,6,7,8]
5
[1,2,3,4,5,6,7,8]
6
[1,2,3,4,5,6,7]
5
[1,2,3,4,5,6,7]
3
[1,2,3]
2
[1,2,3,4,5]
2
[7,9,6,6,7,8,3,0,9,5]
5
[1]
1
[1,2,3,4,5,6,7]
3
[1,2,3,4,5,6,7,8]
3
*/

// TC - O(N) SC - O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0, step = 1;
        ListNode* trav = head, * k1ptr = head, *slow = head, *fast = head;
        // Calculating the length of Linked List.
        while(trav != NULL){
            ++len;
            trav = trav->next;
        }
        if(k > (len+1)/2){
            k = len-k+1;
        }
        // Using Slow Fast method to reach out to the center node and also find the kth node fro mthe begining.
        while(slow && fast){
            if(step == k){
                k1ptr = slow;
            }
            slow = slow->next;
            if(fast->next){
                fast = fast->next->next;
            }
            else{
                break;
            }
            ++step;
        }
        
        step = 0, k = len%2==0?(len+1)/2 -k : (len+1)/2 -k -1;
        // Finding the kth node from the end and then swapping them.
        while(slow){
            if(step == k){
                swap(slow->val, k1ptr->val);
                break;
            }
            slow = slow->next;
            ++step;
        }
        
        return head;
    }
};