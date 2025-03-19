#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <list>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

struct node {
	int x, y;
};

int n, l, r;
vector<vector<int>> v;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int start_x, int start_y, vector<vector<int>>& alliance, vector<vector<bool>>& visible)
{
	if (visible[start_x][start_y] || !alliance[start_x][start_y]) return;

	vector<node> check_visible;
	queue<node> q;
	q.push({ start_x, start_y });

	visible[start_x][start_y] = true;
	check_visible.push_back({ start_x, start_y });

	int sum = v[start_x][start_y];
	int cnt = 1;

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = cur.x + dx[i];
			int y = cur.y + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= n || visible[x][y] || alliance[x][y] != alliance[start_x][start_y]) continue;

			visible[x][y] = true;
			check_visible.push_back({ x,y });
			sum += v[x][y];
			cnt++;

			q.push({ x, y });
		}
	}

	int avg = sum / cnt;
	for (auto pos : check_visible)
	{
		v[pos.x][pos.y] = avg;
	}
}

void find_alliance(int cur_x, int cur_y, int cnt, vector<vector<int>>& alliance, vector<vector<bool>>& visible)
{
	if (visible[cur_x][cur_y]) return;

	visible[cur_x][cur_y] = true;

	for (int i = 0; i < 4; ++i)
	{
		int x = cur_x + dx[i];
		int y = cur_y + dy[i];

		if (x < 0 || x >= n || y < 0 || y >= n || visible[x][y]) continue;

		int temp = abs(v[cur_x][cur_y] - v[x][y]);

		if (temp >= l && temp <= r)
		{
			alliance[cur_x][cur_y] = cnt;
			alliance[x][y] = cnt;
			find_alliance(x, y, cnt, alliance, visible);
		}
	}
}

bool check_alliance(vector<vector<int>>& visible)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (visible[i][j] != 0) return true;
		}
	}

	return false;
}

int main()
{
	format;
	
	cin >> n >> l >> r;

	v.resize(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
	}

	int answer = 0;
	while (true)
	{
		vector<vector<int>> visible(n, vector<int>(n));
		vector<vector<bool>> check(n, vector<bool>(n));
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!check[i][j])
				{
					cnt++;
					find_alliance(i, j, cnt, visible, check);
				}
			}
				
		}

		if (!check_alliance(visible)) break;

		check.clear();
		check.resize(n, vector<bool>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				bfs(i, j, visible, check);
		}

		answer++;
	}

	cout << answer;
}