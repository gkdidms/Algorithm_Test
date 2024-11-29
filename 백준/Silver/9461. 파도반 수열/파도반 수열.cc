#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

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

		if (n == 1 || n == 2 || n == 3)
		{
			cout << 1 << '\n';
			continue;
		}

		vector<long long> dp(n + 1);

		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;

		for (int i = 4; i <= n; ++i)
			dp[i] = dp[i - 2] + dp[i - 3];

		cout << dp[n] << '\n';
	}
}