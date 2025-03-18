#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <list>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;


struct pos {
	int x, y;
};

struct logs {
	pos A, B, C;
	int floating;
	int cnt;
};

int dx[8] = { -1, 1, 0, 0, -1, 1, 1, -1};
int dy[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

int n, answer;
vector<vector<int>> v;
vector<vector<vector<bool>>> visible; // 가운데 통나무 x, y, 눕혀져있는 상태


void bfs(logs st)
{
	queue<logs> q;
	q.push(st);

	while (!q.empty())
	{
		logs cur = q.front();
		q.pop();

		if (v[cur.A.x][cur.A.y] == 'E' && v[cur.B.x][cur.B.y] == 'E' && v[cur.C.x][cur.C.y] == 'E')
		{
			answer = cur.cnt;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			logs next = cur;
			next.A.x += dx[i];
			next.A.y += dy[i];
			next.B.x += dx[i];
			next.B.y += dy[i];
			next.C.x += dx[i];
			next.C.y += dy[i];

			if (next.A.x < 0 || next.A.x >= n || next.B.x < 0 || next.B.x >= n || next.C.x < 0 || next.C.x >= n ||
				next.A.y < 0 || next.A.y >= n || next.B.y < 0 || next.B.y >= n || next.C.y < 0 || next.C.y >= n) continue;
			if (v[next.A.x][next.A.y] == '1' || v[next.B.x][next.B.y] == '1' || v[next.C.x][next.C.y] == '1' || visible[next.B.x][next.B.y][next.floating]) continue;

			next.cnt++;
			visible[next.B.x][next.B.y][next.floating] = true;
			q.push(next);
		}

		bool isTurn = true;
		logs next = cur;

		for (int i = 0; i < 8; ++i)
		{
			int x = next.B.x + dx[i];
			int y = next.B.y + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= n || v[x][y] == '1')
			{
				isTurn = false;
				break;
			}
		}

		if (isTurn)
		{
			if (next.floating == 0)
			{
				//가로로 
				next.A.x = next.B.x;
				next.A.y = next.B.y - 1;
				next.C.x = next.B.x;
				next.C.y = next.B.y + 1;
				next.floating = 1;
			}
			else
			{
				next.A.x = next.B.x - 1;
				next.A.y = next.B.y;
				next.C.x = next.B.x + 1;
				next.C.y = next.B.y;
				next.floating = 0;
			}

			if (!visible[next.B.x][next.B.y][next.floating])
			{
				next.cnt++;
				visible[next.B.x][next.B.y][next.floating] = true;
				q.push(next);
			}
		}
	}

	return;
}

int main()
{
	format;

	cin >> n;

	v.resize(n, vector<int>(n));
	visible.resize(n, vector<vector<bool>>(n, vector<bool>(2)));

	vector<pos> startLogs;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < n; ++j)
		{
			v[i][j] = str[j];
			if (str[j] == 'B')
				startLogs.push_back({ i, j });
		}
	}

	int state = 0;
	if (startLogs[1].y - startLogs[0].y == 1) state = 1;

	logs st = { {startLogs[0].x, startLogs[0].y}, {startLogs[1].x, startLogs[1].y}, {startLogs[2].x, startLogs[2].y}, state, 0 };
	visible[st.B.x][st.B.y][state] = true;

	bfs(st);
	
	cout << answer;
}