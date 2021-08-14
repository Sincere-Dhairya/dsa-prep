#include<bits/stdc++.h>

using namespace std;

map<int, vector<int>> graph;

map<int, bool> status;
map<int, bool> bfsstack;

void addedge(int u, int v){
    graph[u].push_back(v);
    status[u] = status[v] = bfsstack[u] = bfsstack[v] = false;
}

bool cyclebydfs = false;

void dfs_check(int parent){
    status[parent] = bfsstack[parent] = true;

    for(int i =0 ; i<graph[parent].size(); i++){
        int temp = graph[parent][i];
        if(bfsstack[temp] == 1) {
            cout<<"Cycle Found!\n";

            break;
        }
        if(status[temp] == 0){
            status[temp] = bfsstack[temp] = 1;
            dfs_check(temp);
            bfsstack[temp] = 0;
        }
    }
}

void printstack(stack<int> order){
    while(!order.empty()){
        cout<<order.top()<<" ";
        order.pop();
    }
}
int main(){
    addedge(1,2);
    addedge(2,3);
    addedge(3,4);
    addedge(3,8);
    addedge(4,5);
    addedge(8,7);
    addedge(5,6);
    addedge(6,7);
    addedge(5,9);
    addedge(9,10);
    //addedge(10,4);
    dfs_check(1);
    //printstack(order);
}