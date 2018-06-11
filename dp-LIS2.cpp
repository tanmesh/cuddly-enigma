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
 
typedef pair<int,int> pp;
 
int main() {
    int n;
	cin >> n;
	vector<ll> a;
	ll dp[n];
	for(int i=0; i<n; ++i) dp[i] = 0;
	
	for(int i=0; i<n; ++i) {
		ll tmp;	cin >> tmp;
		a.pb(tmp);
	}

	dp[0] = 1;
	ll tmp=1;
	for(int i=1; i<n; ++i) {
		ll ans = 0;
		for(int j=0; j<i; ++j) {
			if(a[i] > a[j]) {
				ans = max(ans, dp[j]);
			}
		}
		dp[i] = ans+1;
		tmp = max(tmp, dp[i]);
	}
	cout << tmp << endl;
 
	return 0;
} 