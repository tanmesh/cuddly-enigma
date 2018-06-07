#include <iostream>
#include <vector>

using namespace std;

int dp[100];

int lis(int i, vector<int> &arr) {
    int &res = dp[i];
    if(res == -1) {
        res = 0;
        if(i == 0) {
            res = 1;
        }
        else{
            for(int j=0; j<i; ++j) {
                if(arr[j] < arr[i]) {
                    res = max(lis(j, arr)+1, res);
                }
            }
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
 
    while(t--) {
        int n;
        cin >> n;

        memset(dp, -1, sizeof(dp));

        vector<int> arr;
        for(int i=0; i<n; ++i) {
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }

        cout << lis(n-1, arr) << endl;
    }
    
    return 0;
}