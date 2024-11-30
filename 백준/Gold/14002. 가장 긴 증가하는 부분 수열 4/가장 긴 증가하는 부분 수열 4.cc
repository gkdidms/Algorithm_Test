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

	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	
	vector<int> dp(n + 1);
	int cnt = 1;
	for (int i = 1; i <= n; ++i) // 현재 수
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; --j) // 현재 비교해야 하는 수의 이전 값들
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);

				cnt = max(cnt, dp[i]);
			}
		}
	}

	cout << cnt << '\n';

	vector<int> anw;
	int preInt = INF;
	for (int i = n; i > 0 ; --i)
	{
		int answer = 0;
		if (dp[i] == cnt && preInt > v[i])
		{
			answer = max(answer, v[i]);

			cnt--;
			preInt = answer;
			anw.push_back(answer);
		}
	}

	sort(anw.begin(), anw.end());

	for (auto a : anw)
		cout << a << " ";
	
}