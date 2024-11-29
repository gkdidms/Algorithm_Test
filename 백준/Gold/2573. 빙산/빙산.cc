#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;
int dx[4] = { -1,1 ,0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;
vector<vector<int>> graph;
vector<vector<bool>> visible;

int cnt_ice(int x, int y)
{
	if (visible[x][y] || graph[x][y] <= 0) return 0;

	queue<pair<int, int>> q;
	q.push({ x,y });
	visible[x][y] = 1;

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visible[nx][ny]) continue;

			if (graph[nx][ny] > 0)
			{
				visible[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	return 1;
}

void update_ice()
{
	vector<vector<int>> math_graph(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (graph[i][j] <= 0) continue;

			for (int k = 0; k < 4; ++k)
			{
				int x = i + dx[k];
				int y = j + dy[k];

				if (x < 0 || x >= n || y < 0 || y >= m) continue;

				if (graph[x][y] == 0)
					math_graph[i][j]++;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			graph[i][j] -= math_graph[i][j];
			if (graph[i][j] < 0)
				graph[i][j] = 0;
		}
			
	}
}


int roof_ice()
{
	int time = 0;

	while (true)
	{
		update_ice();

		time++;

		visible.clear();
		visible.resize(n, vector<bool>(m));

		int cnt = 0;
		int allCnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cnt += cnt_ice(i, j);
				if (graph[i][j] > 0) allCnt++;
			}
				
		}

		if (cnt >= 2) return time;
		else if (allCnt == 0) return 0;
	}
}

int main()
{
	format;

	cin >> n >> m;

	graph.resize(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> graph[i][j];
	}

	cout << roof_ice();
}