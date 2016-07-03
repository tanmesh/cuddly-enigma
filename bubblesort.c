#include <stdio.h>
int main(){
	int temp,i,j,n;
	printf("give array size\n");
	scanf("%d",&n);
	int arr[n];
	printf("give array\n");
	for(i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	for(i=n;i>0;--i){
		for(j=1;j<i;++j){
			if(arr[j-1]>arr[j]){
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("NEWARRAY\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}

}