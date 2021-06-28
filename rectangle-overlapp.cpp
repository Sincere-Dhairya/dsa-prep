#include<bits/stdc++.h>

using namespace std;

bool overlapp(int x1, int x2, int x3, int x4){
    if((x1 == x3|| x1 == x4)&&(x2==x3 || x2 == x4)) return true;
    else if ((x1 < x3 && x3< x2) || (x3 < x1 && x1< x4)) return true;
    else if ((x1<x4 && x4<x2) || (x3<x2 && x2<x4)) return true;
    else return false;
}

int main()
{
    vector<int> rec1 = {0,0,2,2}, rec2 = {1,1,3,3};
    bool ans = overlapp(rec1[0], rec1[2], rec2[0], rec2[2])&&overlapp(rec1[1], rec1[3], rec2[1], rec2[3]);
    cout<<ans;
    return ans;
}