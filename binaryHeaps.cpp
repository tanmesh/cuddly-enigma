#include <math.h>
#include <iostream>
using namespace std;

void heapify(int* ptr, int i, int n) {
	while(i <= n/2) {
		int parent = *(ptr + i-1);
		// only left child
		if(2*i+1 > n) {
			int leftChild = *(ptr + 2*i-1);
			if(parent > leftChild) {
				// swap(parent, leftChild);
				swap(*(ptr + i-1), *(ptr + 2*i-1));
				i = 2*i;
			}
		}
		// both child are there
		else{
			int leftChild = *(ptr + 2*i-1), rightChild = *(ptr + 2*i + 1-1);
			if(parent > leftChild || parent > rightChild) {
				if(leftChild < rightChild) {
					// swap(parent, leftChild);
					swap(*(ptr + i-1), *(ptr + 2*i-1));
					i = 2*i;
				}
				else{
					// swap(parent, rightChild);
					swap(*(ptr + i-1), *(ptr + 2*i + 1-1));
					i = 2*i + 1;
				}
			}
			else{
				break;
			}
		}
	}
}

void buildHeap(int* ptr, int n) {
	for(int i=floor(n/2); i>0; --i) {
		heapify(ptr, i, n);
	}
}

void printHeap(int A[], int n) {
	for(int i=0; i<n; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for(int i=0; i<n; ++i) {
		cin >> A[i];
	}
	buildHeap(A, n);
	printHeap(A, n);
	return 0;
}