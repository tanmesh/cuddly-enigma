#include <iostream>
#include <math.h>
using namespace std;
int dp;

int f(int n) {
	if(n == 1) {
		return dp;
	}
	++dp;
	if(n%2 == 0) {
		f(min(n-1, n/2));
	}
	else if(n%3 == 0) {
		f(min(n-1, n/3));
	}
	else{
		f(n-1);
	}
	return dp;
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}

	for(int i=0; i<n; ++i) {
		dp = 0;
		cout << f(a[i]) << endl;
	}
	return 0;
}