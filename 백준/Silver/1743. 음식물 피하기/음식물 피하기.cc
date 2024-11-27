#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int n, m, k, answer = 0;

vector<vector<int>> graph;
vector<vector<bool>> visible;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y)
{
	priority_queue<pair<int, int>> q;
	q.push({ x, y });
	
	int cnt = 0;
	while (!q.empty())
	{
		int xx = q.top().first;
		int yy = q.top().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visible[nx][ny] || graph[nx][ny] != 1)
				continue;

			visible[nx][ny] = true;
			q.push({ nx, ny });
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	format;

	cin >> n >> m >> k;
	graph.resize(n, vector<int>(m));
	visible.resize(n, vector<bool>(m));

	for (int i = 0; i < k; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a - 1][b - 1] = 1;
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visible[i][j] && graph[i][j] == 1)
				answer = max(answer, bfs(i, j));
		}
	}

	cout << answer;
}