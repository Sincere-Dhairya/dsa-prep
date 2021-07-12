#include<bits/stdc++.h>
#include"linkedlistfunctions.cpp"
using namespace std;


int main()
{
    cout<<"Creating Linked List of 5 elements to reverse it in different ways.\n"<<endl;
    node * head = NULL;

    pushing(head, 5);
    pushing(head, 1);
    pushing(head, 9);
    pushing(head, 8);
    pushing(head, 4);

    printing(head);

    cout<<"Reversing using stack method!\n";
    reversing_using_stack(head);
    printing(head);

    cout<<"Reversing using 3 pointer approach!\n";
    reversing(head);
    printing(head);
    node * pvsptr = NULL;
    cout<<"Reversing using recursion!\n";
    recursionrev(pvsptr, head);
    //cout<<pvsptr->data<<" "<<head->data<<endl;
    //head->next = pvsptr;
    printing(head); 
    //printing(head); 

    cout<<"Deleting...";
    deletion(head);
    return 0;
}