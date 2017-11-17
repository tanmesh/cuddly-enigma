#include <iostream>
#include <vector>

using namespace std;

int coin_change(vector<int> s, int n, int m) {
	if((n < 0) || (m <= 0 && n >= 1)) {
		return 0;
	}
	if(n == 0) {
		return 1;
	}
	return coin_change(s, n, m-1) + coin_change(s, n-s[m-1], m);
}

int main() {
	int n, m, tmp;	//	change for N cents
	cin >> n;

	vector<int> s;	// valued coins
	while(cin >> tmp) {
		s.push_back(tmp);
	} 
	m = s.size();
	// how many ways can we make the change
	cout << coin_change(s, n, m) << endl;
	return 0;
}