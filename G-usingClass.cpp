#include <iostream>
#include <vector>
using namespace std;

vector<int> visited(100, 0);
vector<int> G[100];
class graph{
	public:
		int start,target;
		void input(void);
		friend bool calculate(int, int);
};

void graph :: input(void) {
		int n, m;
		cin >> n >> m;

		for(int i=0; i<m; ++i) {
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		cin >> start >> target;
}

bool calculate(int s, int t) {
	visited[s] =1;
	if( s == t) {
		return true;
	}
	for(int i=0; i<G[s].size() ;++i) {
		int v = G[s][i];
		if(!visited[v] && calculate(v,t)){
			return true;
		}
	}
	return false;
}

int main() {
	graph g;
	g.input();
	if(calculate(g.start, g.target)) {
			cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}
