#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> G[100];

void Topo(int u, vector<int>& visited) {
	visited[u] = 1;
	for(int i=0; i<G[u].size(); ++i) {
		int v = G[u][i];
		if(!visited[v]){
			Topo(v, visited);
		}
	}
	cout << u+1  << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	int u ,v;
	for(int i = 0; i < m ; ++i) {
		cin >> u >> v;
		G[u].push_back(v);                    
	}

	vector<int> visited(n, 0);

	for(int i=0 ;i<n ;++i) {
		if(!visited[i]){
			Topo(i,visited);	
		}
	}

	return 0;
}