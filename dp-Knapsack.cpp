#include <iostream>
#include <vector>

using namespace std;

int dp[1000];

int knapsack(int totalWeigth, vector<int>& weight, vector<int>& value) {
    int& res = dp[totalWeigth];
    if(res == -1) {
        if(totalWeigth == 0) {
            res = 0;
        }
        else{
            for(int i=0; i<weight.size(); ++i) {
                if(totalWeigth-weight[i] >= 0){
                    res = max(value[i] + knapsack(totalWeigth-weight[i], weight, value), 
                    knapsack(totalWeigth-weight[i], weight, value));
                }
            }
        }    
    }
    return res;
}

int main() {
    vector<int> weight, value;
    int totalWeigth;

    memset(dp, -1, sizeof(dp));

    totalWeigth = 100;
    weight.push_back(1); weight.push_back(50);    
    value.push_back(1); value.push_back(30);

    // totalWeigth = 8;
    // weight.push_back(1); weight.push_back(3); weight.push_back(4); weight.push_back(5);
    // value.push_back(10); value.push_back(40); value.push_back(50); value.push_back(70);


    cout << knapsack(totalWeigth, weight, value) << endl;

    return 0;
}