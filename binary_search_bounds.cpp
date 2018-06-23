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
 
const int MAXN = (int)2e5+7;
// const int MAXN = (int)1e3;

int lower_bound(vector<int> a, int l, int h, int key) {
	while(l < h) {
		int mid = l + (h-l)/2;
		if(a[mid] >= key) {
			h = mid;
		}
		else{
			l = mid+1;
		}
	}
	return h;
}

int upper_bound(vector<int> a, int l, int h, int key) {
	while(l < h) {
		int mid = l + (h-l)/2;
		if(a[mid] > key) {
			h = mid;
		}
		else{
			l = mid+1;
		}
	}
	return h;
}

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		a.pb(tmp);
	}
	int key;
	cin >> key;

	cout << "Lower Bound is " << lower_bound(a, 0, n-1, key) << endl;
	cout << "Upper Bound is " << upper_bound(a, 0, n-1, key) << endl;
	return 0;
} 