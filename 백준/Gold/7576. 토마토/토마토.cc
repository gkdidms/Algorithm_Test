//https://www.acmicpc.net/problem/7576
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int answer = 0;

vector<vector<int>> graph;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };


void bfs()
{
	priority_queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (graph[i][j] == 1)
				q.push({ 0, { i, j } });
		}
	}

	int count = 0;
	while (!q.empty())
	{
		int dist = -q.top().first;
		pair<int, int> pos = q.top().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = pos.first + dx[i];
			int y = pos.second + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;

			if (graph[x][y] == 0)
			{
				graph[x][y] = graph[pos.first][pos.second] + 1;
				q.push({ -(dist + 1), {x, y} });
				count = max(count, dist + 1);
			}
		}
	}

	answer = count;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);


	cin >> m >> n;

	graph.resize(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> graph[i][j];
		}
	}

	bfs();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			if (graph[i][j] == 0)
				answer = -1;
	}

	cout << answer << endl;
}