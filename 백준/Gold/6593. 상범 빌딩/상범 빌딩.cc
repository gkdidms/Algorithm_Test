#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int df[6] = { 0, 0, 0, 0, -1, 1 };

int l, r, c;
vector<vector<vector<char>>> graph;

void bfs(pair<int, pair<int, int>> startPos)
{
	vector<vector<vector<bool>>> visible(31, vector<vector<bool>>(31, vector<bool>(31)));
	queue < pair<int, pair<int, pair<int, int>>>> q;
	visible[startPos.first][startPos.second.first][startPos.second.second] = true;
	q.push({ 0, startPos });

	while (!q.empty())
	{
		int cnt = q.front().first;
		int f = q.front().second.first;
		int x = q.front().second.second.first;
		int y = q.front().second.second.second;
		q.pop();

		if (graph[f][x][y] == 'E')
		{
			cout << "Escaped in " << cnt << " minute(s)." << '\n';
			return;
		}

		for (int i = 0; i < 6; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nf = f + df[i];

			if (nf < 0 || nf >= l || nx < 0 || nx >= r || ny < 0 || ny >= c || visible[nf][nx][ny] || graph[nf][nx][ny] == '#')
				continue;

			visible[nf][nx][ny] = true;
			q.push({ cnt + 1, { nf, {nx, ny} } });
		}
	}

	cout << "Trapped!" << '\n';
}

int main()
{
	format;

	while (true)
	{
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0)
			break;

		pair<int, pair<int, int>> startPos;
		pair<int, pair<int, int>> gollPos;

		graph.resize(31, vector<vector<char>>(31, vector<char>(31)));
		for (int i = 0; i < l; ++i)
		{
			for (int j = 0; j < r; ++j)
			{
				string str;
				cin >> str;

				for (int k = 0; k < c; ++k)
				{
					graph[i][j][k] = str[k];

					if (graph[i][j][k] == 'S')
						startPos = { i, {j, k} };
				}
			}
		}

		bfs(startPos);
	}
}