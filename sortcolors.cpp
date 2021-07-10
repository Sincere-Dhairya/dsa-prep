#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {0,0};//{2,0,2,1,1,0};//{2, 7, 9, 1, 3, 5};//
    int n = nums.size();
    /*int rno = 0, wno = 0, bno = 0;
    for ( int i = 0; i<n; i++){
        if(nums[i] == 0) ++rno;
        else if(nums[i] == 1) ++wno;
        else ++bno;
    }
    int i = 0;
    while( i <rno){
        nums[i] = 0;
        ++i;
    }
    while( i <rno + wno){
        nums[i] = 1;
        ++i;
    }
    while( i <rno + wno + bno){
        nums[i] = 2;
        ++i;
    }*/
    // Selection Sort
    /*
    for(int i = 0; i < n; i++){
        //small = nums[i];
        for (int j=i+1; j<n; j++){
            if(nums[i] > nums[j]) swap(nums[i], nums[j]);
        }
    }*/
    //Bubble Sort
    /*for(int i = 0; i<n ; i++){
        for( int j = 0; j<n-1; j++){
            if(nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
        }
    }   */
    //insertion sort
    /*for(int i = 0; i< n; i++){
        for( int j = i; j>0; j--){
            if(nums[j]<nums[j-1]) swap(nums[j], nums[j-1]);
        }
    }*/
    int j =0, i =0;
        if(nums.size() == 1) return 0;
        while(j < nums.size()){
            if(nums[j] <2){
                swap(nums[i], nums[j]);
                ++i; ++j;
            }        
            
            if(nums[j] == 2){
                ++j;
            }
        }
        
        i = 0; j = 0;
        while(j < nums.size()){
            if(nums[j] == 1) ++j;
            else if(nums[j] == 2) break;
            else{
                swap(nums[i], nums[j]);
                ++j;
                ++i;
            }
        }
    
    cout<<'[';
    for(int i = 0; i<n; i++){
        cout<<nums[i];
        if(i != n-1) cout<<',';
    }
    cout<<']'<<endl;
}