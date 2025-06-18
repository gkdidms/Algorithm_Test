#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long
#define INF int(1e9)
//const ll INF = 1e15;

using namespace std;

int r, c;
int answer = 0;
vector<vector<char>> map;
pair<int, int> pos;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void backtracking(int x, int y, int t, int cnt, vector<vector<vector<bool>>>& visible)
{
	if (t == 0)
	{
		answer = max(answer, cnt);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c || visible[nx][ny][t] || map[nx][ny] == '#') continue;

		visible[nx][ny][t-1] = true;
		if (map[nx][ny] == 'S') {
			map[nx][ny] = '.';
			backtracking(nx, ny, t - 1, cnt + 1, visible);
			map[nx][ny] = 'S';
		}
		else backtracking(nx, ny, t - 1, cnt, visible);
		visible[nx][ny][t - 1] = true;
	}
}

int main() {
	FORMAT;

	int t;
	cin >> r >> c >> t;

	map.resize(r, vector<char>(c));


	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == 'G')
				pos = { i,j };

			for (int k = t - 1; k >= 0; --k)
				map[i][j] = map[i][j];
		}
	}

	vector<vector<vector<bool>>> visible(r, vector<vector<bool>>(c, vector<bool>(t + 1)));
	visible[pos.first][pos.second][t] = true;

	backtracking(pos.first, pos.second, t, 0, visible);

	cout << answer;

}
