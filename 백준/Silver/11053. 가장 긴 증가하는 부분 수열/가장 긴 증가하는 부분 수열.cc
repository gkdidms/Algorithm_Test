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

	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	
	vector<int> dp(n + 1);
	
	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 1;

		for (int j = i - 1; j >= 1; --j)
		{
			if (v[i] > v[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;
}