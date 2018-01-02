#include <iostream>
#include <string.h>
using namespace std;

int dp[100][100];

int lcs(string s1, string s2, int i, int j) {
	int &res = dp[i][j];
	if(res == -1) {
		res = 0;
		if(i == 0 || j == 0) {
			return 0;
		}
		if(s1[i-1] == s2[j-1]) {
			res = 1+lcs(s1, s2, i-1, j-1);
		}
		else{
			res = max(lcs(s1, s2, i-1, j), lcs(s1, s2, i, j-1));
		}
	}
	return res;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length(), m = s2.length();

	memset(dp, -1, sizeof(dp));
	cout << "Longest Common Subsequence = " << lcs(s1, s2, n, m) << endl;
	return 0;
}