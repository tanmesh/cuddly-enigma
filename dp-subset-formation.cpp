#include <iostream>
#include <vector>
using namespace std;

vector< vector< int > > ans;
int cnt;

int subset_cnt(vector<int> a) {
	ans.push_back(a);
	if(a.size() == 1) {
		return 1;
	}
	for(int i=0; i<a.size(); ++i) {
		vector<int> tmp;
		for(int j=0; j<a.size(); ++j) {
			if(i !=j) {
				tmp.push_back(a[j]);
			}
		}
		cnt = 1+subset_cnt(tmp);
		tmp.clear();
	}	
	return cnt;
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
	cout << 1 + subset_cnt(a) << endl << endl;
	for(int i=0; i<ans.size(); ++i) {
		for(int j=0; j<ans[i].size(); ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}