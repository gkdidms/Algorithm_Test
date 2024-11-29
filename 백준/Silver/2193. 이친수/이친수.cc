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

	int n;
	cin >> n;

	vector<long long> dp(n + 1);

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n];
}