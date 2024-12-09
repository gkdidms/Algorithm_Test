#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;
vector<string> graph;
vector<vector<bool>> visible;
vector<vector<int>> visiBoard;
vector<bool> selected;

int cnt_s = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

//인접한지 확인
bool bfs()
{
	queue<pair<int, int>> q;
	for (int i = 0; i < 25; ++i)
		if (selected[i]) visiBoard[i / 5][i % 5] = 1;

	int cnt = 0;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (visiBoard[i][j] && !visible[i][j])
			{
				cnt++;

				if (graph[i][j] == 'S') cnt_s++;

				visible[i][j] = true;
				q.push({ i, j });

				while (!q.empty())
				{
					pair<int, int> node = q.front();
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						int nx = node.first + dx[i];
						int ny = node.second + dy[i];

						if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visiBoard[nx][ny] == 0 || visible[nx][ny]) continue;

						visible[nx][ny] = true;
						if (graph[nx][ny] == 'S') cnt_s++;

						q.push({ nx,ny });

					}
				}
			}

			if (cnt > 1) return false;
		}
	}

	if (cnt == 1) return true;
	return false;
}

void init()
{
	visiBoard.clear();
	visiBoard.resize(5, vector<int>(5));

	visible.clear();
	visible.resize(5, vector<bool>(5));
}

int answer = 0;
//조합 7개
void check(int cnt, int idx)
{
	if (cnt == 7)
	{
		cnt_s = 0;

		if (bfs())
		{
			if (cnt_s >= 4) answer++;
		}

		init();
		return;
	}

	for (int i = idx; i < 25; ++i)
	{
		if (!selected[i])
		{
			selected[i] = true;
			check(cnt + 1, i);
			selected[i] = false;
		}

	}
}

int main()
{
	format;

	graph.resize(5);
	selected.resize(25);
	init();
	for (int i = 0; i < 5; ++i)
	{
		cin >> graph[i];
	}


	check(0, 0);

	cout << answer;
}