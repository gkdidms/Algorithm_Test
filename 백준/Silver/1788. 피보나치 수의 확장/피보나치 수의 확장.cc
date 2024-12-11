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

    int n, sign = 1;
    cin >> n;

    if (n < 0) {
        n *= -1;
        if (n % 2 == 0) sign = -1;
    }
    if (n == 0)
    {
        cout << 0 << '\n' << 0;
    }
    else if (n == 1 || n == 2)
    {
        cout << sign << '\n' << 1;
    }
    else
    {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;

        cout << sign << '\n' << dp[n] % 1000000000;
    }

}