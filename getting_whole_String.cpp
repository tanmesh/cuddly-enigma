#include <stdio.h>
#include <string>

int main(){
	int n;

	printf("n=\n");
	scanf("%d",&n);

	char str[n];
	printf("str=\n");
	scanf(" %[^\n]s",str);

	printf("%s\n",str);

}