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

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    vector<int> dp(n + 1);
    dp[1] = p[1];
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            
            dp[i] = max(p[i], max(dp[i],dp[i - j] + dp[j]));
        }

    }

    cout << dp[n];
}