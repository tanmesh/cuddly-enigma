#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int tmp;
	cout<<tmp<<endl;
	int m=INT_MAX,M=INT_MIN;
	cout<<m<<" "<<M<<endl;
	for(int i=0;i<n;++i){
		scanf("%d",&tmp);
		// if(i==0){
		// 	m=tmp,M=tmp;
		// }
		if(tmp<m){
			m=tmp;
		}
		if(tmp>M){
			M=tmp;
		}
	}
	cout<<m<<" "<<M<<endl;
	return 0;
}