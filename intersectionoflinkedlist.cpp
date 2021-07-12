#include<bits/stdc++.h>

#include"linkedlistfunctions.cpp"

using namespace std;


int main(void)
{
    //cout<<"Creating Linked List of 5 elements to reverse it in different ways.\n"<<endl;
    node * head = NULL;

    pushing(head, 5);
    pushing(head, 1);
    pushing(head, 9);

    pushing(head, 8);
    pushing(head, 4);
    node * store = head->next->next;
    cout<<store->data<<"<- is the store data.\n";
    printing(head);

    node * head2 = NULL;
    pushing(head2, 11);
    pushing(head2, 9);
    pushing(head2, 7);
    pushing(head2, 4);
    pushing(head2, 2);

    node * temp = head2;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = store;
    cout<<endl;
    //printing(head);
    printing(head2);

    node * intersection = finding(head, head2);

    cout<<"the nodes intersect at : "<<intersection->data<<endl;
    //----------------------------------------------
    deletion(head);
    delete store, temp, intersection;
    //deletion(head2);
    return 0;
}