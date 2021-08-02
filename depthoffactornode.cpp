#include<bits/stdc++.h>

using namespace std;

// complexity: O(sqrt(n)).
bool checkprime(int n){
    bool flag = 0;
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag) {
        //cout<<n<<" is not a prime!\n";
        return false;
    }
    else {
        //cout<<n<<" is a prime\n"; 
        return true;
    }
}

// complexity: O(sqrt(n)).
set<int> factors(int n){
    set<int> list;

    for(int i =2; i<=sqrt(n); i++){
        if(n%i == 0){
            list.insert(i);
            //cout<<i<<" inserted!"<<endl;
            list.insert(n/i);
            //cout<<n/i<<" inserted!"<<endl;
        }
    }
    return list;
}

int main(){
    int n;
    //cout<<"Enter the root node: ";
    cin>>n;

    if(checkprime(n)) {
        //cout<<"prime hai"<<endl;
        return 0;
    }

    int count = 0;

    while(checkprime(n)==0){        //O(n)* sqrt(n)          O (n^(3/2)).
        set<int> list = factors(n); // O(sqrt n).
        //cout<<"'";
        auto itr = list.end();
        //cout<<*itr;
        --itr;
        //cout<<*itr<<endl;
        
        while(checkprime(*itr) && itr != list.begin()) --itr; // O(sqrt n )
        ++count;
        n = *itr;
    }
    cout<<count;
    return count;
}