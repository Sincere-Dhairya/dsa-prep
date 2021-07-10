#include<bits/stdc++.h>

using namespace std;


class node{
    public:
        static int length;
        int data;
        node * left;
        node* right;
        // node(int d){
        //     this->data = d;
        //     this->right = this->left = NULL;
        // }
};
int node::length = 0;

void pushing(node * &head)
{   
    // if(tempnode == NULL){
    //     cout<<"created!";
    // }
    cout<<"Enter the data: ";
    node * tempnode = new node;
    cin>>tempnode->data;
    tempnode->left = tempnode->right = NULL;
    ++tempnode->length;
    
    if(head == NULL){
        cout<<"Null thi ab nahi";
        head = tempnode;
    }
    else{
        node * temp = head;
        while(temp->right != NULL){
            temp = temp->right;
        }
        tempnode->left = temp; 
        temp->right = tempnode;
    }

}

int find_element_by_recursion(node * head, int n){
    if(head == NULL) return head->length;
    if(head->data == n) return 1;
    else {
        return 1 + find_element_by_recursion(head->right, n);
    }
}

void popping(node * head){
    node * temp = head;
    while(temp->right != NULL){
        temp = temp->right;
    }
    node * temp2 = temp->left;
    temp2->right = NULL;
    --temp2->length;
    delete temp;
}

void popping2(node * &head){
    cout<<"Enter the num that is to be popped: ";
    int n;
    cin>>n;
    node * temp1 = head;
    --temp1->length;
    while(temp1 != NULL){
        if(temp1->data == n) break;
        temp1 = temp1->right;
    }

    if (temp1 == NULL) cout<<"Not Found!"<<endl;
    else if(temp1->left == NULL){
        head = head->right;
        head->left = NULL;
        delete temp1;
    }
    else{
        node * temp = temp1;
        temp = temp->left;
        temp->right = temp1->right;
        delete temp1;
        cout<<"Deleted!\n";
    }
}

void reading(node * head){
    node * temp = head;
    while(temp != NULL){
        cout<<"-> "<<temp->data<<endl;
        temp = temp->right;
    }
}

void deleting(node * &head){
    while(head != NULL){
        node * temp = head;
        head = head->right;
        delete temp;
    }
    delete head;
    cout<<"Everything deleted!\n";
}

int findlength(node * head){
    if(head == NULL) return 0;
    return 1 + findlength(head->right);    
}

void middle(node * head){
    node * temp1 = head;
    node * temp2 = head;
    while(temp2 != NULL){
        temp2 = temp2->right;
        if(temp2 != NULL) {
            temp2 = temp2->right;
            temp1 = temp1->right;
        }
    }
    cout<<temp1->data<<" is in middle r n!"<<endl;
}



int main()
{
    node * head = NULL;
    pushing(head);
    pushing(head);
    pushing(head);
    pushing(head);
    pushing(head);
    pushing(head);
    pushing(head);
    pushing(head);
    pushing(head);
    pushing(head);
    reading(head);
    cout<<"Popping..."<<endl;
    //popping(head);
    reading(head);
    //popping2(head);
    reading(head);
    int l = findlength(head);
    cout<<"Length is: "<<l<<endl;
    cout<<"ENter the element to find it: ";
    int n ; cin>>n;
    int k = find_element_by_recursion(head, n);
    if(k > head->length+1) cout<<"not present!"<<endl;
    else cout<<"Present at position: "<<k<<endl;
    middle(head);
    deleting(head);
}
/*
int main()
{
    node * head = NULL;
    //cout<<head->data<<endl;
    if(head == NULL){
        cout<<"Hai to sahi!"<< sizeof(head)<<endl;
    }
    //head->left = head->right = NULL;
    int choice;
    do{
        cout<<"Creating linked list >"<<endl;
        cout<<"Enter the choices"<<endl;
        cout<<"1. Push 2. Pop 3. Read 4. Exit:  ";
        cin>>choice;
        switch(choice){
            case 1: {pushing(head); break;}
            case 2: popping(head); break;
            case 3: reading(head); break;
            case 4: exit(0); break;
            default: cout<<"Wrong Input!\n";
        }
    } while(choice != 4);
    return 0;
}
*/