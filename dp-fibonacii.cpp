#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

long long dp[1000];

long long fibo(int i) {
	long long &res = dp[i];
	if(res == -1) {
		res = 0;
		if(i == 0 || i == 1) {
			res = 1;
		}
		else{
			res = fibo(i-1) + fibo(i-2);
		}
	}
	return res;
}
	
int main() {
	int n;
	cin >> n;
	for(int i=0;i<1000;++i) {
		dp[i]=-1;
	}
	cout << fibo(n) << endl;
	return 0;
}