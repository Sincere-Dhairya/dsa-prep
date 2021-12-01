#include<bits/stdc++.h>

using namespace std;

class MinHeap{
  public:
  vector<int> arr;
  int capacity, size;
  MinHeap(int num){
      capacity = num, size = 0;
      arr = vector<int> (num);
  }
  int iparent(int i) { return (i-1)/2; }
  int ileft(int i) { return 2*i + 1; }
  int iright(int i) { return 2*i + 2; }
  void insertion(int num){
    if(capacity == size) return;

    ++size;
    arr[size-1] = num;
    insertionsupport(size-1);
  }
  void insertionsupport(int i){
    int par = iparent(i);
    if(arr[par] > arr[i]){
      swap(arr[par], arr[i]);
      if(par != 0)
        insertionsupport(par);
    }
  }
  int front() { return arr[0]; }
  int extractmin(){
    int minimum_element = arr[0];
    swap(arr[0], arr[size-1]);
    --size;
    heapify(0);
    return minimum_element;
  }
  void heapify(int i){
    int small = i;
    int l = ileft(i), r = iright(i);
    if(l < size && arr[small] > arr[l])
      small = l;
    if(r < size && arr[small] > arr[r])
      small = r;
    
    if(small == i) return;
    swap(arr[small], arr[i]);
    heapify(small);
    return;
  }
  void heapsort(){
    while(size){
      cout<<extractmin()<<" ";
    }
    cout<<endl;
  }
  void printing(){
    for(int i =0; i<size; i++)
      cout<<arr[i]<<" ";
    cout<<endl;
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
    cout<<minheap->front()<<endl;
    minheap->printing();
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