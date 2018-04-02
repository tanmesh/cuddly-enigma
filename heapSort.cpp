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
	int min_id=i; // tmp
	
    if(2*i < n){
        if(heapArr[2*i] < heapArr[min_id])
        	min_id = 2*i;
    }
    if(2*i+1 < n){
        if(heapArr[2*i+1] < heapArr[min_id])
        	min_id = 2*i+1;
    }
    if(min_id != i){
		swap(heapArr[i], heapArr[min_id]);
		heapify(heapArr, min_id, n);
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
	for(int i=n-1; i>0; --i ) {
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

	buildHeap(heapArr);
	printHeap(heapArr);
	// heapSort(heapArr);
	return 0;
}