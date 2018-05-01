#include <iostream>
#include <vector>
#include <queue>
#define pb push_back

using namespace std;
vector<int> arr;

void merge(int l, int h) {
	int mid=(l+h)/2;
	queue<int> buffer1, buffer2;

	for(int i=l; i<=mid; ++i)   buffer1.push(arr[i]);
	for(int i=mid+1; i<=h; ++i) buffer2.push(arr[i]);

	int i=l;
	while(!buffer1.empty() && !buffer2.empty()) {
		if(buffer1.front() <= buffer2.front()) {
			arr[i++] = buffer1.front();
			buffer1.pop();
		}
		else{
			arr[i++] = buffer2.front();
			buffer2.pop();
		}
	}
	while(!buffer1.empty()) {
		arr[i++] = buffer1.front();
		buffer1.pop();
	}
	while(!buffer2.empty()) {
		arr[i++] = buffer2.front();
		buffer2.pop();
	}
}

void msort(int l, int h) {
	if(l < h) {
		int mid= (l+h)/2;
		msort(l, mid);
		msort(mid+1, h);
		merge(l, h);
	}
}

void print() {
	for(int i=0; i<arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cout << "Enter n:\n";
	cin >> n;
	
	cout << "Enter array\n";
	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		arr.pb(tmp);
	}

	cout << "Before\n";
	print();
	msort(0, n-1);
	cout << "After\n";
	print();
	return 0;
}
