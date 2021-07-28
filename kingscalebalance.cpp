#include<bits/stdc++.h>

using namespace std;

int dectobin(int n){
    vector<int> store;
    int i =0;
    while(n!= 0){
        int temp = n%2;
        store.push_back(temp);
        store[i++];
        n/=2;
    }

    int length = store.size();
    
    int sum = 0;

    for(int i = length-1; i>=0 ;i--){
        sum += store[i];
        sum *= 10;
    }
    sum /= 10;
    
    return sum;
}

void print_sol(int n , int (*a)[2]){
    map<int, int> list;
    int maxim;
    for(int i=n-1; i>= 0; i--){
        if(a[i][0] > 0) a[i][0] = list[a[i][0]];
        if(a[i][1] > 0) a[i][1] = list[a[i][1]];

        if(a[i][0] < 0 && a[i][1] < 0){
            maxim = max(abs(a[i][0]), abs(a[i][1]));
            maxim *= -2;
            list[i+1] = maxim;
        }
    }

    int final_sum = list.begin()->second;
    final_sum *= -1;

    int ans = dectobin(final_sum);
    cout<<ans<<endl;
}

int main(){
    int a[4][2] = { {2, 3}, {-10, 4}, {-5, -11}, {-3, -6}};
    print_sol(4, a);
    return 0;
}