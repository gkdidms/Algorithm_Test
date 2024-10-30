//https://www.acmicpc.net/problem/1043
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)

using namespace std;

int n, m;
vector<vector<int>> graph;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;
	cin >> m;

	graph.resize(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a][b] = min(graph[a][b], c);
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i == j) continue;

				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (graph[i][j] == INF)
				cout << 0 << " ";
			else
				cout << graph[i][j] << " ";
		}

		cout << '\n';
	}

}