#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

	
int main() {
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;++i) {
		cin >> a[i];
	}

	//n3
	int ans = a[0];
	for(int i=0;i<n;++i) {
		for(int j=i;j < n ; ++j ){
			int tmp = 0;
			for(int k = i ; k <= j ; ++k) {
				tmp += a[k];
			}
			cout<<i<<" "<<j<<" "<<tmp<<endl;
			ans = max(ans, tmp);
		}
	}
	cout<<endl;

	//n2
	ans = a[0];
	for(int i=0;i<n;++i) {
		int tmp  = 0;
		for(int j = i; j < n ; ++j ){
			tmp += a[j];
			cout<<i<<" "<<j<<" "<<tmp<<endl;
			ans = max(ans, tmp);
		}
	}
	cout<<endl;

	//n2 another trick
	int sum[n];
	memset(sum, 0 , sizeof(sum));
	sum[0] = a[0];
		//finding cumulative sum
	for(int i = 1; i < n ; ++i) {
		sum[i] = sum[i-1] + a[i];
	}
	cout<<endl;

	for(int i=0;i<n;++i) {
		for(int j=i; j<n ; ++j ){
			int tmp  = sum[j];
			if(i-1 >= 0){
				tmp = tmp - sum[i-1];
			}
			cout<<i<<" "<<j<<" "<<tmp<<endl;
			ans = max(ans, tmp);
		}
	}

	//n1
	int dp[n];
	memset(dp, 0, sizeof(dp));
	dp[0] = a[0];
	ans = a[0];
	
	for(int i=1;i<n;++i){
		dp[i] = max(dp[i-1] + a[i], a[i]);
		ans = max(ans, dp[i]);
	}

	return 0;
}