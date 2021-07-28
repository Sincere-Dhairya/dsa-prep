#include<bits/stdc++.h>

using namespace std;

void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class minheap {
    //vector<int> arr;
    int * arr;
    int capacity;
    int heapsize;
    
    public:
    
    minheap(int cap);
    
    int parent(int i ){ return (i-1)/2;}

    int left(int i){ return 2*i+1; }
    
    int right(int i ) { return 2*i+2; }
    
    int getmin() { return arr[0]; }
    
    void inserting(int key);
    
    void extractmin();
    
    void heapify(int i);
    
    void printing();
    
    void heapsort();
};

minheap::minheap(int cap){
    int capacity = cap;
    int heapsize = 0;
    arr = new int[cap];
    //vector<int> arr(cap);
    cout<<"run"<<endl;
}

void minheap::inserting(int key){
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
        
        while(i != 0 && arr[par]>arr[i]){
            swap(arr[par], arr[i]);
            i = par;
            par = parent(i);
        }
    }
    cout<<"Insertion for "<<key<<" completed!\n"<<endl;
}

void minheap::extractmin(){

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

void minheap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    //cout<<"Pass4"<<endl;
    if(l < heapsize && arr[l]<arr[i]) smallest = l;
    
    if(r < heapsize && arr[r]<arr[smallest]) smallest = r;
    //cout<<smallest<<" is smallest\n";
    //cout<<"Pass5"<<endl;
    if( smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(smallest);
    }
    
}

void minheap::printing(){
    for(int i =0; i<heapsize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void minheap::heapsort(){
    int length = heapsize;
    for(int i = 0; i<length; i++){
        extractmin();
    }
}

int main(){
    minheap h1(11);
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
    h1.extractmin();
    h1.printing();
    h1.heapsort();
}
