//List: 1. Pigeon Hole Principle.
//2. Inclusion Principle.
//3. Euler Totient ( counting dearrangements)
//4. Modular Arithmetic ( Eulers totient, exponentiation, modular multiplicative inverse)
//5. Permutations and COmbinations
//6. Game theory and geometry

#include<bits/stdc++.h>

#define mod 100000

using namespace std;

int power(int x, int y){
    if(y == 0) return 1;
    
    int prod = power(x, y/2);
    prod*= prod;
    prod %= mod;
    if(y%2) prod *= x;
    prod %= mod;
    return prod;
}

int fibonacci(int n){
    if (n <=1) return 1;
    else {
        int sum = fibonacci(n-1) + fibonacci(n-2);
        return sum;
    }
}

int main()
{
    long long  x  = power(2, 10);
    cout<<x<<endl;
    //cout<<"Hello "<<x<<"  "<<endl<<INT_MAX<<" "<<INT_MAX+1;
    cout<<fibonacci(5-2)<<endl;

    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);

    for(int i =2; i<5; i++){
        fibo.push_back(fibo[i-1] + fibo[i-2]);
    }

    cout<<fibo[4]<<endl;
    cout<<power(9,3);
    return 0;
}