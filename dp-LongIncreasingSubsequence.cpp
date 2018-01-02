#include <iostream>
#include <vector>
using namespace std;

int dp[100];
vector<int> arr;

int LIS(int i) {
	int &res = dp[i];
	if(res == -1) {
		res = 0;
		if(i == 0) {
			res = 1;
		}
		else{
			for(int j=0; j<i; ++j) {
				if(arr[j] < arr[i]) 
					res = max(res, LIS(j)+1);
				}
			}
		}
	return res;
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	memset(dp, -1, sizeof(dp));

	cout << "Ans = " << LIS(n-1) << endl;
	return 0;
}