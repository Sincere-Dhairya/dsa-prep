#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node(int v){
        val = v, next = nullptr;
    }
    Node(int v, Node * node){
        val = v, next= node;
    }
};

// Insertion function
void insertion(Node *& head, int val){
    auto trav = head;
    while(head->next)
        head = head->next;

    head->next = new Node(val);
    head = trav;
}

// Sorting starts
void sorting(Node * &head){
    vector<Node *> arr;
    Node * trav = head;
    while(trav){
        arr.push_back(trav);
        trav = trav->next;
    }
    sort(arr.begin(), arr.end(), [](Node * & a, Node * & b){ return a->val<b->val; });
    head = arr.front();
    trav = head;
    
    int n = arr.end() - arr.begin();
    cout<<n<<endl;
    for(int i = 1; i<n; i++){
        trav->next = arr[i];
        trav = trav->next;
    }
}

// Printing function.
void printing(Node * head){
    while(head)
        cout<<head->val<<" ",
        head = head->next;
}

// Main function starts
int main(){
    Node * head = new Node(5);
    insertion(head, 6);
    insertion(head, 1);
    insertion(head, 2);
    insertion(head, 0);
    insertion(head, 8);
    insertion(head, 5);
    insertion(head, 11);
    insertion(head, 20);
    sorting(head);
    printing(head);
    return 0;
}