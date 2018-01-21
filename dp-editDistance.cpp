#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[100][100];

int editDistance(int i, int j, string& s1, string& s2) {
	int &res = dp[i][j];
	if(res == -1) {
		if(i == 0) {
			res = j;
		}
		else if(j == 0) {
			res = i;
		}
		else {
			if(s1[i-1] == s2[j-1]) {
				res = editDistance(i-1, j-1, s1, s2);
			}
			else {
				int insert  = editDistance(i, j-1, s1, s2);
				int remove  = editDistance(i-1, j, s1, s2);     
				int replace = editDistance(i-1, j-1, s1, s2);	
				res = 1 + min(min(insert, remove), replace);
			}
		}
	}
	return res;
}

int main() {
	string s1, s2;
	cout << "Enter the string\n";
	cin >> s1 >> s2;

	memset(dp, -1, sizeof(dp));
	cout << editDistance(s1.length(), s2.length(), s1, s2) << endl;
	return 0;
}