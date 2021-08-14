#include<bits/stdc++.h>

using namespace std;

map<int, vector<int>> graph;

map<int, bool> status;
map<int, bool> bfsstack;

map<int, int> indegrees;

void addedge(int u, int v){
    graph[u].push_back(v);
    status[u] = status[v] = bfsstack[u] = bfsstack[v] = false;
    ++indegrees[v];
}

void topological_by_dfs(int parent, stack<int> & order){
    status[parent] = true;
    for(int i =0; i<graph[parent].size(); i++){
        int temp = graph[parent][i];
        if(!status[temp]){
            topological_by_dfs(temp, order);
        }
    }
    order.push(parent);
}

//below is the Kahn's Algorithm for topological sort by bfs;

void topological_by_bfs(queue<int> & Q, vector<int> & sortorder){
    while(!Q.empty()){
        int parent = Q.front();
        Q.pop();
        sortorder.push_back(parent);

        for(int i =0 ;i < graph[parent].size(); i++){
            int temp = graph[parent][i];
            --indegrees[temp];
            if(indegrees[temp] == 0) Q.push(temp);
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
    indegrees[1] = 0;
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
    addedge(10,4);
    stack<int> order;
    //topological_by_dfs(1, order);
    //printstack(order);
    queue<int> Q;
    Q.push(1);
    vector<int> ans;
    topological_by_bfs(Q, ans);

    cout<<endl;
    for(auto itr:indegrees){
        cout<<itr.first<<" : "<<itr.second<<endl;
        if(itr.second != 0){
            cout<<"Cycle Exists."<<endl;
            break;
        }
    }

    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}