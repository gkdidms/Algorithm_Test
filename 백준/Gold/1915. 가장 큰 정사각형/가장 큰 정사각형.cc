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

    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n + 1, vector<char>(m + 1));
    
    for (int i = 1; i <= n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; ++j)
        {
            v[i][j] = str[j - 1];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (v[i][j] == '1')
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            else
                dp[i][j] = 0;
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            answer = max(answer, dp[i][j]);
    }

    cout << answer * answer;
}