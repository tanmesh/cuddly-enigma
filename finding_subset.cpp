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
vector< vector <int> > subset;

void F(int id,vector<int>& A,vector<int> tmp){
	if(id == A.size()){
		subset.push_back(tmp);
		return;
	}
	F(id+1,A,tmp);
	tmp.push_back(A[id]);
	F(id+1,A,tmp);
}

int main() {
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;++i) cin>>A[i];

	vector<int> tmp;
	F(0,A,tmp);

	for(int i=0;i<subset.size();++i){
		for(int j=0;j<subset[i].size();++j){
			cout << subset[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}