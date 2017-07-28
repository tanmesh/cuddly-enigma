#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int ver,e;
	cin >>  ver>> e;
	
	int graph[ver][ver];

	for(int i=0;i<ver;++i){
		for(int j=0;j<ver;++j){
			graph[i][j]=0;
		}
	}	

	int u,v;
	for(int i=0;i<e;++i){
		cin >> u >> v;
		graph[u][v]=1;
		graph[v][u]=1;
	}

	for(int i=0;i<ver;++i){
		for(int j=0;j<ver;++j){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}





