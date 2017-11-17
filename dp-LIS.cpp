#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector< vector< int > > ans;

int max(int x, int y) {
	return x>y? x : y;
}

void generateSubset(int i, vector<int> a, vector<int> curr_subset) {
	if(i==a.size()) {
		ans.push_back(curr_subset);
		return;
	}
	curr_subset.push_back(a[i]); 
	generateSubset(i+1, a, curr_subset);

	curr_subset.pop_back(); 
	generateSubset(i+1, a, curr_subset);	
}

bool check_is_lis(vector<int> a) {
	for(int i=1; i<a.size(); ++i) {
		if(a[i] < a[i-1]) {
			return false;
		}
	}
	return true;
}

int lis(vector<int> a) {
	int b = 1 , n = a.size();
	vector<int> curr_subset;
	generateSubset(0, a, curr_subset);

	for(int i=0; i<ans.size(); ++i) {
		if(check_is_lis(ans[i])) {
			b = max((ans[i]).size() , b);
		}
	}
	return b;
}

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	cout << lis(a) << endl;
	return 0;
}
