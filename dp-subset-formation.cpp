#include <iostream>
#include <vector>
using namespace std;

vector< vector< int > > ans;

int subset_cnt(vector<int> a) {
	ans.push_back(a);
	if(a.size() != 1) {
		for(int i=0; i<a.size(); ++i) {
			vector<int> tmp;
			for(int j=0; j<a.size(); ++j) {
				if(i !=j) {
					tmp.push_back(a[j]);
				}
			}
			return 1+subset_cnt(tmp);
			tmp.clear();
		}	
	}
	return 1;
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
	cout << 1+subset_cnt(a) << endl;
	// cout << ans.size() << endl;
	return 0;
}