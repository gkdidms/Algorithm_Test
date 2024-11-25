#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF int(1e9);
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; ++_)
	{
		int n;
		cin >> n;

		vector<int> v(n + 1);
		vector<int> sum(501);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
			sum[i] = sum[i - 1] + v[i];
		}
			

		vector<vector<int>> dp(501, vector<int>(501));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n - i; ++j)
			{
				dp[j][i + j] = INF;

				for (int k = j; k < i + j; ++k)
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][n] << endl;
	}
}