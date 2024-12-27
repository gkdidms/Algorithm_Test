#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INT 1000000

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main()
{
	format;

	int n;
	cin >> n;

	vector<int> dp(n + 1);
	
	for (int i = 1; i <= n; ++i)
		dp[i] = i;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j * j <= i; ++j)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];
}