//gcd and lcm
#include <stdio.h>
int main()
{
	printf("give number to find gcd and lcm\n");
	int a,b,tmp;
	scanf("%d%d",&a,&b);
	while(b!=0) {
		tmp=a%b;
		a=b;
		b=tmp;
	}
	printf("gcd = %d\n",b);
	int lcm=(a*b)/b;
	printf("lcm =%d\n",lcm);
	return 0;
}