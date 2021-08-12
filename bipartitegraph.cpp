#include<bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;

void addedge(int u, int v){
    graph[u].push_back(v);
}

void check_bipartite_by_bfs(vector<int> &colors){
    int child = graph.begin()->first;
    queue<int> Q;
    Q.push(child);
    colors[child] = 0;
    bool flag = 0;
    while(!Q.empty()){
        int parent = Q.front();

        for(int i =0 ;i<graph[parent].size(); i++){
            int temp = graph[parent][i];
            if(colors[temp] == -1){
                colors[temp] = colors[parent]^1;
                Q.push(temp);
            }
            else if(colors[temp] == colors[parent]){
                flag = 1;
                break;
            }
        }
        Q.pop();
        if(flag){
            cout<<"Not Bipartite!\n";
            break;
        }
    }
}

bool dfsflag2 = false;

void check_bipartite_by_dfs(vector<int> & colors, int child, int parent){
    for(int i =0; i<graph[child].size(); i++){
        int temp = graph[child][i];
        if(temp != parent){
            if(dfsflag2) return;
            if(colors[temp] == -1){
                //cout<<temp<<" -> "<<colors[temp]<<" "<<colors[child]^1;
                colors[temp] = colors[child]^1;
                check_bipartite_by_dfs(colors, temp, child);
            }
            else if(colors[temp] == colors[child]){
                dfsflag2 == true;
                cout<<"Not a Bipartite!\n";
                return;
            }
        }
    }
}
int main(){
    int n=8;
    vector<int> coloring(n+1, -1);
    addedge(1,2);
    addedge(2,1);
    addedge(2,3);
    addedge(3,2);
    addedge(2,7);
    addedge(7,2);
    addedge(3,5);
    //addedge(4,3);
    addedge(7,6);
    addedge(6,7);
    //addedge(4,5);
    addedge(5,3);
    addedge(6,5);
    addedge(5,6);
    addedge(5,8);
    addedge(8,5);
    //check_bipartite_by_bfs(coloring);
    coloring[1] = 0;
    check_bipartite_by_dfs(coloring, 1, -1);
    for(int i = 0; i<coloring.size(); i++) cout<<coloring[i]<<" ";
    cout<<endl;
}