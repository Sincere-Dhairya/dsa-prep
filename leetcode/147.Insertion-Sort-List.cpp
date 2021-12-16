/**
 * @file 147. Insertion Sort List
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
 

Constraints:

The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000


  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 */

//TC: O(N) . Space O(N). Not a great solution

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        priority_queue<int, vector<int>, greater<int>> list;
        ListNode * trav = head;
        while(trav)
            list.push(trav->val), trav = trav->next;
        trav = head;
        while(trav)
            trav->val = list.top(), list.pop(), trav = trav->next;
        return head;
    }
};

//O(N^2) and SC - O(1) gave TLE
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode * beg = head, *end = head;
        while(end->next and end->val == end->next->val)
            end = end->next;
        ListNode * trav = end->next;
        while(trav){
            ListNode * pres = trav;
            trav = trav->next;
            if(beg->val >= pres->val)
                end->next = pres->next, pres->next = beg, beg = pres;
            else if(end->val <= pres->val)
                end = pres;
            else{
                ListNode * temphead = beg;
                while(temphead != end and temphead->val <= pres->val and temphead->next->val < pres->val)
                    temphead = temphead->next;
                pres->next = temphead->next, temphead->next = pres;
            }
        }
        end->next = NULL;
        return beg;
    }
};


//Using Compare Structure template in priority_queue.
class Solution {
public:
    struct Compare{
        bool operator()(ListNode * node1, ListNode * node2){
            return node1->val>node2->val;
        }
    };
    ListNode* insertionSortList(ListNode* head) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* trav = head;
        while(trav)
            pq.push(trav), trav = trav->next;
        head = pq.top(), trav = head, pq.pop();
        while(pq.size()){
            trav->next = pq.top(), pq.pop(), trav = trav->next; 
        }
        trav->next = NULL;
        return head;
    }
};

//O(n^2) solution of finding right position of the next of curr element works.
class Solution {
public:
    typedef ListNode ln;
    ListNode* insertionSortList(ListNode* head) {
        ln * pivot = new ln(-5001);
        pivot->next = head;
        ln * trav = head;
        while(trav){
            if(trav->next and trav->next->val< trav->val){
                ln * temp = pivot;
                while(temp->next and temp->next->val < trav->next->val)
                    temp = temp->next;
                ln * copy = temp->next;
                temp->next = trav->next, trav->next = trav->next->next;
                temp->next->next = copy;
            }
            else
                trav = trav->next;
        }
        return pivot->next;        
    }
};