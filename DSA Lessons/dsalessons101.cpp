#include<bits/stdc++.h>

/*
stack
find
size
begin end
auto
iterator

map, unordered map, set unordered set, pair, 
*/

using namespace std;
#define var 1e10
int main(){
    //cout<<sizeof(var)<<" "<<typeid(var).name()<< endl;
    vector<int> v1 (3, 0);
    v1[0] = 10, v1[1] = 20, v1[2] = 30;
    //iterator -> pointer -> memory location.
    vector<int>  :: iterator i = v1.begin();
    cout<<*i<<endl;
    vector<int> :: iterator j = v1.end()-1;
    --j;
    cout<<*j<<endl;
    auto itr = find(v1.begin(), v1.end(), 20)-v1.begin();
    cout<<itr<<endl;
    return 0;
}