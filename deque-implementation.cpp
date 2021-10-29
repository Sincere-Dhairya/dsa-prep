// Deque Implementation
#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int val;
        node * left;
        node * right;
        node(int data);
};

node :: node(int data){
    this->val = data;
    this->left = nullptr;
    this->right = nullptr;
}

void push_front(node * &first, int data){
    node * var = new node(data);
    var->right = first;
    first->left = var;
    first = var;
}

void pop_front(node * &first){
    node * temp = first;
    first = first->right;
    first->left = nullptr;
    delete temp;
}

void push_back(node * &back, int data){
    node * var = new node (data);
    var->left = back;
    back->right = var;
    back = var;
}

void pop_back(node * &back){
    node * var = back;
    back = back->left;
    back->right = nullptr;
    delete var;
}

void display(node * first){
    while(first){
        cout<<first->val<<" <-"<<endl;
        first = first->right;
    }
}

void destroy(node * &first){
    while(first){
        node * var = first;
        first = first->right;
        delete var;
    }
}

bool isempty(node * first){
    if(first == NULL) return true;
    return false;
}

int size(node * first){
    int len = 0;
    while(first) ++len, first = first->right;
    return len;
}

int show_front(node * first){
    if(first) return first->val;
    return -1; 
}

int show_back(node * back){
    if(back) return back->val;
    return -1;
}

int main(){
    node * ptr = new node(5);
    node * first = ptr;
    node * back = ptr;
    push_front(first, 3);
    push_front(first, 4);
    push_front(first, 2);
    display(first);
    cout<<endl<<endl;
    push_back(back, 5);
    push_back(back, 15);
    push_back(back, 7);
    display(first);
    cout<<endl<<endl;
    pop_front(first);
    display(first);
    cout<<endl<<endl;
    pop_back(back);
    display(first);
    cout<<endl<<isempty(first);
    cout<<endl<<isempty(back);
    cout<<endl<<size(first);
    cout<<endl<<show_front(first);
    cout<<endl<<show_back(back);
    destroy(first);
    return 0;    
}