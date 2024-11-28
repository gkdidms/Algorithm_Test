#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int main()
{
	format;
	int n;
	cin >> n;

	vector<vector<int>> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		v[i].resize(i + 1);
		for (int j = 0; j < i; ++j)
			cin >> v[i][j];
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	dp[1][0] = v[1][0];

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			dp[i][j - 1] = max(dp[i][j - 1], v[i][j - 1] + dp[i - 1][j - 1]);
			dp[i][j] = max(dp[i][j], v[i][j] + dp[i - 1][j - 1]);

		}
	}

	int answer = 0;
	for (int i = 0; i < n; ++i)
		answer = max(answer, dp[n][i]);

	cout << answer;
}