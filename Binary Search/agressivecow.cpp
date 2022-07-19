//agressive cow problem.
// Variable Binary Search is used.

#include<bits/stdc++.h>

using namespace std;

bool placingcow(vector<int> & arr, int mid, int cow, int & ans);
int main()
{
    vector<int> arr = {1, 5, 9, 11};
    int cow_no = 3, ans = -1;

    //int sum = accumulate(arr.begin(), arr.end(), 0);
    int low = 0, high = 8, mid;

    while(low<=high){
        mid = (high+low)/2;
        cout<<mid<<": is mid\n";
        bool key = placingcow(arr, mid, cow_no, ans);
        cout<<ans<<endl;
        if (key){
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
        cout<<"ans is : "<<ans<<endl;
    }

}

bool placingcow(vector<int> & arr, int mid, int cow, int & ans)
{
    int count = 0;
    for(int i = 0; i<arr.size()-1; i++){
        count = 1; cout<<"for arr["<<i<<"] = "<<arr[i]<<endl<<endl;
        int j =i, k = j;
        while(k<arr.size()){
            if((arr[k] - arr[j]) >= mid){
                ++count;
                j = k;
                if(count == cow){
                    cout<<"\nCount  = Cowno"<<endl;
                    ans = mid;
                    return true;
                }
            }
            ++k;

        }

    }
    cout<<"Returning...\n";
    return false;
}