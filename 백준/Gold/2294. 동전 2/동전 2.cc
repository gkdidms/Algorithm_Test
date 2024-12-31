#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    vector<int> dp(k + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = v[i]; j <= k; ++j)
        {
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }

    if (dp[k] == INF)
        cout << -1;
    else
        cout << dp[k];
}