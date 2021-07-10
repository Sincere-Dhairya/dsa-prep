//Count Good Numbers
#include<bits/stdc++.h>

#define mod 1000000007
using namespace std;

int power( int x, int y){
    if (y == 0) return 1;

    int ans = power( x, y/2);
    ans *= ans;
    ans %= mod;

    if(y%2) ans*=x;
    ans%=mod;
    return mod;
}
int main()
{
    //odd index = 2,3,5,7
    //even ind = 0,2,4,6,8
    
    //brute force
    long long n=1, nos = 1;
    /*for(int i =0; i<n; i++){
        if(i%2 == 0) {
            nos *=5;
            nos %= 1000000007;
        }
        else {
            nos *=4;
            nos %= 1000000007;
        }
    }

    long long ans;

    //using pow method.
    if( n%2 == 0){
        ans = pow(5, n/2 ) * pow(4, n/2);
        ans %= 1000000007;
    }
    else{
        ans = pow(5, n/2 +1) * pow(4, n/2);
        ans %= 1000000007;
    }
*/
    long long ans;
    ans= power(5, n/2 + n%2) * power(4, n/2);
    ans%=mod;
    cout<<ans<<endl;
    //long long temp = (nos %(1000000007));
    return 0;
}