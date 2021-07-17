#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node * next;

    node(int data){
        this->data= data;
        this->next = NULL;
    }
};

void pushing(node * &head, int data){
    node * tempnode = new node (data);

    if(head == NULL){
        head = tempnode;
    }

    else{
        node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = tempnode;
    }
}

//for O(n) pushing, we keep on updating the head, but at the same time, 
//we should have a tail node for reading traversal as head will always be pointing to NULL and 
//is being pointed to by the previous node.
void printing(node * head){
    while(head != NULL){
        cout<<"->"<<head->data<<endl;
        head = head->next;
    }
}

void deletion(node * &head){

    while(head != NULL){
        node * temp = head;
        head = head->next;
        delete temp;
    }

    delete head;
}

void reversing_using_stack(node * &head){
    
    stack<int> rev;
    node * temp = head;

    while(temp!= NULL){
        rev.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        temp->data = rev.top();
        rev.pop();
        temp = temp->next;
    }
}

void reversing(node * &head){
    cout<<"Traversed\n";
    node * pvsptr = head, *nxtptr  =head->next;
    pvsptr->next = NULL;

    while(nxtptr != NULL){
        head = nxtptr;
        nxtptr = head->next;
        head->next = pvsptr;
        pvsptr = head;
    }
}
//5      1       9        8       4
//
void recursionrev(node * &pvsptr, node* &head){
    if(head == NULL){
        head = pvsptr;
        return;
    }

    //out<<"->"<<head->data<<endl;
    node* nxtptr = head->next;
    //nxtptr = head->next;
    head->next = pvsptr;
    pvsptr = head;
    head = nxtptr;

    recursionrev(pvsptr, head);
}

int lengthoflist(node * head){
    int count = 0;
    while(head != NULL){
        ++count;
        head = head->next;
    }
    return count;
}

node * ans = NULL;
node * finding(node * head1, node * head2){
    int l1 = lengthoflist(head1), l2 = lengthoflist(head2);

    if(l1 >= l2){
        int diff = l1-l2;

        while(diff != 0){
            --diff;
            head1 = head1->next;
        }
    }
    else{
        int diff = l2-l1;

        while(diff != 0){
            --diff;
            head2 = head2->next;
        }
    }

    while(head1 != head2){
        head1 = head1->next;
        head2 = head2->next;
    }
    ans = head1;
    return ans;
}

/*void reversing2(node * &head, int k, int l){
    int calc = ceil(l/k);
    vector<stack<int>> united(calc);
    
    node * temp = head;
    int x = 0;
    for(int i =0; i < l; i++){
        if(i%k == 0) ++x;
        united[x].push(temp->data);
        cout<<"Pushed into stack!\n"
        temp = temp->next;
    }

    temp = head;

    int flag =  0, y = united.size();

    while(flag != 1){
        for(int i =0; i<y; i++){
            for( int j = 0; j<united[i].size(); j++){
                if(temp == NULL){
                    flag = 1;
                    break;
                }
                temp->data = united[i].top();
                united[i].pop();
                temp = temp->next;
            }
        }
    }
}
*/
node * traversal = new node(NULL);
node * reversing_list(node * &head, int k){
    node * pvsptr = nullptr;
    node * nxtptr = head->next;
    head->next = pvsptr;
    pvsptr = head;

    node * store1 = head;
    int count = 1;

    while(count != k){
        if(nxtptr == NULL) return head;

        head = nxtptr;
        nxtptr = nxtptr->next;
        head->next = pvsptr;
        pvsptr = head;
        ++count;
    }
    if (nxtptr != NULL){
        head = nxtptr;
        store1->next = reversing_list(head, k);
    }

    traversal = pvsptr;

    return traversal;
}