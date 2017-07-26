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
void merge(int* a,int i,int j){
	int mid=(i+j)/2,n=j+1;
	int b[n],l=0,k=mid+1;
	int start=i,end=j;
	while(i<=mid && k<=j){
		if(a[i]<a[k]){
			b[l++]=a[i++];
		}
		else{
			b[l++]=a[k++];
		}
	}
	if(i>mid){
		while(k<=j){
			b[l++]=a[k++];
		}
	}
	else{
		while(i<=mid){
			b[l++]=a[i++];
		}
	}
	l=0;
	for(int i=start;i<=end;++i){
		a[i]=b[l++];
	}
}

void mergesort(int *ptr,int i,int j){
	if(i>=j){
		return;
	}
	int mid=(i+j)/2;
	mergesort(ptr,i,mid);
	mergesort(ptr,mid+1,j);
	merge(ptr,i,j);
}
int main(){
	int n;
	cin >> n;
	int a[n];	
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	mergesort(&a[0],0,n-1);
	print(&a[0],n);
}









