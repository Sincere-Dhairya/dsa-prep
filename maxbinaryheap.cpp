#include<vector>
#include<iostream>

using namespace std;

class MaxHeap{
    public:
    int capacity, size;
    vector<int> arr;
    MaxHeap(int num){
        capacity = num, size= 0, arr = vector<int> (num);
    }
    int getparent(int i) { return (i-1)/2; }
    int ileft (int i) { return 2*i+1; }
    int iright (int i) { return 2*i+2; }
    void insertion(int num){
        if(capacity == size) return;
        ++size;
        int i = size-1;
        arr[i] = num;

        int par = getparent(i);
        while(i != 0 and arr[par] < arr[i]){
            swap(arr[par], arr[i]), i = par;
            if (i == 0) break;
            par = getparent(i);
        }
    }
    int extractmax(){
        int save = arr[0];
        swap(arr[0], arr[size-1]);
        --size;
        heapify(0); 
        return save;
    }
    void heapify(int i){
        int big = i;
        int left = ileft(i), right = iright(i);
        if(left < size && arr[big] < arr[left]) big = left;
        if(right < size && arr[big] < arr[right]) big = right;
        if(big == i) return ;
        swap(arr[big], arr[i]);
        heapify(big);
    }
    void printing(){
        for(int i = 0; i<size; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    void heapsort(){
        while(size){
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
    maxheap->printing();
    maxheap->heapsort();
    return 0;
}