#include <iostream>
using namespace std;

int dp[100];

int f(int i) {
	int &res = dp[i];
	if(res == -1) {
		res = 0;
		if(i == 0 || i == 1 || i == 2) {
			res = 1;
		}
		else if(i == 3) {
			res = 2;
		}
		else{
			res = f(i-1) + f(i-3) + f(i-4);
		}
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	memset(dp , -1, sizeof(dp));
	dp[0] = 1, dp[1] = 1, dp[2] = 1, dp[3] = 2;

	cout << f(n) << endl;
}
