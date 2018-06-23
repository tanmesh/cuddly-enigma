#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <math.h>
#include <limits.h>
// #include <bits/stdc++.h>
 
using namespace std;
 
#define mp  make_pair
#define f   first
#define sc  second
#define pb  push_back
#define ll  long long
 
typedef pair<ll,ll> pp;
 
const int MAXN = (int)2e5+7;
// const int MAXN = (int)1e3;

int dp[MAXN][MAXN];

int edit_distance(string& s1, string& s2, int i, int j) {
	int& res = dp[i][j];
	if(res == -1) {
		res = 0;
		if(i == s1.length()) {
			res = s2.length()-j;
        }
        else if(j == s2.length()) {
         	res = s1.length()-i;
        }
		else {
			if(s1[i] != s2[j]) {
				int del = edit_distance(s1, s2, i+1, j);
				int ins = edit_distance(s1, s2, i, j+1);
				int rep = edit_distance(s1, s2, i+1, j+1);
				res = 1 + min(del, min(ins, rep));	
			}
			else{
				res = edit_distance(s1, s2, i+1, j+1);
			}
		}
	}
	return res;
}

int main() {
	string s1, s2;	
	cin >> s1 >> s2;

	// for(int i=0; i<s1.length(); ++i) 
	// 	for(int j=0; j<s2.length(); ++j) 
	// 		dp[i][j] = -1;
	memset(dp, -1, sizeof(dp));

	cout << edit_distance(s1, s2, 0, 0) << endl;
	return 0;
} 