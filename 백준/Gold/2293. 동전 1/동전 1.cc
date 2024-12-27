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

	int n, k;

	cin >> n >> k;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	vector<int> dp(k + 1);
	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = v[i]; j <= k; ++j)
		{
			dp[j] += dp[j - v[i]];
		}
	}

	cout << dp[k];
}