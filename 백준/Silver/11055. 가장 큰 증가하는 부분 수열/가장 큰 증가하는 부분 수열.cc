#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	vector<int> dp(1001);

	int maxInt = 0;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = v[i];
		for (int j = 1; j < i; ++j)
		{
			if (dp[j] < dp[i] && dp[i] < dp[j] + v[i])
				dp[i] = dp[j] + v[i];
		}
		if (maxInt < dp[i]) maxInt = dp[i]; 
	}

	cout << maxInt;
}