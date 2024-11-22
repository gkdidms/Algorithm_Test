#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF int(1e9)

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<vector<int>> graph;
int roads[101][101][101][101];
vector<pair<int, int>> cows;

int n, m, r; 

int bfs(pair<int, int> pos, int x)
{
	vector<vector<int>> visible(graph);

	priority_queue<pair<int, int>> q;
	q.push(pos);
	visible[pos.first][pos.second] = 1;

	int answer = 0;
	while (!q.empty())
	{
		pair<int, int> cowPos = q.top();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = cowPos.first + dx[i];
			int y = cowPos.second + dy[i];


			if (x < 0 || x >= n || y < 0 || y >= n)
				continue;

			//다리 확인
			if (roads[cowPos.first][cowPos.second][x][y] || roads[x][y][cowPos.first][cowPos.second])
				continue;

			//가지 않은 길일때 + 1
			if (visible[x][y] == 0)
			{
				visible[x][y] = 1;
				q.push({ x, y });
			}
		}
	}

	for (int i = x; i < m; ++i)
		if (visible[cows[i].first][cows[i].second] == 0) answer++;

	return answer;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m >> r;
	graph.resize(n, vector<int>(n));

	for (int i = 0; i < r; ++i)
	{
		int r1, c1, r2, c2;

		cin >> r1 >> c1 >> r2 >> c2;

		roads[r1 - 1][c1 - 1][r2 - 1][c2 - 1] = 1;
		roads[r2 - 1][c2 - 1][r1 - 1][c1 - 1] = 1;
	}

	for (int j = 0; j < m; ++j)
	{
		int r, c;
		cin >> r >> c;

		cows.push_back({ r - 1, c - 1});
	}

	int answer = 0;
	for (int i = 0; i < m; ++i)
	{
		answer += bfs(cows[i], i + 1);
	}

	cout << answer;
}