#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main()
{
	format;

	int n;
	cin >> n;

	int m;
	cin >> m;

	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int answer = 1;
	int start = 0;
	
	vector<int> v(m);
	for (int i = 0; i < m; ++i)
	{
		int a;
		cin >> v[i];
	}

	for (int i = 0; i < m; ++i)
	{
		int end = v[i];
		answer = answer * dp[end - start - 1];
		start = end;
	}

	answer = answer * dp[n - start];

	cout << answer;
	

}