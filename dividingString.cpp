#include <iostream>
#include <string>

using namespace std;
int main ()
{
	int i,j,k=0,m=0;
    string name;

    cout << "Please, enter your full name: ";
    getline (cin,name);
    cout << name<< endl;
   
  	char temp[name.size()];
  	for(i=0;i<=(name.size());++i){
  		if(i!= name.size() && name[i]!=' '){
  			temp[m++]=name[i];
  		}
  		else {
  			temp[m]='\0';
  			printf("%s\n",temp);
  			m=0;
  		}
  	}
}