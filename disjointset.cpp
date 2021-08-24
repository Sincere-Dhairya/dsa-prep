#include<bits/stdc++.h>

using namespace std;

vector<int> parent(100), ranking(100, 0);

void makeset(int n){
    for(int i =0 ;i<n; i++){
        parent[i] = i;
        ranking[i] = 0;
    }
}

int findparent(int a){
    if(parent[a] == a) return a;
    else return parent[a] = findparent(parent[a]);
}

void unionset(int u, int v){
    u = findparent(u);
    v = findparent(v);

    if(ranking[u] == ranking[v]){
        parent[v] = u;
        ++ranking[u];
    }
    else if(ranking[u] > ranking[v]) parent[v] = u;
    else parent[u] = v;
}

int main(){
    int V = 20;
    makeset(V);
    unionset(1, 2);
    unionset(1, 3);
    unionset(3, 4);
    unionset(5, 6);
    unionset(6, 7);
    unionset(3, 8);
    unionset(1, 2);
    unionset(1, 8);
    unionset(2, 6); 

    if(findparent(2) != findparent(5)) cout<<"Diff COmp!"<<endl;
    else cout<<"Same Comp!"<<endl;
    return 0;
}