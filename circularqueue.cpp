// Cicular Queue
#include<bits/stdc++.h>

using namespace std;

class Queue{
    public:
    int front, back;

    int msize;
    vector<int> arr;
    
    Queue(int size);
    void push(int num);
    int pop();
    bool isempty();
    int size();
    int get_front();
    void clear();
    void printing();
};

Queue :: Queue(int size){
    this->msize = size;
    this->arr = vector<int>(this->msize);
    this->front = this->back = -1;
}

void Queue :: push(int num){
    if((this->back + 1)%this->msize == this->front){
        cout<<"Error: Queue Overflow!"<<endl;
    }
    else {
        if(this->back == this->front == -1) this->front = this->back = 0;
        this->arr[back] = num;
        ++this->back;
        if(this->back == msize && front > 0) this->back = 0;
    }
}

int Queue :: pop(){
    int save_pop = -1;
    if(this->front == this->back){
        cout<<"Error: Queue Underflow!"<<endl;
    }
    else{
        save_pop = this->arr[this->front];
        ++this->front, this->front %= this->msize;
        if(this->front == this->back) this->front = this->back = 0;
    }
    return save_pop;
}

bool Queue :: isempty(){
    if(this->front == this->back) return true;
    else return false;
}

int Queue :: size(){
    if(this->front <= this->back) return this->back-this->front;
    else return msize - this->front + this->back;
}

int Queue :: get_front(){
    if(this->front == this->back) return -2;
    return this->arr[front-1];
}

void Queue :: clear(){
    this->front = 0, this->back = 0;
    this->arr = vector<int>(msize);
}

void Queue :: printing(){
    int b = back, f = front;
    if(b == f) cout<<"Empty Queue!"<<endl;
    while(b != f){
        cout<<this->arr[f-1]<<"<-"<<endl;
        if(f == msize) f = 1;
        else ++f;
    }
}

int main(){
    Queue * q1 = new Queue(10);
    q1->push(2);
    q1->push(3);
    // q1->push(4);
    // q1->push(12);
    // q1->push(22);
    // q1->push(11);
    // q1->push(67);
    q1->printing();
    // cout<<endl;
    // q1->push(55);
    // q1->push(77);
    // q1->push(3);
    // q1->push(15);
    // q1->printing();
    // cout<<endl;
    // cout<<"Element removed : "<<q1->pop()<<endl;
    // cout<<"Element removed : "<<q1->pop()<<endl;
    // cout<<"Element removed : "<<q1->pop()<<endl;
    // cout<<endl;
    // q1->push(2);    
    // q1->push(4);    
    // q1->push(6);    
    // q1->push(8);
    return 0;    
}