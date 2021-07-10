//Magic of Square

#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> A_i = {1,2,3}; 
    int N = 3;

    vector<int> subarrsums, squaredsum;

    subarrsums.push_back(A_i[0]);
    squaredsum.push_back(A_i[0]*A_i[0]);

    for(int i =1;i<N; i++){
        subarrsums.push_back(max(A_i[i], A_i[i]+subarrsums[i-1]));
        squaredsum.push_back(max(A_i[i]*A_i[i], A_i[i]*A_i[i]+subarrsums[i-1]));
    }

    for(int i =0; i< N; i++){
        cout<<"subarr: "<<subarrsums[i]<<"  "<<"squaredsum: "<<squaredsum[i]<<endl;
    }

    int n = *max_element(squaredsum.begin(),squaredsum.end());
    cout<<n;
    //cout<<INT_MAX*INT_MAX<<endl;
}