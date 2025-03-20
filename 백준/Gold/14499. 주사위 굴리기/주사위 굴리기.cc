#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <list>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n, m, k;
pair<int, int> pos;

vector<vector<int>> graph;
vector<int> command;

int dice[6];// 위, 아래, 동, 서, 남, 북

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool move_dice(int cmd)
{
	int x = pos.first + dx[cmd - 1];
	int y = pos.second + dy[cmd - 1];

	if (x < 0 || x >= n || y < 0 || y >= m) return false;

	int temp = dice[0];
	if (cmd == 1) // 동
	{
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
	}
	else if (cmd == 2) // 서
	{
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
	}
	else if (cmd == 3) // 북
	{
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
	}
	else if (cmd == 4) // 남
	{
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
	}

	pos = { x, y };

	return true;
}

int main()
{
	format;
	
	cin >> n >> m >> pos.first >> pos.second >> k;

	graph.resize(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> graph[i][j];
	}

	command.resize(k);

	for (int i = 0; i < k; ++i)
		cin >> command[i];

	for (auto a : command)
	{
		if (!move_dice(a)) continue;

		if (graph[pos.first][pos.second] != 0)
		{
			dice[1] = graph[pos.first][pos.second];
			graph[pos.first][pos.second] = 0;
		}
		else
		{
			graph[pos.first][pos.second] = dice[1];
		}

		cout << dice[0] << '\n';
	}
}