#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, m, d;
int startX, startY;
vector<vector<int>> graph;
vector<vector<bool>> visible;

int bfs()
{
	queue<pair<int, pair<int, int>>> q;
	q.push({ 1, { startX, startY } });
	visible[startX][startY] = true;
	graph[startX][startY] = 2;

	int answer = 0;
	while (!q.empty())
	{
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		// 주변에 청소가 되어 있는지 아닌지?
		// 반시계 방향으로 돌면서 체크
		int dir = d;
		bool isCheck = false;

		answer = cnt;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x, ny = y;
			if (dir == 0)
			{
				dir = 3;
				ny -= 1;
			}
			else if (dir == 1)
			{
				dir = 0;
				nx -= 1;
			}
			else if (dir == 2)
			{
				dir = 1;
				ny += 1;
			}
			else if (dir == 3)
			{
				dir = 2;
				nx += 1;
			}
			
			if (!visible[nx][ny] && graph[nx][ny] == 0)
			{
				graph[nx][ny] = 2;
				visible[nx][ny] = true;
				isCheck = true;
				d = dir;

				q.push({ cnt + 1, {nx,ny} });
				break;
			}
		}

		//주변에 청소할 공간이 없다면
		if (!isCheck)
		{
			if (dir == 0) x += 1;
			else if (dir == 1) y -= 1;
			else if (dir == 2) x -= 1;
			else if (dir == 3) y += 1;

			if (graph[x][y] != 1)
			{
				if (!visible[x][y])
				{
					q.push({ cnt + 1, {x, y } });
					visible[x][y] = true;
					graph[x][y] = 2;
				}
				else
					q.push({ cnt, {x, y } });
			}
			else
				return answer;
		}
	}

	return answer;
}

int main()
{
	format;
	cin >> n >> m;

	cin >> startX >> startY >> d;

	graph.resize(n, vector<int>(m));
	visible.resize(n, vector<bool>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> graph[i][j];
		}
	}
	
	cout << bfs();
}