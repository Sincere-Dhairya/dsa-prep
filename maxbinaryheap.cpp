#include<vector>
#include<iostream>

using namespace std;

class MaxHeap{
    int capacity, heapsize;
    vector<int> arr;
    public:
    MaxHeap(int val){
        this->capacity = val, heapsize = 0;
        arr=vector<int>(capacity, INT_MIN);
    }
    int getparent(int i ){ return (i-1)/2; }
    int getleft(int i) { return 2*i +1; }
    int getright(int i) { return 2*i + 2; }
    void insertion(int val){
        if(heapsize == capacity){
            cout<<"Overflow!"<<endl;
            return;
        }
        ++heapsize;
        arr[heapsize-1] = val;
        int i = heapsize-1, par = getparent(i);
        while(i > 0 && arr[par] < arr[i]){
            swap(arr[i], arr[par]);
            i = par;
            par = getparent(i);
        }
    }
    void heapify(int i){
        int largest = i;
        int l = getleft(i), r = getright(i);
        if(l < heapsize && arr[largest] < arr[l]) largest = l;
        if(r < heapsize && arr[r] > arr[largest]) largest = r;
        if(largest == i) return;
        swap(arr[largest], arr[i]);
        heapify(largest);
    }
    int extractmax(){
        if(heapsize==0){
            cout<<"Undeflow!"<<endl;
            return -1;
        }
        int ans = arr.front();
        --heapsize;
        swap(arr[0], arr[heapsize]);
        heapify(0);
        return ans;
    }
    void heapsort(){
        for(int i =0 ;i <= heapsize+1; i++){
            cout<<extractmax()<<" ";
        }
    }
};

int main(){
    MaxHeap * maxheap = new MaxHeap(10);
    maxheap->insertion(20);
    maxheap->insertion(3);
    maxheap->insertion(10);
    maxheap->insertion(9);
    maxheap->insertion(7);
    maxheap->insertion(11);
    maxheap->insertion(15);
    maxheap->insertion(21);
    maxheap->heapsort();
    return 0;
}