#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[100][100];

int editDistance(int i, int j, string& s1, string& s2) {
	int &res = dp[i][j];
	if(res == -1) {
		if(i == s1.length() || j == s2.length()) {
			res = 0;
		}
		else{
			if(s1[i] == s2[i]) {
				res = 1 + editDistance(i+1, j+1, s1, s2);
			}
			else {
				res = editDistance(i, j+1, s1, s2);
				res = min(res, editDistance(i+1, j, s1, s2));     // remove
				res = min(res, editDistance(i+1, j+1, s1, s2));		//  replace
			}
		}
	}
	return res;
}

int main() {
	string s1, s2;
	s1 = "cutee";
	s2 = "cut";

	memset(dp, -1, sizeof(dp));
	cout << editDistance(0, 0, s1, s2) << endl;

	return 0;
}