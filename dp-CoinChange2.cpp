#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int f(int s[], int i, int N) {
	if(N == 0) {
		return 1;
	}
	if((N < 0) || (N > 0 && i < 0)) {
		return 0;
	}
	return f(s, i, N-s[i]) + f(s, i-1, N);
}

int main() {
	int N;
	cin >> N;
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	cout << f(arr, n-1, N) << endl;
	return 0;
}