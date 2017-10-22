#include <iostream>
#include <vector>
using namespace std;

vector< vector< int > > ans;

void generateSubset(int i, vector<int> a, vector<int> curr_subset) {
	if(i==a.size()) {
		ans.push_back(curr_subset);
		return;
	}
	
	// taking a[i] in the present subset
	curr_subset.push_back(a[i]); 
	generateSubset(i+1, a, curr_subset);

	// ignoring a[i] in the present subset
	curr_subset.pop_back(); 
	generateSubset(i+1, a, curr_subset);	
}

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	vector<int> curr_subset;
	generateSubset(0, a, curr_subset);

	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size(); ++i){
		cout << "{ ";
		for(int j=0;j<ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout << "}";
		cout<<endl;
	}
	return 0;
}