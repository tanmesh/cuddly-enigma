
#include <iostream>
#include <vector>
using namespace std;

#define INF                         (int)1e9
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define f                           first
#define sc                          second
typedef pair<int,int> pp;
#define MOD 1000000007


int find(int i, vector<int>& parent) {
	return i == parent[i] ? i : parent[i] = find(parent[i], parent);
}

void Union(int u, int v, vector<int>& parent) {
	parent[find(u, parent)] = find(v, parent);
}

void krushkal(vector< pair <int, pp> >& G, int v, vector< pair <int, pp> >& T) {
	sort(G.begin(), G.end());
	int ans=0;
	vector<int> parent(v);
	for(int i=0; i<v; ++i) {
		parent[i] = i;
	}

	for(int i=0; i<G.size(); ++i) {
		int u = G[i].sc.f;
		int v = G[i].sc.sc;

		if(find(u, parent) != find(v, parent)) {
			ans += G[i].f;
			T.push_back(G[i]);
			Union(find(u, parent), find(v, parent), parent);
		}
	}

	cout << ans << endl;
	cout << "Edge :" << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].second.first << " - " << T[i].second.second << " : "
                << T[i].first;
        cout << endl;
    }
}

int main() {
	int v, e;
	cin >> v >> e;

	vector< pair <int, pp> > G, T;

	for(int i=0; i<e; ++i) {
		int u, v, wt;
		cin >> u >> v >> wt;
		G.push_back(mp(wt, mp(u, v)));
		G.push_back(mp(wt, mp(v, u)));
	}

	krushkal(G, v, T);
	return 0;
}