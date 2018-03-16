 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

// input
// 4 6
// 0 1
// 0 2
// 1 2
// 2 0
// 2 3
// 3 3
// 2


void dfs(int u, vector<int>& visited, vector<int>& parent, vector<int> graph[]) {
	visited[u]=1;
	cout << u << " ";
	for(int i=0; i<graph[u].size(); ++i) {
		int v = graph[u][i];
		parent[i] = u;
		if(!visited[v]){
			dfs(v, visited, parent, graph);
		}
	}
}

int main() {
	vector<int> graph[100];
	int n, m;
	cin >> n >> m;
	
	int u,v;
	for(int i=0; i<m ; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		// graph[v].push_back(u);
	}

	for(int i=0; i<n; ++i) {
		cout  << i << " : ";
		for(int j=0; j<graph[i].size(); ++j) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	
	int start;
	cin >> start;
	vector<int> visited(n, 0);
	vector<int> parent(v);

	dfs(start, visited, parent, graph);
	cout << endl;
	return 0;
}
