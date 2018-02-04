#include <iostream>
#include <vector>

using namespace std;

int dp[2000];

int knapsack(int totalWeigth, vector<int>& weight, vector<int>& value) {
    int& res = dp[totalWeigth];
    if(res == -1) {
        if(totalWeigth <= 0) {
            res = 0;
        }
        else{
            int ans = 0;
            for(int i=0; i<weight.size(); ++i) {
                if(totalWeigth-weight[i] >= 0) {
                    int costWithIth = value[i] + knapsack(totalWeigth-weight[i], weight, value);
                    ans = max(ans, costWithIth);
                }
            }
            res = ans;
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

    cout << knapsack(totalWeigth, weight, value) << endl;

    return 0;
}