#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
int w = 12;//globle variable
void fun(int **b1) {
	cout<<"address of b1 "<<&b1<<endl;//8. print address of b1
	cout<<"b1 is "<<b1<<endl;//9. print value at b1,which is value at c,which is location of b
	cout<<"*b1 is "<<*b1<<endl;//10. print value of b,which is location of a  
	cout<<"**b1 is "<<**b1<<endl;// 11. print value of a
	cout<<endl;
	
	cout<<"address of w is: "<<&w<<endl;//12. print address of w
	cout<<endl;
	*b1 = &w;//13. memory location of a is changed to memory location of w in b 
	cout<<"b1 is "<<b1<<endl;//14. print value at b1,which is value at c,which is location of b 
	cout<<"*b1 is "<<*b1<<endl;//15. print value of b,which is memory location of w
	cout<<"**b1 is "<<**b1<<endl;//16. print value at w
	
}

int main(){
	int a = 5;// 1. a assign 5
	int* b = &a;//2. b is pointer to integer,assign memory location of a 
	int** c=&b;//3. c is pointer to pointer,assign memory location of b

	cout<<"a is "<<a<<endl;// 4. print value at a
	cout<<"b is "<<b<<endl;// 5. print value at b
	cout<<"*b is "<<*b<<endl;//6. print value at a
	cout<<"c is "<<c<<endl;// 7. print memory location of b,which is value at c
	
	cout<<endl;
	fun(c);
	cout<<endl;

	cout<<"a is "<<a<<endl;//17. print value at a
	cout<<"b is "<<b<<endl;//18. print value at b
	cout<<"*b is "<<*b<<endl;//19. print value at w 
	
	

	return 0;
}

