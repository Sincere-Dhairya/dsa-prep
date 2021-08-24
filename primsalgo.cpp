#include<bits/stdc++.h>

using namespace std;

map<int, vector<pair<int, int>>> graph;

void addedge(int u, int v, int d){
	graph[u].push_back({v, d});
	graph[v].push_back({u, d});
}
int main(){
	int V; //no of vertices.
	cin>>V;

	for(int i = 0; i<6; i++){
		int u, v, d;
		cin >> u >> v >> d;
		addedge(u, v, d);
	}

	vector<int> keydistances(V, INT_MAX);

        
	vector<bool> mst(V, false);

	vector<int> parent(V, -1);

	keydistances[0] = 0;

	for(int i = 0; i<V; i++){
		int mini = INT_MAX;
		int index;

		for(int j = 0; j<V; j++){
			if(keydistances[j] < mini && mst[j] == false){
				mini = keydistances[j];
				index = j;
			}
		}
		mst[index] = true;

		for(int j = 0; j<graph[index].size(); j++){
			int adj = graph[index][j].first;
			int adj_dist = graph[index][j].second;
			
			if(keydistances[adj] > adj_dist){
				keydistances[adj] = adj_dist;
				parent[adj] = index;
			}
		}
	}

	//for(int i =0 ; i< V; i++) cout<<parent[i]<<" ";

	map<int, vector<int> > minspanningtree;
	for(int i = 1; i<V; i++){
		minspanningtree[parent[i]].push_back(i);
	}

	for(int i =0;i<minspanningtree.size(); i++){
		cout<<i<<"-> ";
		for(int j = 0; j<minspanningtree[i].size(); j++)
			cout<<minspanningtree[i][j]<<", ";
		cout<<endl;
	}
}