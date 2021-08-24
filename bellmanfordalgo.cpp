#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int first;
    int second;
    int distance;

    node(int, int, int); 
};
node :: node(int u, int v, int d){
    this->first = u;
    this->second = v;
    this->distance = d;
}
/*
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3
*/

void addedge(node & temp, int a, int b, int c){
    temp.distance = c;
    temp.first = a;
    temp.second = b;
}
void create_graph(int edges, vector<node> & graph){
    for(int i =0 ;i<edges; i++){
        int u, v, d;
        cin>>u >> v >> d;
        graph.push_back(node(u, v, d));
        //graph[i].first = u;
        //graph[i].second = v;
        //graph[i].distance = d;
        //addedge(graph[i], u, v, d);
    }
}

void printing_nodes(vector<node> graph){
    int n = graph.size();
    for(int i = 0; i<n; i++){
        cout<<graph[i].first<<" "<<graph[i].second<<" "<<graph[i].distance<<endl;
    }
}

void bellmanford(vector<int> & dist, vector<node> &graph){
    int n = dist.size();

    for(int i = 1; i<n; i++){
        for(auto itr : graph){
            //if(dist[itr.second] > dist[itr.first] + itr.distance) dist[itr.second] = dist[itr.first] + itr.distance;
            dist[itr.second] = min(dist[itr.second], dist[itr.first] + itr.distance);
        }
    }
}

int main(){
    int V = 5, edges = 7;

    vector<node> graph;
    create_graph(edges, graph);

    vector<int> distances(V+1, 10000);
    int src = 0;
    distances[src] = 0;
    bellmanford(distances, graph);
    for(int i =0 ;i < V+1; i++) cout<<distances[i]<<" ";
    printing_nodes(graph);
}
