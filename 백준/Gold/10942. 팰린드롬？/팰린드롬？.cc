#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> number;


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	vector<vector<int>> dp(2001, vector<int>(2001));
	
	for (int i = 0; i < n; ++i)
		dp[i][i] = true;

	for (int i = 0; i < n - 1; ++i)
	{
		if (v[i] == v[i + 1])
			dp[i][i + 1] = true;
	}

	for (int i = 2; i <= n - 1; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			int k = i + j;
			if ((v[j] == v[k]) && dp[j + 1][k - 1])
				dp[j][k] = true;
		}
	}
	
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		cout << dp[a - 1][b - 1] << '\n';
	}
}