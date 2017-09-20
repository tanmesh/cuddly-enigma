#include <iostream>
#include <vector>
using namespace std;

class island{
	public:
		int r,c;
		vector < vector <int> > graph;
		vector < vector <bool> > visited;
		void init(void);
		int findIsland(void);
		void dfs(int ,int);
		void display(void);
};

void island :: display(void) {
	for(int i=0; i<r; ++i) {
		for(int j=0; j<c; ++j) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void island :: init(void) {
	cin >> r >> c;
	int a;

	for(int i=0; i<r; ++i) {
		vector <int> tmp;
		for(int j=0; j<c; ++j) {
			cin >> a;
			tmp.push_back(a);
		}
		graph.push_back(tmp);
	}

	for(int i=0; i<r; ++i) {
		vector <bool> tmp;
		for(int j=0; j<c; ++j) {
			tmp.push_back(false);
		}
		visited.push_back(tmp);
	}
}

void island :: dfs(int r1, int c1) {
	static int rc[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	static int cc[] = { 1,  0, -1, 1,-1, 1, 0,-1};
	visited[r1][c1] = true;
	for(int i=0; i<8; ++i) {
		int nx = r1 + rc[i];
		int ny = c1 + cc[i];
		if(nx >=0 && ny >=0 && nx <r && ny <c && graph[nx][ny] && !visited[nx][ny]) {
			dfs(nx , ny);
		}
	}
}

int island :: findIsland(void) {
	int cnt =0;
	for(int i=0; i<r; ++i) {
		for(int j=0; j<c; ++j) {
			if(graph[i][j] && !visited[i][j]) {
				dfs(i,j);
				++cnt;
			}
		}
	}
	return cnt;
}

int main() {
	island i;
	i.init();
	// i.display();
	cout << "number of island " << i.findIsland() << endl;
	return 0;
}