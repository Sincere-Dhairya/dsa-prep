#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node * front, * back;
    Node(int );
};

Node::Node(int data){
    this->val = data;
    front = back = nullptr;
}

class Deque{
    public: 
    int size;
    Node* head, *tail;
    Deque();
    void pushFront(int);
    void popFront();
    void pushBack(int);
    void popBack();
    int getSize();
    bool isEmpty();
};

Deque::Deque(){
    size = 0;
    head = tail = nullptr;
}

void Deque::pushFront(int val){
    if(!head){
        head = new Node(val);
        tail = head;
        ++size;
        return ;
    }
    
    head->front = new Node(val);
    head->front->back =head;
    head = head->front;
    ++size;
    return ;
}

void Deque::popFront(){
    if(isEmpty()){
        cout<<"Deque is empty! " << endl;
        return ;
    }
    Node* pvsNode = head;
    if(head == tail){
        head = tail = nullptr;
        size = 0;
    }
    else {
        head = head->back;
        --size;
    }
    
    cout << "Deleted node is: " << pvsNode->val << endl;
    delete pvsNode;
}

void Deque::pushBack(int val){
    if(!tail){
        head = new Node(val);
        tail = head;
        ++size;
        return ;
    }
    
    tail->back = new Node(val);
    tail->back->front =tail;
    tail = tail->back;
    ++size;
    return ;
}

void Deque::popBack(){
    if(isEmpty()){
        cout<<"Deque is empty! " << endl;
        return ;
    }
    Node * remNode = tail;
    if(head == tail){
        head = tail = nullptr;
        size = 0;
    }
    else {
        tail = tail->front;
        --size;
    }
    
    cout << "Deleted node is: "<< remNode->val << endl;
    delete remNode;
}

int Deque::getSize(){
    return size;
}

bool Deque::isEmpty(){
    return size == 0;
}

int main(){
    Deque *dq = new Deque();
    cout << dq->isEmpty() << endl;
    dq->pushFront(5);
    dq->pushBack(7);
    dq->pushBack(1);
    dq->pushBack(2);
    dq->pushBack(45);
    dq->pushBack(2);
    dq->pushBack(9);
    dq->pushBack(0);
    dq->pushBack(3);
    
    cout << dq->isEmpty() << endl;
    cout << dq->getSize() << endl;
    dq->popFront();
    dq->popBack();
    cout << dq->getSize() << endl;
    dq->popBack();
    cout << dq->getSize() << endl;
    dq->popBack();
    cout << dq->getSize() << endl;
    dq->popBack();
    cout << dq->getSize() << endl;
    dq->popBack();
    cout << dq->getSize() << endl;
    dq->popBack();
    cout << dq->getSize() << endl;
    dq->popBack();
    cout << dq->getSize() << endl;
    dq->popBack();
    cout << dq->getSize() << endl;
    dq->popBack();
    cout << dq->getSize() << endl;
    dq->popBack();
    cout << dq->getSize() << endl;
    return 0;
}