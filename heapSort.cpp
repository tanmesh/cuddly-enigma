#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void heapify(vector<int> &heapArr, int i, int n) {
	if(n == 0) {
		return;
	}
	while(i < n/2){
		// no rigth child
		if(2*i+2 >= n) {
			if(heapArr[i] > heapArr[2*i+1]) {
				// swap parent and left node
				swap(heapArr[i], heapArr[2*i+1]);
				i=2*i+1;
			}
		}
		else if(heapArr[i] > heapArr[2*i+1] || heapArr[i] > heapArr[2*i+2]) {
			if(heapArr[2*i+1] < heapArr[2*i+2]) {
				// swap parent and left node
				swap(heapArr[i], heapArr[2*i+1]);
				i=2*i+1;
			}
			else{
				// swap parent and right node
				swap(heapArr[i], heapArr[2*i+2]);	
				i=2*i+2;
			}
		}
		else{
			break;
		}
	}
}

void buildHeap(vector<int> &heapArr) {
	int n = heapArr.size();
	for(int i=floor(n/2)-1; i>=0; --i) {
		heapify(heapArr, i, n);
	}
}
void printHeap(vector<int> heapArr) {
	for(int i=0; i<heapArr.size(); ++i) {
		cout << heapArr[i] << " ";
	}
	cout << endl;
}

void delMin(vector<int>& heapArr, int n) {
	cout << heapArr[0] << " ";
	swap(heapArr[0], heapArr[n]);
}

void heapSort(vector<int>& heapArr) {
	int n = heapArr.size();
	for(int i=n-1; i>0; --i) {
		delMin(heapArr, i);
		heapify(heapArr, 0, i-1);
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;

	vector<int> heapArr;
	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		heapArr.push_back(tmp);
	}

	// printHeap(heapArr);
	buildHeap(heapArr);
	// printHeap(heapArr);
	heapSort(heapArr);
	return 0;
}