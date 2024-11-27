#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>


using namespace std;

int dp[3][31][1001]; // dp[현재 위치][남은 이동 횟수][현재 시간] = 현재 가진 최대 자두 개수

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t, w;

	cin >> t >> w;

	vector<int> v(t+1);
	for (int i = 1; i <= t; ++i)
	{
		cin >> v[i];
	}

	memset(dp, -1, sizeof(dp));
		

	dp[1][w][0] = 0;

	for (int time = 0; time < t; ++time)
	{
		for (int cnt = 0; cnt <= w; ++cnt)
		{
			for (int pos = 1; pos <= 2; ++pos)
			{
				if (dp[pos][cnt][time] >= 0)
				{
					int nextPos = v[time + 1];

					//자두가 떨어짐
					if (pos == nextPos)
					{
						dp[pos][cnt][time + 1] = dp[pos][cnt][time] + 1;
					}
					else // 현재 위치에 자두가 떨어지지 않음.
					{
						//움직여서 자두를 줍는 경우
						if (cnt != 0)
						{
							dp[nextPos][cnt - 1][time + 1] = max(dp[nextPos][cnt - 1][time + 1], dp[pos][cnt][time] + 1);
						}
						dp[pos][cnt][time + 1] = dp[pos][cnt][time];
					}
				}
			}
		}
	}

	int result = 0;

	for (int pos = 1; pos <= 2; ++pos)
	{
		for (int time = 1; time <= t; ++time)
			result = max(result, dp[pos][0][time]);
		for (int i = 0; i <= w; ++i)
			result = max(result, dp[pos][i][t]);
	}

	cout << result;
}