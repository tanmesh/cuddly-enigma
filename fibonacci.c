#include <stdio.h>

long long cache[1000];
long long fib(int n){
	if(cache[n]!=-1){
		return cache[n];
	}
	     
	long long x,y;

	if(cache[n-1]!=-1){
		x=cache[n-1];
	}
	else{
		x=fib(n-1);	
		cache[n-1]=x;
	}
	
	if(cache[n-2]!=-1){
		y=cache[n-2];
	}
	else{
		y=fib(n-2);	
		cache[n-2]=y;
	}
	
	long long sum=x+y;
	return sum;
}

int main(){
	for(int i=0;i<1000;++i) {
		cache[i] = -1;
	}
	cache[0]=1;
	cache[1]=1;
	int i,n;
	printf("give a number\n");
	scanf("%d",&n);
	long long sum=fib(n);
	printf("%lld\n",sum);


	long long dp[n+1];
	dp[0]=1;
	dp[1]=1;

	for(int i=2;i<=n;++i){
		dp[i]=dp[i-1]+dp[i-2];
	}
	printf("%lld\n",dp[n]);

	return 0;
}

