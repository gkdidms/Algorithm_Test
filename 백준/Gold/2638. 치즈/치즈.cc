#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;
int n, m;
pair<int, int> startPos;
vector<vector<int>> graph;
vector<vector<int>> visible;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs()
{
	priority_queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		int x = q.top().first;
		int y = q.top().second;
		q.pop();


		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (graph[nx][ny] == 0 && !visible[nx][ny])
			{
				visible[nx][ny] = 1;
				q.push({nx, ny});
			}
			else if (graph[nx][ny] == 1)
			{
				visible[nx][ny] += 1;
			}
		}
	}
}

void air()
{
	
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;

	graph.resize(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> graph[i][j];
		}
	}

	int time = 0;
	while (true)
	{
		visible.clear();
		visible.resize(n, vector<int>(m));

		bfs();

		time++;

		//치즈 업데이트
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (visible[i][j] >= 2)
					graph[i][j] = 0;
			}
		}

		bool isSuccess = true;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				if (graph[i][j] == 1) {
					isSuccess = false;
					break;
				}
		}

		if (isSuccess) break;
	}

	cout << time;
}