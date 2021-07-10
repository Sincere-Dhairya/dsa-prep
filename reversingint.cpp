#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x  = 123, n=0;
    bool negative;
    if (x<0) negative = 1;
    x = abs(x);

    while(x != 0){
        cout<<n<<endl;
        n += x%10;
        n *= 10;
        if (n <= INT_MIN || n >= INT_MAX) return 0;
        x /= 10;
    }
    n = n/10;

    if(negative == 1) n*= (-1);

    cout<<n<<INT_MIN<<" "<<INT_MAX<<"\n";
    return 0;
}