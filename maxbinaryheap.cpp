#include<bits/stdc++.h>

using namespace std;

void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class maxheap {
    //vector<int> arr;
    int * arr;
    int capacity;
    int heapsize;
    
    public:
    
    maxheap(int cap);
    
    int parent(int i ){ return (i-1)/2;}

    int left(int i){ return 2*i+1; }
    
    int right(int i ) { return 2*i+2; }
    
    int getmax() { return arr[0]; }
    
    void inserting(int key);
    
    void extractmax();
    
    void heapify(int i);
    
    void printing();
    
    void heapsort();
};

maxheap::maxheap(int cap){
    int capacity = cap;
    int heapsize = 0;
    arr = new int[cap];
    //vector<int> arr(cap);
    cout<<"run"<<endl;
}

void maxheap::inserting(int key){
    cout<<"Insertion\n";
    if(heapsize == capacity) {
        cout<<"Heap overflow!\n";
        return;
    }
    ++heapsize;
    arr[heapsize-1] = key;
    
    if(heapsize != 1){
        int i = heapsize-1;
        int par = parent(i);
        
        while(i != 0 && arr[par]<arr[i]){
            swap(arr[par], arr[i]);
            i = par;
            par = parent(i);
        }
    }
    cout<<"Insertion for "<<key<<" completed!\n"<<endl;
}

void maxheap::extractmax(){

    if(!heapsize) {
        cout<<"Heap Underflow!\n"; 
        return;
    }
    //cout<<"Pass1"<<endl;
    int temp = arr[0];

    --heapsize;
    //cout<<"Pass2"<<endl;
    swap(arr[0], arr[heapsize]);
    //cout<<"Pass3"<<endl;
    heapify(0);
    cout<<temp<<" ";
}

void maxheap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    //cout<<"Pass4"<<endl;
    if(l < heapsize && arr[l]>arr[i]) largest = l;
    
    if(r < heapsize && arr[r]>arr[largest]) largest = r;
    //cout<<smallest<<" is smallest\n";
    //cout<<"Pass5"<<endl;
    if( largest != i){
        swap(arr[largest], arr[i]);
        heapify(largest);
    }
    
}

void maxheap::printing(){
    for(int i =0; i<heapsize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void maxheap::heapsort(){
    int length = heapsize;
    for(int i = 0; i<length; i++){
        extractmax();
    }
}

int main(){
    maxheap h1(11);
    h1.inserting(10);
    h1.inserting(20);
    h1.inserting(30);
    h1.inserting(40);
    h1.inserting(50);
    h1.inserting(60);
    h1.inserting(70);
    h1.inserting(80);
    h1.inserting(90);
    h1.inserting(100);
    h1.extractmax();
    h1.printing();
    h1.heapsort();
}
