#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void print(int *a,int n){
	
	for(int i=0;i<n;++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(int* a,int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *a,int s,int e) {
	int j=s+1;
	for(int i=s+1; i<=e; ++i) {
		if(a[s] < a[i]){
			continue;	
		}
		if(a[s] > a[i]){
			swap(&a[i], &a[j]);
			++j;
		}
	}
	swap(&a[j-1], &a[s]);

	return j-1;
}

void quciksort(int *a,int i,int j) {
	if(i>=j) {
		return;
	}

	int l = partition(a, i, j);
	quciksort(a, i, l-1 );
	quciksort(a, l+1, j);
}

int main() {
	int n;
	cin >> n;
	int a[n];	
	for(int i=0;i<n;++i) {
		cin >> a[i];
	}
	quciksort(a,0,n-1);
	print(a,n);
	return 0;
}