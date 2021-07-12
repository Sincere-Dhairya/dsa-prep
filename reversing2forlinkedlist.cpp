#include<bits/stdc++.h>
#include"linkedlistfunctions.cpp"

using namespace std;

int main()
{
    node * head = NULL;

    pushing(head, 8);
    pushing(head, 1);
    pushing(head, 4);
    pushing(head, 2);
    pushing(head, 5);
    pushing(head, 3);
    pushing(head, 9);
    pushing(head, 6);
    pushing(head, 7);
    pushing(head, 0);

    reversing2(head, 4, 10);
    printing(head);
    deletion(head);
    return 0;
}