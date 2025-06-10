#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long

const ll INF = 1e15;

using namespace std;

int main() {
	FORMAT;

	int t;

	cin >> t;

	while (t--)
	{
		int n, p, q;
		cin >> n >> p >> q;

		vector<vector<ll>> graph(p+1, vector<ll>(p+1, INF));
		vector<int> people(n);

		for (int i = 0; i < n; ++i)
			cin >> people[i];

		for (int k = 0; k < q; ++k)
		{
			ll i, j, d;
			cin >> i >> j >> d;
			
			graph[i][j] = min(graph[i][j], d);
			graph[j][i] = min(graph[j][i], d);
		}

		for (int i = 1; i <= p; ++i)
		{
			graph[i][i] = 0;
		}

		for (int i = 1; i <= p; ++i)
		{
			for (int j = 1; j <= p; ++j)
			{
				for (int k = 1; k <= p; ++k)
				{
					if (graph[j][i] == INF || graph[i][k] == INF) continue;

					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
		}

		ll answer = INF;
		int idx = 0;
		for (int i = 1; i <= p; ++i)
		{
			ll sum = 0;
			bool isPass = true;
			for (auto a : people)
			{
				if (graph[a][i] == INF)
				{
					isPass = false;
					break;
				}
				sum += 1LL * graph[a][i] * graph[a][i];
			}
				
			if (!isPass) continue;

			if (answer > sum)
			{
				answer = sum;
				idx = i;
			}
		}

		cout << idx << " " << answer << '\n';
	}
}
