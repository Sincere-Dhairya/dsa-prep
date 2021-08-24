#include<bits/stdc++.h>

using namespace std;

void addedgedistance(vector< vector< int > > & graph, int u, int v, int d){

}

void floydwarshal(vector< vector< int> > & graph){
    int n = graph.size();

    for(int i =0; i<n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if( i == j || k == i) continue;
                else{
                    if(graph[j][i] == INT_MAX || graph[i][k] == INT_MAX) continue;
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                }
                
            }
        }
    }
}

void printing_graph(vector< vector< int> > graph){
    int n = graph.size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    int V = 4;
    vector< vector<int> > graph(V, vector<int> (4, INT_MAX));

    for(int i =0 ;i<V; i++) graph[i][i] = 0;

    graph[0][1] = 3;
    graph[0][3] = 5;
    graph[1][0] = 2;
    graph[1][3] = 8;
    graph[2][1] = 1;
    graph[3][2] = 2;
    
    printing_graph(graph);
    cout<<endl;
    floydwarshal(graph);
    printing_graph(graph);
    return 0;

}