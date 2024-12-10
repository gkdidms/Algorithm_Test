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

    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(10));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            if (j == 0)
                dp[i][0] = 1;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
        }
            
    }
       
    int answer = 0;
    for (int i = 0; i <= 9; ++i)
        answer += dp[n][i];

    cout << answer % 10007;
}