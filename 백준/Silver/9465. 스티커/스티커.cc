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

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> v(2, vector<int>(n + 1));
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 1; j <= n; ++j)
                cin >> v[i][j];
        }

        vector<vector<int>> dp(2, vector<int>(n + 1));
        dp[0][1] = v[0][1];
        dp[1][1] = v[1][1];
            
        for (int i = 2; i <= n; ++i)
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + v[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + v[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
}