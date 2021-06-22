#include<bits/stdc++.h>

using namespace std;

int distrib(vector<int> & arr, int mid, int k, int & ans)
{
    int check = 0, sum = 0;
    for (int i =0; i<arr.size(); i++){
        if ( sum + arr[i] <= mid && check < k){
            sum += arr[i];
            cout<<"upper for"<<sum<<endl;
        }

        else if ( sum + arr[i] > mid && check < k){
            ++check;
            sum = arr[i];
            cout<<"CHECK: "<<check<<"  lower for"<<sum<<" "<<endl;
            if (mid < arr[i]) return 1;

        }

        if(check == k) {
            cout<<"Shifting towards more time than "<<mid<<endl<<endl;
            return 1;
        }
    }
    
    ans = mid;
    cout<<"ans in this iteration is: "<<ans<<endl<<endl;
    return 0;
    
}
int main()
{
    int n;
    cout<<"Enter the number of boards: ";
    n = 6;

    vector<int> boards = { 658, 786, 531, 47, 169, 397, 914 };

    // for (int i = 0; i<n ; i++){
    //     boards.push_back(10*(i+1));
    // }

    int high = accumulate(boards.begin(), boards.end(), 0), low = 786, mid, ans = -1; 
    int k=5;
    cout<<"Enter the number of painters: "<<endl;
    while(high >= low){
        mid = (high + low )/2;
        int side = distrib(boards, mid, k, ans);
        
        if ( side == 0){
            high = mid-1;
        }

        else if(side == 1){
            low = mid+1;
        }
    }
    cout<<"the min time is: "<<ans<<endl;
    return 0;
}