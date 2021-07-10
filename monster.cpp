#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> dist = {4,3,3,3,4}, speed =  {1,1,1,1,4};
    int dists = dist.size(), n, flag = 0;
        
        for(int i =1; i<dists; i++){
            cout<<i<<endl;
            for(int j = i; j < dists; j++){
                cout<<j<<endl;
                dist[j] -= speed[j];
                cout<<dist[j]<<endl<<endl;
                if (dist[j] < 1) {
                    n= i;
                    cout<<"entered: "<<n;
                    flag = 1; 
                    return n;
                }
            }
           
        }
        if( flag ==0)  n = dists;
    
    cout<<n<<endl;
    return n;
}

