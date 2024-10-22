//https://www.acmicpc.net/problem/1535
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n = 0;
	cin >> n;

	vector<int> hp(n + 1);
	for (int i = 1; i < n + 1; ++i)
		cin >> hp[i];

	vector<int> fun(n + 1);
	for (int i = 1; i < n + 1; ++i)
		cin >> fun[i];

	
	vector<vector<int>> dp(n + 1, vector<int>(101));
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			if (hp[i] >= j)
				dp[i][j] = dp[i - 1][j];
			else
			{
				dp[i][j] = max(dp[i - 1][j], fun[i] + dp[i - 1][j - hp[i]]);
				
			}
		}
	}

	cout << dp[n][100] << endl;
}