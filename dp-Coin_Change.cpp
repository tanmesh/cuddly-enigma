#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <set>
// #include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

int dp[1000][1000];

int makingChange(int i, vector<int>& sack, int v) {
	int& res = dp[i][v];
	if(res == -1) {
		res = 0;
		if(i == -1 || v == 0) {
			res = 1;
		}
		else{
			int taken=0;
			if(v-sack[i] >= 0) {
				taken = makingChange(i, sack, v-sack[i]);
				// res = makingChange(i, sack, v-sack[i]) + makingChange(i-1, sack, v);
			}
			int not_taken = makingChange(i-1, sack, v);
			// cout << taken << " " << not_taken << endl;
			res = taken + not_taken;
		}
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int value;
    cin >> value;

    vector<int> sack;

    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
    	int tmp;	cin >> tmp;
    	sack.pb(tmp);
    }

    memset(dp, -1, sizeof(dp));

    cout << makingChange(n-1, sack, value) << endl;

    // for(int i=0; i<n; ++i) {
    // 	for(int j=1; j<=value; ++j) {
    // 		cout << dp[i][value] << " ";
    // 	}
    // 	cout << endl;
    // }
    return 0; 
}

