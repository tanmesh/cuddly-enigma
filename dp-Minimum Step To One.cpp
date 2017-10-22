#include <iostream>
#include <math.h>
using namespace std;
int dp[1000];

// int f(int n) {
// 	dp[1]=0, dp[2]=1, dp[3]=1;
// 	if(n >= 4){
// 		for(int i=4; i<=n; ++i) {
// 			dp[i] = dp[i-1]+1;
// 			if(i%2 == 0) {
// 				dp[i] = min(dp[i-1],dp[i/2])+1;
// 			}
// 			if(i%3 == 0) {
// 				dp[i] = min(dp[i-1],dp[i/3])+1;	
// 			}
// 		}
// 	}
// 	return dp[n];
// }

int f(int i) {
	int &res = dp[i];
	if(res == -1) {
		res = 0;
		if(i == 1 || i == 2 || i == 3) {
			res = 1;
		}	
		else{
			if(i%2 != 0 && i%3 != 0) {
				res = f(i-1);
			}
			else if(i%2 == 0) {
				res = min(f(i-1), f(i/2)) + 1;
			}
			if(i%3 == 0) {
				res = min(f(i-1), f(i/3)) + 1;
			}
		}
	}
	return res;
}

int main() {
	int term ,n ;
	cin >> term;

	memset(dp , -1, sizeof(dp));
	for(int i=0; i<term; ++i) {
		cin >> n;
		cout << f(n) << endl;
	}
	return 0;
}