//https://www.acmicpc.net/problem/7569
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, h;
int answer = 0;
vector<vector<vector<int>>> box;

int dx[6] = { -1, 1, 0 , 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, -1, 1 };

void bfs()
{
	priority_queue<pair<int, pair<int, pair<int, int>>>> q;
	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (box[k][i][j] == 1)
					q.push({ 0, { k, {i, j} } });
			}
		}
	}

	while (!q.empty())
	{
		int dis = -q.top().first;
		int height = q.top().second.first;
		pair<int, int> pos = q.top().second.second;
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int nh = height + dh[i];
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nh < 0 || nh >= h)
				continue;

			if (box[nh][nx][ny] == 0)
			{
				box[nh][nx][ny] = dis + 1;
				q.push({ -(dis + 1), { nh, {nx, ny} } });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> m >> n >> h;

	box.resize(h, vector<vector<int>>(n, vector<int>(m)));

	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> box[k][i][j];
			}
		}
	}

	pair<bool, bool> check = { false, false };
	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (box[k][i][j] == 0) check.first = true;
			}
		}
	}

	if (check.first == false)
	{
		std::cout << 0 << endl;
		return 0;
	}

	bfs();

	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (box[k][i][j] == 0) check.second = true;
				answer = max(answer, box[k][i][j]);
			}
		}
	}

	if (check.second == true)
	{
		std::cout << -1 << endl;
	}
	else
	{
		std::cout << answer << endl;
	}
}