#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n;
vector<vector<int>> graph;
vector<vector<bool>> visible;

int bfs(int startX, int startY, int height)
{
	if (visible[startX][startY] || graph[startX][startY] <= height) return 0;

	queue<pair<int,int>> q;
	q.push({startX, startY});
	visible[startX][startY] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visible[nx][ny]) continue;

			if (graph[nx][ny] > height)
			{
				visible[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	return 1;
}

int main()
{
	format;

	cin >> n;
	
	graph.resize(n, vector<int>(n));
	

	int maxInt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
			maxInt = max(maxInt, graph[i][j]);
		}
	}

	int answer = 0;
	for (int i = 0; i < maxInt; ++i)
	{
		visible.clear();
		visible.resize(n, vector<bool>(n));

		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
				cnt += bfs(j, k, i);
		}

		answer = max(answer, cnt);
	}
		

	cout << answer << endl;
}