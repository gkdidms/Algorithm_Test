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

	string v;
	cin >> v;

	if (v[0] == '0')
	{
		cout << 0;
		return 0;
	}

	vector<int> dp(v.size() + 1);
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= v.size(); ++i)
	{
		if (v[i - 1] != '0') dp[i] = dp[i - 1] % INT;

		int temp = (v[i - 2] - '0') * 10 + (v[i - 1] - '0');
		if (temp >= 10 && temp <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % INT;
	}

	cout << dp[v.size()];
}