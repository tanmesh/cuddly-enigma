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
	vector<int> dis(v, INT_MAX);
	dis[scr] = 0;
	priority_queue < PP > Q;
	// for(int i=0; i<v; ++i) {
		Q.push(PP(scr, dis[scr]));
	// }
	while(!Q.empty()) {
		int u = Q.top().second;		
		Q.pop();
		// for(auto it = graph[u].begin(); it!=graph[u].end(); ++it) {
		// 	int v = it->f;
		// 	int wt = it->sc;
		// 	if(dis[v] > dis[u]+wt) {
		// 		dis[v] = dis[u]+wt;
		// 		Q.push(PP(v, -dis[v]));
		// 	}
		// }
		int sz=graph[u].size();
	    for(int i=0;i<sz;++i){
	        int v=graph[u][i].first;
	        int wt=graph[u][i].second;
	        if(dis[v]>dis[u]+wt) {
	            dis[v]=dis[u]+wt;
	            Q.push(PP(-dis[v],v));
	        }
    	}
	}
	for(int i=0;i<v;++i) {
		cout<<i<<" "<<dis[i]<<endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);

	int v, e;
	cin >> v >> e;
	
	vector< PP > graph[1000];

	for(int i=0;i<e;i++) {
		int n, m, w;
		cin >> n >> m >> w;
		graph[n].push_back(mp(m, w));
		graph[m].push_back(mp(n, w));
	}

	// for(int j=0; j<v; j++) {
	// 	for(auto it=graph[j].begin(); it!=graph[j].end(); it++) {
	// 		cout << j << "-" << it->first << " " << it->second << endl;
	// 	}
	// }

	dijktra(graph, v);
	return 0;
}

// typedef pair<int,int> pp;
// int main() {
//     int n,m;
//     cin>>n>>m;
//     vector<pp>G[100];
//     int u,v,w;
//     for(int i=0;i<m;++i) {
//         cin>>u>>v>>w;
//         G[u].pb(mp(v,w));
//         G[v].pb(mp(u,w));
//     }
//     priority_queue<pp>Q;
//     int d[n+1];
//     for(int i=1;i<=n;++i)
//         d[i]=INT_MAX;
//     int s;
//     cin>>s;
//     d[s]=0;
//     Q.push(pp(0,s));
//     while(!Q.empty()){
//         int u=Q.top().second;
//         cout << u << endl;
//         Q.pop();
//         int sz=G[u].size();
//         for(int i=0;i<sz;++i){
//             int v=G[u][i].first;
//             int wt=G[u][i].second;
//             if(d[v]>d[u]+wt) {
//                 d[v]=d[u]+wt;
//                 Q.push(pp(-d[v],v));
//             }
//         }
//     }
//     // for(int i=1;i<=n;++i)cout<<i<<" "<<d[i]<<endl;
//      return 0;
// }