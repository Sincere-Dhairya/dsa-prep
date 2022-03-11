/**
 * @file 61. Rotate List
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-03-11
 * @link https://leetcode.com/problems/rotate-list/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/*
Given the head of a linked list, rotate the list to the right by k places.


Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9
*/

// O(N) TC, O(1) SC
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        int len = 0;
        auto trav = head;
        while(trav){
            trav = trav->next;
            ++len;
        }
        
        k %= len;
        int reach = len-k;
        if(len == reach){
            return head;
        }
        
        trav = head;
        while(--reach > 0){
            trav = trav->next;
        }
        
        auto nxtptr = trav->next;
        trav->next = NULL;
        trav = nxtptr;
        while(trav and trav->next){
            trav = trav->next;
        }
        if(trav){
            trav->next = head;
        }
        return nxtptr;
    }
};