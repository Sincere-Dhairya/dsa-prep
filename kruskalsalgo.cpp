#include<bits/stdc++.h>

using namespace std;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

vector<int> parent(100), ranking(100, 0);

void initializeparent(int n){
    for(int i = 0; i<n+1; i++) parent[i] = i;
}

int findparent(int u){
    if(parent[u] == u) return u;
    else return findparent(parent[u]);
}

void makeunion(int u, int v){
    u = findparent(u);
    v = findparent(v);

    if(ranking[u] == ranking[v]) {
        parent[v] = u;
        ++ranking[u];
    }
    else if(ranking[u] > ranking[v]){
        parent[v] = u;
    }
    else parent[u] = v;
}

void pushing(int dist, int u, int v){
    pq.push({dist, {u, v}});
}

int kruskalsalgo(){
    int sum = 0;
    while(!pq.empty()){
        pair<int, pair<int, int>> a = pq.top();
        pq.pop();
        int u = a.second.first, v = a.second.second;
        if(findparent(u) != findparent(v)){
            makeunion(u, v);
            sum += a.first;
            //cout<<sum<<endl;
        }
    }
    return sum;
}
int main(){
    int edges = 9;

    pushing(1, 1, 4);
    pushing(2, 1, 2);
    pushing(3, 2, 3);
    pushing(4, 1, 5);
    pushing(3, 2, 3);
    pushing(5, 3, 4);
    pushing(7, 2, 6);
    pushing(8, 3, 6);
    pushing(9, 4, 5);

    initializeparent(edges);

    int first_vertex = pq.top().second.first;

    int sum = kruskalsalgo();
    cout<<first_vertex<<" ";

    for(int i = 0 ;i<edges; i++) 
        if(parent[i] == first_vertex && i != first_vertex) cout<<i<<" ";

    cout<<endl<<sum<<endl;
    return 0;
}