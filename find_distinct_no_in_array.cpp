#include <stdio.h>
int main(){
	int n;
	printf("give n:\n");
	scanf("%d",&n);
	int array[n];
	char ch;
	printf("wnt to give sorted array?(y/n)\n");
	scanf("%s",&ch);
	printf("give array elements\n");
	for(int i=0;i<n;++i){
		scanf("%d",array+i);
	}
	if(ch=='n'){
		int m=0;
		for(int i=0;i<n;++i){
			int count=0;
			for(int j=i+1;j<n;++j){
				if(array[i]==array[j]){
					++count;
				}
			}
			if(count!=0){
				continue;
			}
			else{
				array[m++]=array[i];
			}
		}
		for(int i=0;i<m;++i){
			printf("%d\t",array[i]);
		}
	}
	else{
		int m=0;
		for (int i=0; i<n; ++i){
			if(array[i]==array[i+1] && i!=(n-1)){
	 			continue;
	 		}
	 		else{
	 			array[m++]=array[i];
	 		}
		}
		// array[m++]=array[n-1];
		for(int i=0;i<m;++i){
			printf("%d\t",array[i]);
		}
	}
}