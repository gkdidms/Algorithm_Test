//https://www.acmicpc.net/problem/14728
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n = 0, t = 0; // 이번 시험의 단원 개수, 시험까지 공부할 수 있는 총 시간
	cin >> n >> t;

	vector<pair<int, int>> ks(n + 1);

	for (int _ = 1; _ < n + 1; ++_)
	{
		cin >> ks[_].first >> ks[_].second; // 예상 공부시간, 배점
	}

	vector<vector<int>> dp(n + 1, vector<int>(t + 1));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= t; ++j)
		{
			if (ks[i].first > j)
				dp[i][j] = dp[i - 1][j];
			else
			{
				dp[i][j] = max(dp[i - 1][j], ks[i].second + dp[i - 1][j - ks[i].first]);
			}
		}
	}

	cout << dp[n][t] << endl;

}