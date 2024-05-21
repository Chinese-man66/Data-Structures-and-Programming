#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SteelRodCutter {
public:
    SteelRodCutter(const vector<int>& prices) : prices(prices) {}

    pair<int, vector<int>> cutRod(int length) {
        int n = prices.size();
        dp.resize(length + 1, 0);
        cuts.resize(length + 1);

        for (int i = 1; i <= length; ++i) {
            int max_val = INT_MIN;
            for (int j = 1; j <= min(i, n - 1); ++j) {
                if (prices[j] + dp[i - j] > max_val) {
                    max_val = prices[j] + dp[i - j];
                    cuts[i] = cuts[i - j];
                    cuts[i].push_back(j);
                }
            }
            dp[i] = max_val;
        }

        return {dp[length], cuts[length]};
    }
private:
    vector<int> prices;
    vector<int> dp;
    vector<vector<int>> cuts;
};

int main() {
    int length;
    cout << "2125120058申顺琦\n";
    cout << "请输入钢条的长度(不超过10英寸): ";
    cin >> length;

    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    SteelRodCutter cutter(prices);
    auto result = cutter.cutRod(length);

    cout << "钢条切割最大收益为: " << result.first << endl;
    cout << "最佳切割方式：" << endl;
    for (int cut : result.second) {
        cout << cut << endl;
    }

    return 0;
}
