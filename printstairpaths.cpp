#include<bits/stdc++.h>

using namespace std;

void printingstairs(int n, string s1){
    if(n<0) return;

    else if (n == 0) {
        cout<<s1<<endl;
        return;
    }

    printingstairs(n-1, s1+"1");
    printingstairs(n-2, s1+"2");
    printingstairs(n-3, s1+"3");
}

int main(){
    int n;
    cin>>n;

    printingstairs(n, "");

}