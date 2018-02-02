#include <iostream>
#include <vector>

using namespace std;

int dp[1000][1000];

int knapsack(int i, int totalWeigth, vector<int>& weight, vector<int>& value) {
    int& res = dp[i][totalWeigth];
    if(res == -1) {
        if(totalWeigth == 0 || i == weight.size()) {
            res = 0;
        }
        else{
            if(totalWeigth > 0) {
                int costWithIth = value[i] + knapsack(i+1, totalWeigth-weight[i], weight, value);
                int costWithoutIth = knapsack(i+1, totalWeigth, weight, value);
                res = max(costWithIth, costWithoutIth);
            }
        }    
    }
    return res;
}

int main() {
    vector<int> weight, value;
    int totalWeigth, n;

    memset(dp, -1, sizeof(dp));

    cin >> n >> totalWeigth;

    for(int i=0; i<n; ++i) {
        int tmp;
        cin >> tmp;
        weight.push_back(tmp);
    }

    for(int i=0; i<n; ++i) {
        int tmp;
        cin >> tmp;
        value.push_back(tmp);
    }

    cout << knapsack(0, totalWeigth, weight, value) << endl;

    // for(int i=0; i<weight.size(); ++i) {
    //     for(int j=0; j<totalWeigth; ++j) {
    //         cout << dp[i][j] << endl;
    //     }
    // }
    return 0;
}