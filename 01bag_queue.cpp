#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Knapsack {
private:
    int capacity;
    vector<int> weights;
    vector<int> values;
    vector<int> bestItems;
    int bestValue;

public:
    Knapsack(int cap, const vector<int>& w, const vector<int>& v) : capacity(cap), weights(w), values(v), bestValue(0) {}

    pair<int, vector<int>> solve() {
        queue<pair<int, pair<int, vector<int>>>> nodes; // (index, (currentCapacity, currentItems))
        nodes.push({0, {capacity, vector<int>(weights.size(), 0)}});

        while (!nodes.empty()) {
            auto [index, state] = nodes.front();
            nodes.pop();

            int currentCapacity = state.first;
            vector<int> currentItems = state.second;

            if (index == weights.size() || currentCapacity == 0) {
                int currentValue = 0;
                for (int i = 0; i < currentItems.size(); ++i) {
                    if (currentItems[i] == 1) {
                        currentValue += values[i];
                    }
                }
                if (currentValue > bestValue) {
                    bestValue = currentValue;
                    bestItems = currentItems;
                }
                continue;
            }

            if (currentCapacity >= weights[index]) {
                currentItems[index] = 1;
                nodes.push({index + 1, {currentCapacity - weights[index], currentItems}});
            }

            currentItems[index] = 0;
            nodes.push({index + 1, {currentCapacity, currentItems}});
        }

        return {bestValue, bestItems};
    }
};

int main() {
    cout << "2125120058申顺琦\n";
    int capacity = 10;
    vector<int> weights = {2, 5, 4, 2};
    vector<int> values = {6, 3, 5, 4};

    Knapsack knapsack(capacity, weights, values);
    auto result = knapsack.solve();

    cout << "背包的最高价值为: " << result.first << endl;
    cout << "放入物品为: ";
    for (int item : result.second) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
