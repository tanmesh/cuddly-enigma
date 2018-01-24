#include <iostream>
#include <vector>

using namespace std;

int dp[100];

int knapsack(int i, vector<int> &weight, vector<int> &value, int& maxWeight) {
    int &res = dp[i];
    if(res == -1) {
        if(i == weight.size()) {
            res = 0;
        }
        else{
            int tmp = 0;
            for(int j=0; j<=i; ++i) {
                tmp += weight[j];
            }
            if(tmp > maxWeight) {
                res = 0;
            }
            else{
                int newWeight = maxWeight-value[i];
                res = max(knapsack(i+1, weight, value, maxWeight), value[i] + knapsack(i+1, weight, value, newWeight));
            }
        }
        // dont choose ith 
        // int amtWithoutIth = knapsack(i+1, weight, value, maxWeight);
        // choose ith
        // int amtWithIth = knapsack(i+1, weight, value, maxWeight-value[i]);
    }

    return res;
}

int main() {
    vector<int> weight, value;
    int maxWeight;

    int n;
    cin >> n;
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
    cin >> maxWeight;
    cout << knapsack(0, weight, value, maxWeight) << endl;

    return 0;
}