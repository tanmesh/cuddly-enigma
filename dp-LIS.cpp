#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

int dp[100];

int lis(int a[], int n) {
	int ans, cnt = 1;
	vector<int> arr;
	arr.push_back(dp[0]);

	for(int i=1; i<n; ++i) {
		if(a[i] >= a[i-1]) {
			if(cnt == 1) {
				arr.push_back(a[i-1]);	
			}
			dp[i] = ++cnt;
			ans = max(ans, cnt);
			arr.push_back(a[i]);
		}
		else{
			cnt = 1;
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
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}
	memset(dp , 1, sizeof(dp));
	cout << lis(a, n) << endl;
	return 0;
}
