#include <stdio.h>

void merge(int a[], int s, int e) {
	
}

int main() {
	int n;
	scanf("%d", &n);

	int a[n];
	for(int  i=0;i<n;++i) {
		scanf("%d", &a[i]);
	}

	merge(a, 0 , n-1);

	for(int i=0;i<n;++i) {
		printf("%d\t", a[i]);
	}
	printf("\n");

	return 0;
}

