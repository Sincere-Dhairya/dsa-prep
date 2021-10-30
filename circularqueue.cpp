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
    if(this->back == -1) this->front = this->back = 0, this->arr[back] = num;
    else if((this->back +1)%(this->msize) == this->front){
        cout<<"Queue Overflow!"<<endl;
        return;
    }
    else{
        if(this->back == this->msize-1) this->back = 0;
        else      
            this->arr[++this->back] = num;
    }
}

int Queue :: pop(){
    int save_pop = -1;
    if(this->front == -1) {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    else if(this->front == this->back){
        save_pop = this->arr[front];
        this->front = this->back = -1;
    }
    else if(this->front == this->msize-1){
        save_pop = this->arr[front];
        front = 0;
    }
    else
        save_pop = this->arr[this->front], ++this->front;
    return save_pop;
}

bool Queue :: isempty(){
    if(this->front == -1) return true;
    else return false;
}

int Queue :: size(){
    if(this->front <= this->back) return this->back-this->front+1;
    else return msize - this->front + this->back+1;
}

int Queue :: get_front(){
    if(this->front == -1) return -1;
    return this->arr[front];
}

void Queue :: clear(){
    this->front = this->back = 1;
    this->arr = vector<int>(msize);
}

void Queue :: printing(){
    int b = back, f = front;
    if(b == -1){
        cout<<"Empty Queue!"<<endl;
        return;
    }
    while(b != f){
        cout<<this->arr[f]<<"<-"<<endl;
        if(f == msize-1) f = 0;
        else ++f;
    }
    cout<<this->arr[f]<<"<-"<<endl;
}

int main(){
    Queue * q1 = new Queue(10);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(12);
    q1->push(22);
    q1->push(11);
    q1->push(67);
    q1->printing();
    cout<<endl;
    q1->push(55);
    q1->push(77);
    q1->push(3);
    q1->push(15);
    q1->printing();
    cout<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<endl;
    q1->printing();
    q1->push(2);    
    q1->push(4);    
    q1->push(6);    
    q1->push(8);
    cout<<endl;
    q1->printing();
    cout<<q1->get_front()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    cout<<"Element removed : "<<q1->pop()<<endl;
    q1->printing();
    return 0;    
}