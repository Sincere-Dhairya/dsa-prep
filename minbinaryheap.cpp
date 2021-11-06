/*
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
*/
#include<bits/stdc++.h>

using namespace std;

class MinHeap{
    int capacity;
    int heapsize;
    vector<int> arr;
    public:
    MinHeap(int cap){
        capacity = cap;
        arr= vector<int>(cap, INT_MAX);
        heapsize = 0;
    }
    int fparent(int i) { return (i-1)/2; }
    int fleft(int i) { return 2*i + 1; }
    int fright(int i) { return 2*i + 2; }
    void insertion(int val){
        if(heapsize == capacity){
            cout<<"Overflow!"<<endl;
            return;
        }

        ++heapsize;
        arr[heapsize-1] = val;
        int i = heapsize-1;
        int par = fparent(i);
        while(i > 0 && arr[par] > arr[i]){
            swap(arr[i], arr[par]);
            i = par;
            par = fparent(i);
        }
    }
    int extractmin(){
        if(heapsize == 0){
            cout<<"Underflow!"<<endl;
            return -1;
        }
        int ans = arr.front();
        --heapsize;
        swap(arr[0], arr[heapsize]);
        heapify(0);
        return ans;
    }
    void heapify(int i){
        int l = fleft(i);
        int r = fright(i);
        int smallest = i;
        
        if(l <heapsize && arr[smallest] > arr[l]) smallest = l;
        if(r < heapsize && arr[smallest] > arr[r]) smallest = r;
        
        if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(smallest);
        }
    }
    void heapsort(){
        cout<<"heapsize is "<<heapsize<<endl;
        for(int i = 0; i<heapsize; i++){
            cout<<extractmin()<<" ";
        }
    }
};

int main(){
    MinHeap * minheap = new MinHeap(10);
    minheap->insertion(20);
    minheap->insertion(3);
    minheap->insertion(10);
    minheap->insertion(9);
    minheap->insertion(7);
    minheap->insertion(11);
    minheap->insertion(15);
    minheap->insertion(21);
    minheap->heapsort();
    // MinHeap minheap(10);
    // minheap.insertion(20);
    // minheap.insertion(3);
    // minheap.insertion(10);
    // minheap.insertion(9);
    // minheap.insertion(7);
    // minheap.insertion(11);
    // minheap.insertion(15);
    // minheap.insertion(21);
    // minheap.heapsort();
    delete minheap;
    return 0;
}
/*
Working code...
#include<bits/stdc++.h>

using namespace std;

class minheap{
    public:
  vector<int> arr;
  int capacity;
  int heapsize;
  
  minheap(int limit){
    capacity = limit;
    heapsize = 0;
    arr = vector<int>(limit);
  }
  
  int fparent(int i){ return (i-1)/2; }
  int fleft(int i ){ return 2*i+1; }
  int fright(int i){ return 2*i+2; }
  
  void inserting(int elem){
    if(heapsize == capacity){
      cout<<"Overflow!"<<endl;
      return;
    }
    
    ++heapsize;
    arr[heapsize-1] = elem;
    int i = heapsize-1;
    int par = fparent(i);
    while(i>0 && arr[i]<arr[par]){
      swap(arr[i], arr[par]);
      i = par;
      par = fparent(i);
    }
  }
  
  int extractmin(){
    if(heapsize == 0){
      cout<<"Underflow!";
      return -1;
    }
    int minelem = arr.front();
    --heapsize;
    swap(arr[0], arr[heapsize]);
    
    heapify(0);
    return minelem;
  }
  
  void heapify(int i){
    int l = fleft(i);
    int r = fright(i);
    int smallest = i;
    
    if(l <heapsize && arr[smallest] > arr[l]) smallest = l;
    if(r < heapsize && arr[smallest] > arr[r]) smallest = r;
    
    if(smallest != i){
      swap(arr[i], arr[smallest]);
      heapify(smallest);
    }
  }
  
  void heapsort(){
    int len = heapsize;
    for(int i = 0; i< len; i++){
      cout<<extractmin()<<" ";
    }
  }
};

int main(){
    minheap h1(11);
    h1.inserting(20);
    h1.inserting(3);
    h1.inserting(10);
    h1.inserting(9);
    h1.inserting(7);
    h1.inserting(11);
    h1.inserting(15);
    h1.inserting(21);
    //h1.inserting(90);
    //h1.inserting(100);
    //h1.extractmin();
    //h1.printing();
    h1.heapsort();
}*/