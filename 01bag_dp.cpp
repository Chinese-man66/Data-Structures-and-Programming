#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Knapsack {
public:
    pair<int, vector<int>> solve(int capacity, const vector<int>& weights, const vector<int>& values) {
        int n = weights.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= capacity; ++j) {
                if (weights[i - 1] <= j) {
                    dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        vector<int> items(n, 0);
        int i = n, j = capacity;
        while (i > 0 && j > 0) {
            if (dp[i][j] != dp[i - 1][j]) {
                items[i - 1] = 1;
                j -= weights[i - 1];
            }
            --i;
        }

        return {dp[n][capacity], items};
    }
};

int main() {
    cout << "2125120058申顺琦\n";
    
    int capacity = 10;
    vector<int> weights = {2, 2, 6, 5, 4};
    vector<int> values = {6, 3, 5, 4, 6};

    Knapsack knapsack;
    auto result = knapsack.solve(capacity, weights, values);

    cout << "背包最高价值为: " << result.first << endl;
    cout << "放入物品: ";
    for (auto item : result.second)
        cout << item << " ";
    cout << endl;

    return 0;
}
