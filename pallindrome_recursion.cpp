#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

bool check(vector<int> a){
	if(a.size() == 1 || a.size() == 0){
		return true;
	}
	
	if(a[0] == a[a.size()-1]){
		vector<int> b;
		for(int i=1;i<a.size()-1;++i){
			b.push_back(a[i]);
		}
		return check(b);
	}	
	
	return false;
}
int main(){

	int n;
	cin >> n;
	vector<int> a;
	int tmp=n;
	while(tmp>0){
		int last_digit=tmp%10;
		a.push_back(last_digit);
		tmp/=10;
	}
	if(check(a)){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
	return 0;
}
