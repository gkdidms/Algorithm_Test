#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main()
{
	format;

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<long long> dp(1000001);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 1; i <= n; ++i)
		{
			if (i == 1) dp[1] = 1;
			else if (i == 2) dp[2] = 2;
			else if (i == 3) dp[3] = 4;
			else
				dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

			dp[i] %= 1000000009;
		}

		cout << dp[n] % 1000000009 << '\n';
	}
}