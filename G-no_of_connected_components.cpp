#include <vector>
#include <iostream>
using namespace std;

void dfs(int u, vector<bool>& visited, vector<int> graph[]) {
	visited[u]=true;
	cout << u << " ";
	for(int i=0; i<graph[u].size(); ++i) {
		int v = graph[u][i];
		if(!visited[v]) {
			dfs(v, visited, graph);
		}
	}
}

void connectedComponent(int v, vector<int> graph[]) {
	vector<bool> visited(v, false);
	for(int i=0; i<v; ++i) {
		if(!visited[i]){
			dfs(i, visited, graph);
			cout << endl;
		}
	}
}

int main() {
	int e, v;
	cin >> v >> e;
	vector<int> graph[100];
	for(int i=0; i<e; ++i) {
		int m, n;
		cin >> m >> n;
		graph[m].push_back(n);
		graph[n].push_back(m);
	}

	connectedComponent(v, graph);
	return 0;
}