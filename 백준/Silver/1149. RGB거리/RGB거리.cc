//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

vector<vector<int>> RGB;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;

	RGB.resize(n + 1, vector<int>(3));
	for (int i = 1; i <= n; ++i)
	{
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}

	vector<vector<int>> dp(n + 1, vector<int>(3));
	dp[1] = RGB[1];
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1] + RGB[i][j];
				dp[i][j] = min(dp[i][j], dp[i - 1][j + 2] + RGB[i][j]);
			}
				
			else if (j == 1)
			{
				dp[i][j] = dp[i - 1][j - 1] + RGB[i][j];
				dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + RGB[i][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + RGB[i][j];
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 2] + RGB[i][j]);
			}
				
		}
	}

	int answer = min(dp[n][0], min(dp[n][1], dp[n][2]));
	cout << answer << endl;
}