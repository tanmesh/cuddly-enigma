#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	printf("give no to be checked\n");
	scanf("%d",&n);
	int cnt=0;
	for(int i=2;i<n;++i) {
		if(n%i==0){
			printf("no is not prime\n");
			exit(0);
		}
	}
	printf("no is prime\n");
	return 0; 
}