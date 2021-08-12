#include<bits/stdc++.h>

using namespace std;

struct graphnode{
    int val;
    bool status;

    graphnode();
};

graphnode::graphnode(){
    status = false;
    cout<<"Status set to False"<<endl;
}

void addedgenew(vector<graphnode> * & graph, int u, int v){
    graphnode node;
    node.val = v;
    graph[u].push_back(node);
}

void addtwoedgenew(vector<graphnode> * & graph, int u, int v){
    graphnode node1;
    node1.val = v;
    graph[u].push_back(node1);
    graphnode node2;
    node2.val = u;
    graph[v].push_back(node2);
}

void printingnew(vector<graphnode> *graph, int v){
    for(int i =0; i<v; i++){
        cout<< i <<" -> ";
        for(int j = 0; j<graph[i].size(); j++){
            cout<<graph[i][j].val<<": ";
        }
        cout<<endl;
    }
}

void bfs(vector<graphnode> * graph, int V){     //time complexity: O()
    vector<bool> status(V, false);
    queue<int> bfsq;
    bfsq.push(0);

    while(!bfsq.empty()){
        int node = bfsq.front();
        status[node] = true;
        for(int i =0; i<graph[node].size(); i++){
            //cout<<graph[node][i].val<<endl;
            if(status[graph[node][i].val] == false ) {
                //cout<<"Pushed"<<endl;
                bfsq.push(graph[node][i].val);
                status[graph[node][i].val] = true;
            }
        }
        cout<<node<<" is visited"<<endl;
        bfsq.pop();
    }
}

void dfs(vector<graphnode> * graph, int x, vector<bool> & status, int V){
    if(status[x]) return;

    cout<<x<<endl;
    status[x] = true;

    for(int i =0; i<graph[x].size(); i++){
        int elem = graph[x][i].val;
        if(status[elem] == false) {
            dfs(graph, elem, status, V);
        }
    }

}

stack<int> topological;

void topologicalsort(vector<graphnode> * & graph, int V, vector<bool> & status, int x){
    
    status[x] = true;
    for(int i = 0; i<graph[x].size(); i++){
        int elem = graph[x][i].val;
        if(status[elem] == false){
            topologicalsort(graph, V, status, elem);
        }
    }
    cout<<x<<endl;
}
//<-----------------------Simple List Functions ------------------------------>

void addtwoedge(vector<int> * graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void addedge(vector<int> *graph, int u, int v){
    graph[u].push_back(v);
}

void printinggraph(vector<int> *graph, int v){
    for(int i =0; i <v; i++){
        cout<< i <<" -> ";
        for(int j = 0; j<graph[i].size(); j++){
            cout<< graph[i][j] <<", ";
        }
        cout<<endl;
    }
}

//<------------ Cycle Detection ------------>
map<int, vector<int> > graph;
map<int, bool> status;

void addedgetograph(int u, int v){
    graph[u].push_back(v);
    status[u] = status [v] = false;
}

void bfscycle(){
    queue<pair<int, int>> Q;
    int begin = graph.begin()->first;
    Q.push({begin, -1});
    status[begin] = true;
    bool flag = 0;
    while(!Q.empty()){
        int cur_child = Q.front().first;
        int parent = Q.front().second;
        for(int i =0 ;i<graph[cur_child].size(); i++){
            int temp = graph[cur_child][i];
            if(temp != parent){
                if(status[temp] == 1){
                    cout<<"Cycle exists";
                    flag = 1;
                    break;
                }
                else{
                    Q.push({temp, cur_child});
                    status[temp] = true;
                }
            }
        }
        Q.pop();
        if(flag) break;
    }
}
bool cycledetected = false;
void dfscycle(int child, int parent){
    
    for(int i = 0; i<graph[child].size(); i++){
        int elem = graph[child][i];
        if(elem != parent){
            if(status[elem] == 1){
                if(cycledetected == 0){
                    printf("Cycle Exists\n");
                    cycledetected = 1;
                }
                break;
            }
            else{
                status[elem] = 1;
                dfscycle(elem, child);
            }
        }
    }
}