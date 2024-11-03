//https://www.acmicpc.net/problem/1504
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)
using namespace std;

int n, m;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<vector<int>> graph;
vector<vector<vector<int>>> visible;
int answer = INF;
void bfs()
{
	priority_queue<pair<int, pair< int, pair<int, int>>>> q;
	q.push({ -1, {0 ,{0, 0}} });
	visible[0][0][0] = true;

	while (!q.empty())
	{
		int count = -q.top().first;

		int wall = q.top().second.first;
		pair<int, int> pos = q.top().second.second;
		q.pop();

		if (pos.first == n - 1 && pos.second == m - 1)
		{
			answer = count;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int x = pos.first + dx[i];
			int y = pos.second + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;

			if (graph[x][y] == 0 && !visible[wall][x][y])
			{
				visible[wall][x][y] = true;
				q.push({ -(count + 1), {wall, {x, y}} });
			}
			if (graph[x][y] == 1 && wall == 0 && !visible[1][x][y])
			{
				visible[1][x][y] = true;
				q.push({ -(count + 1), {1, {x, y}} });
			}
		}
	}

	answer = -1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;
	graph.resize(n);
	visible.resize(2, vector<vector<int>>(n, vector<int>(m)));

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (auto a : str)
		{
			graph[i].push_back(a - 48);
		}
	}

	bfs();

	cout << answer << endl;
}