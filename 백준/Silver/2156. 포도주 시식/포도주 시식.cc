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

	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	vector<int> dp(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		if (i == 1)
			dp[i] = v[i];
		else if (i == 2)
			dp[2] = v[1] + v[2];
		else if (i == 3)
			dp[3] = max(dp[2], max(dp[1] + v[3], v[2] + v[3]));
		else
			dp[i] = max(dp[i - 1], max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]));
		
	}

	cout << dp[n];
}