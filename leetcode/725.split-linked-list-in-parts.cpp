/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */

// @lc code=start
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
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef ListNode ln;

    int lengthcalc(ln * root){
        if(!root) return 0;
        int count = 0;
        while(root != NULL){
            ++count;
            root = root->next;
        }
        return count;
    }

    void dividing_list(ln * &head, int no, int len, int k, vector<ln*>& arr){
        ln * root = head;
        arr.push_back(root);
        //ln * temp = nullptr;
        //int n = no;
        no -=1;
        while(head != NULL && no != 0){
            //if(no == 1) temp = head;
            head = head->next;
            --no;
        }
        ln * temp = head;
        if (temp && head){
            head= head->next;
            temp->next = NULL;
        }
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = lengthcalc(head);
        vector<ln*> ans;
        if(len <= k){
            for(int i = 0; i<k; i++) dividing_list(head, 1, len, k, ans);
        }
        else{
            while(k !=0 ){
                int div = len/k;
                int mod = len%k;
                if(mod) div += 1;
                dividing_list(head, div, len, k, ans);
                len -= div;
                --k;
            }
        }
        return ans;
    }
};
// @lc code=end

