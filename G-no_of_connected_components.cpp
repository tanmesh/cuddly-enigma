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

int connectedComponent(int v, vector<int> graph[]) {
	vector<bool> visited(v, false);
	int cnt=0, ans=0;
	for(int i=0; i<v; ++i) {
		if(!visited[i]){
			++cnt;
			dfs(i, visited, graph);
			cout << endl;
		}
		else if(cnt!=0){
			++ans;
			cnt = 0;
		}
	}
	if(cnt!=0){
		++ans;
		cnt = 0;
	}
	return ans;
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

	cout << connectedComponent(v, graph) << endl;
	return 0;
}