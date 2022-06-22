#include<bits/stdc++.h>

using namespace std;

int main(){
    string A="kimona", B = "", C = "";
    int i = 0, j = -1, k = -1;
    while(i < A.length()){
        while(B.empty() || B[j] >= A[i]){
            B.push_back(A[i++]);
            ++j;
        }
        
        reverse(B.begin(), B.end());
        C += B;
        B = "";
        j = -1;
    }
    cout<<"string output " << C<<endl;
    return 0;
}