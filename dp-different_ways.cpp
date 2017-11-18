#include <iostream>
#include <vector>
using namespace std;

int change(vector<int> s, int n, int m) {
	if(n == 0) {
		return 1;
	}
	if((n < 0) || (n >= 1 && m <= 0)) {
		return 0;
	}
	return change(s, n, m-1) + change(s, n-s[m-1], m);
}

int main() {
	int n;
	cin >> n;
	vector<int> s;
	for(int i=1; i<n; ++i) {
		s.push_back(i);
	}

	cout << change(s, n, n-1) << endl;
	return 0;
}