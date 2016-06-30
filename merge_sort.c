#include <stdio.h>
main()
{
	int *a;
	a=(int*)malloc(sizeof(int)*5)
	int data[100],i,j,n,temp; // data[i], data --> pointer, data+i == &data[i]
	scanf("%d",&n);
	for (int i = 0; i < n; ++i){
	 	scanf("%d",data+i);
	 } 
	 mergesort(data,0,n-1);

	 for (int i = 0; i < n; ++i){
	 	printf("%d\n",data[i] );
	 }
}
	 
void mergesort(a,i,j){
	int a[],i,j;
	if(i>=j)
	 	return;
	else{
	 	mid=(i+j+1)/2; // imp
	 	mergesort(a,i,mid-1);
	 	mergesort(a,mid,j);
	 	merge(a,i,j);
	}
}

merge(a,i,j)
int a[],i,j;
{
	int k,b[100],mid,start,l;
	start =i;
	mid=(i+j)/2;
	k=mid+1;
	l=i;

	while(i<=mid && k<=j){
		if(a[i]>=a[k]){
			b[l++]=a[k++];
		else
		b[l++]=a[k++];	
		}
		if(i>mid){
			for (;k<=j;)
			{
				b[l++]=a[k++];
			}
		}
		else
			if(k>j){
				for (; i<=mid;)
				{
					b[l++]=a[i++];
				}
			}
		for (l=start; l <= j; l++)
			{
				a[l]=b[l];
			}	
	}
}