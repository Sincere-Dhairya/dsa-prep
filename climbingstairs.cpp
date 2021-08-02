//https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb-stairs-with-variable-jumps-official/ojquestion
// Questions are taken from here.

#include<bits/stdc++.h>

using namespace std;

int countingstairs(int n, vector<int> v){
    if(n<0) return 0;
    if(v[n] != 0) return v[n];
    if( n == 0) {
        v[n] = 1;
        return 1;
    }
    int sum = countingstairs(n-3, v) + countingstairs(n-2, v) + countingstairs(n-1, v);
    v[n] = sum;
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n+1, 0);

    cout<<countingstairs(n, v);
}