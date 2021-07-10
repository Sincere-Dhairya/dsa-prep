/* Lower bound of a number is the lower index in the array containing multiple elements. */

#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr= {1, 3, 3, 5, 5, 7, 7, 7, 7, 8, 8, 8, 9};

    
    int low = 0, high = arr.size()-1, mid;

    int x= 8;

    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] > x) high = mid-1;
        else if(arr[mid] < x) low = mid+1;
        else{
            while(arr[mid] == x){
                --mid;
            }
            break;
        }
    }

    cout<<"The lower bound of number is : "<<mid + 1<<endl;
}