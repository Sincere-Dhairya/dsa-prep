#include<bits/stdc++.h>

using namespace std;

/**
 * @brief nth_element() STL function usage
 * 
 * @return int 
 * 
 * The nth_element() function accepts 3 iterators commonly, and optionally, the custom compare function
 * it uses quick select and median of medians algorithm to give.
 * 3 iterators are: 1. begin 2. iterator pointing to an index in array 3. end
 * using these iterators, it places the right element in the array at the position pointed by the 
 * second iterator and the elements before it are smaller and elements after it are greater.
 * It's like a step in Quick Sort. -> Quick Select.
 * 
 */
int main(){
    vector<int> arr = {7,6,12,1,5,6,4,3};
    for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;
    nth_element(arr.begin(), arr.begin()+arr.size()/2, arr.end());
    for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;
}