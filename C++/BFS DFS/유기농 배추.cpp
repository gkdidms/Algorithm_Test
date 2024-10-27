//https://www.acmicpc.net/problem/1012
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
vector<vector<int>> graph;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool bfs(int x, int y)
{
	if (graph[x][y] == 0 || graph[x][y] > 1)
		return false;

	priority_queue<pair<int, int>> q;
	q.push({x, y});

	while (!q.empty())
	{
		pair<int, int> pos = q.top();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (graph[nx][ny] == 1)
			{
				graph[nx][ny] = graph[pos.first][pos.second] + 1;
				q.push({ nx, ny });
			}
		}
		
	}

	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t = 0;
	cin >> t;

	for (int cnt = 0; cnt < t; ++cnt)
	{
		cin >> m >> n >> k;

		graph.resize(n, vector<int>(m));

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;

			graph[y][x] = 1;
		}

		int answer = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (bfs(i, j))
					answer++;
			}
		}

		cout << answer << endl;

		graph.clear();
	}
}