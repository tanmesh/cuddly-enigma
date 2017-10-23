#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

long long dp1[1000];

long long dp2[1000];

// top bottom
long long fibo1(int i) {
	long long &res = dp1[i];
	if(res == -1) {
		res = 0;
		if(i == 0 || i == 1) {
			res = 1;
		}
		else{
			res = fibo1(i-1) + fibo1(i-2);
		}
	}
	return res;
}

//bottom up
long long fibo2(int n) {
	dp2[0] = 1, dp2[1] = 1;
	for(int i=2; i<=n; ++i) {
		dp2[i] = dp2[i-1] + dp2[i-2];
	}
	return dp2[n];
}
	
int main() {
	int n;
	cin >> n;
	memset(dp1, -1, sizeof(dp1));           //top bottom
	memset(dp2, 0, sizeof(dp2));            // bottom up
	cout << fibo1(n) << "\n" <<  fibo2(n) << endl;
	return 0;
}