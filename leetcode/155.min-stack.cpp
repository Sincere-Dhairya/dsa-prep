/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */

    class Node{
        public:
        int val;
        Node * next;
        Node(int data){
            this->val = data;
            this->next = NULL;
        }
    };
    Node * minelem, *head;

    MinStack() {
        head = nullptr;
        minelem = nullptr;
    }
    
    void push(int data) {
        MinStack::Node * temp = new MinStack::Node(data);
        if(!head){
            head = temp;
            minelem = temp;
        }
        else{
            temp->next = head;
            head = temp;
            if(minelem == NULL){
                Node * temp2 = new Node(data);
                minelem = temp2;
            }
            if(minelem!= NULL && minelem->val >= data){
                Node * temp2 = new Node(data);
                temp2->next = minelem;
                minelem = temp2;
            }

        }
    }
    
    void pop() {
        if(minelem->val == head->val){
            Node * temp1 = minelem;
            Node * temp2 = head;
            minelem = minelem->next;
            head = head->next;
            delete temp1, temp2;
        }
        else{
            Node * temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return minelem->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

