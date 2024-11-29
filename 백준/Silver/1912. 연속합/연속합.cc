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

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int answer = v[0];
	vector<int> dp(n);
	dp[0] = v[0];

	for (int i = 1; i < n; ++i)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		answer = max(dp[i], answer);
	}

	cout << answer;
}	