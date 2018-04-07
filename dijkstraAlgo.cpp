#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define mp                          make_pair
#define f                           first
#define sc                          second
#define pb                          push_back
typedef pair<int,int> PP;

void dijktra(vector< PP > graph[], int v) {
	int scr;
	cin >> scr;
	--scr;
	vector<int> dis(v, INT_MAX);
	dis[scr] = 0;
	priority_queue < PP > Q; 
	Q.push(mp(dis[scr], scr));
	int cnt = 1;
	while(!Q.empty()) {
		int u = Q.top().second;		
		Q.pop();
		if(cnt == v) break;
		int sz=graph[u].size();
	    for(int i=0; i<sz; ++i){
	        int v = graph[u][i].first;
	        int wt = graph[u][i].second;
	        if(dis[v] > dis[u]+wt) {
	            dis[v] = dis[u]+wt;
	            Q.push(mp(dis[v], v));
	        }
    	}
	}
	for(int i=0;i<v;++i) {
		if(i!=scr)
		cout<<dis[i]<<" " ;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);

	int v, e;
	cin >> v >> e;
	
	vector< PP > graph[1000];

	for(int i=0;i<e;i++) {
		int n, m, w;
		cin >> n >> m >> w;
		--n, --m;
		graph[n].push_back(mp(m, w));
		graph[m].push_back(mp(n, w));
	}

	dijktra(graph, v);
	return 0;
}