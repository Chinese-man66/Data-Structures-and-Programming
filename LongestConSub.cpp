#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LCS {

public:
    LCS(const string& s1, const string& s2) : str1(s1), str2(s2) {}

    pair<int, string> findLCS() {
        int m = str1.length();
        int n = str2.length();
        
        dp.resize(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string str;
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                str = str1[i - 1] + str;
                --i;
                --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                --i;
            } else {
                --j;
            }
        }

        return {dp[m][n], str};
    }
private:
    string str1;
    string str2;
    vector<vector<int>> dp;

};

int main() {
    cout << "2125120058申顺琦\n";
    string str1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    string str2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

    LCS lcs(str1, str2);
    auto result = lcs.findLCS();

    cout << "最长公共子序列长度为: " << result.first << endl;
    cout << "最长公共子序列为: " << result.second << endl;

    return 0;
}
