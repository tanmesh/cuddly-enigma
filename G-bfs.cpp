#include <iostream>
#include <queue>

using namespace std;

//input
// 4 6
// 0 1
// 0 2
// 1 2
// 2 0
// 2 3 
// 3 3
// 2

void BFS(int i, vector<bool>& visited, vector<int>& parent,  vector<int> graph[]) {
	queue<int> q;
	visited[i] = true;
	q.push(i);

	while(!q.empty()) {
		i = q.front();
		cout << i << " ";
		q.pop();
		for(auto it = graph[i].begin(); it!=graph[i].end(); ++it) {
			if(!visited[*it]) {
				visited[*it] = true;
				parent[*it] = i;
				q.push(*it);
			}
		}
	}

}

int main() {
	int v,e;
	cin >> v >> e;
	vector<int> graph[100];

	for(int i=0; i<e; ++i) {
		int u ,v;
		cin >> u >> v;
		graph[u].push_back(v);
		// graph[v].push_back(u);
	}

	vector<bool> visited(v, false);
	vector<int> parent(v);
	int n;
	cin >> n;
	BFS(n, visited, parent, graph);
	cout << endl;
	return 0;
}