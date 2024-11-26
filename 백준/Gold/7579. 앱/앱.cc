#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, M;
	cin >> n >> M;

	//활성화 되어있는 앱이 사용중인 바이트 수
	vector<int>m(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> m[i];

	//비활성화 했을 경우의 비용
	vector<int>c(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		sum += c[i];
	}
		

	vector<vector<int>> dp(101, vector<int>(10001));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j - c[i] >= 0)
				dp[i][j] = max(dp[i][j], m[i] + dp[i - 1][j - c[i]]);

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				
		}
	}

	for (int i = 0; i <= sum; ++i)
	{
		if (dp[n][i] >= M)
		{
			cout << i;
			break;
		}
	}

	
}