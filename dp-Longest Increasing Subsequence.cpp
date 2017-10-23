#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

int dp[100];

int lis(int a[], int cnt) {
	int ans;
	vector<int> arr;
	arr.push_back(dp[0]);
	for(int i=1; i<9; ++i) {
		if(a[i] > a[i-1]) {
			dp[i] = ++cnt;
			ans = max(ans, dp[i]);
			arr.push_back(a[i]);
		}
		else{
			cnt = 0;
			arr.clear();
		}
	}
	for(int i=0; i<arr.size(); ++i) {
		cout << arr[i] << " "; 
	}
	cout << endl;
	return ans;
}

int main() {
	int a[9] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	memset(dp , 0, sizeof(dp));
	int cnt = 0;
	dp[0] = 0;
	cout << lis(a, cnt) << endl;
	return 0;
}
