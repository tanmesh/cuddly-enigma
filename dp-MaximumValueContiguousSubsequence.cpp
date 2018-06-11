#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <math.h>
#include <limits.h>
// #include <bits/stdc++.h>
 
using namespace std;
 
#define mp  make_pair
#define f   first
#define sc  second
#define pb  push_back
#define ll  long long
 
typedef pair<ll,ll> pp;
 
const int MAXN = (int)1e5+7;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		a.pb(tmp);
	}
	
	int dp[n];
	dp[0] = a[0];
	int ans = 0;
	for(int i=1; i<n; ++i) {
		dp[i] = max(a[i], a[i]+dp[i-1]);
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	return 0;
}