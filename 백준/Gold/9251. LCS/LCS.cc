#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string str1, str2;

    cin >> str1 >> str2;

    vector<vector<int>> dp(1001, vector<int>(1001));

    for (int i = 1; i <= str1.size(); ++i)
    {
        for (int j = 1; j <= str2.size(); ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[str1.size()][str2.size()] << endl;

}