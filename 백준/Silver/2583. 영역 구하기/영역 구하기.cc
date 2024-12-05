#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

struct pos {
	int x1, y1, x2, y2;
};

vector<vector<int>> graph;
int m, n, k;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<vector<bool>> visible;

int bfs(int startX, int startY)
{
	if (visible[startX][startY] || graph[startX][startY] == 1)
		return -1;

	queue< pair<int, int>> q;
	q.push({startX, startY });
	visible[startX][startY] = true;

	int anw = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || visible[nx][ny] || graph[nx][ny] == 1)
				continue;

			visible[nx][ny] = true;
			anw++;
			q.push({nx, ny});
		}
	}

	return anw;
}

int main()
{
	format;


	cin >> m >> n >> k;

	graph.resize(m, vector<int>(n));
	visible.resize(m, vector<bool>(n));

	vector<pos> boxs;
	for (int i = 0; i < k; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		boxs.push_back({ x1, y1, x2, y2 });
	}

	for (auto p : boxs)
	{
		for (int i = p.x1; i < p.x2; ++i)
		{
			for (int j = p.y1; j < p.y2; ++j)
				graph[j][i] = 1;
		}
	}



	vector<int> anwList;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int answer = bfs(i, j);

			if (answer != -1)
				anwList.push_back(answer);
		}
	}

	cout << anwList.size() << '\n';
	sort(anwList.begin(), anwList.end());
	for (auto a : anwList)
		cout << a << " ";
}