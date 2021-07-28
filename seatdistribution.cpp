#include<bits/stdc++.h>

using namespace std;

int counting(vector<vector<bool>> arr){
    int count = 0, n = arr.size()-1, m = arr[0].size()-1;

    for(int i =1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(arr[i][j]) ++count;
        }
    }

    return count-1;
}

void seatalloc(vector<vector<bool>> & arr){
    int n = arr.size()-1, m = arr[0].size()-1;

    for(int i =1; i<n; i++){
        for(int j =1; j<m; j++){
            if(arr[i][j-1] == true || arr[i][j+1] == true || arr[i-1][j] == true || arr[i+1][j] == true ) continue;
            else arr[i][j] = true;
        }
    }
}

void printing(vector<vector<bool>> arr){
    int n = arr.size()-1, m = arr[0].size()-1;
    for(int i =1; i<n; i++){
        for(int j= 1; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n = 4, m=5, p=2, q = 2;
    vector<vector<bool>> seatmatrix(n+2, vector<bool> (m+2, false));
    //p -=1, q -=1;

    seatmatrix[p][q] = true;
    printing(seatmatrix);

    cout<<endl;
    seatalloc(seatmatrix);
    printing(seatmatrix);
    cout<<endl;

    int count = counting(seatmatrix);
    cout<<count;
    return count;
}