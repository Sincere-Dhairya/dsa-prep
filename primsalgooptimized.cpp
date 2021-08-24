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

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > distances;

	vector<bool> mst(V, false);

	vector<int> parent(V, -1);

	keydistances[0] = 0;

	distances.push({0, 0});

	while(!distances.empty()){
		int v = distances.top().second;
        distances.pop();
		mst[v] = true;

		for(int i = 0 ; i< graph[v].size(); i++){
			int adj = graph[v][i].first;
			int dist = graph[v][i].second;

			if(keydistances[adj] > dist && mst[adj] == false){
				keydistances[adj] = dist;
				mst[adj] = true;
				distances.push({dist, adj});
				parent[adj] = v;
			}
		}
	}

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